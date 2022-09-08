#include "unix.h"

/**
 * prompt - this makes a prompt
 *
 * Return: 0 when sucessful
 */
int prompt(void)
{
	char *prompt = " ($) ";
	ssize_t count = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		count = write(STDOUT_FILENO, prompt, 6);
		if (count == -1)
			exit(0);
	}
	return (0);
}

/**
 * _read - takes in stdin and stores it in a buffer
 *
 * Return: pointer to the buff
 */
char *_read(void)
{
	int i = 0;
	size_t n = 0;
	ssize_t count = 0;
	char *buffer = NULL;

	count = getline(&buffer, &n, stdin);
	if (count == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (buffer[count - 1] == '\n' || buffer[count - 1] == '\t')
		buffer[count - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}

/**
 * _fullpathbuffer - this finds the string to call execve
 * @tbuffer: pointer to array of user
 * @path: pointer to PATH
 * @copy: pointer to copy of PATH
 *
 * Return: a pointer to string
 */
char *_fullpathbuffer(char **tbuffer, char *path, char *copy)
{
	char *tok, *fbuffer = NULL, *concatstr = NULL;
	struct stat h;
	static char tmp[256];
	int PATHcount = 0, ping = 0, toklen = 0, val = 0;

	copy = NULL;
	copy = _strdup(path);
	PATHcount = _splitPATH(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concat(tmp, tbuffer, tok);
		if (stat(concatstr, &h) == 0)
		{
			fbuffer = concatstr;
			ping = 1;
			break;
		}
		if (val < PATHcount - 2)
		{
			toklen = _strlen(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(tbuffer[0], &h) == 0)
				{
					fbuffer = tbuffer[0];
					ping = 1;
					break;
				}
			}
		}
		val++;
		tok = strtok(NULL, ":");
	}
	if (ping == 0)
		fbuffer = tbuffer[0];
	free(copy);
	return (fbuffer);
}

/**
 * checkbuiltins - check if first user string is a built-in
 * @tbuffer: pointer to array of user of strings
 * @buffer: pointer to user string
 * @exitstatus: exit status
 *
 * Return: 1 if user string is equal to env, 0 otherwise
 */
int checkbuiltins(char **tbuffer, char *buffer, int exitstatus)
{
	int i;

	if (_strcmp(tbuffer[0], "env") == 0)
	{
		_env();
		for (i = 0; tbuffer[i]; i++)
			free(tbuffer[i]);
		free(tbuffer);
		free(buffer);
		return (1);
	}
	else if (_strcmp(tbuffer[0], "exit") == 0)
	{
		for (i = 0; tbuffer[i]; i++)
			free(tbuffer[i]);
		free(tbuffer);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}

/**
 * _forkprocess - create fork process
 * @tbuffer: pointer to array of string user
 * @buffer: pointer to user string
 * @fbuffer: pointer to user input
 *
 * Return: 0 when successful
 */
int _forkprocess(char **tbuffer, char *buffer, char *fbuffer)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(fbuffer, tbuffer, environ);
		if (result == -1)
		{
			perror(tbuffer[0]);
			for (i = 0; tbuffer[i]; i++)
				free(tbuffer[i]);
			free(tbuffer);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	for (i = 0; tbuffer[i]; i++)
		free(tbuffer[i]);
	free(tbuffer);
	free(buffer);
	return (exitstatus);
}

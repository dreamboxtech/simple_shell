#include "unix.h"

/**
 * tokenize - creates array of tokens with user input
 * @buffer: pointer to user input
 *
 * Return: pointer to array of user input
 */
char **tokenize(char *buffer)
{
	int count = 0, i = 0;
	char *token;
	char *delimiter = " \n";
	char **tbuffer;

	count = _stringcount(buffer);
	if (!count)
		return (NULL);
	tbuffer = malloc((count + 1) * sizeof(char *));
	if (tbuffer == NULL)
		exit(1);
	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		tbuffer[i] = _strdup(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	tbuffer[i] = NULL;
	return (tbuffer);
}

/**
 * _splitPATH - this counts the number of PATH users
 * @str: pointer to string to count
 *
 * Return: number of PATH users
 */
int _splitPATH(char *str)
{
	int i, ping = 1, count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && ping == 1)
		{
			count += 1;
			ping = 0;
		}
		if (str[i + 1] == ':')
		{
			ping = 1;
		}
	}
	return (count);
}

/**
 * _PATHstrcmp - queries PATH with environ to find PATH variables
 * @c1: pointer PATH string
 * @c2: pointer to environ string with actual variable
 *
 * Return: 0 when successful
 */
int _PATHstrcmp(const char *c1, const char *c2)
{
	int i;

	for (i = 0; c2[i] != '='; i++)
	{
		if (c1[i] != c2[i])
			return (-1);
	}
	return (0);
}

/**
 * _concat - concatenate user string with PATH user
 * @tmp: array to store concatenated val
 * @tbuffer: pointer to array of user input
 * @tok: pointer to PATH token
 *
 * Return: 0 when successful
 */
char *_concat(char *tmp, char **tbuffer, char *tok)
{
	int len = 0;

	_memset(tmp, 0, 256);
	len = _strlen(tok) + _strlen(tbuffer[0]) + 2;
	_strcat(tmp, tok);
	_strcat(tmp, "/");
	_strcat(tmp, tbuffer[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}

#include "unix.h"
/**
 * main - starts the unix command interpreter
 *
 * Return: returns 0 if successful
 */
int main(void)
{
	char *buffer = NULL, *fbuffer = NULL, *copy = NULL, *path = NULL;
	char **tbuffer;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);
	path = _getenv("PATH");
	if (path == NULL)
		return (-1);
	while (1)
	{
		tbuffer = NULL;
		prompt();
		buffer = _read();
		if (*buffer != '\0')
		{
			tbuffer = tokenize(buffer);
			if (tbuffer == NULL)
			{
				free(buffer);
				continue;
			}
			fbuffer = _fullpathbuffer(tbuffer, path, copy);
			if (checkbuiltins(tbuffer, buffer, exitstatus) == 1)
				continue;
			exitstatus = _forkprocess(tbuffer, buffer, fbuffer);
		}
		else
			free(buffer);
	}
	return (0);
}

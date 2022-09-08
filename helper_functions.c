#include "unix.h"

/**
 * _getenv - gets env
 * @name: name of env
 * Return: pointer
 *
 */
char *_getenv(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = _PATHstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * _env - prints env var
 * * Return: returns 0 if successful
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}

/**
 * _puts - function to print string
 * * @str: string to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}

/**
 * _putchar - function to print a char
 * @c: char
 *
 * Return: return write value
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _memset - writed memory with a constant byte
 * @arr: char array to fill
 * @byte: const byte to fill with
 * @no: number of bytes to fill
 *
 * Return: pointer to the char
 */
char *_memset(char *arr, char byte, unsigned int no)
{
	unsigned int i;

	for (i = 0; i < no; i++)
		arr[i] = byte;
	return (arr);
}

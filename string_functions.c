#include "unix.h"

/**
 * _strdup - duplicates string
 * @str: string to be duplicated
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	int i;
	char *cpystr;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	cpystr = malloc(sizeof(char) * (i + 1));
	if (cpystr == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		cpystr[i] = str[i];
	}
	cpystr[i] = '\0';
	return (cpystr);
}

/**
 * _stringcount - counts number of words in string
 * @str: string to count
 *
 * Return: char count
 */
int _stringcount(char *str)
{
	int i, count = 0, ping = 1;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && ping == 1)
		{
			count += 1;
			ping = 0;
		}
		if (str[i + 1] == ' ')
			ping = 1;
	}
	return (count);
}

/**
 * _strcmp - compares strings
 * @c1: model char
 * @c2: char to compare to model
 *
 * Return: null or result
 */
int _strcmp(const char *c1, const char *c2)
{
	while ((*c1 != '\0' && *c2 != '\0') && *c1 == *c2)
	{
		c1++;
		c2++;
	}
	if (*c1 == *c2)
		return (0);
	else
		return (*c1 - *c2);
}

/**
 * _strcat - concatenates strings
 * @str1: adding to
 * @str2: adding from
 *
 * Return: char type
 */
char *_strcat(char *str1, char *str2)
{
	int i, j;

	for (i = 0; str1[i] != '\0'; i++)
		;
	for (j = 0; str2[j] != '\0'; j++, i++)
		str1[i] = str2[j];
	str1[i] = '\0';
	return (str1);
}
/**
 * _strlen - returns string length
 * @s: char
 *
 * Return: integer type
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}

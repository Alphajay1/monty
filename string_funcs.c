#include "monty.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if str1 and str2 are equal, otherwise return any other value
 */
int _strcmp(char *str1, char *str2)
{
	int i;

	for (i = 0; str1[i] == str2[i] && str1[i]; i++)
		;
	if (str1[i] > str2[i])
		return (1);
	if (str1[i] < str2[i])
		return (-1);
	return (0);
}

/**
 * _sch - search if a character is inside a string
 * @str: string to search
 * @c: the character find
 *
 * Return: 1 on success, 0 on failure
 */
int _sch(char *str, char c)
{
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] == c)
		{
			break;
		}
		index++;
	}
	if (str[index] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtok - a function that cuts the string into tokens depending
 * on the delimeter
 * @str: string to cut
 * @delim: the delimeter
 *
 * Return: returns the first partition
 */
char *_strtok(char *str, char *delim)
{
	static char *last_position;
	int i = 0, j = 0;

	if (!str)
		str = last_position;
	while (str[i] != '\0')
	{
		if (_sch(delim, str[i]) == 0 && str[i + 1] == '\0')
		{
			last_position = str + i + 1;
			*last_position = '\0';
			str = str + j;
			return (str);
		}
		else if (_sch(delim, str[i]) == 0 && _sch(delim, str[i + 1]) == 0)
			i++;

		else if (_sch(delim, str[i]) == 0 && _sch(delim, str[i + 1]) == 1)
		{
			last_position = str + i + 1;
			*last_position = '\0';
			last_position++;
			str = str + j;
			return (str);
		}
		else if (_sch(delim, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}

#include "shell.h"

/**
 * itos - converts integer to string
 *
 * @list: variadic argument
 *
 * Return: a string
 */
char *itos(int digits)
{
	int count, i, neg, absMod, digitTest;
	char *output;

	digitTest = digits;
	count = 0;
	neg = 0;
	if (digits == 0)
	{
		output = malloc(sizeof(char) * 2);
		output[0] = '0';
		output[1] = 0;
		return (output);
	}
	if (digits < 0)
	{
		neg = 1;
		count++;
	}
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * count + 1);
	if (output == NULL)
		return (NULL);
	if (neg)
		output[0] = '-';
	digitTest = digits;
	for (i = count - 1; i >= 0 + neg; i--)
	{
		absMod = digitTest % 10;
		output[i] = (absMod < 0 ? -absMod : absMod) + '0';
		digitTest /= 10;
	}
	output[count] = '\0';
	return (output);

}

char *malcat(char *dest, char *src)
{
	int len_dest;
	int len_src;
	int i, j;
	char *s;

	printf("In malcat\n");
	len_dest = 0;
	while (dest[len_dest] != '\0')
	{
		len_dest++;
	}
	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	i = len_src + len_dest;
	i++;
	s = malloc(sizeof(char) * i);
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i] != 0)
	{
		s[j++] = dest[i++];
	}
	i = 0;
	while (src[i] != 0)
	{
		s[j++] = src[i++];
	}
	s[j] = 0;

	return (s);
}
/**
 * _strchr - locates a character in a string
 * @s: char pointer
 * @c: char
 * _strchr: locates character in a string and returns a pointer
 * to the first occurence of @c in the string @s
 * Return: address of first occurence of @c in @s
 */
char *_strchr(char *s, char c)
{
	int i;
	int len;

	i = 0;
	while (s[i] != '\0')
	{
		len++;
		i++;
	}

	i = 0;
	while (i <= len)
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}
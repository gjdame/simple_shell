#include "shell.h"
#include "history.h"
/**
 * gethistory - gets the history list
 * Return: 0 uposon success
 */
HistList **gethistory()
{
	static HistList *hlist;
	return (&hlist);
}
/**
 * sethist - set hist and value
 * @cmd: command
 * Return: 0 upon success
 */
int sethist(char *cmd)
{
	HistList **hlistroot = gethistory();
	HistList *hlist = *hlistroot;
	HistList *ptr = hlist, *new;

	if (hlist == NULL)
	{
		new = malloc(sizeof(HistList));
		if (new == NULL)
			return (-1);

		new->cmd = _strdup(cmd);
		new->next = NULL;
		*hlistroot = new;
		return (0);
	}
	while (ptr->next != NULL)
		ptr = ptr->next;

	new = malloc(sizeof(HistList));
	if (new == NULL)
		return (-1);
	new->cmd = _strdup(cmd);
	new->next = NULL;
	ptr->next = new;
	return (0);
}
/**
 * print_listint - prints all elements of listint
 * @h: pointer to first node of list
 * Return: num of elements
 */
int print_hist()
{
	HistList **hlistroot = gethistory();
	HistList *h = *hlistroot;
	int i;
	int len, numlen;
	char *s, *num;

	i = 0;
	while (h != NULL)
	{
		len = _strlen(h->cmd);
		s = h->cmd;
		num = itos(i);
		numlen = _strlen(num);
		write(1, num, numlen);
		_putchar(' ');
		write(1, s, len);
		h = h->next;
		i++;
	}
	return (i);
}

int exit_hist()
{
/*	int fd;
	char *file = ".simple_shell_history";
	int i, len, w;
	char *s;

	HistList **hlistroot = gethistory();
	HistList *hlist = *hlistroot;
	HistList *ptr = hlist;

	file = tildeexpand(file);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC);
	if (fd == -1)
		return (-1);
	

	while (hlist != NULL)
	{
		ptr = hlist->next;
		free(hlist->cmd);
		free(hlist);
		hlist = ptr;
	}
*/
/*	close(fd);*/

	return(1);
}

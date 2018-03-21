#include "shell.h"

int shintmode()
{
	char *bufgl = NULL;
	size_t bufgllen = 0;
	ssize_t lenr;
	int istty = isatty(0) && isatty(1);

	while(1)
	{
#ifdef DEBUGMODE
		printf("At terminal prompt\n");
#endif
		if (istty)
			printf("Homemade shell:%s$", _getenv("PWD"));
		lenr = getline(&bufgl, &bufgllen, stdin);
		if (lenr == 0 || lenr == -1)
			break;
#ifdef DEBUGMODE
		printf("calling parseargs %s\n", bufgl);
#endif
		parseargs(&bufgl);
	}
	if (bufgl != NULL)
		free(bufgl);
	return (0);
}

int scriptmode(int ac, char *av[])
{
	char *buf = NULL;
	size_t n = 0;
	int i = 1;
	FILE *infile;

	while (i < ac)
	{
		infile = fopen(av[i], "r");
/*		if (infile == -1)
		continue;*/
		do
		{
			if (getline(&buf, &n, infile) == -1)
				break;
			if (buf == NULL)
				return (-1); /* fix buffer allocation error later */
			parseargs(&buf);
		} while (*buf != 0);
		fclose(infile);
		i++;
	}
	if (buf != NULL)
		free(buf);
	return (0);
}

int main(int ac, char *av[], char **environ)
{
	setbuf(stdout, NULL);
	initsvars(ac, av);
	setallenv(environ, NULL);
#ifdef DEBUGMODE
	printf("?:%s\n", getsvar("?"));
	printf("0:%s\n", getsvar("0"));
	setsvar(_strdup("simplevar"), _strdup("98"));
	printf("simplevar:%s\n", getsvar("simplevar"));
#endif
	if (ac > 1)
		return (scriptmode(ac, av));

	return (shintmode());
}

#include "lib.h"
/**
  * main - main
  * Return: int
  */
int main(void)
{
	char *buf, *simp, *slash;
	size_t bufsize = 1024;
	int chara;
	char **doub, **simpD;
	int qq = 0;

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 2);

		buf = malloc(sizeof(char *) * bufsize);
		if (!buf)
			return (0);

		chara = getline(&buf, &bufsize, stdin);
		if (chara == -1)
			return (-1);

		if ((buf[chara - 1]) == '\n')
			buf[chara - 1] = 0;

		doub = strD2(buf);
		simp = compEnv();
		qq = qStrtokPath(simp);
		simpD = strD2Path(simp);
		slash = str_concat("/", doub[0]);
		concPath(simpD, slash);
		simpD[qq] = doub[0];
		executen(simpD, doub);
	}
	return (0);
}

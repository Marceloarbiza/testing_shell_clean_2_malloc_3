#include "lib.h"
/**
  *executen - execute the program and the child
  *@d: Array string of PATH
  *@a: Array string of inputs
  *Return: int
  */
int executen(char **d, char **a)
{
	int i = 0, axs = 0;
	pid_t pid = 0;
	int status;
		
	if (a[0] == NULL)
		return (0);
	pid = fork();

	if (pid == 0)
	{
		for (i = 0; d[i]; i++)
		{
			axs = access(d[i], X_OK);
			if (axs == 0)
			{
				execve(d[i], a, NULL);
				break;
			}
		}
		printf("IT DOES NOT WORK!\n");
		exit(98);
	}
		wait(&status);

	return (0);
}

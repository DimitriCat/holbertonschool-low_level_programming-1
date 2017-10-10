#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i;
	int j;
	int sum;

	i = 1;
	j = 0;
	sum = 0;
	if (argc == 0)
	{
		printf("0");
		return (0);
	}
	while (argv[i] != NULL)
	{
		while (argv[i][j] != '\0')
		{
			if (!(isdigit(argv[i][j])))
			{
				printf("Error\n");
				return (1);
			}
			j++;
		}
		sum += atoi(argv[i]);
		i++;
		j = 0;
	}
	printf("%d\n", sum);
	return (0);
}

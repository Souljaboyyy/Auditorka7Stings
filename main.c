#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0, maxd = 0, dlina = 0, levo,o;
	int symb[123] = { 0 };
	char* str = (char*)malloc(sizeof(char));
	printf("Type your string : \n");

	while (1)
	{
		str[i] = _getche();
		if (str[i] == '\r')
		{
			str[i] = '\0';
			break;
		}
		if (str[i] == '\b')
		{
			if (i > 1)
			{
				i -= 1;
				str[i] = '\0';
				system("cls");
				printf("%s", str);
				
			}
			if (i <= 1)
			{
				i = 0;
				str = (char*)realloc(str, i + 1);

			}
		}

		i++;
		str = (char*)realloc(str, i + 1);
	}
	str[i] = '\0';
	printf("\n");
	i = 0;

	char* itog = (char*)calloc(strlen(str), sizeof(char));

	for (int j = 0; j < strlen(str); j++)
	{
		int k = 0;
		while (symb[(int)str[k + j]] != 1 && k + j < strlen(str))
		{
			symb[(int)str[k + j]]++;
			dlina++;
			k++;
		}
		if (dlina > maxd)
		{
			maxd = dlina;
		//	o = k;
			dlina = 0;
			levo = j;
		}
		else dlina = 0;
		for (int i = 0; i < 123; i++)
			symb[i] = 0;
	}

	for (int q = 0; q < maxd; q++)
	{
		itog[q] = str[levo + q];
	}
	printf("%s\n", itog);
	printf("Dlina = %d\n",maxd);
	free(str);
	system("pause");
	return 0;
}
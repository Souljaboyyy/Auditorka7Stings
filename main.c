#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
char* Podschet(char *mass,int lenght) {
	int j = 0;int symb[123] = { 0 },dlina=0,maxd=0,levo;
	for (j; j < lenght; j++)
	{
		int k = 0;
		while (symb[(int)mass[k + j]] != 1 && k + j < lenght)
		{
			symb[(int)mass[k + j]]++;
			dlina++;
			k++;
		}
		if (dlina > maxd)
		{
			maxd = dlina;
			dlina = 0;
			levo = j;
		}
		else dlina = 0;
		for (int i = 0; i < 123; i++)
			symb[i] = 0;
	}
	char *itog = (char*)malloc(maxd * sizeof(char));
	for (j=0; j < maxd; j++)
	{
		itog[j] = mass[levo + j];
	}
	return itog;
}
int PodschetDlin(char *mass, int lenght) {
	int j = 0; int symb[123] = { 0 }, dlina=0, maxd=0, levo;
	for (j; j < lenght; j++)
	{
		int k = 0;
		while (symb[(int)mass[k + j]] != 1 && k + j < lenght)
		{
			symb[(int)mass[k + j]]++;
			dlina++;
			k++;
		}
		if (dlina > maxd)
		{
			maxd = dlina;
			dlina = 0;
			levo = j;
		}
		else dlina = 0;
		for (int i = 0; i < 123; i++)
			symb[i] = 0;
	}
	char *itog = (char*)malloc(maxd * sizeof(char));
	for (j; j < maxd; j++)
	{
		itog[j] = mass[levo + j];
	}
	return maxd;
}
int main()
{
	int i = 0, maxd = 0, dlina = 0;
	char s;
	//char* str = (char*)malloc(sizeof(char));
	FILE *fp;
	fopen_s(&fp, "string.txt", "w");
	printf("Type your string : (Tap enter to calculate) \n");
	while (!feof(fp)) {
		s = getche();
		/*if ((int)s == 44)
			break;*/
	//	if ((((int)s > 47) && ((int)s < 58)) || (((int)s > 64) && ((int)s < 91)) || (((int)s > 96) && ((int)s < 123)) || ((int)s == 32))
			dlina++;
		fprintf(fp,"%c", s);
		if (s == '\r')
		{
			s = '\0';
			break;
		}
	}
	dlina -= 1;
	fclose(fp);
	fopen_s(fp, "string.txt", "r");
	char *stroka = (char*)malloc(dlina * sizeof(char));
	for (i = 0; i < dlina; i++) {
		fscanf_s(fp,"%c", &stroka[i]);
	}
	printf("\n");
	fclose(fp);
	/*for (i = 0; i < dlina ; i++)
		printf("%c", stroka[i]);*/
	printf("\n");
	maxd = PodschetDlin(stroka, dlina);
	char *itog = (char*)malloc(maxd * sizeof(char));
	itog=Podschet(stroka,dlina);
	for (i = 0; i < maxd; i++)
		printf("%c", itog[i]);
	printf("\nDlina = %d\n",maxd);
	fopen_s(fp, "string.txt", "w");
	for (i = 0; i < maxd; i++)
		fprintf(fp,"%c", itog[i]);
	fprintf(fp, "\n%d", maxd);
	fclose(fp);
	free(stroka);
	free(itog);
	system("pause");
	return 0;
}
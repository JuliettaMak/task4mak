#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <float.h>

void first(int, char, char *);
void follow(char);

void main() {
	char ssymbol = '2';
	int Bsymbol_length = 2;
	char bsymbol[] = {'0', '1'};
first(Bsymbol_length, ssymbol, bsymbol);

char rule = 'B';
follow(rule);
}

void first(int B_option_number, char symbol_S, char *symbols_afterB)
{
	int stepnumber = 2;
	FILE* ff = fopen("task4.log", "a");
	fprintf(ff, "FIRST \n");
	fprintf(ff, "terminal\t step_number \n");
	for (int ii = 0; ii < B_option_number; ii = ii + 1) {
		fprintf(ff, "\"%c\" \t\t %d \n", symbols_afterB[ii], stepnumber);
	}
	fclose(ff);
}

void follow(char rule)
{
	FILE* ff = fopen("task4.log", "a");
	fprintf(ff, "FOLLOW\n");
	fprintf(ff, "rule\t number_of_terminals\t terminals \n");

	switch (rule)
	{
	case 'B':
		fprintf(ff, "%c\t %d\t\t\t \"%c\"\t \n", rule, 1, '2');
		break;
	case 'S':
		fprintf(ff, "%c\t %d \n", rule, 0);
		break;
	default:
		printf("Rule %c is not defined. Choose rule S or B", rule);
	}


	fclose(ff);
}

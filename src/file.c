/*
Defines the functions of data.h
*/

#include "file.h"
#include "random.h"
#include <stdio.h>

FILE *fp;

int file_open_routine()
{

//#define FILE_OPEN_CALLED	
		
	if((fp=fopen("data/list","r"))==NULL)	
	{
		printf("There has been an exception, restart application");
		return 1;
	}
	else
		return 0;
}	



int file_print()
{
//#ifdef FILE_OPEN_CALLED

	int count_lines=0;
	int random_line;
	char ch_traverse;
	int count=0;
	char str[100];
	ch_traverse=getc(fp);
	if(ch_traverse==EOF)
	{
		printf("The data file seems to be corrupted, please rerun with \"reset\" as argument");
		return 1;
	}
	
	while(ch_traverse!=EOF)
	{
		if(ch_traverse=='\n')
			count_lines++;
		ch_traverse=getc(fp);
	}
	
//	printf("The number of lines are %d",count_lines);
	
	random_line=random_less_than(count_lines);
	
//	printf("\nA random line number is %d",random_line);
	
	rewind(fp);
	if(random_line==1)
		fgets(str,99,fp);
	else
	{
		while(count!=random_line-1)
		{
			//ch_traverse=getc(fp);
			//if(ch_traverse=='\n');
			fgets(str,99,fp);
			count++;
		}
	fgets(str,99,fp);
	}
	
	fputs(str,stdout);
	return 1;
}

int file_create_default()
{
	if((fp=fopen("data/list","w+"))==NULL)	
	{
		printf("There has been an exception, restart application");
		return 0;
	}
	fputs("You sir are a collosal faggot\nDo not argue with an idiot.He will drag you down to his level and beat you with his experience\nMake it correct,make it clear,make it concise,make it fast.In that order.\n\"Somewhere something incredible is waiting to be known\"- Carl Sagan\n\"Charmender is Red, Squirtle is Blue, If you are a pokemon I would choose you\"\n\"I would walk into Mordor for you\"",fp);
	return 1;
}	
	

/*
Sourav Goswami
Sun May 20, 2012
main.c
A program that prints fortune cookies in the terminal
*/
#define VERSION 1.0

#include <stdio.h>
#include "random.h"
#include "file.h"
#include <string.h>
int i=1;

int main(int argc, char *argv[])
{
	if(argc-1)
	{	
		while(i<argc)
		{
			if(!strcmp(argv[i],"version"))
				printf("Fortune: %d\nSourav Goswami\nThis is a free software\n",VERSION);
			if(!strcmp(argv[i],"reset"))
			{
				if(!file_create_default())
					{
					printf("Unknown Error");
					return 1;
					}
			}
			i++;		
				
		}
	}	
if(argc==1)
{		
			
	if(file_open_routine())
	{
		printf("There has been an exception, quiting");
		return 1;
	}
		
	if(!file_print())
		return 0;
	else
		return 1;
}
	return 1;
}

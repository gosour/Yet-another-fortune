/*
This defines the function in random.h
*/

#include "random.h"
#include<time.h>

int rand; 
int value;

int random_number()
{	
	time_t seconds;
	time(&seconds);
//	printf("%d",(int)seconds);
	srand((unsigned int)seconds);
	return random();
}

int random_less_than(int max)
{
	rand=random_number();
	value=rand%max+1;
	return value;
}

int random_in_between(int bound1, int bound2)
{
	
	if(bound1==bound2)
		return bound1;
	if(bound1>bound2)
	{
		bound1=bound1+bound2;
		bound2=bound1-bound2;
		bound1=bound1-bound2;
	}
	rand=random_number();
	value=rand%(bound1-bound2-1) + bound1+1;
	return value;
}

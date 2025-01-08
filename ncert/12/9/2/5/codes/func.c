#include <stdio.h>
#include <math.h>
#define H 0.01

double function(double x)
{
	return x ;
}

double derivative(double x)
{
	//Definition from first principle
	return function(x+H)/H - function(x)/H ;
}

void pointGen(double x, double y )
{
	FILE *ptr ;
	ptr = fopen("values.txt", "w") ; //Opens the file in write mode
	if ( ptr == NULL )
	{
		printf("File doesn't exist") ;
		return ;
	}
	for ( int i=1; i<=1000; i++ )
	{
		fprintf(ptr, "%lf %lf\n", x, y ) ; //prints in the file
		x += H ;
		y += derivative(x)*H ;
	}


	fclose(ptr) ; //closes file
	printf("The values have been printed in the file\n") ;
}
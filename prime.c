#include <stdio.h>
#include <malloc.h>


long int* primes_less_than(int n,int *number_of_primes)
{
	int  *list = calloc(n,sizeof *list); 
	// allocate an array with all elements initialized to zero 
	int i,j;
	*number_of_primes=0;
	
	for(i=2; i<n; i++)
	{
		if (!list[i])
		{
	
			(*number_of_primes)++;
			for (j = 2 * i; j<n; j += i)
				list[j] = 1;
		}
	}
	printf("\nNumber of primes = %d\n",*number_of_primes);
	long int *primes = calloc(*number_of_primes,sizeof *primes);
	j = 0;
	for (i=2;i<n; i++)
	{
		if (!list[i])
			primes[j++]=i;
	}

	/*for (i = 0 ; i<n;i++)
		printf("\n%d\t",list[i]);
	*/
	return primes;
}

int main(int argc, char** argv)
{

	if(argc>3 || argc<2 )
	{
		printf("\nerror: usage prime [limit] [filename]");
		return 0;
	}
	int n = atoi(argv[1]);
	int nprimes; /*variable to hold no.of primes generated*/
	long int *primes = primes_less_than(n,&nprimes);
	int i=-1;
	char *prefix = "";
	FILE *fp;

	fp = ((argc == 3)?fopen(argv[2] ,"w"):stdout); 
	/*if no filename is given default to stdout*/


	if (fp == NULL)
	{
		printf("\nError opening file.\n");
		return 0;
	}
	/*Printing generated prime numbers seperated by comma*/
	for (i = 0; i<nprimes;i++)
	{
		fprintf(fp,"%s%li",prefix,primes[i]);
		prefix = ", ";
	}
	fclose(fp);
	return 0;
}

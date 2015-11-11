#include<stdio.h>
#include<pthread.h>

int primenum;

void *threadprime(void *args)
{
	int i, a,count=0;
	a=*((int*)args);
	for(i=1; i<=a; i++)
	{
		if(a%i==0)
		{
			count++;
		}
	}
	if(count==2)
	{
		primenum = primenum + 1;
		printf ("%d ",a);
	}
}

int main()
{
	int i, tcase;
	printf("MENGHITUNG BANYAK BILANGAN PRIMA\n");
	printf("Masukkan Testcase : ");
	scanf("%d", &tcase);
	pthread_t arr1[tcase];
	int arr2[tcase];
	for(i=2; i<tcase; i++)
	{
		arr2[i]=i;
		pthread_create(&arr1[i],NULL,threadprime,&arr2[i]); 	
	}
	for(i=2; i<tcase; i++)
	{
		pthread_join(arr1[i],NULL); 
	}
	printf("\nBanyak bilangan prima kurang dari %d ada %d\n",tcase, primenum);
	return 0; 
}

  

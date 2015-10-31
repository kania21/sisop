#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* input()
{
	int input, a, b;

	printf("------------MENGHITUNG BILANGAN PRIMA KURANG DARI N------------\n");
	printf("Masukkan N: ");
	scanf("%d", &input);

	for(a=2; a<input; a++)
	{
		for(b=2; b<a; b++)
		{
			if(a%b==0)
			break;
		}
		if(b==a)
		printf("%d ", b);
	}
	printf("\n");
}

int main()
{
	pthread_t cetak;
	pthread_create(&cetak,NULL,input,NULL);
	pthread_join(cetak,NULL);
	return 0;
}

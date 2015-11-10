/*
SOAL 2
Mencari jumlah bilangan prima < N
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
*untuk menginput testcase yang diinginkan
*menghitung banyak bilangan prima sesuai testcase
*/
void* input()
{
	int tcase, a, b;
	int count=0;

	printf("------------MENGHITUNG BILANGAN PRIMA KURANG DARI N------------\n");
	printf("Masukkan N: ");
	scanf("%d", &tcase);

	for(a=2; a<tcase; a++)
	{
		for(b=2; b<a; b++)
		{
			if(a%b==0)
			break;
		}
		if(b==a)
		{
			printf("%d ", b);
			count++;
		}
	}
	printf("\nJumlah bilangan prima kurang dari %d ada %d\n", tcase, count);
}

/*
memanggil dan menjalankan fungsi input
*/
int main()
{
	pthread_t cetak;
	pthread_create(&cetak,NULL,input,NULL);
	pthread_join(cetak,NULL);
	return 0;
}

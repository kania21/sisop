/*
SISTEM OPERASI A
E-11
Kania Amalia 5114100172
Tiara Anggita 5114100176
SOAL 2
Mencari jumlah bilangan prima kurang dari N
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
Thread Function
menghitung banyak bilangan prima kurang dari testcase
*/
void* prime(void *args)

{
	//deklarasi variabel lokal
	int tcase, a, b;
	int count=0;

	printf("------------MENGHITUNG BILANGAN PRIMA KURANG DARI N------------\n");
	printf("Masukkan N: "); //input testcase
	scanf("%d", &tcase);

	//menghitung banyak bilangan prima
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
Main Function
*/
int main()
{
	pthread_t thread1;
	pthread_create(&thread1,NULL,prime,NULL); //buat thread menjalankan fungsi prime
	pthread_join(thread1,NULL);
	return 0;
}

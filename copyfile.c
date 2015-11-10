/*
SISTEM OPERASI A
E-11
Kania Amalia 5114100172
Tiara Anggita 5114100176
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Variabel global
FILE *input;
FILE *output;

/*
Thread Function
membaca dan menyalin karakter file1 ke file2
*/
void *copyfile1 (void *args)
{
	int *flag = (int *) args; 
	
	input = fopen("file1.txt", "r"); //membuka dan membaca karakter file1
	output = fopen("file2.txt", "w"); //salin karakter file1
	
	while(1)
	{
		char ch = fgetc(input); //membaca karakter file1
		if (ch == EOF) break;	
		else fputc(ch, output); //menyimpan karakter file1
	}
	//menutup file yang sudah tidak diproses
	fclose(input);
	fclose(output);
	*flag=2;
}

/*
Thread Function
membaca dan menyalin karakter file2 ke file3
*/
void *copyfile2 (void *args)
{
	int *flag = (int *) args;
	*flag = 0;
	while(1)
	{
		//if(*flag == 0) continue;
		if(*flag == 2)
		{
			input = fopen("file2.txt","r"); //membaca karakter file2
			output = fopen("file3.txt","w"); //menyalin karakter file3
			break;
		}
	}
	
	while(1)
	{
		char ch = fgetc(input); //membaca karakter file2
		if(ch == EOF)
		{
			if(*flag == 0) continue;
			else break;
		}
		fputc(ch, output); //menyimpan karakter file3
	}
	//menutup file yang sudah tidak diproses
	fclose(input);
	fclose(output);
}

/*
Main Function
*/
int main()
{
	int flag = 0;
	pthread_t thread1, thread2;	
	printf("MEMBACA DAN MENYALIN ISI FILE");
	
	pthread_create(&thread1,NULL,copyfile1,&flag); //buat thread menjalankan fungsi copyfile1
	pthread_create(&thread2,NULL,copyfile2,&flag); //buat thread menjalankan fungsi copyfile2
	
	//menggabungkan thread1 dan thread2
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);	
}

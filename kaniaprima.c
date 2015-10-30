#include<stdio.h>
#include<unistd.h>
void process()
{
	int count,b,data[100],i,j,k;
	pid_t pid;

	for(i=0;i<5;i++)
	{
		pid=fork();
		wait();
		if(pid==0)
		{scanf("%d",&data[i]);
		count=0;
		for(j=1;j<=data[i];j++) 
		{
			if(data[i]%j==0) count++;
		}
		if(count==2) printf("Bil Prima\n");
		else printf("Bukan Prima\n");}
		else break;
	}


}


void main()
{
	process();
}

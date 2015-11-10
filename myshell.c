#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLENGTH 1024

int main()
{
	char line[MAXLENGTH];	//get command line
	char *argv[100]; 	//user command
	char *path="/bin/";	//set path at bin
	char fullpath[20];	//full file path
	int argc;		//argument count

	while(1)
	{
		printf("Welcome to My Shell!");	
		if(!fgets(line,MAXLENGTH,stdin))//get command and put in line
		{
			break;
		}
		if(strcmp(line, "exit\n")==0)	//ctrl+D then exit
		{
			break;
		}
		char *token;	//split command into separate things
		token=strtok(line," ");
		int i=0;
		while(token!=NULL)
		{
			argv[i]=token;
			token=strtok(NULL," ");
			i++;
		}
		argv[i]=NULL;	//set last value to NULL for execvp
		argc=i;		//get argument count
		
		for(i=0;i<argc;i++)
		{
			printf("%s\n",argv[i]);
		}
		strcpy(fullpath,path);		//copy /bin/ to file path
		strcat(fullpath,argv[0]);	//add program to path

		for(i=0;i<strlen(fullpath);i++)	//delete newline
		{
			if(fullpath[i]=='\n')
			{
				fullpath[i]='\0';
			}	
		}
		
		int pid=fork();		//fork child
		if(pid==0)	//child
		{	
			wait();
			execvp(fullpath,argv);
			//fprintf(stderr,"Proses child gagal execvp\n");
		}
		else		//parent
		{
			wait();	
			printf("Keluar dari Child\n");
		}
	}
}

	

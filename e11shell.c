#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <signal.h>
#include <errno.h>

#define MAXLENGTH 1024
#define DELIMS " \t\r\n"

void signalhandler(int signal1)
{
	printf("\nKetik exit untuk keluar dari program\n");
}

int main()
{
	signal(SIGINT, signalhandler);
	signal(SIGTSTP, signalhandler);	

	char *cmd;
	char cwd [1024];
	char line[MAXLENGTH]; //get command line
	char *argv[100]; //user command
	char *path="/bin/"; //set path at bin
	char fullpath[20]; //full file path
	int argc; //argument count

	while(1)
	{
		getcwd(cwd, sizeof(cwd));
		printf("myshell:%s>>", cwd);
 		if (!fgets(line, MAXLENGTH, stdin)) break;
    		if ((cmd = strtok(line, DELIMS))) 
		{
     			errno = 0;
    			if (strcmp(cmd, "cd") == 0) 
			{
        			char *arg = strtok(0, DELIMS);
        			if (!arg) fprintf(stderr, "ERROR: expected argument for \"cd\"\n");
        			else chdir(arg);
     			}

    		}

		if (strcmp(cmd, "exit") == 0)
		{
        		break;
    		}

		char *token; //split command into separate things
		token=strtok(line," ");
		int i=0;
		while(token!=NULL)
		{
			argv[i]=token;
			token=strtok(NULL," ");
			i++;
		}

		argv[i]=NULL; //set last value to NULL for execvp
		argc=i; //get argument count
		strcpy(fullpath,path); //copy /bin/ to file path
		strcat(fullpath,argv[0]); //add program to path

		/*for(i=0;i<strlen(fullpath);i++) //delete newline
		{
			if(fullpath[i]=='\n')
			{
				fullpath[i]='\0';
			}
		}*/

		int pid=fork(); //fork child
		if(pid==0) //child
		{
			wait();
			//if(strcmp(argv[argc-1],"&")==0) argv[argc-1]='\0';
			execvp(fullpath,argv);
		}
		else	//parent
		{
			//if(strcmp(argv[argc-1],"&")==0);
			wait();
		}
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask() {
	char name[30];
	printf("\nEnter your name:-\n");
	scanf("%30s",name);
	printf("Name:%s\n",name);
}

void parentTask() {
	printf("\nJob is done\n");
}

int main(void) 
{
	for(int i = 0 ; i < 4; i++) {
		pid_t pid=fork();

	if(pid == 0) {	
		childTask();
		exit(EXIT_SUCCESS);
	}

	else {
		
		wait(NULL);
	}	
	}
	parentTask();
	return EXIT_SUCCESS;
}

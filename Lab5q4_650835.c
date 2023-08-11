#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	char userChoice = 'z';
	pid_t pid;
	while(userChoice != 'q'){
		printf("a : ls\n");
		printf("b : ps\n");
		printf("c : whoami\n");
		printf("q for quit\n");
		scanf(" %c", &userChoice);
		if(userChoice=='a'){
			pid = fork();
			if(pid==0){
				execlp("/bin/ls","ls",NULL);
			}
		}
		if(userChoice=='b'){
			pid = fork();
			if(pid==0){
				execlp("/bin/ps","ps",NULL);
			}
		}	
		
		if(userChoice=='c'){
			pid = fork();
			if(pid==0){
				execlp("/bin/whoami","whoami",NULL);
			}
		}
		wait(NULL);
	}	
	printf("parent terminated\n");
}

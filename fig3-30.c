/*
 * Figure 3.30
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int value = 5;

int main(int c, const char* argv[]) {
	pid_t pid = fork();
	
	if (pid == 0) { /* child process */
		value += 15;
		
        printf("CHILD, value is: %d\n\n", value);
		return 0;
	} else if (pid > 0) { /* parent process */
		printf("Program modified by Armanul Ambia\n");
		printf("Before PARENT calls wait\n\n");
		wait(NULL);
		printf ("PARENT: after wait, value not changed, value still = %d\n",value); /* LINE A */
		return 0;
	}
} 
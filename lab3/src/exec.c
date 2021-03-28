#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>




int main(int argc, char **argv)
{
	const char* NameScript = "./sequential_min_max";
	char *args[4] = { " ","1","10",NULL};
	int rv, status;
	

	int pid = fork();

	if (pid == 0) {
		execvp(NameScript, args);
		exit(rv);
	}
	else
	{
		wait(&status);
	}	

	fflush(NULL);
	return 0;
}
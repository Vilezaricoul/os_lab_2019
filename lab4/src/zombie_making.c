#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_pid;
	child_pid = fork();
    child_pid = fork();
	if (child_pid > 0)
	{ sleep(60); } // pause 
	else 
	{ exit(0); }
    // there's no 'wait'
	return 0;
}
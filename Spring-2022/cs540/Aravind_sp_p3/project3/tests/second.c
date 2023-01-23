#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
int cs531_system(char *s);
//defining signal handlers for parent process
void interrup_handler(int signum)
{
  //handler for the interrup signal
   printf("\nCaught an interrupt signal %d \n", signum);
}

void quit_handler(int signum)
{
  //handler for the quit signal
   printf("\nCaught a quit signal %d \n", signum);
}
void kill_handler(int signum)
{
  //handler for the kill signal
   printf("\nCaught a kill signal %d \n", signum);
}
void stop_handler(int signum)
{
  //handler for the stop signal
   printf("\nCaught a stop signal %d \n", signum);
}

int main(int argc, char *argv[])
{
int status;
status = cs531_system(argv[1]);
printf("\nParent process is sleeping…\n");
sleep(10);
return status;
}

int cs531_system(char *s)
{
  //check if no string was passed if yes exit
  if(s==NULL)
  exit(0);
  char buf[256];
  char *args[48];
  pid_t pid;
  int status, args_num = 0;
  char *str1, *token;
  //replace the default signal handlers for parent
  signal(SIGINT, &interrup_handler);
  signal(SIGQUIT, &quit_handler);
  signal(SIGKILL, &kill_handler);
  signal(SIGSTOP, &stop_handler);

  //tokenize the string based on space
  str1 = strdup(s);
  for (int j = 0; ; j++, str1 = NULL)
  {
      token = strtok(str1, " ");
      if (token == NULL)
          break;
      args[j] = token;
      args_num += 1;
    }
free(str1);
args[args_num] = (char *) NULL;
//create a child process
if ((pid = fork()) < 0)
{
    perror("fork");
}
if (pid == 0)
{
  //let the child process run the given unix command
  printf("%s %s\n",args[0], args[1]);
    execlp(args[0],args[0], args[1],(char *)NULL);
    return 127;
}
else
{
  //in the parent wait for the child process to finish and get the status
waitpid(pid, &status, WUNTRACED | WCONTINUED);
//check if the child was stopped
if (WIFSTOPPED(status))
{
  //check if the signal received was a SIGSTOP
  if(WSTOPSIG(status)==SIGSTOP)
  {
    printf("received a SIGSTOP child signal: %d \n",WTERMSIG(status));
  }
}
//Check if a continue signal was issues
if(WIFCONTINUED(status))
{
printf("received a continue signal %d\n",WTERMSIG(status));
}
//check if the child exited safely and give its exit status
if(WIFEXITED(status))
{
printf("Child processes exited with signal %d",WEXITSTATUS(status));
}

}

return 0;
}

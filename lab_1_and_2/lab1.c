#include "types.h"
#include "user.h"

int main(int argc, char *argv[])
{
	
	int exitWait(void);
	int waitPid(void);
	int PScheduler(void);
    int Inheritance(void);
  printf(1, "\n This program tests the correctness of your lab#1\n");
  
  if (atoi(argv[1]) == 1)
	exitWait();
  else if (atoi(argv[1]) == 2)
	waitPid();
  else if (atoi(argv[1]) == 3)
	PScheduler();
  else if (atoi(argv[1]) == 4)
     Inheritance(); 
   printf(1, "\ntype \"lab1 1\" to test exit and wait, \"lab1 2\" to test waitpid and \"lab1 3\" to test the priority scheduler \n");
  
    // End of test
	 exit(0);
 }
  
  
int exitWait(void) {
	  int pid, ret_pid, exit_status;
       int i;
  // use this part to test exit(int status) and wait(int* status)
sleep(5); 
  printf(1, "\n  Step 1: testing exit(int status) and wait(int* status):\n");

  for (i = 0; i < 2; i++) {
    pid = fork();
    if (pid == 0) { // only the child executed this code
      if (i == 0)
      {
      printf(1, "\nThis is child with PID# %d and I will exit with status %d\n", getpid(), 0);
      exit(0);
  }
      else
      {
	 printf(1, "\nThis is child with PID# %d and I will exit with status %d\n" ,getpid(), -1);
      exit(-1);
  } 
    } else if (pid > 0) { // only the parent exeecutes this code
      ret_pid = wait(&exit_status);
      printf(1, "\n This is the parent: child with PID# %d has exited with status %d\n", ret_pid, exit_status);
    } else  // something went wrong with fork system call
    {  
	  printf(2, "\nError using fork\n");
      exit(-1);
    }
  }
  return ret_pid;
}

int waitPid(void){
	
  int ret_pid, exit_status;
  int i;
  int pid_a[5]={0, 0, 0, 0, 0};
 // use this part to test wait(int pid, int* status, int options)

 printf(1, "\n  Step 2: testing waitpid(int pid, int* status, int options):\n");

  for (i = 0; i <5; i++) {
    pid_a[i] = fork();
	
    if (pid_a[i] == 0) { // only the child executed this code
     
      
      printf(1, "\n The is child with PID# %d and I will exit with status %d\n", getpid(), 0);
      exit(0);}}
       
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[3]);
      ret_pid = waitpid(pid_a[3], &exit_status, 0);
      printf(1, "\n This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[1]);
      ret_pid = waitpid(pid_a[1], &exit_status, 0);
      printf(1, "\n This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[2]);
      ret_pid = waitpid(pid_a[2], &exit_status, 0);
      printf(1, "\n This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[0]);
      ret_pid = waitpid(pid_a[0], &exit_status, 0);
      printf(1, "\n This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      sleep(5);
      printf(1, "\n This is the parent: Now waiting for child with PID# %d\n",pid_a[4]);
      ret_pid = waitpid(pid_a[4], &exit_status, 0);
      printf(1, "\n This is the parent: Child# %d has exited with status %d\n",ret_pid, exit_status);
      
      return ret_pid;
  }
      
      
     int PScheduler(void){
		 
    // use this part to test the priority scheduler. Assuming that the priorities range between range between 0 to 63
    // 0 is the highest priority. All processes have a default priority of 20 

  int pid, ret_pid, exit_status;
  int i,j,k;
  
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 0 to 63\n");
    printf(1, "\n  Step 2: 0 is the highest priority. All processes have a default priority of 20\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i <  3; i++) {
	pid = fork();
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {
//		printf(1, "\n Hello! this is child# %d and I will change my priority to %d \n",getpid(),60-20*i);
		setpriority(60-20*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<10000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with priority %d has finished! \n",getpid(),60-20*i);		
		exit(0);
        }
        else {
			printf(2," \n Error \n");
			exit(-1);
        }
	}

	if(pid > 0) {
		for (i = 0; i <  3; i++) {
			ret_pid = wait(&exit_status);
			//printf(1,"\n This is the parent: child with PID# %d has finished with status %d \n",ret_pid,exit_status);
			}
                     printf(1,"\n if processes with highest priority finished first then its correct \n");
}
			
	return ret_pid;
}

 int Inheritance(void){
    int pid1, pid2;
    int j,k;
    printf(1, "This is the parent setting priority to 60 \n");
    setpriority(60);
    pid1 = fork();
    if(pid1 == 0){
        printf(1, "This is Child 1, I have inherited 60 \n");
		for (j=0;j<50000;j++) {
			for(k=0;k<10000;k++) {
				asm("nop"); }}
        printf(1, "Child 1 with priority 60 has finished \n");
        exit(0);
    }else{
        printf(1, "This the parent, setting priority to 10 \n");
        setpriority(10);
        pid2 = fork();
        if(pid2 == 0){
            printf(1, "This is Child 2, I have inherited 10 \n");
            for (j=0;j<50000;j++) {
			    for(k=0;k<10000;k++) {
				    asm("nop"); }}
            printf(1, "Child 2 with priority 10 has finished \n");
            exit(0);
        }else{
            waitpid(pid1,0,0);
            waitpid(pid2,0,0);
            return pid1;
        }
    }
 }

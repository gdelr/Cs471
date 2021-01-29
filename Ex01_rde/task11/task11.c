#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define numKids 10

void aveScore(int arr[],int size){
  printf("The ID of aveScore function is: %d\n",getpid());
  printf("The ID of the parent is: %d\n",getppid());
  int i,sum=0;
  int avg;
  for(i=0;i<size;++i){
    sum+=arr[i];
  }
  avg=sum/size;
  printf("Average Score: %d\n",avg);
  execlp("/bin/date","date",NULL);
}
void smallScore(int arr[],int size){
  printf("The ID of smallScore is function is: %d\n",getpid());
  printf("The ID of the parent is: %d\n",getppid());
  int i,small;
  small=100;
  for(i=0;i<size;i++){
    if(arr[i]<small)
      small=arr[i];
  }
  printf("Smallest grade: %d\n",small);
}

int main(){
  int gradeArry[numKids];
  srand(time(NULL));
  for(int i=0;i<numKids;i++){
    gradeArry[i]=rand()%100;
    //printf("%d\n",gradeArry[i]);
  }
  printf("The ID of fuction before a fork is: %d\n",getpid());
  pid_t pid=fork();
  if(pid==0){
    printf("The ID of the parent is: %d\n",getppid());
    aveScore(gradeArry,numKids);
    pid_t pid2=fork();
    if(pid2==0){
      smallScore(gradeArry,numKids);
      exit(0);
    }
    else if(pid!=0)
      pid2=wait(NULL);
    exit(0);
  }
  //Parent process -return value is not zero
  else if(pid!=0)
    pid=wait(NULL);
  return 0;
}

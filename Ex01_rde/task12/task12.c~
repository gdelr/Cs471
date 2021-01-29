#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc,char **argv){
  int n,in,out;
  char buf[1024];
  char InputFile[1024];
  char OutputFile[1024];
  struct stat st;

  printf("enter Input File Name: ");
  scanf("%s",InputFile);
  if(stat(InputFile,&st)!=0){
    perror("InputFile does not exit");
    exit(1);
  }

  printf("enter OutPut File Name: ");
  scanf("%s",OutputFile);
  if(stat(OutputFile,&st)==0){
    perror("Your OutputFile exists");
    exit(1);
  }
  /*
   * Open the input file for reading.
   */
  if((in=open(InputFile,O_RDONLY))<0){
    perror(InputFile);
    exit(1);
  }
  /*
   *Open the output File for writing.
   */
  if((out=open(OutputFile,O_CREAT | O_WRONLY, 0755))<0){
    perror(OutputFile);
    exit(1);
  }
  /*
   *Copy data from the first file to the second.
   */
  while((n=read(in,buf,sizeof(buf)))>0)
    write(out,buf,n);

  close(out);
  close(in);
  printf("Copied %s to %s\n", InputFile,OutputFile);
  exit(0);
}

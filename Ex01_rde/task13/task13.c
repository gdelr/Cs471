#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  int sfd;
  int n;
  char buf[1024];
  int FileLength;
  char *FileName=argv[1];
  char *Message=argv[2];

  if((sfd=open(FileName,O_RDWR | O_TRUNC | O_CREAT, 0600))<0){
    perror(FileName);
    exit(1);
  }

  write(sfd, Message, strlen(Message));
  lseek(sfd,0,SEEK_SET);
  printf("\nFile '%s' contains: \n", FileName);
  fflush(stdout);
  n=read(sfd,buf,sizeof(buf));
  write(1,buf,n);
  FileLength=lseek(sfd,0,SEEK_END);
  printf("\n\nFile '%s' length: '%d'\n", FileName, FileLength);

  return 0;
}

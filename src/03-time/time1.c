#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(){

  time_t secs;

  secs = time(NULL);

  printf("%lu\n",secs);
  return(0);
}

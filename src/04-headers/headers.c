#include <stdio.h>
#include "hash.h"

int main(){
  unsigned int h = hash("test", 5);
  printf("Hash value %zu", h);
  return 0;
}

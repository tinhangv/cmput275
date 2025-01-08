#include <stdio.h>

int foo(unsigned int x){
  int sum =0;
  while (x >=0){
    sum += x--;
  }
  return sum;
}

int main(){
  printf("%d\n",foo(5));
}

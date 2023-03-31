#include <stdio.h>
#include <klee/klee.h>
#define SIZE 15

void foo(int *arr) {

  int temp;

  for(int i = 0; i < SIZE; i++) {
    if(arr[i] <= 2) {
      temp = arr[i];
      temp++;
      temp*=10;  
      temp-=15;
      arr[i] = temp;
    } else {
      temp = arr[i];
      temp+=50;
      temp*=20;
      temp-=-5;
      arr[i] = temp;
    }
    
  }
  
  if (arr[0] == -5) {
    // printf("arr[0] is 0 in this path!\n");
     klee_assert(0);
  }

}

int main() {
  int arr[SIZE];

  klee_make_symbolic(&arr, sizeof(arr), "arr");

  foo(arr);

  return 0;
}

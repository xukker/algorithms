#include <stdio.h>
#include <stdlib.h>

int sortcheck(int* arr, int n) {
  if (n < 1) {
    return 1;
  }
  if (arr[n-1] < arr[n-2]) {
    return 0;
  }
  return sortcheck(arr, n-1);
}

void shuffle(int* arr, int n) {
  if (n > 1) {
    for (int i=0;i<n-1;i++) {
      size_t j = i + rand() / (RAND_MAX / (n-i)+1);
      int tmp = arr[j];
      arr[j] = arr[i];
      arr[i] = tmp;
    }
  }
}

void print(int* arr, long its) {
  for (int i=0; i<its; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int steps = 0;
  int arr[] = {1,7,3,29,5};
  size_t n = sizeof(arr)/sizeof(arr[0]);
  while (sortcheck(arr, n) != 1) {
    shuffle(arr, n);
    steps += 1;
  }
	print(arr, n);
  printf("%d", steps);
}

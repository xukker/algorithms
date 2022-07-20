#include <stdio.h>

void * swap (int* arr, int i, int k) {
  int tmp = arr[i];
  arr[i] = arr[k];
  arr[k] = tmp;
}

void print(int* arr, long n, int steps) {
  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d \n", steps);
}

void sort(int* arr, long n, int steps) {
  for (int i=0; i<n-1; i++) {
    for (int k=0; k<n-i-1; k++) {
      if (arr[k] > arr[k+1]) {
        print(arr, n, steps);
        swap(arr, k, k+1);
        steps += 1;
      }
    }
  }
}

int main() {
  int arr[] = {1,7,3,29,5};
  int steps = 0;
  size_t n = sizeof(arr)/sizeof(*arr);
  sort(arr, n, steps);
  print(arr, n, steps);
  return 0;
}

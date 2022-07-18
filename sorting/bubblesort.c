#include <stdio.h>
void * swap (int* arr, int i, int k) {
  int tmp = arr[i];
  arr[i] = arr[k];
  arr[k] = tmp;
}

void sort(int* arr, long its) {
  for (int i=0; i<its-1; i++) {
    for (int k=0; k<its-i-1; k++) {
      if (arr[k] > arr[k+1]) {
        swap(arr, k, k+1);
      }
    }
  }
}

void print(int* arr, long its) {
  for (int i=0; i<its; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = {1,7,3,29,5};
  size_t its = sizeof(arr)/sizeof(*arr);
  sort(arr, its);
  print(arr, its);
  return 0;
}

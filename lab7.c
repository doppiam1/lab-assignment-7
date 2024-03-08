// Caio Bittencourt
// Lab Assignment 7
// March 7th, 2024

#include <stdio.h>

// For bubble sort, just check if the next element
// in the array is less than the current element,
// if that's the case, assign the current element to temp
// and replace the current element with the next element.

void swap(int *a, int *b);
int *bubbleSort(int *arr, int n, int arrNum);
int *selectionSort(int *arr, int n, int arrNum);

int main() {
  int arr1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int arr2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
  int arr3[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
  int arr4[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

  printf("Array 1 before Bubble Sort:\n");
  printf("arr1[9] = ");

  for (int i = 0; i < 9; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  int *bubbleArr1 = bubbleSort(arr1, 9, 1);

  int *bubbleArr2 = bubbleSort(arr2, 9, 2);

  int *selectionArr1 = selectionSort(arr3, 9, 1);

  int *selectionArr2 = selectionSort(arr4, 9, 2);

  return 0;
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int *bubbleSort(int *arr, int n, int arrNum) {
  int i, j, totalSwaps = 0;
  int swapCounts[n];
  for (int i = 0; i < n; i++) {
    swapCounts[i] = 0;
  }

  for (int i = 0; i < n - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if ((arr[j] > arr[j + 1])) {
        swap(&arr[j], &arr[j + 1]);
        swap(&swapCounts[j], &swapCounts[j + 1]);
        swapCounts[j]++;
        swapCounts[j + 1]++;
        swapped = 1;
      }
    }
    if (swapped == 0) {
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    totalSwaps += swapCounts[i];
  }
  totalSwaps = totalSwaps / 2;

  printf("Array %d Bubble Sort:\n", arrNum);

  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swapCounts[i]);
  }
  printf("%d\n", totalSwaps);

  return arr;
}

int *selectionSort(int *arr, int n, int arrNum) {
  int i, j, minIndex;
  int totalSwaps = 0;
  int swapCounts[n];
  for (int i = 0; i < n; i++) {
    swapCounts[i] = 0;
  }

  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(&arr[minIndex], &arr[i]);
      swap(&swapCounts[minIndex], &swapCounts[i]);
      swapCounts[minIndex]++;
      swapCounts[i]++;
      totalSwaps++;
    }
  }
  printf("Array %d Select Sort:\n", arrNum);

  for (int i = 0; i < n; i++) {
    printf("%d: %d\n", arr[i], swapCounts[i]);
  }
  printf("%d\n", totalSwaps);
  return arr;
}

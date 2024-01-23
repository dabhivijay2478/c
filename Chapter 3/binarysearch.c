#include <stdio.h>

// Function to check if an array is sorted
int isSorted(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      return 0; // Not sorted
    }
  }
  return 1; // Sorted
}

// Function to perform bubble sort on an array
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // Swap elements if they are in the wrong order
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      return mid; // Target found
    }

    if (arr[mid] < target) {
      low = mid + 1; // Adjust the search space to the right half
    } else {
      high = mid - 1; // Adjust the search space to the left half
    }
  }

  return -1; // Target not found
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  if (scanf("%d", &size) != 1 || size <= 0) {
    printf("Invalid size. Exiting...\n");
    return 1;
  }

  int arr[size];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Error reading element. Exiting...\n");
      return 1;
    }
  }

  if (!isSorted(arr, size)) {
    printf("Array is not sorted. Applying bubble sort...\n");
    bubbleSort(arr, size);
  }

  // Display the sorted array
  printf("Sorted Array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int target;
  printf("Enter the target element for binary search: ");
  if (scanf("%d", &target) != 1) {
    printf("Invalid target. Exiting...\n");
    return 1;
  }

  int result = binarySearch(arr, size, target);

  if (result != -1) {
    printf("Element %d found at index %d.\n", target, result);
  } else {
    printf("Element %d not found in the array.\n", target);
  }

  return 0;
}

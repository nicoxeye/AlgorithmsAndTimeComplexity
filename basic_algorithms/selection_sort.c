#include <stdio.h>

// O(n^2), literally don't use it
void selection_sort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = { 2 ,6, 1, 5, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    selection_sort(arr,n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
  
    return 0;
}
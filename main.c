#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays into one sorted array
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2) {
    int* merged = (int*)malloc((size1 + size2) * sizeof(int));
    if (merged == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }

    return merged;
}

int main() {
    int numArrays;
    printf("Enter the number of arrays: ");
    scanf("%d", &numArrays);

    // Initialize variables to store input arrays
    int** arrays = (int**)malloc(numArrays * sizeof(int*));
    int* arraySizes = (int*)malloc(numArrays * sizeof(int));
    if (arrays == NULL || arraySizes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input arrays
    for (int i = 0; i < numArrays; i++) {
        do {
            printf("Enter the size of array %d (positive integer): ", i + 1);
            scanf("%d", &arraySizes[i]);
            if (arraySizes[i] <= 0) {
                printf("Invalid input. Please enter a positive integer for the array size.\n");
            }
        } while (arraySizes[i] <= 0);

        arrays[i] = (int*)malloc(arraySizes[i] * sizeof(int));
        if (arrays[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }

        printf("Enter the elements of array %d in sorted order: ", i + 1);
        for (int j = 0; j < arraySizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    // Merge the arrays
    int* merged = arrays[0];
    int mergedSize = arraySizes[0];
    for (int i = 1; i < numArrays; i++) {
        merged = mergeSortedArrays(merged, mergedSize, arrays[i], arraySizes[i]);
        mergedSize += arraySizes[i];
        free(arrays[i]);
    }

    // Print the merged array
    printf("Merged Sorted Array: [");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("] \n");

    // Free allocated memory
    free(arrays);
    free(arraySizes);
    free(merged);

    return 0;
}

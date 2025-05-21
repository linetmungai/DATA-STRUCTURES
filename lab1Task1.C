#include <stdio.h>
#include <stdlib.h>

int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i<n; i++) {
        sum += arr[i];
    }

    return sum;
}

int max(int arr[], int n) {
    if (n==0) {
        return 0;
    }

    int max = 0;
    for (int i=1; i<n; i++) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n<0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integer(s):\n", n);
    for (int i=0; i<n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int sum = summation(arr, n);
    int maxVal = max(arr, n);

    printf("Sum of elements: %d\n", sum);
    printf("Maximum element: %d\n", maxVal);

    return 0;
}

#include<stdio.h>


int findMax(int pInt[10], int n);

int findMin(int pInt[10], int n);

int main() {
    int arr[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("max = %d\n", findMax(arr, n));
    printf("min = %d", findMin(arr, n));

}

int findMin(int pInt[10], int n) {
    int min = pInt[0];
    for (int i = 0; i < 10; ++i) {
        if (min > pInt[i]) {
            min = pInt[i];
        }
    }

    return min;
}

int findMax(int pInt[10], int n) {
    int max = pInt[0];
    for (int i = 0; i < 10; ++i) {
        if (max < pInt[i]) {
            max = pInt[i];
        }
    }

    return max;
}






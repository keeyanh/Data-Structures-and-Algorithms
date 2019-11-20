#include <iostream>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Problem4A(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)


        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main(int argc, const char * argv[]) {

    int a [5] = { 16, 2, 77, 40, 12071 };
    Problem4A(a, 5);
    for (int i = 0; i <5; i+=2) {
        swap(&a[i], &a[i+2]);
    }
}
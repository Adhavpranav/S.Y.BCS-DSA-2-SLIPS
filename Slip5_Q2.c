#include <stdio.h>
#include <stdlib.h>

int a[20], n;

// Accept elements
void accept() {
    printf("Enter the data:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

// Display elements
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

// Heapify function
void heapify(int a[], int top, int last) {
    int largest = top;
    int left = 2 * top + 1;
    int right = 2 * top + 2;

    if (left <= last && a[left] > a[largest])
        largest = left;
    if (right <= last && a[right] > a[largest])
        largest = right;

    if (largest != top) {
        int temp = a[top];
        a[top] = a[largest];
        a[largest] = temp;
        heapify(a, largest, last);
    }
}

// Build max heap
void buildheap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, i, n - 1);
}

// Heapsort
void heapsort(int a[], int n) {
    int temp;
    buildheap(a, n);
    printf("\nInitial Heap:\n");
    display(a, n);

    for (int last = n - 1; last >= 1; last--) {
        // Swap first (max) with last
        temp = a[0];
        a[0] = a[last];
        a[last] = temp;

        printf("\nAfter Iteration %d:\n", n - last);
        display(a, n);

        // Re-heapify the reduced heap
        heapify(a, 0, last - 1);
    }
}

int main() {
    printf("Enter limit: ");
    scanf("%d", &n);
    accept();
    heapsort(a, n);
    printf("\nSorted Array:\n");
    display(a, n);
    return 0;
}
/*
Enter limit: 5
Enter the data:
12 3 5 7 2
*/

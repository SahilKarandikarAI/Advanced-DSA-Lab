#include <stdio.h>

int binsearch_rec(int a[], int l, int h, int key) {
    if (l > h) return -1; // not found
    int mid = l + (h - l) / 2;
    if (a[mid] == key) 
	return mid;
    if (a[mid] > key) 
	return binsearch_rec(a, l, mid - 1, key);
    return binsearch_rec(a, mid + 1, h, key);
}

int main() {
    
    int a[] = {2, 3, 4, 10, 40};
    int n =5;
    int key;
    printf("Enter the key: ");
    scanf("%d",&key);

    int index = binsearch_rec(a, 0, n - 1, key);
    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }
    return 0;
}


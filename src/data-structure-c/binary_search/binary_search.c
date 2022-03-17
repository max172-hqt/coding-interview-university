#include <stdio.h>

int binary_search(const int n, const int arr[], const int target);
int binary_search_recursive(const int arr[], int lo, int hi, int target);

int main()
{
    int n, target;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);
    /* int res = binary_search(n, arr, target); */
    int res = binary_search_recursive(arr, 0, n-1, target);

    if (res == '\0') {
        printf("Not found\n");
    } else {
        printf("Index: %d\n", res);
    }

    return 0;
}

int binary_search(const int n, const int arr[], const int target)
{
    int lo, hi, mid;
    lo = 0;
    hi = n - 1;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return '\0';
}

int binary_search_recursive(const int arr[], int lo, int hi, int target)
{
    if (lo > hi) return '\0';

    int mid;
    mid = lo + (hi - lo) / 2;

    if (arr[mid] == target) 
        return mid;
    else if (arr[mid] < target) 
        return binary_search_recursive(arr, mid + 1, hi, target);
    else
        return binary_search_recursive(arr, lo, mid - 1, target);
}

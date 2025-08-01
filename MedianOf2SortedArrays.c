/*
 ============================================================================
 Name        : Median of Two Sorted Arrays
 Author      : Heizel Ann Joseph
 Description : 
     Given two sorted arrays nums1 and nums2 of size m and n respectively,
     this program returns the median of the two sorted arrays.
     The solution runs in O(log(min(m, n))) time complexity using binary search.

     Constraints:
     - Arrays must be sorted in non-decreasing order.
     - 0 <= m, n <= 1000
     - 1 <= m + n <= 2000
     - Elements range from -10^6 to 10^6
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return ((double)fmax(maxLeftX, maxLeftY) + fmin(minRightX, minRightY)) / 2;
            } else {
                return (double)fmax(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }

    return -1.0;
}

int main() {
    int m, n;
    printf("Enter the number of elements in first sorted array: ");
    scanf("%d", &m);

    int* nums1 = (int*)malloc(m * sizeof(int));
    printf("Enter %d sorted elements for the first array:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter the number of elements in second sorted array: ");
    scanf("%d", &n);

    int* nums2 = (int*)malloc(n * sizeof(int));
    printf("Enter %d sorted elements for the second array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    double median = findMedianSortedArrays(nums1, m, nums2, n);
    printf("Median of the two sorted arrays: %.5f\n", median);

    free(nums1);
    free(nums2);

    return 0;
}

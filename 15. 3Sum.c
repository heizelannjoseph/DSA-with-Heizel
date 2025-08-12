/*
 * File: threeSum.c
 * Author: Heizel Ann Joseph
 * Description:
 *   Implementation of the "3Sum" problem in C.
 *   Given an integer array nums, returns all unique triplets [nums[i], nums[j], nums[k]]
 *   such that i != j, i != k, j != k, and nums[i] + nums[j] + nums[k] == 0.
 *   The returned set contains no duplicate triplets.
 *
 
 *   - Constraints:
 *        3 <= numsSize <= 3000
 *        -10^5 <= nums[i] <= 10^5
 * 
 */
 
#include <stdlib.h>

static int cmpfunc(const void* a, const void* b) {
    int va = *(const int*)a;
    int vb = *(const int*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;

    if (numsSize < 3) {
        *returnColumnSizes = malloc(0);
        return malloc(0);
    }

    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int cap = 16;
    int count = 0;
    int** result = malloc(cap * sizeof(int*));
    int* colSizes = malloc(cap * sizeof(int));
    if (!result || !colSizes) {
        free(result);
        free(colSizes);
        *returnColumnSizes = malloc(0);
        return malloc(0);
    }

    for (int i = 0; i < numsSize - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  
        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (count == cap) {
                    cap *= 2;
                    int** tmpR = realloc(result, cap * sizeof(int*));
                    int* tmpC = realloc(colSizes, cap * sizeof(int));
                    if (!tmpR || !tmpC) break;
                    result = tmpR;
                    colSizes = tmpC;
                }
                int* trip = malloc(3 * sizeof(int));
                trip[0] = nums[i];
                trip[1] = nums[left];
                trip[2] = nums[right];
                result[count] = trip;
                colSizes[count] = 3;
                ++count;

                ++left;
                --right;
                while (left < right && nums[left] == nums[left - 1]) ++left;
                while (left < right && nums[right] == nums[right + 1]) --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }

    *returnSize = count;
    if (count == 0) {
        free(result);
        *returnColumnSizes = malloc(0);
        return malloc(0);
    }

    result = realloc(result, count * sizeof(int*));
    colSizes = realloc(colSizes, count * sizeof(int));
    *returnColumnSizes = colSizes;
    return result;
}

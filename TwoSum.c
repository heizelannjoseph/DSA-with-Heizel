// Problem: Two Sum
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
//
// Constraints:
// 2 <= nums.length <= 10^4
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9
// Only one valid answer exists.
//
// Language: C

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int numsSize, target;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &numsSize);

    if (numsSize < 2) {
        printf("Array must have at least 2 elements.\n");
        return 1;
    }

    int* nums = (int*)malloc(numsSize * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers:\n", numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        printf("Values: [%d, %d]\n", nums[result[0]], nums[result[1]]);
        free(result);
    } else {
        printf("No valid pair found.\n");
    }

    free(nums);

    return 0;
}

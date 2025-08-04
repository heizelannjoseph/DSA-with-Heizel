/*
Problem: Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that 
the two endpoints of the i-th line are (i, 0) and (i, height[i]).

Find two lines that, together with the x-axis, form a container that can store the maximum amount of water.
The container cannot be slanted.

Examples:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The lines at indices 1 and 8 form the container with the largest area (width = 8-1, height = 7),
so area = 7 * 7 = 49.

Input: height = [1,1]
Output: 1

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/

#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int max = 0;
    int left = 0;
    int right = heightSize - 1;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int width = right - left;
        int area = width * h;

        if (area > max) {
            max = area;
        }

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};
    int size = sizeof(height) / sizeof(height[0]);
    printf("Max Area: %d\n", maxArea(height, size));

    int height2[] = {1,1};
    int size2 = sizeof(height2) / sizeof(height2[0]);
    printf("Max Area: %d\n", maxArea(height2, size2));

    return 0;
}

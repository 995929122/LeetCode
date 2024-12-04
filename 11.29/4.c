// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

// 算法的时间复杂度应该为 O(log (m+n)) 。

#include <stdio.h>
#include <limits.h>

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
        
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];
        
        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return ((double)fmax(maxX, maxY) + fmin(minX, minY)) / 2;
            } else {
                return (double)fmax(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    
    return -1; // Should never reach here
}
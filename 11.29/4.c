// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

// 算法的时间复杂度应该为 O(log (m+n)) 。

#include <stdio.h>
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int sum = nums1Size + nums2Size;
    double ans = 0;
    int i = 0, j = 0;
    if(sum%2==1)
    {
    int moves = sum / 2;
    for (moves; moves > 0; moves--)
    {
        if (i < nums1Size && j < nums2Size)
            if (nums1[i] <= nums2[j])
                i++;
            else
                j++;
        else if (i == nums1Size)
            j++;
        else
            i++;
    }
    if (i<nums1Size&&j<nums2Size)  
        ans = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
    if (i==nums1Size&&j<nums2Size)  
        ans = nums2[j];
    if (i<nums1Size&&j==nums2Size)  
        ans = nums1[i];
    }
    if (sum % 2 == 0)
    {
    int moves = (sum/2)-1;
    for (moves; moves > 0; moves--)
    {
        if (i < nums1Size && j < nums2Size)
            if (nums1[i] <= nums2[j])
                i++;
            else
                j++;
        else if (i == nums1Size)
            j++;
        else
            i++;
    }
    if (i<nums1Size&&j<nums2Size)  ans=((double)nums1[i]+(double)nums2[j])/2;
    if (i==nums1Size&&j<nums2Size)  ans=((double)nums2[j+1]+(double)nums2[j])/2;
    if (i<nums1Size&&j==nums2Size)  ans=((double)nums1[i+1]+(double)nums1[i])/2;
    }
    return ans;
}
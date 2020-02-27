/*************************************************************************
	> File Name: LeetCode-88.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时29分22秒
 ************************************************************************/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *nums = (int *)malloc(sizeof(int) * (m + n));
    int i = 0, j = 0, k = 0;
    while (i < m + n  && j < m && k < n) {
        if (nums1[j] <= nums2[k]) {
            nums[i++] = nums1[j++];
        } else {
            nums[i++] = nums2[k++];
        }
    }
    while (k < n) {
        nums[i++] = nums2[k++];
    }
    while (j < m) {
        nums[i++] = nums1[j++];
    }
    memcpy(nums1, nums, sizeof(int) * (m + n));
}

/*************************************************************************
	> File Name: LeetCode-35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时07分12秒
 ************************************************************************/

int searchInsert(int* nums, int numsSize, int target){
    int head = -1, tail = numsSize - 1;
    while (head < tail) {
        int mid = (head + tail + 1) / 2;
        if (nums[mid] < target) head = mid;
        else tail = mid - 1;
    }
    return head + 1;
}

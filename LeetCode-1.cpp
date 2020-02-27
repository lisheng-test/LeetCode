/*************************************************************************
	> File Name: LeetCode-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 18时55分40秒
 ************************************************************************/

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   int *a = (int *)malloc(sizeof(int) * 2);
    int i, j;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                return a;
            }
        }
    }               
    *returnSize = 0;
    return a;
}

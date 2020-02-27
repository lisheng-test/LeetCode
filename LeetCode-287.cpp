/*************************************************************************
	> File Name: LeetCode-287.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 18时53分50秒
 ************************************************************************/

int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];//因为值的范围和下标范围一样，可以这么做，相当于转化成链表
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    q = nums[0];//因为2倍速的原因，此时将q放回起点，p，q一定相距一个环长
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}

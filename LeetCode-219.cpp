/*************************************************************************
	> File Name: LeetCode-219.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 15时09分19秒
 ************************************************************************/

#define swap(a, b) {\
   __typeof(a) __temp = a;\
   a = b; b = __temp;\ 
}

void merge_sort(int *num, int l, int r) {
    if (r - l <= 1) {
        if (r - l == 1 && num[l] > num[r]) {
            swap(num[l], num[r]);
        }
        return ;
    }
    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1, r);
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int p1 = l, p2 = mid + 1, k = 0;//递归回溯过程中每个小数组的顺序已经排好了
    while (p1 <= mid || p2 <= r) {//将两个数组合并成新的数组的过程
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
            temp[k++] = num[p1++];
        } else {
            temp[k++] = num[p2++];
        }
    }
    memcpy(num + l, temp, sizeof(int) * (r - l + 1));
    free(temp);
    return ;
}


bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    merge_sort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize - k; i++) {
        if (nums[i] == nums[i + k]) return true;
    }
    return false;
}

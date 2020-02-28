/*************************************************************************
	> File Name: LeetCode-350.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 15时14分51秒
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
    int p1 = l, p2 = mid + 1, k = 0;
    while (p1 <= mid || p2 <= r) {
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

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    merge_sort(nums1, 0, nums1Size - 1);
    merge_sort(nums2, 0, nums2Size - 1);
    int i = 0;
    int j = 0;
    int k = 0;
    int *str = (int *)malloc(sizeof(int) * nums1Size);
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) i++;
        else if (nums1[i] > nums2[j]) j++;
        else {
            str[k] = nums1[i];
            i++;
            j++;
            k++;
        }
    }
    *returnSize = k;
    return str;
}

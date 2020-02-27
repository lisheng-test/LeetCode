/*************************************************************************
	> File Name: LeetCode-21.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 19时00分59秒
 ************************************************************************/

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
     if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}

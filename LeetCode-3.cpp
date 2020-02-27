/*************************************************************************
	> File Name: LeetCode-3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 18时57分16秒
 ************************************************************************/

int lengthOfLongestSubstring(char * s){
    int i;
    int ret = 0;
    int tmp = 0;
    int table[128] = {0}; 

    for(i = 0; i < strlen(s); i++){
        int index = (int)s[i];
        if(table[index] == 0){
            ++tmp;
        } else {
            ret = (ret >= tmp) ? ret : tmp;
            tmp = (tmp >= i + 1 - table[index]) ? i + 1 - table[index] : ++tmp;
        }
        table[index] = i + 1;
    }
    ret = (ret >= tmp) ? ret : tmp;
    return ret;
}

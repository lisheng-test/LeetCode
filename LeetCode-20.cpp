/*************************************************************************
	> File Name: LeetCode-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 21时04分46秒
 ************************************************************************/

bool isValid(char * s){
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1, flag = 1;//记录括号类型匹不匹配
    while (s[0]) {
        switch (s[0]) {
            case '(':
            case '[':
            case '{': stack[++top] = s[0]; break;
            case ')': flag = (top != -1) && (stack[top--] == '(');break;
            case ']': flag = (top != -1) && (stack[top--] == '[');break;
            case '}': flag = (top != -1) && (stack[top--] == '{');break;
        }
        if (!flag) break;
        s++;
    }
    free(stack);
    return flag && top == -1;
}

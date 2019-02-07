bool isValid(char* s) {
    int length = strlen(s);
    char *stack = (char *)malloc(length * sizeof(char));
    int stack_top = 0;
    
    for(int i = 0; i < length; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[stack_top++] = s[i];
        } else {
            if(stack_top == 0) {
                return false;
            }
            if(stack[stack_top-1] == '(' && s[i] == ')') {
                stack_top--;
            } else if(stack[stack_top-1] == '[' && s[i] == ']') {
                stack_top--;
            } else if(stack[stack_top-1] == '{' && s[i] == '}') {
                stack_top--;
            } else {
                return false;
            }
        }
    }
    free(stack);
    return stack_top == 0;
}


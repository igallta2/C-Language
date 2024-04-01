#include <stdio.h>
#include <stdbool.h>

// 定义栈的结构和操作
#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initialize(Stack *stack) {
    stack->top = -1;
}

// 入栈
void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

// 出栈
char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

// 检查括号匹配
bool isBalanced(char exp[]) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.top == -1; // 栈为空表示所有括号都匹配
}

// 测试函数
int main() {
    char exp[100];
    scanf("%s",exp);
     if (isBalanced(exp)) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }

    return 0;
}

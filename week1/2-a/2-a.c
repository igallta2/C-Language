#include <stdio.h>
#include <stdbool.h>

// ����ջ�Ľṹ�Ͳ���
#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// ��ʼ��ջ
void initialize(Stack *stack) {
    stack->top = -1;
}

// ��ջ
void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = item;
    }
}

// ��ջ
char pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

// �������ƥ��
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

    return stack.top == -1; // ջΪ�ձ�ʾ�������Ŷ�ƥ��
}

// ���Ժ���
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

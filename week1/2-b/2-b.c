#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef char DataType;

typedef struct {
    DataType data[MAX_SIZE];
    int top;
} SeqStack;

// 出栈操作
int Pop(SeqStack *s, DataType *x) {
    if (s->top == -1) {
        return 0; // 栈为空，出栈失败
    } else {
        *x = s->data[s->top]; // 获取栈顶元素的值
        s->top--; // 栈顶指针向下移动一个位置
        return 1; // 出栈成功
    }
}

//入栈
int Push(SeqStack *s, DataType x) {
    if (s->top == MAX_SIZE - 1) {
        printf("栈已满!\n");
        return 0;
    } else {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

int main() {
    SeqStack stack1;
    SeqStack stack2;
    stack1.top = -1;
    stack2.top = -1;

    char exp[100];
    scanf("%s", exp);
    int length = strlen(exp);
    for (int i = 0; i < length; i++) {
        Push(&stack1, exp[i]);
    }

    // 出栈并将元素存储到 exp 数组中
    DataType popped_element;
    int index = 0;
    while (Pop(&stack1, &popped_element)) {
        exp[index++] = popped_element;
        Push(&stack2, popped_element);
    }

    // 将元素重新存储到 stack1 中
    while (Pop(&stack2, &popped_element)) {
        Push(&stack1, popped_element);
    }

    // 输出结果
    printf("Reversed string: %s\n", exp);

    return 0;
}


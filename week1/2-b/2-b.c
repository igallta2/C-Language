#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef char DataType;

typedef struct {
    DataType data[MAX_SIZE];
    int top;
} SeqStack;

// ��ջ����
int Pop(SeqStack *s, DataType *x) {
    if (s->top == -1) {
        return 0; // ջΪ�գ���ջʧ��
    } else {
        *x = s->data[s->top]; // ��ȡջ��Ԫ�ص�ֵ
        s->top--; // ջ��ָ�������ƶ�һ��λ��
        return 1; // ��ջ�ɹ�
    }
}

//��ջ
int Push(SeqStack *s, DataType x) {
    if (s->top == MAX_SIZE - 1) {
        printf("ջ����!\n");
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

    // ��ջ����Ԫ�ش洢�� exp ������
    DataType popped_element;
    int index = 0;
    while (Pop(&stack1, &popped_element)) {
        exp[index++] = popped_element;
        Push(&stack2, popped_element);
    }

    // ��Ԫ�����´洢�� stack1 ��
    while (Pop(&stack2, &popped_element)) {
        Push(&stack1, popped_element);
    }

    // ������
    printf("Reversed string: %s\n", exp);

    return 0;
}


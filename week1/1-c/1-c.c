#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
    DataType data;
    struct node* next;
} LNode, *LinkList;

// �������壺��������β�巨��
LinkList creatLinkListR(LinkList head) {
    int i, n;
    LinkList p;
    printf("����������ĳ��ȣ�");
    scanf("%d", &n);
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL; // ͷ�ڵ��ʼ��
    p = head;
    printf("�����������е�Ԫ�أ�");
    for (i = 0; i < n; i++) {
        p->next = (LinkList)malloc(sizeof(LNode)); // ָ���´����Ľڵ�
        p = p->next;
        scanf("%d", &p->data);
    }
    p->next = NULL;
    return head;
}

// �������壺��ת����
LinkList reverseList(LinkList head) {
    LinkList prev = NULL;
    LinkList current = head->next; // ����ͷ�ڵ�
    LinkList next = NULL;

    while (current != NULL) {
        // ���浱ǰ�ڵ����һ���ڵ�
        next = current->next;
        // ��ת��ǰ�ڵ��ָ�뷽��
        current->next = prev;
        // ����prev��currentָ��
        prev = current;
        current = next;
    }

    // ����ͷ�ڵ��ָ��
    head->next = prev;
    return head;
}

void printList(LinkList head) {
    LinkList p = head->next; // ����ͷ�ڵ�
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList head = NULL;
    head = creatLinkListR(head);

    printf("Original list: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    LinkList temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

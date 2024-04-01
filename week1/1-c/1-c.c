#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
    DataType data;
    struct node* next;
} LNode, *LinkList;

// 函数定义：创建链表（尾插法）
LinkList creatLinkListR(LinkList head) {
    int i, n;
    LinkList p;
    printf("请输入链表的长度：");
    scanf("%d", &n);
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL; // 头节点初始化
    p = head;
    printf("请输入链表中的元素：");
    for (i = 0; i < n; i++) {
        p->next = (LinkList)malloc(sizeof(LNode)); // 指向新创建的节点
        p = p->next;
        scanf("%d", &p->data);
    }
    p->next = NULL;
    return head;
}

// 函数定义：反转链表
LinkList reverseList(LinkList head) {
    LinkList prev = NULL;
    LinkList current = head->next; // 跳过头节点
    LinkList next = NULL;

    while (current != NULL) {
        // 保存当前节点的下一个节点
        next = current->next;
        // 反转当前节点的指针方向
        current->next = prev;
        // 更新prev和current指针
        prev = current;
        current = next;
    }

    // 更新头节点的指向
    head->next = prev;
    return head;
}

void printList(LinkList head) {
    LinkList p = head->next; // 跳过头节点
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

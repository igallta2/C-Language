#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *next;
} LNode, *LinkList;

// 创建链表，尾插法
LinkList createListR(LinkList head) {
    int i, n;
    LinkList p;
    printf("请输入链表的长度: ");
    scanf("%d", &n);
    head = (LinkList)malloc(sizeof(LNode)); // 创建头结点
    p = head;
    printf("请输入链表的元素: ");
    for (i = 1; i <= n; i++) {
        p->next = (LinkList)malloc(sizeof(LNode));
        p = p->next;
        scanf("%d", &p->data);
    }
    p->next = NULL; // 尾结点指针置空
    return head;
}

// 在第i个位置插入元素x
int insertList(LinkList head, int i, DataType x) {
    int k = 0;
    LinkList p, s;
    p = head;
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }
    if (p == NULL) {
        printf("指定的插入位置不合理!\n");
        return 0;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    return 1;
}

// 删除第i个位置的节点
int deleteNode(LinkList head, int i) {
    LinkList r, p;
    int k = 0;
    p = head;
    while (p && k < i - 1) {
        p = p->next;
        k++;
    }
    if (k > i - 1 || !(p->next)) {
        printf("删除节点的位置不正确\n");
        return 0;
    }
    r = p->next;
    p->next = r->next;
    free(r);
    return 1;
}

// 打印链表
void printList(LinkList head) {
    LinkList p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    LinkList head = NULL;
    head = createListR(head); // 创建链表
    printf("初始链表: ");
    printList(head);

    int n, m;
    printf("请输入要插入的位置和元素: ");
    scanf("%d %d", &n, &m);
    insertList(head, n, m); // 插入元素
    printf("插入后链表: ");
    printList(head);

    int i;
    printf("请输入要删除的位置: ");
    scanf("%d", &i);
    deleteNode(head, i); // 删除节点
    printf("删除后链表: ");
    printList(head);

    return 0;
}

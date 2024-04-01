#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node {
    DataType data;
    struct node *next;
} LNode, *LinkList;

// ��������β�巨
LinkList createListR(LinkList head) {
    int i, n;
    LinkList p;
    printf("����������ĳ���: ");
    scanf("%d", &n);
    head = (LinkList)malloc(sizeof(LNode)); // ����ͷ���
    p = head;
    printf("�����������Ԫ��: ");
    for (i = 1; i <= n; i++) {
        p->next = (LinkList)malloc(sizeof(LNode));
        p = p->next;
        scanf("%d", &p->data);
    }
    p->next = NULL; // β���ָ���ÿ�
    return head;
}

// �ڵ�i��λ�ò���Ԫ��x
int insertList(LinkList head, int i, DataType x) {
    int k = 0;
    LinkList p, s;
    p = head;
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }
    if (p == NULL) {
        printf("ָ���Ĳ���λ�ò�����!\n");
        return 0;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    return 1;
}

// ɾ����i��λ�õĽڵ�
int deleteNode(LinkList head, int i) {
    LinkList r, p;
    int k = 0;
    p = head;
    while (p && k < i - 1) {
        p = p->next;
        k++;
    }
    if (k > i - 1 || !(p->next)) {
        printf("ɾ���ڵ��λ�ò���ȷ\n");
        return 0;
    }
    r = p->next;
    p->next = r->next;
    free(r);
    return 1;
}

// ��ӡ����
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
    head = createListR(head); // ��������
    printf("��ʼ����: ");
    printList(head);

    int n, m;
    printf("������Ҫ�����λ�ú�Ԫ��: ");
    scanf("%d %d", &n, &m);
    insertList(head, n, m); // ����Ԫ��
    printf("���������: ");
    printList(head);

    int i;
    printf("������Ҫɾ����λ��: ");
    scanf("%d", &i);
    deleteNode(head, i); // ɾ���ڵ�
    printf("ɾ��������: ");
    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LNode, *LinkList;

LinkList creatLinkListR(LinkList head){
    int i,n;
    LinkList p;
    printf("����������ĳ��ȣ�");
    scanf("%d",&n);
    head=(LinkList)malloc(sizeof(LNode));
    p=head;
    printf("�����������е�Ԫ�أ�");
    for(i=0;i<n;i++){
        p->next=(LinkList)malloc(sizeof(LNode)); // ָ���´����Ľڵ�
        p=p->next;
        scanf("%d",&p->data);
    }
    p->next=NULL;
    return head;
}

int getLength(LinkList head) {
    int length = 0;
    LinkList p = head->next; // ����ͷ�ڵ�
    while (p != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

LinkList findMiddle(LinkList head,int length){
    if(length%2==0){
        struct node *slow=head;
        struct node *fast=head;
        while(fast!=NULL&&fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
        }
        return slow->next; // �����м�ڵ����һ���ڵ�
    }
    else
    {
        struct node *slow=head;
        struct node *fast=head;
        while(fast!=NULL&&fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
        }
        return slow; //�����м�ڵ�
    }

}

void printList(LinkList head){
    LinkList p=head->next;
    while(p!=NULL){
        printf("%d ",p->data); // ��ӡ�ڵ��ֵ�����ǵ�ַ
        p=p->next; // ȱ���˷ֺ�
    }
    printf("\n");
}

int main()
{
    LinkList head=NULL;
    head=creatLinkListR(head);
    int length=getLength(head);
    LinkList middle_node=findMiddle(head,length);
    printf("�м�ڵ����һ���ڵ��ֵΪ: %d\n", middle_node->data);
    return 0;
}

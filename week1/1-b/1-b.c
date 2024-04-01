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
    printf("请输入链表的长度：");
    scanf("%d",&n);
    head=(LinkList)malloc(sizeof(LNode));
    p=head;
    printf("请输入链表中的元素：");
    for(i=0;i<n;i++){
        p->next=(LinkList)malloc(sizeof(LNode)); // 指向新创建的节点
        p=p->next;
        scanf("%d",&p->data);
    }
    p->next=NULL;
    return head;
}

int getLength(LinkList head) {
    int length = 0;
    LinkList p = head->next; // 跳过头节点
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
        return slow->next; // 返回中间节点的下一个节点
    }
    else
    {
        struct node *slow=head;
        struct node *fast=head;
        while(fast!=NULL&&fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
        }
        return slow; //返回中间节点
    }

}

void printList(LinkList head){
    LinkList p=head->next;
    while(p!=NULL){
        printf("%d ",p->data); // 打印节点的值而不是地址
        p=p->next; // 缺少了分号
    }
    printf("\n");
}

int main()
{
    LinkList head=NULL;
    head=creatLinkListR(head);
    int length=getLength(head);
    LinkList middle_node=findMiddle(head,length);
    printf("中间节点的下一个节点的值为: %d\n", middle_node->data);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// �����½ڵ�
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �������������
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // �ݹ����������
    inorderTraversal(root->left);

    // ���ʸ��ڵ�
    printf("%c ", root->data);

    // �ݹ����������
    inorderTraversal(root->right);
}

int main() {
    // ����ʾ��������
    struct TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');

    // ִ���������
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // �ͷ��ڴ�
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

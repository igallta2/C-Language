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

// ��α���������
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // �����������ڲ�α���
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        // ������
        struct TreeNode* current = queue[front++];
        printf("%c ", current->data);

        // ��������ӽڵ㣬�����ӽڵ������
        if (current->left != NULL)
            queue[rear++] = current->left;

        // ��������ӽڵ㣬�����ӽڵ������
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
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

    // ִ�в�α���
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
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

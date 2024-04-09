#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 创建新节点
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 层次遍历二叉树
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // 创建队列用于层次遍历
    struct TreeNode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        // 出队列
        struct TreeNode* current = queue[front++];
        printf("%c ", current->data);

        // 如果有左子节点，将左子节点入队列
        if (current->left != NULL)
            queue[rear++] = current->left;

        // 如果有右子节点，将右子节点入队列
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {
    // 构建示例二叉树
    struct TreeNode* root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    root->right->left = createNode('F');
    root->right->right = createNode('G');

    // 执行层次遍历
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // 释放内存
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}

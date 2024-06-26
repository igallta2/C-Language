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

// 中序遍历二叉树
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    // 递归遍历左子树
    inorderTraversal(root->left);

    // 访问根节点
    printf("%c ", root->data);

    // 递归遍历右子树
    inorderTraversal(root->right);
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

    // 执行中序遍历
    printf("Inorder Traversal: ");
    inorderTraversal(root);
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

#include <stdio.h>
#include <stdlib.h>
#include "treetrv.h"

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    // 트리 생성
    GenerateLinkTree(root);

    // 생성한 트리를 스택 반복형식으로 순회
    LinkOrders(root);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "treetrv.h"

int main() {
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    // Ʈ�� ����
    GenerateLinkTree(root);

    // ������ Ʈ���� ���� �ݺ��������� ��ȸ
    LinkOrders(root);

    return 0;
}
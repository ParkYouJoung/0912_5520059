#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void Push(Stack* stack, TreeNode* treeNode) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Push: %d\n", treeNode->data);
}

TreeNode* Pop(Stack* stack) {
    if (IsEmpty(stack)) {
        return NULL;
    }

    StackNode* temp = stack->top;
    TreeNode* node = temp->treeNode;
    stack->top = temp->next;
    free(temp);

    printf("Pop: %d\n", node->data);
    return node;
}

int IsEmpty(Stack* stack) {
    return stack->top == NULL;
}
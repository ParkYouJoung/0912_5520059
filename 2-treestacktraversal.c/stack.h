#pragma once
#ifndef STACK_H
#define STACK_H

#include "treetrv.h"

typedef struct StackNode {
    TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void Push(Stack* stack, TreeNode* treeNode);
TreeNode* Pop(Stack* stack);
int IsEmpty(Stack* stack);

#endif

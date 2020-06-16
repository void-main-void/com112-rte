#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdlib.h>

typedef unsigned int uint;
typedef struct Node {
  int value;
  struct Node *left;
  struct Node *right;
} Node, *NodePtr;

int m_max(int x, int y);

void treeDestroy(NodePtr root);
int  treeHeight(NodePtr root);
int  treeBalance(NodePtr root);
int  treePrintUtil(NodePtr root, int is_left, int offset, int depth, char s[20][255]);
void treePrint2D(NodePtr root);
void treeRightRotate(NodePtr *root);
void treeLeftRotate(NodePtr *root);
void treeLeftRightRotate(NodePtr *root);
void treeRightLeftRotate(NodePtr *root);

NodePtr nodeCreate(int value);
void    nodeDestroy(NodePtr node);
int     nodeInsert(NodePtr *root, int value);
int     nodeRemove(NodePtr *root, int value);

#endif

#include "com112_arvoreAVL.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  NodePtr tree_root = 0;
  tree_root = nodeCreate(2);
  tree_root->left = nodeCreate(1);
  tree_root->right = nodeCreate(3);
  treePrint(tree_root);
  treeDestroy(tree_root);
  return 0;
}

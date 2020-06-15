#include "com112_arvoreAVL.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  NodePtr tree = 0;
  tree = nodeCreate(2);
  nodeInsert(&tree, 1);
  nodeInsert(&tree, 3);
  treePrint(tree);
  treeDestroy(tree);
  return 0;
}

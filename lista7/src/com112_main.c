#include "com112_arvoreAVL.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  NodePtr tree = 0;
  nodeInsert(&tree, 50);
  treePrint(tree);
  nodeInsert(&tree, 40);
  treePrint(tree);
  nodeInsert(&tree, 60);
  treePrint(tree);
  nodeInsert(&tree, 30);
  treePrint(tree);
  nodeInsert(&tree, 70);
  treePrint(tree);
  nodeInsert(&tree, 20);
  treePrint(tree);
  nodeInsert(&tree, 80);
  treePrint(tree);
  nodeInsert(&tree, 10);
  treePrint(tree);
  nodeInsert(&tree, 90);
  treePrint(tree);
  nodeInsert(&tree, 100);
  treePrint(tree);
  nodeInsert(&tree, 0);
  treePrint(tree);
  treeDestroy(tree);
  return 0;
}

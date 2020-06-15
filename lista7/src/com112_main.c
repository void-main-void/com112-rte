#include "com112_arvoreAVL.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  NodePtr tree = 0;
  nodeInsert(&tree, 50);
  treePrint2D(tree);
  nodeInsert(&tree, 40);
  treePrint2D(tree);
  nodeInsert(&tree, 60);
  treePrint2D(tree);
  nodeInsert(&tree, 30);
  treePrint2D(tree);
  nodeInsert(&tree, 70);
  treePrint2D(tree);
  nodeInsert(&tree, 20);
  treePrint2D(tree);
  nodeInsert(&tree, 80);
  treePrint2D(tree);
  nodeInsert(&tree, 10);
  treePrint2D(tree);
  nodeInsert(&tree, 90);
  treePrint2D(tree);
  nodeInsert(&tree, 100);
  treePrint2D(tree);
  nodeInsert(&tree, 0);
  treePrint2D(tree);
  treeDestroy(tree);
  return 0;
}

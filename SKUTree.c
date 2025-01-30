#include "SKUTree.h"
#include <stdlib.h>

bool addSku(SKUTree *tree, const char *SkUPath){
    if(SkUPath[0] != 's' || SkUPath[1] != '_'){
        return false;
    }
    if(tree->root == NULL){
        int maxChildren = tree->maxChildren[0];
        SKUNode **children = (SKUNode**) malloc(maxChildren * sizeof(SKUNode*));
        tree->root = (SKUNode*){0, maxChildren, children};
    }

}

SKUNode* findSKU(SKUTree *root, const char *SKUPath){

}

void countNumOfSKUsInSKUChart(SKUNode *node, unsigned int *count){

}

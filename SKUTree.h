#include <stdbool.h>

typedef struct{
    int depth;
    int maxChildren;
    SKUNode **children;
}SKUNode;

typedef struct{
    int numInternalLevels;
    int **maxChildren;
    SKUNode *root;
} SKUTree;

bool addSKU(SKUTree *root, const char *SkUPath);

SKUNode* findSKU(SKUTree *root, const char *SKUPath);

void countNumOfSKUsInSKUChart(SKUNode *node, unsigned int *count);
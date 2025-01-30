#include <stdbool.h>

struct SKUNodes{
    int depth;
    char *SKUID;
    struct SKUNodes **children;
};
typedef struct SKUNodes SKUNode;

typedef struct{
    int numInternalLevels;
    int *maxChildren;
    SKUNode *root;
}SKUTree;

bool addSKU(SKUTree *tree, const char *SKUPath);

SKUNode* findSKU(SKUTree *tree, const char *SKUPath);

int countNumOfSKUsInSKUChart(SKUTree *tree, SKUNode *node);
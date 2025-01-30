#include <stdio.h>
#include <stdlib.h>
#include "SKUTree.h"

int main(int argc, char **argv){
    //check for correct number of arguments
    if(argc != 3){
        printf("Expected 3 arguments got %d\n", argc);
        exit(1);
    }
    
    //initialize file variables
    FILE *skuChart = NULL;
    FILE *testFile = NULL;

    //attempt to open skuChart
    skuChart = fopen(argv[1], "r");
    if(skuChart == NULL){
        printf("Unable to open %s\n", argv[1]);
        exit(1);
    }

    //attempt to open testFile
    testFile = fopen(argv[2], "r");
    if(testFile == NULL){
        printf("Unable to open %s\n", argv[2]);
        fclose(skuChart);
        exit(1);
    }

    const int maxStrLen = 50;
    char levelsLine[maxStrLen];
    char maxChildrenLine[maxStrLen];
    fgets(levelsLine, maxStrLen, skuChart);
    fgets(maxChildrenLine, maxStrLen, skuChart);

    int internalLevels = 0;
    sscanf(levelsLine, "internalLevels=%d", &internalLevels);

    int maxChildren[internalLevels];
    
    for(int i = 0; i < internalLevels; i++){
        maxChildren[i] = maxChildrenLine[i * 2] - '0';
    }

    SKUTree tree = (SKUTree){internalLevels, maxChildren, NULL}; 

    char codeLine[maxStrLen];
    while(fgets(codeLine, maxStrLen, skuChart) != NULL){
        addSKU(&tree, codeLine);
    }

    char testLine[maxStrLen];
    while(fgets(testLine, maxStrLen, testFile) != NULL){
        SKUNode *node = findSKU(&tree, testLine);
        int total = countNumOfSKUsInSKUChart(&tree, node);
        char testLineClean[maxStrLen];
        sscanf(testLine, "%s\r", testLineClean);
        printf("%s %d\n", testLineClean, total);
    }

    fclose(skuChart);
    fclose(testFile);
    return 0;
}
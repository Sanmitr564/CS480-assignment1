#include <stdlib.h>
#include "SKUTree.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

SKUNode* newSKUNode(int depth, int maxChildren, const char *SKUPath){
    SKUNode *newNode = (SKUNode*)(malloc(sizeof(SKUNode)));
    SKUNode **children = (SKUNode**)(malloc(maxChildren * sizeof(SKUNode*)));
    char *id = (char*)(malloc((2 * (depth + 1))*sizeof(char)));
    strncpy(id, SKUPath, 1 + 2 * depth);
    id[1 + 2 * depth] = '\0';
    newNode->depth = depth;
    newNode->SKUID = id;
    newNode->children = children;
    for(int i = 0; i < maxChildren; i++){
        newNode->children[i] = NULL;
    }
    return newNode;
}

void getPath(char *path, int maxLength, const char *SKUPath, int *length){
    int index = 0;
    *length = 0;

    if(SKUPath[index] != 's'){
        return;
    }
    path[index] = 's';
    (*length)++;

    index++;
    if(SKUPath[index] != '_'){
        return;
    }
    index++;

    while(*length < maxLength){
        if(!isdigit(SKUPath[index])){
            return;
        }
        if(isdigit(SKUPath[index + 1])){
            return;
        }
        path[*length] = SKUPath[index];
        (*length)++;
        if(SKUPath[index + 1] != '_'){
            return;
        }
        index += 2;
    }
}

bool addSKU(SKUTree *tree, const char *SKUPath){

    bool addedNode = false;

    if(SKUPath[0] != 's' || SKUPath[1] != '_'){
        return addedNode;
    }
    if(tree->root == NULL){
        SKUNode *root = newSKUNode(0, tree->maxChildren[0], SKUPath);

        tree->root = root;
        addedNode = true;
    }

    SKUNode currNode = *(tree->root);
    bool expectDigit = true;
    int index = 2;
    while(true){
        if(currNode.depth >= tree->numInternalLevels){
            break;
        }
        char nextChar = SKUPath[index];
        if(!expectDigit){
            if(nextChar != '_'){
                break;
            }else{
                index++;
                expectDigit = true;
                continue;
            }
        }

        if(!isdigit(nextChar)){
            break;
        }

        int path = nextChar - '0';
        
        if(path >= tree->maxChildren[currNode.depth]){
            break;
        }

        if(currNode.children[path] == NULL){
            int maxChildren = 0;
            if(currNode.depth + 1 < tree->numInternalLevels){
                maxChildren = tree->maxChildren[currNode.depth + 1];
            }
            currNode.children[path] = newSKUNode(currNode.depth + 1, maxChildren, SKUPath);
            addedNode = true;
        }

        currNode = *currNode.children[path];
        index++;
        expectDigit = false;
    }
    return addedNode;
}

SKUNode* findSKU(SKUTree *root, const char *SKUPath){
    return NULL;
}

int countNumOfSKUsInSKUChart(SKUTree *tree, SKUNode *node){
    int count = 0;
    if(node == NULL){
        return count;
    }
    return 0;
}
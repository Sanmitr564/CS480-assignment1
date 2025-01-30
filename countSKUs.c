#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv){
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

    char str[50];
    while(fgets(str, 50, skuChart) != NULL){
        printf("%s", str);
    }

    fclose(skuChart);
    fclose(testFile);
}
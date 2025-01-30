std:
	gcc -std=c11 -Wall -g -c SKUTree.c
	gcc -std=c11 -Wall -g -c countSKUs.c
	gcc -o countSKUs SKUTree.o countSKUs.o

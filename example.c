#include <stdio.h>
#include "cvector.h"

int main(){
	vectorCreate(int, vec); // Create vector with type int 

    // vectorPushBack
	for (int i = 1; i < 11; i++){ // Push 10 elements to vector
		vectorPushBack(vec, i); 
	}
	for (int i = 0; i < vectorLength(vec); i++){
		printf("%d ", vec.array[i]); // Array syntax
	} printf("\tvectorPushBack\n");


    // vectorEraseIndex
	vectorEraseIndex(vec, 3); // Delete an element with index = 3
	for (int* it = vectorBegin(vec); it != vectorEnd(vec); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\tvectorEraseIndex\n");


    // vectorEraseRange
	vectorEraseRange(vec, 1, 3); // Delete elements in range [1, 3)
	for (int* it = vectorBegin(vec); it != vectorEnd(vec); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\tvectorEraseRange\n");


    // vectorPopBack
	vectorPopBack(vec);// Delete last element
	for (int i = 0; i < vectorLength(vec); i++){
		printf("%d ", vectorAt(vec, i)); // vectorAt syntax
	} printf("\tvectorPopBack\n");


	vectorCreate(int, vec1); // Create second vector with type int 


    // vectorCopy
	vectorCopy(vec, vec1); // Copy all data from vec to vec1
	for (int i = 0; i < vectorLength(vec1); i++){
		printf("%d ", vec1.array[i]); // Array syntax
	} printf("\tvectorCopy\n");


    // vectorInsert
	vectorInsert(vec1, 6, 736);	// Insert 736 to vec1[6]
	for (int i = 0; i < vectorLength(vec1); i++){
		printf("%d ", vec1.array[i]); // Array syntax
	} printf("\tvectorInsert\n");


    // vectorSwap
    printf("Before swap:\n");
    printf("\tvec: ");
    for (int* it = vectorBegin(vec); it != vectorEnd(vec); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\n");
    printf("\tvec1: ");
    for (int* it = vectorBegin(vec1); it != vectorEnd(vec1); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\n");
    vectorSwap(vec, vec1);
    printf("After swap:\n");
    printf("\tvec: ");
    for (int* it = vectorBegin(vec); it != vectorEnd(vec); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\n");
    printf("\tvec1: ");
    for (int* it = vectorBegin(vec1); it != vectorEnd(vec1); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\n");


    // vectorClear
    vectorClear(vec);
    vectorPushBack(vec, 234);
    vectorPushBack(vec, 567);
    for (int* it = vectorBegin(vec); it != vectorEnd(vec); it++){   // it must be type of vector array
		printf("%d ", *it); // Iterator syntax
	} printf("\tvectorClear\n");


    vectorFree(vec);// Free memory
    vectorFree(vec1);

	return 0;
}
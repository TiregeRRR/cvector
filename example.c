#include <stdio.h>
#include "cvector.h"

int main(){
	vectorCreate(int, vec); // Create vector with type int 


	for (int i = 1; i < 11; i++){ // Push 10 elements to vector
		vectorPushBack(vec, i); 
	}
	for (int i = 0; i < vectorLength(vec); i++){
		printf("%d ", vec.array[i]); // Elements must be accessed with this syntax
	} printf("\tvectorPushBack\n");

	vectorErase(vec, 3); // Delete an element with index = 3
	for (int i = 0; i < vectorLength(vec); i++){
		printf("%d ", vec.array[i]); // Elements must be accessed with this syntax
	} printf("\tvectorErase\n");

	vectorPopBack(vec);// Delete last element
	for (int i = 0; i < vectorLength(vec); i++){
		printf("%d ", vec.array[i]); // Elements must be accessed with this syntax
	} printf("\tvectorPopBack\n");

	vectorCreate(int, vec1); // Create second vector with type int 

	vectorCopy(vec, vec1); // Copy all data from vec to vec1
	for (int i = 0; i < vectorLength(vec1); i++){
		printf("%d ", vec1.array[i]); // Elements must be accessed with this syntax
	} printf("\tvectorCopy\n");

	vectorInsert(vec1, 6, 736);	// Insert 736 to vec1[6]
	for (int i = 0; i < vectorLength(vec1); i++){
		printf("%d ", vec1.array[i]); // Elements must be accessed with this syntax
	} printf("\tvectorInsert\n");
	vectorFree(vec); // Free memory
	getchar();
	return 0;
}
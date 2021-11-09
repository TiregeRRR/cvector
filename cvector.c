#include "cvector.h"
#include <stdio.h>


//char* getLittleEndian(char* array, const size_t size);
void vectorInit(cvector* vec, size_t elementSize){
	vec->capacity = DEFAULT_CAPACITY;
	vec->used = 0;
	vec->elementSize = elementSize;
	vec->array = malloc(DEFAULT_CAPACITY * vec->elementSize);
}

int vectorLength(cvector* vec){
	return vec->used;
}

int vectorPushBack(cvector* vec, char* value){
	if(vec){
		if(vec->capacity == vec->used){
			if(vectorResize(vec, vec->capacity*2)==NOT_INITIALIZED){
				return NOT_INITIALIZED;
			}
			for (int i = 0; i < vec->elementSize; i++){
				*(vec->array + vec->used * vec->elementSize + i) = value[i];
			}
			vec->used++;
		} else {
			for (int i = 0; i < vec->elementSize; i++){
				*(vec->array + vec->used * vec->elementSize + i) = value[i];
			}
			vec->used++;
		}
		return SUCCESS;
	} else {
		return NOT_INITIALIZED;
	}
}

void* vectorGet(cvector* vec, size_t index){
	if(vec){
		if(index < vec->used && index >= 0){
			return (vec->array + index * vec->elementSize);
		}
	}
}

int vectorResize(cvector* vec, size_t newLength){
	if(vec){
		void *point_check = realloc(vec->array, newLength * vec->elementSize);
		if (point_check == NULL){
			return NOT_INITIALIZED;
		}
		vec->array = point_check;
		vec->capacity = newLength;
		return SUCCESS;
	} else {
		return NOT_INITIALIZED;
	}
}

int vectorEraseIndex(cvector* vec, size_t index){
	if(vec){
		if(index < vec->used && index >= 0){
			for (int i = index; i < vec->used - 1; i++){
				vec->array[i * vec->elementSize] = vec->array[(i + 1) * vec->elementSize];
			}
			vec->used--;
		}
	}
}

void vectorFree(cvector* vec){
	free(vec->array);
	vec->array = NULL;
}


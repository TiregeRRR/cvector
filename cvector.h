#include <stdlib.h>

#define DEFAULT_CAPACITY 6
#define NOT_INITIALIZED 1
#define OUT_OF_BOUNDS 2
#define SUCCESS 0

// vector struct
typedef struct cvector
{
	size_t capacity;
	size_t used;
	size_t elementSize;
	char* array;
} cvector;

// Initialize cvector struct fields
void vectorInit(cvector* vec, size_t elementSize);
// Return length of vector
int vectorLength(cvector* vec);

int vectorPushBack(cvector* vec, char* value);

void* vectorGet(cvector* vec, size_t index);

int vectorResize(cvector* vec, size_t newLength);

int vectorEraseIndex(cvector* vec, size_t index);

void vectorFree(cvector* vec);
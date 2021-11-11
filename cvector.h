#include <stdlib.h>

// Default vector capacity
#define DEFAULT_CAPACITY 6
// Default capacity increase on resize when needed
#define DEFAULT_RESIZE_MULTIPLIER 2

#define OUT_OF_BOUNDS -1

int inBounds(int used, int index);

// Initialize vector array with DEFAULT_CAPACITY, 0 and allocate a memory for array
// Will be called on vectorCreate
#define vectorInit(var)                                         \
    var.capacity = DEFAULT_CAPACITY;                            \
    var.used = 0;                                               \
    var.array = malloc(DEFAULT_CAPACITY * sizeof(*var.array))	


// Create a struct with name of a variable and call vectorInit
#define vectorCreate(type, varName)     \
    struct varName {                    \
        size_t capacity;	            \
        size_t used;		            \
        type* array;		            \
    } varName;                          \
    vectorInit(varName)
 
// Reallocate var.array with given length
#define vectorResize(var, newLength)  					            \
    void* ptr = realloc(var.array, newLength * sizeof(*var.array));	\
    if (!(ptr == NULL)){                                            \
        var.array = ptr;                                            \
        var.capacity = newLength;                                   \
    }

// Add a value to end of array, if out of space - will call var.capacity with DEFAULT_RESIZE_MULTIPLIER
#define vectorPushBack(var, value)                                      \
    do{                                                                 \
        if(var.used >= var.capacity){                                   \
            vectorResize(var, var.capacity*DEFAULT_RESIZE_MULTIPLIER);	\
            var.array[var.used] = value;                                \
            var.used++;                                                 \
        } else {                                                        \
            var.array[var.used] = value;                                \
            var.used++;                                                 \
        }                                                               \
    }while(0)

// Return length of vector array
#define vectorLength(var)\
    var.used

// Free vector array
// Should be used only in the end of using vector
#define vectorFree(var) \
    free(var.array);    \
    var.used = 0;       \
    var.capacity = 0;

// If vectorLength > 0 will decrease it length, otherwise will do nothing
#define vectorPopBack(var)\
    var.used > 0 ? var.used-- : var.used

// Delete an element on given index and shift all elements
#define vectorEraseIndex(var, index)                    \
    do{                                                 \
        if(index >= 0 && index < var.used){             \
            for(int i = index; i < var.used - 1; i++){  \
                var.array[i] = var.array[i + 1];        \
            }                                           \
            var.used--;                                 \
        }                                               \
    }while(0)

// // Delete an element on given range [start, end) and shift all elements 
#define vectorEraseRange(var, start, end)                   \
    do{                                                     \
        int diff = end - start;                         \
        if(start >= 0 && end < var.used){                   \
            for(int i = start; i < var.used - diff; i++){	\
                var.array[i] = var.array[i + diff];         \
            }						                        \
            var.used-=diff;					                \
        }							                        \
    }while(0)

// Copy all elements from one vector to another
#define vectorCopy(from, to)                    \
    do{                                         \
        for(int i = 0; i < from.used; i++){     \
            vectorPushBack(to, from.array[i]);  \
        }                                       \
    }while(0)

// Inserts given value to index. Elements in vector will be always shifted to right
#define vectorInsert(var, index, value)                                     \
    do{                                                                     \
        if(index >= 0 && index <= var.used){                                \
            if(var.used >= var.capacity){                                   \
                vectorResize(var, var.capacity * DEFAULT_RESIZE_MULTIPLIER);\
                for(int i = var.used; i > index; i--){                      \
                    var.array[i] = var.array[i - 1];                        \
                }                                                           \
                var.array[index] = value;                                   \
                var.used++;                                                 \
            } else {                                                        \
                for(int i = var.used; i > index; i--){                      \
                    var.array[i] = var.array[i - 1];                        \
                }                                                           \
                var.used++;                                                 \
                var.array[index] = value;                                   \
            }                                                               \
        }                                                                   \
    }while(0)

// Return a value of var.array[index]
#define vectorAt(var, index)\
    inBounds(var.used, index) ? var.array[index] : OUT_OF_BOUNDS

// Return a start pointer of var.array
#define vectorBegin(var)\
    var.array

// Return an end pointer of var.array
#define vectorEnd(var)\
    var.array+var.used

// Clear the vector by re-initialization
#define vectorClear(var)\
    vectorFree(var);    \
    vectorInit(var)

// Swap two vectors
#define vectorSwap(var1, var2)              \
    do{                                     \
        size_t tmpCapacity = var1.capacity; \
        size_t tmpUsed = var1.used;         \
        void* tmpPointer = var1.array;      \
        var1.capacity = var2.capacity;      \
        var1.used = var2.used;              \
        var1.array = var2.array;            \
        var2.capacity = tmpCapacity;        \
        var2.used = tmpUsed;                \
        var2.array = tmpPointer;            \
    }while(0)

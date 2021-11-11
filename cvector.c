#include "cvector.h"

int inBounds(int used, int index){
    if(index >= 0 && index < used){
        return 1;
    }
    return 0;
}
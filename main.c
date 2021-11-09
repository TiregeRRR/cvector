#include <stdio.h>
#include "cvector.h"

int main(){
	unsigned int x = 0x76543210;
	char *c = (char*) &x;
	
	printf ("*c is: 0x%x\n", *c);
	if (*c == 0x10)
	{
		printf ("Underlying architecture is little endian. \n");
	}
	else
	{
		printf ("Underlying architecture is big endian. \n");
	}
	cvector vec;
	vectorInit(&vec, sizeof(double));
	int cnt = 0;
	for (double i = 0; i < 100; i++){
		vectorPushBack(&vec, (char*)&i);
	}
	for (int i = 0; i < 100; i++){
		printf("%d\n", *(double*)vectorGet(&vec, i));
	}
	printf("vector length is %d\n", vectorLength(&vec));
	vectorEraseIndex(&vec, 0);
	printf("vector length is %d\n", vectorLength(&vec));
	getchar();
	return 0;
}
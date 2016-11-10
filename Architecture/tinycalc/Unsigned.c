#include <stdio.h>

int main(void){
	short int v = 80;
	unsigned short int uv = (unsigned short) v;
	printf("v = %d, uv = %u\n", v, uv);
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* create_user_string(){
	char *pt = (char*)malloc(12*sizeof(char));
	return pt;
}

int main(void){
	printf("creating a user string\n\n");
	create_user_string();
	printf("done");
}
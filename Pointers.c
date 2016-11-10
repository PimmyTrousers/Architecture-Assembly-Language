#include <stdio.h>

int main(){

	/*int a;
	int b = 10;
	float c = 5.8;
	printf("the memory address for int A is %d\n", &a); //the memory address is 235916
	int *p1;// declares a pointer variable
	p1 = &a;//pointer p1 contains the address of a because a has the &, so the value of p1 will be 235916 
	int *p2 = &b;//pointer variables only contain memory addresses. there is no difference betweem the first statement with p1 and the second p2
	float *p3 = &c;
	printf("The value of pointer p1 is %d\n", p1); //if done correctly the program should come up with 235916 since p1 is a pointer of memory  
	printf("The value of a is %d", *p1); // will print out the data that is stored at the memory address p1 (thats what the purpose of the * is) */

	int i1, i2;
	char c1, c2;
	int *ip1, *ip2;
	char *cp1, *cp2;

	//c2 = *&c1;
	//printf("%c\n", c2);
	//*ip2 = i2;
	//printf("%c\n", *cp1);
	//i2 = *(&i1);
	//printf("%d\n", i2);
	//ip2 = &i1;
	//printf("%d\n", ip2);
	cp2 = &cp1;
	printf("%c\n", cp2);
}
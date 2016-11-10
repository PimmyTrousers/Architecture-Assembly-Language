#include <stdio.h>
#include <math.h> 

typedef struct d11_node{
	int value;
	struct d11_node *prev;
	structd11_node *next;
	}d11_node_t;

}
d11_node_t* new_node(int n){
	d11_node_t *node;
	node->value = n;
	return node;
}
int main(void){
	d11_node_t node;
	int val;
	int *p;
	printf("welcome to Listomatic! \n");
	printf("List as many numbers as you like with a space as a seperator or a new line\n");
	printf("To end the input of numbers, press a non numeric key\n");
	scanf("%d", &val);
	node.value = val;
	node.prev = NULL;
	while(1){
		scanf("%d", val);
		p = new_node(val);
		p->prev = &node;
		
	}
}
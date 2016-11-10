#include <stdio.h>
#include <stdlib.h>

int count=0;

typedef struct node{
  int value;
  struct node *prev;
  struct node *next;
}node; 


node* new_node(int n) {
  struct node *px = malloc(sizeof(struct node));
  node*  this_node = px;
  this_node->value = n;
  count++;
  return this_node;
}

int main(void){
  node *this_node;
  node *prev_node;
  struct node *first_node;
  first_node = malloc(sizeof(struct node));
  first_node->next=NULL;
  int val;
  scanf("%d", &val);
first_node = new_node(val);
 this_node= first_node;
  while(scanf("%d", &val)==1){
    prev_node = this_node;
    this_node = new_node(val);
    this_node->prev = prev_node;
    prev_node->next = this_node;	
  }
  this_node = first_node;
  int array[count], copy[count];
  int i = 0;
  int d = 0;
  int t = 0;
  while(this_node!=NULL){
    array[i]=this_node->value;
    this_node = this_node->next;
    i++;
    }
  printf("Read %d integers\n",count);
 node* temp;
 this_node=first_node;
 while(this_node!=NULL){
   temp=this_node;
   this_node=this_node->next;
   free(temp);
 }
 
 for(int j=0;j<count;j++){
    copy[j]=array[j];
  }
  for (int c = 1;c<count;c++) {
    d = c;
    while ( d > 0 && copy[d] < copy[d-1]) {
      t  = copy[d];
      copy[d] = copy[d-1];
      copy[d-1] = t;
      d--;
    }
  }
  for(int c=0;c<count;c++){
    printf("%d\n",copy[c]);
  }
 
 for(int c=count-1;c>=0;c--){
    printf("%d\n",copy[c]);
  }
 
 for(int c=count-1;c>=0;c--){
    printf("%d\n",array[c]);
  }

}



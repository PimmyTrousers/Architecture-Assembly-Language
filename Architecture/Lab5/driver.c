#include<stdio.h>
#include<stdlib.h>
#include"bigint.h"

void print_big_int(big_int_t *);

int main(void) {
  //big_int_t *a = unsigned_to_big_int(45);
  //big_int_t *b = hex_to_big_int("0xfffdffccffddff000aa134567"); // 0f fd ff cc
  big_int_t *b = hex_to_big_int("0xa532fd");
  big_int_t *a = hex_to_big_int("0xb7a4ac");
  print_big_int(a);
  print_big_int(b);
int c =  big_int_add(a,b);
  print_big_int(a);
  destroy_big_int(a);
  destroy_big_int(b);

}

//------------------ print_big_int --------------------//
// pretty printing for each byte of a big_int_t        //
//-----------------------------------------------------//
void print_big_int(big_int_t *big) {

  int i;

  if (big == NULL) return;

  for(i=0;i<BIG_INT_BYTE_WIDTH;i++) {
    if (i%8 == 0) {
      printf("\n%d: ", i);
    }
    printf("%.2x ", big->bytes[i]);
  }
  printf("\n");
}

#include<stdio.h>
#include<stdlib.h>
#include"bigint.h"

void print_big_int(big_int_t *);

int main(void) {
  big_int_t *a = unsigned_to_big_int(45);
  big_int_t *b = hex_to_big_int("0xfffdffccffddff000aa134567"); // 0f fd ff cc
  a = hex_to_big_int("0xffdd"); //01100111010001010001001110101010000000001111000011011111111111011100111111111100110111111111111100001111, 674513aa00f0dffdcffcdfff0f
  big_int_t *c = hex_to_big_int("0xffdd");//6636321
big_int_add(a,c);//14465688

  printf("**************** INITIAL PRINT ***************************\n");
  print_big_int(a);
  print_big_int(b);
  /*printf("**************** PRINT AFTER RIGHT SHIFT ***********************\n");
  big_int_shiftr(a, 8);
  big_int_shiftr(b, 8);
  print_big_int(a);
  print_big_int(b);
  printf("**************** PRINT AFTER LEFT SHIFT ***********************\n");
  big_int_shiftl(a, 8);
  big_int_shiftl(b, 8); */
  destroy_big_int(a);
  destroy_big_int(b);

}


//------------------ print_big_int --------------------//
// pretty printing for each byte of a big_int_t        //
//-----------------------------------------------------//
void print_big_int(big_int_t *b) {

  int i;

  if (b == NULL) return;

  for(i=0;i<BIG_INT_BYTE_WIDTH;i++) {
    if (i%8 == 0) {
      printf("\n%d: ", i);
    }
    printf("%.2x ", b->bytes[i]);
  }
  printf("\n");
}

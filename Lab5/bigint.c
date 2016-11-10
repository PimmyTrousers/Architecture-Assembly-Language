#include"bigint.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

// TIP: internet search and read about C's string.h library
//  you will find many functions that might be of use in this assignment
//  like strlen(cont char *) which returns the length of a string

void get_bin(int c,int *a){
  switch(c){
    case 1:
    printf("case 1 is hit\n");
    *a++=0;
    *a++=0;
    *a++=0;
    *a++=1;
    return;
    case 2:
    printf("case 2 is hit\n");
    *a++=0;
    *a++=0;
    *a++=1;
    *a++=0;
    return;
    case 3:
    printf("case 3 is hit\n");
    *a++=0;
    *a++=0;
    *a++=1;
    *a++=1;
    return;
    case 4:
    printf("case 4 is hit\n");
    *a++=0;
    *a++=1;
    *a++=0;
    *a++=0;
    return;
    case 5:
    printf("case 5 is hit\n");
    *a++=0;
    *a++=1;
    *a++=0;
    *a++=1;
    return;
    case 6:
    printf("case 6 is hit\n");
    *a++=0;
    *a++=1;
    *a++=1;
    *a++=0;
    return;
    case 7:
    printf("case 7 is hit\n");
    *a++=0;
    *a++=1;
    //printf("1 val is %d and mem is %x\n", *(a+0x1), (a+0x1));//*(abit+i), abit+i
    *a++=1;
    //printf("2 val is %d and mem is %x\n", *(a+0x2), (a+0x2));//*(abit+i), abit+i
    *a++=1;
    //printf("3 val is %d and mem is %x\n", *(a+0x3), (a+0x3));//*(abit+i), abit+i
    return;
    case 8:
    printf("case 8 is hit\n");
    *a++=1;
    *a++=0;
    *a++=0;
    *a++=0;
    return;
    case 9:
    printf("case 9 is hit\n");
    *a++=1;
    *a++=0;
    *a++=0;
    *a++=1;
    return;
    case 0xa:
    printf("case a is hit\n");
    *a++=1;
    *a++=0;
    *a++=1;
    *a++=0;
    return;
    case 0xb:
    printf("case b is hit\n");
    *a++=1;
    *a++=0;
    *a++=1;
    *a++=1;
    return;
    case 0xc:
    printf("case c is hit\n");
    *a++=1;
    *a++=1;
    *a++=0;
    *a++=0;
    return;
    case 0xd:
    printf("case d is hit\n");
    *a++=1;
    *a++=1;
    *a++=0;
    *a++=1;
    return;
    case 0xe:
    printf("case e is hit\n");
    *a++=1;
    *a++=1;
    *a++=1;
    *a++=0;
    return;
    case 0xf:
    printf("case f is hit\n");
    *a++=1;
    *a++=1;
    *a++=1;
    *a++=1;
    return;
    case 0x0:
    printf("case 0 is hit\n");
    *a=0;
    *a++=0;
    *a++=0;
    *a++=0;
    return;
  }
}
unsigned char get_bits(char c){ //WORKS
  switch(c){
    case '0':
    return 0x0;
    case '1':
    return 0x1;
    case '2':
    return 0x2;
    case '3':
    return 0x3;
    case '4':
    return 0x4;
    case '5':
    return 0x5;
    case '6':
    return 0x6;
    case '7':
    return 0x7;
    case '8':
    return 0x8;
    case '9':
    return 0x9;
    case 'A':
    return 0xA;
    case 'B':
    return 0xB;
    case 'C':
    return 0xC;
    case 'D':
    return 0xD;
    case 'E':
    return 0xE;
    case 'F':
    return 0xF;
    case 'a':
    return 0xA;
    case 'b':
    return 0xB;
    case 'c':
    return 0xC;
    case 'd':
    return 0xD;
    case 'e':
    return 0xE;
    case 'f':
    return 0xF;
    default:
    return 0;
  }
}

unsigned char hex_to_byte(unsigned char left,unsigned char right){ //WORKS
  return (unsigned char) (left<<= 4) | right;
}

big_int_t * unsigned_to_big_int(unsigned int x) { //WORKS *****************************************************************************************
  big_int_t *p1;
  int j = 0;
  p1 = malloc(sizeof(big_int_t));
  for(j = 0; j < BIG_INT_BYTE_WIDTH; j++){
    p1->bytes[j] = 0x00;
  }
    p1->bytes[0] = x;
  return p1;
}

big_int_t * hex_to_big_int(char *hex_string) { //WORKS *******************************************************************************************
  int j;
  int i = 0;
  int k = 2;
  int size = strlen(hex_string);
  big_int_t *p1;

  p1 = malloc(sizeof(big_int_t));
  for(j = 0; j < BIG_INT_BYTE_WIDTH; j++){
    p1->bytes[j] = 0x00;
  }
if(size % 2 == 0){
  for(j = size/2-2;i < size/2; j--){
    p1->bytes[j] = hex_to_byte(get_bits(*(hex_string+k)),get_bits(*(hex_string+k+1)));
    k = k + 2;
    i = i + 1;
  }
}
else{
  for(j = size/2-1 ;i < size/2; j--){
    if(i == 0){
      p1->bytes[j] = hex_to_byte(0,get_bits(*(hex_string+k)));
    }
    if(i > 0){
    p1->bytes[j] = hex_to_byte(get_bits(*(hex_string+k-1)),get_bits(*(hex_string+k)));
}
    if(i == (size/2)-1){
      p1->bytes[j] = hex_to_byte(get_bits(*(hex_string+k-1)),get_bits(*(hex_string+k)));
    }
    k = k + 2;
    i = i + 1;
  }
}
  return p1;
}

void destroy_big_int(big_int_t *a) { //DOESNT WORK  ****************************************************************************************
free(a);
}


void big_int_and(big_int_t *a, big_int_t *b) {//WORKS *************************************************************************************
  int i = 0;
  for(i = 0; i < BIG_INT_BIT_WIDTH; i++){
    a->bytes[i] = a->bytes[i] & b->bytes[i];
  }

}

void big_int_not(big_int_t *a) { //WORKS *************************************************************************************************
  int i = 0;
  for(i = 0; i < BIG_INT_BIT_WIDTH; i++){
    a->bytes[i] = ~a->bytes[i];
  }

}

int big_int_add(big_int_t *a, big_int_t *b) { //DOESNT WORK
int abit[131072];
int bbit[131072];
int j = 0;

for(int i = 0; i < 4096*32; i++){
  abit[i] = 0;
}
for(int i = 0; i < 4096*32; i++){
  bbit[i] = 0;
}
for(int i=0; i<10; i++){
  get_bin(((a->bytes[i]&0xF0)>>4),abit+j);
  j+=4;
  get_bin(((a->bytes[i]&0x0F)),abit+j);
  j+=4;
}

j = 0;

for(int i=0; i<10; i++){
  get_bin(((b->bytes[i]&0xF0)>>4),bbit+j);
  j+=4;
  get_bin(((b->bytes[i]&0x0F)),bbit+j);
  j+=4;
}

printf("\n\n\n");
for(int i =0; i < 500; i++){
printf("%x",bbit[i]);
if(i % 4 ==0){

}
}
printf("\n");


  return 0;
}

void big_int_shiftl(big_int_t *a, int s) { //DOESNT WORK
  //int i = 0;
  int p = 0;
  if(s % 4 ==0){
  p = s/4;


}
}

void big_int_shiftr(big_int_t *a, int s) { //DOESNT WORK
  int i = 0;
  int p = 0;
  if(s % 8 == 0){
    p = s/8;
  for(i = BIG_INT_BYTE_WIDTH; i != 0;i--){
    if(i==1){
      a->bytes[i] = 00;
    }
    a->bytes[i] = a->bytes[i-p];
  }
}
}

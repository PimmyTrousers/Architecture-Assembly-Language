#include"bigint.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

// TIP: internet search and read about C's string.h library
//  you will find many functions that might be of use in this assignment
//  like strlen(cont char *) which returns the length of a string
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
  int carry = 0;
  int temp = 0;
  for(int i = 0; i <= BIG_INT_BYTE_WIDTH; i++){
    temp = a->bytes[i];
    a->bytes[i]=(a->bytes[i]+b->bytes[i]+carry)&0xFF;
    carry = ((carry + temp + b->bytes[i])>>8);
    if(carry!=0&&i>=BIG_INT_BYTE_WIDTH){
      return 1;
    }
  }
  return 0;
}

void big_int_shiftl(big_int_t *a, int s) { //WORKS****************************************************************************************
  int carry=0;
  int temp=0;
  int zeros = floor(s/8);
  int i = 0;
  if(s > 4093){
  s = s % 4096;
  }

  s = s % 8;

    for(i = BIG_INT_BIT_WIDTH; i >= 0; i--){
      if(i+zeros > 0){
        a->bytes[i+zeros] = a->bytes[i];
      }
      if((i-zeros)<=0){
          a->bytes[i]=0x0;
        }
      }

    for(i = 0; i <BIG_INT_BYTE_WIDTH;i++){
      temp = a->bytes[i];
      a->bytes[i] = (carry|((a->bytes[i])<<s));
      carry=0xFF&((temp)>>(8-s));
  }
}

void big_int_shiftr(big_int_t *a, int s) { //WORKS***************************************************************************************
  int i = 0;
  int carry=0;
  int temp=0;
  int zeros = floor(s/8);
  if(s > 4093){
    s = s % 4096;
  }
  s = s % 8;
    for(i = 0; i < BIG_INT_BYTE_WIDTH; i++){
      if(i+zeros >= BIG_INT_BYTE_WIDTH){
      a->bytes[i]=0;

    }else{
    a->bytes[i] = a->bytes[i+zeros];
  }
    }
  for(i = BIG_INT_BYTE_WIDTH-1; i >= 0;i--){
    temp = a->bytes[i];
    a->bytes[i] = (carry|((a->bytes[i])>>s));
    carry=0xFF&((temp)<<(8-s));
  }

}

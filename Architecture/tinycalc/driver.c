#include<stdio.h>
#include"tinycalc.h"


/* Put your application code in this file   */

int main(void) {
char op;
int m;
double num, total;
tc_memory_t mem;
mem.most_recent = 5;

  printf("\nWelcome to TinyCalc!\n\n Enter an operation <+, - , *, /, ^>");
  printf(" followed by operand\n\n Enter 'q' or 'Q' to quit.\n\n");
  printf(" Enter 'm' or 'M' followed by location (0-4) to load a previous\n");
  printf(" result from memory.");
  
  while(1==1){
  printf("\n>");
  //check_command(op);
  char *operate = &op;
  double *number = &num;
  double *calculation = &total;
  tc_memory_t *memPointer=&mem;
  m = read_command(operate,number);
  if(m==1){
    break;
  }
  if((*operate == 'm')||(*operate == 'M')){
  *calculation = mem_read(mem, (int)*number);
  }
  else{
 execute_calculation(op, num, calculation);
  }
 mem_save(memPointer, *calculation);

 printf("%.2lf", *calculation);

  }


}





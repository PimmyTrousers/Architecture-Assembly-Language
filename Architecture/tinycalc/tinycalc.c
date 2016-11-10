#include"tinycalc.h"
#include<stdio.h>

double power(double num, double pow){
  int count;
  double result = 1;

  for(count = 0; count < pow; count ++){
    result = result * num;
 }
  return result;
}

int check_command(char op) {
if(op=='+' || op=='-' || op=='*' || op=='^' || op=='/' || op=='m'|| op== 'M' || op == 'q'|| op == 'Q'){
return 0;
}
else{
  return 1;
}
}

int read_command(char *op, double *num) {
scanf("\n%1c", op);
 if((*op == 'q')||(*op == 'Q')){
   return 1;
 }else if(check_command(*op)==0){
  scanf("%lf", num);
  return 0;
 }
 return 0;
}

void execute_calculation(char f_operator, double f_operand, double *p_result) {
 if(f_operator=='+'){
    *p_result = f_operand + *p_result;
  }
  if(f_operator=='-'){
    *p_result = - (f_operand) + (*p_result);
  }
  if(f_operator =='/'){
    *p_result = (*p_result)/(f_operand);
  }
  if(f_operator == '*'){
    *p_result = f_operand * *p_result;
  }if(f_operator == '^'){
    *p_result = power(*p_result, f_operand);
  }
}

double mem_read(tc_memory_t mem, int v) {
  double num = 0;
  if((v < 5)&&(v >= 0)){
    num = mem.vals[v];
  }else{
    num = mem.vals[0];
  }
  return num;
}

void mem_save(tc_memory_t *mem, double v) {
  int count = 5;
  double temp;
  while(count > 0){
    if(count == 1){
      temp = mem->vals[count-1];
      mem->vals[0] = v;
      mem->vals[count] = temp;
    }else{
      temp = mem->vals[count-1];
      mem->vals[count] = temp;
    }

    if(mem->most_recent > 0){
      mem->most_recent--;
    }
    count--;
  }
}

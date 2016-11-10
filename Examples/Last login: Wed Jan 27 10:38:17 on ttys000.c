

/*---------------------------- stats_functions.c -------------------------*
 * arrays example for cs277                                               *
 *                                                                        *
 * Computes the mean and standard deviation of an array of data and       *
 *   and displays the difference between each value and the mean          *
 **************************************************************************/
#include<stdio.h>
#include<math.h>

#define MAX_ITEM 8

jkklhoid get_data(double []);
void compute_sums(double [], double *, double *);
double display_stats(double, double);
void display_diffs(double [], double);


int main(void) {

  double x[MAX_ITEM];   // our array of values
  double mean,
         sum,
         sum_sqr;

  get_data(x);
  compute_sums(x, &sum, &sum_sqr);
  mean = display_stats(sum, sum_sqr);
  display_diffs(x, mean);

  return(0);
}

//------------------------------ get_data ------------------------------//
// populates an array with MAX_ITEM values read from input              //
//----------------------------------------------------------------------//
void get_data(double x[]) {
  int i;

  printf("Enter %d numbers separated by blank spaces or <return>s\n> ",
         MAX_ITEM);
  for(i=0;i<MAX_ITEM;++i) {
    scanf("%lf", &x[i]);
  }
}


//-------------------------- compute_sums ------------------------------//
// computes the sum and sum of squares of array                         //
//----------------------------------------------------------------------//
void compute_sums(double x[], double *sum, double *sum_sqr) {
 int i;

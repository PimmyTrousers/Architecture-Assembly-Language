Last login: Wed Jan 27 10:38:17 on ttys000
Pims-MacBook-Pro:~ Pim$ ssh ptrouerbach@simpson4
The authenticity of host 'simpson4 (149.175.51.204)' can't be established.
ECDSA key fingerprint is SHA256:6tPSkvcUJ+/c4bI7pp3d8jWFcpqobWSo+mstcRrLfJI.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'simpson4' (ECDSA) to the list of known hosts.
ptrouerbach@simpson4's password: 
Welcome to Ubuntu 14.04.3 LTS (GNU/Linux 3.13.0-73-generic x86_64)

 * Documentation:  https://help.ubuntu.com/

84 packages can be updated.
58 updates are security updates.

Last login: Mon Jan 25 18:07:29 2016 from 149.175.182.15
ptrouerbach@simpson4:~$ ls
a.out  Desktop  deviation.c  Documents  Downloads  examples.desktop  graph.c  graph.c~  mode.c  Music  Pictures  Public  t01c.c  Templates  #triangle.c#  unixfun  Videos
ptrouerbach@simpson4:~$ cd ..
ptrouerbach@simpson4:/home/users$ cd mharmon/
ptrouerbach@simpson4:/home/users/mharmon$ ls
cs277  cs383  Desktop  Documents  Downloads  examples.desktop  Music  Pictures  priv  Public  Templates  tmp  Videos
ptrouerbach@simpson4:/home/users/mharmon$ cd cs277/
ptrouerbach@simpson4:/home/users/mharmon/cs277$ ls
bin  examples  homeworks
ptrouerbach@simpson4:/home/users/mharmon/cs277$ cd examples
ptrouerbach@simpson4:/home/users/mharmon/cs277/examples$ ls
coins.c  stats.c  stats_functions.c  stats_pointer.c  stats_struct.c
ptrouerbach@simpson4:/home/users/mharmon/cs277/examples$ vim stats.c
ptrouerbach@simpson4:/home/users/mharmon/cs277/examples$ vim stats_functions.c
























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

-- INSERT --                                                                                                                                                       12,6          Top

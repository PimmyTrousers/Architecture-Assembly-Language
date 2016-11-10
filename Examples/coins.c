#include<stdio.h>

int main(void) {

  char first, middle, last;
  int pennies, nickels;
  int dimes, quarters;
  int change;
  int dollars;
  int total_cents;


  // get initials
  printf("Type initials of first, middle and last name and press enter> ");
  scanf("%c%c%c", &first, &middle, &last);
  printf("Hello %c%c%c, let's see what your coins are worth\n",
         first, middle, last);


 // get coin counts
 printf("Number of quarters> ");
 scanf("%d", &quarters);
 printf("Number of dimes> ");
 scanf("%d", &dimes);
 printf("Number of nickels> ");
 scanf("%d", &nickels);
 printf("Number of pennies> ");
 scanf("%d", &pennies);

 // compute total value in cents
 total_cents = 25 * quarters + 10 * dimes + 5 * nickels + pennies;

 // compute value in dollars and cents
 dollars = total_cents / 100;
 change = total_cents % 100;

 // display values
 printf("\n Your coins are worth %d dollars and %d cents.\n",
         dollars, change);

  return(0);
}


#include <stdio.h>

#include <math.h>

#include <stdlib.h>

int main ()

{ double x, p, i, y, m, counter;

    printf ("What is the starting amount? \n");

    scanf ("%lf", &x);

    

    printf ("What is the added amount?\n"); //paycheck

    scanf ("%lf", &p);

    //p=p*12; //per year

    

    printf ("What is the compound interest?\n");

    scanf ("%lf", &i);

    i=i/100; //convert to decimal

    i=i/12; //per month

    

    printf ("How many years until retirement?\n");

    scanf ("%lf", &y);

    m=y*12; //months

    

    counter=1;

    while (counter<=m) {

        x=((x*i)+x);

        x=x+p;

        counter=counter+1;

    }

    

    i=x-(p*m);

    

    printf ("You will have $%lf after %lf years, with $%lf interest gained.\n", x,y,i);

}
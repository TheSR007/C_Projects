#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    long long N;
    printf("Enter N to get the sum from 0 to N: ");
    scanf("%lld",&N);
    printf("%lld\n",N*(N+1)/2);//formula for Nth sum N*(N+1)/2
    getch();
}

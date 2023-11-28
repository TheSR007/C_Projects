// 0 + 1 + 1 + 2 + 3 + 5 + 8 + ...........+ N
#include<stdio.h>
#include <conio.h>
int main(){
    unsigned long int  b = 2, T = 0, N, a = 1, Sum = 2;
    printf("0 + 1 + 1 + 2 + 3 + 5 + 8 + ...........+ N \nEnter N: ");
    scanf("%ld",&N);
    N-=2;
    printf("0 + 1 + 1 + ");
    for(unsigned long int i = 1; i < N; i++){
        i == N-1 ? printf("%ld",b) : printf("%ld + ",b);
        Sum += b;
        T = b;
        b += a;
        a = T;
    }   
    printf(" = %ld\n",Sum);
    getch();
    return 0;
}
#include<stdio.h>
#include <conio.h>
long long fac(long long int x);
int main(){
    long long N,n;
    level:
    printf("Enter N between 1 to 20: ");
    scanf("%lld",&N);
    n=2*N;
    if(N>0 && N<21){
    for(long long k = n; k; k--)
        printf(" ");
    printf("1\n");
    n-=2;    
    for(long long i = 1; i<=N;i++){
        for(long long k = n; k; k--)
        printf(" ");
        n-=2;       
        printf("1");
        for(long long j = 1; j<i;j++)
            printf("   %lld",fac(i)/(fac(j)*fac((i-j))));
        printf("   1\n");
    }
    }else{
        printf("Enter between 1 to 20\n");
        goto level;
    }   
    getch();
}
long long fac(long long x){
    if(!x || x == 1)
        return 1;
    return x*fac(x-1);
}

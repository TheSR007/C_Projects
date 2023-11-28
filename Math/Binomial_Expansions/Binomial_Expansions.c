#include<stdio.h>
#include<conio.h>
long fac(long x);
int main(){
    int power,sign;
    level:
    printf("Enter The power: ");
    scanf("%d",&power);
    printf("Enter 1 if want negative or 0 for positive: ");
    scanf("%d",&sign);
    
    if(power>1 && !sign){
    printf("X^%d + ",power);
    for(int i = 1; i<power;i++)
        printf("%dX^%dY^%d +",fac(power)/(fac(i)*fac((power-i))),power-i,i);
    printf(" Y^%d",power); 
    }else if(sign && power>1){
    printf("X^%d ",power);
    for(int i = 1; i<power;i++){
        if(i%2==0)
        printf("+ %dX^%dY^%d",fac(power)/(fac(i)*fac((power-i))),power-i,i);
        else 
        printf("- %dX^%dY^%d",fac(power)/(fac(i)*fac((power-i))),power-i,i);
    }
    printf("- Y^%d",power);    
    }else if(power==1 && !sign){
        printf("X + Y");
    }else if(power==1 && sign){
        printf("X - Y");
    }else{
        printf("Enter between 1 to whatever");
        goto level;
    }   
    getch();
}
long fac(long x){
    if(!x)
        return 1;
    return x*fac(x-1);
}

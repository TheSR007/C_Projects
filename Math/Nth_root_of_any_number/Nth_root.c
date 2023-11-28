#include<stdio.h>
#include<complex.h>
#include<math.h>
#include<conio.h>
int main(){
    int N,iscomplex;
    double x,y,theta;
    complex double r,root;

printf("Enter 0 for Real numbers or 1 for complex numbers: ");
    scanf("%d",&iscomplex);
if(iscomplex){                                  //for complex numbers 
    printf("Enter a Complex number(X + Yi): ");
    scanf("%lf %lf",&x,&y);
    printf("Enter The power of root: ");
    scanf("%d",&N);
    if(x>0 && y>0)
        theta = atan(y/x);
    else if(x<0 && y>0)    
        theta = M_PI-atan(y/x);
    else if(x>0 && y<0)    
        theta = -atan(y/x);
    else if(x<0 && y<0)    
        theta = -M_PI+atan(y/x);
    else if(!x && !y)
        theta = 0;
    else if(!x)
        theta = M_PI/2;
    else if(!y)
        theta = 0;
    r = csqrt(cpow(x,2) + cpow(y,2));
    for(int i = 0;i<N;i++){
        root = cpow(r,1./N)*cexp(I*(theta+(2*M_PI*i))/N);
        if(!x)
            printf("%gi's %dth root is %g + (%gi)\n",y,i+1,creal(root),cimag(root));
        else if(!y)
            printf("%gi's %dth root is %g + (%gi)\n",x,i+1,creal(root),cimag(root));
        else
            printf("%g + (%gi)'s %dth root is %g + (%gi)\n",x,y,i+1,creal(root),cimag(root));
    }
}else{                                      //for real numbers
printf("Enter a real number X: ");
    scanf("%lf",&x);
    printf("Enter The power of root: ");
    scanf("%d",&N);  
    theta = 0;
    r = x;
    for(int i = 0;i<N;i++){
        root = cpow(r,1./N)*cexp(I*(theta+(2*M_PI*i))/N);
        if(!cimag(root))
            printf("%g's %dth root is %g\n",x,i+1,creal(root));
        else
            printf("%g's %dth root is %g + (%gi)\n",x,i+1,creal(root),cimag(root));
    }
}
    getch();
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<complex.h>
#define Omega (-1+sqrt(3)*I)/2

int main(){                 //I used the formula from wiki you can check them if you really want to understand how it is solving the equations
        int power,T;
        double a,b,c,d,e,Del0,Del1,Dc,P,R,D,p,q;
        double complex X1,X2,X3,X4,Cp,Cn,S,Q,Phi;
        printf("Polinomial Equation(1-4)\n");       
        level:
            printf("Pls Enter The Power of X: ");
            scanf("%d",&power);
            
            printf("Power of X is %d\n",power);
            switch(power){
                
                case 1:
                    printf("Plz Enter a & b(aX+b=0): ");
                    scanf("%lf %lf",&a,&b);
                    printf("X is %g",(-b/a));
                    break;
                case 2:
                    printf("Plz Enter a, b & c(aX^2+bX+c=0): ");
                    scanf("%lf %lf %lf",&a,&b,&c);
                    if((pow(b,2)-(4*a*c))<0){
                        X1 = ((-b+csqrtl((pow(b,2)-(4*a*c))))/(2*a));
                        X2 = conjl(X1);
                        printf("X1 is %g + %gi\nX2 is %g - %gi",creal(X1),cimag(X1),creal(X2),-cimag(X2)); 
                    }else if((pow(b,2)-(4*a*c))==0)
                        printf("X is %g(double)",(-b+sqrtf((pow(b,2)-(4*a*c))))/(2*a));
                    else
                        printf("X1 is %g\nX2 is %g",(-b+sqrtf((pow(b,2)-(4*a*c))))/(2*a),(-b-sqrtf((pow(b,2)-(4*a*c))))/(2*a));
                    break;
                case 3:
                    printf("Plz Enter a, b, c & d(aX^3+bx^2+cX+d=0): ");
                    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
                    Del0=pow(b,2)-(3*a*c);
                    Del1=(2*pow(b,3))-(9*a*b*c)+(27*d*pow(a,2));
                    Cp=cbrt((Del1+csqrt(pow(Del1,2)-4*pow(Del0,3)))/2);
                    Cn=cbrt((Del1-csqrt(pow(Del1,2)-4*pow(Del0,3)))/2);
                    Dc=(pow(b,2)*pow(c,2))-(4*a*(pow(c,3)))-(4*d*(pow(b,3)))-(27*(pow(a,2))*(pow(d,2)))+(18*a*b*c*d);
                    if(!Dc){
                       if(pow(b,2)==(3*a*c)){
                            printf("X is %g",-b/(3*a));
                       }else
                         printf("X1 is %g\nX2 is %g(double)",(((4*a*b*c)-(9*d*pow(a,2))-pow(b,3))/(a*(pow(b,2)-3*a*c))),(((9*a*d)-(b*c))/(2*(pow(b,2)-3*a*c))));
                    }
                    else{
                        if(Cp){
                            X1=(-1*(b+Cp+(Del0/Cp)))/(3*a);
                            printf("X1 is %g\n",creal(X1));
                            X1=(-1*(b+(Cp*Omega)+(Del0/(Cp*Omega))))/(3*a);
                            X2=conj(X1);
                            printf("X2 is %g + %gi\nX3 is %g - %gi",creal(X2),cimag(X2),creal(X1),-cimag(X1)); 
                        }else if(Cn){
                            X1=(-1*(b+Cn+(Del0/Cn)))/(3*a);
                            printf("X1 is %g\n",-creal(X1));
                            X1=(-1*(b+(Cn*Omega)+(Del0/(Cn*Omega))))/(3*a);
                            X2=conj(X1);
                            printf("X2 is %g + %gi\nX3 is %g - %gi",creal(X1),cimag(X1),creal(X2),-cimag(X2));
                        }
                      }
                    break;
                case 4:
                    printf("Plz Enter a, b, c, d & e(aX^4+bx^3+cX^2+dX+e=0): ");
                    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
                    Dc=(256*pow(a,3)*pow(e,3))-(192*pow(a,2)*b*d*pow(e,2))-(128*pow(a,2)*pow(c,2)*pow(e,2))+(144*pow(a,2)*c*pow(d,2)*e)-(27*pow(a,2)*pow(d,4))+(144*c*a*pow(b,2)*pow(e,2))-(6*a*e*pow(b,2)*pow(d,2))-(80*a*b*pow(c,2)*d*e)+(18*a*b*c*pow(d,3))+(16*a*pow(c,4)*e)-(4*a*pow(c,3)*pow(d,2))-(27*pow(b,4)*pow(e,2))+(18*pow(b,3)*c*d*e)-(4*pow(b,3)*pow(d,3))-(4*pow(b,2)*pow(c,3)*e)+(pow(b,2)*pow(c,2)*pow(d,2));
                    P=(8*a*c)-(3*pow(b,2));
                    R=pow(b,3)+(8*d*pow(a,2))-(4*a*b*c);
                    Del0=pow(c,2)-(3*b*d)+(12*a*e);
                    Del1=(2*pow(c,3))-(9*b*c*d)+(27*pow(b,2)*e)+(27*pow(d,2)*a)-(72*a*c*e);
                    D=(64*pow(a,3)*e)-(16*pow(a,2)*pow(c,2))+(16*a*pow(b,2)*c)-(16*b*d)-(3*pow(b,4));
                    p=((8*a*c)-(3*pow(b,2)))/(8*pow(a,2));
                    q=((pow(b,3))-(4*a*b*c)+(8*pow(a,2)*d))/(8*pow(a,3));
                    Q=cbrt((Del1+csqrt(pow(Del1,2)-(4*pow(Del0,3))))/2);
                    Phi=acos(Del1/(2*csqrt(pow(Del0,3))));
                    
                    S=csqrt(((-2*p)/3)+((Q+(Del0/Q))/(3*a)))/2;
                    if(Dc>0)
                        S=csqrt(((-2*p)/3)+((2*csqrt(Del0)*cos(Phi/3))/(3*a)))/2;
                   // printf("Dc is %g\nP is %g\nR is %g\nDel0 is %g\nDel1 is %g\nD is %g\np is %g\nq is %g\nS is %g and %gi\nQ is %g and %gi\n",Dc,p,R,Del0,Del1,D,p,q,creal(S),cimag(S),creal(Q),cimag(Q));
                    X1=((-b/(4*a))-S+(csqrt((-4*pow(S,2))-(2*p)+(q/S))/2));
                    X2=((-b/(4*a))-S-(csqrt((-4*pow(S,2))-(2*p)+(q/S))/2));
                    X3=((-b/(4*a))+S+(csqrt((-4*pow(S,2))-(2*p)-(q/S))/2));
                    X4=((-b/(4*a))+S-(csqrt((-4*pow(S,2))-(2*p)-(q/S))/2));
                    /*
                    if(!Dc){
                        if(P<0 && D<0 && Del0){
                            //2 real double and real 2 simple
                            printf("X1 is %g\nX2 is %g\nX3 is %g\nX3 is %g",creal(X1),creal(X2),creal(X3),creal(X4));
                        }else if(D>0 || (P>0 && (D || R))){
                            //2 real double and 2 complex
                            printf("X1 is %g(double)\nX2 is %g + %gi\nX3 is %g - %gi\n",creal(X3),creal(X1),cimag(X1),creal(X2),-cimag(X2));
                        }else if(!Del0 && D){
                            //all real and a triple and a simple
                            printf("X1 is %g\nX2 is %g\nX3 is %g\nX3 is %g",creal(X1),creal(X2),creal(X3),creal(X4));
                        }else if(!D){
                            if(P<0){
                                //2 real double
                            }else if(P>0 && !R){
                                //2 complex conjugate double roots
                            }else if(!Del0){
                                printf("X is %g(all same)",-b/(4*a));
                            }
                        }
                    }else if(Dc>0){
                        if(P<0 && D<0){
                            //all real and distinct
                        }else if(P>0 || D>0){
                            //2 pairs of non real complex conjugate
                        }
                    }else if(Dc<0)
                        //2 real and 2 complex conjugate
                   }
                  */
                    if(S && Q && Dc)
                        printf("X1 is %g+(%gi)\nX2 is %g+(%gi)\nX3 is %g+(%gi)\nX4 is %g+(%gi)",creal(X1),cimag(X1),creal(X2),cimag(X2),creal(X3),cimag(X3),creal(X4),cimag(X4));//for Dc>0 && Dc<0
                  
                    else if(!Dc){
                    if(!D && !Del0)
                        printf("X is %g",-b/4*a);              
                    else if(!Dc && !Del0 && !Del1){
                    double A = a;
                    a=3*A;
                    c=0;
                    d=0;
                    Dc=(256*pow(a,3)*pow(e,3))-(192*pow(a,2)*b*d*pow(e,2))-(128*pow(a,2)*pow(c,2)*pow(e,2))+(144*pow(a,2)*c*pow(d,2)*e)-(27*pow(a,2)*pow(d,4))+(144*c*a*pow(b,2)*pow(e,2))-(6*a*e*pow(b,2)*pow(d,2))-(80*a*b*pow(c,2)*d*e)+(18*a*b*c*pow(d,3))+(16*a*pow(c,4)*e)-(4*a*pow(c,3)*pow(d,2))-(27*pow(b,4)*pow(e,2))+(18*pow(b,3)*c*d*e)-(4*pow(b,3)*pow(d,3))-(4*pow(b,2)*pow(c,3)*e)+(pow(b,2)*pow(c,2)*pow(d,2));
                    P=(8*a*c)-(3*pow(b,2));
                    R=pow(b,3)+(8*d*pow(a,2))-(4*a*b*c);
                    Del0=pow(c,2)-(3*b*d)+(12*a*e);
                    Del1=(2*pow(c,3))-(9*b*c*d)+(27*pow(b,2)*e)+(27*pow(d,2)*a)-(72*a*c*e);
                    D=(64*pow(a,3)*e)-(16*pow(a,2)*pow(c,2))+(16*a*pow(b,2)*c)-(16*b*d)-(3*pow(b,4));
                    p=((8*a*c)-(3*pow(b,2)))/(8*pow(a,2));
                    q=((pow(b,3))-(4*a*b*c)+(8*pow(a,2)*d))/(8*pow(a,3));
                    Q=cbrt((Del1+csqrt(pow(Del1,2)-(4*pow(Del0,3))))/2);
                    Phi=acos(Del1/(2*csqrt(pow(Del0,3))));
                    S=csqrt(((-2*p)/3)+((Q+(Del0/Q))/(3*a)))/2;
                    if(Dc>0 && (cimag(S) || cimag(Q)))
                        S=csqrt(((-2*p)/3)+((2*csqrt(Del0)*cos(Phi/3))/(3*a)))/2;
                    //printf("Dc is %g\nP is %g\nR is %g\nDel0 is %g\nDel1 is %g\nD is %g\np is %g\nq is %g\nS is %g and %gi\nQ is %g and %gi\n",Dc,p,R,Del0,Del1,D,p,q,creal(S),cimag(S),creal(Q),cimag(Q));
                    X1=round(((-b/(4*a))-S+(csqrt((-4*pow(S,2))-(2*p)+(q/S))/2))*10)/10;
                    X2=round(((-b/(4*a))-S-(csqrt((-4*pow(S,2))-(2*p)+(q/S))/2))*10)/10;
                    X3=round(((-b/(4*a))+S+(csqrt((-4*pow(S,2))-(2*p)-(q/S))/2))*10)/10;
                    X4=round(((-b/(4*a))+S-(csqrt((-4*pow(S,2))-(2*p)-(q/S))/2))*10)/10;
                    //printf("X1 is %g+(%gi)\nX2 is %g+(%gi)\nX3 is %g+(%gi)\nX4 is %g+(%gi)\n",creal(X1),cimag(X1),creal(X2),cimag(X2),creal(X3),cimag(X3),creal(X4),cimag(X4));
                    if(floor(X1)==ceil(X1))
                       printf("X1 is %g(triple)\nX2 is %g",creal(X1),e/(A*pow(creal(X1),3))); 
                    else if(floor(X2)==ceil(X2))
                       printf("X1 is %g(triple)\nX2 is %g",creal(X2),e/(A*pow(creal(X2),3))); 
                    else if(floor(X3)==ceil(X3))
                       printf("X1 is %g(triple)\nX2 is %g",creal(X3),e/(A*pow(creal(X3),3))); 
                    else if(floor(X4)==ceil(X4))
                       printf("X1 is %g(triple)\nX2 is %g",creal(X4),e/(A*pow(creal(X4),3)));   
                   }else if(P>0 && !R)
                        printf("X1 is %g+(%gi)\nX2 is %g+(%gi)",creal(X2),cimag(X2)/2,creal(X4),cimag(X4)/2);else
                        printf("X1 is %g+(%gi)\nX2 is %g+(%gi)\nX3 is %g+(%gi)\nX4 is %g+(%gi)",creal(X1),cimag(X1),creal(X2),cimag(X2),creal(X3),cimag(X3),creal(X4),cimag(X4));
                    
                  }
                    break;
                default:
                    printf("Plz Enter a number between 1 to 4\n");
                    goto level;   
                    break;            
            }
            a=0,b=0,c=0,d=0,e=0;
            printf("\npls Enter 0 to exit :) or 1 to continue: ");
            scanf("%d",&T);
            if(!T)
                exit(0);
            else
                goto level;

        

    getch();
    return 0;
}
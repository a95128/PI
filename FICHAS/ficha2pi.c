#include <stdio.h>

//EXERCICIO 1

float multInt1(int n, float m) {
    float res = 0.0;
    int i = 0;
    while(i<n) {
        res += m;
        i++;
    }
printf("%f\n",res);
return res;
}

//EXERCICIO 2

float multInt2(int n, float m) {
    float res = 0.0;
    while(n>0) {
        if(n%2!=0) {
            res += m;
        }
    n=n/2;
    m=m*2;
    }

printf("%f\n",res);
return res;
}

//EXERCICIO 3

int mdc1(int a, int b) {
    int menor, maior, mdc;
    if (a>=b) {menor = b; maior=a;} else {menor=a;maior=b;}
    mdc = 1;
    for(int i = 1; i<= menor; i++) {
        if(menor % i == 0 && maior % i == 0) {
            mdc = i;
        }
    }
printf("%d\n",mdc);
return mdc;
}

//EXERCICIO 4

int mdc2(int a, int b) {
int res=0;

while(a!=b) {
    if(a>=b) {a=a-b;}
    if(a<b) {b=b-a;}    
}
if (a==0) {res = b;} else {res = a;}
printf("%d\n",res);
return res; 
}

//EXERCICIO 5

int mdc3(int a, int b) {
    int res;

    while (a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }

    res = b;

    printf("%d\n", res);
    return res;
}

//EXERCICIO 6.A

int fib1(int n) {
    int res;
    if (n<2) res =1;
    if (n>=2) res = fib1(n-1) + fib1(n-2);

    printf("%d\n", res);
    return res;

}

int fib2(int n) {
    int res, aux1, aux2;
    aux1 = n-1;
    aux2= n-2;

    if (n == 0) {
        res = 0;;
    } else if (n == 1) {
        res = 1;
    }
    else {res = fib1(aux1) + fib1(aux2);}

    printf("%d\n", res);
    return res;
}

int main() {
    int x,y;
    //scanf("%d%d", &x, &y);
    scanf("%d", &x);
    //multInt1(x,y);
    //multInt2(x,y);
    //mdc1(x,y);
    //mdc2(x,y);
   // mdc3(x,y);
    fib2(x);
    return 0;
}


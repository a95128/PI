#include <stdio.h>

//EXERCICIO 1.A) 

/*int main () {
int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11,12,13,14,15};
int *y, *z, i;
y = x;
z = x+3;
for (i=0; i<5; i++) {
printf ("%d %d %d\n",
x[i], *y, *z);
y = y+1; z = z+2;
}*/

// i = 0 output: 1, 1, 4  //atualiza: y = 2; z = 6
// i = 1 output: 2, 2, 6  //atualiza: y = 3; z = 8
// i = 2 output: 3, 3, 8  //atualiza: y = 4; z = 10
// i = 3 output: 4, 4, 10 //atualiza: y = 5; z = 12
// i = 4 output: 5, 5, 12 //atualiza: y = 6; z = 14

//EXERCICIO 1.B)

/*
int main () {
    int i, j, *a, *b;
    i=3; j=5;
    a = b = 42;
    a = &i; b = &j;
    i++;
    j = i + *b;
    b = a;
    j = j + *b;
    printf ("%d\n", j);
return 0;
}
*/

// i = 3 => j = 5 => a = b = 42; (relembrando que sao apontadores) designacao inutil; 
// a = 3; b = 5; i = 4; (consequentemente a = 4) j = 4 + 5 = 9; b = 4 ; j = + 4= 13; 
// output: 13

//EXERCICIO 2

void swapM (int *x, int *y) {
    int a;
    a = *x;
    *x = *y;
    *y = a;
}


//EXERCICIO 3

void swap (int v[], int i, int j) {
    int a = v[i];
    v[i]= v[j];
    v[j] = a;
    
}

//EXERCICO 4

int soma (int v[], int N) {

    int i = 0;
    int soma=0;
    while (i<= N) {
        soma += v[i];
        i++;
    }

    return soma;

}

//EXERCICIO 5 //VER A DIFERENÇA ENTRE ELAS NO CTUTOR AGAIN

void inverteArrayV1 (int v[], int N) {
    for(int i = 0; i <= N/2 ; i++) {
        swap(v, i, N - 1-i);
    }
}

void inverteArrayV2 (int v[], int N) {
    for(int i = 0; i <= N/2 ; i++) {
        swapM(&v[i],&v[N-1-i]);
    }
}

//EXERCICIO 6

int main () {
    int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10, 11,12,13,14,15};
    //int x = 3, y = 5;
    //swapM (&x, &y);
   // printf ("%d %d\n", x, y);
   //swap(x, 3, 4);
   //int res = soma(x, 15);
   //printf("%d\n", res);
   inverteArrayV1(x,15);
   inverteArrayV2(x,15);


    return 0;
}
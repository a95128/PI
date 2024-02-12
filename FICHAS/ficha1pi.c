#include <stdio.h>
#include <math.h>

//1:ESTADO E ATRIBUIÇÕES

//1: x = 3; y = 4; x = 12; y = 16 -> printf(12,16)

//2: printf(0,random)

//3:  printf('A';65); printf('B', 66, '2',50)

//4: x = 200; y = 100; x = 300; y = 300-100 = 200; x = 100; printf(100,200)


//2:ESTRUTURAS DE CONTROLO

//a: printf(3,5)

//b: x = 1; y = 1; x = 2; y= 3; x =3; y = 6; x=4; y = 10; x = 5;y=15; x = 6; y = 21; x =7; y = 28; x = 8; y = 36; x=9;y=45; x =10; y=55; x = 11;y=66; printf(11,66)

//c: printf(_#_#_#_#_#_#_#_#_#_#)

/*d: 
0:
1:1
2:01
3:11
4:001
5:101
6:011
7:111
8:0001
9:1001
10:0101
11:1101
12:0011
13:1011
14:0111
15:1111
*/

//3:PROGRAMAS ITERATIVOS

void quadrado(int x) {
    for(int i = 0; i < x;i++) {
        for(int j = 0; j < x;j++) {
            putchar('#');
        }
    putchar('\n');
    }
} 

void xadrez(int x) {
    for(int i = 0; i <x;i++) {
        for(int j = 0;j<x;j++) {
            if(i%2==0) {
                if(j%2==0) { putchar('#');} 
                else {putchar('_');}}
            
            if(i%2!=0) {
                if(j%2==0) { putchar('_');} 
                else {putchar('#');}}
            } 

    putchar('\n');

        }
    }

void trianguloum(int x) {
    for(int i = 0;i<x;i++) {    
        for(int j = 0; j<x;j++) {
            if (j<=i) putchar('#');
            else printf("%s","");
    }
        putchar('\n');

    }

    for(int i = x-1;i>0;i--) {
        for(int j = 0; j<x;j++) {
            if (j<i) putchar('#');
            else printf("%s","");
    }
        putchar('\n');

    }

}

void triangulodois(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x - i - 1; j++) {
            printf(" ");
        }

        for (int k = 0; k < 2 * i + 1; k++) {
            printf("#");
        }

        for (int j = 0; j < x - i - 1; j++) {
            printf(" ");
        }

        printf("\n");
    }
}

void desenhar_circulo(int raio) {
    int diametro = raio * 2;

    for (int y = -raio; y <= raio; y++) {
        for (int x = -diametro; x <= diametro; x++) {
            if (sqrt(x * x + y * y) <= raio) {
                printf("#");  
            } else {
                printf(" ");  
        }
        }
        printf("\n");  
    }
}


int main() {
    int n;
    scanf("%d", &n);
    //quadrado(n);
    //xadrez(n);
    //trianguloum(n);
    triangulodois(n);
    desenhar_circulo(5);
    return 0;
}

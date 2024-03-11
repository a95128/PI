#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//EXERCICIO 1

void maior() {
   int maior, num;
   scanf("%d", &maior);
   while(1) {
       scanf("%d", &num);
       if(num == 0) break;
       if(num > maior) maior = num;
   }
   printf("Maior: %d\n", maior);
}

//EXERCICIO 2

void media() {
    float media, num;
    int count;
    while(1) {
       scanf("%f", &num);
       if(num == 0) break;
       media += num;
       count++;
   }
   media = media/count;
   printf("Média: %.3f\n", media);
}

//EXERCICIO 3

void segundomaior() {
    int maior = 0, segundo_maior = 0, num;
    scanf("%d", &maior);
    while(1) {
       scanf("%d", &num);
       if(num == 0) break;
       if(num >= maior) {
           segundo_maior = maior; 
           maior = num; 
       } else if (num > segundo_maior) {
           segundo_maior = num;
   }
   printf("Segundo maior: %d\n", segundo_maior);
}
}

//EXERCICIO 4

int bitsUm(unsigned int n) {
    int count=0;
    while(n!=0) {
        if(n%2!=0) {
            count++;
        }
        n=n/2;
    }
    return count;
}

//EXERCICIO 5

int trailingZ(unsigned int n) {
    int count=0;
    while(n!=0) {
        if(n%2==0) {
            count++;
        }
        n=n/2;
    }
    return count;
}

//EXERCICIO 6

int qDig (unsigned int n) {
    int count=0;
    while(n!=0) {
        n=n/10;
        count++;
    }
    return count;
}

//EXERCICIO 7

char *strcattest(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i, j;
    char *aux = (char *)malloc(len1 + len2 + 1);
    for (int i = 0; i < len1; i++) {
        aux[i] = s1[i];
    }

    for (int j = 0; j < len2; j++) {
        aux[len1 + j] = s2[j];
    }
    aux[len1 + len2] = '\0'; 
    return aux;
}

//EXERCICIO 8



int main () {
    //one();
    //media();
    //segundomaior();
    //int res = bitsUm(7);
    //int res = trailingZ(8);
    //int res = qDig(440);
    //printf("%d\n", res);
    char s1[] = "Hello, ";
    char s2[] = "world!";
    char *result = strcattest(s1, s2);
    printf("%s\n", result);
    free(result); 
    return 0;
}
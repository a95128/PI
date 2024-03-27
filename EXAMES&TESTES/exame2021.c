#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//EXERCICIO 1

int pesquisa(int a[], int N, int x) {
    int indice = -1;
    for(int i = 0; i < N; i++) {
        if (a[i]==x) {
            indice = x;
        }
    }

    return indice;
}

//EXERCICIO 4

void checksum (char s[]) {
    int soma = 0;
    int tamanho = strlen(s);
    int numero = 0;
    for(int i = tamanho -1; i >= 0; i--) {
        if(i%2!=0) {
            numero = s[i] - '0'; //passsa pra inteiro
            numero = 2*numero;
            int parte_inteira = numero/10;
            int resto=numero%10;

            soma += parte_inteira + resto;
        }
        else {
            numero =s[i] - '0';
            soma += numero;
        }
    }
    
    int digito_controle = soma%10;
    digito_controle = 10-digito_controle;
    if (digito_controle == 10) digito_controle = 0;
    s[tamanho] = digito_controle + '0';
    s[tamanho+1] = '\0';

    for(int i =0;s[i]!='\0';i++) {
        printf("%c ", s[i]);
    }

}

//EXERCICIO 5

int escolhe(int N, int valor[], int peso[], int C, int quant[]) {
    int q = 0, j = 0;
    int peso_atual = 0;
    int valor_total = 0;

    for(int i = 0; i < N; i++) {
        q = 0;
        while(peso_atual+peso[i]<= C) {
            peso_atual=peso_atual + peso[i];
            q++;
            quant[j] = q;

        }
        j++;
    }

    for(int t = 0; t < N; t++) {
        valor_total+=quant[t] * valor[t];
    }
    return valor_total;

}


int main() {
    //int N = 3;
    //int valor[] = {20, 150, 30};
    //int peso[] = {20, 10, 3};
    //int C = 14;
    //int quant[N];
//
    //int valor_total = escolhe(N, valor, peso, C, quant);
//
    //printf("Valor total: %d\n", valor_total);
    //printf("Quantidades: ");
    //for (int i = 0; i < N; i++) {
    //    printf("%d ", quant[i]);
    //}
    //printf("\n");
    char s[] = "9871";
    checksum(s);

    return 0;
}

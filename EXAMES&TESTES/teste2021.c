#include <stdio.h>
#include <string.h>


//EXERCICIO 1

void ordena(int array[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int nesimo(int a[], int N, int i) {
    ordena(a, N); 
    int numero = a[i - 1]; 
    return numero;
}

//EXERCICIO 4

void inc(char s[]) {
    int tamanho = strlen(s), j = 0;
    if(s[tamanho-1]< '9' && s[tamanho - 1] >= 0) {
        int numero = s[tamanho -1] - '0';
        numero++;
        s[tamanho-1] = numero + '0';
    }
    else {
        while(s[tamanho-1-j] == '9' && (tamanho-1-j >=0)) {
            s[tamanho-1-j] = '0';
            j++;
        }
        int aux = s[tamanho-1-j] -'0';
        aux++;
        s[tamanho-1-j] = aux+'0';

    }

    for(int i = 0; i < tamanho;i++) {
        printf("%c", s[i]);
    }
}

int main() {
    //int array[] = {3,4,2, 0};
    //int N = 4;
    //int i = 3;
    //int result = nesimo(array, N, i);
    //printf("%d-ésimo menor elemento: %d\n", i, result);

    char s[] = "199";
    inc(s);
    
    return 0;
}
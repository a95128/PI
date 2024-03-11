#include <stdio.h>
#include <string.h>
#include <assert.h>

int evogal(char c) {
    // Verifica se o caractere é uma vogal (maiúscula ou minúscula)
    if ((c == 'a' || c == 'A') || 
        (c == 'e' || c == 'E') || 
        (c == 'i' || c == 'I') || 
        (c == 'o' || c == 'O') || 
        (c == 'u' || c == 'U')) {
        return 1;
    } else {
        return 0;
    }
}

int contaVogais(char *s) {
    int countavogais = 0;

    for(int i = 0; s[i]!= '\0';i++) {
        if ((s[i]=='a' || s[i]=='A') || 
           (s[i]=='e' || s[i]=='E') || 
           (s[i]=='i' || s[i]=='I') || 
           (s[i]=='o' || s[i]=='O') || 
           (s[i]=='u' || s[i]=='U'))
           countavogais++;
    }
    
    return countavogais;
}   

//TA MAL ESTE

int retiraVogaisRep(char *s) { 
    char aux[strlen(s)+1];
    int count = 0;
    int j = 1;
    int i;
    aux[0] = s[0];
    for(int i = 1; i < strlen(s)+1;i++) {
        if(!(evogal(s[i]) && s[i]==s[i-1])) {
            aux[j++] = s[i];
        }
        else {
            count++;
        }
    }    

    for(int i = 1; i<j;i++) {
        s[i]= aux[i];
    }
    s[i] = '\0';
    return count;
}

int retiraVogaisRep2(char *s) {
    char *n = s;
    char *p = s + 1;
    int c = 0; // Inicializa a contagem de caracteres removidos

    while (*p != '\0') {
        if (!(evogal(*p) && *p == *n)) {
            n++;
            *n = *p; // Corrige o operador de atribuição
        } else {
            c++;
        }

        p++;
    }    
    *(n + 1) = '\0';

    assert(c == (p - n - 1));
    return c;
}

int partition (int v[], int N, int x) {
    int t[N];
    for (int i = 0; i < N; i++) {
        if(v[i]<=x) {
            t[i]=v[i];
        }
    }
    for(int i = 0;i<N;i++) {
        if(v[i]>=x) {
            t[sizeof(t)] = v[i];
        }
    }
    return t;
}

int main() {
    char string1[] = "alface";
    char string2[] = "Estaa e umaa string coom duuuplicadoos"; 
    int teste[6]={1,7,8,9,1,2};
        int N = 6;
    int x = 4;
    
    int *resultado = partition(teste, N, x);
    
    printf("Array particionado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");
    // int res = contaVogais(string1);
    int res = retiraVogaisRep2(string2);
    printf("%d\n", res);
    printf("%s\n", string2);
    printf("%d\n", partition(teste, 6, 4));
    return 0;
}
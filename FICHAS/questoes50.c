#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

//EXERCICIO 7

char *mystrcat(char s1[], char s2[]) {
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

char *mystrcpy (char *dest, char source[]) {
    int i;
    for(i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0'; // Null terminate the destination string
    return dest;
}

//EXERCICIO 9

int mystrcmp (char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i]) {
            return -1; 
        } else if (s1[i] > s2[i]) {
            return 1;
        }
        i++;
    }

    if (s1[i] != '\0' && s2[i] != '\0'){
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

//EXERCICIO 10

//EXERCICIO 11

void strrev (char s[]) {
    char aux;
    int length = strlen(s);
    for(int i = 0; i != (length-1)/2; i++) {
        aux = s[length-i-1];
        s[length-i-1] = s[i];
        s[i] = aux;

    }
    printf("%s", s);
}

//EXERCICIO 12

int evogal(char l) {
    if (l=='a' || l=='A' ||
        l=='e' || l=='E' ||
        l=='i' || l=='I' ||
        l=='o' || l=='o' ||
        l=='u' || l=='U') 
        return 0;
}
void strnoV (char s[]) {
    char aux[strlen(s)+1];
    int j = 0;
    for(int i =0; s[i] != '\0' ; i++) {
        if(evogal(s[i]) != 0) {
            aux[j] = s[i];
            j++;
        }
    }
    printf("%s", aux);
}

//EXERCICIO 13

void delete (int i, char s[]) {
    for (i;s[i];i++)
        s[i]=s[i+1];
}

void truncW (char t[], int n){
    int i = 0;
    int comp = 0;
    char c;
    while (t[i])
        if (t[i] == ' ') {
            comp = 0;
            i++;
        } else if (comp<n) {
            comp++;
            i++;
        }
        else {delete (i,t);
            comp++;
        }
    printf("%s",t);
    
}

//EXERCICIO 14

int conta(char c, char s[]) {
    int conta=0;
    for(int i=0; s[i]!='\0';i++) {
        if(s[i]==c){ conta++;};
    }

    return conta;
}

char charMaisfreq (char s[]) {
    char aux=s[0];
    for(int i = 0; s[i]!='\0';i++) {
        if(conta(s[i], s) > conta(aux,s)) {aux = s[i];}
    }
    return aux;
}

//EXERCICIO 15

int iguaisConsecutivos(char s[]) {
    int conta1 = 1;
    int aux = 1; 
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++) {
        if (s[i] == s[i + 1]) {
            conta1++; 
            if (conta1 > aux) {
                aux = conta1;
            }
        } else {
            conta1 = 1; 
        }
    }
    return aux;
}


//EXERCICIO 16

int difConsecutivos (char s[]) {
   int conta1 = 1;
    int aux = 1; 
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++) {
        if (s[i] != s[i + 1]) {
            conta1++; 
            if (conta1 > aux) {
                aux = conta1;
            }
        } else {
            conta1 = 1; 
        }
    }
    return aux;
} 

//EXERCICIO 17

int maiorPrefixo (char s1 [], char s2 []) {
    
}

int main() {
    char s1[] = "Hello,";
    char s2[] = "World";
    char s3[] = "liberdade, igualdade e fraternidade";
    char s4[] = "aabcccaac";

    //char* result = mystrcat(s1,s2);
    //printf("%s\n", result);

    //char dest[50];
    //char source[] = "Copying this string";
    //mystrcpy(dest, source);
    //printf("%s\n", dest);
    //strrev(s1);
    //strnoV(s2);
    //truncW(s3,4);
    //char r = charMaisfreq(s3);
    //int r = iguaisConsecutivos(s4);
    int r = difConsecutivos(s1);
    printf("%d", r);
    return 0;
}
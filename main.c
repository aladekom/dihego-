#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURA DOS DADOS
typedef struct {
    char titulo[100];
    float preco;
} Livro;

// Opcao && opcaoOrdenacao

// criar variaveis do tipo livro com IA para deixar na lista desordenado

int CompararNomes( char s1[], char s2[]){
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] > 90){
        s1[i] = (s1[i]) - 32;
        }  
        if(s2[i] > 90){
        s2[i] = (s2[i]) - 32;
        }
        i++;
    }
    return s1[i] - s2[i];
}

void ordenaTitulo(int tipoOrdenação){
    Livro titulosOrdenados;

    for(int i = 0; i<5;i++){
        titulosOrdenados[i] = 
    }
    for(int i=0; i<5;i++){
        for(int k=1; k<5-1; k++){
            if(CompararNomes(livro[i].titulo, livro[k].titulo)>0){

            }
        }
    }
    
}

void ordenaPreco(void){
    int k;
    k = livros[0].preco;
    for(int i=0; i<100;i++){
        if (    livros[i].preco < k){
            k = livros[i].preco;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURA DOS DADOS
typedef struct {
    char titulo[100];
    float preco;
} Livro;
 
Livro livros[100]; //vetor de livros//
// Opcao && opcaoOrdenacao

/*void compararTitulosSeguro(char s1[], char s2[]){

    if(s1[i]>90){
        s1[i] -= '0';
        s1[i] -= 32;
    }
    if(s2[j]>90){
        s2[j] -= '0';
        s2[j] -= 32;
    }
}
void ordenaTitulo(int opcao, int opcaoOrdenacao){
    for(int i=0;i<nTitulos;i++){
        for(int j=0;j<nTitulos-1;j++){
            compararTitulosSeguro(livro[i].titulo, livro[j].titulo)
        }  
    }

}*/
void ordenaPreco(void){
    int k;
    k = livros[0].preco;
    for(int i=0; i<100;i++){
        if (    livros[i].preco < k){
            k = livros[i].preco;
        }
    }
}
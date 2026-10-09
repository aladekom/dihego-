#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURA DOS DADOS
typedef struct {
    char titulo[100];
    float preco;
} Livro;

// Opcao && opcaoOrdenacao

// criar variaveis do tipo livro com 
Livro listaLivros[5] = { 
    {"Pai rico, filho probissímo", 39.90}, 
    {"Ricke and Mori", 29.90}, 
    {"50 tons de rosa", 25.00},
    {"As crônicas de nargas", 45.50},
    {"Capitões do IFBA", 34.90}
};

//função para comparar nomes transformando letra por letra em minusculas
int compararNomesSeguro(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        //criei essas temporarias para n mexer direto no titulo dos livros
        char c1 = s1[i];
        char c2 = s2[i];

        if (c1 == '\n') 
        c1 = '\0';
        if (c2 == '\n') 
        c2 = '\0';

        if (c1 == '\0' || c2 == '\0') 
        break;

        if (c1 >= 'A' && c1 <= 'Z') 
        c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') 
        c2 += 32;

        if (c1 != c2) {
            return c1 - c2;
        }
        i++;
    }
    return 0;
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURA DOS DADOS
typedef struct {
    char titulo[100];
    float preco;
} Livro;

// variaveis do tipo livro
Livro listaLivros[5] = { 
    {"Pai rico, filho probissimo", 39.90}, 
    {"Ricke and Mori", 29.90}, 
    {"Belo e a Fera", 25.00},
    {"As cronicas de nargas", 45.50},
    {"Capitoes do IFBA", 34.90}
};

//função para comparar nomes transformando letra por letra em minusculas
int compararNomes(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        //criei essas temporarias para n mexer direto no titulo dos livros
        char c1 = s1[i];
        char c2 = s2[i];

        if (c1 == '\n') //Transforma \n em \0
        c1 = '\0';
        if (c2 == '\n') 
        c2 = '\0';

        if (c1 == '\0' || c2 == '\0') 
        break;

        if (c1 >= 'A' && c1 <= 'Z') //Transforma maiusculas em minusculas
        c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') 
        c2 += 32;

        if (c1 != c2) {
            return c1 - c2;  //Se entrar nesse if já significa que uma palavra é alfabeticamente maior que a outra
        }
        i++;
    }
    return 0;
}

//tipo 1 Crescente 
//tipo 0 Decrescente 
void ordenaTitulo(int tipoOrdenacao){
    Livro titulosOrdenados[5];

    for(int i = 0; i<5;i++){
        titulosOrdenados[i] = listaLivros[i];
    }
    for(int i=0; i<5;i++){
        for(int k=i+1; k<5; k++){
            int comp = compararNomes(titulosOrdenados[i].titulo, titulosOrdenados[k].titulo);

    //Ordem CRESCENTE (A-Z)
    if(tipoOrdenacao == 1) {
        if (comp > 0) { // Se o primeiro for MAIOR alfabeticamente, troca
        Livro temp = titulosOrdenados[i];
        titulosOrdenados[i] = titulosOrdenados[k];
        titulosOrdenados[k] = temp;
        }
    }

    //Ordem DECRESCENTE (Z-A)
    if (tipoOrdenacao == 0) {
        if (comp < 0) { // Se o primeiro for MENOR alfabeticamente, troca
        Livro temp = titulosOrdenados[i];
        titulosOrdenados[i] = titulosOrdenados[k];
        titulosOrdenados[k] = temp;
        }
    }
    }
}
    printf("\n=== LIVROS ORDENADOS POR TITULO ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Titulo: %-30s | Preco: R$ %.2f\n", titulosOrdenados[i].titulo, titulosOrdenados[i].preco);
    }
}

void ordenaPreco(void){
    int k;
    k = listaLivros[0].preco;
    for(int i=0; i<100;i++){
        if (listaLivros[i].preco < k){
            k = listaLivros[i].preco;
        }
    }
}

int main(void){
    ordenaTitulo(1);
    return 0;
}
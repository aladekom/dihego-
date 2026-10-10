#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. ESTRUTURA DOS DADOS
typedef struct {
    char titulo[100];
    float preco;
} Livro;

// Lista original (desorganizada por padrão)
Livro listaLivros[5] = { 
    {"Pai rico, filho probissimo", 39.90}, 
    {"Ricke and Mori", 29.90}, 
    {"Belo e a Fera", 25.00},
    {"As cronicas de nargas", 45.50},
    {"Capitoes do IFBA", 34.90}
};

// Função para comparar nomes transformando letra por letra em minúsculas
int compararNomes(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        char c1 = s1[i];
        char c2 = s2[i];

        if (c1 == '\n') c1 = '\0';
        if (c2 == '\n') c2 = '\0';

        if (c1 == '\0' || c2 == '\0') break;

        if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 32;

        if (c1 != c2) {
            return c1 - c2;  
        }
        i++;
    }
    return 0;
}

// Exibe a lista original (desorganizada)
void exibeOriginal(void) {
    printf("\n=== LISTA ORIGINAL (DESORGANIZADA) ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Titulo: %-30s | Preco: R$ %.2f\n", listaLivros[i].titulo, listaLivros[i].preco);
    }
}

// tipoOrdenacao: 1 = Crescente (A-Z), 0 = Decrescente (Z-A)
void ordenaTitulo(int tipoOrdenacao){
    Livro titulosOrdenados[5];

    for(int i = 0; i < 5; i++){
        titulosOrdenados[i] = listaLivros[i];
    }
    for(int i = 0; i < 5; i++){
        for(int k = i + 1; k < 5; k++){
            int comp = compararNomes(titulosOrdenados[i].titulo, titulosOrdenados[k].titulo);

            if(tipoOrdenacao == 1) {
                if (comp > 0) { 
                    Livro temp = titulosOrdenados[i];
                    titulosOrdenados[i] = titulosOrdenados[k];
                    titulosOrdenados[k] = temp;
                }
            }
            if(tipoOrdenacao == 0) {
                if (comp < 0) { 
                    Livro temp = titulosOrdenados[i];
                    titulosOrdenados[i] = titulosOrdenados[k];
                    titulosOrdenados[k] = temp;
                }
            }
        }
    }
    printf("\n=== LIVROS ORDENADOS POR TITULO (%s) ===\n", tipoOrdenacao == 1 ? "Crescente (A-Z)" : "Decrescente (Z-A)");
    for (int i = 0; i < 5; i++) {
        printf("Titulo: %-30s | Preco: R$ %.2f\n", titulosOrdenados[i].titulo, titulosOrdenados[i].preco);
    }
}

// tipoOrdenacao: 1 = Crescente (Menor para Maior), 0 = Decrescente (Maior para Menor)
void ordenaPreco(int tipoOrdenacao){
    Livro precosOrdenados[5];

    for(int i = 0; i < 5; i++){
        precosOrdenados[i] = listaLivros[i];
    }
    for(int i = 0; i < 5; i++){
        for(int k = i + 1; k < 5; k++){
            if(tipoOrdenacao == 1) {
                if (precosOrdenados[i].preco > precosOrdenados[k].preco) {
                    Livro temp = precosOrdenados[i];
                    precosOrdenados[i] = precosOrdenados[k];
                    precosOrdenados[k] = temp;
                }
            } else {
                if (precosOrdenados[i].preco < precosOrdenados[k].preco) {
                    Livro temp = precosOrdenados[i];
                    precosOrdenados[i] = precosOrdenados[k];
                    precosOrdenados[k] = temp;
                }
            }
        }
    }
    printf("\n=== LIVROS ORDENADOS POR PRECO (%s) ===\n", tipoOrdenacao == 1 ? "Crescente (Menor > Maior)" : "Decrescente (Maior > Menor)");
    for (int i = 0; i < 5; i++) {
        printf("Titulo: %-30s | Preco: R$ %.2f\n", precosOrdenados[i].titulo, precosOrdenados[i].preco);
    }
}

// Recebe os argumentos enviados pela interface Python
int main(int argc, char *argv[]){
    if (argc >= 3) {
        char *criterio = argv[1];
        int tipo = atoi(argv[2]);

        if (strcmp(criterio, "titulo") == 0) {
            ordenaTitulo(tipo);
        } else if (strcmp(criterio, "preco") == 0) {
            ordenaPreco(tipo);
        } else {
            exibeOriginal();
        }
    } else {
        exibeOriginal(); 
    }
    return 0;
}
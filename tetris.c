#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char tipo;
    int id;
} Peca;

#define MAX 5

typedef struct {
   Peca peca[MAX];
   int inicio;
   int final;
   int total;
} FilaDePecas;

void menu(){
    printf(".............. TETRIS STACK ..............\n");
    printf("1 - jogar uma peça.\n");
    printf("2 - inserir uma peça.\n");
    printf("3 - ver o resultado.\n");
    printf("0 - sair\n");
    printf("..........................................\n");
    printf("Escolha uma das opções acima: \n\n");

}

void iniciarFila(FilaDePecas *f){
    f->final = 0;
    f->inicio = 0;
    f->total = 0;
}

void gerarPecas(FilaDePecas *f, Peca p){
    if(f->total == MAX){
        printf("Fila cheia.\n");
    }

    f->peca[f->final] = p;
    // f->peca[f->final].id++;
    f->final = (f->final +1) % MAX;
    f->total++;
}

void removerPecas(FilaDePecas *f, Peca *p){
    if(f->total == 0){
        printf("Fila Vazia.\n"); 
    }

    *p = f->peca[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

void mostrarFila(FilaDePecas *f){
    if (f->total == 0){
        printf("Nenhuma pessoa na fila.\n");
        return;
    }
    printf("Fila completa:\n");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx+1)%MAX){
        printf("[%c | %d]\n", f->peca[idx].tipo, f->peca[idx].id);
    }
}

int main(){
    char pecasPossiveis[] = {'I', 'O', 'T', 'L'};

    FilaDePecas fila;
    iniciarFila(&fila);

    Peca peca[MAX];

    srand(time(NULL)); // fará com que os valores venham realmente aleatórios

    for (int i = 0; i <= MAX; i++){
        int indice = rand() % 4;
        peca[i].tipo = pecasPossiveis[indice];
        peca[i].id = i + 1;
        // printf("Peça %d: %c (ID: %d)\n", i+1, peca[i].tipo, peca[i].id);
    }

    gerarPecas(&fila, peca[1]);
    gerarPecas(&fila, peca[2]);
    gerarPecas(&fila, peca[3]);
    gerarPecas(&fila, peca[4]);
    gerarPecas(&fila, peca[5]); 
    gerarPecas(&fila, peca[6]); // vem vazio; para vir mais resultados, precisa aumentar o MAX ou alterar o for

    mostrarFila(&fila);

    menu();

    return 0;
};

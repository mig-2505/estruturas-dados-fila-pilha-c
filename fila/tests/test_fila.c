#include <stdio.h>

#define MAX 5

typedef struct {
   int dados[MAX];
   int inicio;
   int fim;
   int qtd;
} Fila;

void inicializarFila(Fila *f) {
   f->inicio = 0;
   f->fim = -1;
   f->qtd = 0;
}

void enqueue(Fila *f, int valor) {
   if (f->qtd == MAX) {
       printf("Fila cheia! Não foi possível adicionar o paciente %d.\n", valor);
       return;
   }
   f->fim = (f->fim + 1) % MAX;
   f->dados[f->fim] = valor;
   f->qtd++;
}

int dequeue(Fila *f) {
   if (f->qtd == 0) {
       printf("Fila vazia! Nenhum paciente para atender.\n");
       return -1;
   }
   int valor = f->dados[f->inicio];
   f->inicio = (f->inicio + 1) % MAX;
   f->qtd--;
   return valor;
}

void mostrarFila(Fila *f) {
   printf("Fila: ");
   for (int i = 0; i < f->qtd; i++) {
       int idx = (f->inicio + i) % MAX;
       printf("%d ", f->dados[idx]);
   }
   printf("\n");
}

int filaVazia(Fila *f) {
   return (f->qtd == 0);
}

int main() {
   Fila f;
   inicializarFila(&f);

   printf("=== Simulação de Fila de Pacientes ===\n");

   // Pacientes chegando
   enqueue(&f, 101);
   enqueue(&f, 102);
   enqueue(&f, 103);

   printf("Fila após chegada dos pacientes:\n");
   mostrarFila(&f);

   // Atendendo pacientes
   int atendido = dequeue(&f);
   if (atendido != -1)
       printf("\nPaciente %d foi atendido.\n", atendido);

   printf("Fila atualizada:\n");
   mostrarFila(&f);

   // Mais pacientes chegando
   enqueue(&f, 104);
   enqueue(&f, 105);

   printf("\nFila após novos pacientes:\n");
   mostrarFila(&f);

   // Atender até esvaziar
   while (!filaVazia(&f)) {
       atendido = dequeue(&f);
       if (atendido != -1)
           printf("Atendendo paciente %d...\n", atendido);
   }
   
   printf("\nTodos os pacientes foram atendidos. Fila vazia.\n");
   return 0;
}
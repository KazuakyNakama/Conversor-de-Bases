/* conversorbase.c
 * Implementação das operações realizadas sobre os TAD's listas e pilha representados de forma encadeada */

#include "conversorbase.h"
#include <stdio.h>
#include <stdlib.h>


                        //Operações da lista (Bases escolhidas pelo Usuário).
void lst_init(lst_ptr * l)
{
    *l = NULL;
}

void lst_inserir(lst_ptr * l, lst_info x)
{
    if (x < 2 || x > 27 ) {
        return;
    }
    lst_ptr p = *l;
    while (p != NULL){
        if (x == p->dado) {
            return;
        }
        p = p->prox;
    }
    lst_ptr n;
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
        fprintf(stderr, "Lista ordenada cheia!\n");
        exit(1);
    }
    n->dado = x;
    if (*l == NULL || x < (*l)->dado) { // 1º e 2º casos
        n->prox = *l;
        *l = n;
    }
    else { // 3º e 4º casos
        p = *l;
        while (p->prox != NULL && p->prox->dado < x) {
            p = p->prox;
        }
        n->prox = p->prox;
        p->prox = n;
    }
}

void lst_imprimir(lst_ptr l)
{
    printf("[ ");
    while (l != NULL) {
        printf("%d,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}


                        //Operações da lista novaLista (Números Decimais).
void novaLista_init(novaLista_ptr * l)
{
    *l = NULL;
}

void novaLista_inserir(novaLista_ptr * l, novaLista_info x)
{
    if (x < 1 || x > 1000) {
        return;
    }
    novaLista_ptr p = *l;
    while (p != NULL){
        if (x == p->dado) {
            return;
        }
        p = p->prox;
    }
    novaLista_ptr n;
    if ((n = (novaLista_ptr) malloc(sizeof(struct novaLista_no))) == NULL) {
        fprintf(stderr, "Lista ordenada cheia!\n");
        exit(1);
    }
    n->dado = x;
    if (*l == NULL || x < (*l)->dado) { // 1º e 2º casos
        n->prox = *l;
        *l = n;
    }
    else { // 3º e 4º casos
        p = *l;
        while (p->prox != NULL && p->prox->dado < x) {
            p = p->prox;
        }
        n->prox = p->prox;
        p->prox = n;
    }
    listaString_ptr ls;
    (*l)->pntStrg = ls;
}

void novaLista_imprimir(novaLista_ptr l)
{
    printf("[ ");
    while (l != NULL) {
        printf("%d,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}


                        //Operações da lista listaString (Resultado das Bases).
void listaString_init(listaString_ptr * l)
{
    *l = NULL;
}

void listaString_inserir(listaString_ptr * l, listaString_info x)
{
    listaString_ptr n;
    if ((n = (listaString_ptr) malloc(sizeof(struct listaString_no))) == NULL) {
        fprintf(stderr, "Lista ordenada cheia!\n");
        exit(1);
    }
    strcpy(n->dado, x);
    if (*l == NULL) {
        n->prox = *l;
        *l = n;
        return;
    }
    listaString_ptr p = *l;
    while (p->prox != NULL){
        p = p->prox;
    }
    n->prox = p->prox;
    p->prox = n;
}

void listaString_imprimir(listaString_ptr l)
{
    printf("[ ");
    while (l != NULL) {
        printf("%s,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}


                        //Operações da Pilha (para a Conversão).
void stack_init(stack_ptr * topo)
{
    *topo = NULL;
}

bool stack_isempty(stack_ptr topo)
{
    return (topo == NULL);
}

void push(stack_ptr * topo, stack_info x)
{
    stack_ptr n;
    if ((n = (stack_ptr) malloc(sizeof(struct stack_no))) == NULL) {
        fprintf(stderr, "Pilha cheia!\n");
        exit(1);
    }
    n->dado = x;
    n->prox = *topo;
    *topo = n;
}

stack_info pop(stack_ptr * topo)
{
    if (!stack_isempty(*topo)) {
        stack_info x = (*topo)->dado;
        stack_ptr n = *topo;
        *topo = (*topo)->prox;
        free(n);
        return x;
    }
    else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

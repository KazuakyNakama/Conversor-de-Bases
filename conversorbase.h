/* conversorbase.h
 * Definição dos TAD's listas e pilha representados de forma encadeada e protótipos
 * de suas operações */

#ifndef _CONVERSORBASE_H
#define _CONVERSORBASE_H

#include <stdbool.h>
#include <strings.h>

//Lista B (Bases escolhidas pelo Usuário).
typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

//Lista de Strings, Nó da lista D (Contém os resultados das Bases).
typedef char listaString_info[11];
typedef struct listaString_no * listaString_ptr;
struct listaString_no {
    listaString_info dado;
    listaString_ptr prox;
};

//Lista D (Números Decimais).
typedef int novaLista_info;
typedef struct novaLista_no * novaLista_ptr;
struct novaLista_no {
    novaLista_info dado;
    novaLista_ptr prox;
    listaString_ptr pntStrg;
};

//Pilha (Utilizada na conversão de Bases).
typedef int stack_info;
typedef struct stack_no * stack_ptr;
struct stack_no {
    stack_info dado;
    stack_ptr prox;
};


                        //Protótipos de operações da lista B (Bases).

/* inicializa a lista */
void lst_init(lst_ptr *);

/* insere um novo nó na lista ordenada */
void lst_inserir(lst_ptr *, lst_info);

/* imprime a lista */
void lst_imprimir(lst_ptr);


                        //Protótipos de operações da lista novaLista (Base Decimal).

/* inicializa a lista */
void novaLista_init(novaLista_ptr *);

/* insere um novo nó na lista ordenada */
void novaLista_inserir(novaLista_ptr *, novaLista_info);

/* imprime a lista */
void novaLista_imprimir(novaLista_ptr);


                        //Protótipos de operações da lista listaString (Resultados das Bases).

/* inicializa a lista */
void listaString_init(listaString_ptr *);

/* insere um novo nó na lista ordenada */
void listaString_inserir(listaString_ptr *, listaString_info);

/* imprime a lista */
void listaString_imprimir(listaString_ptr);


                        //Protótipos de operações da Pilha (para a Conversão).

/* inicializa a pilha */
void stack_init(stack_ptr *);

/* verifica se a pilha está vazia */
bool stack_isempty(stack_ptr);

/* insere um novo elemento no topo da pilha */
void push(stack_ptr *, stack_info);

/* remove o elemento do topo da pilha */
stack_info pop(stack_ptr *);

#endif // _CONVERSORBASE_H

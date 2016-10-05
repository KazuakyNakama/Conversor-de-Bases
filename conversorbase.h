/* conversorbase.h
 * Defini��o dos TAD's listas e pilha representados de forma encadeada e prot�tipos
 * de suas opera��es */

#ifndef _CONVERSORBASE_H
#define _CONVERSORBASE_H

#include <stdbool.h>
#include <strings.h>

//Lista B (Bases escolhidas pelo Usu�rio).
typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

//Lista de Strings, N� da lista D (Cont�m os resultados das Bases).
typedef char listaString_info[11];
typedef struct listaString_no * listaString_ptr;
struct listaString_no {
    listaString_info dado;
    listaString_ptr prox;
};

//Lista D (N�meros Decimais).
typedef int novaLista_info;
typedef struct novaLista_no * novaLista_ptr;
struct novaLista_no {
    novaLista_info dado;
    novaLista_ptr prox;
    listaString_ptr pntStrg;
};

//Pilha (Utilizada na convers�o de Bases).
typedef int stack_info;
typedef struct stack_no * stack_ptr;
struct stack_no {
    stack_info dado;
    stack_ptr prox;
};


                        //Prot�tipos de opera��es da lista B (Bases).

/* inicializa a lista */
void lst_init(lst_ptr *);

/* insere um novo n� na lista ordenada */
void lst_inserir(lst_ptr *, lst_info);

/* imprime a lista */
void lst_imprimir(lst_ptr);


                        //Prot�tipos de opera��es da lista novaLista (Base Decimal).

/* inicializa a lista */
void novaLista_init(novaLista_ptr *);

/* insere um novo n� na lista ordenada */
void novaLista_inserir(novaLista_ptr *, novaLista_info);

/* imprime a lista */
void novaLista_imprimir(novaLista_ptr);


                        //Prot�tipos de opera��es da lista listaString (Resultados das Bases).

/* inicializa a lista */
void listaString_init(listaString_ptr *);

/* insere um novo n� na lista ordenada */
void listaString_inserir(listaString_ptr *, listaString_info);

/* imprime a lista */
void listaString_imprimir(listaString_ptr);


                        //Prot�tipos de opera��es da Pilha (para a Convers�o).

/* inicializa a pilha */
void stack_init(stack_ptr *);

/* verifica se a pilha est� vazia */
bool stack_isempty(stack_ptr);

/* insere um novo elemento no topo da pilha */
void push(stack_ptr *, stack_info);

/* remove o elemento do topo da pilha */
stack_info pop(stack_ptr *);

#endif // _CONVERSORBASE_H

/* Conversor de Bases
 *
 * para converter cada elemento de uma lista de números na base decimal entre 1 a 1000 para uma lista de números
 * expressados em um sistema de numeração cuja base é um valor entre 2 e 27.
 *
 * Luiz Fernando Kazuaky Nakama (Ciências da Computação)
 * Caio Cesar Lopes Teles de Menezes (Ciências da Computação)
 * Victor Almeida Chagas (Ciências da Computação)
 *
 * Disciplina: Estrutura de Dados I
 *
 * Última Modificação: 09/05/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "conversorbase.h"

//Declarações das Funções que serão utilizadas no Programa principal (Main).
void dados(novaLista_ptr *, lst_ptr *);
void conversao(novaLista_ptr, lst_ptr);
void converte(int, int, char *);
void instrucoes();
void staff();


int main()
{
    lst_ptr b;
    novaLista_ptr d;
    int ibirapuera = 13, op;

    do{
        system("cls");
        printf("\n|==========================================|\n");
        printf("|            CONVERSOR DE BASES\t\t   |");
        printf("\n|==========================================|\n");
        printf("|<1> - Leitura de Dados\t\t\t   |\n");
        printf("|<2> - Realizar Conversao\t\t   |\n");
        printf("|<3> - Instrucoes\t\t\t   |\n");
        printf("|<4> - Staff\t\t\t\t   |\n");
        printf("|<0> - Sair do Programa\t\t\t   |\n");
        printf("|==========================================|\n");
        printf("|Selecione uma opcao -> ");
        scanf("%d", &op);
        if((ibirapuera == 13) && (op == 1 || op == 2)){
            op = 1;
            ibirapuera = 37;
        }
        switch(op){
        case 1: dados(&d, &b);
            break;
        case 2: conversao(d, b);
            break;
        case 3: instrucoes();
            break;
        case 4: staff();
            break;
        case 0:
            break;
        default: fprintf(stderr, "Opcao invalida...  |\n|Pressione qualquer tecla para continuar...|\n");

        }
    } while(op != 0);
    return 0;
}

/* Função void "dados" será responsável pela leitura dos dados escolhidos pelo o usuário,
 * como os números na base Decimal e a Base para a conversão desejada, a função recebe 3 parâmetros
 * por referência, um ponteiro para lista dinâmica tipo int "novaLista d" de Números decimais, um ponteiro para a lista dinâmica
 * tipo int "lst b" que contém as Bases desejadas e um ponteiro para a lista dinâmica tipo char "listaString ls" que
 * contém os resultados das conversões, a Função não retorna nenhum parâmetro, sendo todos os parâmetros referências para ponteiros.*/
void dados(novaLista_ptr * d, lst_ptr * b)
{
    int op, x, i = 0;
    system("cls");

    lst_init(b);
    novaLista_init(d);

    printf("\n|=====================================================|\n");
    printf("|\t\t    LEITURA DE DADOS\t\t      |");
    printf("\n|=====================================================|\n\n");

    printf("Informe os numeros na Base Decimal - (0 para sair):\n\n");
    do{
        i++;
        printf("\n%do Elemento: ", i);
        scanf("%d", &x);
        novaLista_inserir(d, x);
    } while(x != 0);
    printf("\nLista de Decimais -> ");
    novaLista_imprimir(*d);

    i = 0;
    printf("\n\nInforme as bases a serem convertidas - (0 para sair):\n\n");
    do{
        i++;
        printf("\n%do Elemento: ", i);
        scanf("%d", &x);
        lst_inserir(b, x);
    } while(x != 0);
    printf("\nLista de Bases -> ");
    lst_imprimir(*b);

    novaLista_ptr dec = *d;
    lst_ptr base = *b;

    char string[11];

    while(dec != NULL){
        while(base != NULL){
            converte(dec->dado, base->dado, string);
            listaString_inserir(&dec->pntStrg, string);
            base = base->prox;
        }
        base = *b;
        listaString_imprimir(dec->pntStrg);
        dec = dec->prox;
    }

    printf("\n\nPressione 0 para retornar ao menu -> ");
    while(op != 0) scanf("%d", &op);
}

/* Função void "conversao" será responsável pela alocação da lista dinâmica tipo char"listaString ls" que irá
 * conter os resultados das conversões dos números decimais para as bases escolhidas pelo o usuário e a impressão da tabela de
 * conversões,a função recebe 3 parâmetros, por valor um ponteiro para lista dinâmica tipo int "novaLista d" de Números
 * decimais e um ponteiro para a lista dinâmica tipo int "lst b" que contém as Bases desejadas, por referência um ponteiro
 * para a lista dinâmica tipo char "listaString ls", a Função não retorna nenhum parâmetro, sendo ls referência para um ponteiro.*/
void conversao(novaLista_ptr d, lst_ptr b)
{
    int op;
    novaLista_ptr decimal = d;
    lst_ptr base = b;
    system("cls");

    printf("\n|=====================================================|\n");
    printf("|\t\t       CONVERSAO\t\t      |");
    printf("\n|=====================================================|\n\n");

    printf("Base 10 ");
    while(base != NULL){
        if(base->dado == 2){
            printf("|    Base %d    ", base->dado);
        }
        else{
            printf("| Base %d ", base->dado);
        }
        base = base->prox;
    }
    printf("\n--------");
    base = b;
    while(base != NULL){
        if(base->dado == 2){
            printf("---------------");
        }
        else{
            if(base->dado > 10){
                printf("----------");
            }
            else{
                printf("---------");
            }
        }
        base = base->prox;
    }
    printf("\n");

    while(decimal != NULL){
        printf("%7d ", decimal->dado);
        while(decimal->pntStrg != NULL){
            if(base->dado == 2){
                printf("|%12s  ", decimal->pntStrg->dado);
            }
            else{
                if(base->dado > 10){
                    printf("|%8s ", decimal->pntStrg->dado);
                }
                else{
                    printf("|%7s ", decimal->pntStrg->dado);
                }
            }
            decimal->pntStrg = decimal->pntStrg->prox;
        }
        decimal = decimal->prox;
        printf("\n");
    }

    printf("\n\nPressione 0 para retornar ao menu -> ");
    while(op != 0) scanf("%d", &op);
}

/* Função void "converte" será responsável pela conversão dos Números na base decimal para as bases desejadas pelo usuário,
 * a função recebe 3 parâmetros, por valor um número tipo int na base decimal, por valor um número tipo int que contém a
 * Base desejada, por referência um ponteiro para a lista dinâmica tipo char "listaString result" que irá conter os resultados
 * das conversões, a Função não retorna nenhum parâmetro, sendo result referência para um ponteiro.*/
void converte(int dec, int base, char * result)
{
    stack_ptr p;
    stack_init(&p);
    int i, cont = 0;
    char x;
    while(dec != 0){
        push(&p, dec % base);
        dec /= base;
        cont++;
    }
    for(i = 0; i < cont; i++){
        if((x = pop(&p)) < 10){
            result[i] = x + 48;
        }
        else{
            result[i] = x + 55;
        }
    }
    result[i] = '\0';
}

/* Função void "instrucoes" irá printar na tela instruções para se utilizar o programa corretamente,
 * nao recebe e não retorna nenhum parâmetro.*/
void instrucoes()
{
    system("cls");
    printf("\n|=====================================================|\n");
    printf("|\t\t       INSTRUCOES\t\t      |");
    printf("\n|=====================================================|\n\n");
    printf("Antes de realizar a conversao, o usuario devera entrar\n");
    printf("com os dados do problema. Portanto, mesmo que o usuario\n");
    printf("entre primeiramente com a segunda opcao para converter,\n");
    printf("FORCAREMOS A LEITURA DE DADOS.\n\n");
    printf("Numeros decimais acima de 1000 e menores que 1 nao serao\n");
    printf("aceitos para conversao. Bases acima de 27 e menores que 2\n");
    printf("tambem nao serao aceitas.\n");
    printf("\nO resto do programa e simples e intuitivo...\n");

    int op;
    printf("\n\nPressione 0 para retornar ao menu -> ");
    while(op != 0) scanf("%d", &op);
}

/* Função void "staff" irá printar na tela os integrantes do grupo responsável pelo trabalho,
 * nao recebe e não retorna nenhum parâmetro.*/
void staff()
{
    system("cls");
    printf("\n|=====================================================|\n");
    printf("|\t\t\t STAFF\t\t\t      |");
    printf("\n|=====================================================|\n\n");
    printf("Luiz Fernando Kazuaky Nakama\n\n");
    printf("Caio Cesar Lopes Teles de Menezes\n\n");
    printf("Victor Almeida Chagas\n");

    int op;
    printf("\n\nPressione 0 para retornar ao menu -> ");
    while(op != 0) scanf("%d", &op);
}

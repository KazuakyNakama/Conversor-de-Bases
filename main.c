/* Conversor de Bases
 *
 * para converter cada elemento de uma lista de n�meros na base decimal entre 1 a 1000 para uma lista de n�meros
 * expressados em um sistema de numera��o cuja base � um valor entre 2 e 27.
 *
 * Luiz Fernando Kazuaky Nakama (Ci�ncias da Computa��o)
 * Caio Cesar Lopes Teles de Menezes (Ci�ncias da Computa��o)
 * Victor Almeida Chagas (Ci�ncias da Computa��o)
 *
 * Disciplina: Estrutura de Dados I
 *
 * �ltima Modifica��o: 09/05/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include "conversorbase.h"

//Declara��es das Fun��es que ser�o utilizadas no Programa principal (Main).
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

/* Fun��o void "dados" ser� respons�vel pela leitura dos dados escolhidos pelo o usu�rio,
 * como os n�meros na base Decimal e a Base para a convers�o desejada, a fun��o recebe 3 par�metros
 * por refer�ncia, um ponteiro para lista din�mica tipo int "novaLista d" de N�meros decimais, um ponteiro para a lista din�mica
 * tipo int "lst b" que cont�m as Bases desejadas e um ponteiro para a lista din�mica tipo char "listaString ls" que
 * cont�m os resultados das convers�es, a Fun��o n�o retorna nenhum par�metro, sendo todos os par�metros refer�ncias para ponteiros.*/
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

/* Fun��o void "conversao" ser� respons�vel pela aloca��o da lista din�mica tipo char"listaString ls" que ir�
 * conter os resultados das convers�es dos n�meros decimais para as bases escolhidas pelo o usu�rio e a impress�o da tabela de
 * convers�es,a fun��o recebe 3 par�metros, por valor um ponteiro para lista din�mica tipo int "novaLista d" de N�meros
 * decimais e um ponteiro para a lista din�mica tipo int "lst b" que cont�m as Bases desejadas, por refer�ncia um ponteiro
 * para a lista din�mica tipo char "listaString ls", a Fun��o n�o retorna nenhum par�metro, sendo ls refer�ncia para um ponteiro.*/
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

/* Fun��o void "converte" ser� respons�vel pela convers�o dos N�meros na base decimal para as bases desejadas pelo usu�rio,
 * a fun��o recebe 3 par�metros, por valor um n�mero tipo int na base decimal, por valor um n�mero tipo int que cont�m a
 * Base desejada, por refer�ncia um ponteiro para a lista din�mica tipo char "listaString result" que ir� conter os resultados
 * das convers�es, a Fun��o n�o retorna nenhum par�metro, sendo result refer�ncia para um ponteiro.*/
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

/* Fun��o void "instrucoes" ir� printar na tela instru��es para se utilizar o programa corretamente,
 * nao recebe e n�o retorna nenhum par�metro.*/
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

/* Fun��o void "staff" ir� printar na tela os integrantes do grupo respons�vel pelo trabalho,
 * nao recebe e n�o retorna nenhum par�metro.*/
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

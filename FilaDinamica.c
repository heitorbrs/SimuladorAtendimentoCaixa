/***********************************************************************/
/*                            BIBLIOTECAS                              */
/***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***********************************************************************/
/*                            ESTRUTURAS                               */
/***********************************************************************/

typedef struct sCell{

    char nome[50];
    int codigo;
    struct sCell *next;

}CELULA;

/***********************************************************************/

typedef struct fila{

    CELULA *inicio;
    CELULA *fim;

}FILA;

/***********************************************************************/
/*                            FILA NORMAL                              */
/***********************************************************************/

//inicializa a fila normal
void inicializar (FILA* f){
    f->inicio = NULL;
    f->fim = NULL;
}

/***********************************************************************/

//verifica se a fila normal está vazia
int filaVazia(FILA *f){
    if(f->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

/***********************************************************************/

//função para criar uma nova célula
CELULA* criar(){
    return (CELULA*) malloc (sizeof(CELULA));
}

/***********************************************************************/

//senha da fila normal
int i = 1;

//adiciona um novo elemento na fila normal
int enfileirar(FILA *f){

    CELULA *nova = criar();

    printf("\n  Nome: ");
    scanf("%s", nova->nome);

    nova->codigo = i;

    printf("\n  Sua senha: 000%d \n", nova->codigo);

    i = i + 1;

    nova->next = NULL;

    if(filaVazia(f)){
        f->inicio = nova;
        f->fim = nova;
        return 1;
    }
    f->fim->next = nova;
    f->fim = nova;
    return 1;
}

/***********************************************************************/

//remove o primeiro elemento da fila normal
int desenfileirar(FILA *f){

    int codigoRemovido = -1;
    char nomeRemovido[50] = {};

    CELULA *endRemovida;

    if(filaVazia(f)){
        return codigoRemovido;
    }
    endRemovida = f->inicio;
    nomeRemovido[50] = f->inicio->nome[50];
    codigoRemovido = f->inicio->codigo;
    f->inicio = f->inicio->next;

    free(endRemovida);
    return codigoRemovido;
}

/***********************************************************************/

void imprimeInicio(FILA *f){

    if(filaVazia(f)){
        printf("\n  Fila Vazia!\n");

    }else{
        printf("\n  Cliente: %s | Senha: 000%d \n", f->inicio->nome, f->inicio->codigo);
    }
}

/***********************************************************************/

//imprime todos os elementos da fila normal
void ImprimeFila(FILA *f){

    CELULA *aux;

	if(f->inicio == NULL){
		printf("\n  Fila Vazia!\n");
	}
	else{
		aux = f->inicio;

		do{
			printf("\n  Senha: 000%d  |  Cliente: %s", aux->codigo, aux->nome);
			aux = aux->next;
		} while(aux != NULL);

		printf("\n");
	}
}

/***********************************************************************/
/*                         FILA PRIORITÁRIA                            */
/***********************************************************************/

//inicializa a fila normal
void inicializar2(FILA* f2){
    f2->inicio = NULL;
    f2->fim = NULL;
}

/***********************************************************************/

//verifica se a fila prioritária está vazia
int filaVazia2(FILA *f2){
    if(f2->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

/***********************************************************************/

//senha da fila prioritária
int j = 1;

//adiciona um novo elemento na fila prioritária
int enfileirar2(FILA *f2) {

    CELULA *nova = criar();

    printf("\n  Nome: ");
    scanf("%s", nova->nome);

    nova->codigo = j;

    printf("\n  Sua senha: 100%d \n", j);

    j = j + 1;

    nova->next = NULL;

    if(filaVazia(f2)){
        f2->inicio = nova;
        f2->fim = nova;
        return 1;
    }
    f2->fim->next = nova;
    f2->fim = nova;
    return 1;
}

/***********************************************************************/


//remove o primeiro elemento da fila prioritária
int desenfileirar2(FILA *f2){

    int codigoRemovido = -1;
    char nomeRemovido[50] = {};

    CELULA *endRemovida;

    if(filaVazia(f2)){
        return codigoRemovido;
    }
    endRemovida = f2->inicio;
    nomeRemovido[50] = f2->inicio->nome[50];
    codigoRemovido = f2->inicio->codigo;
    f2->inicio = f2->inicio->next;

    free(endRemovida);
    return codigoRemovido;
}

/***********************************************************************/

void imprimeInicio2(FILA *f2){

    if(filaVazia(f2)){
        printf("\n  Fila Vazia!\n");

    }else{
        printf("\n  Cliente: %s | Senha: 100%d \n", f2->inicio->nome, f2->inicio->codigo);
    }
}

/***********************************************************************/

//imprime todos os elementos da fila prioritária
void ImprimeFila2(FILA *f2){

    CELULA *aux;

	if(f2->inicio == NULL){
		printf("\n  Fila Vazia!\n");
	}
	else{
		aux = f2->inicio;

		do{
			printf("\n  Senha: 100%d  |  Cliente: %s", aux->codigo, aux->nome);
			aux = aux->next;
		} while(aux != NULL);

		printf("\n");
	}
}

/***********************************************************************/
/*                        MENUS DO PROGRAMA                            */
/***********************************************************************/

void menu_principal() {

    system("cls");
    printf("+-----------------------------------------------------------+\n");
    printf("|    ATENDIMENTO DE PESSOAS DA FILA                         |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("| 1. Entrar na fila normal                                  |\n");
    printf("| 2. Entrar na fila prioritaria                             |\n");
    printf("| 3. Atender cliente                                        |\n");
    printf("| 4. Imprimir todos os clientes na fila                     |\n");
    printf("| 5. Imprimir clientes sendo atendidos atualmente           |\n");
    printf("| 6. Imprimir numero de clientes atendidos por cada caixa   |\n");
    printf("| 0. Sair do programa                                       |\n");
    printf("+-----------------------------------------------------------+\n");
    printf("\n  Escolha uma opcao:\n");
    printf("\n  >>> ");

}

/***********************************************************************/

//Imprimir todos os clientes na fila
void menu_opcao4() {

    printf("\n  De qual fila voce deseja imprimir?\n");
    printf("\n  (1) Fila Normal");
    printf("\n  (2) Fila Prioritaria");
    printf("\n  (0) Voltar\n");
    printf("\n  >>> ");

}

/***********************************************************************/

//Imprimir clientes sendo atendidos atualmente
void menu_opcao5() {

    printf("\n  De qual caixa voce deseja imprimir?\n");
    printf("\n  (1) Caixa 1");
    printf("\n  (2) Caixa 2");
    printf("\n  (0) Voltar\n");
    printf("\n  >>> ");

}

/***********************************************************************/

//Imprimir numero de clientes atendidos por cada caixa
void menu_opcao6() {

    printf("\n  De qual caixa voce deseja imprimir?\n");
    printf("\n  (1) Caixa 1");
    printf("\n  (2) Caixa 2");
    printf("\n  (0) Voltar\n");
    printf("\n  >>> ");

}

/***********************************************************************/
/*                         FUNÇÃO PRINCIPAL                            */
/***********************************************************************/

int main(){

    int opcao, op_aux, cont_1=0, cont_2=0;

    char nomeTemp1[50], nomeTemp2[50];
    int codigoTemp1=0, codigoTemp2=0;

    char caixa1, caixa2;

    FILA fi;
    FILA fi2;

    inicializar(&fi);
    inicializar2(&fi2);

/***********************************************************************/

     for(;;) {

        menu_principal();
        scanf("%d", &opcao);

/***********************************************************************/

        //Entrar na fila normal
        if(opcao==1) {
            enfileirar(&fi);
        }

/***********************************************************************/

        //Entrar na fila prioritária
        else if(opcao==2) {
            enfileirar2(&fi2);
        }

/***********************************************************************/

        //Atender cliente
        else if(opcao==3) {

            if(filaVazia(&fi) == 1 && filaVazia2(&fi2) == 1) {
                printf("\n  Fila Normal e Prioritaria vazias!\n");
            }

            else if(fi2.inicio == NULL) {

                printf("\n  - CAIXA 1: (fila normal)\n");

                strcpy(nomeTemp1, fi.inicio->nome);
                codigoTemp1 = fi.inicio->codigo;

                desenfileirar(&fi);
                cont_1++;

                caixa1 = 'n';

                printf("\n  Cliente atendido: %s | Senha: 000%d \n", nomeTemp1, codigoTemp1);

                if(fi.inicio != NULL){
                    printf("\n  - CAIXA 2: (fila normal)\n");

                    strcpy(nomeTemp2, fi.inicio->nome);
                    codigoTemp2 = fi.inicio->codigo;

                    desenfileirar(&fi);
                    cont_2++;

                    caixa2 = 'n';

                    printf("\n  Cliente atendido: %s | Senha: 000%d \n", nomeTemp2, codigoTemp2);

                }

                else if(fi.inicio == NULL) {
                    printf("\n  - CAIXA 2:\n");
                    printf("\n  Fila Vazia!\n");
                }
            }

            else {

                printf("\n  - CAIXA 1: (fila prioritaria)\n");

                strcpy(nomeTemp1, fi2.inicio->nome);
                codigoTemp1 = fi2.inicio->codigo;

                desenfileirar2(&fi2);
                cont_1++;

                caixa1 = 'p';

                printf("\n  Cliente atendido: %s | Senha: 100%d \n", nomeTemp1, codigoTemp1);

                if(fi2.inicio != NULL){
                    printf("\n  - CAIXA 2: (fila prioritaria)\n");

                    strcpy(nomeTemp2, fi2.inicio->nome);
                    codigoTemp2 = fi2.inicio->codigo;

                    desenfileirar2(&fi2);
                    cont_2++;

                    caixa2 = 'p';

                    printf("\n  Cliente atendido: %s | Senha: 100%d \n", nomeTemp2, codigoTemp2);
                }

                else if(fi2.inicio == NULL && fi.inicio != NULL){
                    printf("\n  - CAIXA 2: (fila normal)\n");

                    strcpy(nomeTemp2, fi.inicio->nome);
                    codigoTemp2 = fi.inicio->codigo;

                    desenfileirar(&fi);
                    cont_2++;

                    caixa2 = 'n';

                    printf("\n  Cliente atendido: %s | Senha: 000%d \n", nomeTemp2, codigoTemp2);
                }

                else {
                    printf("\n  - CAIXA 2: \n");
                    printf("\n  Vazio!\n");
                }
            }
        }

/***********************************************************************/

        //Imprimir todos os clientes na fila
        else if(opcao==4) {

            menu_opcao4();
            scanf("%d", &op_aux);

            if(op_aux == 1) {
                ImprimeFila(&fi);
            }
            else if(op_aux == 2) {
                ImprimeFila2(&fi2);
            }
            else if(op_aux == 0) {
                continue;
            }
            else {
                printf("\n  Digite uma opcao valida!\n");
            }
        }

/***********************************************************************/

        //Imprimir clientes sendo atendidos atualmente
        else if(opcao==5) {

            menu_opcao5();
            scanf("%d", &op_aux);

            if(op_aux == 1) {

                if(codigoTemp1==0) {
                    printf("\n  Nenhum cliente atendido!\n");
                }
                else {

                    if(caixa1=='n'){
                        printf("\n  Sendo atendido: %s | Senha: 000%d \n", nomeTemp1, codigoTemp1);
                    }
                    if(caixa1=='p'){
                        printf("\n  Sendo atendido: %s | Senha: 100%d \n", nomeTemp1, codigoTemp1);
                    }
                }
            }

            else if(op_aux == 2) {

                if(codigoTemp2==0) {
                    printf("\n  Nenhum cliente atendido!\n");
                }
                else {

                    if(caixa2=='n'){
                        printf("\n  Sendo atendido: %s | Senha: 000%d \n", nomeTemp2, codigoTemp2);
                    }
                    if(caixa2=='p'){
                        printf("\n  Sendo atendido: %s | Senha: 100%d \n", nomeTemp2, codigoTemp2);
                    }
                }
            }

            else if(op_aux == 0) {
                continue;
            }
            else {
                printf("\n  Digite uma opcao valida!\n");
            }
        }

/***********************************************************************/

        //Imprimir numero de clientes atendidos por cada caixa
        else if(opcao==6) {

            menu_opcao6();
            scanf("%d", &op_aux);

            if(op_aux == 1) {
                printf("\n  Numero de clientes atendidos: %d\n", cont_1);
            }
            else if(op_aux == 2) {
                printf("\n  Numero de clientes atendidos: %d\n", cont_2);
            }
            else if(op_aux == 0) {
                continue;
            }
            else {
                printf("\n  Digite uma opcao valida!\n");
            }
        }

/***********************************************************************/

        //Sair do programa
        else if(opcao==0) {
            printf("\n  VOLTE SEMPRE!\n");
            break;
        }

/***********************************************************************/

        else {
            printf("\n  Digite uma opcao valida!\n");

        }
        printf("\n");
        system("pause");
     }
    return 0;
}

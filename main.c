#include <stdio.h>
#include "funcoes.c"

int main(){

    printf("----------Sistema de banco----------\n\n");

    int escolha = 0;

    while(1){

        printf("1 - Entrar\n");
        printf("2 - Cadastrar-se\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                entrar();
                break;
            case 2:
                cadastro();
                break;
            case 3:
                printf("\nOperacao finalizada!\n");
                return 0;
            default:
                printf("Opcao invalida.");
                break;
        }
    }
}
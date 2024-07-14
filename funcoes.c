#include "funcoes.h"
info_pessoais *usuarios = NULL;
int numUsuario = 0;
float saldoDisponivel = 0.0;
int cpf;
int senha;

void alocarClientes(){

    usuarios = (info_pessoais *)realloc(usuarios, (numUsuario + 1) * sizeof(info_pessoais));

}

void entrar(){

    printf("\nVerificando usuarios");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    
    if(numUsuario == 0){

        printf("\n\nNao ha usuarios cadastrados\n");
        printf("1 - Cadastrar\n2 - Voltar para o inicio\n\n");
        printf("Escolha uma opcao: ");

        int opcao = 0;
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastro();
                break;
            case 2:
                return;
            default:
                printf("Opcao invalida\n\n");
                break;
        }
        return;
    }

    printf("\n\nInsira seus dados para entrar: \n");

    printf("CPF: ");
    scanf("%d", &cpf);

    printf("Senha: ");
    scanf("%d", &senha);

    for(int i = 0; i < numUsuario; i++){
        if((usuarios[i].CPF == cpf) && (usuarios[i].senha == senha)){
            printf("\nVerificando dados");
            Sleep(1000);

            
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf("\n\nOla %s %s, seja bem vindo(a).\n", usuarios[i].nome, usuarios[i].sobrenome);
            
            opcoesCliente();

            return;
        }
    }
    printf("\nVerificando dados");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".\n");
    printf("Dados incorretos\n");
    printf("1 - Tentar novamente\n2 - cadastrar-se\n3 - Voltar para o inicio\n\n");
    printf("Escolha uma opcao: ");

    int opcao = 0;

    scanf("%d", &opcao);

    switch (opcao){
        case 1:
            entrar();
            break;
        case 2:
            cadastro();
        case 3:
            return;
        default:
            printf("Opcao invalida\n\n");
            break;
    }

}

void cadastro(){

    alocarClientes();
    int cpfTEMP;

    int senhaCadastro = 0;

    printf("\nInsira suas infomacoes \n");
    printf("Primeiro nome: ");
    scanf(" %s", usuarios[numUsuario].nome);

    printf("Sobrenome: ");
    scanf(" %s", usuarios[numUsuario].sobrenome);
    
    printf("Data de nascimento(DD/MM/AAAA): ");
    while(scanf("%d/%d/%d", &usuarios[numUsuario].dia, &usuarios[numUsuario].mes, &usuarios[numUsuario].ano) != 3){
        while(getchar() != '\n'); // Limpar o buffer de entrada
    }
    
    printf("CPF: ");
    scanf(" %d", &cpfTEMP);

    char a;
    char b;

    while(1){
        while(1){
            printf("Crie uma senha(somente numeros): ");
            if(scanf("%d%c", &usuarios[numUsuario].senha, &a) != 2 || a != '\n'){
            printf("Formato de senha invalido\n");
            }
            else{
                break;
            }
        }

        while(1){
            printf("Digite a senha novamente: ");
            if(scanf("%d%c", &senhaCadastro, &b) != 2 || b != '\n'){
                printf("Formato de senha invalido\n");
            }
            else{
                break;
            }
        }

        if(usuarios[numUsuario].senha != senhaCadastro){
            printf("As senhas nao coincidem\n");
            printf("Tente novamente\n\n");
        }
        else{
            break;
        }

    }

    int existe = 0;

    for(int i = 0; i < numUsuario; i++){
        if(usuarios[i].CPF == cpfTEMP) {
            existe++;
        }
    }
    if(existe != 0){
        printf("Usuario ja cadastrado\n\n");
        printf("Voltando para o inicio");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".\n\n");
        Sleep(1000);

        return;
    }

    usuarios[numUsuario].CPF = cpfTEMP;

    numUsuario++;

    printf("Cadastrando");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nUsuario cadastrado!\n\n");

}

void opcoesCliente(){

    int opcao = 0;

    printf("\nQual operacao voce deseja realizar?\n");
    printf("1 - Consultar saldo.\n");
    printf("2 - Realizar saque.\n");
    printf("3 - Realizar deposito.\n");
    printf("4 - Finalizar operacao.\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1: 
            saldo();
            break;
        case 2:
            saque();
            break;
        case 3:
            deposito();
            break;
        case 4: 
            printf("Operacao finalizada\n\n");
            return;
        default:
            printf("Opcao invalida\n\n");
            opcoesCliente();
            break;
    }
}

void saldo(){

    int opcao = 0;

    printf("\nSeu saldo eh: R$ %.2f\n\n", saldoDisponivel);

    if(saldoDisponivel <= 0){
        printf("1 - Realizar deposito\n2 - Voltar para o inicio\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1: 
                deposito();
                break;
            case 2:
                return;
            default:
                printf("Opcao invalida\n\n");
                break;
        }
    }
    else{
        printf("1 - Realizar deposito\n2 - Realizar saque\n3 - Realizar outra operacao\n4 - Voltar para o inicio\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: 
                deposito();
                break;
            case 2:
                saque();
            case 3:
                opcoesCliente();
                break;
            case 4:
                return;
            default:
                printf("Opcao invalida\n\n");
                break;
        }
    }
}

void deposito(){

    float valor = 0.0;

    while(1){
        printf("\nQual o valor voce deseja depositar?\n");
        scanf("%f", &valor);

        if(valor < 1){
            printf("Valor invalido\n");
            printf("Insira um valor valido\n");
        }
        else{
            break;
        }
    }
    printf("Realizando deposito");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nDeposito realizado com sucesso!\n");
    saldoDisponivel += valor;
    printf("\nSeu saldo atual eh: R$ %.2f\n", saldoDisponivel);

    int opcao = 0;

    printf("\n1 - Realizar outra operacao\n2 - Voltar para o inicio\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            opcoesCliente();
            break;
        case 2:
            return;
        default:
            printf("Opcao invalida\n\n");
            break;
    }
}

void saque(){

    float valorSaque = 0.0;

    while(1){
        printf("\nQual o valor voce deseja sacar?\n");
        scanf("%f", &valorSaque);

        if(valorSaque < 1){
            printf("Valor invalido\n");
            printf("Insira um valor valido\n");
        }
        else{
            break;
        }
    }

    if(saldoDisponivel == 0 || valorSaque > saldoDisponivel){

        int opcao = 0;

        printf("\nSaldo insuficiente\n");
        printf("1 - Realizar deposito\n2 - Voltar para o inicio\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                deposito();
                break;
            case 2:
                return;
            default:
                printf("Opcao invalida\n\n");
                break;
        }   
        return;
    }

    saldoDisponivel -= valorSaque;

    printf("Realizando saque");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\nSaque realizado com sucesso!\n");
    printf("Retire seu dinheiro\n\n");

    printf("Seu novo saldo eh: R$ %.2f\n\n", saldoDisponivel);

    int opcao = 0;

    printf("1 - Realizar outra operacao\n2 - Voltar para o inicio\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            opcoesCliente();
            break;
        case 2:
            return;
        default:
            printf("Opcao invalida\n\n");
            break;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TAM 40

struct info_pessoais{
    char nome[TAM];
    char sobrenome[TAM];
    int dia, mes, ano;
    int CPF;
    int senha;
};
typedef struct info_pessoais info_pessoais;

void alocarClientes();
void entrar();
void cadastro();
void opcoesCliente();
void saldo();
void deposito();
void saque();
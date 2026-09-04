#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int matricula;
    char nome[100];
    int data_nascimento;
    int cpf;
    int disciplinas[10];
    char genero;

}Pessoa;

int main(){
    int opcao;
    puts("PROJETO ESCOLA\n\n");

    puts("Escolha uma opção:");

    puts("\t0 - Sair");
    puts("\t1 - Cadastrar");
    puts("\t2 - Alterar");
    puts("\t3 - Excluir");
    puts("\t4 - Listar");
    scanf("%d", &opcao);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int matricula;
    char nome[100];
    int data_nascimento;
    int cpf;
    int disciplinas[10];
    char genero;
    char aluno_ou_professor;

}Pessoa;

int main(){
    int opcao;
    int sair=0;

    while(sair==0){
        puts("PROJETO ESCOLA\n\n");

        puts("Escolha uma opção:");

        puts("\t0 - Sair");
        puts("\t1 - Cadastrar");
        puts("\t2 - Alterar");
        puts("\t3 - Excluir");
        puts("\t4 - Listar");

        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:{
                sair=1;
                break;
            }
            case 1:{
                puts("Cadastrar:\n");
                puts("\t1 - Aluno:\n");
                puts("\t2 - Professor:\n");
                puts("\t2 - Disciplina:\n");
                getchar();
                break;
            }
            case 2:{

                break;
            }
            case 3:{

                break;
            }
            case 4:{
                break;
            }
            default:{
                break;
            }
        }
    }
    return 0;
}

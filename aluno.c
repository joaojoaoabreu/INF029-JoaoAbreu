#include <stdio.h>
#include <string.h>
define limite_alunos = 3;

void menu();

typedef struct{
    int matricula;
    char nome[100];
    int data_nascimento[3];
    int cpf;
    int disciplinas[10];
    char genero;
    char aluno_ou_professor;

}Pessoa;

int main(){
    int opcao;
    int sair=0;
    Pessoa Lista_alunos[limite_alunos];
    int num_aluno=0;

    while(sair==0){
        menu();
        scanf("%d", &opcao);
        getchar();


        switch(opcao){
            case 0:{
                sair=1;
                break;
            }
            case 1:{
                puts("Cadastrar Aluno:\n");
                puts("Digite o Nome:\n");
                fgets(Lista_alunos[num_aluno].nome, 100, stdin);
                getchar();
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

void menu(){
    puts("PROJETO ESCOLA\n\n");

    puts("Escolha uma opção:");

    puts("\t0 - Sair");
    puts("\t1 - Cadastrar Aluno");
    puts("\t2 - Alterar Aluno");
    puts("\t3 - Excluir Aluno");
    puts("\t4 - Listar Alunos");
}

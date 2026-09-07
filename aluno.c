#include <stdio.h>
#include <string.h>
#define limite_alunos 3

void menu();
void recebe_string(char *string, int tam);
void recebe_data(int *dia, int *mes, int *ano);

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
                recebe_string(Lista_alunos[num_aluno].nome, 100);
                recebe_data(&Lista_alunos[num_aluno].data_nascimento[0], &Lista_alunos[num_aluno].data_nascimento[1], &Lista_alunos[num_aluno].data_nascimento[2]);
                puts("Digite o CPF:\n");
                scanf("%d",&Lista_alunos[num_aluno].cpf);
                do{
					puts("Digite o gênero (M - Masculino | F - Feminino):");
					scanf("%c", &Lista_alunos[num_aluno].genero);
					getchar();

					if(Lista_alunos[num_aluno].genero == 'm' || Lista_alunos[num_aluno].genero == 'f')
						Lista_alunos[num_aluno].genero -= 32;

				} while(Lista_alunos[num_aluno].genero != 'M' && Lista_alunos[num_aluno].genero != 'F');
                scanf("%c",&Lista_alunos[num_aluno].genero);
                Lista_alunos[num_aluno].aluno_ou_professor = 'A';
                Lista_alunos[num_aluno].matricula = num_aluno + 1;
                num_aluno ++;
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
void recebe_data(int *dia, int *mes, int *ano){
    puts("Digite o dia, mês e ano de nascimento em números:\n");
    do{
        do{
            puts("Dia (formato DD):\n");
            scanf("%d",dia);
            getchar();
            if(*dia>31 || *dia<1) puts("Dia é um número entre 1 e 31\n");
        } while(*dia>31 || *dia<1);
        do{
            puts("Mês (Formato MM):\n");
            scanf("%d",mes);
            getchar();
            if(*mes>12) puts("Dia é um número entre 1 e 12\n");
        } while(*mes>12 || *mes<1);
        if((*dia>29 && *mes ==2)||(*dia>30 && *mes ==4)||(*dia>30 && *mes ==6)||(*dia>30 && *mes ==9)||(*dia>30 && *mes ==11)) puts("Data Inválida.\n");
    }while((*dia>29 && *mes ==2)||(*dia>30 && *mes ==4)||(*dia>30 && *mes ==6)||(*dia>30 && *mes ==9)||(*dia>30 && *mes ==11));
    puts("Ano (Formato AAAA):\n");
    do{
        puts("Ano (formato AAAA):\n");
        scanf("%d",ano);
        getchar();
        if(*ano>2026) puts("Você não nasceu no futuro.\n");
    } while(*ano>2026);
}
void recebe_string(char *string, int tamanho){
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
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

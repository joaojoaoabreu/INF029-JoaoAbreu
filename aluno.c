#include <stdio.h>
#include <string.h>
#define limite_alunos 3
#define CADASTRO_SUCESSO -1
#define CADASTRO_ERRO -2
#define DELETADO_SUCESSO -3
#define DELETADO_ERRO -4

typedef struct{
    int matricula;
    char nome[100];
    int data_nascimento[3];
    long long cpf;
    int disciplinas[10];
    char genero;
    char aluno_ou_professor;

}Pessoa;

void menu();
void recebe_string(char *string, int tam);
void recebe_data(int *dia, int *mes, int *ano);
void Listar(Pessoa Lista_alunos[], int num_aluno);
int Cadastrar(Pessoa Lista_alunos[], int num_aluno, int matricula);
void Alterar(Pessoa Lista_alunos[], int num_aluno);
int Deletar(Pessoa Lista_alunos[], int num_aluno);
void marcador_titulo(int tamanho);

int main(){
    int opcao;
    int sair=0;
    Pessoa Lista_alunos[limite_alunos];
    int num_aluno=0;
    int matricula=1;

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
                int cad = Cadastrar(Lista_alunos, num_aluno, matricula);
                if(cad==CADASTRO_SUCESSO){
                    num_aluno ++;
                    matricula ++;
                }
                break;
            }
            case 2:{
                Alterar(Lista_alunos, num_aluno);
                break;
            }
            case 3:{
                int del = Deletar(Lista_alunos, num_aluno);
                if(del==DELETADO_SUCESSO){
                    num_aluno --;
                }
                break;
            }
            case 4:{
                Listar(Lista_alunos, num_aluno);
                getchar();
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
    puts("\n");
    marcador_titulo(48);
    puts("*****DIGITE O DIA, MÊS E ANO DE NASCIMENTO:*****");
    marcador_titulo(48);\
    do{
        do{
            puts("\n");
            puts("DIA:");

            scanf("%d",dia);
            getchar();

            if(*dia>31 || *dia<1){

                puts("\n");
                marcador_titulo(38);
                puts("*****DIA É UM NÚMERO ENTRE 1 E 31*****");
                marcador_titulo(38);
            }
        } while(*dia>31 || *dia<1);
        do{
            puts("\n");
            puts("MÊS:");
            scanf("%d",mes);
            getchar();

            if(*mes>12){
                puts("\n");
                marcador_titulo(38);
                puts("*****MÊS É UM NÚMERO ENTRE 1 E 12*****\n");
                marcador_titulo(38);
            }
        } while(*mes>12 || *mes<1);
        if((*dia>29 && *mes ==2)||(*dia>30 && *mes ==4)||(*dia>30 && *mes ==6)||(*dia>30 && *mes ==9)||(*dia>30 && *mes ==11)){
            marcador_titulo(23);
            puts("*****DATA INVÁLIDA*****");
            marcador_titulo(23);
        }
    }while((*dia>29 && *mes ==2)||(*dia>30 && *mes ==4)||(*dia>30 && *mes ==6)||(*dia>30 && *mes ==9)||(*dia>30 && *mes ==11));
    do{
        puts("\n");
        puts("ANO(FORMATO AAAA):");
        scanf("%d",ano);
        getchar();
        if(*ano>2026 ||*ano<1900){
            puts("\n");
            marcador_titulo(22);
            puts("*****ANO INVÁLIDO*****");
            marcador_titulo(22);
        }
    } while(*ano>2026 || *ano<1900);
}
void recebe_string(char *string, int tamanho){
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
}
void menu(){
    marcador_titulo(30);
    puts("********PROJETO ESCOLA********");
    marcador_titulo(30);
    puts("\n");

    marcador_titulo(25);
    puts("****ESCOLHA UMA OPÇÃO****");
    marcador_titulo(25);
    puts("\n");

    puts("\t0 - Sair");
    puts("\t1 - Cadastrar Aluno");
    puts("\t2 - Alterar Aluno");
    puts("\t3 - Excluir Aluno");
    puts("\t4 - Listar Alunos");
}
void Listar(Pessoa Lista_alunos[], int num_aluno){
    if(num_aluno==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        puts("\n");
        marcador_titulo(25);
        puts("*****LISTA DE ALUNOS*****");
        marcador_titulo(25);
        puts("\n");
        for(int i=0; i<num_aluno; i++){
            printf("%d - Matrícula:%d \tNome: %s \tNascimento: %d/%d/%d \tCPF:%lld \tGênero:%c\n", i+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2], Lista_alunos[i].cpf, Lista_alunos[i].genero);
        }
    }
    puts("\n");
}
int Cadastrar(Pessoa Lista_alunos[], int num_aluno, int matricula){
    if(num_aluno<limite_alunos){
        puts("\n");
        marcador_titulo(29);
        puts("*******CADASTRAR ALUNO*******");
        marcador_titulo(29);
        puts("\n");

        puts("DIGITE O NOME:");

        recebe_string(Lista_alunos[num_aluno].nome, 100);

        recebe_data(&Lista_alunos[num_aluno].data_nascimento[0], &Lista_alunos[num_aluno].data_nascimento[1], &Lista_alunos[num_aluno].data_nascimento[2]);
        puts("\n");
        puts("DIGITE O CPF:");

        scanf("%lld",&Lista_alunos[num_aluno].cpf);
        getchar();
        do{
            puts("\n");
            puts("DIGITE O GÊNERO (M - MASCULINO | F - FEMININO):");
            scanf("%c", &Lista_alunos[num_aluno].genero);
            getchar();

            if(Lista_alunos[num_aluno].genero == 'm' || Lista_alunos[num_aluno].genero == 'f')
                Lista_alunos[num_aluno].genero -= 32;

        } while(Lista_alunos[num_aluno].genero != 'M' && Lista_alunos[num_aluno].genero != 'F');

        Lista_alunos[num_aluno].aluno_ou_professor = 'A';
        Lista_alunos[num_aluno].matricula = matricula;
        return CADASTRO_SUCESSO;
    }
    else{
        puts("\n");
        marcador_titulo(40);
        puts("**NÃO É POSSÍVEL CADASTRAR MAIS ALUNOS**");
        marcador_titulo(40);
        puts("\n");
        return CADASTRO_ERRO;
    }
}

void Alterar(Pessoa Lista_alunos[], int num_aluno){
    Listar(Lista_alunos, num_aluno);
    puts("\n");
    marcador_titulo(63);
    puts("**DIGITE O NÚMERO DE MATRÍCULA DO ALUNO QUE VOCÊ QUER ALTERAR**\n");
    marcador_titulo(63);
    int opcao;
    scanf("%d", &opcao);
    getchar();
    int alterado=0;
    for(int i=0; i<=num_aluno; i++){
        if(Lista_alunos[i].matricula == opcao){
            puts("/n");
            puts("DIGITE O NOME:");
            marcador_titulo(35);
            recebe_string(Lista_alunos[i].nome, 100);
            recebe_data(&Lista_alunos[i].data_nascimento[0], &Lista_alunos[i].data_nascimento[1], &Lista_alunos[i].data_nascimento[2]);
            puts("/n");
            puts("DIGITE O CPF:");
            scanf("%lld",&Lista_alunos[num_aluno].cpf);
            getchar();

            do{
                puts("/n");
                puts("DIGITE O GÊNERO (M - MASCULINO | F - FEMININO):");
                scanf("%c", &Lista_alunos[i].genero);
                getchar();

                if(Lista_alunos[i].genero == 'm' || Lista_alunos[i].genero == 'f')
                Lista_alunos[i].genero -= 32;

            } while(Lista_alunos[i].genero != 'M' && Lista_alunos[i].genero != 'F');
            alterado=1;
        }
        if(i>num_aluno && alterado==1){
            marcador_titulo(35);
            puts("**NÚMERO DE MATRÍCULA NÃO ENCONTRADO**");
            marcador_titulo(35);
        }
    }

}

int Deletar(Pessoa Lista_alunos[], int num_aluno){
    Listar(Lista_alunos, num_aluno);

    int opcao;
    do{
        marcador_titulo(35);
        puts("**DIGITE O NÚMERO REFERENTE AO ALUNO QUE VOCÊ QUER DELETAR OU 0 PARA CANCELAR**");
        marcador_titulo(35);
        scanf("%d", &opcao);
        getchar();
    }while(opcao > num_aluno+1 || opcao < 0);
    if(opcao==0) return DELETADO_ERRO;
    else{
        for(int i=opcao; i<num_aluno; i++){
            Lista_alunos[i-1] = Lista_alunos[i];
        }
        return DELETADO_SUCESSO;
    }
}
void marcador_titulo(int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("*");
    }
    printf("\n");
}

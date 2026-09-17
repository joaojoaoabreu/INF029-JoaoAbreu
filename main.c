#include <stdio.h>
#include <string.h>
#define limite_alunos 3
#define limite_professores 3
#define limite_aluno_por_disciplina 30
#define limite_disciplinas_por_aluno 10
#define CADASTRO_SUCESSO -1
#define CADASTRO_ERRO -2
#define DELETADO_SUCESSO -3
#define DELETADO_ERRO -4

typedef struct{
    int codigo;
    char nome;
    int semestre;
    int professor;
    int alunos[limite_aluno_por_disciplina];

}Disciplina;

typedef struct{
    int matricula;
    char nome[100];
    int data_nascimento[3];
    long long cpf;
    int disciplinas[limite_disciplinas_por_aluno];
    char genero;
    char aluno_ou_professor;

}Pessoa;

int menu();
void menu_aluno(Pessoa Lista_alunos[], int num_aluno);
void recebe_string(char *string, int tam);
void recebe_data(int *dia, int *mes, int *ano);
void Listar_Alunos(Pessoa Lista_alunos[], int num_aluno);
int Cadastrar(Pessoa Lista_alunos[], int num_aluno);
void Alterar(Pessoa Lista_alunos[], int num_aluno);
int Deletar_Aluno(Pessoa Lista_alunos[], int num_aluno);
void marcador_titulo(int tamanho);

int main(){
    Pessoa Lista_alunos[limite_alunos];
    Pessoa Lista_professores[limite_professores];
    int sair=0;
    int num_aluno=0;
    int num_professor=0;

    while(sair==0){
       int opcao = menu();

        switch(opcao){ //menu principal
            case 0:{
                sair=1;
                break;
            }
            case 1:{ //menu aluno
                menu_aluno(Lista_alunos, num_aluno);
                break;
            }
            case 2:{
                break;
            }
            case 3:{
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
                puts("*****MÊS É UM NÚMERO ENTRE 1 E 12*****");
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
int menu(){

    marcador_titulo(30);
    puts("********PROJETO ESCOLA********");
    marcador_titulo(30);
    puts("\n");

    marcador_titulo(25);
    puts("****ESCOLHA UMA OPÇÃO****");
    marcador_titulo(25);
    puts("\n");

    puts("\t0 - Sair");
    puts("\t1 - Menu Aluno");
    puts("\t2 - Menu Professor");
    puts("\t3 - Menu Disciplinas");

    int opcao;
    scanf("%d", &opcao);
    getchar();
    return opcao;
}
void menu_aluno(Pessoa Lista_alunos[], int num_aluno){

    int voltar=0;
    while(voltar==0){

        marcador_titulo(26);
        puts("********MENU ALUNO********");
        marcador_titulo(26);
        puts("\n");

        marcador_titulo(25);
        puts("****ESCOLHA UMA OPÇÃO****");
        marcador_titulo(25);
        puts("\n");

        puts("\t0 - Voltar");
        puts("\t1 - Cadastrar Aluno");
        puts("\t2 - Alterar Aluno");
        puts("\t3 - Excluir ALuno");
        puts("\t4 - Listar Alunos");

        int opcao;
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:{ //voltar para menu principal
                voltar=1;
                break;
            }
            case 1:{ //cadastrar alunos
                int cad = Cadastrar(Lista_alunos, num_aluno);
                if(cad==CADASTRO_SUCESSO){
                    num_aluno ++;
                }
                break;
            }
            case 2:{ //alterar alunos
                Alterar(Lista_alunos, num_aluno);
                break;
            }
            case 3:{ //deletar alunos
                int del = Deletar_Aluno(Lista_alunos, num_aluno);
                if(del==DELETADO_SUCESSO){
                    num_aluno --;
                }
                break;
            }
            case 4:{ //listar alunos
                Listar_Alunos(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de aluno");
                getchar();
                break;
            }
            default:{
                break;
            }
        }
    }

}
/* void menu_professor(Pessoa Lista_professores[], int num_professor){

    int voltar=0;
    while(voltar==0){

        marcador_titulo(26);
        puts("********MENU ALUNO********");
        marcador_titulo(26);
        puts("\n");

        marcador_titulo(25);
        puts("****ESCOLHA UMA OPÇÃO****");
        marcador_titulo(25);
        puts("\n");

        puts("\t0 - Voltar");
        puts("\t1 - Cadastrar Aluno");
        puts("\t2 - Alterar Aluno");
        puts("\t3 - Excluir ALuno");
        puts("\t4 - Listar Alunos");

        int opcao;
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:{ //voltar para menu principal
                voltar=1;
                break;
            }
            case 1:{ //cadastrar alunos
                int cad = Cadastrar(Lista_alunos, num_aluno);
                if(cad==CADASTRO_SUCESSO){
                    num_aluno ++;
                }
                break;
            }
            case 2:{ //alterar alunos
                Alterar(Lista_alunos, num_aluno);
                break;
            }
            case 3:{ //deletar alunos
                int del = Deletar_Aluno(Lista_alunos, num_aluno);
                if(del==DELETADO_SUCESSO){
                    num_aluno --;
                }
                break;
            }
            case 4:{ //listar alunos
                Listar_Alunos(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de aluno");
                getchar();
                break;
            }
            default:{
                break;
            }
        }
    }

} */
void Listar_Alunos(Pessoa Lista_alunos[], int num_aluno){
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
int Cadastrar(Pessoa Lista_alunos[], int num_aluno){
    static int matricula=1;
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
        matricula++;
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
    Listar_Alunos(Lista_alunos, num_aluno);
    puts("\n");
    marcador_titulo(53);
    puts("**ESCOLHA O ALUNO CUJO CADASTRO VOCÊ QUER ATUALIZAR**");
    marcador_titulo(53);
    int opcao;
    scanf("%d", &opcao);
    getchar();
    if(opcao<=num_aluno+1 && opcao>0){
        opcao--;
        puts("\n");
        puts("DIGITE O NOME:");
        recebe_string(Lista_alunos[opcao].nome, 100);
        recebe_data(&Lista_alunos[opcao].data_nascimento[0], &Lista_alunos[opcao].data_nascimento[1], &Lista_alunos[opcao].data_nascimento[2]);
        puts("\n");
        puts("DIGITE O CPF:");
        scanf("%lld",&Lista_alunos[opcao].cpf);
        getchar();

        do{
            puts("\n");
            puts("DIGITE O GÊNERO (M - MASCULINO | F - FEMININO):");
            scanf("%c", &Lista_alunos[opcao].genero);
            getchar();

            if(Lista_alunos[opcao].genero == 'm' || Lista_alunos[opcao].genero == 'f')
            Lista_alunos[opcao].genero -= 32;

        } while(Lista_alunos[opcao].genero != 'M' && Lista_alunos[opcao].genero != 'F');
    }
    else{
        marcador_titulo(21);
        puts("**OPÇÃO NÃO ENCONTRADA**");
        marcador_titulo(21);
    }

}

int Deletar_Aluno(Pessoa Lista_alunos[], int num_aluno){
    Listar_Alunos(Lista_alunos, num_aluno);

    int opcao;
    do{
        marcador_titulo(79);
        puts("**DIGITE O NÚMERO REFERENTE AO ALUNO QUE VOCÊ QUER DELETAR OU 0 PARA CANCELAR**");
        marcador_titulo(79);
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

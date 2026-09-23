#include <stdio.h>
#include <string.h>
#define limite_alunos 5
#define limite_professores 5
#define limite_disciplinas 5
#define limite_aluno_por_disciplina 45
#define limite_disciplinas_por_aluno 10
#define CADASTRO_SUCESSO -1
#define CADASTRO_ERRO -2
#define DELETADO_SUCESSO -3
#define DELETADO_ERRO -4
#define MATRICULA_ERRO -5
#define MATRICULA_SUCESSO -6
#define CPF_VALIDO -7
#define CPF_INVALIDO -8

#define ANO_ATUAL 2026
#define MES_ATUAL 9

typedef struct{
    int codigo;
    char nome[100];
    int semestre;
    int professor;
    int alunos[limite_aluno_por_disciplina];
    int num_alunos;

}Disciplina;

typedef struct{
    int matricula;
    char nome[100];
    int data_nas;
    int data_nascimento[3];
    long long cpf;
    int disciplinas[limite_disciplinas_por_aluno];
    int num_disciplinas;
    char genero;
    char aluno_ou_professor;

}Pessoa;

int menu();
int menu_aluno(Pessoa Lista_alunos[], int num_aluno);
int menu_professor(Pessoa Lista_professores[], int num_professor);
int menu_disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_disciplina, int num_professor, int num_aluno);
int menu_relatorios(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_disciplina, int num_professor, int num_aluno);
void recebe_string(char *string, int tam);
int recebe_data(int *dia, int *mes, int *ano);
int validar_cpf(long long cpf);
void Buscar_pessoas(Pessoa Lista_alunos[], Pessoa Lista_professores[], int num_aluno, int num_professor);
void Alunos_menos_de_tres(Pessoa Lista_alunos[], int num_aluno);
void Listar_Alunos(Pessoa Lista_alunos[], int num_aluno);
void Listar_Alunos_data(Pessoa Lista_alunos[], int num_aluno);
void Listar_Alunos_nome(Pessoa Lista_alunos[], int num_aluno);
void Listar_Alunos_sexo(Pessoa Lista_alunos[], int num_aluno);
void Listar_Professores(Pessoa Lista_professores[], int num_professor);
void Listar_Professores_data(Pessoa Lista_professores[], int num_professor);
void Listar_Professores_nome(Pessoa Lista_professores[], int num_professor);
void Listar_Professores_sexo(Pessoa Lista_professores[], int num_professor);
void Listar_Disciplinas_Menu(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_disciplina, int num_professor);
void Listar_Disciplinas_mais_quarenta(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], int num_disciplina, int num_professor);
void Aniversariante_mes(Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_aluno, int num_professor);
int Cadastrar_aluno(Pessoa Lista_alunos[], int num_aluno);
int Cadastrar_professor(Pessoa Lista_professores[], int num_professor);
int Cadastrar_disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], int num_disciplina, int num_professor);
int Matricular_aluno(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_professor, int num_disciplina, int num_aluno);
int Desmatricular_aluno(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_professor, int num_disciplina, int num_aluno);
void Alterar(Pessoa Lista_alunos[], int num_aluno);
void Alterar_professor(Pessoa Lista_professores[], int num_professor);
int Deletar_Aluno(Pessoa Lista_alunos[], int num_aluno);
int Deletar_Professor(Pessoa Lista_professores[], int num_professor);//Adicionar verificação para matéria que o professor ensina, atualização do professor da matéria ou opção de deletar a matéria.
int Deletar_Disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[],Pessoa Lista_alunos[], int num_disciplina, int num_professor, int num_aluno);
void marcador_titulo(int tamanho);

int main(){
    Pessoa Lista_alunos[limite_alunos];
    Pessoa Lista_professores[limite_professores];
    Disciplina Lista_disciplinas[limite_disciplinas];
    int sair=0;
    int num_aluno=0;
    int num_professor=0;
    int num_disciplina=0;

    while(sair==0){
       int opcao = menu();

        switch(opcao){ //menu principal
            case 0:{
                sair=1;
                break;
            }
            case 1:{ //menu aluno
                num_aluno=menu_aluno(Lista_alunos, num_aluno);
                break;
            }
            case 2:{
                num_professor=menu_professor(Lista_professores, num_professor);
                break;
            }
            case 3:{
                num_disciplina=menu_disciplina(Lista_disciplinas, Lista_professores, Lista_alunos, num_disciplina, num_professor, num_aluno);
                break;
            }
            case 4:{
                num_disciplina=menu_relatorios(Lista_disciplinas, Lista_professores, Lista_alunos, num_disciplina, num_professor, num_aluno);
                break;
            }
            default:{

                break;
                }

        }
    }
    return 0;
}
int recebe_data(int *dia, int *mes, int *ano){
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
    }while(
        (*dia>29 && *mes ==2)||
        (*dia>30 && *mes ==4)||
        (*dia>30 && *mes ==6)||
        (*dia>30 && *mes ==9)||
        (*dia>30 && *mes ==11));
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
    } while(*ano>ANO_ATUAL || *ano<ANO_ATUAL-150);
    int aaaammdd = *ano * 10000 + *mes * 100 + *dia;
    return aaaammdd;
}
void recebe_string(char *string, int tamanho){
    fgets(string, tamanho, stdin);
    string[strcspn(string, "\n")] = '\0';
}
int validar_cpf(long long cpf){
    if(cpf>99999999999){
        printf("CPF inválido");
        return CPF_INVALIDO;
    }
    int num[11];
    int temp=0;
    for(int i=10; i>=0; i--){
        num[i]=cpf%10;
        cpf/=10;
    }
    for(int j=0; j<10; j++){
        if(num[j]==num[j+1]){
            temp++;
        }
    }
    if(temp==10){
        printf("CPF inválido");
        return CPF_INVALIDO;
    }
    else{

        int s1=(num[0]*10)+(num[1]*9)+(num[2]*8)+(num[3]*7)+(num[4]*6)+(num[5]*5)+(num[6]*4)+(num[7]*3)+(num[8]*2);
        int s2=(num[0]*11)+(num[1]*10)+(num[2]*9)+(num[3]*8)+(num[4]*7)+(num[5]*6)+(num[6]*5)+(num[7]*4)+(num[8]*3)+(num[9]*2);
        int resto1=s1%11;
        int resto2=s2%11;

        if(resto1<2 && num[9]==0){
            if(resto2<2 && num[10]==0){
                return CPF_VALIDO;
            }
            else if(num[10]==(11-resto2)){
                return CPF_VALIDO;
            }
            else{
                printf("CPF inválido");
                return CPF_INVALIDO;
            }
        }
        else if(num[9]==(11-resto1)){
            if(resto2<2 && num[10]==0){
                return CPF_VALIDO;
            }
            else if(num[10]==(11-resto2)){
                return CPF_VALIDO;
            }
            else{
                printf("CPF inválido");
                return CPF_INVALIDO;
            }
        }
        else{
            printf("CPF inválido");
            return CPF_INVALIDO;
        }
    }
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
    puts("\t1 - Menu Alunos");
    puts("\t2 - Menu Professores");
    puts("\t3 - Menu Disciplinas");
    puts("\t4 - Menu Relatórios");


    int opcao;
    scanf("%d", &opcao);
    getchar();
    return opcao;
}
int menu_aluno(Pessoa Lista_alunos[], int num_aluno){

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
        puts("\t3 - Excluir Aluno");
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
                if(Cadastrar_aluno(Lista_alunos, num_aluno)==CADASTRO_SUCESSO){
                    num_aluno ++;
                }
                break;
            }
            case 2:{ //alterar alunos
                Alterar(Lista_alunos, num_aluno);
                break;
            }
            case 3:{ //deletar alunos
                if(Deletar_Aluno(Lista_alunos, num_aluno)==DELETADO_SUCESSO){
                    num_aluno --;
                    puts("Aluno deletado com sucesso. Aperte ENTER para voltar ao menu de aluno");
                    getchar();
                }
                else puts("Nenhum aluno deletado");
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
    return num_aluno;
}
int menu_professor(Pessoa Lista_professores[], int num_professor){

    int voltar=0;
    while(voltar==0){

        marcador_titulo(30);
        puts("********MENU PROFESSOR********");
        marcador_titulo(30);
        puts("\n");

        marcador_titulo(25);
        puts("****ESCOLHA UMA OPÇÃO****");
        marcador_titulo(25);
        puts("\n");

        puts("\t0 - Voltar");
        puts("\t1 - Cadastrar Professor");
        puts("\t2 - Alterar Professor");
        puts("\t3 - Excluir Professor");
        puts("\t4 - Listar Professores");

        int opcao;
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:{ //voltar para menu principal
                voltar=1;
                break;
            }
            case 1:{ //cadastrar professores
                if(Cadastrar_professor(Lista_professores, num_professor)==CADASTRO_SUCESSO){
                    num_professor ++;
                }
                break;
            }
            case 2:{ //alterar professores
                Alterar_professor(Lista_professores, num_professor);
                break;
            }
            case 3:{ //deletar professores
                if(Deletar_Professor(Lista_professores, num_professor)==DELETADO_SUCESSO){
                    num_professor --;
                    puts("Professor deletado com sucesso. Aperte ENTER para voltar ao menu de professores");
                    getchar();
                }
                else puts("Nenhum professor deletado");
                break;
            }
            case 4:{ //listar professores
                Listar_Professores(Lista_professores, num_professor);
                puts("Aperte ENTER para voltar ao menu de professor");
                getchar();
                break;
            }
            default:{
                break;
            }
        }
    }
    return num_professor;
}
int menu_disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_disciplina, int num_professor, int num_aluno){

    int voltar=0;
    while(voltar==0){

        marcador_titulo(31);
        puts("********MENU DISCIPLINA********");
        marcador_titulo(31);
        puts("\n");

        marcador_titulo(25);
        puts("****ESCOLHA UMA OPÇÃO****");
        marcador_titulo(25);
        puts("\n");

        puts("\t0 - Voltar");
        puts("\t1 - Cadastrar Disciplina");
        puts("\t2 - Alterar Disciplina");
        puts("\t3 - Excluir Disciplina");
        puts("\t4 - Listar Disciplinas");
        puts("\t5 - Matricular Aluno em Disciplina");
        puts("\t6 - Remover Aluno de Disciplina");

        int opcao;
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:{ //voltar para menu principal
                voltar=1;
                break;
            }
            case 1:{ //cadastrar disciplinas
                if(Cadastrar_disciplina(Lista_disciplinas, Lista_professores, num_disciplina, num_professor)==CADASTRO_SUCESSO){
                    num_disciplina ++;
                }
                break;
            }
            case 2:{ //alterar professores
                Alterar_professor(Lista_professores, num_professor);
                break;
            }
            case 3:{ //deletar professores
                if(Deletar_Professor(Lista_professores, num_professor)==DELETADO_SUCESSO){
                    num_professor --;
                    puts("Professor deletado com sucesso. Aperte ENTER para voltar ao menu de professores");
                    getchar();
                }
                else puts("Nenhum professor deletado");
                break;
            }
            case 4:{ //listar disciplinas
                Listar_Disciplinas_Menu(Lista_disciplinas, Lista_professores, Lista_alunos, num_disciplina, num_professor);
                puts("Aperte ENTER para voltar ao menu de disciplina");
                getchar();
                break;
            }
            case 5:{ //matricular aluno em disciplina
                int sair_da_matricula=0;
                while(sair_da_matricula==0){

                    if( Matricular_aluno(Lista_disciplinas, Lista_professores, Lista_alunos, num_professor, num_disciplina, num_aluno) == MATRICULA_ERRO){
                        puts("Matrícula não realizada.");
                    }
                    do{
                    puts("Digite: \n\t0 para realizar outra matrícula ou \n\t1 para voltar ao menu de disciplinas.");
                    scanf("%d", &sair_da_matricula);
                    getchar();
                    } while(sair_da_matricula != 0 && sair_da_matricula != 1);
                }
                break;
            }
            case 6:{ //remover aluno de disciplina
                int sair_da_desmatricula=0;
                while(sair_da_desmatricula==0){

                    if( Desmatricular_aluno(Lista_disciplinas, Lista_professores, Lista_alunos, num_professor, num_disciplina, num_aluno) == MATRICULA_ERRO){
                        puts("Remoção não realizada.");
                    }
                    do{
                    puts("Digite: \n\t0 para remover outro aluno ou \n\t1 para voltar ao menu de disciplinas.");
                    scanf("%d", &sair_da_desmatricula);
                    getchar();
                    } while(sair_da_desmatricula != 0 && sair_da_desmatricula != 1);
                }
                break;
            }
            default:{
                break;
            }
        }
    }
    return num_disciplina;
}
int menu_relatorios(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_disciplina, int num_professor, int num_aluno){

    int voltar=0;
    while(voltar==0){

        marcador_titulo(31);
        puts("********MENU RELATÓRIOS********");
        marcador_titulo(31);
        puts("\n");

        marcador_titulo(25);
        puts("****ESCOLHA UMA OPÇÃO****");
        marcador_titulo(25);
        puts("\n");

        puts("\t00 - Voltar");
        puts("\t01 - Listar Alunos");
        puts("\t02 - Listar Professores");
        puts("\t03 - Listar Disciplinas");
        puts("\t04 - Listar Alunos por gênero");
        puts("\t05 - Listar Alunos ordenados por nome");
        puts("\t06 - Listar Alunos ordenados por data de nascimento");
        puts("\t07 - Listar Professores por gênero");
        puts("\t08 - Listar Professores ordenados por nome");
        puts("\t09 - Listar Professores ordenados por data de nascimento");
        puts("\t10 - Aniversariantes do Mês");
        puts("\t11 - Buscar Pessoas por nome");
        puts("\t12 - Listar Alunos matriculados em menos de 3 disciplinas");
        puts("\t13 - Listar Disciplinas como mais de 40 vagas");

        int opcao;
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 0:{ //voltar para menu principal
                voltar=1;
                break;
            }
            case 1:{ //listar alunos
                Listar_Alunos(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 2:{ //listar professores
                Listar_Professores(Lista_professores, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 3:{ //listar aluno por sexo
                Listar_Disciplinas_Menu(Lista_disciplinas, Lista_professores, Lista_alunos, num_disciplina, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 4:{ //listar aluno por sexo
                Listar_Alunos_sexo(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 5:{ //listar aluno por nome
                Listar_Alunos_nome(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de disciplina");
                getchar();
                break;
            }
            case 6:{ //listar aluno por data de nascimento
                Listar_Alunos_data(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 7:{ //listar professores por sexo
                Listar_Professores_sexo(Lista_professores, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 8:{ //listar professores por nome
                Listar_Professores_nome(Lista_professores, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 9:{ //listar professores por data de nascimento
                Listar_Professores_data(Lista_professores, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 10:{ //Aniversariantes do mês
                Aniversariante_mes(Lista_professores, Lista_alunos, num_aluno, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 11:{ //Buscar Pessoas por nome
                Buscar_pessoas(Lista_alunos, Lista_professores, num_aluno, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 12:{ //Listar Alunos matriculados em menos de 3 disciplinas
                Alunos_menos_de_tres(Lista_alunos, num_aluno);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            case 13:{ //Listar Disciplinas como mais de 40 vagas
                Listar_Disciplinas_mais_quarenta(Lista_disciplinas, Lista_professores, num_disciplina, num_professor);
                puts("Aperte ENTER para voltar ao menu de relatórios");
                getchar();
                break;
            }
            default:{
                break;
            }
        }
    }
    return num_disciplina;
}
void Buscar_pessoas(Pessoa Lista_alunos[], Pessoa Lista_professores[], int num_aluno, int num_professor){
    if(num_aluno==0 && num_professor==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        int volta=0;
        marcador_titulo(27);
        puts("*****BUSCAR PESSOAS*****");
        marcador_titulo(27);
        char busca[4];
        int encontrados = 0;
        while(volta==0){
            puts("\nDIGITE 3 LETRAS DO NOME QUE VOCÊ QUER BUSCAR:\n");
            recebe_string(busca, 4);
            for(int i=0; i<3; i++){
                if(busca[i]>96 && busca[i]<123){
                    busca[i]-=32;
                }
            }
            puts("Alunos:\n");
            for(int i=0; i<num_aluno; i++){
                for(int j=0; Lista_alunos[i].nome[j]!='\0'; j++){
                    if(busca[0]==Lista_alunos[i].nome[j] || (busca[0]+32)==Lista_alunos[i].nome[j]){
                        if(busca[1]==Lista_alunos[i].nome[j+1] || (busca[1]+32)==Lista_alunos[i].nome[j+1]){
                            if(busca[2]==Lista_alunos[i].nome[j+2] || (busca[2]+32)==Lista_alunos[i].nome[j+2]){
                                printf("%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", encontrados+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].cpf, Lista_alunos[i].genero, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2]);
                                encontrados++;
                            }
                        }
                    }
                }
            }
            if(encontrados==0){
                puts("\tNenhum aluno encontrado.\n\n");
            }
            puts("Professores:\n");
            for(int i=0; i<num_professor; i++){
                for(int j=0; Lista_professores[i].nome[j]!='\0'; j++){
                    if(busca[0]==Lista_professores[i].nome[j] || busca[0]+32==Lista_professores[i].nome[j]){
                        if(busca[1]==Lista_professores[i].nome[j+1] || busca[1]+32==Lista_professores[i].nome[j+1]){
                            if(busca[2]==Lista_professores[i].nome[j+2] || busca[2]+32==Lista_professores[i].nome[j+2]){
                                printf("%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", encontrados+1, Lista_professores[i].matricula, Lista_professores[i].nome, Lista_professores[i].cpf, Lista_professores[i].genero, Lista_professores[i].data_nascimento[0], Lista_professores[i].data_nascimento[1], Lista_professores[i].data_nascimento[2]);
                                encontrados++;
                            }
                        }
                    }
                }
            }
            if(encontrados==0){
                puts("\tNenhum professor encontrado.\n\n");
            }
            do{
            puts("\nDIGITE 0 PARA BUSCAR NOVAMENTE OU 1 PARA SAIR.\n");
            scanf("%d", &volta);
            getchar();
            }while(volta<0 || volta>1);
        }
        puts("\n");
    }
}
void Listar_Alunos_sexo(Pessoa Lista_alunos[], int num_aluno){
    if(num_aluno==0){
        puts("\n");
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        char escolha;
        do{

            puts("\n");
            puts("ESCOLHA O GÊNERO (M - MASCULINO | F - FEMININO):");
            puts("\n");
            scanf("%c", &escolha);
            getchar();
            puts("\n");

            if(escolha == 'm' || escolha == 'f')
                escolha -= 32;

        } while(escolha != 'M' && escolha != 'F');
        marcador_titulo(37);
        puts("***LISTA DE ALUNOS POR GENERO***");
        marcador_titulo(37);
        int contagem=0;
        switch(escolha){
            case 'F':{
                puts("\n");
                printf("Feminino:\n");
                puts("\n");
                for(int i=0; i<num_aluno; i++){
                    if(Lista_alunos[i].genero=='F'){
                        printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", contagem+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].cpf, Lista_alunos[i].genero, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2]);
                        contagem++;
                    }
                }
                break;
            }
            case 'M':{
                puts("\n");
                printf("Masculino:\n");
                puts("\n");
                for(int i=0; i<num_aluno; i++){
                    if(Lista_alunos[i].genero=='M'){
                        printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", contagem+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].cpf, Lista_alunos[i].genero, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2]);
                        contagem++;
                    }
                }
                break;
            }
            default:{
                break;
                }
        }

    }
}
void Listar_Alunos_nome(Pessoa Lista_alunos[], int num_aluno){
    Pessoa Alunos_por_nome[num_aluno];
    for(int i=0; i<num_aluno; i++){
        Alunos_por_nome[i]=Lista_alunos[i];
    }
    if(num_aluno==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        marcador_titulo(36);
        puts("*****ALUNOS EM ORDEM ALFABÉTICA*****");
        marcador_titulo(36);
        puts("\n");

        for(int i=0; i<num_aluno; i++){
            for(int j=i+1; j<num_aluno; j++){
                int k=0;
                while(Alunos_por_nome[j].nome[k]==Alunos_por_nome[i].nome[k]) k++;
                if(Alunos_por_nome[j].nome[k]<Alunos_por_nome[i].nome[k]){
                    Pessoa temp = Alunos_por_nome[i];
                    Alunos_por_nome[i] = Alunos_por_nome[j];
                    Alunos_por_nome[j] = temp;
                }
            }
        }
        for(int i=0; i<num_aluno; i++){
            printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", i+1, Alunos_por_nome[i].matricula, Alunos_por_nome[i].nome, Alunos_por_nome[i].cpf, Alunos_por_nome[i].genero, Alunos_por_nome[i].data_nascimento[0], Alunos_por_nome[i].data_nascimento[1], Alunos_por_nome[i].data_nascimento[2]);
        }
        puts("\n");
    }
}
void Listar_Alunos_data(Pessoa Lista_alunos[], int num_aluno){
    Pessoa Alunos_por_data[num_aluno];
    for(int i=0; i<num_aluno; i++){
        Alunos_por_data[i]=Lista_alunos[i];
    }
    if(num_aluno==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        marcador_titulo(37);
        puts("***ALUNOS ORDENADOS POR NASCIMENTO***");
        marcador_titulo(37);
        puts("\n");

        for(int i=0; i<num_aluno; i++){
            for(int j=i+1; j<num_aluno; j++){
                if(Alunos_por_data[j].data_nas<Alunos_por_data[i].data_nas){
                    Pessoa temp = Alunos_por_data[i];
                    Alunos_por_data[i] = Alunos_por_data[j];
                    Alunos_por_data[j] = temp;
                }
            }
        }
        for(int i=0; i<num_aluno; i++){
            printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", i+1, Alunos_por_data[i].matricula, Alunos_por_data[i].nome, Alunos_por_data[i].cpf, Alunos_por_data[i].genero, Alunos_por_data[i].data_nascimento[0], Alunos_por_data[i].data_nascimento[1], Alunos_por_data[i].data_nascimento[2]);
        }
        puts("\n");
    }
}
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
            printf("%d - Matrícula:%d \tNome: %s \tNascimento: %d/%d/%d \tCPF: %011lld \tGênero:%c\n", i+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2], Lista_alunos[i].cpf, Lista_alunos[i].genero);
        }
    }
    puts("\n");
}
void Alunos_menos_de_tres(Pessoa Lista_alunos[], int num_aluno){
    if(num_aluno==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        puts("\n");
        marcador_titulo(51);
        puts("***ALUNOS MATRICULADOS EM MENOS DE 3 DISCIPLINAS***");
        marcador_titulo(51);
        puts("\n");
        int contador=0;
        for(int i=0; i<num_aluno; i++){
            if(Lista_alunos[i].num_disciplinas<3){
                printf("%d - Matrícula:%d \tNome: %s \tNascimento: %d/%d/%d \tCPF: %011lld \tGênero:%c\n", contador+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2], Lista_alunos[i].cpf, Lista_alunos[i].genero);
                contador++;
            }
        }
        if(contador==0){
            puts("Nenhum aluno matriculado em menos de 3 disciplinas");
        }
    }
    puts("\n");
}
void Listar_Professores_sexo(Pessoa Lista_professores[], int num_professor){
    if(num_professor==0){
        puts("\n");
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        char escolha;
        do{

            puts("\n");
            puts("ESCOLHA O GÊNERO (M - MASCULINO | F - FEMININO):");
            puts("\n");
            scanf("%c", &escolha);
            getchar();
            puts("\n");
            if(escolha == 'm' || escolha == 'f')
                escolha -= 32;

        } while(escolha != 'M' && escolha != 'F');
        int contagem=0;
        marcador_titulo(32);
        puts("***LISTA DE PROFESSORES POR GENERO***");
        marcador_titulo(32);
        puts("\n");
        switch(escolha){
            case 'F':{
                puts("\n");
                printf("Feminino:\n");
                puts("\n");
                for(int i=0; i<num_professor; i++){
                    if(Lista_professores[i].genero=='F'){
                        printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", contagem+1, Lista_professores[i].matricula, Lista_professores[i].nome, Lista_professores[i].cpf, Lista_professores[i].genero, Lista_professores[i].data_nascimento[0], Lista_professores[i].data_nascimento[1], Lista_professores[i].data_nascimento[2]);
                        contagem++;
                    }
                }
                break;
            }
            case 'M':{
                puts("\n");
                printf("Masculino:\n");
                puts("\n");
                for(int i=0; i<num_professor; i++){
                    if(Lista_professores[i].genero=='M'){
                        printf("%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", contagem+1, Lista_professores[i].matricula, Lista_professores[i].nome, Lista_professores[i].cpf, Lista_professores[i].genero, Lista_professores[i].data_nascimento[0], Lista_professores[i].data_nascimento[1], Lista_professores[i].data_nascimento[2]);
                        contagem++;
                    }
                }
                break;
            }
            default:{
                break;
                }
        }

    }
}
void Listar_Professores_data(Pessoa Lista_professores[], int num_professor){
    Pessoa Professores_por_data[num_professor];
    for(int i=0; i<num_professor; i++){
        Professores_por_data[i]=Lista_professores[i];
    }
    if(num_professor==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        marcador_titulo(42);
        puts("***PROFESSORES ORDENADOS POR NASCIMENTO***");
        marcador_titulo(42);
        puts("\n");

        for(int i=0; i<num_professor; i++){
            for(int j=i+1; j<num_professor; j++){
                if(Professores_por_data[j].data_nas<Professores_por_data[i].data_nas){
                    Pessoa temp = Professores_por_data[i];
                    Professores_por_data[i] = Professores_por_data[j];
                    Professores_por_data[j] = temp;
                }
            }
        }
        for(int i=0; i<num_professor; i++){
            printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", i+1, Professores_por_data[i].matricula, Professores_por_data[i].nome, Professores_por_data[i].cpf, Professores_por_data[i].genero, Professores_por_data[i].data_nascimento[0], Professores_por_data[i].data_nascimento[1], Professores_por_data[i].data_nascimento[2]);
        }
        puts("\n");
    }
}
void Listar_Professores_nome(Pessoa Lista_professores[], int num_professor){
    Pessoa Professores_por_nome[num_professor];
    for(int i=0; i<num_professor; i++){
        Professores_por_nome[i]=Lista_professores[i];
    }
    if(num_professor==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        marcador_titulo(41);
        puts("*****PROFESSORES EM ORDEM ALFABÉTICA*****");
        marcador_titulo(41);
        puts("\n");

        for(int i=0; i<num_professor; i++){
            for(int j=i+1; j<num_professor; j++){
                int k=0;
                while(Professores_por_nome[j].nome[k]==Professores_por_nome[i].nome[k]) k++;
                if(Professores_por_nome[j].nome[k]<Professores_por_nome[i].nome[k]){
                    Pessoa temp = Professores_por_nome[i];
                    Professores_por_nome[i] = Professores_por_nome[j];
                    Professores_por_nome[j] = temp;
                }
            }
        }
        for(int i=0; i<num_professor; i++){
            printf("\t%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", i+1, Professores_por_nome[i].matricula, Professores_por_nome[i].nome, Professores_por_nome[i].cpf, Professores_por_nome[i].genero, Professores_por_nome[i].data_nascimento[0], Professores_por_nome[i].data_nascimento[1], Professores_por_nome[i].data_nascimento[2]);
        }
        puts("\n");
    }
}
void Listar_Professores(Pessoa Lista_professores[], int num_professor){
    if(num_professor==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        puts("\n");
        marcador_titulo(26);
        puts("***LISTA DE PROFESSORES***");
        marcador_titulo(26);
        puts("\n");
        for(int i=0; i<num_professor; i++){
            printf("%d - Matrícula:%d \tNome: %s \tNascimento: %d/%d/%d \tCPF: %011lld \tGênero:%c\n", i+1, Lista_professores[i].matricula, Lista_professores[i].nome, Lista_professores[i].data_nascimento[0], Lista_professores[i].data_nascimento[1], Lista_professores[i].data_nascimento[2], Lista_professores[i].cpf, Lista_professores[i].genero);
        }
    }
    puts("\n");
}
void Listar_Disciplinas_Menu(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_disciplina, int num_professor){
    if(num_disciplina==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        int j;
        puts("\n");
        marcador_titulo(26);
        puts("***LISTA DE DISCIPLINAS***");
        marcador_titulo(26);
        puts("\n");
        for(int i=0; i<num_disciplina; i++){
            printf("%d - Código: %d \tNome: %s \tSemestre: %d", i+1, Lista_disciplinas[i].codigo, Lista_disciplinas[i].nome, Lista_disciplinas[i].semestre);
            for(j=0; j<num_professor; j++){
                if(Lista_professores[j].matricula == Lista_disciplinas[i].professor){
                    printf("\tProfessor: %s\n", Lista_professores[j].nome);
                    break;
                }
            }
        }

        puts("\n\nESCOLHA UMA DISCIPLINA PARA VER ALUNOS MATRICULADOS:");

        int opcao;
        scanf("%d", &opcao);
        getchar();
        if(opcao<=num_disciplina+1 && opcao>0){
            opcao--;
            printf("Código: %d \tNome: %s \tSemestre: %d \tProfessor: %s\n", Lista_disciplinas[opcao].codigo, Lista_disciplinas[opcao].nome, Lista_disciplinas[opcao].semestre, Lista_professores[j].nome);
            if(Lista_disciplinas[opcao].num_alunos==0) puts("\nNão há alunos cadastrados nessa disciplina.");
            else{
                puts("Alunos:");
                for(int i=0;i<Lista_disciplinas[opcao].num_alunos;i++){
                    for(int j=0; j<Lista_disciplinas[opcao].num_alunos; j++){
                        if(Lista_alunos[i].matricula == Lista_disciplinas[opcao].alunos[j]){
                            printf("\tNome: %s\tMatrícula: %d\n", Lista_alunos[i].nome, Lista_alunos[i].matricula);
                            break;
                        }
                    }

                }
            }
        }
    }
    puts("\n");
}
void Aniversariante_mes(Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_aluno, int num_professor){
    if(num_professor==0 && num_aluno==0){
        marcador_titulo(25);
        puts("*****LISTA VAZIA*****");
        marcador_titulo(25);
        puts("\n");
    }
    else{
        switch(MES_ATUAL){
            case 1:{
                printf("MÊS ATUAL: JANEIRO");
                break;
            }
            case 2:{
                printf("MÊS ATUAL: FEVEREIRO");
                break;
            }
            case 3:{
                printf("MÊS ATUAL: MARÇO");
                break;
            }
            case 4:{
                printf("MÊS ATUAL: ABRIL");
                break;
            }
            case 5:{
                printf("MÊS ATUAL: MAIO");
                break;
            }
            case 6:{
                printf("MÊS ATUAL: JUNHO");
                break;
            }
            case 7:{
                printf("MÊS ATUAL: JULHO");
                break;
            }
            case 8:{
                printf("MÊS ATUAL: AGOSTO");
                break;
            }
            case 9:{
                printf("MÊS ATUAL: SETEMBRO");
                break;
            }
            case 10:{
                printf("MÊS ATUAL: OUTUBRO");
                break;
            }
            case 11:{
                printf("MÊS ATUAL: NOVEMBRO");
                break;
            }
            case 12:{
                printf("MÊS ATUAL: DEZEMBRO");
                break;
            }
        }
        int j;
        puts("\n");
        marcador_titulo(28);
        puts("***ANIVERSARIANTES DO MÊS***");
        marcador_titulo(28);
        int aniversariantes = 0;
        for(int i=0; i<num_aluno; i++){
            if(Lista_alunos[i].data_nascimento[1]==MES_ATUAL){
                printf("%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", aniversariantes+1, Lista_alunos[i].matricula, Lista_alunos[i].nome, Lista_alunos[i].cpf, Lista_alunos[i].genero, Lista_alunos[i].data_nascimento[0], Lista_alunos[i].data_nascimento[1], Lista_alunos[i].data_nascimento[2]);
                aniversariantes++;
            }
        }
        for(int i=0; i<num_professor; i++){
            if(Lista_professores[i].data_nascimento[1]==MES_ATUAL){
                printf("%d - Matrícula:%d \tNome: %s \tCPF: %011lld \tGênero:%c \tNascimento: %d/%d/%d\n", aniversariantes+1, Lista_professores[i].matricula, Lista_professores[i].nome, Lista_professores[i].cpf, Lista_professores[i].genero, Lista_professores[i].data_nascimento[0], Lista_professores[i].data_nascimento[1], Lista_professores[i].data_nascimento[2]);
                aniversariantes++;
            }
        }
        printf("\n");
        if(aniversariantes==0){
            printf("Não há aniversariantes esse mês.\n");
        }
        else{
            if(aniversariantes>1){
                printf("Total = %d aniversariantes\n", aniversariantes);
            }
            if(aniversariantes==1){
                printf("Total = 1 aniversariante\n");
            }
        }
    }
    puts("\n");
}
void Listar_Disciplinas(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], int num_disciplina, int num_professor){
    if(num_disciplina==0){
        puts("LISTA VAZIA");
        puts("\n");
    }
    else{
        int j;
        puts("\n");
        puts("LISTA DE DISCIPLINAS:");
        puts("\n");
        for(int i=0; i<num_disciplina; i++){
            printf("%d - Código: %d \tNome: %s \tSemestre: %d", i+1, Lista_disciplinas[i].codigo, Lista_disciplinas[i].nome, Lista_disciplinas[i].semestre);
            for(j=0; j<num_professor; j++){
                if(Lista_professores[j].matricula == Lista_disciplinas[i].professor){
                    printf("\tProfessor: %s\n", Lista_professores[j].nome);
                    break;
                }
            }
        }
    }
    puts("\n");
}
void Listar_Disciplinas_mais_quarenta(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], int num_disciplina, int num_professor){
    if(num_disciplina==0){
        puts("LISTA VAZIA");
        puts("\n");
    }
    else{
        int j;
        puts("\n");
        puts("LISTA DE DISCIPLINAS COM MAIS DE 40 VAGAS:");
        puts("\n");
        for(int i=0; i<num_disciplina; i++){
            if(limite_aluno_por_disciplina - Lista_disciplinas[i].num_alunos > 40){
                printf("%d - Código: %d \tNome: %s \tSemestre: %d", i+1, Lista_disciplinas[i].codigo, Lista_disciplinas[i].nome, Lista_disciplinas[i].semestre);
                for(j=0; j<num_professor; j++){
                    if(Lista_professores[j].matricula == Lista_disciplinas[i].professor){
                        printf("\tProfessor: %s\n", Lista_professores[j].nome);
                        break;
                    }
                }
            }
        }
    }
    puts("\n");
}
int Matricular_aluno(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_professor, int num_disciplina, int num_aluno){
    if(num_disciplina==0){
        puts("NÃO HÁ DISCIPLINAS CADASTRADAS.");
        puts("\n");

        return MATRICULA_ERRO;
    }
    else if(num_aluno==0){
        puts("NÃO HÁ ALUNOS CADASTRADOS.");
        puts("\n");

        return MATRICULA_ERRO;
    }
    else{
        int j;
        puts("\n");
        marcador_titulo(26);
        puts("***ESCOLHA A DISCIPLINA***");
        marcador_titulo(26);
        puts("\n");

        Listar_Disciplinas(Lista_disciplinas, Lista_professores, num_disciplina, num_professor);

        int opcao_d;
        scanf("%d", &opcao_d);
        getchar();
        if(Lista_disciplinas[opcao_d-1].num_alunos==limite_aluno_por_disciplina){
            puts("\n");
            printf("A disciplina %s não tem mais vagas.\n", Lista_disciplinas[opcao_d].nome);
            puts("\n");
            return MATRICULA_ERRO;
        }
        else if(opcao_d<=num_disciplina+1 && opcao_d>0){
            opcao_d--;
            puts("\n");
            printf("Disciplina escolhida: %s\n", Lista_disciplinas[opcao_d].nome);
            puts("\n");

            int opcao_a;
            do{
                marcador_titulo(57);
                puts("***ESCOLHA UM ALUNO PARA MATRICULAR OU 0 PARA CANCELAR***");
                marcador_titulo(57);
                puts("\n");
                Listar_Alunos(Lista_alunos, num_aluno);
                scanf("%d", &opcao_a);
                getchar();
                if(opcao_a==0) return MATRICULA_ERRO;

                opcao_a--;
                if(opcao_a>num_aluno && opcao_a<0) puts("Aluno inválido.\n\n");
                else{
                    for(int i=0; i<Lista_disciplinas[opcao_d].num_alunos; i++){
                        if(Lista_alunos[opcao_a].matricula==Lista_disciplinas[opcao_d].alunos[i]){
                            puts("Aluno já matriculado nessa disciplina, escolha outro aluno ou 0 para sair.");
                            opcao_a=-1;
                        }
                    }
                }
            } while(opcao_a>num_aluno || opcao_a<0);

            Lista_disciplinas[opcao_d].alunos[Lista_disciplinas[opcao_d].num_alunos]=Lista_alunos[opcao_a].matricula; //insere a matrícula do aluno na relação de alunos da disciplina
            Lista_alunos[opcao_a].disciplinas[Lista_alunos[opcao_a].num_disciplinas]=Lista_disciplinas[opcao_d].codigo; //insere o código da disciplina na relação de disciplinas do aluno
            Lista_disciplinas[opcao_d].num_alunos ++;
            Lista_alunos[opcao_a].num_disciplinas ++;
            printf("Aluno %s matriculado com sucesso na diciplina %s.\n\n", Lista_alunos[opcao_a].nome, Lista_disciplinas[opcao_d].nome);
            return MATRICULA_SUCESSO;
        }
        else{
            puts("Opção inválida\n\n");
            return MATRICULA_ERRO;
        }
    }
}
int Desmatricular_aluno(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], Pessoa Lista_alunos[], int num_professor, int num_disciplina, int num_aluno){
    if(num_disciplina==0){
        puts("NÃO HÁ DISCIPLINAS CADASTRADAS.");
        puts("\n");

        return MATRICULA_ERRO;
    }
    else if(num_aluno==0){
        puts("NÃO HÁ ALUNOS CADASTRADOS.");
        puts("\n");

        return MATRICULA_ERRO;
    }
    else{
        int j;
        puts("\n");
        marcador_titulo(26);
        puts("***ESCOLHA A DISCIPLINA***");
        marcador_titulo(26);
        puts("\n");

        Listar_Disciplinas(Lista_disciplinas, Lista_professores, num_disciplina, num_professor);

        int opcao_d;
        scanf("%d", &opcao_d);
        getchar();
        if(Lista_disciplinas[opcao_d-1].num_alunos==0){
            puts("\n");
            printf("A disciplina %s não tem alunos para serem removidos.\n", Lista_disciplinas[opcao_d].nome);
            puts("\n");
            return MATRICULA_ERRO;
        }
        else if(opcao_d<=num_disciplina+1 && opcao_d>0){
            opcao_d--;
            puts("\n");
            printf("Disciplina escolhida: %s\n", Lista_disciplinas[opcao_d].nome);
            puts("\n");

            int opcao_a;
            do{
                marcador_titulo(54);
                puts("***ESCOLHA UM ALUNO PARA REMOVER OU 0 PARA CANCELAR***");
                marcador_titulo(54);
                puts("\n");

                puts("Alunos:");
                for(int i=0;i<Lista_disciplinas[opcao_d].num_alunos;i++){
                    for(int j=0; j<Lista_disciplinas[opcao_d].num_alunos; j++){
                        if(Lista_alunos[i].matricula == Lista_disciplinas[opcao_d].alunos[j]){
                            printf("\t%d -\tNome: %s\tMatrícula: %d\n", j+1, Lista_alunos[i].nome, Lista_alunos[i].matricula);
                            break;
                        }
                    }
                }
                scanf("%d", &opcao_a);

                if(opcao_a==0) return MATRICULA_ERRO;

                opcao_a--;
                getchar();
                if(opcao_a>num_aluno && opcao_a<0) puts("\nAluno inválido.\n\n");

            } while(opcao_a>num_aluno && opcao_a<0);
            for(int i=opcao_a; i<Lista_disciplinas[opcao_d].num_alunos; i++){
                Lista_disciplinas[opcao_d].alunos[i]=Lista_disciplinas[opcao_d].alunos[i+1];
            }
            for(int i=opcao_d; i<Lista_alunos[opcao_a].num_disciplinas; i++){
                Lista_alunos[opcao_a].disciplinas[i]=Lista_alunos[opcao_a].disciplinas[i+1];
            }
            Lista_disciplinas[opcao_d].num_alunos--;
            Lista_alunos[opcao_a].num_disciplinas--;
            printf("\nAluno %s removido com sucesso da diciplina %s.\n\n", Lista_alunos[opcao_a].nome, Lista_disciplinas[opcao_d].nome);

            return MATRICULA_SUCESSO;
        }
        else{
            puts("Opção inválida\n\n");
            return MATRICULA_ERRO;
        }
    }
}
int Cadastrar_aluno(Pessoa Lista_alunos[], int num_aluno){
    static int matricula=1;
    if(num_aluno<limite_alunos){
        puts("\n");
        marcador_titulo(29);
        puts("*******CADASTRAR ALUNO*******");
        marcador_titulo(29);
        puts("\n");

        puts("DIGITE O NOME:");

        recebe_string(Lista_alunos[num_aluno].nome, 100);
        if(Lista_alunos[num_aluno].nome[0] > 96 && Lista_alunos[num_aluno].nome[0] < 123){
            Lista_alunos[num_aluno].nome[0] -= 32;
        }

        Lista_alunos[num_aluno].data_nas = recebe_data(&Lista_alunos[num_aluno].data_nascimento[0], &Lista_alunos[num_aluno].data_nascimento[1], &Lista_alunos[num_aluno].data_nascimento[2]);


        do{

            puts("\n");
            puts("DIGITE O CPF:");
            scanf("%lld",&Lista_alunos[num_aluno].cpf);
            getchar();
        } while(validar_cpf(Lista_alunos[num_aluno].cpf)==CPF_INVALIDO);

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
        Lista_alunos[num_aluno].num_disciplinas = 0;
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
int Cadastrar_professor(Pessoa Lista_professores[], int num_professor){
    static int matricula_p=1;
    if(num_professor<limite_professores){
        puts("\n");
        marcador_titulo(33);
        puts("*******CADASTRAR PROFESSOR*******");
        marcador_titulo(33);
        puts("\n");

        puts("DIGITE O NOME:");

        recebe_string(Lista_professores[num_professor].nome, 100);

        Lista_professores[num_professor].data_nas = recebe_data(&Lista_professores[num_professor].data_nascimento[0], &Lista_professores[num_professor].data_nascimento[1], &Lista_professores[num_professor].data_nascimento[2]);

        do{

            puts("\n");
            puts("DIGITE O CPF:");
            scanf("%lld",&Lista_professores[num_professor].cpf);
            getchar();
        } while(validar_cpf(Lista_professores[num_professor].cpf)==CPF_INVALIDO);

        do{
            puts("\n");
            puts("DIGITE O GÊNERO (M - MASCULINO | F - FEMININO):");
            scanf("%c", &Lista_professores[num_professor].genero);
            getchar();

            if(Lista_professores[num_professor].genero == 'm' || Lista_professores[num_professor].genero == 'f')
                Lista_professores[num_professor].genero -= 32;

        } while(Lista_professores[num_professor].genero != 'M' && Lista_professores[num_professor].genero != 'F');

        Lista_professores[num_professor].aluno_ou_professor = 'P';
        Lista_professores[num_professor].matricula = matricula_p;
        Lista_professores[num_professor].num_disciplinas = 0;
        matricula_p++;
        return CADASTRO_SUCESSO;
    }
    else{
        puts("\n");
        marcador_titulo(45);
        puts("**NÃO É POSSÍVEL CADASTRAR MAIS PROFESSORES**");
        marcador_titulo(45);
        puts("\n");
        return CADASTRO_ERRO;
    }
}
int Cadastrar_disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], int num_disciplina, int num_professor){
    static int codigo_d=1;
    int opcao;
    if(num_professor==0){
        marcador_titulo(77);
        puts("**NÃO É POSSÍVEL CADASTRAR UMA DISCIPLINA SE NÃO HÁ PROFESSORES CADASTRADOS**");
        marcador_titulo(77);
        return CADASTRO_ERRO;
    }
    if(num_disciplina<limite_disciplinas){
        puts("\n");
        marcador_titulo(34);
        puts("*******CADASTRAR DISCIPLINA*******");
        marcador_titulo(34);
        puts("\n");

        puts("DIGITE O NOME DA DISCIPLINA:");
        recebe_string(Lista_disciplinas[num_disciplina].nome, 100);
        puts("\n");

        puts("DIGITE O SEMESTRE:");
        scanf("%d",&Lista_disciplinas[num_disciplina].semestre);
        getchar();

        do{
            puts("CADASTRE UM PROFESSOR PARA ESSA DISCIPLINA:");
            Listar_Professores(Lista_professores, num_professor);
            scanf("%d", &opcao);
            opcao--;
            getchar();
        }
        while(opcao>num_professor+1 || opcao<0);

        Lista_disciplinas[num_disciplina].professor = Lista_professores[opcao].matricula;
        Lista_professores[opcao].disciplinas[Lista_professores[opcao].num_disciplinas]=Lista_disciplinas[num_disciplina].codigo;
        Lista_professores[opcao].num_disciplinas++;
        Lista_disciplinas[num_disciplina].num_alunos = 0;
        Lista_disciplinas[num_disciplina].codigo = codigo_d;
        codigo_d++;
        return CADASTRO_SUCESSO;
    }
    else{
        puts("\n");
        marcador_titulo(45);
        puts("**NÃO É POSSÍVEL CADASTRAR MAIS DISCIPLINAS**");
        marcador_titulo(45);
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
        printf("NOME ATUAL: %s\n\n", Lista_alunos[opcao].nome);
        puts("DIGITE O NOME (REPITA CASO JÁ ESTEJA CORRETO):");
        recebe_string(Lista_alunos[opcao].nome, 100);
        recebe_data(&Lista_alunos[opcao].data_nascimento[0], &Lista_alunos[opcao].data_nascimento[1], &Lista_alunos[opcao].data_nascimento[2]);
        do{
            puts("\n");
            printf("CPF ATUAL: %011lld\n\n", Lista_alunos[opcao].cpf);
            puts("DIGITE O NOVO CPF (REPITA CASO JÁ ESTEJA CORRETO):");
            scanf("%lld",&Lista_alunos[opcao].cpf);
            getchar();
        } while(validar_cpf(Lista_alunos[opcao].cpf)==CPF_INVALIDO);

        do{
            puts("\n");
            printf("GÊNERO ATUAL: %c\n\n", Lista_alunos[opcao].genero);
            puts("DIGITE O GÊNERO (M - MASCULINO | F - FEMININO) (REPITA CASO JÁ ESTEJA CORRETO):");
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
void Alterar_professor(Pessoa Lista_professores[], int num_professor){
    marcador_titulo(57);
    puts("**ESCOLHA O PROFESSOR CUJO CADASTRO VOCÊ QUER ATUALIZAR**");
    marcador_titulo(57);
    Listar_Professores(Lista_professores, num_professor);
    puts("\n");
    int opcao;
    scanf("%d", &opcao);
    getchar();
    if(opcao<=num_professor+1 && opcao>0){
        opcao--;
        puts("\n");
        printf("NOME ATUAL: %s\n\n", Lista_professores[opcao].nome);
        puts("DIGITE O NOVO NOME (REPITA CASO JÁ ESTEJA CORRETO):");
        recebe_string(Lista_professores[opcao].nome, 100);
        recebe_data(&Lista_professores[opcao].data_nascimento[0], &Lista_professores[opcao].data_nascimento[1], &Lista_professores[opcao].data_nascimento[2]);
        do{
            puts("\n");
            printf("CPF ATUAL: %011lld\n\n", Lista_professores[opcao].cpf);
            puts("DIGITE O NOVO CPF (REPITA CASO JÁ ESTEJA CORRETO):");
            scanf("%lld",&Lista_professores[opcao].cpf);
            getchar();
        } while(validar_cpf(Lista_professores[opcao].cpf)==CPF_INVALIDO);

        do{
            puts("\n");
            printf("GÊNERO ATUAL: %c\n\n", Lista_professores[opcao].genero);
            puts("DIGITE O GÊNERO (M - MASCULINO | F - FEMININO) (REPITA CASO JÁ ESTEJA CORRETO):");
            scanf("%c", &Lista_professores[opcao].genero);
            getchar();

            if(Lista_professores[opcao].genero == 'm' || Lista_professores[opcao].genero == 'f')
            Lista_professores[opcao].genero -= 32;

        } while(Lista_professores[opcao].genero != 'M' && Lista_professores[opcao].genero != 'F');
    }
    else{
        marcador_titulo(21);
        puts("**OPÇÃO NÃO ENCONTRADA**");
        marcador_titulo(21);
    }

}
void Alterar_disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[], int num_disciplina, int num_professor){
    marcador_titulo(58);
    puts("**ESCOLHA A DICSIPLINA CUJO CADASTRO VOCÊ QUER ATUALIZAR**");
    marcador_titulo(58);
    Listar_Disciplinas(Lista_disciplinas, Lista_professores, num_disciplina, num_professor);
    puts("\n");
    int opcao;
    scanf("%d", &opcao);
    getchar();
    if(opcao<=num_disciplina+1 && opcao>0){
        opcao--;
        puts("\n");
        printf("NOME ATUAL DA DISCIPLINA: %s\n\n", Lista_disciplinas[opcao].nome);
        puts("DIGITE O NOVO NOME (REPITA CASO JÁ ESTEJA CORRETO):");
        recebe_string(Lista_disciplinas[opcao].nome, 100);
        int op_prof;
        do{
            printf("PROFESSOR ATUAL: ");
            for(int i=0; i<num_professor; i++){
                if(Lista_disciplinas[opcao].professor==Lista_professores[i].matricula){
                    printf("%s\n\n", Lista_professores[i].nome);
                    break;
                }
            }
            puts("ESCOLHA O NOVO PROFESSOR PARA ESSA DISCIPLINA:");
            Listar_Professores(Lista_professores, num_professor);
            scanf("%d", &op_prof);
            getchar();
            op_prof--;

        }while(op_prof>num_professor+1 || op_prof<0);

        Lista_disciplinas[num_disciplina].professor = Lista_professores[op_prof].matricula;
        Lista_professores[op_prof].disciplinas[Lista_professores[op_prof].num_disciplinas]=Lista_disciplinas[num_disciplina].codigo;
        puts("\n");

        printf("SEMESTRE ATUAL DA DISCIPLINA: %d\n\n", Lista_disciplinas[opcao].semestre);
        puts("DIGITE O NOVO SEMESTRE (REPITA CASO JÁ ESTEJA CORRETO):");
        scanf("%d", &Lista_disciplinas[opcao].semestre);
        getchar();
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
int Deletar_Professor(Pessoa Lista_professores[], int num_professor){
    Listar_Professores(Lista_professores, num_professor);

    int opcao;
    do{
        marcador_titulo(83);
        puts("**DIGITE O NÚMERO REFERENTE AO PROFESSOR QUE VOCÊ QUER DELETAR OU 0 PARA CANCELAR**");
        marcador_titulo(83);
        scanf("%d", &opcao);
        getchar();
    }while(opcao > num_professor+1 || opcao < 0);
    if(opcao==0) return DELETADO_ERRO;
    else{
        for(int i=opcao; i<num_professor; i++){
            Lista_professores[i-1] = Lista_professores[i];
        }
        return DELETADO_SUCESSO;
    }
}
int Deletar_Disciplina(Disciplina Lista_disciplinas[], Pessoa Lista_professores[],Pessoa Lista_alunos[], int num_disciplina, int num_professor, int num_aluno){
    //Finzalizar essa função
    int opcao;
    do{
        marcador_titulo(83);
        puts("**ESCOLHA A OPÇÃO REFERENTE À DISCIPLINA QUE VOCÊ QUER DELETAR OU 0 PARA CANCELAR**");
        marcador_titulo(83);
        scanf("%d", &opcao);
        getchar();
    }while(opcao > num_professor+1 || opcao < 0);
    if(opcao==0) return DELETADO_ERRO;
    else{
        for(int i=opcao; i<num_professor; i++){
            Lista_professores[i-1] = Lista_professores[i];
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

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define NUM_CHAR 11
#define NUM_VIAGEM 50
#define NUM_COD 4

//ESTRUTURA
 struct Viagem {
    int codigo;
    char cidade_origem[NUM_CHAR];
    char cidade_destino[NUM_CHAR];
    int escalas;
};

//PROTÓTIPOS
void lista_viagens(struct Viagem V[], int quant_voo);
int inclusao_voo(struct Viagem V[]);
void alteracao_info_voo(struct Viagem V[], int quant_voo);
int exclusao_voo(struct Viagem V[], int quant_voo);
// void quant_voo_origem();
// void menor_quant_escala_voo();

int main(){
    setlocale(LC_ALL, "Portuguese");
    struct Viagem viagem[NUM_VIAGEM];
    int resposta = 0, n_viagem = 0;

    do{
        system("cls");
        printf("VERMELHO LINHAS AÉREAS\n");
        printf("\nPor favor, selecionar as opções abaixo:\n");
        printf("1.Incluir voos.\n");
        printf("2.Alterar as informações do voo.\n");
        printf("3.Apagar voo.\n");
        printf("4.Quantidade de voos.\n");
        printf("5.Quantidade de voos com menor número de escala .\n");
        printf("0.Sair\n");
        scanf("%d",&resposta);

        switch (resposta) {
            case 1:
                system("cls");
                n_viagem = inclusao_voo(viagem);
                // n_viagem = inclusao_voo(viagem);
                break;
            case 2:
                system("cls");
                alteracao_info_voo(viagem, n_viagem);
                break;
            case 3:
                system("cls");
                //atualiza o n_viagem com a quantidade de voo não excluido
                n_viagem = exclusao_voo(viagem, n_viagem);
                break;
            case 4:
                //lista_viagens(viagem, n_viagem);
                //quant_voo_origem();
                break;
            // case 5:
            //     menor_quant_escala_voo();
            //     break;
            case 0:
                return 0;
            default:
                printf("Opção inválida, digite novamente.\n");
                break;
        }

    }while(resposta != 0);
}

int inclusao_voo(struct Viagem V[]){
    int quant_voo = 0, contador =0, i = 0;

    printf("INCLUSÃO DE VIAGENS\n");
    printf("\nDeseja incluir quantos voos?");
    while(scanf("%d",&quant_voo) != ((quant_voo>0) && (quant_voo<50))){
        printf("Entrada inválida. Digite um valor entre 1 e 49: ");
    }
    contador = quant_voo;

    do{
        printf("\nVIAGEM %d:",i+1);
        printf("\nDigite o código da viagem: ");
        while(scanf("%d",&V[i].codigo) != (V[i].codigo >=1000 && V[i].codigo <= 9999)){
            printf("O número não possui 4 dígitos, digite novamente.\n");
        }
        printf("\nDigite a cidade de origem: ");
        getchar();
        gets(V[i].cidade_origem);
        printf("\nDigite a cidade de destino: ");
        gets(V[i].cidade_destino);
        printf("\nDigite a quantidade de paradas: ");
        scanf("%d", &V[i].escalas);
        printf("\n");

        contador--;
        i++;
    }while(contador != 0);
    return quant_voo;
}

void alteracao_info_voo(struct Viagem V[], int quant_voo){
    int resposta = 0, contador = 1, flag = 0, a = 1, posicao_cod = 0;
    char resposta2 = 0;
    do{
        printf("VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<quant_voo; i++){
            if(V[i].codigo != 0){
                printf("\n%d- Viagem(%d)", a, V[i].codigo);
                a++;
            }
        }
        printf("\n%d- Sair;\n",quant_voo+1);
        printf("\nSelecione o código da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == quant_voo+1))){
                printf("Código inválido, digite novamente.\n");
        }
        for(int i = 0; i<quant_voo; i++){
            if(resposta == V[i].codigo) posicao_cod = i; //variavel recebe a posição referente o código digitado
        }
        if(resposta == quant_voo+1) return; //atualiza o flag para sair dessa funçao

        do{
            printf("\nVIAGEM %d:",posicao_cod+1);
            printf("\nDigite o código da viagem: ");
            while(scanf("%d",&V[posicao_cod].codigo) != (V[posicao_cod].codigo >=1000 && V[posicao_cod].codigo <= 9999)){
                printf("Código inválido, digite novamente.\n");
            }
            printf("\nDigite a cidade de origem: ");
            getchar();
            gets(V[posicao_cod].cidade_origem);
            printf("\nDigite a cidade de destino: ");
            gets(V[posicao_cod].cidade_destino);
            printf("\nDigite a quantidade de paradas: ");
            scanf("%d", &V[posicao_cod].escalas);
            printf("\n");

            contador--;
        }while(contador != 0);
            if(quant_voo >= 0){
                printf("\nDeseja alterar mais viagens? ");
                getchar();
                while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
                    printf("\nResposta inválida, digite novamente");
                }
            }
            if(resposta2 == 'n' || resposta2 == 'N') flag = 1; //atualiza o flag para sair dessa funçao
    }while (flag != 1);
}

int exclusao_voo(struct Viagem V[], int quant_voo){
    int resposta = 0, flag = 0, contador_v_disp = 0, a = 1, posicao_cod = 0;
    char resposta2 = 0;
    do{
        printf("EXCLUSÃO DAS VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<quant_voo; i++){
            if(V[i].codigo != 0){
                printf("\n%d- Viagem(%d)", a, V[i].codigo);
                contador_v_disp++; //calcula a quantidade de viagens nao apagadas/zeradas
                a++;
            }
        }
        //verifica se algumas viagens foram apagadas e atualiza a quantidade de voos nao apagados
        if (contador_v_disp != quant_voo) quant_voo = quant_voo - contador_v_disp;
        printf("\n%d- Sair;\n",quant_voo+1);
        printf("\nSelecione o código da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == quant_voo+1))){
                printf("Código inválido, digite novamente.\n");
        }
        for(int i = 0; i<quant_voo; i++){
            if(resposta == V[i].codigo) posicao_cod = i; //variavel recebe a posição referente o código digitado
        }
        if(resposta == quant_voo+1) break;//flag = 1; //atualiza o flag para sair dessa funçao

        //zera as informações da posição ESCOLHIDA do vetor de struct
        memset(&V[posicao_cod], 0, sizeof(struct Viagem));

        if(quant_voo > 1){
            printf("\nDeseja excluir mais viagens? ");
            getchar();
            while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
                printf("\nResposta inválida, digite novamente");
            }
        }
            if(resposta2 == 'n' || resposta2 == 'N') flag = 1; //atualiza o flag para sair dessa funçao
    }while (flag != 1);
    return quant_voo;
}

//void lista_viagens (struct Viagem V[], int quant_voo){
//    for(int i = 0; i<quant_voo; i++){
//        if(V[i].codigo != 0){
//            printf("\nViagem %d(%d)", i+1, V[i].codigo);
//        }
//    }
//}


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

//PROT�TIPOS
int inclusao_voo(struct Viagem V[]);
void alteracao_info_voo(struct Viagem V[], int quant_voo);
// void exclusao_voo();
// void quant_voo_origem();
// void menor_quant_escala_voo();

int main(){
    setlocale(LC_ALL, "Portuguese");
    struct Viagem viagem[NUM_VIAGEM];
    int resposta = 0, n_viagem = 0;
    // char resposta = 0;

    do{
        // system("cls");
        printf("VERMELHO LINHAS A�REAS\n");
        printf("Por favor, selecionar as op��es abaixo:\n");
        printf("\n1.Incluir voos.\n");
        printf("2.Alterar as informa��es do voo.\n");
        printf("3.Apagar voo.\n");
        printf("4.Quantidade de voos da cidade de origem.\n");
        printf("5.Quantidade de voos com menor n�mero de escala da cidade de origem e destino.\n");
        printf("0.Sair\n");
        scanf("%d",&resposta);

        switch (resposta) {
            case 1:
                // printf("\nPassou");
                n_viagem=inclusao_voo(viagem);
                // n_viagem = inclusao_voo(viagem);
                break;
            case 2:
                for(int i = 0; i<n_viagem; i++){
                    printf("\nVIAGEM %d:",i+1);
                    printf("\nDigite o c�digo da viagem: %d", viagem[i].codigo);
                    printf("\nDigite a cidade de origem: %s", viagem[i].cidade_origem);
                    printf("\nDigite a cidade de destino: %s", viagem[i].cidade_destino);
                    printf("\nDigite a quantidade de paradas: %d\n", viagem[i].escalas);
                }

                alteracao_info_voo(viagem, n_viagem);

                for(int i = 0; i<n_viagem; i++){
                    printf("\nVIAGEM %d:",i+1);
                    printf("\nDigite o c�digo da viagem: %d", viagem[i].codigo);
                    printf("\nDigite a cidade de origem: %s", viagem[i].cidade_origem);
                    printf("\nDigite a cidade de destino: %s", viagem[i].cidade_destino);
                    printf("\nDigite a quantidade de paradas: %d\n", viagem[i].escalas);
                }

                break;
            // case 3:
            //     exclusao_voo();
            //     break;
            // case 4:
            //     quant_voo_origem();
            //     break;
            // case 5:
            //     menor_quant_escala_voo();
            //     break;
            case 0:
                return 0;
            default:
                printf("Op��o inv�lida, digite novamente.\n");
                break;
        }

    }while(resposta != 0);

}

int inclusao_voo(struct Viagem V[]){
    int quant_voo = 0, contador =0, i = 0;

    printf("\nDeseja incluir quantos voos?");
    while(scanf("%d",&quant_voo) != ((quant_voo>0) && (quant_voo<50))){
        printf("Entrada inv�lida. Digite um valor entre 1 e 49: ");
    };
    contador = quant_voo;

    do{
        printf("\nVIAGEM %d:",i+1);
        printf("\nDigite o c�digo da viagem: ");
        while(scanf("%d",&V[i].codigo) != (V[i].codigo >=1000 && V[i].codigo <= 9999)){
            printf("O n�mero n�o possui 4 d�gitos, digite novamente.\n");
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
    }while(contador > 0);
    return quant_voo;
}

void alteracao_info_voo(struct Viagem V[], int quant_voo){
    int resposta = 0, contador = 1, flag = 0;
    char resposta2 = 0;
    do{
        printf("VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<quant_voo; i++){
            printf("%d- Viagem %d;\n",i+1,i+1);
        }
        printf("\nQual das viagens deseja alterar: ");
        while(scanf("%d",&resposta) != (resposta>0 && resposta<=quant_voo)){
            printf("N�mero inv�lido, digite novamente.\n");
        }

        do{
            printf("\nVIAGEM %d:",resposta);
            printf("\nDigite o c�digo da viagem: ");
            while(scanf("%d",&V[resposta].codigo) != (V[resposta].codigo >=1000 && V[resposta].codigo <= 9999)){
                printf("Op��o inv�lida, digite novamente.\n");
            }
            printf("\nDigite a cidade de origem: ");
            getchar();
            gets(V[resposta].cidade_origem);
            printf("\nDigite a cidade de destino: ");
            gets(V[resposta].cidade_destino);
            printf("\nDigite a quantidade de paradas: ");
            scanf("%d", &V[resposta].escalas);
            printf("\n");

            contador--;
        }while(contador != 0);
            if(quant_voo > 1){
                printf("\nDeseja alterar mais viagens? ");
                getchar();
                while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
                    printf("\nResposta inv�lida, digite novamente");
                }
            }
            flag = 1;
    }while (resposta2 != (('n' || 'N') && flag != 1));
}

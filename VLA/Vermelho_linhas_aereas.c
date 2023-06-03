#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "VLA.h"
#include <ctype.h>





int main(){
    setlocale(LC_ALL, "Portuguese");
    Viagem viagem[NUM_VIAGEM];
    int resposta = 0, n_viagem = 0;

    do{
        system("cls");
        printf("VERMELHO LINHAS A�REAS\n");
        printf("\nPor favor, selecionar as op��es abaixo:\n");
        printf("1.Incluir voos.\n");
        printf("2.Alterar as informa��es do voo.\n");
        printf("3.Apagar voo.\n");
        printf("4.pesquisar voos .\n");
        printf("5.Quantidade de voos com menor n�mero de escala .\n");
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
                //atualiza o n_viagem com a quantidade de voo n�o excluido
                n_viagem = exclusao_voo(viagem, n_viagem);
                break;
            case 4:
                lista_viagens(viagem, n_viagem);
                //quant_voo_origem();
                break;
            case 5:
                 menor_quant_escala_voo(viagem, n_viagem);
                 break;
            case 0:
                return 0;
            default:
                printf("Op��o inv�lida, digite novamente.\n");
                break;
        }

    }while(resposta != 0);
}



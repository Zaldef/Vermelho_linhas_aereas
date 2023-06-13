#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VLA.h"
#include <ctype.h>


int main(){
    Viagem viagem[NUM_VIAGEM];
    int n_viagem = 0,exclusao_viagem = 0, valor_funcao_excluir = 0, resposta = 0;
    do{
        printf("                                               VERMELHO LINHAS AEREAS\n");
        printf("                        -------------------------------------------------------------------\n");
        printf("                                                    Bem vindo                            \n");
        printf("                        ------------------------------------------------------------------- \n");
        printf("                                      Por favor, selecionar as opcoes abaixo:\n");
        printf("                                      _________________________________________\n\n");
        printf("                                          1-Incluir voos.\n\n");
        printf("                                          2-Alterar as informacoes do voo.\n\n");
        printf("                                          3-Apagar voo.\n\n");
        printf("                                          4-Pesquisar voos (por origem).\n\n");
        printf("                                          5-Pesquisar voos (por menor escala).\n\n");
        printf("                                          0-Sair\n");
        printf("                                     __________________________________________\n\n");
        scanf("%d",&resposta);
        switch (resposta) {
            case 1:
                system("cls");
                n_viagem += inclusao_voo(viagem, n_viagem, exclusao_viagem);
                system("cls");
                break;
            case 2:
                system("cls");
                alteracao_info_voo(viagem, n_viagem, exclusao_viagem);
                system("cls");
                break;
            case 3:
                system("cls");
                if((valor_funcao_excluir = exclusao_voo(viagem, n_viagem, exclusao_viagem))>0){
                    exclusao_viagem += valor_funcao_excluir;
                    n_viagem -= valor_funcao_excluir;
                }
                else valor_funcao_excluir = 0;
                system("cls");
                break;
            case 4:
                system("cls");
                lista_viagens(viagem, n_viagem);
                system("cls");
                break;
            case 5:
                 system("cls");
                 menor_quant_escala_voo(viagem, n_viagem);
                 system("cls");
                 break;
            case 0:
                return 0;
            default:
                system("cls");
                printf("                                           Opcao invalida, digite novamente.\n                        -------------------------------------------------------------------\n");
                break;
        }
    }while(resposta != 0);
}


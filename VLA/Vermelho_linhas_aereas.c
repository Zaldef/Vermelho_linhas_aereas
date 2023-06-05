#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "VLA.h"
#include <ctype.h>


int main(){
    setlocale(LC_ALL, "Portuguese");
    Viagem viagem[NUM_VIAGEM];
    int resposta = 0, n_viagem = 0,exclusao_viagem = 0, valor_funcao_excluir = 0;

    do{
        system("cls");
        printf("                                               VERMELHO LINHAS AEREAS\n");
        printf("                        -------------------------------------------------------------------\n");
        printf("                                                    Bem vindo                            \n");
        printf("                        ------------------------------------------------------------------- \n");
        printf("                                      Por favor, selecionar as opcoes abaixo:\n");
        printf("                                      _________________________________________\n\n");
        printf("                                          1.Incluir voos.\n\n");
        printf("                                          2.Alterar as informacoes do voo.\n\n");
        printf("                                          3.Apagar voo.\n\n");
        printf("                                          4.pesquisar voos (por origem).\n\n");
        printf("                                          5.Pesquisar voos (por menor escala).\n\n");
        printf("                                          0.Sair\n");
         printf("                                     __________________________________________\n\n");

        scanf("%d",&resposta);

        switch (resposta) {
            case 1:
                system("cls");
                n_viagem += inclusao_voo(viagem, n_viagem, exclusao_viagem);
                break;
            case 2:
                system("cls");
                alteracao_info_voo(viagem, n_viagem, exclusao_viagem);
                break;
            case 3:
                system("cls");

                //armazena o numero de viagens apagadas na var exclusao_viagem
                if((valor_funcao_excluir = exclusao_voo(viagem, n_viagem, exclusao_viagem))>0){
                    exclusao_viagem += valor_funcao_excluir;
                    n_viagem -= valor_funcao_excluir;
                }
                else valor_funcao_excluir = 0;
                //atualiza o n_viagem com a quantidade de voos não excluidos
                break;
            case 4:
                system("cls");
                lista_viagens(viagem, n_viagem);
                //quant_voo_origem();
                break;
            case 5:
                 system("cls");
                 menor_quant_escala_voo(viagem, n_viagem);
                 break;
            case 0:
                return 0;
            default:
                printf("Opção inválida, digite novamente.\n");
                break;
        }

    }while(resposta != 0);
}


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

int inclusao_voo(struct Viagem V[], int quant_voo, int n_voo_del){
    //PRECISO ARRUMAR ESSA INCLUSÃO
    int resp_quant_voo = 0, max_viagem = 0, quant_tl_voo_e_voo_del = 0, contador_posicao = 0, a = 0;

    //verifica a quantidade de voos
    max_viagem = NUM_VIAGEM - quant_voo;

    printf("INCLUSÃO DE VIAGENS\n");
    printf("\nDeseja incluir quantos voos?");
    while(scanf("%d",&resp_quant_voo) != ((resp_quant_voo>0) && (resp_quant_voo<max_viagem))){
        printf("Entrada inválida. Digite um valor entre 1 à %d: ", max_viagem);
    }
    // tenho que fazer uma variavel para receber a quantidade de voos existentes e "deletados" para a partir dele referenciar a posição
    if(quant_voo>0 && n_voo_del>0){
        quant_tl_voo_e_voo_del = (quant_voo+n_voo_del);
        contador_posicao = resp_quant_voo;
        a = quant_tl_voo_e_voo_del;
    }
    else if(quant_voo>0){
        quant_tl_voo_e_voo_del += quant_voo;
        contador_posicao = resp_quant_voo;
        a = quant_tl_voo_e_voo_del;
    }
    else if(quant_voo==0){
        contador_posicao = resp_quant_voo;
    }
    do{
        printf("\nVIAGEM %d:",a+1);
        printf("\nDigite o código da viagem: ");
        while(scanf("%d",&V[a].codigo) != (V[a].codigo >=1000 && V[a].codigo <= 9999)){
            printf("O número não possui 4 dígitos, digite novamente.\n");
        }
        printf("\nDigite a cidade de origem: ");
        getchar();
        gets(V[a].cidade_origem);
        printf("\nDigite a cidade de destino: ");
        gets(V[a].cidade_destino);
        printf("\nDigite a quantidade de paradas: ");
        scanf("%d", &V[a].escalas);
        printf("\n");
        a++;
        contador_posicao--;
    }while(contador_posicao != 0);
    return resp_quant_voo;
}

void alteracao_info_voo(struct Viagem V[], int quant_voo, int n_voo_del){
    int resposta = 0, contador = 1, flag = 0, a = 1, posicao_cod = 0, quant_tl_voo_e_voo_del = 0, contador_posicao = 0;
    char resposta2 = 0;
    do{
        // tenho que fazer uma variavel para receber a quantidade de voos existentes e "deletados" para a partir dele referenciar a posição
        if((quant_voo>0 && n_voo_del>0) || quant_voo>0){
            quant_tl_voo_e_voo_del += (quant_voo+n_voo_del);
            contador_posicao = quant_tl_voo_e_voo_del;
        }
        printf("VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<contador_posicao; i++){
            if(V[i].codigo != 0){
                //if((quant_voo>0 && n_voo_del>0) || quant_voo>0) i = quant_tl_voo_e_voo_del;
                printf("\n%d- Viagem(%d)", a, V[i].codigo);
                a++;
            }
        }
        printf("\n%d- Sair;\n",a);
        printf("\nSelecione o código da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == a))){
                printf("Código inválido, digite novamente.\n");
        }
        for(int i = 0; i<quant_tl_voo_e_voo_del; i++){
            if(resposta == V[i].codigo) posicao_cod = i; //variavel recebe a posição referente o código digitado
        }
        if(resposta == a) return; //atualiza o flag para sair dessa funçao

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

int exclusao_voo(struct Viagem V[], int quant_voo, int n_voo_del){
    int resposta = 0, flag = 0, contador_v_disp = 0, a = 0, posicao_cod = 0, viagems_excluidas = 0, quant_tl_voo_e_voo_del = 0, flag_encerrar = 0, contador_posicao = 0;
    char resposta2 = 0;
    do{
        // tenho que fazer uma variavel para receber a quantidade de voos existentes e "deletados" para a partir dele referenciar a posição
        if((quant_voo>0 && n_voo_del>0) || quant_voo>0){
            quant_tl_voo_e_voo_del += (quant_voo+n_voo_del);
            contador_posicao = quant_tl_voo_e_voo_del;
        }
        printf("LISTA DAS VIAGENS CADASTRADAS:\n");
        /*printf("\nQUANTIDADE DE NUMEROS DE VOO: %d\n", quant_voo);
        printf("\nQUANTIDADE DE NUMEROS DE VOO EXCLUIDOS: %d\n", viagems_excluidas);
        printf("\nQUANTIDADE TOTAL DE VOOS EXCLUIDOS E NAO EXCLUIDOS: %d\n", quant_tl_voo_e_voo_del);
        */
        //PRIMEIRA VERIFICAÇÃO--------------------------------------------------------------------------------------------------
        for(int i = 0; i<contador_posicao; i++){
            if(V[i].codigo != 0){
                //if((quant_voo>0 && n_voo_del>0) || quant_voo>0) i = contador_posicao;
                contador_v_disp++; //calcula a quantidade de viagens nao apagadas/zeradas
                a++;
                printf("\n%d- Viagem(%d)", a, V[i].codigo);
            }
        }
        //verifica se algumas viagens foram apagadas e atualiza a variável viagens_excluidas com a quantidade de viagens apagadas
        if (contador_v_disp == quant_voo) viagems_excluidas = 0; //quant_voo - contador_v_disp;
        else if (contador_v_disp<quant_voo)viagems_excluidas = quant_voo - contador_v_disp;
        //-----------------------------------------------------------------------------------------------------------------------
        /*printf("\nQUANTIDADE DE NUMEROS DE VOO: %d\n", quant_voo);
        printf("\nQUANTIDADE DE NUMEROS DE VOO EXCLUIDOS: %d\n", viagems_excluidas);
        printf("\nQUANTIDADE TOTAL DE VOOS EXCLUIDOS E NAO EXCLUIDOS: %d\n", quant_tl_voo_e_voo_del);
        */
        printf("\n%d- Sair;\n",contador_v_disp+1);
        printf("\nSelecione o código da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == contador_v_disp+1))){
                printf("Código inválido, digite novamente.\n");
        }
        if (resposta >=1000 && resposta <= 9999){
            for(int i = 0; i<quant_tl_voo_e_voo_del; i++){
                if(V[i].codigo != 0){
                    if(resposta == V[i].codigo) posicao_cod = i; //variavel recebe a posição referente o código digitado
                }
            }

            //zera as informações da posição ESCOLHIDA do vetor de struct
            memset(&V[posicao_cod], 0, sizeof(struct Viagem));

            // SEGUNDA VERIFICAÇÃO---------------------------------------------------------------------------------------------------
            //reinicia as variáveis que vao ser utilizadas
            contador_v_disp = 0;
            a = 0;

            for(int i = 0; i<contador_posicao; i++){
                if(V[i].codigo != 0){
                    contador_v_disp++; //calcula a quantidade de viagens nao apagadas/zeradas
                    a++;
                }
            }
            //verifica se algumas viagens foram apagadas e atualiza a variável viagens_excluidas com a quantidade de viagens apagadas
            if (contador_v_disp == quant_voo) viagems_excluidas = 0; //quant_voo - contador_v_disp;
            else if (contador_v_disp<quant_voo)viagems_excluidas = quant_voo - contador_v_disp;

            //acaba a verificação
            flag_encerrar = 1;
            //-----------------------------------------------------------------------------------------------------------------------
        }else if(resposta == contador_v_disp+1) break;//flag = 1; //sair dessa funçao

        /*printf("\nQUANTIDADE DE NUMEROS DE VOO: %d\n", quant_voo);
        printf("\nQUANTIDADE DE NUMEROS DE VOO EXCLUIDOS: %d\n", viagems_excluidas);
        printf("\nQUANTIDADE TOTAL DE VOOS EXCLUIDOS E NAO EXCLUIDOS: %d\n", quant_tl_voo_e_voo_del);
        */

        if(contador_v_disp > 1){
            printf("\nDeseja excluir mais viagens? ");
            getchar();
            while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
                printf("\nResposta inválida, digite novamente");
            }
        }else flag = 1;
        if(resposta2 == 'n' || resposta2 == 'N') flag = 1; //atualiza o flag para sair dessa funçao
    }while (flag != 1 || flag_encerrar != 1);
    return viagems_excluidas; // retorna os voos apagados
}


#define NUM_CHAR 11
#define NUM_VIAGEM 50
#define NUM_COD 4
#include <ctype.h>
//ESTRUTURA
 typedef struct Viagem {
    char codigo[NUM_COD];
    char cidade_origem[NUM_CHAR];
    char cidade_destino[NUM_CHAR];
    int escalas;
}Viagem;
//PROT�TIPOS
int inclusao_voo(Viagem V[], int quant_voo, int n_voo_del);
void alteracao_info_voo(Viagem V[], int quant_voo, int n_voo_del);
int exclusao_voo(Viagem V[], int quant_voo, int n_voo_del);
void lista_viagens(Viagem V[], int quant_voo);
void up();
void menor_quant_escala_voo(Viagem V[], int quant_voo);
// void quant_voo_origem();


int inclusao_voo(Viagem V[], int quant_voo, int n_voo_del){
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
        getchar();
        while((strlen(gets(V[a].codigo)) != 4)){
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

void alteracao_info_voo(Viagem V[], int quant_voo, int n_voo_del){
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
                printf("%s ---> %s \n",V[i].cidade_origem,V[i].cidade_destino);
                printf(":---------------------------------------");
                printf("\n|Viagem %d: %d ", i+1, V[i].codigo);
                printf("\n|Cidade de Origem: %s ", V[i].cidade_origem);
                printf("\n|Cidade de Destino: %s ", V[i].cidade_destino);
                printf("\n|Paradas: %d ", V[i].escalas);
                printf("\n:--------------------------------------- \n");
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

int exclusao_voo(Viagem V[], int quant_voo, int n_voo_del){
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
                printf("%s ---> %s \n",V[i].cidade_origem,V[i].cidade_destino);
                printf(":---------------------------------------");
                printf("\n|Viagem %d: %d ", i+1, V[i].codigo);
                printf("\n|Cidade de Origem: %s ", V[i].cidade_origem);
                printf("\n|Cidade de Destino: %s ", V[i].cidade_destino);
                printf("\n|Paradas: %d ", V[i].escalas);
                printf("\n:--------------------------------------- \n");
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

void lista_viagens (Viagem V[], int quant_voo){
    char resposta2 = 0;
    int flag = 0;
    char city_name[25];
    printf("digite o nome da cidade de origem:");
    scanf("%s",city_name);
    up(city_name);


do{
   for(int i = 0; i<quant_voo; i++){

    up(V[i].cidade_origem);


       if(!strcmp(V[i].cidade_origem,city_name)){
        printf("%s ---> %s \n",V[i].cidade_origem,V[i].cidade_destino);
        printf(":---------------------------------------");
        printf("\n|Viagem %d: %d ", i+1, V[i].codigo);
        printf("\n|Cidade de Origem: %s ", V[i].cidade_origem);
        printf("\n|Cidade de Destino: %s ", V[i].cidade_destino);
        printf("\n|Paradas: %d ", V[i].escalas);
        printf("\n:--------------------------------------- \n");

       }
   }
 printf("\nSair?(S/N)");
getchar();
while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
printf("\nResposta inv�lida, digite novamente");
}
if(resposta2 == 's' || resposta2 == 'S') flag = 1;
 }while (flag != 1);
}

void menor_quant_escala_voo(Viagem V[], int quant_voo){

    Viagem mesma_viagem_city[NUM_VIAGEM];
    char origem_city[25];
    char destino_city[25];
    char resposta2 = 0;
    int flag = 0;
    int j = 0;
    int menor_escala=0;

    printf("\ndigite a cidade de origem:");
    scanf("%s",origem_city);
    up(origem_city);

    printf("\ndigite a cidade de destino:");
    scanf("%s",destino_city);
    up(destino_city);



    //mesma_viagem_city[j] = V[j];



do{

for (int i = 0; i < quant_voo; i++)
{
 up(V[i].cidade_origem);
 up(V[i].cidade_destino);
     if(!strcmp(V[i].cidade_origem,origem_city ) && !strcmp(V[i].cidade_destino,destino_city ) ) {

            mesma_viagem_city[j] = V[i];
            j++;

     }


}

menor_escala = mesma_viagem_city[0].escalas;

for (int i = 0; i < j; i++)
{
    if(mesma_viagem_city[i].escalas <= menor_escala){
        menor_escala = mesma_viagem_city[i].escalas;
    }
}



for (int i = 0; i < j; i++)
{
    if (mesma_viagem_city[i].escalas == menor_escala)
    {



     printf(":---------------------------------------");
        printf("\n|Viagem %d: %d ", i+1, mesma_viagem_city[i].codigo);
        printf("\n|Cidade de Origem: %s ", mesma_viagem_city[i].cidade_origem);
        printf("\n|Cidade de Destino: %s ", mesma_viagem_city[i].cidade_destino);
        printf("\n|Paradas: %d ", mesma_viagem_city[i].escalas);
        printf("\n:--------------------------------------- \n");
    }
}

 printf("\nSair(S/N)? ");
getchar();
while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
printf("\nResposta inv�lida, digite novamente");
}
if(resposta2 == 's' || resposta2 == 'S') flag = 1;
 }while (flag != 1);
}



//////////dexar string maiuscula///////////////

//funçao criada para fazer a comparação entre cidades
// e corrigir possiveis erros do usuario

void up(char string[]){
    int i =0;

    while (string[i] != '\0' )
    {
        string[i] = toupper(string[i]);

        i++;
    }

}
/////////////////////////////////////////////

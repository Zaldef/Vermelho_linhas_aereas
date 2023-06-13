#define NUM_CHAR 11
#define NUM_VIAGEM 50
#define NUM_COD 4
#include <ctype.h>
//ESTRUTURA
 typedef struct Viagem {
    int codigo;
    char cidade_origem[NUM_CHAR];
    char cidade_destino[NUM_CHAR];
    int escalas;
}Viagem;
//PROT�TIPOS
void alteracao_info_voo(Viagem V[], int quant_voo, int n_voo_del);
int exclusao_voo(Viagem V[], int quant_voo, int n_voo_del);
int inclusao_voo(Viagem V[], int quant_voo, int n_voo_del);
void menor_quant_escala_voo(Viagem V[], int quant_voo);
void lista_viagens(Viagem V[], int quant_voo);
void conversao(int *n,char *n2);
void up();
//FUNÇÕES
int inclusao_voo(Viagem V[], int quant_voo, int n_voo_del){
    int resp_quant_voo = 0, max_viagem = 0, quant_tl_voo_e_voo_del = 0, contador_posicao = 0, a = 0;

    max_viagem = NUM_VIAGEM - quant_voo;

    printf("INCLUSAO DE VIAGENS\n");
    printf("\nDeseja incluir quantos voos?");
    while(scanf("%d",&resp_quant_voo) != ((resp_quant_voo>0) && (resp_quant_voo<max_viagem))){
        printf("Entrada invalida. Digite um valor entre 1 a %d: ", max_viagem);
    }
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
        printf("\nDigite o codigo da viagem: ");
        while(scanf("%d",&V[a].codigo) != (V[a].codigo >=1000 && V[a].codigo <= 9999)){
            printf("O numero não possui 4 digitos, digite novamente.\n");
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
        if((quant_voo>0 && n_voo_del>0) || quant_voo>0){
            quant_tl_voo_e_voo_del += (quant_voo+n_voo_del);
            contador_posicao = quant_tl_voo_e_voo_del;
        }
        printf("VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<contador_posicao; i++){
            if(V[i].codigo != 0){
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
        printf("\nSelecione o codigo da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == a))){
                printf("Codigo invalido, digite novamente.\n");
        }
        for(int i = 0; i<quant_tl_voo_e_voo_del; i++){
            if(resposta == V[i].codigo) posicao_cod = i;
        }
        if(resposta == a) return;
        do{
            printf("\nVIAGEM %d:",posicao_cod+1);
            printf("\nDigite o codigo da viagem: ");
            while(scanf("%d",&V[posicao_cod].codigo) != (V[posicao_cod].codigo >=1000 && V[posicao_cod].codigo <= 9999)){
                printf("Codigo invalido, digite novamente.\n");
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
                printf("\nResposta invalida, digite novamente");
            }
        }
        if(resposta2 == 'n' || resposta2 == 'N') flag = 1;
    }while (flag != 1);
}

int exclusao_voo(Viagem V[], int quant_voo, int n_voo_del){
    int resposta = 0, flag = 0, contador_v_disp = 0, a = 0, posicao_cod = 0, viagems_excluidas = 0, quant_tl_voo_e_voo_del = 0, flag_encerrar = 0, contador_posicao = 0;
    char resposta2 = 0;
    do{
        if((quant_voo>0 && n_voo_del>0) || quant_voo>0){
            quant_tl_voo_e_voo_del += (quant_voo+n_voo_del);
            contador_posicao = quant_tl_voo_e_voo_del;
        }
        printf("LISTA DAS VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<contador_posicao; i++){
            if(V[i].codigo != 0){
                contador_v_disp++;
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
        if (contador_v_disp == quant_voo) viagems_excluidas = 0;
        else if (contador_v_disp<quant_voo)viagems_excluidas = quant_voo - contador_v_disp;
        printf("\n%d- Sair;\n",contador_v_disp+1);
        printf("\nSelecione o codigo da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == contador_v_disp+1))){
                printf("Codigo invalido, digite novamente.\n");
        }
        if (resposta >=1000 && resposta <= 9999){
            for(int i = 0; i<quant_tl_voo_e_voo_del; i++){
                if(V[i].codigo != 0){
                    if(resposta == V[i].codigo) posicao_cod = i;
                }
            }
            memset(&V[posicao_cod], 0, sizeof(struct Viagem));
            contador_v_disp = 0;
            a = 0;
            for(int i = 0; i<contador_posicao; i++){
                if(V[i].codigo != 0){
                    contador_v_disp++;
                    a++;
                }
            }
            if (contador_v_disp == quant_voo) viagems_excluidas = 0;
            else if (contador_v_disp<quant_voo) viagems_excluidas = quant_voo - contador_v_disp;
            flag_encerrar = 1;
        }else if(resposta == contador_v_disp+1) break;
        if(contador_v_disp > 1){
            printf("\nDeseja excluir mais viagens? ");
            getchar();
            while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
                printf("\nResposta invalida, digite novamente");
            }
        }else flag = 1;
        if(resposta2 == 'n' || resposta2 == 'N') flag = 1;
    }while (flag != 1 || flag_encerrar != 1);
    return viagems_excluidas;
}

void lista_viagens (Viagem V[], int quant_voo){
    char resposta2 = 0;
    int flag = 0;
    char city_name[25];
    printf("\nDigite o nome da cidade de origem: ");
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
            printf("\nResposta invalida, digite novamente");
        }
        if(resposta2 == 's' || resposta2 == 'S'){
            flag = 1;
        }
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

    printf("\nDigite a cidade de origem:");
    scanf("%s",origem_city);
    up(origem_city);

    printf("\nDigite a cidade de destino:");
    scanf("%s",destino_city);
    up(destino_city);

    do{
        for (int i = 0; i < quant_voo; i++){
            up(V[i].cidade_origem);
            up(V[i].cidade_destino);
            if(!strcmp(V[i].cidade_origem,origem_city ) && !strcmp(V[i].cidade_destino,destino_city)){
                mesma_viagem_city[j] = V[i];
                j++;
            }
        }
        menor_escala = mesma_viagem_city[0].escalas;
        for (int i = 0; i < j; i++){
            if(mesma_viagem_city[i].escalas <= menor_escala){
            menor_escala = mesma_viagem_city[i].escalas;
            }
        }
        for (int i = 0; i < j; i++){
            if(mesma_viagem_city[i].escalas == menor_escala){
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
            printf("\nResposta invalida, digite novamente");
        }
        if(resposta2 == 's' || resposta2 == 'S') flag = 1;
    }while (flag != 1);
}

void up(char string[]){
    int i =0;

    while(string[i] != '\0' ){
        string[i] = toupper(string[i]);
        i++;
    }
}
/////////////////////////////////////////////

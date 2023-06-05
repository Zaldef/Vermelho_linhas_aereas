
#define NUM_CHAR 11
#define NUM_VIAGEM 50
#define NUM_COD 4
#include <ctype.h>
//ESTRUTURA
 struct Viagem {
    int codigo;
    char cidade_origem[NUM_CHAR];
    char cidade_destino[NUM_CHAR];
    int escalas;
};

typedef struct Viagem Viagem;

//PROT�TIPOS
void lista_viagens(Viagem V[], int quant_voo);
int inclusao_voo(Viagem V[]);
void alteracao_info_voo(Viagem V[], int quant_voo);
int exclusao_voo(Viagem V[], int quant_voo);
void up();
void menor_quant_escala_voo(Viagem V[], int quant_voo);
// void quant_voo_origem();


int inclusao_voo(Viagem V[]){
    int quant_voo = 0, contador =0, i = 0;

    printf("INCLUS�O DE VIAGENS\n");
    printf("\nDeseja incluir quantos voos?");
    while(scanf("%d",&quant_voo) != ((quant_voo>0) && (quant_voo<50))){
        printf("Entrada inv�lida. Digite um valor entre 1 e 49: ");
    }
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
    }while(contador != 0);
    return quant_voo;
}

void alteracao_info_voo(Viagem V[], int quant_voo){
    int resposta = 0, contador = 1, flag = 0, a = 1, posicao_cod = 0;
    char resposta2 = 0;
    do{
        printf("VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<quant_voo; i++){
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
        printf("\n%d- Sair;\n",quant_voo+1);
        printf("\nSelecione o c�digo da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == quant_voo+1))){
                printf("C�digo inv�lido, digite novamente.\n");
        }
        for(int i = 0; i<quant_voo; i++){
            if(resposta == V[i].codigo) posicao_cod = i; //variavel recebe a posi��o referente o c�digo digitado
        }
        if(resposta == quant_voo+1) return; //atualiza o flag para sair dessa fun�ao

        do{
            printf("\nVIAGEM %d:",posicao_cod+1);
            printf("\nDigite o c�digo da viagem: ");
            while(scanf("%d",&V[posicao_cod].codigo) != (V[posicao_cod].codigo >=1000 && V[posicao_cod].codigo <= 9999)){
                printf("C�digo inv�lido, digite novamente.\n");
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
                    printf("\nResposta inv�lida, digite novamente");
                }
            }
            if(resposta2 == 'n' || resposta2 == 'N') flag = 1; //atualiza o flag para sair dessa fun�ao
    }while (flag != 1);
}

int exclusao_voo(Viagem V[], int quant_voo){
    int resposta = 0, flag = 0, contador_v_disp = 0, a = 1, posicao_cod = 0;
    char resposta2 = 0;
    do{
        printf("EXCLUS�O DAS VIAGENS CADASTRADAS:\n");
        for(int i = 0; i<quant_voo; i++){
            if(V[i].codigo != 0){
        printf("%s ---> %s \n",V[i].cidade_origem,V[i].cidade_destino);
        printf(":---------------------------------------");
        printf("\n|Viagem %d: %d ", i+1, V[i].codigo);
        printf("\n|Cidade de Origem: %s ", V[i].cidade_origem);
        printf("\n|Cidade de Destino: %s ", V[i].cidade_destino);
        printf("\n|Paradas: %d ", V[i].escalas);
        printf("\n:--------------------------------------- \n");
                contador_v_disp++; //calcula a quantidade de viagens nao apagadas/zeradas
                a++;
            }
        }
        //verifica se algumas viagens foram apagadas e atualiza a quantidade de voos nao apagados
        if (contador_v_disp != quant_voo) quant_voo = quant_voo - contador_v_disp;
        printf("\n%d- Sair;\n",quant_voo+1);
        printf("\nSelecione o c�digo da viagem ou aperte para sair: ");
        while(scanf("%d",&resposta) != ((resposta >=1000 && resposta <= 9999) || (resposta == quant_voo+1))){
                printf("C�digo inv�lido, digite novamente.\n");
        }
        for(int i = 0; i<quant_voo; i++){
            if(resposta == V[i].codigo) posicao_cod = i; //variavel recebe a posi��o referente o c�digo digitado
        }
        if(resposta == quant_voo+1) break;//flag = 1; //atualiza o flag para sair dessa fun�ao

        //zera as informa��es da posi��o ESCOLHIDA do vetor de struct
        memset(&V[posicao_cod], 0, sizeof(struct Viagem));

        if(quant_voo > 1){
            printf("\nDeseja excluir mais viagens? ");
            getchar();
            while(scanf("%c",&resposta2) != (('s' && 'S') || ('n' && 'N'))){
                printf("\nResposta inv�lida, digite novamente");
            }
        }
            if(resposta2 == 'n' || resposta2 == 'N') flag = 1; //atualiza o flag para sair dessa fun�ao
    }while (flag != 1);
    return quant_voo;
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
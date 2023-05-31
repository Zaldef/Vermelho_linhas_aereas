#include <stdio.h>
#define NUM_CHAR 11
#define NUM_VIAGEM 50

//PROTÓTIPOS
void inclusao_voo();
void alteracao_info_voo();
void exlusao_voo();
void quant_voo_origem();
void menor_quant_escala_voo();

//ESTRUTURA
struct Voo{
    int codigo;
    char cidade_origem[NUM_CHAR];
    char cidade_destino[NUM_CHAR];
    int escalas;
};

int main(){
    struct Voo viagem [NUM_VIAGEM];
    int resposta = 0;
    // char resposta = 0;

    // do{

    // }while();
    printf("VERMELHO LINHAS AÉREAS\n");
    printf("Por favor, selecionar as opções abaixo:\n");
    scanf("%d",&resposta);

    switch (resposta) {
        case 1:
            printf("Incluir voos.\n");
            inclusao_voo(viagem);
            break;
        case 2:
            printf("Alterar as informações do voo.\n");
            alteracao_info_voo();
            break;
        case 3:
            printf("Apagar voo.\n");
            exlusao_voo();
            break;
        case 4:
            printf("Quantidade de voos da cidade de origem.\n");
            quant_voo_origem();
            break;
        case 5:
            printf("Quantidade de voos com menor número de escala da cidade de origem e destino.\n");
            menor_quant_escala_voo();
            break;
        case 6:
            printf("Sair.\n");
            return 0;
            break;
        default:
            printf("Opção inválida, tente novamente.\n");
            break;
    }

}

void inclusao_voo(Voo viagem[]){
    int quant_voo = 0, contador = 1;
    printf("\nDeseja incluir quantos voos?");
    scanf("%d",&quant_voo);
    //Verificaçao da quantidade de voo, que nao pode exceder de 50
    //do{

    //}while(quant_voo<50);

    do{
        printf("\nVIAGEM %d:",contador);
        printf("\nDigite o código da viagem: ");
        scanf("%d",%Voo[quant_voo].codigo);
        printf("\nDigite a cidade de origem: ");
        scanf("%d",%Voo[quant_voo].cidade_origem);

    }while(quant_voo !=0);


}

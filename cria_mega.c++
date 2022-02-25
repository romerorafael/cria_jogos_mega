#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct{
int num1,num2, num3,num4,num5,num6;
} cartela;

void geraJogos(int quantity, cartela* ptr_jogos);
void verificaCartela(cartela *jogo);
void verificaJogosIguais(cartela *jogos, int num_jogos);
void salvarJogos(cartela *jogos, int num_jogos);
int main()
{
    setlocale(LC_ALL,"Portuguese");
    cartela *jogos=NULL;
    int num_jogos, i=0, j=0, press;
    srand(time(NULL)); //Cria a semente para os números randomicos
    printf("Quantos jogos quer gerar? (max:20)\n");
    scanf("%i", &num_jogos);
    if(num_jogos > 20 || num_jogos <= 0) //Verifica se a quantidade de jogo é válida, por regra deve ser menor ou igual a 20
    {
        printf("Quantidade inválida: digite outro valor\n");
        scanf("%i", &num_jogos);
    }
    jogos = (cartela*)malloc(num_jogos*sizeof(cartela)); //Vai alocar na memória somente o número de jogos que deverão ser feitos
    geraJogos(num_jogos, jogos);
    verificaJogosIguais(jogos, num_jogos);
    for (i = 0; i < num_jogos; i++)
    {
    printf("Jogo número %02i: ", i+1);
    printf("%02i,", (jogos+i)->num1);
    printf("%02i,", (jogos+i)->num2);
    printf("%02i,", (jogos+i)->num3);
    printf("%02i,", (jogos+i)->num4);
    printf("%02i,", (jogos+i)->num5);
    printf("%02i\n", (jogos+i)->num6);
    }
    printf("Quer salvar os dados (1-Sim/2-Nao)\n");
    scanf("%i", &press);
    if(press == 1)
    {
    salvarJogos(jogos, num_jogos);
    printf("Jogos impressos com sucesso.\n");
    }else
    {
    printf("Obrigado por utilizar o nosso programa.\n");
    }
    free(jogos); //Libera a memória usada para armazenar os jogos
    system("pause");
    return 0;
}
//Função que sorteia os 6 números do jogos. Ele tb chama a função que vai verificar se todos os números são diferentes
void geraJogos(int quantity, cartela *jogos)
{
    if(quantity != 0){
        jogos->num1 = 1 + (rand()%60);
        jogos->num2 = 1 + (rand()%60);
        jogos->num3 = 1 + (rand()%60);
        jogos->num4 = 1 + (rand()%60);
        jogos->num5 = 1 + (rand()%60);
        jogos->num6 = 1 + (rand()%60);
        verificaCartela(jogos);
        geraJogos(quantity-1, jogos+1);
    }
}
//Função que verifica se todos os números são diferentes. Caso tenha um número repetido ele altera esse número e faz uma nova verificação dos repetidos
void verificaCartela(cartela *jogo)
{
    if( jogo->num1 == jogo->num2 ||
        jogo->num1 == jogo->num3 ||
        jogo->num1 == jogo->num4 ||
        jogo->num1 == jogo->num5 ||
        jogo->num1 == jogo->num6
    )
    {
        jogo->num1 = 1 + (rand()%60);
        verificaCartela(jogo);
    }
    else if( jogo->num2 == jogo->num3 ||
            jogo->num2 == jogo->num4 ||
            jogo->num2 == jogo->num5 ||
            jogo->num2 == jogo->num6 )
    {
    jogo->num2 = 1 + (rand()%60);
    verificaCartela(jogo);
    }
    else if( jogo->num3 == jogo->num4 ||
            jogo->num3 == jogo->num5 ||
            jogo->num3 == jogo->num6
    )
    {
        jogo->num3 = 1 + (rand()%60);
        verificaCartela(jogo);
    }
    else if(jogo->num4 == jogo->num5 ||
        jogo->num4 == jogo->num6
    )
    {
        jogo->num4 = 1 + (rand()%60);
        verificaCartela(jogo);
    }
    else if(jogo->num5 == jogo->num6 )
    {
        jogo->num5 = 1 + (rand()%60);
        verificaCartela(jogo);
    }
}
//Função que verifica se existem jogos iguais. Caso exista um jogo igual ao outro ele refaz o jog e repete a verificação tanto dos jogos quanto dos números dentro da mesma cartela
void verificaJogosIguais(cartela *jogos, int num_jogos)
{
    int i, j;
    for (i = 0; i < num_jogos-1; i++)
    {
        for (j = i+1; j < num_jogos; j++)
        {
            if( (jogos+i)->num1 != (jogos+j)->num1 && (jogos+i)->num1
                != (jogos+j)->num2 && (jogos+i)->num1 != (jogos+j)->num3 &&
                (jogos+i)->num1 != (jogos+j)->num4 && (jogos+i)->num1
                != (jogos+j)->num5 && (jogos+i)->num1 != (jogos+j)->num6 )
            {
                break;
            }
            if( (jogos+i)->num2 != (jogos+j)->num1 && (jogos+i)->num2
                != (jogos+j)->num2 && (jogos+i)->num2 != (jogos+j)->num3 &&
                (jogos+i)->num2 != (jogos+j)->num4 && (jogos+i)->num2
                != (jogos+j)->num5 && (jogos+i)->num2 != (jogos+j)->num6 )
            {
                break;
            }
            if( (jogos+i)->num3 != (jogos+j)->num1 && (jogos+i)->num3
                != (jogos+j)->num2 && (jogos+i)->num3 != (jogos+j)->num3 &&
                (jogos+i)->num3 != (jogos+j)->num4 && (jogos+i)->num3
                != (jogos+j)->num5 && (jogos+i)->num3 != (jogos+j)->num6 )
            {
                break;
            }
            if( (jogos+i)->num4 != (jogos+j)->num1 && (jogos+i)->num4
                != (jogos+j)->num2 && (jogos+i)->num4 != (jogos+j)->num3 &&
                (jogos+i)->num4 != (jogos+j)->num4 && (jogos+i)->num4
                != (jogos+j)->num5 && (jogos+i)->num4 != (jogos+j)->num6 )
            {
                break;
            }
            if( (jogos+i)->num4 != (jogos+j)->num1 && (jogos+i)->num4
                != (jogos+j)->num2 && (jogos+i)->num4 != (jogos+j)->num3 &&
                (jogos+i)->num4 != (jogos+j)->num4 && (jogos+i)->num4
                != (jogos+j)->num5 && (jogos+i)->num4 != (jogos+j)->num6 )
            {
                break;
            }
            if( (jogos+i)->num5 != (jogos+j)->num1 && (jogos+i)->num5
                != (jogos+j)->num2 && (jogos+i)->num5 != (jogos+j)->num3 &&
                (jogos+i)->num5 != (jogos+j)->num4 && (jogos+i)->num5
                != (jogos+j)->num5 && (jogos+i)->num5 != (jogos+j)->num6 )
            {
                break;
            }
            if( (jogos+i)->num6 != (jogos+j)->num1 && (jogos+i)->num6
                != (jogos+j)->num2 && (jogos+i)->num6 != (jogos+j)->num3 &&
                (jogos+i)->num6 != (jogos+j)->num4 && (jogos+i)->num6
                != (jogos+j)->num5 && (jogos+i)->num6 != (jogos+j)->num6 )
            {
                break;
            }
            system("pause");
            geraJogos(1, jogos+i);
            i--;
        }
    }
}
//Função responsável por imprimir os jogos caso seja solicitado pelo usuário
void salvarJogos(cartela *jogos, int num_jogos){
    int i;
    FILE *file = fopen("MeusJogos.csv", "w"); //Ele abre/cria o arquivo onde serão salvos os jogos
    if (file!=NULL)
    {
    for (i = 0; i < num_jogos; i++)
    {
    fprintf(file, "%02i; %02i; %02i; %02i; %02i; %02i.\n",
    (jogos+i)->num1, (jogos+i)->num2, (jogos+i)->num3, (jogos+i)->num4,
    (jogos+i)->num5, (jogos+i)->num6);
    }
    }
    fclose(file); //Fecha o arquivo depois do uso
}
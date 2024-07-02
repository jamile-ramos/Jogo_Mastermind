#include<stdio.h>
#include<string.h> // utilizado para pode usar strings
#include<stdlib.h>  // precisa dele para utilizar o srannd
#include<stdbool.h> // utilizado para usar a funcao boll que serve para manipular variaveis logicas
#include<time.h> //usado para gerar o numero aleatorio
#define TAM 100

int casas[90];
char nome[20];
char jogador1[20];
char jogador2[20];
int preto[20], branco[20];
int vazio[20];
int q, j, s1, s2, s3, s4, s5, s6, pontos1=0, pontos2=0;
int s[8];
int cor=2;
int acabou;

void tabuleiro1();
void tabuleiro2();
void tabuleiro3();
void tabuleiropc();
void tabuleiropc2();
void tabuleiropc3();

void menu()
{
    system("clear");
    printf("\t  +==========================================================================+ \n");
    printf("\t  ||                                                                        || \n");
    printf("\t  ||    XXX         XXX   XXXXXXXX  XXXXXXX  XXXXXXXX  XXXXXXX  XXXXXXX     || \n");
    printf("\t  ||   XXX XX     XX XXX  XX    XX  XXXXXXX  XXXXXXXX  XX       XX    XX    || \n");
    printf("\t  ||   XXX   XX  XX  XXX  XX    XX  XX          XX     XX       XX    XX    || \n");
    printf("\t  ||   XXX    XXX    XXX  XXXXXXXX  XXXXXXX     XX     XXXXXXX  XXXXXXX     || \n");
    printf("\t  ||   XXX     X     XXX  XX    XX       XX     XX     XX       XX    XX    || \n");
    printf("\t  ||   XXX           XXX  XX    XX  XXXXXXX     XX     XX       XX     XX   || \n");
    printf("\t  ||   XXX           XXX  XX    XX  XXXXXXX     XX     XXXXXXX  XX     XX   ||        Grupo: Jamile Ramos\n");
    printf("\t  ||                                                                        || \n");
    printf("\t  ||             XXX         XXX   XXX   XXX       XX  XXXXXX               || \n");
    printf("\t  ||            XXX XX     XX XXX  XXX  XXX XX    XX   XX    XX             || \n");
    printf("\t  ||            XXX   XX  XX  XXX  XXX  XXX  XX  XX    XX     XX            || \n");
    printf("\t  ||            XXX    XXX    XXX  XXX  XXX    XXX     XX     XX            || \n");
    printf("\t  ||            XXX     X     XXX  XXX  XXX     X      XX     XX            || \n");
    printf("\t  ||            XXX           XXX  XXX  XXX            XX    XX             || \n");
    printf("\t  ||            XXX           XXX  XXX  XXX            XXXXXX               || \n");
    printf("\t  ||                                                                        || \n");
    printf("\t  +==========================================================================+\n\n");

    printf("\t  +==========================================================================+\n");
    printf("\t  |                              MENU DE OPCOES                              |\n");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                            0 - SAIR DO JOGO                              |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                            1 - JOGAR                                     |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                            2 - INSTRUCOES                                |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");

}

void facil()
{
    //nivel facil, com dois jogadores, sem repeticao de cores//
    int x, s, jogo;

    vazio[0] = 4;
    vazio[1] = 4;
    vazio[2] = 4;
    vazio[3] = 4;
    vazio[4] = 4;
    vazio[5] = 4;
    vazio[6] = 4;
    vazio[7] = 4;
    vazio[8] = 4;
    vazio[9] = 4;

    system("clear");

    printf("\t      +==================================================================+\n");
    printf("\t      ||  JOGADOR X JOGADOR  |  NIVEL FACIL  |  SEM REPETICAO DE CORES  ||\n");
    printf("\t      ||----------------------------------------------------------------||\n");
    printf("\t      ||                        VAMOS COMECAR!!!                        ||\n");
    printf("\t      +==================================================================+\n\n");

    printf("\t\t\t\tNOME DO JOGADOR 1: "); // nome do jogador 1
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    printf("\t\t\t\tNOME DO JOGADOR 2: "); // nome do jogador 2
    fflush(stdin);
    fgets(jogador2,20,stdin);
    jogador2[strcspn(jogador2, "\n")] = 0;

    printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
    printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
    scanf("%i", &q);


    while(q%2!=0)
    {
        printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
        printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
        scanf("%i", &q);
        system("clear");
    }

    int d, i, b=0, soma=4;
    j=0;

    for(j=0; j<q; j++)
    {

        system("clear");

        printf("\t\t                           <<==============>>\n");
        printf("\t\t                           ||   PARTIDA %i  || \n", j+1);
        printf("\t\t                           <<==============>>\n");

        printf("\n\t\t\t\t+=================================+ \n");
        printf("\t\t\t\t||     Vermelho    |      1      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Azul        |      2      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Marrom      |      3      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Laranja     |      4      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Roxo        |      5      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Cinza       |      6      || \n");
        printf("\t\t\t\t+=================================+ \n\n");

        if(j%2==0)
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 1:  ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador2);

        }
        else
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 2   ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador1);
        }

        printf("\n\t\t\t\t     Digite sua senha: ");
        scanf("%i", &x);

        s1 = x/1000;
        s2 = (x%1000)/100;
        s3 = ((x%1000)%100)/10;
        s4 = ((x%1000)%100)%10;


        if(s1>7 || s1==0 || s2==0 || s3==0 || s4==0 || s1==s2 || s1==s3 || s1==s4 || s2==s3 || s2==s4 || s3==s4)
        {
            do
            {
                system("clear");
                printf("\n\n\t\t\t\t           Senha invalida.\n");

                printf("\t\t\t     +---------------------------------------+\n");
                printf("\t\t\t     |              OBSERVACOES              | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    A senha deve conter 4 digitos      | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    Os digitos nao podem se repetir    | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |  Utilize apenas os numeros de 1 a 6   | \n");
                printf("\t\t\t     +---------------------------------------+ \n\n");
                printf("\n\n\t\t\t\t     Digite sua senha: ");
                scanf("%i", &x);
                s1 = x/1000;
                s2 = (x%1000)/100;
                s3 = ((x%1000)%100)/10;
                s4 = ((x%1000)%100)%10;

            }
            while(s1>7 || s1==0 || s2==0 || s3==0 || s4==0 || s1==s2 || s1==s3 || s1==s4 || s2==s3 || s2==s4 || s3==s4);

        }

        printf("\n");
        printf("\t                               +==================+ \n");
        printf("\t                               ||   AGORA VAMOS  || \n");
        printf("\t                               ||  AO DESAFIO!!! || \n");
        printf("\t                               +==================+ \n\n\n\n");
        system("pause");
        system("clear");

        if(j>0)
        {
            for(int g=0; g<40; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<10; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=4;
        }

        i=0;
        while(i<10)// usado para rodar a quantidade de tentativas(jogadas)//
        {
            system("clear");
            //jogada//
            tabuleiro1();
            printf("\t\t\t                 Adivinhe a senha: ");
            scanf("%i", &s);
            if(i>0)//if  usado para acrescentar +4 //
            {
                b = b+4;
                soma = soma+4;
            }
            for(int k=b; k<soma; k++)
            {
                d = s%10;
                casas[k]= d;
                s = s/10;
            }

            // testar os pinos que s�o pretos//
            if(s1 == casas[soma-1] && s1 != casas[soma-2] && s1 != casas[soma-3] && s1 != casas[soma-4])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s2 == casas[soma-2] && s2 != casas[soma-1] && s2 != casas[soma-3] && s2 != casas[soma-4])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s3 == casas[soma-3] && s3 != casas[soma-1] && s3 != casas[soma-2] && s3 != casas[soma-4])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s4 == casas[soma-4] && s4 != casas[soma-1] && s4 != casas[soma-2] && s4 != casas[soma-3])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }

            //testar se ganhou o jogo ou n�o//
            if(preto[i]==4)
            {
                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
                printf("\n                                       ||  PARABENS! VOCE ACERTOU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }
            if(i==9 && preto[i]!=4)
            {
                for(int g=0; g<40; g++)
                {
                    casas[g]=0;
                }
                for(int g=0; g<10; g++)
                {
                    preto[g]=0;
                    branco[g]=0;
                    vazio[g]=4;
                }
                b=0;
                d=0;
                soma=4;

                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
                printf("\n                                       ||  QUE PENA! VOCE ERROU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }

            //testar os pinos brancos//
            if(s1 != casas[soma-1] && s1 == casas[soma-2] || s1 == casas[soma-3] || s1 == casas[soma-4])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s2 != casas[soma-2] && s2 == casas[soma-1] || s2 == casas[soma-3] || s2 == casas[soma-4])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s3 != casas[soma-3] && s3 == casas[soma-1] || s3 == casas[soma-2] || s3 == casas[soma-4])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s4 != casas[soma-4] && s4 == casas[soma-1] || s4 == casas[soma-2] || s4 == casas[soma-3])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }


            i++;
        }

    }
    if(pontos1 == pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nO JOGO DEU EMPARTE!!!");
        pontos1 = 0;
        pontos2 = 0;
    }

    else if(pontos1 > pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador1);
        pontos1 = 0;
        pontos2 = 0;
    }
    else
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador2);
        pontos1 = 0;
        pontos2 = 0;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        facil();
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
    }
    else
    {
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
        menu();
    }



}

bool Existe(int valores[], int tam, int valor)
{
    for(int i=0; i<tam; i++) // usado para saber se o numero ja existe dentro do vetor
    {
        if(valores[i]==valor)
            return true;
    }
    return false;
}

void geraAleatorios(int numeros[], int quantNumeros, int limite)
{
    srand(time(NULL));
    int v;
    for(int u=0; u<quantNumeros; u++)  //usado para gerar numeros aleatorios
    {
        v =  1 + rand () % limite;
        while(Existe(numeros,u,v))
        {
            v =  1 + rand () % limite;
        }
        numeros[u] = v;
    }
}

void medio()
{
    //nivel medio, com dois jogadores, sem repeticao de cores//

    int x, s;
    vazio[0] = 5;
    vazio[1] = 5;
    vazio[2] = 5;
    vazio[3] = 5;
    vazio[4] = 5;
    vazio[5] = 5;
    vazio[6] = 5;
    vazio[7] = 5;
    vazio[8] = 5;
    vazio[9] = 5;
    vazio[10] = 5;
    vazio[11] = 5;

    system("clear");

    printf("\t      +==================================================================+\n");
    printf("\t      ||  JOGADOR X JOGADOR  |  NIVEL MEDIO  |  SEM REPETICAO DE CORES  ||\n");
    printf("\t      ||----------------------------------------------------------------||\n");
    printf("\t      ||                        VAMOS COMECAR!!!                        ||\n");
    printf("\t      +==================================================================+\n\n");


    printf("\t\t\t\tNOME DO JOGADOR 1: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    printf("\t\t\t\tNOME DO JOGADOR 2: ");
    fflush(stdin);
    fgets(jogador2,20,stdin);
    jogador2[strcspn(jogador2, "\n")] = 0;

    printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
    printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
    scanf("%i", &q);

    while(q%2!=0)
    {
        printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
        printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
        scanf("%i", &q);
        system("clear");
    }
    while(q%2!=0);

    int d, i, b=0, soma=5, h=0;
    j=0;

    for(j=0; j<q; j++)
    {

        system("clear");

        printf("\t\t                           <<==============>>\n");
        printf("\t\t                           ||   PARTIDA %i  || \n", j+1);
        printf("\t\t                           <<==============>>\n");

        printf("\n\t\t\t\t+=================================+ \n");
        printf("\t\t\t\t||     Vermelho    |      1      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Azul        |      2      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Marrom      |      3      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Laranja     |      4      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Roxo        |      5      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Cinza       |      6      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Verde       |      7      || \n");
        printf("\t\t\t\t+=================================+ \n\n");

        if(j%2==0)
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 1:  ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador2);

        }
        else
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 2   ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador1);
        }

        printf("\n\t\t\t\t     Digite sua senha: ");
        scanf("%i", &x);

        s1 = x/10000;
        s2 = (x%10000)/1000;
        s3 = ((x%10000)%1000)/100;
        s4 = (((x%10000)%1000)%100)/10;
        s5 = (((x%10000)%1000)%100)%10;



        if(s1>8 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0 || s1==s2 || s1==s3 || s1==s4 || s1==s5 || s2==s3 || s2==s4 || s2==s5 || s3==s4 || s3==s5 || s4==s5|| s5==s1)
        {
            do
            {
                system("clear");
                printf("\n\n\t\t\t\t           Senha invalida.\n");

                printf("\t\t\t     +---------------------------------------+\n");
                printf("\t\t\t     |              OBSERVACOES              | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    A senha deve conter 5 digitos      | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    Os digitos nao podem se repetir    | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |  Utilize apenas os numeros de 1 a 7   | \n");
                printf("\t\t\t     +---------------------------------------+ \n\n");
                printf("\n\n\t\t\t\t     Digite sua senha: ");
                scanf("%i", &x);
                s1 = x/10000;
                s2 = (x%10000)/1000;
                s3 = ((x%10000)%1000)/100;
                s4 = (((x%10000)%1000)%100)/10;
                s5 = (((x%10000)%1000)%100)%10;

            }
            while(s1>8 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0 || s1==s2 || s1==s3 || s1==s4 || s1==s5 || s2==s3 || s2==s4 || s2==s5 || s3==s4 || s3==s5 || s4==s5|| s5==s1);
        }



        printf("\n");
        printf("\t                               +==================+ \n");
        printf("\t                               ||   AGORA VAMOS  || \n");
        printf("\t                               ||  AO DESAFIO!!! || \n");
        printf("\t                               +==================+ \n\n\n\n");
        system("pause");
        system("clear");

        if(j>0)
        {
            for(int g=0; g<60; g++)//usado para zerar as casas
            {
                casas[g]=0;
            }
            for(int g=0; g<12; g++)  //usar para zerar o peto, branco e vazio
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=5;
            }
            b=0;
            d=0;
            soma=5;
        }

        i=0;
        while(i<12)// usado para rodar a quantidade de tentativas(jogadas)//
        {
            system("clear");
            //jogada//
            tabuleiro2();
            printf("\t\t\t                 Adivinhe a senha: ");
            scanf("%i", &s);
            if(i>0)//if  usado para acrescentar +4 //
            {
                b = b+5;
                soma = soma + 5;
            }
            for(int k=b; k<soma; k++)
            {
                d = s%10;
                casas[k]= d;
                s = s/10;
            }

            // testar os pinos que s�o pretos//
            if(s1 == casas[soma-1] && s1 != casas[soma-2] && s1 != casas[soma-3] && s1 != casas[soma-4] && s1 != casas[soma-5])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s2 == casas[soma-2] && s2 != casas[soma-1] && s2 != casas[soma-3] && s2 != casas[soma-4] && s2!= casas[soma-5])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s3 == casas[soma-3] && s3 != casas[soma-1] && s3 != casas[soma-2] && s3 != casas[soma-4] && s3 != casas[soma-5])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s4 == casas[soma-4] && s4 != casas[soma-1] && s4 != casas[soma-2] && s4 != casas[soma-3] && s4 != casas[soma-5])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s5 == casas[soma-5] && s5 != casas[soma-1] && s5 != casas[soma-2] && s5 != casas[soma-3] && s5 != casas[soma-4] )
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }

            //testar se ganhou o jogo ou n�o//
            if(preto[i]==5)
            {
                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i%i%i%i%i     ||", s1, s2, s3, s4, s5);
                printf("\n                                       || PARABENS! VOCE ACERTOU!  ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }
            if(i==11 && preto[i]!=5)
            {
                for(int g=0; g<60; g++)
                {
                    casas[g]=0;
                }
                for(int g=0; g<12; g++)
                {
                    preto[g]=0;
                    branco[g]=0;
                    vazio[g]=5;
                }
                b=0;
                d=0;
                soma=5;

                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i %i %i %i %i ||", s1, s2, s3, s4, s5);
                printf("\n                                       ||   QUE PENA! VOCE ERROU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }
            //testar os pinos brancos//
            if(s1 != casas[soma-1] && s1 == casas[soma-2] || s1 == casas[soma-3] || s1 == casas[soma-4] || s1 == casas[soma-5])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s2 != casas[soma-2] && s2 == casas[soma-1] || s2 == casas[soma-3] || s2 == casas[soma-4] || s2 == casas[soma-5])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s3 != casas[soma-3] && s3 == casas[soma-1] || s3 == casas[soma-2] || s3 == casas[soma-4] || s3 == casas[soma-5])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s4 != casas[soma-4] && s4 == casas[soma-1] || s4 == casas[soma-2] || s4 == casas[soma-3] || s4 == casas[soma-5])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s5 != casas[soma-5] && s5 == casas[soma-1] || s5 == casas[soma-2] || s5 == casas[soma-3] || s5 == casas[soma-4])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }


            i++;
        }
    }
    if(pontos1 == pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nO JOGO DEU EMPARTE!!!");
        pontos1 = 0;
        pontos2 = 0;
    }

    else if(pontos1 > pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador1);
        pontos1 = 0;
        pontos2 = 0;
    }
    else
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador2);
        pontos1 = 0;
        pontos2 = 0;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        medio();
        for(int g=0; g<60; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
    }
    else
    {
        for(int g=0; g<60; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
        menu();
    }


}

void dificil()
{
    //nivel medio, com dois jogadores, sem repeticao de cores//

    int x, s;
    vazio[0] = 6;
    vazio[1] = 6;
    vazio[2] = 6;
    vazio[3] = 6;
    vazio[4] = 6;
    vazio[5] = 6;
    vazio[6] = 6;
    vazio[7] = 6;
    vazio[8] = 6;
    vazio[9] = 6;
    vazio[10] = 6;
    vazio[11] = 6;
    vazio[12] = 6;
    vazio[13] = 6;
    vazio[14] = 6;

    system("clear");

    printf("\t      +===================================================================+\n");
    printf("\t      ||  JOGADOR X JOGADOR  |  NIVEL DIFICIL  |  SEM REPETICAO DE CORES ||\n");
    printf("\t      ||-----------------------------------------------------------------||\n");
    printf("\t      ||                         VAMOS COMECAR!!!                        ||\n");
    printf("\t      +===================================================================+\n\n");


    printf("\t\t\t\tNOME DO JOGADOR 1: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    printf("\t\t\t\tNOME DO JOGADOR 2: ");
    fflush(stdin);
    fgets(jogador2,20,stdin);
    jogador2[strcspn(jogador2, "\n")] = 0;

    printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
    printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
    scanf("%i", &q);

    while(q%2!=0)
    {
        printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
        printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
        scanf("%i", &q);
        system("clear");
    }

    int d, i, b=0, soma=6, h=0;
    j=0;

    for(j=0; j<q; j++)
    {

        system("clear");

        printf("\t\t                           <<==============>>\n");
        printf("\t\t                           ||   PARTIDA %i  || \n", j+1);
        printf("\t\t                           <<==============>>\n");

        printf("\n\t\t\t\t+=================================+ \n");
        printf("\t\t\t\t||     Vermelho    |      1      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Azul        |      2      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Marrom      |      3      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Laranja     |      4      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Roxo        |      5      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Cinza       |      6      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Verde       |      7      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Rosa        |      8      || \n");
        printf("\t\t\t\t+=================================+ \n\n");

        if(j%2==0)
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 1:  ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador2);

        }
        else
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 2   ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador1);
        }

        printf("\n\t\t\t\t     Digite sua senha: ");
        scanf("%i", &x);

        s1 = x/100000;
        s2 = (x%100000)/10000;
        s3 = ((x%100000)%10000)/1000;
        s4 = (((x%100000)%10000)%1000)/100;
        s5 = ((((x%100000)%10000)%1000)%100)/10;
        s6 = ((((x%100000)%10000)%1000)%100)%10;

        if(s1>9 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0 || s6==0 || s1==s2 || s1==s3 || s1==s4 || s1==s5 || s1==s6 || s2==s3 || s2==s4 || s2==s5 || s2==s6 || s3==s4 || s3==s5 || s3==s6 || s4==s5 || s4==s6 || s5==s6 || s6==s1)
        {
            do
            {
                system("clear");
                printf("\n\n\t\t\t\t           Senha invalida.\n");

                printf("\t\t\t     +---------------------------------------+\n");
                printf("\t\t\t     |              OBSERVACOES              | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    A senha deve conter 6 digitos      | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    Os digitos nao podem se repetir    | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |  Utilize apenas os numeros de 1 a 8   | \n");
                printf("\t\t\t     +---------------------------------------+ \n\n");
                printf("\n\n\t\t\t\t     Digite sua senha: ");
                scanf("%i", &x);
                s1 = x/100000;
                s2 = (x%100000)/10000;
                s3 = ((x%100000)%10000)/1000;
                s4 = (((x%100000)%10000)%1000)/100;
                s5 = ((((x%100000)%10000)%1000)%100)/10;
                s6 = ((((x%100000)%10000)%1000)%100)%10;

            }
            while(s1>9 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0 || s6==0 || s1==s2 || s1==s3 || s1==s4 || s1==s5 || s1==s6 || s2==s3 || s2==s4 || s2==s5 || s2==s6 || s3==s4 || s3==s5 || s3==s6 || s4==s5 || s4==s6 || s5==s6 || s6==s1);
        }



        printf("\n");
        printf("\t                               +==================+ \n");
        printf("\t                               ||   AGORA VAMOS  || \n");
        printf("\t                               ||  AO DESAFIO!!! || \n");
        printf("\t                               +==================+ \n\n\n\n");
        system("pause");
        system("clear");

        if(j>0)
        {
            for(int g=0; g<84; g++)//usado para zerar as casas
            {
                casas[g]=0;
            }
            for(int g=0; g<14; g++)  //usar para zerar o peto, branco e vazio
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=6;
            }
            b=0;
            d=0;
            soma=6;
        }

        i=0;
        while(i<14)// usado para rodar a quantidade de tentativas(jogadas)//
        {
            system("clear");
            //jogada//
            tabuleiro3();
            printf("\t\t\t                 Adivinhe a senha: ");
            scanf("%i", &s);
            if(i>0)//if  usado para acrescentar +4 //
            {
                b = b+6;
                soma = soma + 6;
            }
            for(int k=b; k<soma; k++)
            {
                d = s%10;
                casas[k]= d;
                s = s/10;
            }

            // testar os pinos que s�o pretos//
            if(s1 == casas[soma-1] && s1 != casas[soma-2] && s1 != casas[soma-3] && s1 != casas[soma-4] && s1 != casas[soma-5] && s1 != casas[soma-6])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s2 == casas[soma-2] && s2 != casas[soma-1] && s2 != casas[soma-3] && s2 != casas[soma-4] && s2!= casas[soma-5] && s2!= casas[soma-6])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s3 == casas[soma-3] && s3 != casas[soma-1] && s3 != casas[soma-2] && s3 != casas[soma-4] && s3 != casas[soma-5] && s3 != casas[soma-6])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s4 == casas[soma-4] && s4 != casas[soma-1] && s4 != casas[soma-2] && s4 != casas[soma-3] && s4 != casas[soma-5] && s4 != casas[soma-6])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s5 == casas[soma-5] && s5 != casas[soma-1] && s5 != casas[soma-2] && s5 != casas[soma-3] && s5 != casas[soma-4] && s5 != casas[soma-6])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s6 == casas[soma-6] && s6 != casas[soma-1] && s6 != casas[soma-2] && s6 != casas[soma-3] && s6 != casas[soma-4] && s6 != casas[soma-5])
            {
                preto[i]= preto[i] + 1;
                vazio[i] = vazio[i]-1;
            }

            //testar se ganhou o jogo ou n�o//
            if(preto[i]==6)
            {
                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i%i%i%i%i%i      ||", s1, s2, s3, s4, s5, s6);
                printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    if(preto[i]!=6)
                    {
                        pontos1 = pontos1 + 1;
                    }
                }
                else
                {
                    if(preto[i]!=1)
                    {
                        pontos2 = pontos2 + 2;
                    }
                }

                system("pause");
                break;
            }

            if(i==13 && preto[i]!=6)
            {
                for(int g=0; g<84; g++)
                {
                    casas[g]=0;
                }
                for(int g=0; g<14; g++)
                {
                    preto[g]=0;
                    branco[g]=0;
                    vazio[g]=6;
                }
                b=0;
                d=0;
                soma=6;

                printf("\n                                       +============================+");
                printf("\n                                       ||  A SENHA ERA %i %i %i %i %i %i ||", s1, s2, s3, s4, s5, s6);
                printf("\n                                       ||    QUE PENA! VOCE ERROU! ||");
                printf("\n                                       +============================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }


            //testar os pinos brancos//
            if(s1 != casas[soma-1] && s1 == casas[soma-2] || s1 == casas[soma-3] || s1 == casas[soma-4] || s1 == casas[soma-5]|| s1 == casas[soma-6])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s2 != casas[soma-2] && s2 == casas[soma-1] || s2 == casas[soma-3] || s2 == casas[soma-4] || s2 == casas[soma-5]|| s2 == casas[soma-6])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s3 != casas[soma-3] && s3 == casas[soma-1] || s3 == casas[soma-2] || s3 == casas[soma-4] || s3 == casas[soma-5]|| s3 == casas[soma-6])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s4 != casas[soma-4] && s4 == casas[soma-1] || s4 == casas[soma-2] || s4 == casas[soma-3] || s4 == casas[soma-5]|| s4 == casas[soma-6])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s5 != casas[soma-5] && s5 == casas[soma-1] || s5 == casas[soma-2] || s5 == casas[soma-3] || s5 == casas[soma-4]|| s5 == casas[soma-6])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }
            if(s6 != casas[soma-6] && s6 == casas[soma-1] || s6 == casas[soma-2] || s6 == casas[soma-3] || s6 == casas[soma-4]|| s6 == casas[soma-5])
            {
                branco[i] = branco[i] + 1;
                vazio[i] = vazio[i]-1;
            }


            i++;
        }
    }

    if(pontos1 == pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nO JOGO DEU EMPARTE!!!");
        pontos1 = 0;
        pontos2 = 0;
    }

    else if(pontos1 > pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador1);
        pontos1 = 0;
        pontos2 = 0;
    }
    else
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador2);
        pontos1 = 0;
        pontos2 = 0;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        dificil();
        for(int g=0; g<84; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<14; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=6;
        }
        b=0;
        d=0;
        soma=6;
    }
    else
    {
        for(int g=0; g<84; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<14; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=6;
        }
        b=0;
        d=0;
        soma=6;
        menu();
    }


}

void pc1()
{
    //nivel facil, jogando com a maquina, sem repeticao de cores//

    int x, ss; //x vai ser usado para guardar minha senha pricipal e ss � usada para guardar a senha que o usuario der

    vazio[0] = 4;
    vazio[1] = 4;
    vazio[2] = 4;
    vazio[3] = 4;
    vazio[4] = 4;
    vazio[5] = 4;
    vazio[6] = 4;
    vazio[7] = 4;
    vazio[8] = 4;
    vazio[9] = 4;


    system("clear");

    printf("\t      +====================================================================+\n");
    printf("\t      ||  JOGADOR X COMPUTADOR  |  NIVEL FACIL  |  SEM REPETICAO DE CORES ||\n");
    printf("\t      ||------------------------------------------------------------------||\n");
    printf("\t      ||                           VAMOS COMECAR!!!                       ||\n");
    printf("\t      +====================================================================+\n\n");

    printf("\t\t\t\t\tNOME DO JOGADOR: "); // nome do jogador 1
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    int d, i, b=0, soma=4, u=0, igual;

    int s[4];

    geraAleatorios(s, 4, 6); // usado para gerar numeros aleatorios

    s1 = s[0];
    s2 = s[1];
    s3 = s[2];
    s4 = s[3];

    printf("\n");
    printf("\t                               +========================+ \n");
    printf("\t                               ||  VAMOS AO DESAFIO!!! || \n");
    printf("\t                               +========================+ \n\n\n\n");
    system("pause");
    system("clear");

    i=0;
    while(i<10)// usado para rodar a quantidade de tentativas(jogadas)//
    {
        system("clear");
        //jogada//
        tabuleiropc();
        printf("\t\t\t                 Adivinhe a senha: ");
        scanf("%i", &ss);
        if(i>0)//if  usado para acrescentar +4 //
        {
            b = b+4;
            soma = soma+4;
        }
        for(int k=b; k<soma; k++)// usado para inserir os numeros nas casas do tabuleiro
        {
            d = ss%10;
            casas[k]= d;
            ss = ss/10;
        }

        // testar os pinos que s�o pretos//
        if(s1 == casas[soma-1] && s1 != casas[soma-2] && s1 != casas[soma-3] && s1 != casas[soma-4])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s2 == casas[soma-2] && s2 != casas[soma-1] && s2 != casas[soma-3] && s2 != casas[soma-4])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s3 == casas[soma-3] && s3 != casas[soma-1] && s3 != casas[soma-2] && s3 != casas[soma-4])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s4 == casas[soma-4] && s4 != casas[soma-1] && s4 != casas[soma-2] && s4 != casas[soma-3])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }

        //testar se ganhou o jogo ou n�o//
        if(preto[i]==4)
        {
            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
            printf("\n                                       ||  PARABENS! VOCE ACERTOU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }
        if(i==9 && preto[i]!=4)
        {
            for(int g=0; g<40; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<10; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=4;

            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
            printf("\n                                       ||  QUE PENA! VOCE ERROU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }

        //testar os pinos brancos//
        if(s1 != casas[soma-1] && s1 == casas[soma-2] || s1 == casas[soma-3] || s1 == casas[soma-4])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s2 != casas[soma-2] && s2 == casas[soma-1] || s2 == casas[soma-3] || s2 == casas[soma-4])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s3 != casas[soma-3] && s3 == casas[soma-1] || s3 == casas[soma-2] || s3 == casas[soma-4])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s4 != casas[soma-4] && s4 == casas[soma-1] || s4 == casas[soma-2] || s4 == casas[soma-3])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }

        i++;
    }

    printf("\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        pc1();
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
    }
    else
    {
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
        menu();
    }
}

void pc2()
{
    //nivel medio, jogar com pc, sem repeticao de cores//

    int x, ss;
    vazio[0] = 5;
    vazio[1] = 5;
    vazio[2] = 5;
    vazio[3] = 5;
    vazio[4] = 5;
    vazio[5] = 5;
    vazio[6] = 5;
    vazio[7] = 5;
    vazio[8] = 5;
    vazio[9] = 5;
    vazio[10] = 5;
    vazio[11] = 5;

    system("clear");

    printf("\t      +====================================================================+\n");
    printf("\t      ||  JOGADOR X COMPUTADOR  |  NIVEL  MEDIO  | SEM REPETICAO DE CORES ||\n");
    printf("\t      ||------------------------------------------------------------------||\n");
    printf("\t      ||                           VAMOS COMECAR!!!                       ||\n");
    printf("\t      +====================================================================+\n\n");


    printf("\t\t\t\t\tNOME DO JOGADOR: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    int d, i, b=0, soma=5, u=0, igual;

    int s[5];

    geraAleatorios(s, 5,7);

    printf("\n");
    printf("\t                               +========================+ \n");
    printf("\t                               ||  VAMOS AO DESAFIO!!! || \n");
    printf("\t                               +========================+ \n\n\n\n");
    system("pause");
    system("clear");

    i=0;
    while(i<12)// usado para rodar a quantidade de tentativas(jogadas)//
    {
        system("clear");
        //jogada//
        tabuleiropc2();
        printf("\t\t\t                 Adivinhe a senha: ");
        scanf("%i", &ss);
        if(i>0)//if  usado para acrescentar +4 //
        {
            b = b+5;
            soma = soma + 5;
        }
        for(int k=b; k<soma; k++)
        {
            d = ss%10;
            casas[k]= d;
            ss = ss/10;
        }

        // testar os pinos que s�o pretos//
        if(s[0] == casas[soma-1] && s[0] != casas[soma-2] && s[0] != casas[soma-3] && s[0] != casas[soma-4] && s[0] != casas[soma-5])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[1] == casas[soma-2] && s[1] != casas[soma-1] && s[1] != casas[soma-3] && s[1] != casas[soma-4] && s[1]!= casas[soma-5])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[2] == casas[soma-3] && s[2] != casas[soma-1] && s[2] != casas[soma-2] && s[2] != casas[soma-4] && s[2] != casas[soma-5])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[3] == casas[soma-4] && s[3] != casas[soma-1] && s[3] != casas[soma-2] && s[3] != casas[soma-3] && s[3] != casas[soma-5])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[4] == casas[soma-5] && s[4] != casas[soma-1] && s[4] != casas[soma-2] && s[4] != casas[soma-3] && s[4] != casas[soma-4] )
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }

        //testar se ganhou o jogo ou n�o//
        if(preto[i]==5)
        {
            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i%i%i%i%i     ||", s1, s2, s3, s4, s5);
            printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }

        //testar os pinos brancos//
        if(s[0] != casas[soma-1] && s[0] == casas[soma-2] || s[0] == casas[soma-3] || s[0] == casas[soma-4] || s[0] == casas[soma-5])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[1] != casas[soma-2] && s[1]  == casas[soma-1] || s[1]  == casas[soma-3] || s[1]  == casas[soma-4] || s[1]  == casas[soma-5])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[2]  != casas[soma-3] && s[2] == casas[soma-1] || s[2] == casas[soma-2] || s[2] == casas[soma-4] || s[2] == casas[soma-5])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[3] != casas[soma-4] && s[3] == casas[soma-1] || s[3] == casas[soma-2] || s[3] == casas[soma-3] || s[3] == casas[soma-5])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[4] != casas[soma-5] && s[4] == casas[soma-1] || s[4] == casas[soma-2] || s[4] == casas[soma-3] || s[4] == casas[soma-4])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }

        if(i==11)
        {
            for(int g=0; g<60; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<12; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=5;
            }
            b=0;
            d=0;
            soma=5;


            printf("\n                                       +===========================+");
            printf("\n                                       ||   A senha era %i %i %i %i   ||", s[0], s[1], s[2], s[3], s[4]);
            printf("\n                                       || QUE PENA! VOCE PERDEU:( ||");
            printf("\n                                       +===========================+\n\n");
        }


        i++;
    }


    printf("\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        pc2();
        for(int g=0; g<60; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
    }
    else
    {
        for(int g=0; g<60; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
        menu();
    }

}

void pc3()
{
    //nivel medio, jogar com pc, sem repeticao de cores//

    int x, ss;
    vazio[0] = 6;
    vazio[1] = 6;
    vazio[2] = 6;
    vazio[3] = 6;
    vazio[4] = 6;
    vazio[5] = 6;
    vazio[6] = 6;
    vazio[7] = 6;
    vazio[8] = 6;
    vazio[9] = 6;
    vazio[10] = 6;
    vazio[11] = 6;

    system("clear");

    printf("\t      +====================================================================+\n");
    printf("\t      ||  JOGADOR X COMPUTADOR  |  NIVEL  MEDIO  | SEM REPETICAO DE CORES ||\n");
    printf("\t      ||------------------------------------------------------------------||\n");
    printf("\t      ||                           VAMOS COMECAR!!!                       ||\n");
    printf("\t      +====================================================================+\n\n");


    printf("\t\t\t\t\tNOME DO JOGADOR: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    int d, i, b=0, soma=6, u=0, igual;

    int s[6];

    geraAleatorios(s, 6,8);

    printf("\n");
    printf("\t                               +========================+ \n");
    printf("\t                               ||  VAMOS AO DESAFIO!!! || \n");
    printf("\t                               +========================+ \n\n\n\n");
    system("pause");
    system("clear");

    i=0;
    while(i<14)// usado para rodar a quantidade de tentativas(jogadas)//
    {
        system("clear");
        //jogada//
        tabuleiropc3();
        printf("\t\t\t                 Adivinhe a senha: ");
        scanf("%i", &ss);
        if(i>0)//if  usado para acrescentar +4 //
        {
            b = b+6;
            soma = soma + 6;
        }
        for(int k=b; k<soma; k++)
        {
            d = ss%10;
            casas[k]= d;
            ss = ss/10;
        }

        // testar os pinos que s�o pretos//
        if(s[0] == casas[soma-1] && s[0] != casas[soma-2] && s[0] != casas[soma-3] && s[0] != casas[soma-4] && s[0] != casas[soma-5] && s[0] != casas[soma-6])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[1] == casas[soma-2] && s[1] != casas[soma-1] && s[1] != casas[soma-3] && s[1] != casas[soma-4] && s[1]!= casas[soma-5] && s[1]!= casas[soma-6])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[2] == casas[soma-3] && s[2] != casas[soma-1] && s[2] != casas[soma-2] && s[2] != casas[soma-4] && s[2] != casas[soma-5] && s[2] != casas[soma-6])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[3] == casas[soma-4] && s[3] != casas[soma-1] && s[3] != casas[soma-2] && s[3] != casas[soma-3] && s[3] != casas[soma-5] && s[3] != casas[soma-6])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[4] == casas[soma-5] && s[4] != casas[soma-1] && s[4] != casas[soma-2] && s[4] != casas[soma-3] && s[4] != casas[soma-4] && s[4] != casas[soma-6])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[5] == casas[soma-6] && s[5] != casas[soma-1] && s[5] != casas[soma-2] && s[5] != casas[soma-3] && s[5] != casas[soma-4] && s[5] != casas[soma-5])
        {
            preto[i]= preto[i] + 1;
            vazio[i] = vazio[i]-1;
        }

        //testar se ganhou o jogo ou n�o//
        if(preto[i]==6)
        {
            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i%i%i%i%i%i      ||", s[0],s[1],s[2],s[3],s[4],s[5]);
            printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }


        //testar os pinos brancos//
        if(s[0] != casas[soma-1] && s[0] == casas[soma-2] || s[0] == casas[soma-3] || s[0] == casas[soma-4] || s[0] == casas[soma-5]|| s[0] == casas[soma-6])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[1] != casas[soma-2] && s[1] == casas[soma-1] || s[1] == casas[soma-3] || s[1] == casas[soma-4] || s[1] == casas[soma-5]|| s[1] == casas[soma-6])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[2] != casas[soma-3] && s[2] == casas[soma-1] || s[2] == casas[soma-2] || s[2]== casas[soma-4] || s[2] == casas[soma-5]|| s[2] == casas[soma-6])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[3] != casas[soma-4] && s[3] == casas[soma-1] || s[3] == casas[soma-2] || s[3] == casas[soma-3] || s[3] == casas[soma-5]|| s[3] == casas[soma-6])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[4] != casas[soma-5] && s[4] == casas[soma-1] || s[4] == casas[soma-2] || s[4] == casas[soma-3] || s[4] == casas[soma-4]|| s[4] == casas[soma-6])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }
        if(s[5] != casas[soma-6] && s[5] == casas[soma-1] || s[5] == casas[soma-2] || s[5] == casas[soma-3] || s[5] == casas[soma-4]|| s[5] == casas[soma-5])
        {
            branco[i] = branco[i] + 1;
            vazio[i] = vazio[i]-1;
        }

        if(i==13)
        {
            for(int g=0; g<84; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<14; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=6;

            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i %i %i %i %i %i ||", s[0], s[1], s[2], s[3], s[4], s[5]);
            printf("\n                                       || QUE PENA! VOCE PERDEU:( ||");
            printf("\n                                       +===========================+\n\n");
        }
        i++;
    }
    printf("\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        pc3();
        for(int g=0; g<84; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<14; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=6;
        }
        b=0;
        d=0;
        soma=6;
    }
    else
    {
        for(int g=0; g<84; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<14; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=6;
        }
        b=0;
        d=0;
        soma=6;
        menu();
    }
}

void facil_com_repeticao2()
{
    //nivel facil, com dois jogadores, com repeticao de cores//

    int x, ss;

    vazio[0] = 4;
    vazio[1] = 4;
    vazio[2] = 4;
    vazio[3] = 4;
    vazio[4] = 4;
    vazio[5] = 4;
    vazio[6] = 4;
    vazio[7] = 4;
    vazio[8] = 4;
    vazio[9] = 4;

    system("clear");

    printf("\t      +==================================================================+\n");
    printf("\t      ||  JOGADOR X JOGADOR  |  NIVEL FACIL  |  COM REPETICAO DE CORES  ||\n");
    printf("\t      ||----------------------------------------------------------------||\n");
    printf("\t      ||                        VAMOS COMECAR!!!                        ||\n");
    printf("\t      +==================================================================+\n\n");

    printf("\t\t\t\tNOME DO JOGADOR 1: "); // nome do jogador 1
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    printf("\t\t\t\tNOME DO JOGADOR 2: "); // nome do jogador 2
    fflush(stdin);
    fgets(jogador2,20,stdin);
    jogador2[strcspn(jogador2, "\n")] = 0;

    printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
    printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
    scanf("%i", &q);

    while(q%2!=0)
    {
        printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
        printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
        scanf("%i", &q);
        system("clear");
    }


    int d, i, b=0, soma=4;
    j=0;

    for(j=0; j<q; j++) // for usado para rodar a quantidade de partidas
    {

        system("clear");

        printf("\t\t                           <<==============>>\n");
        printf("\t\t                           ||   PARTIDA %i  || \n", j+1);
        printf("\t\t                           <<==============>>\n");

        printf("\n\t\t\t\t+=================================+ \n");
        printf("\t\t\t\t||     Vermelho    |      1      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Azul        |      2      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Marrom      |      3      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Laranja     |      4      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Roxo        |      5      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Cinza       |      6      || \n");
        printf("\t\t\t\t+=================================+ \n\n");

        if(j%2==0)
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 1:  ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador2);//jogador que vai adivinha a senha

        }
        else
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 2   ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador1);//jogador que vai adivinha a senha
        }

        printf("\n\t\t\t\t     Digite sua senha: ");
        scanf("%i", &x);

        s1 = x/1000;
        s2 = (x%1000)/100;
        s3 = ((x%1000)%100)/10;
        s4 = ((x%1000)%100)%10;

        if(s1>7 || s1==0 || s2==0 || s3==0 || s4==0)
        {
            do
            {
                system("clear");
                printf("\n\n\t\t\t\t           Senha invalida.\n");

                printf("\t\t\t     +---------------------------------------+\n");
                printf("\t\t\t     |              OBSERVACOES              | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    A senha deve conter 4 digitos      | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |  Utilize apenas os numeros de 1 a 6   | \n");
                printf("\t\t\t     +---------------------------------------+ \n\n");
                printf("\n\n\t\t\t\t     Digite sua senha: ");
                scanf("%i", &x);
                s1 = x/1000;
                s2 = (x%1000)/100;
                s3 = ((x%1000)%100)/10;
                s4 = ((x%1000)%100)%10;

            }
            while(s1>7 || s1==0 || s2==0 || s3==0 || s4==0);
        }

        printf("\n");
        printf("\t                               +==================+ \n");
        printf("\t                               ||   AGORA VAMOS  || \n");
        printf("\t                               ||  AO DESAFIO!!! || \n");
        printf("\t                               +==================+ \n\n\n\n");
        system("pause");
        system("clear");

        if(j>0)
        {
            for(int g=0; g<40; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<10; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=4;
        }

        i=0;
        while(i<10)// usado para rodar a quantidade de tentativas(jogadas)//
        {
            system("clear");
            //jogada//
            tabuleiro1();
            printf("\t\t\t                 Adivinhe a senha: ");
            scanf("%i", &ss);
            if(i>0)//if  usado para acrescentar +4 //
            {
                b = b+4; // b e soma sao variaveis auxiliares
                soma = soma+4;
            }
            for(int k=b; k<soma; k++)
            {
                d = ss%10;
                casas[k]= d;
                ss = ss/10;

            }

            // testar os pinos//
            //TESTANTO O PRIMEIRO DIGITO
            if(s1 == casas[soma-1])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s1 == casas[h] && (preto[i]+branco[i])<4)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }

            }
            //TESTANDO O SEGUNDO DIGITO
            if(s2 == casas[soma-2])
            {
                preto[i]= preto[i] + 1;
            }

            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s2 == casas[h] && (preto[i]+branco[i])<4)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }

            //TESTANDO O TERCEIRO DIGIT0
            if(s3 == casas[soma-3])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s3 == casas[h] &&(preto[i]+branco[i])<4)
                    {
                        branco[i] = branco[i] + 1;
                    }

                }
            }

            //TESTANDO O QUARTO DIGITO
            if(s4 == casas[soma-4])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s4 == casas[h] && (preto[i]+branco[i])<4)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }

            vazio[i]= vazio[i] - (branco[i]+preto[i]);

            //testar se ganhou o jogo ou n�o//
            if(preto[i]==4)
            {
                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
                printf("\n                                       ||  PARABENS! VOCE ACERTOU!||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }

            if(i==9)
            {
                for(int g=0; g<40; g++)
                {
                    casas[g]=0;
                }
                for(int g=0; g<10; g++)
                {
                    preto[g]=0;
                    branco[g]=0;
                    vazio[g]=4;
                }
                b=0;
                d=0;
                soma=4;

                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i %i %i %i ||", s1, s2, s3, s4);
                printf("\n                                       || QUE PENA! VOCE PERDEU:( ||");
                printf("\n                                       +===========================+\n\n");
            }

            i++;

        }
    }

        if(pontos1 == pontos2)
        {
            system("clear");
            printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
            printf("\nO JOGO DEU EMPARTE!!!");
            pontos1 = 0;
            pontos2 = 0;
        }

        else if(pontos1 > pontos2)
        {
            system("clear");
            printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
            printf("\nParabens %s! Voce venceu o jogo!", jogador1);
            pontos1 = 0;
            pontos2 = 0;
        }
        else
        {
            system("clear");
            printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
            printf("\nParabens %s! Voce venceu o jogo!", jogador2);
            pontos1 = 0;
            pontos2 = 0;
        }

        printf("\n\t  +==========================================================================+\n");
        printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
        printf("\t  |--------------------------------------------------------------------------|\n");
        printf("\t  |                          2 - IR PARA O MENU                              |\n");
        printf("\t  +==========================================================================+\n");

        printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
        scanf("%i", &acabou);

        if (acabou == 1)
        {
            facil_com_repeticao2();
            for(int g=0; g<40; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<10; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=4;
        }
        else
        {
            for(int g=0; g<40; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<10; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=4;
            menu();
        }
}

void medio_com_repeticao()
{
    //nivel medio, com dois jogadores, sem repeticao de cores//

    int x, s;
    vazio[0] = 5;
    vazio[1] = 5;
    vazio[2] = 5;
    vazio[3] = 5;
    vazio[4] = 5;
    vazio[5] = 5;
    vazio[6] = 5;
    vazio[7] = 5;
    vazio[8] = 5;
    vazio[9] = 5;
    vazio[10] = 5;
    vazio[11] = 5;

    system("clear");

    printf("\t      +==================================================================+\n");
    printf("\t      ||  JOGADOR X JOGADOR  |  NIVEL MEDIO  |  COM REPETICAO DE CORES  ||\n");
    printf("\t      ||----------------------------------------------------------------||\n");
    printf("\t      ||                        VAMOS COMECAR!!!                        ||\n");
    printf("\t      +==================================================================+\n\n");


    printf("\t\t\t\tNOME DO JOGADOR 1: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    printf("\t\t\t\tNOME DO JOGADOR 2: ");
    fflush(stdin);
    fgets(jogador2,20,stdin);
    jogador2[strcspn(jogador2, "\n")] = 0;

    printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
    printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
    scanf("%i", &q);


    while(q%2!=0)
    {
        printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
        printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
        scanf("%i", &q);
        system("clear");
    }

    int d, i, b=0, soma=5, h=0;
    j=0;

    for(j=0; j<q; j++)
    {

        system("clear");

        printf("\t\t                           <<==============>>\n");
        printf("\t\t                           ||   PARTIDA %i  || \n", j+1);
        printf("\t\t                           <<==============>>\n");

        printf("\n\t\t\t\t+=================================+ \n");
        printf("\t\t\t\t||     Vermelho    |      1      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Azul        |      2      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Marrom      |      3      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Laranja     |      4      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Roxo        |      5      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Cinza       |      6      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Verde       |      7      || \n");
        printf("\t\t\t\t+=================================+ \n\n");

        if(j%2==0)
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 1:  ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador2);

        }
        else
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 2   ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador1);
        }

        printf("\n\t\t\t\t     Digite sua senha: ");
        scanf("%i", &x);

        s1 = x/10000;
        s2 = (x%10000)/1000;
        s3 = ((x%10000)%1000)/100;
        s4 = (((x%10000)%1000)%100)/10;
        s5 = (((x%10000)%1000)%100)%10;



        if(s1>8 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0)
        {
            do
            {
                system("clear");
                printf("\n\n\t\t\t\t           Senha invalida.\n");

                printf("\t\t\t     +---------------------------------------+\n");
                printf("\t\t\t     |              OBSERVACOES              | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    A senha deve conter 5 digitos      | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |  Utilize apenas os numeros de 1 a 7   | \n");
                printf("\t\t\t     +---------------------------------------+ \n\n");
                printf("\n\n\t\t\t\t     Digite sua senha: ");
                scanf("%i", &x);
                s1 = x/10000;
                s2 = (x%10000)/1000;
                s3 = ((x%10000)%1000)/100;
                s4 = (((x%10000)%1000)%100)/10;
                s5 = (((x%10000)%1000)%100)%10;

            }
            while(s1>8 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0);
        }



        printf("\n");
        printf("\t                               +==================+ \n");
        printf("\t                               ||   AGORA VAMOS  || \n");
        printf("\t                               ||  AO DESAFIO!!! || \n");
        printf("\t                               +==================+ \n\n\n\n");
        system("pause");
        system("clear");

        if(j>0)
        {
            for(int g=0; g<60; g++)//usado para zerar as casas
            {
                casas[g]=0;
            }
            for(int g=0; g<12; g++)  //usar para zerar o peto, branco e vazio
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=5;
            }
            b=0;
            d=0;
            soma=5;
        }

        i=0;
        while(i<12)// usado para rodar a quantidade de tentativas(jogadas)//
        {
            system("clear");
            //jogada//
            tabuleiro2();
            printf("\t\t\t                 Adivinhe a senha: ");
            scanf("%i", &s);
            if(i>0)//if  usado para acrescentar +4 //
            {
                b = b+5;
                soma = soma + 5;
            }
            for(int k=b; k<soma; k++)
            {
                d = s%10;
                casas[k]= d;
                s = s/10;
            }

            // testar os pinos//
            //TESTANTO O PRIMEIRO DIGITO
            if(s1 == casas[soma-1])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s1 == casas[h] && (preto[i]+branco[i])<5)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }

            }
            //TESTANDO O SEGUNDO DIGITO
            if(s2 == casas[soma-2])
            {
                preto[i]= preto[i] + 1;
            }

            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s2 == casas[h] && (preto[i]+branco[i])<5)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }

            //TESTANDO O TERCEIRO DIGIT0
            if(s3 == casas[soma-3])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s3 == casas[h] &&(preto[i]+branco[i])<5)
                    {
                        branco[i] = branco[i] + 1;
                    }

                }
            }
            //TESTANDO O QUARTO DIGITO
            if(s4 == casas[soma-4])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s4 == casas[h] && (preto[i]+branco[i])<5)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }
            //TESTANDO O QUINTO DIGITO
            if(s5 == casas[soma-5])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s5 == casas[h] && (preto[i]+branco[i])<5)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }

            vazio[i]= vazio[i] - (branco[i]+preto[i]);



            //testar se ganhou o jogo ou n�o//
            if(preto[i]==5)
            {
                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i%i%i%i%i     ||", s1, s2, s3, s4, s5);
                printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }
            if(i==11 && preto[i]!=5)
            {
                for(int g=0; g<60; g++)
                {
                    casas[g]=0;
                }
                for(int g=0; g<12; g++)
                {
                    preto[g]=0;
                    branco[g]=0;
                    vazio[g]=5;
                }
                b=0;
                d=0;
                soma=5;

                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i %i %i %i %i ||", s1, s2, s3, s4, s5);
                printf("\n                                       ||   QUE PENA! VOCE ERROU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }


            i++;
        }
    }

    if(pontos1 == pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nO JOGO DEU EMPARTE!!!");
        pontos1 = 0;
        pontos2 = 0;
    }

    else if(pontos1 > pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador1);
        pontos1 = 0;
        pontos2 = 0;
    }
    else
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador2);
        pontos1 = 0;
        pontos2 = 0;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        medio_com_repeticao();
        for(int g=0; g<64; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
    }
    else
    {
        for(int g=0; g<64; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
        menu();
    }

}

void dificil_com_repeticao()
{
//nivel dificil, com dois jogadores, com repeticao de cores//

    int x, s;
    vazio[0] = 6;
    vazio[1] = 6;
    vazio[2] = 6;
    vazio[3] = 6;
    vazio[4] = 6;
    vazio[5] = 6;
    vazio[6] = 6;
    vazio[7] = 6;
    vazio[8] = 6;
    vazio[9] = 6;
    vazio[10] = 6;
    vazio[11] = 6;
    vazio[12] = 6;
    vazio[13] = 6;
    vazio[14] = 6;

    system("clear");

    printf("\t      +===================================================================+\n");
    printf("\t      ||  JOGADOR X JOGADOR  |  NIVEL DIFICIL  |  COM REPETICAO DE CORES ||\n");
    printf("\t      ||-----------------------------------------------------------------||\n");
    printf("\t      ||                         VAMOS COMECAR!!!                        ||\n");
    printf("\t      +===================================================================+\n\n");


    printf("\t\t\t\tNOME DO JOGADOR: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    printf("\t\t\t\tNOME DO JOGADOR 2: ");
    fflush(stdin);
    fgets(jogador2,20,stdin);
    jogador2[strcspn(jogador2, "\n")] = 0;

    printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
    printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
    scanf("%i", &q);


    while(q%2!=0)
    {
        printf("\n\t\t\t     QUANTAS PARTIDAS DESEJA JOGAR?\n");
        printf("\n\t\t\t(OBS: O NUMERO DE PARTIDAS DEVE SER PAR) ");
        scanf("%i", &q);
        system("clear");
    }

    int d, i, b=0, soma=6, h=0;
    j=0;

    for(j=0; j<q; j++)
    {
        system("clear");

        printf("\t\t                           <<==============>>\n");
        printf("\t\t                           ||   PARTIDA %i  || \n", j+1);
        printf("\t\t                           <<==============>>\n");

        printf("\n\t\t\t\t+=================================+ \n");
        printf("\t\t\t\t||     Vermelho    |      1      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Azul        |      2      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Marrom      |      3      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Laranja     |      4      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Roxo        |      5      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Cinza       |      6      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Verde       |      7      || \n");
        printf("\t\t\t\t||-------------------------------||\n");
        printf("\t\t\t\t||     Rosa        |      8      || \n");
        printf("\t\t\t\t+=================================+ \n\n");

        if(j%2==0)
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 1:  ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador2);

        }
        else
        {
            printf("\t\t                        +==================+\n");
            printf("\t\t                        ||    JOGADOR 2   ||\n");
            printf("\t\t                        +==================+\n");
            strcpy(nome, jogador1);
        }

        printf("\n\t\t\t\t     Digite sua senha: ");
        scanf("%i", &x);

        s1 = x/100000;
        s2 = (x%100000)/10000;
        s3 = ((x%100000)%10000)/1000;
        s4 = (((x%100000)%10000)%1000)/100;
        s5 = ((((x%100000)%10000)%1000)%100)/10;
        s6 = ((((x%100000)%10000)%1000)%100)%10;

        if(s1>9 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0 || s6==0)
        {
            do
            {
                system("clear");
                printf("\n\n\t\t\t\t           Senha invalida.\n");

                printf("\t\t\t     +---------------------------------------+\n");
                printf("\t\t\t     |              OBSERVACOES              | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |    A senha deve conter 6 digitos      | \n");
                printf("\t\t\t     |---------------------------------------|\n");
                printf("\t\t\t     |  Utilize apenas os numeros de 1 a 8   | \n");
                printf("\t\t\t     +---------------------------------------+ \n\n");
                printf("\n\n\t\t\t\t     Digite sua senha: ");
                scanf("%i", &x);
                s1 = x/100000;
                s2 = (x%100000)/10000;
                s3 = ((x%100000)%10000)/1000;
                s4 = (((x%100000)%10000)%1000)/100;
                s5 = ((((x%100000)%10000)%1000)%100)/10;
                s6 = ((((x%100000)%10000)%1000)%100)%10;

            }
            while(s1>9 || s1==0 || s2==0 || s3==0 || s4==0 || s5==0 || s6==0);
        }



        printf("\n");
        printf("\t                               +==================+ \n");
        printf("\t                               ||   AGORA VAMOS  || \n");
        printf("\t                               ||  AO DESAFIO!!! || \n");
        printf("\t                               +==================+ \n\n\n\n");
        system("pause");
        system("clear");

        if(j>0)
        {
            for(int g=0; g<84; g++)//usado para zerar as casas
            {
                casas[g]=0;
            }
            for(int g=0; g<14; g++)  //usar para zerar o peto, branco e vazio
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=6;
            }
            b=0;
            d=0;
            soma=6;
        }

        i=0;
        while(i<14)// usado para rodar a quantidade de tentativas(jogadas)//
        {
            system("clear");
            //jogada//
            tabuleiro3();
            printf("\t\t\t                 Adivinhe a senha: ");
            scanf("%i", &s);
            if(i>0)//if  usado para acrescentar +4 //
            {
                b = b+6;
                soma = soma + 6;
            }
            for(int k=b; k<soma; k++)
            {
                d = s%10;
                casas[k]= d;
                s = s/10;
            }

            // testar os pinos//
            //TESTANTO O PRIMEIRO DIGITO
            if(s1 == casas[soma-1])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s1 == casas[h] && (preto[i]+branco[i])<6)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }

            }
            //TESTANDO O SEGUNDO DIGITO
            if(s2 == casas[soma-2])
            {
                preto[i]= preto[i] + 1;
            }

            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s2 == casas[h] && (preto[i]+branco[i])<6)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }

            //TESTANDO O TERCEIRO DIGIT0
            if(s3 == casas[soma-3])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s3 == casas[h] &&(preto[i]+branco[i])<6)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }
            //TESTANDO O QUARTO DIGITO
            if(s4 == casas[soma-4])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s4 == casas[h] && (preto[i]+branco[i])<6)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }
            //TESTANDO O QUINTO DIGITO
            if(s5 == casas[soma-5])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s5 == casas[h] && (preto[i]+branco[i])<6)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }
            //TESTANDO O QUINTO DIGITO
            if(s6 == casas[soma-6])
            {
                preto[i]= preto[i] + 1;
            }
            else
            {
                for(int h=b; h<soma; h++)
                {
                    if(s6 == casas[h] && (preto[i]+branco[i])<6)
                    {
                        branco[i] = branco[i] + 1;
                    }
                }
            }

            vazio[i]= vazio[i] - (branco[i]+preto[i]);

            //testar se ganhou o jogo ou n�o//
            if(preto[i]==6)
            {
                printf("\n                                       +===========================+");
                printf("\n                                       ||   A SENHA ERA %i%i%i%i%i%i      ||", s1, s2, s3, s4, s5, s6);
                printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
                printf("\n                                       +===========================+\n\n");
                if(j%2==0)
                {
                    if(preto[i]!=6)
                    {
                        pontos1 = pontos1 + 1;
                    }
                }
                else
                {
                    if(preto[i]!=1)
                    {
                        pontos2 = pontos2 + 2;
                    }
                }

                system("pause");
                break;
            }

            if(i==13 && preto[i]!=6)
            {
                for(int g=0; g<84; g++)
                {
                    casas[g]=0;
                }
                for(int g=0; g<14; g++)
                {
                    preto[g]=0;
                    branco[g]=0;
                    vazio[g]=6;
                }
                b=0;
                d=0;
                soma=6;

                printf("\n                                       +=============================+");
                printf("\n                                       ||  A SENHA ERA %i %i %i %i %i %i||", s1, s2, s3, s4, s5, s6);
                printf("\n                                       ||    QUE PENA! VOCE ERROU!  ||");
                printf("\n                                       +=============================+\n\n");
                if(j%2==0)
                {
                    pontos1 = pontos1 + (i+1);
                }
                else
                {
                    pontos2 = pontos2 + (i+1);

                }
                system("pause");
                break;
            }
            i++;
        }
    }

    if(pontos1 == pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nO JOGO DEU EMPARTE!!!");
        pontos1 = 0;
        pontos2 = 0;
    }

    else if(pontos1 == pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nO JOGO DEU EMPARTE!!!");
        pontos1 = 0;
        pontos2 = 0;
    }

    else if(pontos1 > pontos2)
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador1);
        pontos1 = 0;
        pontos2 = 0;
    }
    else
    {
        system("clear");
        printf("\n\nPontuacao\n%s: %i pontos\n%s: %i pontos\n", jogador1, pontos1, jogador2, pontos2);
        printf("\nParabens %s! Voce venceu o jogo!", jogador2);
        pontos1 = 0;
        pontos2 = 0;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        dificil();
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
    }
    else
    {
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
        menu();
    }

}

void pc1_repeticao()
{
    int x, ss; //x vai ser usado para guardar minha senha pricipal e ss � usada para guardar a senha que o usuario der

    vazio[0] = 4;
    vazio[1] = 4;
    vazio[2] = 4;
    vazio[3] = 4;
    vazio[4] = 4;
    vazio[5] = 4;
    vazio[6] = 4;
    vazio[7] = 4;
    vazio[8] = 4;
    vazio[9] = 4;


    system("clear");

    printf("\t      +====================================================================+\n");
    printf("\t      ||  JOGADOR X COMPUTADOR  |  NIVEL FACIL  |  SEM REPETICAO DE CORES ||\n");
    printf("\t      ||------------------------------------------------------------------||\n");
    printf("\t      ||                           VAMOS COMECAR!!!                       ||\n");
    printf("\t      +====================================================================+\n\n");

    printf("\t\t\t\t\tNOME DO JOGADOR: "); // nome do jogador 1
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    int d, i, b=0, soma=4, u=0, igual;

    int s[4];

    // usado para gerar numeros aleatorios

    srand(time(NULL));

    s1 = 1 + rand () % 6;
    s2 = 1 + rand () % 6;
    s3 = 1 + rand () % 6;
    s4 = 1 + rand () % 6;

    printf("\n");
    printf("\t                               +========================+ \n");
    printf("\t                               ||  VAMOS AO DESAFIO!!! || \n");
    printf("\t                               +========================+ \n\n\n\n");
    system("pause");
    system("clear");

    i=0;
    while(i<10)// usado para rodar a quantidade de tentativas(jogadas)//
    {
        system("clear");
        //jogada//
        tabuleiropc();
        printf("\t\t\t                 Adivinhe a senha: ");
        scanf("%i", &ss);
        if(i>0)//if  usado para acrescentar +4 //
        {
            b = b+4;
            soma = soma+4;
        }
        for(int k=b; k<soma; k++)// usado para inserir os numeros nas casas do tabuleiro
        {
            d = ss%10;
            casas[k]= d;
            ss = ss/10;
        }
        // testar os pinos//
        //TESTANTO O PRIMEIRO DIGITO
        if(s1 == casas[soma-1])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s1 == casas[h] && (preto[i]+branco[i])<4)
                {
                    branco[i] = branco[i] + 1;
                }
            }

        }
        //TESTANDO O SEGUNDO DIGITO
        if(s2 == casas[soma-2])
        {
            preto[i]= preto[i] + 1;
        }

        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s2 == casas[h] && (preto[i]+branco[i])<4)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }

        //TESTANDO O TERCEIRO DIGIT0
        if(s3 == casas[soma-3])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s3 == casas[h] &&(preto[i]+branco[i])<4)
                {
                    branco[i] = branco[i] + 1;
                }

            }
        }

        //TESTANDO O QUARTO DIGITO
        if(s4 == casas[soma-4])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s4 == casas[h] && (preto[i]+branco[i])<4)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }
        vazio[i]= vazio[i] - (branco[i]+preto[i]);


        //testar se ganhou o jogo ou n�o//
        if(preto[i]==4)
        {
            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
            printf("\n                                       ||  PARABENS! VOCE ACERTOU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }
        if(i==9 && preto[i]!=4)
        {
            for(int g=0; g<40; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<10; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=4;
            }
            b=0;
            d=0;
            soma=4;

            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i %i %i %i   ||", s1, s2, s3, s4);
            printf("\n                                       ||  QUE PENA! VOCE ERROU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }

        i++;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        pc1_repeticao();
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
    }
    else
    {
        for(int g=0; g<40; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<10; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=4;
        }
        b=0;
        d=0;
        soma=4;
        menu();
    }



}

void pc2_repeticao()
{
//nivel medio, jogar com pc, sem repeticao de cores//

    int x, ss;
    vazio[0] = 5;
    vazio[1] = 5;
    vazio[2] = 5;
    vazio[3] = 5;
    vazio[4] = 5;
    vazio[5] = 5;
    vazio[6] = 5;
    vazio[7] = 5;
    vazio[8] = 5;
    vazio[9] = 5;
    vazio[10] = 5;
    vazio[11] = 5;

    system("clear");

    printf("\t      +====================================================================+\n");
    printf("\t      ||  JOGADOR X COMPUTADOR  |  NIVEL  MEDIO  | COM REPETICAO DE CORES ||\n");
    printf("\t      ||------------------------------------------------------------------||\n");
    printf("\t      ||                           VAMOS COMECAR!!!                       ||\n");
    printf("\t      +====================================================================+\n\n");


    printf("\t\t\t\t\tNOME DO JOGADOR: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    int d, i, b=0, soma=5, igual;

    srand(time(NULL));

    s1 = 1 + rand () % 7;
    s2 = 1 + rand () % 7;
    s3 = 1 + rand () % 7;
    s4 = 1 + rand () % 7;
    s5 = 1 + rand () % 7;

    printf("\n");
    printf("\t                               +========================+ \n");
    printf("\t                               ||  VAMOS AO DESAFIO!!! || \n");
    printf("\t                               +========================+ \n\n\n\n");
    system("pause");
    system("clear");

    i=0;
    while(i<12)// usado para rodar a quantidade de tentativas(jogadas)//
    {
        system("clear");
        //jogada//
        tabuleiropc2();
        printf("\t\t\t                 Adivinhe a senha: ");
        scanf("%i", &ss);
        if(i>0)//if  usado para acrescentar +4 //
        {
            b = b+5;
            soma = soma + 5;
        }
        for(int k=b; k<soma; k++)
        {
            d = ss%10;
            casas[k]= d;
            ss = ss/10;
        }

        // testar os pinos//
        //TESTANTO O PRIMEIRO DIGITO
        if(s1 == casas[soma-1])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s1 == casas[h] && (preto[i]+branco[i])<5)
                {
                    branco[i] = branco[i] + 1;
                }
            }

        }
        //TESTANDO O SEGUNDO DIGITO
        if(s2 == casas[soma-2])
        {
            preto[i]= preto[i] + 1;
        }

        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s2 == casas[h] && (preto[i]+branco[i])<5)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }

        //TESTANDO O TERCEIRO DIGIT0
        if(s3 == casas[soma-3])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s3 == casas[h] &&(preto[i]+branco[i])<5)
                {
                    branco[i] = branco[i] + 1;
                }

            }
        }
        //TESTANDO O QUARTO DIGITO
        if(s4 == casas[soma-4])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s4 == casas[h] && (preto[i]+branco[i])<5)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }
        //TESTANDO O QUINTO DIGITO
        if(s5 == casas[soma-5])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s5 == casas[h] && (preto[i]+branco[i])<5)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }

        vazio[i]= vazio[i] - (branco[i]+preto[i]);

        //testar se ganhou o jogo ou n�o//
        if(preto[i]==5)
        {
            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i%i%i%i%i     ||", s1, s2, s3, s4, s5);
            printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }

        if(i==11)
        {
            for(int g=0; g<60; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<12; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=5;
            }
            b=0;
            d=0;
            soma=5;


            printf("\n                                       +===========================+");
            printf("\n                                       ||    A senha era %i%i%i%i%i   ||", s1, s2, s3, s4, s5);
            printf("\n                                       || QUE PENA! VOCE PERDEU:( ||");
            printf("\n                                       +===========================+\n\n");
        }


        i++;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        pc2_repeticao();
        for(int g=0; g<60; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
    }
    else
    {
        for(int g=0; g<60; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<12; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=5;
        }
        b=0;
        d=0;
        soma=5;
        menu();
    }

}
void pc3_repeticao()
{

    int x, ss;
    vazio[0] = 6;
    vazio[1] = 6;
    vazio[2] = 6;
    vazio[3] = 6;
    vazio[4] = 6;
    vazio[5] = 6;
    vazio[6] = 6;
    vazio[7] = 6;
    vazio[8] = 6;
    vazio[9] = 6;
    vazio[10] = 6;
    vazio[11] = 6;
    vazio[12] = 6;
    vazio[13] = 6;
    vazio[14] = 6;

    system("clear");

    printf("\t      +======================================================================+\n");
    printf("\t      ||  JOGADOR X COMPUTADOR  |  NIVEL DIFICIL  |  COM REPETICAO DE CORES ||\n");
    printf("\t      ||--------------------------------------------------------------------||\n");
    printf("\t      ||                           VAMOS COMECAR!!!                         ||\n");
    printf("\t      +======================================================================+\n\n");

    printf("\t\t\t\t\tNOME DO JOGADOR: ");
    fflush(stdin);
    fgets(jogador1,20,stdin);
    jogador1[strcspn(jogador1, "\n")] = 0;

    strcpy(nome, jogador1);

    int d, i, b=0, soma=6, igual;

    srand(time(NULL));

    s1 = 1 + rand () % 8;
    s2 = 1 + rand () % 8;
    s3 = 1 + rand () % 8;
    s4 = 1 + rand () % 8;
    s5 = 1 + rand () % 8;
    s6 = 1 + rand () % 8;

    printf("\n");
    printf("\t                               +========================+ \n");
    printf("\t                               ||  VAMOS AO DESAFIO!!! || \n");
    printf("\t                               +========================+ \n\n\n\n");
    system("pause");
    system("clear");

    i=0;
    while(i<14)// usado para rodar a quantidade de tentativas(jogadas)//
    {
        system("clear");
        //jogada//
        tabuleiropc3();
        printf("\t\t\t                 Adivinhe a senha: ");
        scanf("%i", &ss);
        if(i>0)//if  usado para acrescentar +4 //
        {
            b = b+6;
            soma = soma + 6;
        }
        for(int k=b; k<soma; k++)
        {
            d = ss%10;
            casas[k]= d;
            ss = ss/10;
        }

// testar os pinos//
        //TESTANTO O PRIMEIRO DIGITO
        if(s1 == casas[soma-1])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s1 == casas[h] && (preto[i]+branco[i])<6)
                {
                    branco[i] = branco[i] + 1;
                }
            }

        }
        //TESTANDO O SEGUNDO DIGITO
        if(s2 == casas[soma-2])
        {
            preto[i]= preto[i] + 1;
        }

        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s2 == casas[h] && (preto[i]+branco[i])<6)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }

        //TESTANDO O TERCEIRO DIGIT0
        if(s3 == casas[soma-3])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s3 == casas[h] &&(preto[i]+branco[i])<6)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }
        //TESTANDO O QUARTO DIGITO
        if(s4 == casas[soma-4])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s4 == casas[h] && (preto[i]+branco[i])<6)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }
        //TESTANDO O QUINTO DIGITO
        if(s5 == casas[soma-5])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s5 == casas[h] && (preto[i]+branco[i])<6)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }
        //TESTANDO O QUINTO DIGITO
        if(s6 == casas[soma-6])
        {
            preto[i]= preto[i] + 1;
        }
        else
        {
            for(int h=b; h<soma; h++)
            {
                if(s6 == casas[h] && (preto[i]+branco[i])<6)
                {
                    branco[i] = branco[i] + 1;
                }
            }
        }

        vazio[i]= vazio[i] - (branco[i]+preto[i]);


        //testar se ganhou o jogo ou n�o//
        if(preto[i]==5)
        {
            printf("\n                                       +===========================+");
            printf("\n                                       ||   A SENHA ERA %i%i%i%i%i%i     ||", s1, s2, s3, s4, s5,s6);
            printf("\n                                       || PARABENS! VOCE ACERTOU! ||");
            printf("\n                                       +===========================+\n\n");
            break;
        }

        if(i==11)
        {
            for(int g=0; g<84; g++)
            {
                casas[g]=0;
            }
            for(int g=0; g<14; g++)
            {
                preto[g]=0;
                branco[g]=0;
                vazio[g]=6;
            }
            b=0;
            d=0;
            soma=6;


            printf("\n                                       +===========================+");
            printf("\n                                       ||    A SENHA ERA %i%i%i%i%i   ||", s1, s2, s3, s4, s5,s6);
            printf("\n                                       || QUE PENA! VOCE PERDEU:( ||");
            printf("\n                                       +===========================+\n\n");
        }


        i++;
    }

    printf("\n\t  +==========================================================================+\n");
    printf("\t  |                          1 - JOGAR NOVAMENTE                             |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - IR PARA O MENU                              |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
    scanf("%i", &acabou);

    if (acabou == 1)
    {
        pc2_repeticao();
        for(int g=0; g<84; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<14; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=6;
        }
        b=0;
        d=0;
        soma=6;
    }
    else
    {
        for(int g=0; g<84; g++)
        {
            casas[g]=0;
        }
        for(int g=0; g<14; g++)
        {
            preto[g]=0;
            branco[g]=0;
            vazio[g]=6;
        }
        b=0;
        d=0;
        soma=6;
        menu();
    }
}
void jogadores()
{
    system("clear");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                                 MODO DE JOGO                             |\n");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                          0 - VOLTAR AO MENU PRINCIPAL                    |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          1 - JOGADOR X JOGADOR                           |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                          2 - JOGADOR X COMPUTADOR                        |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tESCOLHA O MODO EM QUE DESEJA JOGAR: ");
}

void dificuldade()
{
    system("clear");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                           NIVEIS DE DIFICULDADE                          |\n");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                         0 - VOLTAR AO MENU PRINCIPAL                     |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                         1 - NIVEL FACIL                                  |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                         2 - NIVEL MEDIO                                  |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                         3 - NIVEL DIFICIL                                |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tESCOLHA O NIVEL QUE DESEJA JOGAR: ");
}

void cores()
{
    system("clear");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                           MENU DE REPETICAO DE CORES                     |\n");
    printf("\t  +==========================================================================+\n");
    printf("\t  |                         0 - VOLTAR AO MENU PRINCIPAL                     |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                         1 - PODE REPETIR AS CORES                         |\n");
    printf("\t  |--------------------------------------------------------------------------|\n");
    printf("\t  |                         2 - NAO PODE REPETIR CORES                       |\n");
    printf("\t  +==========================================================================+\n");

    printf("\n\t\t\t\tO QUE VOCE DESEJA FAZER? ");
}

void instrucoes()
{
    system("clear");
    printf ("\t+---------------------------------------------- ---------------------------+ \n " );
    printf ("\t|----------------------------MASTERMIND---------------- -------------------| \n " );
    printf ("\t| O jogo consiste em descobrir a senha secreta.                            | \n " );
    printf ("\t|                                                                          | \n " );
    printf ("\t| A palavra 'preto' indica posicao e numero correto                        | \n " );
    printf ("\t|                                                                          | \n " );
    printf ("\t| Ex: preto(2) indica que ha dois valores e posicoes corretas              | \n " );
    printf ("\t|                                                                          | \n " );
    printf ("\t| A palavra 'branco' indica somente valor correto                          | \n " );
    printf ("\t|                                                                          | \n " );
    printf ("\t| Ex: branco(2) indica que ha dois valores corretos, mas as posicoes estao | \n " );
    printf ("\t| erradas.                                                                 | \n " );
    printf ("\t|                                                                          | \n " );
    printf ("\t| A palavra 'vazio' indica que nem a cor e nem a posicao entao corretas.   | \n " );
    printf ("\t|                                                                          | \n " );
    printf ("\t| Obs: O jogo nunca avisa quais valores ou posicoes estao corretas!        | \n " );
    printf ("\t+---------------------------------------------- ---------------------------+ \n " );

}

void tabuleiro1()
{

    printf("\n\n\n");
    printf("\t\t\t\t+=================================+                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[39], casas[38], casas[37], casas[36], preto[9], branco[9], vazio[9]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[35], casas[34], casas[33], casas[32], preto[8], branco[8], vazio[8]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[31], casas[30], casas[29], casas[28], preto[7], branco[7], vazio[7]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[27], casas[26], casas[25], casas[24], preto[6], branco[6], vazio[6]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[23], casas[22], casas[21], casas[20], preto[5], branco[5], vazio[5]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazios %i  \n", casas[19], casas[18], casas[17], casas[16], preto[4], branco[4], vazio[4]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[15], casas[14], casas[13], casas[12], preto[3], branco[3], vazio[3]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[11], casas[10], casas[9], casas[8], preto[2], branco[2], vazio[2]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[7], casas[6], casas[5], casas[4], preto[1], branco[1], vazio[1]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[3], casas[2], casas[1], casas[0], preto[0], branco[0], vazio[0]);
    printf("\t\t\t\t+=================================+                                           \n");
    printf("\t\t\t\t                                            Jogador atual: %s\n", nome);
    printf("\t\t\t\t+=================================+                                           \n");
    printf("\t\t\t\t|| 1 - Vermelho  |  4 - Laranja  ||         Partida atual: %i\n", q-(q-j)+1);
    printf("\t\t\t\t||-------------------------------||                                               \n");
    printf("\t\t\t\t|| 2 - Azul      |  5 - Roxo     ||         Partida restante: %i\n", (q-j)-1);
    printf("\t\t\t\t||-------------------------------||                                                   \n");
    printf("\t\t\t\t|| 3 - Marrom    |  6 - Cinza    ||         Pontuacoes: %s %i pontos\n", jogador1, pontos1);
    printf("\t\t\t\t+=================================+                     %s %i pontos\n\n", jogador2, pontos2);

}

void tabuleiro2()
{

    printf("\n\n\n");
    printf("\t\t\t\t+=========================================+                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[59], casas[58], casas[57], casas[56], casas[44], preto[11], branco[11], vazio[11]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[54], casas[53], casas[52], casas[51], casas[50], preto[10], branco[10], vazio[10]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[49], casas[48], casas[47], casas[46], casas[45], preto[9], branco[9], vazio[9]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[44], casas[43], casas[42], casas[41], casas[40], preto[8], branco[8], vazio[8]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[39], casas[38], casas[37], casas[36], casas[35], preto[7], branco[7], vazio[7]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[34], casas[33], casas[32], casas[31], casas[30], preto[6], branco[6], vazio[6]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[29], casas[28], casas[27], casas[26], casas[25], preto[5], branco[5], vazio[5]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazios %i  \n", casas[24], casas[23], casas[22], casas[21], casas[20], preto[4], branco[4], vazio[4]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[19], casas[18], casas[17], casas[16], casas[15], preto[3], branco[3], vazio[3]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[14], casas[13], casas[12], casas[11], casas[10], preto[2], branco[2], vazio[2]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[9], casas[8], casas[7], casas[6], casas[5], preto[1], branco[1], vazio[1]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[4], casas[3], casas[2], casas[1], casas[0], preto[0], branco[0], vazio[0]);
    printf("\t\t\t\t+=========================================+                                           \n");
    printf("\t\t\t\t \n");
    printf("\t\t\t\t+=================================+                                                     \n");
    printf("\t\t\t\t|| 1 - Vermelho  |  5 - Roxo     ||         Jogador atual: %s\n", nome);
    printf("\t\t\t\t||-------------------------------||                                                      \n");
    printf("\t\t\t\t|| 2 - Azul      |  6 - Cinza    ||         Partida atual: %i\n", q-(q-j)+1);
    printf("\t\t\t\t||-------------------------------||                                                       \n");
    printf("\t\t\t\t|| 3 - Marrom    |  7 - Verde    ||         Partida restante: %i\n", (q-j)-1);
    printf("\t\t\t\t||-------------------------------||                                                       \n");
    printf("\t\t\t\t||           7 - Verde           ||         Pontuacoes: %s %i pontos\n", jogador1, pontos1);
    printf("\t\t\t\t+=================================+                     %s %i pontos\n\n", jogador2, pontos2);

}

void tabuleiro3()
{
    printf("\n");
    printf("\t\t\t\t+=================================================+                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[83], casas[82], casas[81], casas[80], casas[79], casas[78], preto[13], branco[13], vazio[13]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[77], casas[76], casas[75], casas[74], casas[73], casas[72], preto[12], branco[12], vazio[12]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[71], casas[70], casas[69], casas[68], casas[67], casas[66], preto[11], branco[11], vazio[11]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[65], casas[64], casas[63], casas[62], casas[61], casas[60], preto[10], branco[10], vazio[10]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[59], casas[58], casas[57], casas[56], casas[55], casas[54], preto[9], branco[9], vazio[9]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[53], casas[52], casas[51], casas[50], casas[49], casas[48], preto[8], branco[8], vazio[8]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[47], casas[46], casas[45], casas[44], casas[43], casas[42], preto[7], branco[7], vazio[7]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[41], casas[40], casas[39], casas[38], casas[37], casas[36], preto[6], branco[6], vazio[6]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[35], casas[34], casas[33], casas[32], casas[31], casas[30], preto[5], branco[5], vazio[5]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazios %i  \n", casas[29], casas[28], casas[27], casas[26], casas[25], casas[24], preto[4], branco[4], vazio[4]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[23], casas[22], casas[21], casas[20], casas[19], casas[18], preto[3], branco[3], vazio[3]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[17], casas[16], casas[15], casas[14], casas[13], casas[12], preto[2], branco[2], vazio[2]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[11], casas[10], casas[9], casas[8], casas[7], casas[6], preto[1], branco[1], vazio[1]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[5], casas[4], casas[3], casas[2], casas[1], casas[0], preto[0], branco[0], vazio[0]);
    printf("\t\t\t\t+=================================================+                                           \n");
    printf("\t\t\t\t \n");
    printf("\t\t\t\t+=================================+                                                     \n");
    printf("\t\t\t\t|| 1 - Vermelho  |  5 - Roxo     ||         Jogador atual: %s\n", nome);
    printf("\t\t\t\t||-------------------------------||                                                      \n");
    printf("\t\t\t\t|| 2 - Azul      |  6 - Cinza    ||         Partida atual: %i\n", q-(q-j)+1);
    printf("\t\t\t\t||-------------------------------||                                                       \n");
    printf("\t\t\t\t|| 3 - Marrom    |  7 - Verde    ||         Partida restante: %i\n", (q-j)-1);
    printf("\t\t\t\t||-------------------------------||                                                       \n");
    printf("\t\t\t\t|| 4 - Laranja   |  8 -  Rosa    ||         Pontuacoes: %s %i pontos\n", jogador1, pontos1);
    printf("\t\t\t\t+=================================+                     %s %i pontos\n\n", jogador2, pontos2);

}

void tabuleiropc()
{

    printf("\n\n\n");
    printf("\t\t\t\t+=================================+                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[39], casas[38], casas[37], casas[36], preto[9], branco[9], vazio[9]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[35], casas[34], casas[33], casas[32], preto[8], branco[8], vazio[8]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[31], casas[30], casas[29], casas[28], preto[7], branco[7], vazio[7]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[27], casas[26], casas[25], casas[24], preto[6], branco[6], vazio[6]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[23], casas[22], casas[21], casas[20], preto[5], branco[5], vazio[5]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazios %i  \n", casas[19], casas[18], casas[17], casas[16], preto[4], branco[4], vazio[4]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[15], casas[14], casas[13], casas[12], preto[3], branco[3], vazio[3]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[11], casas[10], casas[9], casas[8], preto[2], branco[2], vazio[2]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[7], casas[6], casas[5], casas[4], preto[1], branco[1], vazio[1]);
    printf("\t\t\t\t||-------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[3], casas[2], casas[1], casas[0], preto[0], branco[0], vazio[0]);
    printf("\t\t\t\t+=================================+                                           \n");
    printf("\t\t\t\t                                          \n");
    printf("\t\t\t\t+=================================+       \n");
    printf("\t\t\t\t|| 1 - Vermelho  |  4 - Laranja  ||       \n");
    printf("\t\t\t\t||-------------------------------||       \n");
    printf("\t\t\t\t|| 2 - Azul      |  5 - Roxo     ||       Jogador atual: %s\n", jogador1);
    printf("\t\t\t\t||-------------------------------||        \n");
    printf("\t\t\t\t|| 3 - Marrom    |  6 - Cinza    ||        \n");
    printf("\t\t\t\t+=================================+        \n\n");

}

void tabuleiropc2()
{
    printf("\t\t\t\t+=========================================+                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[59], casas[58], casas[57], casas[56], casas[44], preto[11], branco[11], vazio[11]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[54], casas[53], casas[52], casas[51], casas[50], preto[10], branco[10], vazio[10]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[49], casas[48], casas[47], casas[46], casas[45], preto[9], branco[9], vazio[9]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[44], casas[43], casas[42], casas[41], casas[40], preto[8], branco[8], vazio[8]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[39], casas[38], casas[37], casas[36], casas[35], preto[7], branco[7], vazio[7]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[34], casas[33], casas[32], casas[31], casas[30], preto[6], branco[6], vazio[6]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[29], casas[28], casas[27], casas[26], casas[25], preto[5], branco[5], vazio[5]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazios %i  \n", casas[24], casas[23], casas[22], casas[21], casas[20], preto[4], branco[4], vazio[4]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[19], casas[18], casas[17], casas[16], casas[15], preto[3], branco[3], vazio[3]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[14], casas[13], casas[12], casas[11], casas[10], preto[2], branco[2], vazio[2]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[9], casas[8], casas[7], casas[6], casas[5], preto[1], branco[1], vazio[1]);
    printf("\t\t\t\t||---------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[4], casas[3], casas[2], casas[1], casas[0], preto[0], branco[0], vazio[0]);
    printf("\t\t\t\t+=========================================+                                           \n");
    printf("\t\t\t\t \n");
    printf("\t\t\t\t+=================================+         \n");
    printf("\t\t\t\t|| 1 - Vermelho  |  5 - Roxo     ||         \n");
    printf("\t\t\t\t||-------------------------------||         \n");
    printf("\t\t\t\t|| 2 - Azul      |  6 - Cinza    ||         \n");
    printf("\t\t\t\t||-------------------------------||         Jogador atual: %s\n", jogador1);
    printf("\t\t\t\t|| 3 - Marrom    |  7 - Verde    ||         \n", (q-j)-1);
    printf("\t\t\t\t||-------------------------------||         \n");
    printf("\t\t\t\t||           7 - Verde           ||         \n");
    printf("\t\t\t\t+=================================+         \n\n");

}

void tabuleiropc3()
{
    printf("\n\n\n");
    printf("\t\t\t\t+=================================================+                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[83], casas[82], casas[81], casas[80], casas[79], casas[78], preto[13], branco[13], vazio[13]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[77], casas[76], casas[75], casas[74], casas[73], casas[72], preto[12], branco[12], vazio[12]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[71], casas[70], casas[69], casas[68], casas[67], casas[66], preto[11], branco[11], vazio[11]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[65], casas[64], casas[63], casas[62], casas[61], casas[60], preto[10], branco[10], vazio[10]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[59], casas[58], casas[57], casas[56], casas[55], casas[54], preto[9], branco[9], vazio[9]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[53], casas[52], casas[51], casas[50], casas[49], casas[48], preto[8], branco[8], vazio[8]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[47], casas[46], casas[45], casas[44], casas[43], casas[42], preto[7], branco[7], vazio[7]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[41], casas[40], casas[39], casas[38], casas[37], casas[36], preto[6], branco[6], vazio[6]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[35], casas[34], casas[33], casas[32], casas[31], casas[30], preto[5], branco[5], vazio[5]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazios %i  \n", casas[29], casas[28], casas[27], casas[26], casas[25], casas[24], preto[4], branco[4], vazio[4]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[23], casas[22], casas[21], casas[20], casas[19], casas[18], preto[3], branco[3], vazio[3]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[17], casas[16], casas[15], casas[14], casas[13], casas[12], preto[2], branco[2], vazio[2]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[11], casas[10], casas[9], casas[8], casas[7], casas[6], preto[1], branco[1], vazio[1]);
    printf("\t\t\t\t||-----------------------------------------------||                                           \n");
    printf("\t\t\t\t||   %i   |   %i   |   %i   |   %i   |   %i   |   %i   ||   Preto: %i   Branco: %i   Vazio: %i  \n", casas[5], casas[4], casas[3], casas[2], casas[1], casas[0], preto[0], branco[0], vazio[0]);
    printf("\t\t\t\t+=================================================+                                           \n");
    printf("\t\t\t\t \n");
    printf("\t\t\t\t+=================================+         \n");
    printf("\t\t\t\t|| 1 - Vermelho  |  5 - Roxo     ||         \n");
    printf("\t\t\t\t||-------------------------------||         \n");
    printf("\t\t\t\t|| 2 - Azul      |  6 - Cinza    ||         \n");
    printf("\t\t\t\t||-------------------------------||         Jogador atual: %s\n", nome );
    printf("\t\t\t\t|| 3 - Marrom    |  7 - Verde    ||         \n");
    printf("\t\t\t\t||-------------------------------||         \n");
    printf("\t\t\t\t|| 4 - Laranja   |  8 -  Rosa    ||         \n");
    printf("\t\t\t\t+=================================+         \n\n");

}

void sair()
{
    exit(0);
}

int main()
{

    int op, conf, num, dif;

    while(1)
    {
        menu();
        scanf("%i", &op);
        switch(op)//menu principal
        {
        case 0: //sair
            exit(0);
            break;
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
        case 1: //jogar

            jogadores(); // jogador
            scanf("%i", &num);

            if(num == 0)
            {
                break;
            }

            dificuldade(); // nivel de dificuldade
            scanf("%i", &dif);
            if(dif == 0)
            {
                break;
            }

            cores(); // repeti��o de cores
            scanf("%i", &cor);
            if(cor== 0)
            {
                break;
            }

            if(num == 1 && dif == 1 && cor == 2)
            {
                facil();
            }
            if(num == 1 && dif == 2 && cor == 2)
            {
                medio();
            }
            if(num == 1 && dif == 3 && cor ==2)
            {
                dificil();
            }
            if(num == 2 && dif == 1 && cor ==2)
            {
                pc1();
            }
            if(num == 2 && dif == 2 && cor ==2)
            {
                pc2();
            }
            if(num == 2 && dif == 3 && cor ==2)
            {
                pc3();
            }
            if(num == 1 && dif == 1 && cor ==1)
            {
                facil_com_repeticao2();
            }
            if(num == 1 && dif == 2 && cor==1)
            {
                medio_com_repeticao();
            }
            if(num == 1 && dif == 3 && cor ==1)
            {
                dificil_com_repeticao();
            }
            if(num == 2 && dif ==1 && cor == 1)
            {
                pc1_repeticao();
            }
            if(num == 2 && dif == 2 && cor ==1)
            {
                pc2_repeticao();
            }
            if(num == 2 && dif == 3 && cor ==1)
            {
                pc3_repeticao();
            }
            break;
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

        case 2:
            instrucoes();
            break;
        default:
            printf("Opcao invalida. Tente novamente...");
        }
        printf("\n\n\n");
        system("pause");
    }
}

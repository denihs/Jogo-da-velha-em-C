#include <Windows.h>
#include <stdio.h>
#define DIM 3
#define CARACTER 35
#define PLAYER2 79
#define PLAYER1 88

char Continuar(char conti);
char NomeCamp(char nome1[],char nome2[]);
int ExibirTab(char tabuleiro[][DIM]);
int Modificador(char nome1[],char nome2[]);
int VerCoordenadas(char Tab[][DIM],int a, int b);
int verCadaCoor(int a);
int verCampeao(char tab[][DIM],char N1[],char N2[],int count);
int MusicVitoria(char n1[],char n2[]);
int MusicEmpate(char n1[],char n2[]);

int main()
{
    char nome1[30],nome2[30];
    char conti;
    do{
        system("clear||cls");
        NomeCamp(nome1,nome2);
        Modificador(nome1,nome2);

        printf("Querem batalhar novamente? \n");
        printf("1- JOGAR\n0- sair\n");
        printf("--->");
        do{
            scanf(" %c",&conti);
            Continuar(conti);
        }while(conti!='1'&&conti!='0');

      }while(conti=='1');
    return 0;
}
//Verificar ser os jogadores desejam continuar a jogar
char Continuar(char conti)
{
   if(conti!='1'&&conti!='0'){
        printf("Nao entendi a respostos...\n");
        printf("Repita por favor...");
    }
    return conti;
}

//Nome dos Campe�es
char NomeCamp(char nome1[],char nome2[])
{
    printf("\tENTRE COM O NOME DOS CAMPEOES\n");
    printf("\nCAMPEAO 1 --> ");
        scanf(" %30[^\n]",nome1);
    printf("\nCAMPEAO 2 --> ");
        scanf(" %30[^\n]",nome2);
    return 1;
}
//EXIBIR TABULEIRO
int ExibirTab(char tabuleiro[][DIM])
{
    int Linha,Coluna;
    for(Linha=0;Linha<DIM;Linha++){
            printf("\t");
        for(Coluna=0;Coluna<DIM;Coluna++){
                printf("%c ",tabuleiro[Linha][Coluna]);
            }
        printf("\n");
    }
    return 1;
 }

//Modificador das posi�oes do tabuleiro
int Modificador(char nome1[],char nome2[])
{
    int  Linha,Coluna,count=0,L,C;
    char tabuleiro[DIM][DIM];

   //MONTAGEM DO TABULEIRO
    for(Linha=0;Linha<DIM;Linha++){
        for(Coluna=0;Coluna<DIM;Coluna++){
            tabuleiro[Linha][Coluna]=CARACTER;
        }
    }

    do{
        count++;
        system("clear || cls");
    ExibirTab(tabuleiro);
//________________________________________
//============ENTRADA DO JOGADOR 1==================
    if (count%2 != 0){
       do{
     //----------LINHA------------
        printf("\n%s\n",nome1);
        printf("Linha: ");
          do{
            scanf("%d",&L);
            if(verCadaCoor(L)){
                printf("Como? --> ");
            }
           }while(verCadaCoor(L));
            --L;
      //----------COLUNA------------
        printf("Coluna: ");
            do{
                scanf("%d",&C);
                if(verCadaCoor(L)){
                    printf("Como? --> ");
                }
           }while(verCadaCoor(C));
            --C;
     }while(VerCoordenadas(tabuleiro,L,C));
     //----------------------------------
        tabuleiro[L][C]=PLAYER1;
//=================================================

//===============ENTRADA DO JOGADOR 2=============
       }else{
         do{
        //----------LINHA------------
           printf("\n\n%s \n",nome2);
           printf("Linha: ");
            do{
                scanf("%d",&L);
                if(verCadaCoor(L)){
                    printf("Como? --> ");
                }
            }while(verCadaCoor(L));
                --L;
         //----------COLUNA------------
            printf("Coluna: ");
               do{
                  scanf("%d",&C);
                  if(verCadaCoor(L)){
                    printf("Como? --> ");
                  }
               }while(verCadaCoor(C));
              --C;

        }while(VerCoordenadas(tabuleiro,L,C));
            tabuleiro[L][C]=PLAYER2;
       }
//=====================================================
        printf("\n");
    }while(verCampeao(tabuleiro,nome1,nome2,count));

    //EXIBIR TABELA DA JOGADA FINAL
    ExibirTab(tabuleiro);
    return 1;
}


//Verifica��o das das entradas de coordenadas
int VerCoordenadas(char Tab[][DIM],int a, int b)
{
    if (Tab[a][b]==CARACTER){
        return 0;
    }else{
        printf("\nCasa ja foi marcada :)\n");
        return 1;
    }
}
//Verifica��o de cada coordenada
int verCadaCoor(int a)
{

    if(a<1 || a>3){
        return 1;
    }else{
        return 0;
    }
}
//Verifica��o de linhas colunas e diagonais
int verCampeao(char tab[][DIM],char N1[],char N2[],int count)
{
    //TESTE DE TODA A LINHA 0
    if(tab[0][0]==PLAYER1&&tab[0][1]==PLAYER1&&tab[0][2]==PLAYER1){
        MusicVitoria(N1,N2);
        printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else if(tab[0][0]==PLAYER2&&tab[0][1]==PLAYER2&&tab[0][2]==PLAYER2){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //TESTE DE TODA A LINHA 1
    }else
        if(tab[1][0]==PLAYER1&&tab[1][1]==PLAYER1&&tab[1][2]==PLAYER1){
        MusicVitoria(N1,N2);
        printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else if(tab[1][0]==PLAYER2&&tab[1][1]==PLAYER2&&tab[1][2]==PLAYER2){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //TESTE DE TODA A LINHA 2
    }else
        if(tab[2][0]==PLAYER1&&tab[2][1]==PLAYER1&&tab[2][2]==PLAYER1){
        MusicVitoria(N1,N2);
        printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else if(tab[2][0]==PLAYER2&&tab[2][1]==PLAYER2&&tab[2][2]==PLAYER2){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //TESTE DE TODA A COLUNA 0
    }else
        if(tab[0][0]==PLAYER1&&tab[1][0]==PLAYER1&&tab[2][0]==PLAYER1){
        MusicVitoria(N1,N2);
        printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else if(tab[0][0]==PLAYER2&&tab[1][0]==PLAYER2&&tab[2][0]==PLAYER2){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //TESTE DE TODA A COLUNA 1
    }else
        if(tab[0][1]==PLAYER1&&tab[1][1]==PLAYER1&&tab[2][1]==PLAYER1){
        MusicVitoria(N1,N2);
        printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else if(tab[0][1]==PLAYER2&&tab[1][1]==PLAYER2&&tab[2][1]==PLAYER2){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //TESTE DE TODA A COLUNA 2
    }else
        if(tab[0][2]==PLAYER1&&tab[1][2]==PLAYER1&&tab[2][2]==PLAYER1){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else if(tab[0][2]==PLAYER2&&tab[1][2]==PLAYER2&&tab[2][2]==PLAYER2){
        MusicVitoria(N2,N1);
        printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //TESTE DAS DIAGONAIS
    }else
        if(tab[0][0]==PLAYER1&&tab[1][1]==PLAYER1&&tab[2][2]==PLAYER1){
            MusicVitoria(N1,N2);
            printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else
        if(tab[0][0]==PLAYER2&&tab[1][1]==PLAYER2&&tab[2][2]==PLAYER2){
            MusicVitoria(N2,N1);
            printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    }else
        if(tab[0][2]==PLAYER1&&tab[1][1]==PLAYER1&&tab[2][0]==PLAYER1){
            MusicVitoria(N1,N2);
            printf("O player %s VENCEUUUUUU\n",N1);
        return 0;
    }else
        if(tab[0][2]==PLAYER2&&tab[1][1]==PLAYER2&&tab[2][0]==PLAYER2){
            MusicVitoria(N2,N1);
            printf("O player %s VENCEUUUUUU\n",N2);
        return 0;
    //Empate...........
    }else if(count >= 9){
        MusicEmpate(N1,N2);
        printf("O jogo entre os campeoes %s e %s deu EMPATE!!!\n",N1,N2);
        return 0;
    }
 return 1;
}
//MUSICA PARA A VITORIA
int MusicVitoria(char n1[],char n2[])
{

    //PRIMEIRA ESTROFE
 printf("\n\tO campeao\n");
  Beep(330,200);
  Beep(396,200);
  Beep(440,200);
  Beep(440,470);
printf("\t%s\n",n1);
  Beep(440,200);
  Beep(495,200);
  Beep(528,200);
  Beep(528,470);
printf("\tVenceuu \n");
  Beep(528,200);
  Beep(297,200);
  Beep(495,200);
  Beep(495,470);
printf("\tA partida!\n\n");
  Beep(440,200);
  Beep(396,200);
  Beep(396,200);
  Beep(440,200);
  Beep(0,200);
//SEGUNDA ESTROFE
 printf("\tE o campeaoo\n");
  Beep(330,200);
  Beep(396,200);
  Beep(440,200);
  Beep(440,470);
printf("\t%s\n",n2);
  Beep(440,200);
  Beep(495,200);
  Beep(528,200);
  Beep(528,470);
printf("\tEh um bosta\n");
  Beep(528,200);
  Beep(297,200);
  Beep(495,200);
  Beep(495,470);
printf("\tNa sua vida\n\n");
  Beep(440,200);
  Beep(396,200);
  Beep(440,200);
  Beep(0,200);
  return 0;
}
//MUSICA NO CASO DE EMPATE
int MusicEmpate(char n1[],char n2[])
{
  printf("\n\tACABOOO\n");
   Beep(396,240);
   Beep(330,240);
   Beep(256,1000);
   Beep(0,100);
printf("\tO jogooo...\n");
   Beep(330,350);
   Beep(396,350);
   Beep(440,1050);
   Beep(330,800);
   Beep(0,150);
printf("\tEEEEEE\n");
   Beep(396,1000);
printf("\tO jogo empatoooo\n\n");
   Beep(360,270);
   Beep(396,270);
   Beep(440,270);
   Beep(297,270);
   Beep(495,1000);
   Beep(440,600);
   Beep(0,250);
   //rep
   printf("\t%s e %s\n",n1,n2);
   Beep(396,340);
   Beep(330,340);
   Beep(256,1000);
   Beep(0,100);
 printf("\tVoces saooooo\n");
   Beep(330,350);
   Beep(396,350);
   Beep(440,1050);
printf("\tRUUIIM\n");
   Beep(330,800);
   Beep(0,150);
printf("\tE merecem \n");
   Beep(396,1000);
   Beep(360,270);
   Beep(396,270);
   Beep(440,270);
   Beep(297,270);
printf("\tMorrer...\n\n");
   Beep(330,1100);

   return 0;
}

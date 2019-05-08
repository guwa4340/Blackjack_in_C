#include<string.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"blackjack.h"

int main(){
  srand(time(NULL));
  //add n value to previous cards
  char CardSuit[10];
  char CardNum[10];
  int Cardval;
  int playercards[52];
  for (int i = 0; i<52; i++){
    playercards[i] = 0;
  }
  // set all playercards to zero
  
  int dealercards[52];
  for (int i = 0; i<52; i++){
    dealercards[i] = 0;
  }
  //dealercards are set to zero
  
  int playersum = 0;
  int dealersum = 0;
  //intitialize all the sum values to zero
  
  //now the UI will initialize
  printf("Welcome to Blackjack!\n");
  printf("\n");
  printf("The dealer has dealt you these two cards:\n");
  int pd = 1;
  int n = 1;
  n = randomcard(CardSuit,CardNum,&Cardval,pd,playercards,dealercards,n);
  printf("1) %s of %s\n",CardNum,CardSuit);
  pd = 1;
  n = randomcard(CardSuit,CardNum,&Cardval,pd,playercards,dealercards,n);
  printf("2) %s of %s\n",CardNum,CardSuit);
  printf("\n");
  printf("The dealer has dealt himself:\n");
  pd = 2;
  n = randomcard(CardSuit,CardNum,&Cardval,pd,playercards,dealercards,n);
  printf("1) %s of %s\n",CardNum,CardSuit);
  pd = 2;
  n = randomcard(CardSuit,CardNum,&Cardval,pd,playercards,dealercards,n);
  char CardSuitHidden[10];
  for (int i=0;i<10;i++){
    CardSuitHidden[i]=CardSuit[i];
  }
  char CardNumHidden[10];
  for (int i=0;i<10;i++){
    CardNumHidden[i]=CardNum[i];
  }
  printf("This card is hidden\n");
  printf("\n");
  playersum = playercardsum(playercards);
  dealersum = dealercardsum(dealercards);
  printf("Your sum is %d\n",playersum);
  Hitorstand(playersum,dealersum,playercards,dealercards,CardSuit,CardNum,CardSuitHidden,CardNumHidden,n);
  return 0;
}

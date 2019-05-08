#include<strings.h>
#include<stdio.h>
#include"blackjack.h"

//do the ace algorithm
//count every ace as one. Go through the hand if at least one ace was seen and sum () add 10 to the sum.
int generateRandom(){
    //randomNumberGenerator a to b
    int r = rand()%(52)+1;
    return r;
}

int randomcard(char *cardsuit,char *cardnum,int *cardval,int p_or_d,int *playercards,int * dealercards,int n){
  //increment in the main function
  int previouscards[52];
  int i = generateRandom();
  for (int k = 0;k<n-1;k++){
    if (previouscards[k] == i){
      i = generateRandom();
      printf("You Suck This Card is a Repeat\n");
    }
  }
  n++;
  int suit = i/13;
  if (suit == 1){
    //puts letters in the string for each card value and suit
    *cardsuit = 'H'; cardsuit++;
    *cardsuit = 'e'; cardsuit++;
    *cardsuit = 'a'; cardsuit++;
    *cardsuit = 'r'; cardsuit++;
    *cardsuit = 't'; cardsuit++;
    *cardsuit = 's'; cardsuit++;
    *cardsuit = '\0'; 
  }
  if (suit == 0){
    *cardsuit = 'S'; cardsuit++;
    *cardsuit = 'p'; cardsuit++;
    *cardsuit = 'a'; cardsuit++;
    *cardsuit = 'd'; cardsuit++;
    *cardsuit = 'e'; cardsuit++;
    *cardsuit = 's'; cardsuit++;
    *cardsuit = '\0'; ;
  }
  if (suit == 2){
    *cardsuit = 'D'; cardsuit++;
    *cardsuit = 'i'; cardsuit++;
    *cardsuit = 'a'; cardsuit++;
    *cardsuit = 'm'; cardsuit++;
    *cardsuit = 'o'; cardsuit++;
    *cardsuit = 'n'; cardsuit++;
    *cardsuit = 'd'; cardsuit++;
    *cardsuit = 's'; cardsuit++;
    *cardsuit = '\0'; ;
  }
  if (suit == 3){
    *cardsuit = 'C'; cardsuit++;
    *cardsuit = 'l'; cardsuit++;
    *cardsuit = 'u'; cardsuit++;
    *cardsuit = 'b'; cardsuit++;
    *cardsuit = 's'; cardsuit++;
    *cardsuit = '\0'; 
  }
  int num = i%13;
  if (num!=0||num!=10||num!=11||num!=12){
    *cardval = num + 1;
  }
  if (num == 0){
    *cardnum = 'A'; *cardnum++;
    *cardnum = 'c'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = '\0'; *cardnum++;
    *cardval = 1;
  }
  if (num == 1){
    *cardnum = 'T'; *cardnum++;
    *cardnum = 'w'; *cardnum++;
    *cardnum = 'o'; *cardnum++;
    *cardnum = '\0';
  }
  if (num == 2){
    *cardnum = 'T'; *cardnum++;
    *cardnum = 'h'; *cardnum++;
    *cardnum = 'r'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = '\0'; 
  }
  if (num == 3){
    *cardnum = 'F'; *cardnum++;
    *cardnum = 'o'; *cardnum++;
    *cardnum = 'u'; *cardnum++;
    *cardnum = 'r'; *cardnum++;
    *cardnum = '\0'; 
  }
  if (num == 4){
    *cardnum = 'F'; *cardnum++;
    *cardnum = 'i'; *cardnum++;
    *cardnum = 'v'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = '\0'; 
  }
  if (num == 5){
    *cardnum = 'S'; *cardnum++;
    *cardnum = 'i'; *cardnum++;
    *cardnum = 'x'; *cardnum++;
    *cardnum = '\0';
  }
  if (num == 6){
    *cardnum = 'S'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = 'v'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = 'n'; *cardnum++;
    *cardnum = '\0'; 
  }
  if (num == 7){
    *cardnum = 'E'; *cardnum++;
    *cardnum = 'i'; *cardnum++;
    *cardnum = 'g'; *cardnum++;
    *cardnum = 'h'; *cardnum++;
    *cardnum = 't'; *cardnum++;
    *cardnum = '\0'; 
  }
  if (num == 8){
    *cardnum = 'N'; *cardnum++;
    *cardnum = 'i'; *cardnum++;
    *cardnum = 'n'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = '\0'; 
  }
  if (num == 9){
    *cardnum = 'T'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = 'n'; *cardnum++;
    *cardnum = '\0'; 
  }
  if(num==10){
    *cardnum = 'J'; *cardnum++;
    *cardnum = 'a'; *cardnum++;
    *cardnum = 'c'; *cardnum++;
    *cardnum = 'k'; *cardnum++;
    *cardnum = '\0'; 
    *cardval = 10;
  }
  if (num==11){
    *cardnum = 'Q'; *cardnum++;
    *cardnum = 'u'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = 'e'; *cardnum++;
    *cardnum = 'n'; *cardnum++;
    *cardnum = '\0'; 
    *cardval = 10;
  }
  if(num==12){
    *cardnum = 'K'; *cardnum++;
    *cardnum = 'i'; *cardnum++;
    *cardnum = 'n'; *cardnum++;
    *cardnum = 'g'; *cardnum++;
    *cardnum = '\0'; 
    *cardval = 10;
  }
  if (p_or_d == 1){
    //1 = player
    for (i = 0; i<52; i++){
      if (playercards[i] == 0){
	playercards[i] = *cardval;
	break;
      }
    }
  }
  if (p_or_d == 2){
    // 2 = dealer
    for (i = 0; i<52; i++){
      if (dealercards[i] == 0){
	dealercards[i] = *cardval;
	break;
      }
    }
  }
  return n;
}

int playercardsum(int *playercards){
  int playersum = 0;
  int playerace = 0;
  //for loop checks to see amount of aces. If more than one ace and total is <=11, add 10 to the sum.
  for (int i=0;i<52;i++){
    if (playercards[i] == 1){
    playerace++;
    }
  }
  for (int i = 0;i<52;i++){
    playersum = playercards[i]+playersum;
  }
  if (playerace >= 1 && playersum <= 11){
    playersum = playersum + 10;
  }
  return playersum;
}

int dealercardsum(int *dealercards){
  int dealersum = 0;
  int dealerace = 0;
  for (int i=0;i<52;i++){
    if (dealercards[i] == 1){
      dealerace++;
    }
  }
  for (int i = 0; i<52; i++){
    dealersum = dealercards[i] + dealersum;
  }
  if (dealerace >= 1 && dealersum <= 11){
    dealersum = dealersum + 10;
  }
  return dealersum;
}

int Hitorstand(int playersum,int dealersum,int *playercards,int *dealercards,char *CardSuit,char *CardNum,char *CardSuitHidden,char *CardNumHidden,int n){
  int Cardval;
  char hitstand;
  //check for immediate win or lose
  if (playersum > 21){
    printf("You Bust!\n");
    printf("Game Over, You Lose, The Dealer Had %d\n",dealersum);
    return 0;
    }
  if (dealersum > 21){
    printf("The Dealer Busts With A Total Of %d\n",dealersum);
    printf("You Win!\n");
    return 0;
  }
  if (playersum == 21 && dealersum == 21){
    printf("The Game is a Draw, you and the dealer both have 21\n");
    printf("Game Over, You Lose\n");
    return 0;
  }
  if (playersum == 21 && dealersum != 21){
    printf("You Got Blackjack! The dealer only had %d\n",dealersum);
    printf("You Win!\n");
    return 0;
  }
  if (playersum != 21 && dealersum == 21){
    printf("The Dealer Got Blackjack!\n");
    printf("Game Over, You Lose\n");
    return 0;
  }
  //If unresolved, player has the oppurtunity to hit or stand
  else if (playersum < 21 && dealersum < 21){
    printf("You Now Have The Option To Hit or Stand\n");
    scanf("%c",&hitstand);
    //erase the stdin
    scanf("%*[^\n]");
    scanf("%*c");
    if (hitstand == 'H' || hitstand == 'h'){
      int pd = 1;
      n = randomcard(CardSuit,CardNum,&Cardval,pd,playercards,dealercards,n);
      playersum = playercardsum(playercards);
      printf("You Add A %s of %s To Your Hand.\n Your New Sum is %d\n\n",CardNum,CardSuit,playersum);
      Hitorstand(playersum,dealersum,playercards,dealercards,CardSuit,CardNum,CardSuitHidden,CardNumHidden,n);
      return 1;
    }
    //resolve the game if stand
    if (hitstand == 'S' || hitstand == 's'){
      //make this so that it goes to the last card added to the dealercards array
      printf("The Dealers Hidden Card Was %s Of %s\n\n",CardNumHidden,CardSuitHidden);
      if (dealersum < 17){
	int pd = 2;
	n = randomcard(CardSuit,CardNum,&Cardval,pd,playercards,dealercards,n);
	dealersum = dealercardsum(dealercards);
	printf("The Dealer Hits And Adds A %s of %s to his hand\n\n",CardNum,CardSuit);
	if (playersum > 21){
	  printf("You Bust!\n");
	  printf("Game Over, You Lose, The Dealer Had %d\n",dealersum);
	  return 0;
	}
	if (dealersum > 21){
	  printf("The dealer busts with a total of %d\n",dealersum);
	  printf("You Win!\n");
	  return 0;
	}
	if (playersum == 21 && dealersum == 21){
	  printf("The Game is a Draw, you and the dealer both have 21\n");
	  printf("Game Over, You Lose\n");
	  return 0;
	}
	if (playersum == 21 && dealersum != 21){
	  printf("You Got Blackjack! The dealer only had %d\n\n",dealersum);
	  printf("You Win!\n");
	  return 0;
	}
	if (playersum != 21 && dealersum == 21){
	  printf("The Dealer Got Blackjack!\n");
	  printf("Game Over, You Lose\n");
	  return 0;
	}
	if (dealersum > playersum){
	  printf("You Lose The Game. The Dealer Had %d\n",dealersum);
	  return 0;
	}
	if (dealersum < playersum){
	  printf("You Win The Game. The Dealer Had %d\n",dealersum);
	  return 0;
	}
	if (dealersum == playersum){
	  printf("The Game Is A Draw. You Lose. The Dealer Also Had %d\n",dealersum);
	}
      }
      else{
	if (playersum > 21){
	  printf("You Bust!\n");
	  printf("Game Over, You Lose, The Dealer Had %d\n",dealersum);
	  return 0;
	}
	if (dealersum > 21){
	  printf("The dealer busts with a total of %d\n",dealersum);
	  printf("You Win!\n");
	  return 0;
	}
	if (playersum == 21 && dealersum == 21){
	  printf("The Game is a Draw, you and the dealer both have 21\n");
	  printf("Game Over, You Lose\n");
	  return 0;
	}
	if (playersum == 21 && dealersum != 21){
	  printf("You Got Blackjack! The dealer only had %d\n",dealersum);
	  printf("You Win!\n");
	  return 0;
	}
	if (playersum != 21 && dealersum == 21){
	  printf("The Dealer Got Blackjack!\n");
	  printf("Game Over, You Lose\n");
	  return 0;
	}
	else if (playersum > dealersum){
	  printf("You Win! The Dealer Had %d\n",dealersum);
	  return 0;
	}
	else if (playersum < dealersum){
	  printf("You Lose! The Dealer Had %d\n",dealersum);
	  return 0;
	}
      }
    }
    else{
      printf("Please Type Either 'H' or 'S'\n\n");
      Hitorstand(playersum,dealersum,playercards,dealercards,CardSuit,CardNum,CardSuitHidden,CardNumHidden,n);
      return 1;
    }
  }
}


      


int generateRandom();

int randomcard(char *cardsuit,char *cardnum,int *cardval,int p_or_d,int *playercards,int *dealercards,int n);

int playercardsum(int *playercards);

int dealercardsum(int *dealercards);

int Hitorstand(int playersum,int dealersum, int *playercards, int *dealercards,char *CardSuit,char *CardNum, char *CardSuitHidden,char *CardNumHidden,int n);

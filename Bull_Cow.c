/*	C language used	*/
/*	Program for bull and cow game	*/

//File Inclusion
#include<stdio.h>

//Declaring Score counter variable for cows and bulls
int cows = 0, bulls = 0;

//User defined function to count score
void countScore(char a, char b, char c, char d, char A, char B, char C, char D)
{
	if(a==A)	bulls+=1;
	else	if((a==B)||(a==C)||(a==D))	cows+=1;
     
	if(b==B)	bulls+=1;
	else	if((b==A)||(b==C)||(b==D))	cows+=1;
     
	if(c==C)	bulls+=1;
	else	if((c==A)||(c==B)||(c==D))	cows+=1;
     
	if(d==D)	bulls+=1;
	else	if((d==A)||(d==B)||(d==C))	cows+=1;
}

//Driver Function
int main()
{
	//input characters
	char a,b,c,d;
	char A,B,C,D;
	
	//Getting Number set as problem
	printf("Bull and Cow Game \n\nEnter the four digit number : ");
	scanf("%c %c %c %c", &a, &b, &c, &d);
	
	//Clearing Screen for player to come
	system("CLS");
	
	//Player enters its guess
	printf("Player, Enter your guess : ");
    scanf(" %c %c %c %c", &A, &B, &C, &D);
    
    //calling function to count the score of bulls and cows
	countScore(a, b, c, d, A, B, C, D);	
    
    //if bull == 4 player wins the game
	if(bulls==4) 
		printf("\n\nCongratulations!!, You Won!");
	
	//else printing score
	else 
	 	printf("Bulls = %d Cows = %d", bulls, cows);
	
	return 0;
}
//program ends here

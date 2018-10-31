/*
|   --------------------------------------------------------------------------
|   Bull and Cow Game
|   --------------------------------------------------------------------------
|
|   @author Tushar Sharma <imtusharsharma@gmail.com>
|
*/


#include<stdio.h>

//Score counter variables
int cows = 0, bulls = 0;

/*
 *  Method to count for scores.
 *  Only if the user input and the generated numbers matched.
 *
 *  @param a first character
 *  @param b second character
 *  @param c third character
 *  @param d fourth character
 *  @param A first character from the user
 *  @param B second character from the user
 *  @param C third character from the user
 *  @param D fourth character from the user
 *  @return void
 */
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


/*
 *  Main method to generate problem number.
 *  Take numbers from the user and calculate score.
 *
 *  @param unused
 *  @return 0 successful count
 */
int main()
{

	char a,b,c,d;
	char A,B,C,D;

	printf("Bull and Cow Game \n\nEnter the four digit number : ");
	scanf("%c %c %c %c", &a, &b, &c, &d);

	system("CLS");

    	printf("Player, Enter your guess : ");
    	scanf(" %c %c %c %c", &A, &B, &C, &D);

	countScore(a, b, c, d, A, B, C, D);

	if(bulls==4)
		printf("\n\nCongratulations!!, You Won!");
	else
	 	printf("Bulls = %d Cows = %d", bulls, cows);

	return 0;
}

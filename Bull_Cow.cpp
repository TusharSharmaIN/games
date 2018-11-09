/*
|   --------------------------------------------------------------------------
|   Bull and Cow Game
|   --------------------------------------------------------------------------
|
|   @author Tushar Sharma <imtusharsharma@gmail.com>
|
*/

#include <iostream>
#include <fstream>

#define FILE_PATH "puzzle.txt"

using namespace std;

//golbal score counter
int cows = 0, bulls = 0;

// structure to hold digits as char
struct number
{
	char a, b, c, d;
};

/*
 *  Method to count for scores.
 *  Only if the user input and the generated numbers matched.
 *  @param X first number
 *  @param Y second number
 *  @return void
 */
void countScore(number X, number Y)
{

	if(X.a==Y.a)	bulls+=1;
	else	if((X.a==Y.b)||(X.a==Y.c)||(X.a==Y.d))	cows+=1;

	if(X.b==Y.b)	bulls+=1;
	else	if((X.b==Y.a)||(X.b==Y.c)||(X.b==Y.d))	cows+=1;

	if(X.c==Y.c)	bulls+=1;
	else	if((X.c==Y.b)||(X.c==Y.b)||(X.c==Y.d))	cows+=1;

	if(X.d==Y.d)	bulls+=1;
	else	if((X.d==Y.a)||(X.d==Y.b)||(X.d==Y.c))	cows+=1;

}


/*
 *	function to set puzzle and store it in a file
 *	@param NULL
 *	@return void
 */
void setPuzzle()
{
	number puzz;

	cout<<"\nEnter the four digit number to set as puzzle: ";
	cin>>puzz.a>>puzz.b>>puzz.c>>puzz.d;

	ofstream file;
	file.open(FILE_PATH);
	file<<puzz.a<<puzz.b<<puzz.c<<puzz.d;

	cout<<"\nSet Succesfully";
	file.close();
}

/*
 *	function to solve puzzle that is stored in the file
 *	@param NULL
 *	@return void
 */
void solvePuzzle()
{
	number guess, puzz;

	cout<<"\nPlayer, Enter your guess : ";
    cin>>guess.a>>guess.b>>guess.c>>guess.d;

	ifstream file;
	file.open(FILE_PATH);
	
	file>>puzz.a>>puzz.b>>puzz.c>>puzz.d;
	
	countScore(puzz, guess);
	
	file.close();
}

/*
 *  Main method to generate problem number.
 *  Take numbers from the user and calculate score.
 *  @param NULL
 *  @return 0 successful count
 */
int main()
{
	
	int choice, solved = 0;

	cout<<"\t\t\t\tWelcome to Cows and Bulls - Game"<<endl<<endl;
	cout<<"Menu"<<endl;
	cout<<"1. Set Puzzle"<<endl;
	cout<<"2. Solve Puzzle"<<endl<<endl;
	in:
	cout<<"Enter a valid choice: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1	:	setPuzzle();
					break;
	
		case 2	:	solvePuzzle();
					solved = 1;
					break;
	
		default	:	cout<<"Not a valid choice\n";
					goto in;
	}

	if(solved)
	{
		if(bulls==4)
			printf("\nCongratulations!!, You Won!");
		else
		 	printf("\nBulls = %d Cows = %d", bulls, cows);
	}
	
	return 0;
}
/*	Program Ends Here	*/

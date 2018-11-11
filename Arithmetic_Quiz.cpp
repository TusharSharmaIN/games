#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int countScore = 0;

/*
 *  Swap two numbers
 *  @param &x reference of first number
 *  @param &y reference of second number
 *  @return void
 */
void swap(int &x, int &y)
{
    if(x != y)
	{   int temp = x;
	    x = y;
	    y = temp;
    }
}

/*
 *  Check if the input answer is matched with the result
 *  @param num1 number one
 *  @param num2 number two
 *  @param ans answer from the user
 *  @param op operator to operate on
 *  @return true if found ans is correct
 */
int isAnsTrue(int num1, int num2, int ans, char op)
{
	switch(op)
	{
		case '+'	:	if(ans == (num1 + num2))
						return 1;
		
		case '-'	:	if(ans == (num1 - num2))
						return 1;

		case '*'	:	if(ans == (num1 * num2))
						return 1;
		
		default		:	return 0;
	}
	
}

/*
 *  To Execute a problem specified ten times
 *  @param operation string for operation
 *  @param opSymbol char for symbol of operator
 *  @return void
 */
void problem(string operation, char opSymbol = ' ')
{
	string correctMsg[] = { {"Correct."}, {"Excellent!"}, {"Very good"}, {"Great Job"} };
	string wrongMsg[] = { {"Sorry, that is incorrect."}, {"No, that was a tough one."}, {"Sorry, keep trying"}, {"No, missed that one."}};
	string opName[] = { {"plus"}, {"minus"}, {"times"} };
	char opSym[] = {'+', '-', '*'};
	
	srand(time(NULL));

	string temp = operation;

	int num1, num2, ans;
	
	for(int i = 1; i <= 10; i++)
	{
		if(temp == "mix")
		{
			int loc = rand()%3;
			operation = opName[loc];
			opSymbol = opSym[loc];
		}
		
		num1 = rand()%10;
		num2 = rand()%10;

		if(opSymbol == '-' && num2 > num1)
			swap(num2, num1);

		cout<<"\nProblem #"<<i<<": What is "<<num1<<" "<<operation<<" "<<num2<<"? ";
		cin>>ans;

		if(isAnsTrue(num1, num2, ans, opSymbol))
		{
			countScore++;
			cout<<correctMsg[rand()%4];
		}
		else
		{
			cout<<wrongMsg[rand()%4];
		}

	}
	
	cout<<"\n\n"<<countScore<<" out of 10 correct.";
}

/*
 *  Menu Driven Program
 *  @param unused
 *  @return 0 successful count
 */
int main()
{
	int choice;

	cout<<"\t\tWelcome to the arithmetic challenge!\n\n";
	cout<<"1 - Addition\n";
	cout<<"2 - Subtraction\n";
	cout<<"3 - Multiplication\n";
	cout<<"4 - Addtition, Subtraction, and Multiplication Mix\n";
	cout<<"\nEnter the number for the problem type: ";
	cin>>choice;

	system("cls");

	switch(choice)
	{
		case 1	:	problem("plus", '+');
				break;
		
		case 2	:	problem("minus", '-');
				break;

		case 3	:	problem("times", '*');
				break;
		
		case 4	:	problem("mix");
				break;
	}
	
	return 0;
}

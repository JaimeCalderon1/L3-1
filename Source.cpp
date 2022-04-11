#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void checkPrime(int x)
{
	for (int i = 2; i <= 100; i++)
	{
		if (x % i == 0) // flag for not prime number
		{
			cout << x << " is not a prime number.\n";
			i = 101;
		}
		else
		{
			cout << x << " is a prime number.\n";
			i = 101;
		}
	}
}

int randomNum()
{
	return 10 + (rand() % 89);
}

int main()
{
	srand(time(0));
	bool proLoop = true;
	while (proLoop)
	{
		int randNum = randomNum();
		cout << "The two digit random numbers are: " << randNum << '\n';
		cout << '\n';
		cout << "Enter 1 to double the number.\n";
		cout << "Enter 2 to reverse the digits of the number.\n";
		cout << "Enter 3 to raise the number to the power of 2,3, or 4.\n";
		cout << "Enter 4 to sum the digits of the number.\n";
		cout << "Enter 5 to raise the first digit to the power of the second digit.\n";
		cout << "Enter 6 to count total digits.\n";
		cout << "Enter 9 to terminate the program.\n";
		int userInput;
		cin >> userInput;
		if (userInput == 1) // double the number
		{
			clear();
			int dblNum = randNum * 2;
			cout << dblNum << '\n';
			if (dblNum < 10)
			{
				cout << "The number is less than 10 ... adding 10\n";
				dblNum += 10;
			}
			checkPrime(dblNum);
			Sleep(2000);
			clear();
		}
		else if (userInput == 2)
		{
			clear();
			int rem, rev;
			for (rev = 0; randNum != 0; randNum = randNum / 10)
			{
				rem = randNum % 10;
				rev = rem + (rev * 10);
			}
			cout << "Reverese = " << rev << '\n';
			checkPrime(rev);
			Sleep(2000);
			clear();
		}
		else if (userInput == 3)
		{
			clear();
			int dice = 1 + rand() % 3;
			if (dice == 1)
			{
				cout << "Raised to the power of 2 = " << randNum * randNum;

			}
			else if (dice == 2)
			{
				cout << "Raised to the power of 3 = " << (randNum * randNum) * randNum;
			}
			else
			{
				cout << "Raised to the power of 4 = " << (randNum * randNum) * (randNum * randNum);
			}
			Sleep(2000);
			clear();

		}
		else if (userInput == 4) 
		{
			clear();
			int firstDigit, secondDigit;
			firstDigit = randNum % 10; 
			randNum = randNum / 10;
			secondDigit = randNum % 10;
			cout << "\nThe sum of the digits is = " << firstDigit + secondDigit;
			Sleep(2000);
			clear();
				
		}
		else if (userInput == 5)
		{
			clear();
			int firstDigit, secondDigit;
			firstDigit = randNum % 10;
			randNum = randNum / 10;
			secondDigit = randNum % 10;
			cout << "The first digit raised to the power of the second digit is = " << pow(firstDigit, secondDigit);
			Sleep(2000);
			clear();
		}
		else if (userInput == 6)
		{
			clear();
			int counter = 0;
			while (randNum>0)
			{
				randNum = randNum / 10;
				counter++;
			}
			cout << "\nThe total count of the digits is = " << counter;
			Sleep(2000);
			clear();
		}
		else if (userInput == 9)
		{
			cout << "TERMINATING PROGRAM.\n";
			return EXIT_FAILURE;
		}
		else
		{
			cout << "Please enter a valid choice.\n";
		}
	}
	
	

}
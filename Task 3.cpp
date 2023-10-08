#include<iostream>
using namespace std;

char grid[9] = { '0','1','2','3','4','5','6','7','8' };
char newgrid[9] = { '0','1','2','3','4','5','6','7','8' };
string name1, name2;
int winner;
char ch1, ch2;
int draw;
char c;

void DrawBorad()
{
	if (draw == -1)
	{
		
		cout << "  " << newgrid[0] << " | " << newgrid[1] << "  | " << newgrid[2] << "  " << endl;
		cout << "----|----|----" << endl;
		cout << "  " << newgrid[3] << " | " << newgrid[4] << "  | " << newgrid[5] << " " << endl;
		cout << "----|----|----" << endl;
		cout << "  " << newgrid[6] << " | " << newgrid[7] << "  | " << newgrid[8] << " " << endl;
	}
	else
	{
		cout << "  " << grid[0] << " | " << grid[1] << "  | " << grid[2] << "  " << endl;
		cout << "----|----|----" << endl;
		cout << "  " << grid[3] << " | " << grid[4] << "  | " << grid[5] << " " << endl;
		cout << "----|----|----" << endl;
		cout << "  " << grid[6] << " | " << grid[7] << "  | " << grid[8] << " " << endl;
	}

}
int checkforwin()
{
	//check for rows
	if ((grid[0] == grid[1]) && (grid[1] == grid[2]))
		return true;
	else if ((grid[3] == grid[4]) && (grid[4] == grid[5]))
		return true;
	else if ((grid[6] == grid[7]) && (grid[7] == grid[8]))
		return true;
	// check for coloums
	else if ((grid[0] == grid[3]) && (grid[3] == grid[6]))
		return true;
	else if ((grid[1] == grid[4]) && (grid[4] == grid[7]))
		return true;
	else if ((grid[2] == grid[5]) && (grid[5] == grid[8]))
		return true;
	// check for diagonals
	else if ((grid[0] == grid[4]) && (grid[4] == grid[8]))
		return true;
	else if ((grid[2] == grid[4]) && (grid[4] == grid[6]))
		return true;
	else
		return false;
}
int DrawGame()
{
	if (((grid[0] == ch1) || (grid[0] == ch2)) && ((grid[1] == ch1) || (grid[1] == ch2)) && ((grid[2] == ch1) || (grid[2] == ch2)) && ((grid[3] == ch1) || (grid[3] == ch2))
		&& ((grid[4] == ch1) || (grid[4] == ch2)) && ((grid[5] == ch1) || (grid[5] == ch2)) && ((grid[6] == ch1) || (grid[6] == ch2)) && ((grid[7] == ch1) || (grid[7] == ch2))
		&& ((grid[8] == ch1) || (grid[8] == ch2)))
	{
		return -1;
	}
	else
	{
		return false;
	}
	
}
void PlayerInput()
{
	int c1, c2;

	while (!winner)
	{
		while (true)
		{
			cout << name1 << " , Enter your position : ";
			cin >> c1;
			if ((c1 < 0) || (c1 > 8) || (grid[c1] == 'X') || (grid[c1] == 'O'))
			{
				cout << "INVALID " << endl;
				continue;
			}
			else
			{
				grid[c1] = ch1;
			}
			break;

		}
		DrawBorad();
		winner = checkforwin();
		draw = DrawGame();
		if (winner == 1)
		{
			cout << "Congratualtions, " << name1 << " wins" << endl;
			break;
		}
		if (draw == -1)
		{
			cout << "Game Draws" << endl;
			break;
		}
		while (true)
		{
			cout << name2 << " , Enter your position : ";
			cin >> c2;
			if ((c2 < 0) || (c2 > 8) || (grid[c2] == 'X') || (grid[c2] == 'O'))
			{
				cout << "INVALID " << endl;
				continue;
			}
			else
			{
				grid[c2] = ch2;
			}
			break;

		}
		DrawBorad();
		winner = checkforwin();
		if (winner == 1)
		{
			cout << "Congratualtions, " << name2 << " wins" << endl;
			break;
		}

	}
}


int main()
{

	cout << "Welcome to TIC-TAC-TOE Game!" << endl;
	cout << "1st Player, Enter your name: ";
	cin >> name1;
	cout << "2nd Player, Enter your name: ";
	cin >> name2;
	cout << name1 << " Player, Choose (X or O): ";
	cin >> ch1;
	if ((ch1 != 'X') && (ch1 != 'O'))
	{
		cout << "INVALID, Choose (X OR O): ";
		cin >> ch1;
	}
	if (ch1 == 'X')
	{
		ch2 = 'O';
		cout << name2 << " Player, playes with: " << ch2 << endl;;
	}
	if (ch1 == 'O')
	{
		ch2 = 'X';
		cout << name2 << " Player, playes with: " << ch2 << endl;;
	}
	cout << "The current state of the borad " << endl;
	DrawBorad();
	PlayerInput();
	cout << "Do You want to play again>(Y OR N): ";
	cin >> c;
	if (c == 'Y')
	{
		system("cls");
		cout << "1st Player, Enter your name: ";
		cin >> name1;
		cout << "2nd Player, Enter your name: ";
		cin >> name2;
		cout << name1 << " Player, Choose (X or O): ";
		cin >> ch1;
		if ((ch1 != 'X') && (ch1 != 'O'))
		{
			cout << "INVALID, Choose (X OR O): ";
			cin >> ch1;
		}
		if (ch1 == 'X')
		{
			ch2 = 'O';
			cout << name2 << " Player, playes with: " << ch2 << endl;;
		}
		if (ch1 == 'O')
		{
			ch2 = 'X';
			cout << name2 << " Player, playes with: " << ch2 << endl;
		}
		cout << "The current state of the borad " << endl;
		DrawBorad();
		PlayerInput();
	}
	else
	{
		cout << "Thank you, Good Bye!" << endl;
	}
	system("pause");
	return 0;
}
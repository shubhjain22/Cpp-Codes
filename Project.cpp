#include <constream.h>

char s[10] = {'o','1','2','3','4','5','6','7','8','9'};
/*
	FUNCTION TO RETURN GAME STATUS :-
	1 -> GAME IS OVER WITH RESULT
	-1 -> GAME IS IN PROGRESS
	O -> GAME IS OVER AND NO RESULT
*/
int win()
{
	if (s[1] == s[2] && s[2] == s[3])
		return 1;
	else if (s[4] == s[5] && s[5] == s[6])
		return 1;
	else if (s[7] == s[8] && s[8] == s[9])
		return 1;
	else if (s[1] == s[4] && s[4] == s[7])
		return 1;
	else if (s[2] == s[5] && s[5] == s[8])
		return 1;
	else if (s[3] == s[6] && s[6] == s[9])
		return 1;
	else if (s[1] == s[5] && s[5] == s[9])
		return 1;
	else if (s[3] == s[5] && s[5] == s[7])
		return 1;
	else if (s[1] != '1' && s[2] != '2' && s[3] != '3' &&
			 s[4] != '4' && s[5] != '5' && s[6] != '6' &&
			s[7] != '7' && s[8] != '8' && s[9] != '9')
		return 0;
	else
		return -1;
}
void board()  //FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH MARK
{
	clrscr();
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << "\n\n";
	cout << "\n";
	cout << "     |     |     " << "\n";
	cout << "  " << s[1] << "  |  " << s[2] << "  |  " << s[3] << "\n";
	cout << "_____|_____|_____" << "\n";
	cout << "     |     |     " << "\n";
	cout << "  " << s[4] << "  |  " << s[5] << "  |  " << s[6] << "\n";
	cout << "_____|_____|_____" << "\n";
	cout << "     |     |     " << "\n";
	cout << "  " << s[7] << "  |  " << s[8] << "  |  " << s[9] << "\n";
	cout << "     |     |     " << "\n\n";
}


void main()
{
	int player = 1,i,ch;
	char mark;
	clrscr();
	do
	{
		board();
		if(player=(player%2)){
			player = 1;
		}
		else{
			player = 2;
		}
		cout << "Player " << player << ", enter a number:  ";
		cin >> ch;
		if(mark=(player == 1)){
			  mark = 'X';
		}
		else{
			  mark = 'O';
		}
		if (ch == 1 && s[1] == '1')
			s[1] = mark;
		else if (ch == 2 && s[2] == '2')
			s[2] = mark;
		else if (ch == 3 && s[3] == '3')
			s[3] = mark;
		else if (ch == 4 && s[4] == '4')
			s[4] = mark;
		else if (ch == 5 && s[5] == '5')
			s[5] = mark;
		else if (ch == 6 && s[6] == '6')
			s[6] = mark;
		else if (ch == 7 && s[7] == '7')
			s[7] = mark;
		else if (ch == 8 && s[8] == '8')
			s[8] = mark;
		else if (ch == 9 && s[9] == '9')
			s[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			getch();
		}
		i=win();
		player++;
	}while(i==-1);
	board();
	if(i==1)
		cout<<"-:Player "<<--player<<" win ";
	else
		cout<<"-:Game draw";
getch();
}
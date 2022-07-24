#include <bits/stdc++.h>
using namespace std;


void printSudoku9x9(vector<vector<int>> board) {
	cout << "-------------------------" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << "-------------------------" << endl;

}
bool isValid(vector<vector<int>> &board, int row, int col, int n)
{
	for(int i=0; i<board.size(); i++)
	{
		if(board[i][col] == n)
			return false;

		if(board[row][i] == n)
			return false;

		if(board[3*(row/3)+i/3][3*(col/3)+i%3] == n)
			return false;
	}
	return true;
}
bool solve(vector<vector<int>> &board)
{
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[0].size();j++)
		{
			if(board[i][j] == 0)
			{
				for(int n=1; n<=9; n++)
				{
					if(isValid(board,i,j,n))
					{
						board[i][j] = n;

						if(solve(board) == true)
							return true;
						else
							board[i][j] = 0;
					}
						
				}
				return false;
			}

			
		}
	}
	return true;
}
int main()
{
	vector<vector<int>> board1 = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};
	vector<vector<int>> board2 = {
		{8,0,0,0,0,0,0,0,0},
		{0,0,3,6,0,0,0,0,0},
		{0,7,0,0,9,0,2,0,0},
		{0,5,0,0,0,7,0,0,0},
		{0,0,0,0,4,5,7,0,0},
		{0,0,0,1,0,0,0,3,0},
		{0,0,1,0,0,0,0,6,8},
		{0,0,8,5,0,0,0,1,0},
		{0,9,0,0,0,0,4,0,0}
	};
	
	if(solve(board1)) cout << "successfully solved board 1!" << std::endl;
	printSudoku9x9(board1);
	if(solve(board2)) cout << "successfully solved board 2!" << std::endl;
	printSudoku9x9(board2);

	return 0;
}
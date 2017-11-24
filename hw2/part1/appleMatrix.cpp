#include<iostream>
#include<queue>
using namespace std;
struct Position {
	int row;
	int column;
	Position(int _row = 0, int _column = 0) : row(_row), column(_column) {}

};
bool isValid(int row, int column)
{
	return row >= 0 && row < 4 && column >= 0 && column < 4;
}
bool isNextToRotten(Position p, int field[4][4])
{
	if (isValid(p.row - 1, p.column))
	{
		if (field[p.row - 1][p.column] == 2)
		{
			return true;
		}
	}
	if (isValid(p.row + 1, p.column))
	{
		if (field[p.row + 1][p.column] == 2)
		{
			return true;
		}
	}
	if (isValid(p.row, p.column - 1))
	{
		if (field[p.row][p.column - 1] == 2)
		{
			return true;
		}
	}
	if (isValid(p.row, p.column + 1))
	{
		if (field[p.row][p.column + 1] == 2)
		{
			return true;
		}
	}
	return false;
}

bool isTheFieldGonnaDie(int field[4][4], int* howLong)
{
	queue<Position> q;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (field[i][j] == 1)
			{
				q.emplace(i, j);
			}
		}
	}
	cout << endl;
	if (q.empty())
	{
		return true;
	}
	else
	{
		Position current;
		int numberOfInfected = 0;
		queue<Position> toBeInfected;

		while (!q.empty())
		{
			current = q.front();
			q.pop();
			if (isNextToRotten(current, field))
			{
				toBeInfected.emplace(current.row, current.column);
				cout << "shte zarazim [" << current.row << "] [" << current.column << "]" << endl;
				numberOfInfected++;
			}
		}
		if (numberOfInfected == 0)
		{
			return false;
		}
		else
		{
			while (!toBeInfected.empty())
			{
				current = toBeInfected.front();
				toBeInfected.pop();
				field[current.row][current.column] = 2;
			}
			*howLong += 1;
			return isTheFieldGonnaDie(field, howLong);
		}
	}
}
int main()
{
	int arr[4][4] = { { 1,1,1,0 },
	{ 2,0,1,1 },
	{ 2,0,1,1 },
	{ 2,0,1,1 } };
	int howLong = 0;
	cout << isTheFieldGonnaDie(arr, &howLong) << endl;  // a)
	if (isTheFieldGonnaDie(arr, &howLong))
	{
		cout << howLong << endl;                        // b)
	}

	cin.get();
	return 0;
}
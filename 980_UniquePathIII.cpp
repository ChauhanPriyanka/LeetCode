#include<string>
#include <set>
#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include <iterator> 
#include<vector>

using namespace std;

int count89 = 0;
bool dfs(vector<vector<int>>& grid, int i, int j, int row, int col)
{
	if (i > row || j > col) return false;

	if (grid[i][j] == -1)
		return false;

	if (grid[i][j] == 2)
	{
		count89++;
		return true;
	}

	if (grid[i][j] == 0)
	{
		grid[i][j] = 3; //visited

		if (i + 1 < row)
			dfs(grid, i + 1, j, row, col);

		if (i - 1 >= 0)
			dfs(grid, i - 1, j, row, col);

		if (j + 1 < col)
			dfs(grid, i, j + 1, row, col);

		if (j - 1 >= 0)
			dfs(grid, i, j - 1, row, col);

	}
	return true;
}
int uniquePathsIII(vector<vector<int>>& grid)
{
	if (!grid.size())
		return -1;

	int row = grid.size();
	int col = grid[0].size();

	int newR = 0;
	int newCol = 0;
	bool found = false;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (grid[i][j] == 1)
			{
				newR = i;
				newCol = j;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	grid[newR][newCol] = 0;
	dfs(grid, newR, newCol, row, col);
	return count89;
}

int main980()
{

	vector<vector<int>> vec = { {1,0,0,0} ,{0,0,0,0},{0,0,0,2} };
	uniquePathsIII(vec);
	return 0;
}
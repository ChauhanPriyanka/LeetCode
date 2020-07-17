#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include<unordered_map>
#include<utility>
#include<queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
	int i = 1;
	vector<int> intermediateCell(cells);
	while (i <= 1000000000)
	{
		for (int j = 1; j < cells.size() - 1; ++j)
		{
			intermediateCell[j] = cells[j - 1] == cells[j + 1] ? 1 : 0;
		}
		cells = intermediateCell;
		i++;
	}
	return intermediateCell;
}

int main264()
{
	vector<int> prison{ 1,0,0,1,0,0,1,0 };
	vector <int> result = prisonAfterNDays(prison, 1);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	return 0;
}
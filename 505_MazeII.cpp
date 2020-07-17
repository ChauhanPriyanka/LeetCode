#include<string.h>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;
int count2 = 0;
int maxC = INT_MAX;
bool dfs(vector<vector<int>>& maze, int rStart, int cStart, int rEnd, int cEnd, int row, int col)
{
    if (row > maze.size() && col > maze[0].size() && row > rEnd&& col > cEnd)
        return false;

    if (row == rEnd && col == cEnd)
    {
        maxC = min(maxC, count2);
        count2 = 0;
        return true;   
    }

    if (maze[row][col] == 0)
    {
        maze[row][col] = 2;
        if (row + 1 < maze.size() && maze[row + 1][col] != 1) if (dfs(maze, rStart, cStart, rEnd, cEnd, row + 1, col)) count2++;
        if (col + 1 < maze[0].size() && maze[row][col + 1] != 1) if (dfs(maze, rStart, cStart, rEnd, cEnd, row, col + 1)) count2++;  
        if (row - 1 > 0 && maze[row - 1][col] != 1) if (dfs(maze, rStart, cStart, rEnd, cEnd, row - 1, col)) count2++;
        if (col - 1 > 0 && maze[row][col - 1] != 1)if (dfs(maze, rStart, cStart, rEnd, cEnd, row, col - 1)) count2++;
        maze[row][col] = 0;
    }
    return true;
}

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
{
    if (!start.size() && !destination.size())
        return -1;

    int rStart = start[0];
    int cStart = start[1];

    int rEnd = destination[0];
    int cEnd = destination[1];

    dfs(maze, rStart, cStart, rEnd, cEnd, rStart, cStart);

    return count2;
}

int main505()
{
    vector<vector<int>> vec = { {0, 0, 1, 0, 0 }, 
                                {0, 0, 0, 0, 0 }, 
                                {0, 0, 0, 1, 0 }, 
                                {1, 1, 0, 1, 1 }, 
                                {0, 0, 0, 0, 0 } };
    vector<int> start = { 0,4 };
    vector<int> dest = { 4,4 };
    int count = shortestDistance(vec, start, dest);
    return 0;
}
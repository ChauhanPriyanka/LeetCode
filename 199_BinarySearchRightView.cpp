#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
	map<int, set<int>> mp;
	int result = -1;
	vector<int> couldNotBeJudge;
	for (auto item : trust)
	{
		int key = item[1];
		int value = item[0];
		if (key != value )
		{	
			//check if the value is already a key
			set<int> s = mp[key];
			s.insert(value);
			mp[key] = s;
			if (mp.find(value) != mp.end())
			{
				couldNotBeJudge.push_back(value);
			}
			
		}
		else
		{
			couldNotBeJudge.push_back(value);
		}
	}

	for (auto item : mp)
	{
		int size = item.second.size();
		if (size == N - 1)
		{
			if (find(couldNotBeJudge.begin(), couldNotBeJudge.end(), item.first) == couldNotBeJudge.end())
				result = item.first;
		}
	}
	return result;
}

int main199()
{

	//int count = climbStairs(5);
	int N = 2;
	vector<vector<int>> vec{ {1,2}, {2,1} };
	int lnResult = findJudge(N, vec);
	cout << lnResult;
	return 0;
}
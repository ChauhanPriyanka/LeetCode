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

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int>> result;
	int length = candidates.size();
	int sum = 0;
	vector<int> subResult;
	for (int i = 0; i < length; ++i)
	{
		if (candidates[i] == target)
		{
			result.push_back({ candidates[i] });
			continue;
		}

		//case: when array sum is eqaul to target.
		sum += candidates[i];
		subResult.push_back(candidates[i]);
		if (sum == target)
		{
			result.push_back(subResult);
			subResult.clear();
			continue;
		}

		if (sum > target)
		{
			sum = candidates[i];
			subResult.clear();
			subResult.push_back(candidates[i]);
		}
	
		//check if current number itself adds up to the target
		int num = candidates[i];
		vector<int> r2;
		r2.push_back(candidates[i]);
		while (1)
		{
			if (num == target)
			{
				//r2.push_back(candidates[i]);
				result.push_back(r2);
			}
			if (num < target)
			{
				r2.push_back(candidates[i]);
			}
			else
			{
				break;
			}
			num += candidates[i];
		}

		vector<int> r1(subResult);
		int j = i;
		while (j >= 0)
		{
			int newNumber = sum + candidates[j];
			if (newNumber == target)
			{
				r1.push_back(candidates[j]);
				result.push_back(r1);
				r1.clear();
				break;
			}
			else if (newNumber < target)
			{
				r1.push_back(candidates[j]);
				newNumber += candidates[j];
			}
			j--;
		}
	}
	return result;
}

int main39()
{

	vector<int> vec = {1};
	vector<vector<int>> r =  combinationSum(vec, 2);
	return 0;
}
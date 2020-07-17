#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_map>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
	unordered_map<int, int> mp;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)
			{
				if (mp.size() == 0)
				{
					if (mp.find(nums[i]) == mp.end())
					{
						mp[nums[i]] = i;
					}
					if (mp.find(nums[j]) == mp.end())
					{
						mp[nums[j]] = j;
					}
				}
				else
				{
					bool bValidate = true;
					for (auto item : mp)
					{
						if (mp.find(nums[j]) == mp.end() && (item.first % nums[j] == 0 || nums[j] % item.first == 0))
							bValidate = true;
						else
						{
							bValidate = false;
							break;
						}
					}
					
					if (bValidate)
					{
						mp[nums[j]] = j;
					}
				}
			}
		}

		if (mp.size() > result.size())
		{
			//push the elements in mp
			result.clear();
			for (auto item : mp)
			{
				result.push_back(item.first);
			}
			mp.clear();
		}
	}
	return result;
}

int main368()
{

    //int count = climbStairs(5);
    int N = 2;
    vector<int> a{ 2,3,8,9,27 };
    vector<int> lnResult = largestDivisibleSubset(a);
    
    return 0;
}
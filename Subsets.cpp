#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> ans;

void sub(vector<int>& nums, int i, vector<int> temp)
{
    if (i == nums.size())
    {
        ans.push_back(temp);
        return;
    }

    sub(nums, i + 1, temp);
    temp.push_back(nums[i]);
    sub(nums, i + 1, temp);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> temp;
    sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
    return ans;
}
void dfs(int pos, vector<int>& temp, vector<vector<int>>& result, vector<int>& nums)
{
	if (pos == nums.size())
	{
		result.push_back(temp);
		return;
	}

	dfs(pos + 1, temp, result, nums);
	temp.push_back(nums[pos]);
	dfs(pos + 1, temp, result, nums);
}
//vector<vector<int>> subsets(vector<int>& nums)
//{
//
//	vector<vector<int>> result;
//	vector<int> temp;
//	result.push_back(temp);
//	dfs(0, temp, result, nums);
//	return result;
//}


int mainSubsets()
{
	vector<int> nums{ 1,2,3 };
	subsets(nums);
	return 0;
}
#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
#include<unordered_map>
using namespace std;

int findMaxLength1(vector<int>& nums) {
    map<int, int> mp;
    mp[0] = -1;
    int count = 0;
    int maxVal = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        count = count + (nums[i] == 0 ? -1 : 1);
        if (mp.find(count) != mp.end())
        {
            int index = mp[count];
            maxVal = max(maxVal, i - mp[count]);
        }
        else
        {
            mp[count] = i;
        }
    }
    return maxVal;
}

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;

    mp[0] = -1;
    int maxlen = 0, count = 0;

    for (int i = 0; i < nums.size(); i++) {
        count = count + (nums[i] == 1 ? 1 : -1);
        if (mp.find(count) != mp.end()) {
            maxlen = max(maxlen, i - mp[count]);
        }
        else {
            mp[count] = i;
        }
    }
    return maxlen;
}

int main525()
{

    //int count = climbStairs(5);
    int N = 2;
    vector<int> a{ 0,0,1,0,0,0,1,1};
    int lnResult = findMaxLength(a);
    cout << lnResult;
    return 0;
}
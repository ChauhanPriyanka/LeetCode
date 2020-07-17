#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std; 

string expandAroundCenter(string s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s[L] == s[R]) {
        L--;
        R++;
    }
    string sVal = s.substr(L+1, R-1-L);
	return sVal;
}

string longestPalindrome1(string s)
{
	if(s.length()==0||s.length()==1)return s;
    string sResult="";
	for(int i = 0;i<s.length();i++)
	{
		string str1 = expandAroundCenter(s, i, i);
        if(str1.length() > sResult.length())sResult=str1;
		string str2  = expandAroundCenter(s, i, i+1);
         if(str2.length() > sResult.length())sResult=str2;

    }
	return sResult;
}

string helper(string s, int left, int right){
    while(left >=0 && right <s.length() && s[right]==s[left]){
        left--;
        right++;
    }
    return s.substr(left+1, right-1-left);
    
}
string longestPalindrome2(string s) {
    if(s.length()==0||s.length()==1)return s;
    string max=""+s[0];
    for(int i=0;i< s.length()-1; i++){
        string first=helper(s, i, i);
        if(first.length() > max.length())max=first;
        
        string second=helper(s, i, i+1);
        if(second.length() > max.length())max=second;
    }
    return max;
}

    int split(vector<int>& nums, int largestSum)
    {
        int pieces = 1;
        int tempSum = 0;
        for(int i= 0; i< nums.size(); i++)
        {
            if(tempSum + nums[i] > largestSum)
            {
                tempSum = nums[i];
                pieces++;
            }
            else
            {
                tempSum += nums[i];
            }
        }
        return pieces;
    }
    int splitArray(vector<int>& nums, int m) 
    {
        
        int n = nums.size();
        int maxVal = 0;
        int sum =0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            maxVal = max(maxVal, nums[i]);
            sum += maxVal;
        }
        
        int lo = maxVal;
        int hi = sum;
        while(lo<hi)
        {
          int mid = lo+ (hi-lo)/2;
          int pieces = split(nums, mid);
          if(pieces>m)
          {
              lo = mid+1;
          }
            else
                hi = mid;
        }
        return lo;
    }

	 static bool comparator( vector<int>& a, vector<int>& b )
    {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        //Handle Edge cases
        if( intervals.empty() )
        {
            return res;
        }
        
        if( intervals.size() == 1 )
        {
            res.push_back( intervals[0]);
            return res;
        }
        
        //Sort the inetrvals first based on the start of interval
        std::sort( intervals.begin(), intervals.end(), comparator );
        
        //Push the first interval into the result
        res.push_back( intervals[0] );
        int i = 1;
        while( i < intervals.size() )
        {
            vector<int>& last = res.back();
            //Check for overlapping boundaries in the intervals and merge them suitably
            if( last[1] < intervals[i][0] )
            {
                res.push_back( intervals[i] );
            }
            else
            {
                last[1] = max( last[1], intervals[i][1] );
            }
            i++;
        }
        
        return res;
    }
 
int main7()
{
	//longestPalindrome1("babad");
	vector <int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	//splitArray(nums,2);

	vector<vector<int>> vec;
	vector<int> v1, v2, v3, v4;
	v1.push_back(1);
	v1.push_back(3);
	v2.push_back(2);
	v2.push_back(6);
	v3.push_back(8);
	v3.push_back(10);
	v4.push_back(15);
	v4.push_back(18);

	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	merge(vec);
	return 0;
}
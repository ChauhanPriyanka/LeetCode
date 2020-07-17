#include<string>
#include<map>
#include<vector>
#include<iostream>

using namespace std;

string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets)
{
	string ret_str = "";
	map<int, string> replace_map;

	int begin, end;
	int key;


	for (int i = 0; i < indexes.size(); i++) {
		int matched_chars = 0;

		int index = indexes[i];

		string src_str = sources[i];
		string target_str = targets[i];

		for (int j = index; j < index + src_str.size() && j < S.length(); j++) {
			if (S[j] != src_str[j - index]) {
				break;
			}
			matched_chars++;
		}

		if (matched_chars == src_str.size())
		{
			begin = index;
			end = begin + src_str.size() - 1;
			key = ((begin << 16) | end);
			replace_map[key] = target_str;
		}
	}

	int current_pos = 0;

	for (auto it = replace_map.begin(); it != replace_map.end(); it++) {
		key = it->first;
		end = key & ((1 << 16) - 1);
		begin = key >> 16;

		ret_str += S.substr(current_pos, begin - current_pos);
		ret_str += it->second;
		current_pos = end + 1;
	}

	if (current_pos <= S.length() - 1) {
		ret_str += S.substr(current_pos, S.length() - current_pos);
	}

	return ret_str;
}


string minWindow1(string s, string t) {

	 vector<int> need(128,0);
	int i = 0, j =0;
	int left = 0, right = 0;
	int missing = 0;

	for(int i=0; i< t.length(); i++)
	{
		need[t[i]]++;
	}

	int minStart=0, minLen=INT_MAX;
	missing =  t.length();
	int len = s.length();
	while(right<len)
	{
		if(need[s[right]] > 0) 
		{
			missing--;
		}
		need[s[right]]--;
		right= right+1;
		while(missing == 0)
		{
			if(right-left < minLen) 
			{
				minLen= right-left;
				minStart = left;
			}
			need[s[left]]++;
			if(need[s[left]]>0)  missing++;
			left++;
		}
	}
	if(minLen!=INT_MAX)
		return s.substr(minStart, minLen);
	return "";

	//vector<int> v(128, 0);
	//for(int i=0;i<t.length();i++) 
	//{
	//	v[t[i]]++;
	//}
	//int start=0, end=0, counter=t.size();
	//int minStart=0, minLen=INT_MAX;
	//int len=s.size();
	//while(end<len)
	//{
	//	if(v[s[end]]>0)  
	//		counter--;
	//	v[s[end]]--;
	//	end++;
	//	while(counter==0)
	//	{
	//		if(end-start<minLen)
	//		{
	//			minStart=start;
	//			minLen=end-start;
	//		}
	//		v[s[start]]++;
	//		if(v[s[start]]>0)  counter++;
	//		start++;
	//	}
	//}
	//if(minLen!=INT_MAX)
	//	return s.substr(minStart, minLen);
	//return "";
}

  vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
		
		//std::sort(nums.begin(),nums.end());
		for(int i=0;i<nums.size();i++)
		{
			if ((i>0) && (nums[i]==nums[i-1]))
            continue;
		
			int start = i+1;
			int end = nums.size()-1;
			
			while(start < end)
			{
				int sum = nums[i]+nums[start]+nums[end];
				if(sum>0) end--;
				else if(sum<0) start++;
				else
				{
					vector<int> vec(3,0);
					vec[0] = nums[i];
					vec[1] = nums[start];
					vec[2] = nums[end];
					result.push_back(vec);
					while((start<end) && nums[start]==nums[start+1]) start++;
					while((start<end) && nums[end]==nums[end-1]) end--;
					start++;end--;

				}
			}
		}
return result;
    }

  bool isValid(string s, string word)
    {
        int i = 0;
        int j = 0;
       
        while(i < s.size() && j < word.size())
        {
            if(s[i] != word[j])
                return false;
            i++; j++;
            int countS =1; int countW =1;
            while(i<s.length() && s[i] == s[i-1])
            {
                i++;
                countS++;
            }
            while(j<word.length() && word[j] == word[j-1])
            {
                j++;
                countW++;
            }
            
            if(countW>countS)  //word count are greater than string s
                return false;
            
            if(countS<3)
                if(countS!=countW)
                    return false;
        }
          if(i==s.size() && j==word.size()) 
              return true;  //reach the end --->great
        return false;
    }

      int expressiveWords(string S, vector<string>& words)
	  {
        int result = 0;
        for(int i =0; i< words.size(); i++)
        {
            if(isValid(S,words[i]))
            {
                result++;
            }
        }
      return result;
    }

	   bool isIsomorphic(string s, string t) 
	   {
         int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
	   
	   
int main5()
{
	vector<int> indices;
	indices.push_back(0);
	indices.push_back(2);

	vector<string> src;
	src.push_back("a");
	src.push_back("cd");

	vector<string>tgt;
	tgt.push_back("eee");
	tgt.push_back("ffff");
	//findReplaceString("abcd",indices,src,tgt);

	//minWindow1("ADOBECODEBANC", "ABC");

	/*vector<int> ind;
	ind.push_back(0);
	ind.push_back(0);
	ind.push_back(0);
	threeSum(ind);*/
	vector<string> word;
	word.push_back("hello");
	word.push_back("hi");
	word.push_back("helo");
	//expressiveWords("heeellooo", word);

	isIsomorphic("egg","add");
	return 0;
}
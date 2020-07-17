#include<iostream>
#include<unordered_map>
#include<set>
#include <sstream>  
using namespace std;


int left (const int i)
{
	return (2*i+1);
}

int right(const int i)
{
	return (2*i+2);
}

void maxHeapify(vector<int>& nums, int i)
{
	int lIndex = left(i);
	int rIndex  = right(i);

	int heap_size = nums.size();
	int largest = i;
	if(lIndex < heap_size && nums[lIndex] > nums[i])
	{
		largest = lIndex;
	}
	if(rIndex < heap_size && nums[rIndex] > nums[largest])
	{
		largest = rIndex;
	}
	if(i != largest)
	{
		int temp = nums[i];
		nums[i] = nums[largest];
		nums[largest] = temp;
		maxHeapify(nums, largest);
	}
}

void minHeapify(vector<int>& nums, int i)
{
	int lIndex = left(i);
	int rIndex  = right(i);

	int heap_size = nums.size();
	int smallest = i;
	if(lIndex < heap_size && nums[lIndex] < nums[i])
	{
		smallest = lIndex;
	}
	if(rIndex < heap_size && nums[rIndex] < nums[smallest])
	{
		smallest = rIndex;
	}
	if(i != smallest)
	{
		int temp = nums[i];
		nums[i] = nums[smallest];
		nums[smallest] = temp;
		minHeapify(nums, smallest);
	}
}
void maxHeap(vector<int>& nums, int k)
{
	int i = k/2; 
	while (i >= 0) 
	{ 
		maxHeapify(nums, i); 
		i--; 
	} 
}
void replaceMax(vector<int>& nums,int x) 
{ 
	nums[0] = x;  maxHeapify(nums,0);
} 
int findKthLargest(vector<int>& nums, int k)
{
	if(nums.size() == 0 || k> nums.size()) return 0;

	int heapSize = nums.size();
	// prepare heap only for k elements
	maxHeap(nums,nums.size()); 

	for (int i = 0; i < k - 1; i++) {
		swap(nums[0], nums[--heapSize]);
		maxHeapify(nums, 0);
	}
        return nums[0];
}

 string getFormattedStr(string s)
    {
        int len = s.length();
        int count = 0;
        string returnStr;
        for(int i = len-1; i>0;i--)
        {
            if(s[i] == '#')
            {
                count++;
            }
            if(count > 0)
            {
                count --;
            }
            else if(count == 0)
            {
				char c = s[i];
                //returnStr = +returnStr;
            }
        }
		return "";
    }
    bool backspaceCompare(string S, string T) {
        //return (getFormattedStr(S) == getFormattedStr(T));
		return true;
    }

	int search(vector<int> v)
	{
		int lo = 0; int hi = v.size();
		while (lo < hi)
		{
			int mid = lo + (hi - lo) / 2;
			if (v[mid] > v[hi])
				lo = mid + 1;
			else
				hi = mid;
		}
		return 0;
	}

	set<string> setUniqueComb;
	void permute(string s, int len, int pos)
	{
		if (pos > len)
			return;

		if (!setUniqueComb.count(s))
			setUniqueComb.insert(s);

		for (int i = pos; i < len; i++)
		{
			swap(s[pos], s[i]);
			permute(s, len, pos + 1);
			swap(s[pos], s[i]);
		}
	}

	string getPermutation(int n, int k)
	{
		//convert to string
		string s;
		for (int i = 1; i <= n; i++)
		{   
			s = s + to_string(i);
		}
		permute(s, n, 0);

		int count = 0;
		string sResult;
		for (auto it : setUniqueComb)
		{
			count++;
			if (count == k)
			{
				sResult = it;
				break;
			}
		}
		return sResult;
	}
int mainLCG()
{
	string sResult = getPermutation(4,3);

	vector<int> v = { 4,5,6,7,1,2,3 };
	search(v);
	////{12, 3, 5, 7, 19}
	////3,2,1,5,6,4
	vector <int> vec;
	////vec.push_back(3);
	////vec.push_back(2);
	////vec.push_back(1);
	////vec.push_back(5);
	////vec.push_back(6);
	////vec.push_back(4);
	//

	////[3,2,3,1,2,4,5,5,6] => //6,5,5,4,3,3,2,2,1
	vec.push_back(3);vec.push_back(2);vec.push_back(3);vec.push_back(1);vec.push_back(2);vec.push_back(4);vec.push_back(5);vec.push_back(5);vec.push_back(6);
	int max = findKthLargest(vec,4);
	//cout << max;
	return 0;
}
#include<string>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_map>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;



unordered_map<int, int> mp;
vector<int> vec;

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool insert(int val) {
	if (mp.find(val) != mp.end())
	{
		return false;
	}
	mp[val] = vec.size();
	vec.push_back(val);
	return true;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool remove(int val) {
	if (mp.find(val) == mp.end()){	
		return false;
	}
	
	//Remove element from last in vector - O(1)
	swap(vec[mp[val]], vec[vec.size() - 1]);
	vec.pop_back();
	
	//update the size of swapped element in 
	mp[vec[mp[val]]] = mp[val];
	
	//Remove element from map
	mp.erase(val);
	return true;
}

/** Get a random element from the set. */
int getRandom() {
	return vec[rand() % vec.size()];
}

#include<vector>
#include<unordered_map>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;

//DFS memoization
//c++ gives compilation error if pair is directly used as key.
//This is because unordered_map uses std::hash to compute hash value for its keys. 
//and there is no specialization of std::hash for std::pair
// The other alternative to unordered map key is to use unique string as key instead of pair
//define specialization for hashing, using XOR, this could result in collisions, in real world
//We should shift/rotate one of the hashes before XORing
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

//DFS memoization
vector<vector<int>> adjMatrix;
typedef std::pair<int, int> pair1;
unordered_map<pair1, int, pair_hash> mp;

long DFSUtility(int node, int stops, int dst, int cities)
{
    if (node == dst)
        return 0;

    if (stops < 0)
    {
        return INT_MAX;
    }

    pair<int, int> key(node, stops);

    if (mp.find(key) != mp.end())
    {
        return mp[key];
    }

    long ans = INT_MAX;
    for (int neighbour = 0; neighbour < cities; ++neighbour)
    {
        long weight = adjMatrix[node][neighbour];
        if (weight > 0)
        {
            long minVal = DFSUtility(neighbour, stops - 1, dst, cities);
            if (minVal + weight > 0)
                ans = min(ans, minVal + weight);
        }
    }

    mp[key] = ans;
    //cout << ans << endl;
    return ans;
}

int findCheapestPrice1(int cities, vector<vector<int>>& flights, int src, int dst, int stops) {
    adjMatrix.resize(cities + 1, vector<int>(cities + 1, 0));
    for (auto item : flights)
    {
        adjMatrix[item[0]][item[1]] = item[2];
    }


    long ans = DFSUtility(src, stops, dst, cities);
    return ans >= INT_MAX ? -1 : (int)ans;;
}

int mainDFS()
{
	//input flight : {Source, Destination, Cost}
	vector<vector<int>> flights = { {4,1,1 }, { 1, 2, 3 }, { 0, 3, 2 }, { 0, 4, 10 }, { 3, 1, 1 }, { 1, 4, 3 } };

	//vec, n, stops, src , dst
	int stops = 2;
	int totalCities = 5;
	int sourceCity = 0;
	int destCity = 4;
	long ans = findCheapestPrice1(totalCities, flights, sourceCity, destCity, stops);
	return 0;
}

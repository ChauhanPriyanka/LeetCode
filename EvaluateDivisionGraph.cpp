#include "Solution.h"
#include<string.h>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
using namespace std;


/*
int minAreaRect(vector<vector<int>>& points) {
        vector<int> v[40001];
        int mn = INT_MAX;
        for(auto &point: points) v[point[0]].push_back(point[1]); // group by X co-ordinate
        for(int i = 0; i < 40000; i++) {
            if(v[i].size() > 0) { // there are some points with this i as X coordinate
                unordered_set<int> s;
                vector<int> inter;
                for(auto &p: v[i]) s.insert(p); // i is first x
                for(int j = i + 1; j < 40001; j++) {
                    if(v[j].size() > 0) { // j is the second x
                        inter.clear();
                        for(auto &r: v[j]) if(s.find(r) != s.end()) inter.push_back(r); // compute y-intersections for i and j
                        if(inter.size() < 2) continue; // there should be atleast 2 points to make a rectangle
                        sort(inter.begin(), inter.end());
                        for(int y = 0; y < inter.size() - 1; y++) mn = min(mn, (j-i)*(inter[y+1] - inter[y]));
                    }
                }
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
*/
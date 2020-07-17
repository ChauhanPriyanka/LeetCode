#include<string.h>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>

/*
using namespace std;

map <string, vector<pair<string, double>>> g;

void build_graph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            g[equations[i][0]].emplace_back(make_pair(equations[i][1], values[i]));
            g[equations[i][1]].emplace_back(make_pair(equations[i][0], 1/values[i]));
        }
    }
    double dfs(string a, string b, unordered_set<string> &visited) {
        double result = INT_MAX;
        if (visited.count(a))
            return result;
        visited.emplace(a);

		vector<pair<string, double>> :: iterator it;
		for (it = g[a].begin(); it != g[a].end(); ++it ) {
			string sA = it->first;
			if (sA.compare(b))
                return it->second;
            double next_r = dfs(it->first,b, visited);
            if (next_r != INT_MAX)
                result = min(result, it->second * next_r);
        }
        return result;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector <double> results;
        build_graph(equations, values);
        for (int i = 0; i<queries.size(); i++) {
            unordered_set <string> visited;
            double r = dfs(queries[i][0], queries[i][1], visited);
            results.emplace_back(r == INT_MAX?-1:r);
        }
        return results;
    }
	*/
#include<string.h>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
#include <unordered_set>
#include <algorithm>    // std::min_element, std::max_element
using namespace std;

int topologicalSort(vector<vector<int>>& relations, vector<int>& visited, vector<int>& depth, int course)
{
    if (visited[course] == 2)
    {
        return 0;
    }

    if (visited[course] == 1)
    {
        return -1;
    }

    visited[course] = 1;
	for (auto nextCourse : relations[course])
	{

		if (topologicalSort(relations, visited, depth, nextCourse) == -1)
			return -1;
		depth[course] = max(depth[course], depth[nextCourse] + 1);

	}
	visited[course] = 2;
	return 1;
}
int minimumSemesters(int N, vector<vector<int>>& relations)
{
    vector<int> visited(N + 1, 0);  //0-> Not visited, 1->visiting and 2->visited
    vector<int> depth(N + 1, 1);
    vector<vector<int>> g(N+1);
    for (auto r : relations) {
        g[r[0]].push_back(r[1]);
    }
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
            if (topologicalSort(g, visited, depth, i) == -1)
                return -1;
    }
    return *max_element(depth.begin(), depth.end());
}


enum VisitedState {
    // Indicates we are seeing a node for the first time.
    NOT_VISITED,

    // Indicates we are in the process of visiting this node's children (in a previous recursive call).
    // If we encounter a node with this state, then we have hit a cycle.
    VISITING_CHILDREN,

    // Indicates we have visited all the children of a node.
    // If we encounter a node with this state, then there are no cycles starting from that node.
    VISITED,
};



bool populateHeightsFrom(int root,
    const vector<vector<int>>& children,
    vector<VisitedState>& visitedStates,
    vector<int>& heights) {
    // If we've hit a node marked VISITED, then we know there are no cycles starting from this node
    // (otherwise it would have state VISITING_CHILDREN).
    if (visitedStates[root] == VISITED) {
        return true;
    }

    // If we've hit a node marked VISITING_CHILDREN, then we must have hit a cycle
    // (since we would mark the node as VISITED once we visited all children).
    if (visitedStates[root] == VISITING_CHILDREN) {
        return false;
    }

    // Now mark the node to indicate we are visiting children. If we re-counter this node
    // while performing DFS on children then we've hit a cycle.
    visitedStates[root] = VISITING_CHILDREN;

    for (auto child : children[root]) {
        auto foundCycle = !populateHeightsFrom(child, children, visitedStates, heights);
        if (foundCycle) {
            return false;
        }

        heights[root] = max(heights[root], 1 + heights[child]);
    }

    // Mark the node as visited once we've visited all children. If we encounter this node
    // in a future DFS we are guaranteed it will not contain any cycles (since we would have
    // already caught them at this point).
    visitedStates[root] = VISITED;

    return true;
}

int minimumSemesters1(int N, vector<vector<int>>& relations) {
    vector<vector<int>> children(N + 1);
    for (auto r : relations) {
        children[r[0]].push_back(r[1]);
    }

    vector<VisitedState> visitedStates(N + 1, NOT_VISITED);
    // All nodes start with height 1.
    vector<int> heights(N + 1, 1);

    for (int i = 1; i <= N; ++i) {
        auto foundCycle = !populateHeightsFrom(i, children, visitedStates, heights);
        if (foundCycle) {
            return -1;
        }
    }

    return *max_element(heights.begin(), heights.end());
}

unsigned long int catalan(unsigned int n)
{
    // Base case 
    if (n <= 1) return 1;

    // catalan(n) is sum of catalan(i)*catalan(n-i-1) 
    unsigned long int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}


int main1136()
{
    int N= 3;
    //vector<vector<int>> vec = { { 1, 3 }, {2, 3}};
    vector<vector<int>> vec = { { 1, 2 }, {2, 3}, {3,1} };
    //int count = minimumSemesters(N, vec);

    for (int i = 0; i < 10; i++)
        cout << catalan(i) << " ";

    return 0;
}
#include "Solution.h"
#include<string.h>
#include <set>
#include<vector>
#include<iostream>
#include<map>
#include<stack>
using namespace std;

int distance(const vector<int> &p) {
	return p[0] * p[0] + p[1] * p[1];
}


// [low, high]
int partition(vector<vector<int>>& points, int low, int high) {
	auto pivot = high;
	auto next = low;
	using std::swap;
	for (; low < high; low++) {
		int distLow = distance(points[low]);
		int disHigh = distance(points[high]);
		if (distLow < disHigh) 
		{
			swap(points[low], points[next++]);
		}
	}
	swap(points[pivot], points[next]);
	return next;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	if (points.size() < K) {
		return vector<vector<int>>();
	}
	int mid;
	int low = 0, high = points.size() - 1;
	while ((mid = partition(points, low, high)) != K-1) {
		if (mid < K-1) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return vector<vector<int>>(points.begin(), points.begin() + K);
}


int main9()
{
	vector<vector<int>> pos;

	vector<int> vec1, vec2, vec3;
	vec1.push_back(3);
	vec1.push_back(3);

	vec2.push_back(2);
	vec2.push_back(-1);

	vec3.push_back(2);
	vec3.push_back(4);

	pos.push_back(vec1);
	pos.push_back(vec2);
	pos.push_back(vec3);

	kClosest(pos,1);
	return 0;
}
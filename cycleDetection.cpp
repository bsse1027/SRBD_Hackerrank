#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
unordered_map<int, vector<int>> adjList;
int visited[101];
int dfsVisited[101];
bool isCycle;
bool flag = 0;
int minNodeSum = 999999999;
unordered_map<int, set<int>> probAns;
set<int> temp;
int min(int x, int y) {
	if (x < y) return x;
	return y;
}
void dfs(int currentNode, int nodeSum) {
	temp.insert(currentNode);
	visited[currentNode] = 1;
	dfsVisited[currentNode] = 1;
	for (auto i : adjList[currentNode]) {
		if (!visited[i]) {
			dfs(i,nodeSum+ i);
		}
		else {
			if (dfsVisited[i]) {
				//out << i << " ";
				if (nodeSum < minNodeSum) {
					set<int> result;
					auto pos = temp.find(i);
					for (auto it = pos; it != temp.end(); it++) {
						result.insert(*it);
					}
					minNodeSum = min(nodeSum, minNodeSum);
					//cout << minNodeSum << "-- ";
					probAns[minNodeSum] = result;
					temp.erase(i);
				}
				//isCycle = 1;
			}
		}
	}
	dfsVisited[currentNode] = 0;
}

int main()
{
	int vertices, edges;
	int start;
	cin >> vertices >> edges;
	for (int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		visited[i] = 0;
		dfsVisited[i] = 0;
	}
	isCycle = 0;
	for (int i = 1; i <= vertices; i++) {
		if(!visited[i]) dfs(i, i);
	}
	cout << endl;
	for (auto i : probAns[minNodeSum]) {
		cout << i << " ";
	}
}

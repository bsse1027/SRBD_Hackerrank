#include <iostream>
#include <vector>
using namespace std;
int N;
int Sx, Sy, Dx, Dy;
int visited[50];
int minCost;

struct nodes {
	int x, y;
};

int abs(int x) {
	if (x >= 0) return x;
	return -x;
}

int calcDist(nodes x, nodes y) {
	int xDist = abs(x.x - y.x);
	int yDist = abs(x.y - y.y);
	return xDist + yDist;
}

vector<nodes> points(50);

void traverse(int currentNode, int currentCost, int nodeLeft) {
	if (nodeLeft == 0) {
		currentCost = currentCost + calcDist(points[currentNode], points[N + 1]);
		if (currentCost < minCost) minCost = currentCost;
		return ;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			traverse(i, currentCost + calcDist(points[currentNode], points[i]), nodeLeft-1);
			visited[i] = 0;
		}
	}
}
int main()
{
	int T = 10;
	int Z = T;
	while (T--) {
		cin >> N;
		nodes startNode, endNode;
		cin >>startNode.x >> startNode.y >> endNode.x >> endNode.y;
		points[0] = endNode;
		for (int i = 1; i <= N;i++) {
			nodes temp;
			cin >> temp.x >> temp.y;
			points[i] = (temp);
			visited[i] = 0;
		}
		points[N+1]  = startNode;
		visited[N + 1] = 0;
		minCost = 9999999;
		visited[0] = 1;
		traverse(0, 0, N);
		//cout << calcDist(points[0], points[N + 1]);
		cout << "# " << Z-T <<" " << minCost << endl;
	}
}

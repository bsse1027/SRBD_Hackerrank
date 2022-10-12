#include <iostream>
#include <string>

using namespace std;

int main()
{
	int maxLevel;
	cin >> maxLevel;
	char graph[1001];
	cin >> graph;
	int currentLevel = -1;
	int sum = 0;
	int flag = 0;

	for (int i = 0; i < sizeof(graph); i++) {
		if (graph[i] == '(') currentLevel++;
		else if (graph[i] == ')') currentLevel--;
		else if (currentLevel == maxLevel) {
			if (graph[i] == '-') {
				flag = 1;
				continue;
			}
			int num = graph[i] - '0';
			i++;
			while (graph[i] - '0' >= 0 && graph[i] - '0' <= 9) {
				num = num * 10 + (graph[i] - '0');
				i++;
			}
			i--;
			if(!flag) sum += num;
			else if (flag) sum -= num; flag = 0;



		}
	}

	cout << sum;
	return 0;
}
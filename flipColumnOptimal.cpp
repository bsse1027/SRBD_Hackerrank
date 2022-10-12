#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N, M, K;
		int graph[110][110];
		unordered_map<int, int> frequency;
		int ans = 0;

		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			int zeroCount = 0;
			int value = 0;
			for (int j = 0; j < M; j++) {
				value = (value << 1) + graph[i][j];
				if (graph[i][j] == 0) zeroCount++;
			}
			if (!frequency.count(value))frequency[value] = 1;
			else frequency[value] ++;

			if ((K - zeroCount) % 2 == 0 && K >= zeroCount) {
				if (frequency[value] > ans) ans = frequency[value];
			}
		}

		cout <<"ANS : " << ans << endl;
	}
}


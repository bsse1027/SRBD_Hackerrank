#include <iostream>

using namespace std;
int N;
int graph[100][5];
int maxCoin;

void traverse(int currentCol, int currentRow, int coins, bool isBombed, int rowSafe ) {
	if (isBombed) rowSafe--;
	if (currentCol < 0 || currentCol>4 || currentRow < 0) {
		if (coins > maxCoin) maxCoin = coins;
		return;
	}
	if (graph[currentRow][currentCol] == 1) {
		int newCoins = coins;
		cout << currentRow << " " << currentCol << endl;
		newCoins++;
		traverse(currentCol, currentRow - 1, newCoins, isBombed, rowSafe);
		traverse(currentCol-1, currentRow - 1, newCoins, isBombed, rowSafe);
		traverse(currentCol+1, currentRow - 1, newCoins, isBombed, rowSafe);
	}

	else if (graph[currentRow][currentCol] == 0) {
		int newCoins = coins;
		traverse(currentCol, currentRow - 1, newCoins, isBombed, rowSafe);
		traverse(currentCol - 1, currentRow - 1, newCoins, isBombed, rowSafe);
		traverse(currentCol + 1, currentRow - 1, newCoins, isBombed, rowSafe);
	}

	else if (graph[currentRow][currentCol] == 2) {
		if (isBombed && rowSafe <= 0) {
			if (coins > maxCoin) maxCoin = coins;
			return;
		}
		else if (!isBombed) {
			isBombed = 1;
			rowSafe = 4;
			traverse(currentCol, currentRow - 1, coins, isBombed, rowSafe);
			traverse(currentCol - 1, currentRow - 1, coins, isBombed, rowSafe);
			traverse(currentCol + 1, currentRow - 1, coins, isBombed, rowSafe);
		}
		else {
			traverse(currentCol, currentRow - 1, coins, isBombed, rowSafe);
			traverse(currentCol - 1, currentRow - 1, coins, isBombed, rowSafe);
			traverse(currentCol + 1, currentRow - 1, coins, isBombed, rowSafe);
		}
	}
}


int main() {
	int T;
	cin >> T;
	int A = T;
	
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> graph[i][j];
			}
		}
		maxCoin = -1;
		traverse(2, N - 1, 0, 0, 0);
		traverse(1, N - 1, 0, 0, 0);
		traverse(3, N - 1, 0, 0, 0);
		cout <<"#"<< A-T <<" "<< maxCoin << endl;
	}
	return 0;
}

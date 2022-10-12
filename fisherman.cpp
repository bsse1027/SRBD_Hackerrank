#include <iostream>
#include <vector>

using namespace std;

int noOfSpots;
int minCost;
vector<int> visitSpot(100, 0);

struct gate {
	int loc, men;
};

gate gates[4];

int searchleft(int index) {
	for (int i = index; i > 0; i--) {
		if (!visitSpot[i]) return i;
	}
	return 99999;
}

int searchRight(int index) {
	for (int i = index+1; i <=noOfSpots; i++) {
		if (!visitSpot[i] ) return i;
	}
	return 999999;
}

void solve(int x, int y, int z, int cost, int start) {
	if (cost >= minCost) return;

	if (gates[start].men == 0) {
		if (start == x) start = y;
		else if (start == y) start = z;
		else {
			if (cost < minCost) minCost = cost;
			return;
		}
	}

	int left = searchleft(gates[start].loc);
	int right = searchRight(gates[start].loc);

	int leftCost = abs(left - gates[start].loc) + 1;
	int rightCost = abs(right - gates[start].loc) + 1;

	if (leftCost < rightCost) {
		visitSpot[left] = 1; //important, start index ei je fisherman boshbe gurantee nai, So left e jehetu gate er same spot er case ta ase so ekhan thekei visited ta start hbe.
		gates[start].men--;
		solve(x, y, z, cost + leftCost, start);
		visitSpot[left] = 0;
		gates[start].men++;
	}
	if (rightCost <= leftCost) {
		visitSpot[right] = 1;
		gates[start].men--;
		solve(x, y, z, cost + rightCost, start);
		visitSpot[right] = 0;
		gates[start].men++;
	}

}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> noOfSpots;
		for (int i = 1; i <= 3; i++) {
			cin >> gates[i].loc;
			cin >> gates[i].men;
		}
		//for (int i = 1; i <= 3; i++) {
		//	cin >> gates[i].men;
		//}
		minCost = 999999;
		solve(1, 2, 3, 0, 1);
		solve(1, 3, 2, 0, 1);
		solve(2, 1, 3, 0, 2);
		solve(2, 3, 1, 0, 2);
		solve(3, 1, 2, 0, 3);
		solve(3, 2, 1, 0, 3);
		cout << minCost;
	}
}

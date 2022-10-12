#include <iostream>
#include <vector>
#define INT_MAX 999999
using namespace std;
int N;
int Sx, Sy, Dx, Dy;
int ans;
struct Points {
    int x1, x2, y1, y2, weight;
};
vector<Points> nodes(20);
int visited[100];

int calcDistance(int x, int y) {
    if (x >= y) return x - y;
    else return y - x;
}

void solve(int x, int y, int cost) {
    if (cost >= ans) return;
    int direct;
    direct = calcDistance(x, Dx) + calcDistance(y, Dy) + cost;
    if (direct < ans) ans = direct;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int leftDist, rightDist;
            visited[i] = 1;
            leftDist = calcDistance(x, nodes[i].x1) + calcDistance(y, nodes[i].y1);
            rightDist = calcDistance(x, nodes[i].x2) + calcDistance(y, nodes[i].y2);
            if (leftDist < rightDist) {
                solve(nodes[i].x2, nodes[i].y2, cost+leftDist+nodes[i].weight);
            }
            else {
                solve(nodes[i].x1, nodes[i].y1, cost+rightDist+nodes[i].weight);
            }
            visited[i] = 0;
        }
    }

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        cin >> Sx >> Sy >> Dx >> Dy;
        for (int i = 0; i < N; i++) {
            Points temp;
            cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2 >> temp.weight;
            nodes[i] = temp;
            visited[i] = 0;
        }
        ans = INT_MAX;
        solve(Sx, Sy, 0);
        cout << ans << endl;
    }
    return 0;
}
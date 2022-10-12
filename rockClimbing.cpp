#include <iostream>

using namespace std;
int N, M;
int graph[20][20];
int visited[20][20];
int maxLevel;
int flag = 0;

void init(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

void dfs(int x, int y, int level) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (graph[x][y] == 3) {
        flag = 1;
        return;
    }
    visited[x][y] = 1;

    if (y-1 >=0 && (graph[x][y - 1] == 1 || graph[x][y - 1] == 3) && !visited[x][y - 1]) {
        dfs(x, y - 1, level);
    }

    if (y+1 <M && (graph[x][y + 1] == 1 || graph[x][y + 1] == 3) && !visited[x][y + 1]) {
        dfs(x, y + 1, level);
    }

    int height = 1;

    for (int i = height; i <= level; i++) {
        if (x-i >=0 && (graph[x-i][y] == 1 || graph[x-i][y] == 3) && !visited[x-i][y]) {
            dfs(x - i, y, level);
        }
    }

    for (int i = height; i <= level; i++) {
        if (x+i < M && (graph[x + i][y] == 1 || graph[x + i][y] == 3) && !visited[x + i][y]) {
            dfs(x + i, y, level);
        }
    }

}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        init();
        dfs(N-1, 0, i);
        if (flag) {
            cout << i;
            break;
        }
    }

}

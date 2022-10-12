/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct points{
  int r, c , length;  
};

int graph[100][100];
int T, M, N, R, C, L;
int visited[100][100];
queue<points> nodes;
int ans;

bool checkUp(int x, int y){
    if(graph[x][y] == 1 || graph[x][y] == 2 || graph[x][y] == 4 || graph[x][y] == 7) return true;
    return false;
}

bool checkDown(int x, int y){
    if(graph[x][y] == 1 || graph[x][y] == 2 || graph[x][y] == 5 || graph[x][y] == 6) return true;
    return false;
}

bool checkLeft(int x, int y){
    if(graph[x][y] == 1 || graph[x][y] == 3 || graph[x][y] == 6 || graph[x][y] == 7) return true;
    return false;
}

bool checkRight(int x, int y){
    if(graph[x][y] == 1 || graph[x][y] == 3 || graph[x][y] == 4 || graph[x][y] == 5) return true;
    return false;
}

void traverse(){
    while(!nodes.empty()){
        points start = nodes.front();
        points temp;
        ans++;
        nodes.pop();
        if(start.length <=1) continue;
        if(start.r-1>=0 && checkUp(start.r, start.c) && checkDown(start.r-1, start.c) &&
        !visited[start.r-1][start.c]){
            visited[start.r-1][start.c]=1;
            temp.r = start.r-1;
            temp.c = start.c;
            temp.length = start.length-1;
            nodes.push(temp);
        }
        
        if(start.r+1<N && checkUp(start.r+1, start.c) && checkDown(start.r, start.c) &&
        !visited[start.r+1][start.c]){
            visited[start.r+1][start.c]=1;
            temp.r = start.r+1;
            temp.c = start.c;
            temp.length = start.length-1;
            nodes.push(temp);
        }
        
        if(start.c-1>=0 && checkLeft(start.r, start.c) && checkRight(start.r, start.c-1) &&
        !visited[start.r][start.c-1]){
            visited[start.r][start.c-1]=1;
            temp.r = start.r;
            temp.c = start.c-1;
            temp.length = start.length-1;
            nodes.push(temp);
        }
        
        if(start.c+1<M && checkLeft(start.r, start.c+1) && checkRight(start.r, start.c) &&
        !visited[start.r][start.c+1]){
            visited[start.r][start.c+1]=1;
            temp.r = start.r;
            temp.c = start.c+1;
            temp.length = start.length-1;
            nodes.push(temp);
        }
    }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> N >> M >> R >> C >> L;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> graph[i][j];
                visited[i][j] = 0;
            }
        }
        ans = 0;
        if(graph[R][C]){
            points start;
            start.r = R;
            start.c = C;
            start.length = L;
            visited[start.r][start.c]=1;
            nodes.push(start);
            traverse();
        }
        cout << ans << endl;
    }

    return 0;
}

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#define INT_MAX 99999999

using namespace std;
int N;
int matrix[100][100];
int visited[100];
int minCost;

void permutation(int curretNode, int nodeLeft, int currCost){
    if(nodeLeft == 0){
        currCost = currCost + matrix[curretNode][0];
        if(currCost < minCost) minCost = currCost;
        return;
    }
    
    for(int i=1; i<N; i++){
        if(!visited[i]){
            visited[i] = 1;
            permutation(i, nodeLeft-1, currCost+matrix[curretNode][i]);
            visited[i] = 0;
        }
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--){
        minCost = INT_MAX;
        cin >> N;
        for(int i=0; i<N;i++){
            for(int j=0; j<N; j++){
                cin >> matrix[i][j];
            }
        }
        visited[0] = 1;
        permutation(0,N-1,0);
        cout << minCost << endl;
    }
}

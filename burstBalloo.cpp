#include<iostream>
using namespace std;

int n;
int ballons[50];
int dp[100][100];

int solve(int l, int r)
{
    if(dp[l][r] != -1) return dp[l][r];
    
    dp[l][r] = 0;
    for (int i = l+1; i < r; i++)
    {
        int cs = solve(l,i) + solve(i, r);

        if (l == 0 && r == n+1)
            cs = cs + ballons[i];
        else
            cs = cs + ballons[l] * ballons[r];

        if (cs > dp[l][r])
            dp[l][r] = cs;
    }
    return dp[l][r];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ballons[i];
    }
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dp[i][j] = -1;
        }
    }
    ballons[0] = 1;
    ballons[n + 1] = 1;
    cout << solve(0, n + 1) << endl;
    return 0;
}
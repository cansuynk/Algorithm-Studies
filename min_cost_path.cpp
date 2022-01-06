#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

#define N 3
int min (int n1, int n2, int n3){
    if(n1 <= n2 && n1 <= n3)
        return n1;
    if(n2 <= n1 && n2 <= n3)
        return n2;
    return n3;
}
//minimum cost path (mcp)
//recursive programming
int minCost(int cost[N][N], int m, int n){
    //look at m[i][j-1], m[i-1][j] and m[i-1][j-1], choose min cost
    if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return cost[m][n];
    else{
        return cost[m][n] + min(minCost(cost, m, n-1), minCost(cost, m-1, n), minCost(cost, m-1, n-1));
    }
}

//dynamic implementation
int minCost_dynamic(int cost[N][N], int m, int n)
{
    int i, j;
    int dp[N][N]; 

    dp[0][0] = cost[0][0];

    /* Initialize first column of total cost array */
    for (i = 1; i <= m; i++)
        dp[i][0] = dp[i - 1][0] + cost[i][0];

    /* Initialize first row of dp array */
    for (j = 1; j <= n; j++)
        dp[0][j] = dp[0][j - 1] + cost[0][j];

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            dp[i][j] = min(dp[i - 1][j - 1],  dp[i - 1][j],  dp[i][j - 1]) + cost[i][j];

    return dp[m][n];
}


int main(){

    int cost[N][N] = { { 1, 2, 3 },
                       { 4, 8, 2 },
                       { 1, 5, 3 } };
                        
    cout << minCost(cost, 2, 2) << endl;

    return 0;
}
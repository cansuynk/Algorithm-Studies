#include <iostream>

using namespace std;

#define N 3
int max(int n1, int n2){
    return (n1 > n2) ? n1 : n2;
}
//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{ 
    
    //base case
    if(n == 0 || W == 0) 
        return 0;
    
    //if weight is greater than W, not included
    if(wt[n-1] > W)
        return knapSack(W, wt, val, n-1);
    
    //return the max of 2 cases
    //if item is included
    //if item is not included
    else{
        return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
    }
}


int main(){

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
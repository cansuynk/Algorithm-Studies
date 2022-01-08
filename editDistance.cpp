#include <stdio.h>
#include <string>

using namespace std;


int min (int n1, int n2, int n3){
        if(n1 <= n2 && n1 <= n3)
            return n1;
        if(n2 <= n1 && n2 <= n3)
            return n2;
        return n3;
}
//dynamic programming
int editDistance(string s, string t, int m, int n) {

    int dp[m+1][n+1];
    
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            //if s is empty, insert all characters from t
            if( i == 0 )
                dp[i][j] = j;
            
            //if n is empty remove all character from s
            else if( j == 0)
                dp[i][j] = i;
            
            //if last characters are the same, ignore it
            //add remaning characters operations
            else if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                //if the last character is different
                //consider all operations and take min one.
                //insertion, deletion, removing
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}

//recursive programming
int editDistance_recursive(string s, string t, int m, int n){
    if(m==0)
        return n;
    if(n==0)
        return m;
    
    if(s[m - 1] == t[n - 1]){
        return editDistance_recursive(s, t, m-1, n-1);
    }
    return 1 + min(editDistance_recursive(s,t,m,n-1), editDistance_recursive(s,t,m-1,n), editDistance_recursive(s,t,m-1,n-1));
}

int main(){

    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistance(str1, str2, str1.length(), str2.length()) << endl;
    cout << editDistance_recursive(str1, str2, str1.length(), str2.length());

    return 0;
}

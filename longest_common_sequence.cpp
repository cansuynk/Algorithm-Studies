#include <iostream>
#include <string>
using namespace std;

//recursive implementation
int lcs_recursive(char A[], char B[], int m, int n){

    if (m == 0 || n == 0){
        return 0;
    }
    if(A[m-1] == B[n-1]){
        return 1 + lcs_recursive(A, B, m-1, n-1);
    }else{
        if (lcs_recursive(A, B, m-1, n) > lcs_recursive(A, B, m, n-1))
            return lcs_recursive(A, B, m-1, n);
        else
            return lcs_recursive(A, B, m, n-1);
    }
}

//dynamic implementation for longest common sequence problem
int lcs_dynamic(char *A, char *B) {
   
    const int m = sizeof(A)/sizeof(A[0]) - 1;
    const int n = sizeof(B)/sizeof(B[0]) - 1;
    int L[m+1][n+1];
    
    
    if (m == 0 || n == 0){
        return 0;
    }
    
    for(int i = 0; i<=m; i++){
        for(int j = 0; j<=n; j++){
            
            if(i==0 || j == 0){
                L[i][j] = 0;
            }
            else if(A[i-1] == B[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }
            else{
                if (L[i][j-1] > L[i-1][j])
                    L[i][j] = L[i][j-1];
                else
                    L[i][j] = L[i-1][j];
            }
        }
    }
    return L[m][n];
}

int main() {
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
    
    int m = sizeof(X)/sizeof(X[0]) - 1 ;
    int n = sizeof(Y)/sizeof(Y[0]) - 1; 
    
    printf("Length of LCS is %d\n", lcs_recursive( X, Y, m, n ) ); 
    printf("Length of LCS is %d", lcs_dynamic( X, Y) ); 
    
    return 0; 
} 
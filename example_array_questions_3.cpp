/******************************************************************************
 
 Some example leetcode solutions

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//Time Complexity: 2^n
int max(int a, int b, int c){
    if(a>b && a>c)
        return a;
    if(b>a && b>c)
        return b;
    return c;
}
int profit(vector<int>& prices, int l, int r){
    if(l<prices.size() && r<prices.size() && l<r){
        return max(prices[r]-prices[l], profit(prices, l, r+1), profit(prices, l+1, r+1));
    }
    return 0;
}
int maxProfit_rec(vector<int>& prices) {
    return profit(prices, 0, 1);
}
int min(int a, int b){
    if(a<b)
        return a;
    return b;
}

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int minn = prices[0];
    for(int i=1; i<prices.size(); i++){
        ans = max(ans, prices[i]-minn);
        minn = min(minn, prices[i]);
    }
    return ans;
}
//https://leetcode.com/problems/median-of-two-sorted-arrays/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    
    vector <int> ans;
    
    
    int mid = (m+n)/2;
    // 2 4 => 6 => 3 , 2 3 => mid, mid-1
    // 2 3 => 5 = 2, 
    
    int count = 0;
    int i=0;
    int j=0;
    
    while(count <= mid && i<m && j<n){
        if(nums1[i] < nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }else{
            ans.push_back(nums2[j]);
            j++;
        }
        count++;
    }
    
    while(count <= mid && i<m){
        ans.push_back(nums1[i]);
        i++;
        count++;
    }
    
    while(count <= mid && j<n){
        ans.push_back(nums2[j]);
        j++;
        count++;
    }
    
    if((m+n)%2==1){
        return ans[mid];
    }else{
        return (ans[mid] + ans[mid-1])/2.0;
    }
}

//https://leetcode.com/problems/reshape-the-matrix/
vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    
    if(m*n != r*c){
        return mat;
    }
    
    vector<vector<int>> ans(r, vector<int> (c, 0));
    int k=0;
    int l=0;
    // 1 2 3
    // 3 4 5
    //1 2 3 4
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            ans[i][j] = mat[k][l];
            l++;
            if(l>=n){
                k++;
                l=0;
            }
        }
    }
    return ans;
}

//https://leetcode.com/problems/pascals-triangle/
vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> ans;
    
    /*  1
       1 1
      1 2 1
     1 3 3 1
    */
    vector <int> col(1,1);
    ans.push_back(col); //1 2 3
    for(int i=2; i<=numRows; i++){ //3 4
        vector <int> col(i,1); //3
        for(int j=1; j<=i-2; j++){
            col[j]=ans[ans.size()-1][j-1] + ans[ans.size()-1][j];
        }
        ans.push_back(col);
    }
    
    return ans;
}

//https://leetcode.com/problems/search-a-2d-matrix/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
 
    int row = 0;

    //1, 3, 5, 7
    //10,11,16,20
    //23,30,34,60  13
    for(int i=0; i<matrix.size(); i++){
        if(matrix[i][0] <= target){
            row = i;
        }
        else{
            break;
        }
    }
    
    int l = 0;
    int h = matrix[row].size()-1;
    
    while(l<=h){
        int mid = l + (h-l)/2;
        if(matrix[row][mid] == target){
            return true;
        }
        else if(matrix[row][mid]>target){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return false;
    
}
void merge(vector<int> &arr, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1);
    vector<int> M(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

//https://leetcode.com/problems/squares-of-a-sorted-array/
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> sq(nums.size(),0);
    
    for(int i=0; i<nums.size(); i++){
        sq[i] = nums[i]*nums[i];
    }
    
    mergeSort(sq, 0, sq.size()-1);
    return sq;
}

int main()
{
    /*
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    
    vector <int> prices = {2,2,5};
    cout << maxProfit(prices) << endl;
    */

    /*
    vector<vector<int>> mat = {{1,2,3},{3,4,5}};
    vector<vector<int>> ans = matrixReshape(mat, 1, 6);
    */
    
    /*
    vector<vector<int>> ans = generate(5);
    
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    */

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << searchMatrix(matrix, 60) << endl;
    
    vector <int> nums = {-4,-1,0,3,10};
    vector <int> ans = sortedSquares(nums);
    
    for(int j=0; j<ans.size(); j++){
        cout << ans[j] << " ";
    }
    
    return 0;
}

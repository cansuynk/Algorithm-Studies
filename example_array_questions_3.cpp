/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
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

int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    
    vector <int> prices = {2,2,5};
    cout << maxProfit(prices) << endl;
    return 0;
}

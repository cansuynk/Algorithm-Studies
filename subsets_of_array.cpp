/******************************************************************************
Find all Subsets of an array
Credit: https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
Time Complexity: O(2 ^ (n))
Because at every step we have two choices
Either include or ignore.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> output){
  for(int i = 0; i < output.size(); i++){
    for(int j = 0; j < output[i].size(); j++){
      cout << output[i][j] << " "; 
    }
    cout << endl;
  }
}

void subsetsUtil(vector<int>& A, vector<vector<int> >& res,
                 vector<int>& subset, int index)
{
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {
 
        // include the A[i] in subset.
        subset.push_back(A[i]);
 
        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);
 
        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
 
    return;
}
 
// below function returns the subsets of vector A.
vector<vector<int> > subsets(vector<int>& A)
{
    vector<int> subset;
    vector<vector<int> > res;
 
    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);
 
    return res;
}


int main()
{
    vector<int>nums = {3,5,1,3,2};
    vector<vector<int>> result = subsets(nums);
    print (result);
    
    return 0;
}
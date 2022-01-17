/******************************************************************************

My Solutions of Some Leetcode Questions

*******************************************************************************/
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec[i];
    }
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
void moveZeroes(vector<int>& nums) {
    int zero = 0;
    int num = 0;
    int size = nums.size();
    
    while(num < size && zero < size){
        if(nums[num] == 0){
            num++;
        }
        else{
            if(nums[zero] == 0 && zero < num){
                nums[zero] = nums[num];
                nums[num] = 0;
                zero++; 
            }
            else if(nums[zero] == 0 && zero > num){
                num = zero + 1;
            }
            else{
               zero++; 
            }
            
        }
    }
}

//Recursive solution
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
vector<int> x(vector<int>& nums, int target, int size, int m, int n){
    if(m>=size)
        return {};
    
    if(n>=size){
        return x(nums, target, size, m+1, m+2);
    }
    else{
        if(nums[m] + nums[n] == target){
            return {m, n};
        }
    
        //x(nums, target, size, m+1, n);
        return x(nums, target, size, m, n+1);
    }

}
//Recurvise solution
vector<int> twoSum1(vector<int>& nums, int target) {
    return x(nums, target, nums.size(), 0, 1);
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
vector<int> twoSum(vector<int>& nums, int target) {
    
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
        }
    }
    return {};
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/
bool isValidSudoku(vector<vector<char>>& board) {
    
    int num;
    //check all rows
    for(int i=0; i<board.size(); i++){
        vector<int> hashMap(9, -1);
        for(int j=0; j<board.size(); j++){
            if(board[i][j] != '.'){
                num = board[i][j] - '0';
                if(hashMap[num%9] != -1){
                    return false;
                }else{
                    hashMap[num%9] = num;
                }
            }
        }
    }
    
    //check all columns
    for(int i=0; i<board.size(); i++){
        vector<int> hashMap(9, -1);
        for(int j=0; j<board.size(); j++){
            if(board[j][i] != '.'){
                num = board[j][i] - '0';
                if(hashMap[num%9] != -1){
                    return false;
                }else{
                    hashMap[num%9] = num;
                }
            }
        }
    }
    
    //check 3x3 boxes
    int k=0;
    int l=0;
    while(l<board.size()/3){
        vector<int> hashMap(9, -1);
        for(int i=l*3; i<(l+1)*board.size()/3; i++){
            for(int j=k*3; j<(k+1)*board.size()/3; j++){
                if(board[i][j] != '.'){
                    num = board[i][j] - '0';
                    if(hashMap[num%9] != -1){
                        return false;
                    }else{
                        hashMap[num%9] = num;
                    }
                }
            }
        }
        if(k+1>=board.size()/3){
            k = 0;
            l++;
        }
        else{
            k++;
        }
    }

    return true;
}

int main()
{
    /*
    vector<int> nums = {0,0,1,0,0,1,1,1,0,0};
    moveZeroes(nums);
    printVector(nums);
    */
    
    /*
    vector<int> nums = {3,2,4};
    //vector<int> ans = twoSum(nums, 9);
    vector<int> ans = twoSum(nums, 6);
    printVector(ans);
    */
    
    vector<vector<char>> board={
    {'5','3','.','.','7','.','.','.','.'}, 
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}};
    
    vector<vector<char>> board2={{'.','.','.','.','5','.','.','1','.'},
    {'.','4','.','3','.','.','.','.','.'},
    {'.','.','.','.','.','3','.','.','1'},
    {'8','.','.','.','.','.','.','2','.'},
    {'.','.','2','.','7','.','.','.','.'},
    {'.','1','5','.','.','.','.','.','.'},
    {'.','.','.','.','.','2','.','.','.'},
    {'.','2','.','9','.','.','.','.','.'},
    {'.','.','4','.','.','.','.','.','.'}};
    
    
    cout << isValidSudoku(board) << endl;
    
    return 0;
}

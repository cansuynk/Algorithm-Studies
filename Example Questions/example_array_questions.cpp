/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
int longestSubarray(vector<int>& nums, int limit) {
    //update!
    //Time Limit Exceeded!
    stack <int> s = stack<int>();

    int size = 0;
    int i=0;
    int j=0;
   
    s.push(nums[0]);
    int min = nums[0];
    int max = nums[0];
   
    while(j<nums.size()){
       
        int f = s.top();
       
        if(f < min){
            min = f;
        }
        if(f > max){
            max = f;
        }
        if(max - min <= limit && s.size()>size){
            size = s.size(); //1
        }
       
        i++;
        if(i==nums.size() && j<nums.size()-1){
            s = stack <int>();
            j++;
            i = j;
            max = nums[i];
            min = nums[i];
        }
        if(i<nums.size()){
            s.push(nums[i]);
        }
        else{
            j=i;
        }
    }
    return size;
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/
vector<int> plusOne(vector<int>& digits) {

    int i=digits.size()-1; //2
    vector<int> ans(digits.size() + 1,0);
    while(digits[i]==9 && i>0){
        digits[i] = 0;
        ans[i+1] = digits[i];
        i--;
    }
    
    if(i<=0 && digits[i] == 9){
        ans[0] = 1;
        return ans;
    }
    else{
        digits[i] = digits[i] + 1;
        return digits;
    }
    
}

//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/
void rotate(vector <vector<int>> &matrix){
	int size = matrix.size();
	int i = 0; int j = size-1;
	int k = 0; //determine which row or column;
	int temp = 0; //keep current value
	bool turn = true;
	int first = 0;
	int x = size-1;
 	while(first<size-1){
 	    
 	    if(turn){
 	        i = first;
 	        j = size-1;
 	        temp = matrix[first][size-1];
 	        turn = false;
 	    }
    	//upper row
    	if(k%4==0){
    	    
    		if(i==first && j==first){
    			matrix[i][j] = matrix[i+1][j];
    			k++;
            }
            else{
        		matrix[i][j] = matrix[i][j-1];
        		j--;
            }
        }
    	//left column
    	else if(k%4==1){
    	    
    		if(i==size-1 && j==first){
    			matrix[i][j] = matrix[i][j+1];
    			k++;
            }
            else{
    			matrix[i][j] = matrix[i+1][j];
    			i++;
            }		
        }
    	//bottom row
    	else if(k%4==2){
            if(i==size-1 && j==size-1){
    			matrix[i][j] = matrix[i-1][j];
    			k++;
            }else{
    			matrix[i][j] = matrix[i][j+1];
    			j++;
            }		
        }
    	//right column
    	else if(k%4==3){
            if(i==first+1 && j==size-1){
    			matrix[i][j] = temp;
    			k++;
    			turn = true;
            }
            else{
    			matrix[i][j] = matrix[i-1][j];
    			i--;
            }	
        }
        
        if(k==4*x){
            
 	        first++; //1
 	        
 	        size = size - 1; //3
 	        turn = true;
 	        x = size-first-1;
 	        k = 0;
 	        
 	    }
    }
}

void printDoubleVector(vector<vector<int>> vec){
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[i].size(); j++){
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }
}

void printVector(vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        cout << vec[i];
    }
}

int main()
{
    
    vector <int> nums={8};
    int limit = 10;
    
    cout<< longestSubarray(nums, limit);
    
    
    
    /*
    vector <int> num1={7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
    vector <int> num2={6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};
    vector <int> num3={9,9,8,9};
    vector <int> num4={8,9};
    vector <int> ans = plusOne(num4);
    printVector(ans);
    */
    
    
    
    /*
    vector <vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector <vector<int>> matrix2 = {{1,2,3},{4,5,6},{7,8,9}};
    vector <vector<int>> matrix3 = {{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}};
    
    printDoubleVector(matrix2);
    cout << endl;
    
    rotate(matrix2);
    
    printDoubleVector(matrix2);
    
    //[[4,33,13,32,12,2],[24,1,14,33,27,29],[1,20,32,32,9,20],[6,7,27,2,25,26],[32,21,22,28,13,16],[34,7,26,14,21,28]]
    */

    return 0;
}
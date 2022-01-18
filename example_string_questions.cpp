/******************************************************************************

My Solutions of Some Leetcode Questions

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
int lengthOfLongestSubstring(string s) {
    int ans;
    int maxAns = 0;
    int j;
    
    for(int i=0; i<s.length(); i++){
        j = i;
        vector<bool>hash(100,false);
        ans = 0;
        while(j<s.length()){
            if(!hash[s[j]%100]){ //if false
                ans++;
                hash[s[j]%100] = true;
            }
            else{
                break;
            }
            j++;
        }
        if(ans > maxAns){
            maxAns = ans;
        }
    }
    return maxAns;
}

//https://leetcode.com/explore/featured/card/top-interview-questions-easy/127/strings/879/
void reverseString(vector<char>& s) {
    
    int i=0;
    char temp;
    int size = s.size();
    
    //abab  -> baba
    while(i<size/2){ //2
        temp=s[i]; //a
        s[i] =s[size-1-i];
        s[size-1-i] = temp;
        i++;
    }
    
}

//https://leetcode.com/explore/featured/card/top-interview-questions-easy/127/strings/881/
int firstUniqChar(string s) {
    
    //26 english letters, -2 means this letter not seen
    vector<int>hash(26,-2);
    
    for(int i=0; i<s.length(); i++){
        
        if(hash[(s[i]-97)%26] == -2){
            hash[(s[i]-97)%26] = i;
        }
        else{
            hash[(s[i]-97)%26] = -1; //-1 means this letter is seen before
        }
    }
    
    for(int i=0; i<s.length(); i++){
        if(hash[(s[i]-97)%26]!=-1 && hash[(s[i]-97)%26]!=-2){
            return i;
        }
    }
    return -1;
    
}

int main()
{

    /*
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    */
    
    /*
    vector<char> s = {'c', 'a', 'n', 's', 'u'};
    reverseString(s);
    for(int i=0; i<s.size(); i++){
        cout << s[i];
    }
    */
    
    string s = "abcabkczz";
    cout << firstUniqChar(s);
    
    
    
    return 0;
}

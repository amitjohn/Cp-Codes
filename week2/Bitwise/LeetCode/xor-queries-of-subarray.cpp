// https://leetcode.com/problems/xor-queries-of-a-subarray/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int len= arr.size();
        vector<int>prefix(len,0);
        prefix[0] = arr[0];
        for(int i=1;i<arr.size();i++) prefix[i] = prefix[i-1]^arr[i];
            
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            if(l!=0)
                ans.push_back(prefix[l-1]^prefix[r]);
            else 
                ans.push_back(prefix[r]);
            
        }
        return ans;
    }
};
// Define Main method and take input
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

void findSubset(int ind, vector<int>&arr ,vector<int>&ds, vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i = ind; i<arr.size();i++){
        if(i!=ind && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        findSubset(ind+1, arr, ds, ans);
        ds.pop_back();
    }
}


int main() {
	vector<vector<int>>ans;
	vector<int>ds;
	vector<int>v={1,2,2,2,3,3};
	findSubset(0,v,ds,ans);
	for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }  
	    
	return 0;
}
// Given an array, Calculate the Maximum Length of an Subarray with Xor as Zero

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	unordered_map<int, int>mpp;
	int xr=0;
	mpp.insert({arr[0],0});
	int len=0;
	for(int i=0;i<n;i++){
	    xr = xr^arr[i];
	    if(xr==0)
	        len = i+1;
	   else if(mpp.find(xr)!=mpp.end()){
	       len = max(len, i-mpp[xr]+1);
	   }else{
	       mpp.insert({arr[i],i});
	   }
	}
	cout<<len;
	return 0;
}
// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;
vector<int>dp(1000000,-1);
int f(int ind, int n, int k, int arr[], int ans){
    if(ind == n-1)
        return 0;
    if(dp[ind] != -1)
        return dp[ind];
        int fans = INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind+i < n){
            ans = abs(arr[ind] - arr[ind+i]) + f(ind+i, n, k, arr, ans);
            fans = min(ans, fans);
        }
    }
        
    return dp[ind] = fans;
}


signed main() {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i =0;i<n;i++)   cin>>arr[i];
	cout<<f(0, n, k, arr, INT_MAX);
	return 0;
}
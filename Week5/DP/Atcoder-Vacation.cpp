// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>>dp(100000 , vector<int>(4, -1));

int max(int a , int b, int c){
    return a>b?(a>c?a:c):(b>c?b:c);
}
int f(int ind, int flag, int n,  int a[], int b[], int c[]){
    if(ind == n)
        return 0;
    
    if(dp[ind][flag]!=-1) return dp[ind][flag];
   
    int task1=0, task2=0, task3=0;
    if(flag == 0){
        task1 = task1  + a[ind] + f(ind+1, 1, n, a, b, c);
        task2 = task2  + b[ind] + f(ind+1, 2, n, a, b, c);
        task3 = task3  + c[ind] + f(ind+1, 3, n, a, b, c);
    } else if(flag == 1){
        task2 = task2  + b[ind] + f(ind+1, 2, n, a, b, c);
        task3 = task3  + c[ind] + f(ind+1, 3, n, a, b, c);
    } else if(flag == 2){
        task1 = task1  + a[ind] + f(ind+1, 1, n, a, b, c);
        task3 = task3  + c[ind] + f(ind+1, 3, n, a, b, c);
    }else if(flag == 3){
        task1 = task1  + a[ind] + f(ind+1, 1, n, a, b, c);
        task2 = task2  + b[ind] + f(ind+1, 2, n, a, b, c);
    }
    return dp[ind][flag] = max(task1, task2, task3);
}


signed main() {
	int n;
	cin>>n;
	int a[n],b[n],c[n];
	for(int i =0;i<n;i++) {
	    cin>>a[i]>>b[i]>>c[i];
	}
	cout<<f(0, 0, n, a, b, c);
	return 0;
}
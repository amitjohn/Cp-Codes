#include <bits/stdc++.h>
using namespace std;
typedef int long long ll;

bool isPossible(ll arr[], int n){
    ll sumY=0;
    for(int i=0;i<n;i++) sumY += arr[i];
    
    ll sum1=0;
    ll maX = INT_MIN;
    for(int i=1;i<n;i++){
        sum1 +=arr[i];
        if(sum1<0) sum1 = 0;
        maX = max(sum1, maX);
    }
    sum1=0;
    ll maXX = INT_MIN;
    for(int i=0;i<n-1;i++){
        sum1 +=arr[i];
        if(sum1<0) sum1 = 0;
        maXX = max(sum1, maXX);
    }
    return (sumY > max(maX, maXX));
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    
	    if(isPossible(arr, n))
	        cout<<"YES\n";
	    else
	        cout<<"NO\n";
	   	}
	return 0;
}
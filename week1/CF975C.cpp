// https://codeforces.com/problemset/problem/975/C

#include <bits/stdc++.h>
typedef int long long ll;
using namespace std;

int main() {
	ll n,q;
	cin>>n>>q;
	ll arr[n];
	for(ll i=0;i<n;i++) cin>>arr[i];
	ll prefix[n+1] = {0};
	for(ll i=1;i<=n;i++) prefix[i] = prefix[i-1]+arr[i-1];
	ll curr=0;
	for(ll i=0;i<q;i++){
	    ll k;
	    cin>>k;
	    curr +=k;
	    ll low=1, high = n,ans=0;
	    while(low<=high){
	       ll mid = low + (high-low)/2;
	       if(curr>=prefix[n]){
	           curr=0;
	           ans=n;
	           break;
	       }else 
	       if(curr == prefix[mid]){
	           ans = n-mid;
	           break;
	           
	       }else if(curr<prefix[mid]){
	           high = mid-1;
	       }else
	       if(curr>prefix[mid]){
	           low=mid+1;
	           ans=n-mid;
	          // cout<<"mid "<<mid<<" "<<"ans "<<ans<<"\n";
	       }
	    }
	    if(ans==0)
    		cout<<n<<"\n";
    	else
    		cout<<ans<<"\n";
	    
	}
	return 0;
}
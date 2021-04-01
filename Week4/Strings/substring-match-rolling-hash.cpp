//Week4 day2
#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = (int)1e9+7;
// int computeHash(string s){
//     int hash = 0;
//     int pr=1;
//     for(int i=0;i<s.length();i++){
//         hash = (hash + ((s[i] - 'a' + 1)*pr)%mod)%mod;
//         pr = (pr * 31)%mod; 
//     }
    
//     return pr;
// }
int modpower(int base, int x, int mod){
    int ans =1;
    while(x){
        if(x%2==0){
            base = (base*base)%mod;
            x=x/2;
        }else{
             ans = (ans*base)%mod;
             x--;
        }
    }
    return ans;
}

bool ComputeSubstringHash(string s){
    int n = s.size();
    int hash = 0;
    int pr=1;
    int preHash[n]; //declaring a prehash array similary to prefix sum technique
    for(int i=0;i<n;i++){
        hash = (hash + ((s[i] - 'a' + 1)*pr)%mod)%mod;  // a user defined hash function which can minimize collision
        pr = (pr*31)%mod; // pr^i
        preHash[i] = hash;
    }
    int i1,j1;
    cin>>i1>>j1; //indexes of Substring-1 
    int i2,j2;
    cin>>i2>>j2; //indexes of Substring-2 
    int s1hash = preHash[j1];
    if(i1>0) s1hash = (preHash[j1] - preHash[i1-1] + mod)%mod;   // finding the hash value similar to the prefix technique ' + mod ' is just a way to prevent overlapping of hash values
    //here fermat little theorem is applied to calculate (pre[j]-pre[i])/(31^i) 
    s1hash = (s1hash * modpower(modpower(31, i1, mod),mod-2,mod))%mod; 
    
    
    int s2hash= preHash[j2];
    if(i2>0) s2hash = (preHash[j2] - preHash[i2-1] + mod)%mod;
    s2hash = (s2hash * modpower(modpower(31, i2, mod),mod-2,mod))%mod;
    
    if(s1hash == s2hash)
        return true;
    else 
        return false;
}
signed main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout<<ComputeSubstringHash("aabaa");
	return 0;
}
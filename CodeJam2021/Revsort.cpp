// Problem Link
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

#include<bits/stdc++.h>
using namespace std;
int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
    int t;
    cin>>t;
    int nm=1;
    while(t--){
        int ans=0;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        for(int i=0; i<n-1; i++){
            int min_ind = i;
            for(int j=i; j<n; j++){
                if(arr[j] < arr[min_ind])
                    min_ind = j;
            }
            if(min_ind>i)
                reverse(arr+i, arr+min_ind+1);
            ans += (min_ind+1)-(i+1)+1;
        }
         cout<<"Case #"<<nm++<<": "<<ans<<"\n";
    }
    return 0;
}
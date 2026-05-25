///template
#ifdef LOCAL
#define redir(X, Y)            \
    freopen((X), "r", stdin);  \
    freopen((Y), "w", stdout); 
#else
#define redir(X, Y)
#endif

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
#define SZ(X) ((int)((X).size()))
typedef long long int ll;

///template

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n; ll k; cin>>n>>k;
    vector<ll> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<ll> srted;
    for(int i=0, j=n-1; j-i>=0; ){
        if(nums[i]>nums[j]){
            srted.push_back(nums[j]);
            j--;
        } else{
            srted.push_back(nums[i]);
            i++;
        }
    }

    int l=0, r=n-1;
    ll ret = 1e18;
    while(l<=r){
        ret = min(ret, abs(k-srted[l]*srted[r]));

        if(srted[l]*srted[r]>k){
            r--;
        } else{
            l++;
        }
    }

    cout << ret;
}
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

vector<pair<int, ll>> tree[200005];
int defaults[200005];
ll ret[200005];

void dfs(int i, int par, int sw, ll cost){
    if (defaults[i]==0){ //it is leaf
        ret[sw] = min(ret[sw], cost);
        return;
    }

    for(auto[j, cst]: tree[i]){
        if(j!=par){
            dfs(j, i, sw+(j!=defaults[i]), cost+cst);
        }
    }
}

int main(){
    fastio;
    redir("in.txt", "out.txt");

    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        ll w; cin>>w;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }
    for(int i=1; i<=n; i++){
        cin >> defaults[i];
    }

    for(int i=0; i<n; i++){
        ret[i] = 1e15;
    }
    dfs(1, 0, 0, 0);
    
    ll ans = 1e15;
    for(int i=0; i<n; i++){
        ans = min(ans, ret[i]);
        cout << ans << '\n';
    }
}
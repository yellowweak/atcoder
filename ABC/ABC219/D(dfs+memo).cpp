#include <bits/stdc++.h>
using namespace std;
// BEGIN LIB
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
#define print_grid(x) for(auto &r:x){for(auto &c:r)cout<<c<<" ";cout<<endl;}cout<<endl;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> grid;
typedef pair<ll, ll> pll;
int mod = 1000000007;
// END LIB

int dfs(vector<vvi> &dp, vector<array<int,2>> &box, int ith, int rx, int ry){
    if(rx<=0&&ry<=0)    return 0;
    if(ith==sz(box))    return INT_MAX/2;
    if(dp[ith][rx][ry]==-1){
        int newx = max(0,rx-box[ith][0]);
        int newy = max(0,ry-box[ith][1]);
        int take_ith = dfs(dp,box,ith+1,newx,newy)+1;
        int skip_ith = dfs(dp,box,ith+1,rx,ry);

        dp[ith][rx][ry] = min(take_ith, skip_ith);
    }
    return dp[ith][rx][ry];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N,X,Y;cin>>N>>X>>Y;
    int suma=0, sumb=0;
    vector<array<int,2>> box(N);
    vector<vvi> dp(N, vvi(301, vi(301, -1)));
    rep(i,0,N){
        cin>>box[i][0]>>box[i][1];
        suma+=box[i][0];
        sumb+=box[i][1];
    }
    if(suma<X || sumb<Y){
        cout << -1;
        return 0;
    }
    sort(box.rbegin(), box.rend());
    cout << dfs(dp,box,0,X,Y);
    
    return 0;
}
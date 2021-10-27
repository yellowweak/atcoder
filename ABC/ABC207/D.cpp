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
// END LIB
int dot(vi &v1, vi &v2){
    return v1[0]*v2[0]+v1[1]*v2[1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,t1,t2; cin>>n;
    int msx=0, msy=0, mtx=0, mty=0;
    vvi s(n,vi(2)), t(n,vi(2));
    unordered_map<int, unordered_map<int,int>> ums;
    rep(i,0,n){
        cin>>t1>>t2;
        s[i][0] = 100*t1;
        s[i][1] = 100*t2;
        msx+=s[i][0];
        msy+=s[i][1];
    }
    msx/=100; msy/=100;
    rep(i,0,n){
        cin>>t1>>t2;
        t[i][0] = 100*t1;
        t[i][1] = 100*t2;
        mtx+=t[i][0];
        mty+=t[i][1];
    }
    mtx/=100; mty/=100;
    rep(i,0,n){
        s[i][0]-=msx; s[i][1]-=msy;
        t[i][0]-=mtx; t[i][1]-=mty;
        int sr = s[i][0]*s[i][0]+s[i][1]*s[i][1];
        // s[i].push_back();
        // t[i].push_back(t[i][0]*t[i][0]+t[i][1]*t[i][1]);
        ums[sr][s[i][0]]=s[i][1];

    }

    return 0;
}
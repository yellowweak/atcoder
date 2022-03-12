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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin>>N;
    vector<int> X(N), Y(N);
    unordered_map<int, int> LmaxR, RmaxL;
    rep(i,0,N){
        cin >> X[i]>> Y[i];
    }
    string S; cin>>S;
    for(int i=0; i<N; i++){
        if(S[i]=='L'){
            if(LmaxR.count(Y[i])==0 || LmaxR[Y[i]]<X[i])
                LmaxR[Y[i]] = X[i];
        }
        if(S[i]=='R'){
            if(RmaxL.count(Y[i])==0 || RmaxL[Y[i]]>X[i])
                RmaxL[Y[i]] = X[i];
        }
    }
    bool flag = false;
    for(auto [y,x]:LmaxR){
        if(flag) break;
        if(RmaxL.count(y)>0 && RmaxL[y]<x) flag = true;
    }

    cout << (flag? "Yes":"No");

    return 0;
}
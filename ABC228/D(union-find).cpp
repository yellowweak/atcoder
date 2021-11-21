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
int find(vi &who, int root){
    if(who[root]!=root){
        who[root] = find(who, who[root]);
    }
    return who[root];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N=1048576;
    vll A(N,-1);
    vi who(N,-1);
    int Q; cin>>Q;
    rep(i,0,Q){
        ll type, x;
        cin >> type >> x;
        int xmn = x%N;
        if(type==1){
            if(who[xmn]==-1){
                int l = who[(xmn+N-1)%N];
                int r = who[(xmn+1)%N];
                if(l==-1&&r==-1)    who[xmn] = xmn;
                else if (l!=-1&&r==-1)  who[l] = who[xmn] = xmn;
                else if (l==-1&&r!=-1)  who[xmn] = find(who, r);
                else who[l] = who[xmn] = find(who, r);
                A[xmn] = x;
            }
            else{
                int l = find(who, xmn);
                int target = (l+1)%N;
                int r = (target+1)%N;
                if(who[r]==-1)  who[l] = who[target] = target;
                else who[l] = who[target] = find(who, r);
                A[target] = x;
            }
        }
        else {
            cout << A[xmn] <<endl;
        }
    }


    return 0;
}
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

    int N,Mx,Mi; cin>>N>>Mx>>Mi;
    vi A(N); cin >> A;
    map<int, set<int>> mp;
    int l=0, r=0;
    ll ans=0;
    mp[A[0]].emplace(0);
    while(r<N){
        int b = mp.begin()->first;
        int e = mp.rbegin()->first;
        if(b<Mi || e>Mx){
            r++; l=r;
            mp.clear();
        }
        else if(b==Mi && e==Mx){
            int b_i = *(mp[b].rbegin());
            int e_i = *(mp[e].rbegin());
            int pos = min(b_i, e_i);
            ans += pos-l+1;
            r++;
        }
        else{
            r++;
        }
        if(r<N) mp[A[r]].emplace(r);
    }

    cout << ans << endl;

    return 0;
}
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
bool ok(vi &slots, int m, int l, int k){
    int sum=0, n=slots.size()-1;
    for(int prev_cut_pos=0, i=0; i<k; i++){
        int cut_pos = prev_cut_pos+1;
        while(cut_pos<=n && slots[cut_pos]-slots[prev_cut_pos]<m)   cut_pos++;
        if(cut_pos > n)     return false;
        sum += slots[cut_pos]-slots[prev_cut_pos];
        prev_cut_pos = cut_pos;
    }
    return l-sum >= m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,l,k; cin>>n>>l>>k;
    vi slots(n+1);
    slots[0] = 0;
    rep(i,0,n)  cin>>slots[i+1];
    int L=1, R=l;
    while(L<R){
        int m = (L+R)/2;
        if(!ok(slots, m, l, k))  R = m;
        else        L = m+1;
    }
    cout << L-1;

    return 0;
}
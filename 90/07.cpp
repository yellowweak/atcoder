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

    int N,Q; cin>>N;
    vi A(N); cin >>A>>Q;
    vi B(Q); cin>>B;
    int ans=0;
    sort(all(A));
    for(auto b:B){
        auto it = lower_bound(all(A), b);
        if(it == A.end())   ans=abs(A.back()-b);
        else if (it == A.begin())   ans=abs(A[0]-b);
        else{
            int pos = it-A.begin();
            ans = min(abs(A[pos-1]-b), abs(A[pos]-b));
        }
        cout << ans << endl;
    }

    return 0;
}
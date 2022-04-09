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

    int N,K; cin>>N>>K;
    vi A(N); cin>>A;
    vector<pii> st = {{A[0], 0}};
    for(int i=1; i<K; i++){
        while(!st.empty() && A[i]<st.back().first)   st.pop_back();
        if(st.empty())  st.push_back(make_pair(A[i], i));
        else if(A[i]==st.back().first)   st.back() = make_pair(A[i], i);
        else st.push_back(make_pair(A[i],i));
    }
    int ans = INT_MAX;
    for(int i=K; i<N; i++){
        if(A[i]<=st[0].first)    continue;
        auto it = upper_bound(all(st), make_pair(A[i]-1, INT_MAX));
        it--;
        ans = min(ans, i-it->second);
    }
    cout << (ans==INT_MAX? -1:ans) << endl;
    return 0;
}
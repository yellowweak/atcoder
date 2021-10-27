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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N,Q,K,sum=0; cin>>N>>Q;
    vll A(N); cin>>A;
    sort(all(A));
    vector<pll> seg;
    ll maxll=1000000000000000000LL;
    A.push_back(maxll+1+N);
    for(int i=0; i<=N; i++){
        if(i==0){
            if(A[i]==1) continue;
            else{
                sum+=A[i]-1;
                seg.push_back({sum, 1});
            }
        } else {
            if(A[i]-A[i-1]==1)  continue;
            else {
                sum += A[i] - A[i-1] -1;
                seg.push_back({sum, A[i-1]+1});
            }
        }
    }
    rep(i,0,Q){
        cin >> K;
        int l=0, r=seg.size()-1;
        while(l<r){
            int m=(l+r)/2;
            if(K>seg[m].first) l=m+1;
            else r=m;
        }
        if(l==0){
            cout << seg[l].second + K-1 << endl;;
        } else {
            cout << seg[l].second + (K-seg[l-1].first)-1<<endl;
        }
    }
    return 0;
}
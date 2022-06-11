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

    int N, Q; cin>>N>>Q;
    vll A(N), X(Q); cin>>A>>X;
    vector<ll> L(N+1), R(N+1);
    sort(all(A));
    ll tmp=0;
    for(auto a:A)   tmp+=abs(a-A[0]);
    R[N]=tmp;
    for(int i=1; i<N; i++){
        R[N-i] = R[N-i+1] - (N-i)*(A[i]-A[i-1]);
    }
    tmp=0;
    for(auto a:A)   tmp+=abs(a-A[N-1]);
    L[N]=tmp;
    for(int i=1; i<N; i++){
        L[N-i] = L[N-i+1] - (N-i)*(A[N-i]-A[N-i-1]);
    }
    unordered_map<ll, int> um;
    for(int i=0; i<N; i++)  um[A[i]] = i;
    for(auto x:X){
        ll ans;
        if(um.count(x)>0){
            int ti = um[x];
            if(ti==0)   ans=R[N];
            else if(ti==N-1)    ans=L[N];
            else    ans=L[ti+1]+R[N-ti];
        }
        else if(x<A[0])
            ans = R[N] + N*abs(x-A[0]);
        else if(x>A[N-1])
            ans = L[N] + N*abs(x-A[N-1]);
        else{
            auto it = upper_bound(all(A), x);
            int tl = it-A.begin(); tl--;
            ans = L[tl+1] + R[N-tl-1] + (tl+1)*abs(x-A[tl]) + (N-tl-1)*abs(x-A[tl+1]);
        }
        cout << ans << endl;
    }

    return 0;
}
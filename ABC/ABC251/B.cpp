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

    int N, W; cin >>N>>W;
    vi A(N); cin >> A;
    unordered_set<int> us;
    sort(all(A));
    for(auto a:A)   if(a<=W)us.emplace(a);
    for(int i=0; i<N-1 && A.size()>1; i++){
        for(int j=i+1; j<N; j++){
            if(A[i]+A[j]<=W)us.emplace(A[i]+A[j]);
        }
    }
    for(int i=0; i<N-2 && A.size()>2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(A[i]+A[j]+A[k]<=W)us.emplace(A[i]+A[j]+A[k]);
            }
        }
    }
    cout << us.size();

    return 0;
}
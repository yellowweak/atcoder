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

int f(int x){
    return x*x+2*x+3;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K; cin>>N>>K;
    vi P(N); cin >>P;
    priority_queue<int, vi, greater<int>> pq;
    for(int i=0; i<K; i++)    pq.emplace(P[i]);
    cout << pq.top() << endl;
    for(int i=K; i<N; i++){
        if(P[i]>pq.top()){
            pq.emplace(P[i]);
            pq.pop();
        }
        cout << pq.top()<< endl;
    }


    return 0;
}
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
 
typedef pair<int,vector<int>> pivi;
struct Comp {
    bool operator()(const pivi& lhs, const pivi& rhs){
        return lhs.second.size() < rhs.second.size();
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N,M,k,tmp;cin>>N>>M;
    vvi A(M);
    rep(i,0,M){
        cin>>k;
        rep(j,0,k){
            cin>>tmp;
            A[i].emplace_back(tmp);
        }
    }
    unordered_map<int,int> um1;
    unordered_map<int,vi> um2;
    rep(i,0,M){
        if(A[i].size()==0)  continue;
        if(um1.count(A[i].back())>0){
            um2[A[i].back()] = {um1[A[i].back()], i};
            um1.erase(A[i].back());
        }
        else um1[A[i].back()] = i;
    }
    while(!um2.empty()){
        auto [k,v] = *(um2.begin());
        um2.erase(k);
        for(auto i:v){
            A[i].pop_back();
            if(A[i].size()>0){
                if(um1.count(A[i].back())>0){
                    um2[A[i].back()] = {um1[A[i].back()], i};
                    um1.erase(A[i].back());
                }
                else um1[A[i].back()] = i;
            }
        }
    }
 
    cout << (um1.size()==0? "Yes":"No");
    
    return 0;
}
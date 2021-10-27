#include <bits/stdc++.h>
using namespace std;
int ans=0;
vector<pair<int, int>> bps;
unordered_map<int, vector<int>> umr, umc;

void dfs(int r, int c){
    if(true){}

    
}
int main(){
    int N, X, Y;
    cin >>N;
    for(int i=0; i<N; i++){
        cin >> X >> Y;
        bps.push_back({X,Y});
        umr[X].push_back(Y);
        umc[Y].push_back(X);
    }
    for(auto &[k, v]:umr)    sort(v.begin(), v.end());
    for(auto &[k, v]:umc)    sort(v.begin(), v.end());

    dfs(N, 0);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXN = 1e6 + 5;

vector<int> tree[MAXN];
vector<int> dp[MAXN];
bool anc[MAXN];
int res = 0;


void dfs(int v, int anc){
    for(auto w : tree[v]){
        if(w == anc) continue;

        dfs(w, v);

        int wsize = dp[w].size();
        int vsize = dp[v].size();

        if(wsize > vsize){
            for(int i = 0; i < vsize && vsize; i++){
                dp[w][wsize - vsize + i] += dp[v][i];
                res = max(res, dp[w][wsize - vsize + i] - (vsize - i + 1));
            }
            dp[v] = move(dp[w]);
        }else{
            for(int i = 0; i < wsize && wsize; i++){
                //cout << "xd" << "\n";
                dp[v][vsize - wsize + i] += dp[w][i];
                res = max(res, dp[v][vsize - wsize + i] - (wsize - i + 1));

            }
            dp[w].clear();
            dp[w].shrink_to_fit();
        }
    }

     dp[v].push_back(1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++) anc[i] = 0;

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            tree[i].push_back(a);
            anc[a] = true;
        }
    }



    for(int i = 1; i <= n; i++){
        if(!anc[i]) {
            dfs(i, i);
            dp[i].clear();
            dp[i].shrink_to_fit();
        }
    }

    cout << res << "\n";

    return 0;
}

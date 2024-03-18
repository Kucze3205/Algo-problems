#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3 + 3;
const int MAXK = 1e6 + 3;

vector<int> Graf[MAXN * 2]; //pamięć : 0(4 * 4 * m + 2 * n * 12)
vector<pair<int, int>> Path[MAXN * 2]; //pamięć : 0(2 * n * 12 + k * 2 * 8)
int lenght[MAXK];
queue<int> sequence;
bool visited[MAXN * 2];
int dist[MAXN * 2];
bool result[MAXK];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);

        Graf[a].push_back(b + n);
        Graf[b + n].push_back(a);
        Graf[a + n].push_back(b);
        Graf[b].push_back(a + n);
    }


    for(int i = 1; i <= n * 2; i++)
        dist[i] = -1;


    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &a, &b, &lenght[i]);

        if(lenght[i] % 2 == 0){
            Path[a].push_back({b, i});
            Path[b].push_back({a, i});
        }
        else{
            Path[a].push_back({b + n, i});
            Path[b].push_back({a + n, i});

        }
    }

    for(int i = 1; i <= n; i++){
        sequence.push(i);
        if(Graf[i].size()) dist[i] = 0;

        while(sequence.size()){
            int v = sequence.front();
            sequence.pop();
            visited[v] = true;

            for(auto w : Graf[v]){
                if(!visited[w]){
                    dist[w] = dist[v] + 1;
                    sequence.push(w);
                }
            }
        }

        for(auto w : Path[i]){
            if(dist[w.first] != -1 && dist[w.first] <= lenght[w.second])
                result[w.second] = true;
        }

        for(int i = 1; i <= 2 * n; i++){
            visited[i] = false;
            dist[i] = -1;
        }
    }

    /*for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n * 2; j++)
            cout << path[i][j] << " ";
        cout << "\n";
    }*/


    for(int i = 0; i < k; i++) {
        if(result[i]) cout << "TAK";
        else cout << "NIE";
        cout << "\n";
    }


    return 0;
}

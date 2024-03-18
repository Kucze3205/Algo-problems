#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 3;
const int MAXP = 1e6 + 3;
vector<int> conn[MAXN];
string wyn[2*MAXN];

void base(int n){
    for(int i = 1; i <= n; i++){
        wyn[i] += 'A';
    }
    for(int i = n + 1; i <= n * 2; i++){
        wyn[i] += 'B';
    }
}

void Addend(int n){
    for(int l = 1; l <= n; l++){
        for(int i = 1; i <= n; i++){
            wyn[i] += 'A';
        }
        for(int i = n + 1; i <= n * 2; i++){
            if(l + n == i) wyn[i] += 'C';
            else wyn[i] += 'B';
        }
    }

    for(int i = 1; i <= n; i++){
        wyn[i] += 'A';
    }
    for(int i = n + 1; i <= n * 2; i++){
        wyn[i] += 'B';
    }
}

void solve() {

    for(int i = 0; i < MAXN; i++) conn[i].clear();
    for(int i = 0; i < MAXN * 2; i++) wyn[i].clear();

    int n, p, M;
    cin >> n >> p >> M;

    int a, b;
    for(int i = 0; i < p; i++){
        cin >> a >> b;
        conn[a].push_back(b);
    }

    //base(n);
    int layer = 0;

    for(int i = 1; i <= n; i++){
        base(n);
        wyn[i][layer] = 'C';
        if(conn[i].size()){
            for(auto to : conn[i])
                wyn[to][layer] = 'C';
        }
        layer++;
    }
    Addend(n);

    //wyn[1] += 'C';
    cout << layer + n + 1 << "\n";
    for(int i = 1; i <= 2 * n; i++)
        cout << wyn[i] << "\n";
}

int main() {
  int test_cases = 1;
  cin >> test_cases;
  while(test_cases--) {
    solve();
  }
}

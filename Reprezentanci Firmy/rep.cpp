#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 3;
const int base = 1 << 18;
int pay[MAXN];
vector<pair<pair<int, int>, int>> team;//index od 0
vector<int> sec[MAXN];//index od 1
int bin[base << 1];

vector<int> result;


stack<int> maker;
void dfs(){

}


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pay[i];

    cin >> m;
    int a, b, c;
    team.push_back({{1,n},0});
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        team.push_back({{a, -b}, c});
    }

    sort(team.begin(), team.end());


    maker.push(0);
    pair<int, int> curr = team[0].first;

    for(int i = 1; i < m; i++){
        while(curr.second < team[i].first.first){

                maker.pop();
                curr = team[maker.top()].first;
        }
        if(curr.second >= team[i].first.first){
            sec[i].push_back(maker.top());
            maker.push(i);
            curr = team[i].first;
        }
    }

    for(int i = 1; i < m; i++){
        for(auto w : sec[i]){}
           // cout << w << "<--" << i;

    }

    return 0;
}

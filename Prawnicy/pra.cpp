#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;

priority_queue<pair<int, pair<int, bool>>> mainQue;
priority_queue<pair<int, int>> expTime;
pair<int, int> law[MAXN];
bool disactive[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> law[i].first >> law[i].second;

        mainQue.push({-law[i].first, {i , true}});
        mainQue.push({-law[i].second, {i , false}});

    }

    pair<int, int> result = {0, 0};

    while(mainQue.size()){
        int time = -mainQue.top().first;
        int id = mainQue.top().second.first;
        bool start = mainQue.top().second.second;
        mainQue.pop();

        if(start){
            expTime.push({-law[id].second, id});

            if(expTime.size() >= k){

                if(expTime.top().first != time){

                    if(result.first < -expTime.top().first - time)
                        result = {-expTime.top().first - time, time};

                }
                disactive[expTime.top().second] = true;
                expTime.pop();

            }
        }
        else{
            if(!disactive[id]){
                expTime.pop();
                disactive[id] = true;
            }
        }
    }

    cout << result.first << "\n";

    int j = 0;
    for(int i = 0; i < n; i++){
        if(law[i].first <= result.second && law[i].second >= result.first + result.second){
            j++;
            cout << i + 1 << " ";
        }
        if(j == k)
            break;
    }

    return 0;
}

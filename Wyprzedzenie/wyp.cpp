#include <iostream>                                                             
#include <queue>
using namespace std;

double long dotyk[100007];
bool dotknol[100007];
double v[100007];
int x[100007];
int d[100007];
priority_queue<pair<double long, int>> momenty;

//dsu
int sajz[100007];
int rep[100007];

int true_rep(int w) {
    return (rep[w] == w) ? w : rep[w] = true_rep(rep[w]);
}


double long moment_dotkniecia(int a, int b) {

    return (x[b] - d[b] - x[a]) / (v[a] - v[b]);
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, D, W;
    double Vel;

    cin >> n >> D >> W >> Vel;
    Vel = W / Vel;

    v[0] = Vel;
    x[0] = 0;
    d[0] = D;

    for (int i = 1; i <= n; i++) {
        int m;
        cin >> x[i] >> d[i] >> v[i] >> m;
        v[i] = v[i] / m;
        sajz[i] = 1;
        rep[i] = i;
    }


    for (int i = 0; i < n; i++) {
        if (v[i] > v[i + 1]) {
            dotyk[i] = moment_dotkniecia(i, i + 1);
            momenty.emplace(-dotyk[i], i);
        }
    }

    int wynik = 0;
    int nastepny = 1;
    while (momenty.size()) {
        while (momenty.top().second != 0) {

            int tir = momenty.top().second;

            if (momenty.top().first > dotyk[tir]) {
                momenty.pop();
                continue;
            }

            momenty.pop();

            dotknol[tir] = true;
            d[true_rep(tir + 1)] += d[tir];

            if (v[rep[tir - 1]] > v[rep[tir + 1]]) {
                dotyk[tir - sajz[tir]] = moment_dotkniecia(tir - sajz[tir], true_rep(tir + 1));
                momenty.emplace(-dotyk[tir - sajz[tir]], tir - sajz[tir]);
            }


            v[rep[tir + 1]] = v[rep[tir]];
            sajz[rep[tir + 1]] += sajz[rep[tir]];
            rep[tir] = rep[tir + 1];
        }


        double long mom_wyp = nastepny == 1 ? -1 : (x[nastepny - 1] - x[0] + d[0]) / (v[0] - v[nastepny - 1]); // moment wyprzedzenia poprzedniej ciê¿arówki
        if (dotyk[0] >= mom_wyp)
            wynik++;

        momenty.pop();

        if (nastepny >= n)
            break;
        nastepny = nastepny + sajz[nastepny];
        dotyk[0] = moment_dotkniecia(0, nastepny);
        momenty.emplace(-dotyk[0], 0);
    }
    cout << wynik;

    return 0;
}
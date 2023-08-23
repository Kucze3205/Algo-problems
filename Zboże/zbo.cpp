#include <iostream>                                                             
#include <queue>                                                                                                                             
using namespace std;

#define MAX 100007

vector<pair<int, int>> Graf[MAX];
int sajz[MAX]; // wielkoœæ i-tego poddrzewa
int my_Centroid[MAX];
bool cutted[MAX];

int krol_amount[MAX];
int Ilosc_zboza[MAX];
int Zboze_z_zamkow[MAX];
int n, k;
int Listakrolestw[MAX];

int wynik[MAX];

void dfs_FindSajz(int v, int ojciec) {
    sajz[v] = 1;

    for (auto w : Graf[v]) {
        if (w.first == ojciec || cutted[w.first])
            continue;

        dfs_FindSajz(w.first, v);
        sajz[v] += sajz[w.first];
    }
}

void dfs_FindOdl(int v, int ojciec, int ilosc_zboza_ojca) {

    for (auto w : Graf[v]) {
        if (w.first == ojciec || cutted[w.first])
            continue;

        Ilosc_zboza[w.first] = w.second + ilosc_zboza_ojca;

        dfs_FindOdl(w.first, v, Ilosc_zboza[w.first]);
    }
}


int FindCentroid(int v, int ojciec, int tree_size, int old_centroid) {

    for (auto w : Graf[v]) {
        if (w.first == ojciec || cutted[w.first])
            continue;

        if (sajz[w.first] > (tree_size + 1) / 2)
            return FindCentroid(w.first, v, sajz[w.first], old_centroid);

    }
    return v;
}

void Decentroization(int v, int tree_size, int old_centroid) {

    int centroid = FindCentroid(v, 0, tree_size, old_centroid);

    cutted[centroid] = true;
    my_Centroid[centroid] = old_centroid;
    dfs_FindOdl(centroid, 0, 0);

    for (auto w : Graf[centroid]) {
        if (cutted[w.first])
            continue;
        dfs_FindSajz(w.first, 0);
        Decentroization(w.first, sajz[w.first], centroid);
    }


}

int update(int v, int dlugosc_drogi) {
    krol_amount[v]++;

    if (my_Centroid[v] == 0)
        return 0;

    int wyn_z_cent = krol_amount[my_Centroid[v]] - krol_amount[v] + 1;
    wyn_z_cent *= (dlugosc_drogi + Ilosc_zboza[v]);
    Zboze_z_zamkow[my_Centroid[v]] += (dlugosc_drogi + Ilosc_zboza[v]);
    wyn_z_cent += Zboze_z_zamkow[my_Centroid[v]] - (Ilosc_zboza[v] * krol_amount[v]) - dlugosc_drogi;



    return wyn_z_cent + update(my_Centroid[v], Zboze_z_zamkow[v] + Ilosc_zboza[v]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    int a, b, c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        Graf[a].push_back({ b,c });
        Graf[b].push_back({ a,c });
    }

    dfs_FindSajz(1, 0);
    Decentroization(1, n, 0);

    Listakrolestw[0] = 1;
    int currCent = 1;

    while (currCent != 0) {
        krol_amount[currCent]++;
        Zboze_z_zamkow[my_Centroid[currCent]] += Ilosc_zboza[currCent];
        currCent = my_Centroid[currCent];
    }

    for (int i = 1; i <= k; i++) {
        cin >> Listakrolestw[i];
        wynik[i] = wynik[i - 1] + 2 * update(Listakrolestw[i], 0);
    }

    for (int i = 1; i <= k; i++) {
        cout << wynik[i] << '\n';
    }

    return 0;
}
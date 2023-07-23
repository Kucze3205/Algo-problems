#include <iostream>
#include <queue>
using namespace std;

char grid[2007][2007];
bool visited[2007][2007];

string VerticalWord(int x, int y, int a) {
    string result;
    for (int i = x; i < a + x; i++) {
        result += grid[i][y];
        if (visited[i][y])
            return "&";
    }
    return result;
}

string HorizontalWord(int x, int y, int a) {
    string result;
    for (int i = y; i < a + y; i++) {
        result += grid[x][i];
        if (visited[x][i])
            return "&";
    }
    return result;
}

void V_MakeVisited(int x, int y, int a) {
    for (int i = x; i < a + x; i++) {
        visited[i][y] = true;
    }
}

void H_MakeVisited(int x, int y, int a) {
    for (int i = y; i < a + y; i++) {
        visited[x][i] = true;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> result;
    bool hrsntlChecked = false;

    for (int k = 1; k <= max(m, n); k++) {

        if ((m * n) % k == 0) {


            for (int i = 0; i < 2007; i++) { // make visited false
                for (int j = 0; j < 2007; j++) {
                    visited[i][j] = false;
                }
            }

            string wzorzec;

            if (!hrsntlChecked) {
                wzorzec = HorizontalWord(0, 0, k);
                H_MakeVisited(0, 0, k);
                hrsntlChecked = true;
            }
            else {
                wzorzec = VerticalWord(0, 0, k);
                V_MakeVisited(0, 0, k);
                hrsntlChecked = false;
            }

            bool pasuje = true;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    if (visited[i][j] == false) {
                        if (wzorzec == HorizontalWord(i, j, k)) {
                            H_MakeVisited(i, j, k);
                        }
                        else if (wzorzec == VerticalWord(i, j, k)) {
                            V_MakeVisited(i, j, k);
                        }
                        else {  // wyjœcie z pêtli, wzorzec niepasuje
                            i = n + 1;
                            j = m + 1;
                            pasuje = false;
                        }
                    }

                }
            }

            if (pasuje) {
                result.push_back(k);
                hrsntlChecked = false;
            }
            else
                if (!hrsntlChecked) {
                    k--;
                }
        }
    }

    cout << result.size() << "\n";

    if (result.size() > 0)
        cout << result[0];

    for (int i = 1; i < result.size(); i++)
        cout << " " << result[i];

}
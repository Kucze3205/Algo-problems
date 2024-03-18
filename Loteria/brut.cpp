#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int n, k;
int tab[MAXN];
int wyn = 0;
vector<int> st;

bool check(){
    int k = 1;
    for(auto a : st){
        //cout << a << " ";
        if(a != k){
            //cout << "\n";
            return false;
        }
        k++;
    }
    //cout << "\n";
    return true;
}

void solution2(int i, int left){
    //cout << n - k + i + 1 << "\n";
    for(int j = i; j < n - left; j++){
        st.push_back(tab[j]);
        if(left == 0){
            if(check()) wyn++;
            st.pop_back();

        }
        else {
            solution2(j + 1, left - 1);
            st.pop_back();
        }
    }

}

void solution(int i){
    st.push_back(tab[i]);
    if(st.size() == k){
            if(check()) wyn++;
            st.pop_back();
    }else{
        for(int j = i + 1; j <= n - k + i - 1; j++){
            solution(j);
        }
        st.pop_back();
    }
}

int main(){

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> tab[i];
    }
    //for(int i = 0; i < n; i++)
        //solution(i);

    solution2(0, k - 1);
    cout << wyn << "\n";
}

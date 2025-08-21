#include <bits/stdc++.h>
using namespace std;

int n, m;
int adj[54][54];
vector<pair<int, int>> homes, chickens;
vector<vector<int>> remainChickenLists;
int ret = 987654321;

void combi(int start, vector<int>& v){
    if(v.size() == m){
        remainChickenLists.push_back(v);
        return;
    }

    for(int i = start + 1; i < chickens.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> adj[i][j];

            if (adj[i][j] == 1){
                homes.push_back({i, j});
            }

            if (adj[i][j] == 2){
                chickens.push_back({i, j});
            }
        }
    }

    vector<int> v;
    combi(-1, v);

    for(vector<int> remainChickenList : remainChickenLists){
        int temp = 0;
        for(auto home : homes){
            int _min = 987654321;
            for(int i : remainChickenList){
                int _dist = abs(home.first - chickens[i].first) + abs(home.second - chickens[i].second);
                _min = min(_min, _dist);
            }

            temp += _min;
        }

        ret = min(ret, temp);
    }
    
    cout << ret << "\n";
    return 0;
}
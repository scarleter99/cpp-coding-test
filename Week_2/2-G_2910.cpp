#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<pair<int, int>> v; 
map<int, int> mp, mp_first; 

bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.second == b.second)
    {
		return mp_first[a.first] < mp_first[b.first];
	}

	return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
        
        if(mp_first[temp] == 0) 
        {
            mp_first[temp] = i + 1; 
        }
    }

    for (auto it : mp)
    {
        v.push_back({it.first, it.second});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v)
    {
        for (int j = 0; j < i.second; j++)
        {
            cout << i.first << " ";
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int k;
char opers[14];
int use[14];
vector<string> v;
string str;

bool cmp(int a, int b, char oper){

    if (oper == '<'){
        return a < b;
    }
    else{
        return a > b;
    }
}

void dfs(int idx){
    if (idx > k){
        v.push_back(str);
        return;
    }

    for (int i = 0; i < 10; i++){
        if (!use[i] && cmp(str[idx-1] - '0', i, opers[idx-1])){
            str += to_string(i);
            use[i] = 1;
            idx++;
            dfs(idx);
            str.pop_back();
            use[i] = 0;
            idx--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    
    for (int i = 0; i < k; i++){
        cin >> opers[i];
    }
    
    for (int i = 0; i < 10; i++){
        str += to_string(i);
        use[i] = 1;
        dfs(1);
        str.pop_back();
        use[i] = 0;
    }

    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << "\n" << v[0] << "\n";
    cout << (v[v.size() - 1] > v[0]) << "\n";
    return 0;
}
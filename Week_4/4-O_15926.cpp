#include <bits/stdc++.h>
using namespace std;

int n, now, cnt, _max;
int a[200004];
string str;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> str;
    
    for (int i = 0; i < n; i++){
        if (str[i] == '('){
            st.push(i);
        }
        else if (st.size()){
            a[i] = 1;
            a[st.top()] = 1;
            st.pop();
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i]){
            cnt++;
            _max = max(_max, cnt);
        }
        else{
            cnt = 0;
        }
    }

    cout << _max;

    return 0;
}
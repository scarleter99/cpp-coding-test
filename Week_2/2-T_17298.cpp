#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000004];
int ret[1000004];
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    fill(ret, ret + n, -1);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        
        while(st.size() && a[st.top()] < a[i]){
            ret[st.top()] = a[i];
            st.pop();
        }

        st.push(i);
    }

    for (int i = 0; i < n; i++){
        cout << ret[i] << " ";
    }

    return 0;
}
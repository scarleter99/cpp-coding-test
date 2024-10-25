#include<bits/stdc++.h>
using namespace std;

stack<int> st;
string a, b;

void algo(string a, string b) {
    int sum = 0;
	
    while(a.size() || b.size() || sum){
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back(); 
        }
        st.push(sum % 10); 
        sum /= 10;
    } 
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> a >> b;

    algo(a, b);

    while (st.size()){
        cout << st.top();
        st.pop();
    }

    return 0; 
}

#include <bits/stdc++.h>
using namespace std;

int n;
string line, temp;
vector<string> v;

void algo()
{
    while(true)
    {  
		if(temp.size() && temp.front() == '0')
            temp.erase(temp.begin()); 
		else 
            break;
	}

	if(temp.size() == 0) 
        temp = "0"; 
	v.push_back(temp);

    temp = "";
}

bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }

    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (char i : line)
        {
            if (i >= '0' && i <= '9')
            {
                temp += i;
            }
            else if(temp.size())
            {
                algo();
            }
        }

        if (temp.size())
        {
            algo();
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (string i : v)
    {
        cout << i << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, sTeam, sum, lastSum, s1, s2, t1, t2;
string sTime;

void printEx(int t)
{
    string m = "00" + to_string(t / 60);
    string s = "00" + to_string(t % 60);
    cout << m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2) + "\n";
}

int getTime(string str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3));
}

void algo()
{
    if (s1 > s2)
    {
        t1 += sum - lastSum;
    }
    else if(s2 > s1)
    {
        t2 += sum - lastSum;
    }

    lastSum = sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> sTeam >> sTime;

        sum = getTime(sTime);

        algo();

        if (sTeam == 1)
        {
            s1++;
        }
        else
        {
            s2++;
        }
    }

    sum = getTime("48:00");

    algo();

    printEx(t1);
    printEx(t2);

    return 0;
}
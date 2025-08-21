#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

template <typename T>
class Queue {
    static const int QSIZE = 5;

    T q[QSIZE];
    int in = 0;
    int out = 0;
    int cnt = 0;

public:
    void enqueue(T a){
        if (cnt >= QSIZE){
            cout << "Error1: " << a << endl;
            return;
        }

        q[in] = a;
        in = in + 1 < QSIZE ? in + 1 : 0;
        cnt++;
    }

    void dequeue(){
        if (cnt == 0){
            cout << "Error2" << endl;
            return;
        }

        out = out + 1 < QSIZE ? out + 1 : 0;
        cnt--;
    }

    T front(){
        if (cnt == 0){
            return -1;
        }

        return q[out];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    cout << q.front() << endl;

    q.enqueue(7);
    q.dequeue();
    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;

    q.dequeue();
    cout << q.front() << endl;

    q.dequeue();
    q.enqueue(8);
    cout << q.front() << endl;


    return 0;
}
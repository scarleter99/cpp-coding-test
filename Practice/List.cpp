#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

template <typename T>
class Node {
public:
    T data;
    Node* prev = nullptr;
    Node* next = nullptr;
public:
    Node(T val) : data(val)
    {}
};

template <typename T>
class List {
public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:
    void push_back(T a){
        Node<T>* node = new Node(a);
        if(head == nullptr){
            head = tail = node;
            return;
        }
        
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    void push_front(T a){
        Node<T>* node = new Node(a);
        if(head == nullptr){
            head = tail = node;
            return;
        }
        
        head->prev = node;
        node->next = head;
        head = node;
    }

    void erase(T val){
        Node<T>* node = head;
        while(node){
            if(node->data == val){
                if(node->prev){
                    node->prev->next = node->next;
                }
                else{
                    head = node->next;
                }

                if(node->next){
                    node->next->prev = node->prev;
                }
                else{
                    tail = node->prev;
                }
                
                delete node;
                return;
            }

            node = node->next;
        }

        cout << "No Value" << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    List<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.erase(1);
    l.erase(2);
    l.erase(4);

    cout << l.head->data << endl;
    cout << l.tail->data << endl;

    return 0;
}
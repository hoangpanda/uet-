#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() 
    {
        data  = 0;
        next = NULL;
    }

    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
    }
};  

class dq {
Node* head;

public:
    dq() 
    {
        head = NULL;
    }
    void insert_node(int);
    void delete_node();
    void print_list();
};

void dq::insert_node(int data) 
{
    Node* new_node = new Node(data);
    if(head == NULL) {
        head = new_node;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;

}

void dq::print_list() 
{   
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << ' ';
        temp = temp -> next;
    }
    cout << endl;
}

void dq::delete_node() 
{
    Node* temp = head;
    head = head->next;
    delete(temp);
    return;
}

int main() {
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    dq q;
    for(int i = 1; i <= n; ++i) {
        string s; cin >> s;
        if(s == "enqueue") {
            int data; cin >> data;
            q.insert_node(data);
        }
        else {
            q.delete_node();
        }
    }
    q.print_list();
}
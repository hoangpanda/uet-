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
    void delete_node(int);
    void print_list();
    void insert_node_index(int,int);
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

void dq::insert_node_index(int index, int data) 
{
    if(head == NULL) {
        head = new Node(data);
        return;
    }
    
    Node* temp = head;
    for(int i = 1; i <= index - 2; ++i) {
        temp = temp -> next;
    }
    // cout << temp->data << endl;
    Node* new_node = new Node(data);
    new_node->next = temp->next;
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

void dq::delete_node(int index) 
{
    Node* temp = head;
    for(int i = 1; i <= index - 2; ++i) {
        temp = temp -> next;
    }
    Node* temp2 = temp->next;
    temp->next = temp2->next;
    delete(temp2);
}

int main() {
    // int n; cin >> n;
    // dq q;
    // int ss = 0;
    // for(int i = 1; i <= n; ++i) {
    //     string s; cin >> s;
    //     if(s == "enqueue") {
    //         int data;
    //         q.insert_node_index(ss,data);
    //         ss++;
    //     }
    //     else {
    //         q.delete(1);
    //     }
    // }
    // q.print_list();
}
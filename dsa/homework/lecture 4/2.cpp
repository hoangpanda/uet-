#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node() 
    {
        data = 0;
        next = NULL;
    }
    node(int data) 
    {
        this->data = data;
        next = NULL;
    }
};

class link_list {
public:
node* head;
public:
    link_list() 
    {
        head = NULL;
    }
    void insert(int); 
    void print_list();
    bool check_empty();
};

void link_list::insert(int data) {
    node* new_node = new node(data);
    if(head == NULL) {
        head = new_node;
        return;
    }

    node *temp = head;
    while(temp->next != NULL) {
        temp = temp ->next;
    }
    temp->next = new_node;
}

void link_list::print_list() {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data;
        if(temp->next != NULL) cout << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

bool link_list::check_empty() {
    return head == NULL;
}

int hash_f(int n) {
    return (2*n+5) % 11;
}


int main() {
    vector<int> num = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    for(auto v:num) cout << hash_f(v) << ' ';
    cout << endl;

    vector<link_list> a(10);
    for(auto v:num) {
        int hash_v = hash_f(v);
        a[hash_v].insert(v);
    }
    for(int i = 0; i < 10; ++i) {
        if(!a[i].check_empty()) {
            cout << i << ':' << ' ';
            a[i].print_list();
        }
    } 
}
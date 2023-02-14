#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
    node() 
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(int data) 
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class linked_list {
public:
node* head;
public:
    linked_list()
    {
        head = NULL;
    }
    void insert(int);
    void print_list(); 
    void show();
    int count_triples();
};

void linked_list::insert(int data)
{
    node* new_node = new node(data);
    if(head == NULL) {
        head = new_node;
        return;
    }

    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void linked_list::print_list() 
{
    node* temp = head;
    while(temp != NULL) {
        // cout << temp->data << ' ';
        temp = temp -> next;
    }
    cout << endl;
} 

void linked_list::show() 
{
    cout << head->data << endl;
}

int linked_list::count_triples() 
{
    int cnt = 0;
    node *temp = head;
    temp = temp->next;
    while(temp->next != NULL) {
        int sum = temp->data + temp->next->data + temp->prev->data;
        if(!sum) cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main() {
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    linked_list list;
    for(int i = 1; i <= n; ++i) {
        int num; cin >> num;
        // cout << num << ' ';
        list.insert(num);
    }
    cout << list.count_triples();
}
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

class linked_list {
Node* head;

public:
    linked_list() 
    {
        head = NULL;
    }
    void insert_node(int);
    void delete_node(int);
    void print_list();
    void insert_node_index(int,int);
};

void linked_list::insert_node(int data) 
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

void linked_list::insert_node_index(int index, int data) 
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

void linked_list::print_list() 
{   
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << ' ';
        temp = temp -> next;
    }
    cout << endl;
}

void linked_list::delete_node(int index) 
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
    freopen("input.txt","r",stdin);
    linked_list list;
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        string s; cin >> s;
        if(s == "insert") {
            int index, data;
            cin >> index >> data;
            list.insert_node_index(index+1,data);
        }
        else {
            int index; cin >> index;
            list.delete_node(index+1);
        }   
    }
    list.print_list();
}
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
    node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class circular_linked_list {
public:
node* head;
node* tail;
public:
    circular_linked_list() {
        head = NULL;
        tail = NULL;
    }
    void insert_item(int data, int index);
    void print();
    void delete_item(int index);
};

void circular_linked_list::insert_item(int data, int index) {
    node* new_node = new node(data);
    if(head == NULL) {
        head = new_node;
        tail = new_node;
        return;
    }

    node* temp = head;
    for(int i = 1; i < index - 1; ++i) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        // last element
        temp->next = new_node;
        new_node->next = head;
        tail = new_node;
        new_node->prev = temp;
        head->prev = tail;
        return;
    }

    node* temp2 = temp->next;
    temp->next = new_node;
    new_node->next = temp2;
    new_node->prev = temp;
    new_node->next->prev = new_node;

}

void circular_linked_list::print() {
    node* temp = head;
    while(temp != tail) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void circular_linked_list::delete_item(int index) {
    if(index == 1) {
        node* temp = head;
        tail->next = head->next;
        head = temp->next;
        tail->next = head;
        head->prev = tail;
        delete(temp);
    }
    else {
        node* temp = head;
        for(int i = 1; i < index - 1; ++i) {
            temp = temp -> next;
        }
        node* temp2 = temp->next;
        temp->next = temp2->next;
        temp->next->prev = temp;
        delete(temp2);
    }
}

int main() {
    circular_linked_list list;
    list.insert_item(3,1);
    list.insert_item(4,2);
    list.insert_item(5,2);
    list.delete_item(2);
    list.print(); 
}
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class hash_table
{
    int bucket;
    list<int> *table;

public:
    hash_table(int v);
    void insert_item(int x);
    void delete_item(int x);
    int hash_function(int x);
    void display();
};

int hash_table::hash_function(int x) {
    return (x % bucket);
}

void hash_table::insert_item(int x) {
    int hash_v = hash_function(x);
    table[hash_v].push_back(x);
}

void hash_table::delete_item(int x) {
    int hash_v = hash_function(x);
    list<int>::iterator i;
    for(i = table[hash_v].begin(); i != table[hash_v].end(); ++i) 
        if(*i == x) break;
    
    if(i != table[hash_v].end()) {
        table[hash_v].erase(i);
    }
}

hash_table::hash_table(int v) {
    this->bucket = v;
    table = new list<int>[bucket];
}

void hash_table::display() {
    for(int i = 0; i < bucket; ++i) {
        cout << i << ": ";
        for(auto x:table[i]) cout << "-> " << x << ' ';
        cout << endl;
    }
}


int main() {
    vector<int> a = {15, 11, 27, 8, 12};
    hash_table h(7);
    for(int i = 0; i < a.size(); ++i) {
        h.insert_item(a[i]);
    }
    h.delete_item(11);
    h.display();
}
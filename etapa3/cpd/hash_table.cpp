#include "hash_table.hpp"

using namespace std;

Hash::Node::Node(){
    key = -1;
    prev = NULL;
    next = NULL;
}

Hash::Node::Node(int key){
    this->key = key;
    prev = NULL;
    next = NULL;
}

Hash::LinkedList::LinkedList(){
    head = NULL;
}

bool Hash::LinkedList::isEmpty(){
    if (head == NULL)
        return true;
    else
        return false;
}

void Hash::LinkedList::insert(int key){
    if (!(this->isEmpty())){
        head->prev = new Node();
        Node *buffer = head;
        head = head->prev;
        head->next = buffer;
    }
    else {
        head = new Node();
    }
}

void Hash::LinkedList::remove(int key){
    if (!(this->isEmpty())){
        for (Node *it = head; it != NULL; it = it->next){
            if (it->key == key){
                if (it->next != NULL && it->prev != NULL){
                    it->next->prev = it->prev;
                    it->prev->next = it->next;
                }   
                else if (it->next != NULL){
                    it->next->prev = NULL;
                }
                else{
                    it->prev->next = NULL;
                }
                free(it);
            }
        }
    }
}

Hash::Hash_table::Hash_table(int size){
    this->size = size;
    for (vector<Hash::LinkedList>::iterator it = table.begin(); it != table.begin() + (size - 1); ++it)
        *it = LinkedList();
}

int Hash::Hash_table::h(int key){
    return key % (size - 1);
}

void Hash::Hash_table::insert(int key){
    LinkedList list = table[h(key)];
    list.insert(key);
}

void Hash::Hash_table::remove(int key){
    LinkedList list = table[h(key)];
    list.remove(key);
}

Hash::Node Hash::Hash_table::search(int key){
    LinkedList list = table[h(key)];
    return list.search(key);
}

Hash::Node Hash::LinkedList::search(int key){
    if (!(this->isEmpty())){
        for (Node *it = head; it != NULL; it = it->next){
            if (it->key == key){
                return *it;
            }
        }
    }
    return Node();
}

Hash::Node* Hash::LinkedList::begin(){
    return head;
}

void Hash::Hash_table::print(){
    for (vector<Hash::LinkedList>::iterator it = table.begin(); it != table.end() ; it ++){
        for (Node *it2 = it->begin(); it2 != NULL; it2 = it2->next){
            cout << it2->key << " ";
        }   
        cout << endl;
    }
}
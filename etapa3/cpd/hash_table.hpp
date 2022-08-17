#include <iostream>
#include <vector>

using namespace std;

namespace Hash{

    class Data{

    };

    class Node{
        public:
            Node();
            Node(int key);
            int key;
            Data data;
            Node *prev, *next;

    };
    
    class LinkedList{
        private:
            Node *head;
        public:
            LinkedList();
            void insert(int key);
            Node search(int key);
            void remove(int key);
            Node* begin();
            bool isEmpty();

    };

    class Hash_table{
        private:
            int size;
            vector<LinkedList> table;
            int h(int key);
        
        public:
            Hash_table(int size);
            void insert(int key);
            Node search(int key);
            void remove(int key);
            void print();
    };
}


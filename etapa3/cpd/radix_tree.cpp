#include <iostream>
#include <vector>
#include <string>

namespace rtr{
    class Node{
    public:
        std::string data;
        std::vector<Node*> children;
        Node(){this->children.assign(256,NULL);}
        Node(std::string str){
            this->children.assign(256,NULL);
            this->data=str;
        }
    };

    class RadixTree{
    private:
        std::vector<Node*> root;
        void recursive_insertion(Node *node, std::string::iterator b1, std::string::iterator e1, std::string::iterator b2, std::string::iterator e2){
            while (*b1 == *b2 && b1 != e1 && b2 != e2){
                b1++;b2++;
            }
            if (*b1 == *b2){
                if (b1 != e1 && b2 != e2){
                    return;
                }
                else if (b1 != e2){
                    node = node->children[*b1];
                }
                else{
                    
                }
            }
        }
        
    public:
        RadixTree(){root.assign(256, NULL);}
        void insert(std::string str){
            auto it = str.begin();
            Node* node = root[*it];
            if (node != NULL){
                recursive_insertion(node, str.begin(), str.end(), node->data.begin(), node->data.end());
            }
            else {

            }
        }
    };
}
/*

auto it2 = node->data.begin();
                while (*it == *it2 && it != str.end() && it2 != node->data.end()){
                    it++;it2++;
                }
                if (*it == *it2){
                    if (it != str.end() && it2 != node->data.end()){
                        return;
                    }
                    else if (it != str.end()){
                        node = node->children[*it];
                    }
                    else{
                        
                    }
                }
                else {
                    if (it != str.end())
                        node->children[*it] = new Node(std::string(it, str.end()));
                    if (it2 != node->data.end())
                        node->children[*it] = new Node(std::string(it2, node->data.end()));
                }
*/
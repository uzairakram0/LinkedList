#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main(){
    //Declarations
    LinkedList<int> lst;
    Node<int> * tail = lst.preheadPtr;

    //insertions
    for (int i = 1; i < 10; i++) {
        lst.insert(i, tail);
        tail = tail->next;
    }

    //removals
    lst.remove(lst.preheadPtr);
    cout << lst << endl;

    Node<int> * node = lst.preheadPtr->next;
    for(int i = 0; i < 2; i++) node = node->next;

    lst.remove(node);
    lst.remove(node);
    cout << lst << endl;
    lst.insert(75, node);
    lst.insert(43, lst.preheadPtr);

    //prints from any particular node
    cout << lst << endl;

    node = lst.search(43);

    cout << "\nsearch node: " << "[" << node->data << "]->\n" << endl;

}
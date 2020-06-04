#include <string>
#include <climits>
#include "Node.hpp"

//////////////////////////////////////////////////////////////////////////////
/***************************** Class Definition *****************************/
template<typename T>
class LinkedList{
    public:
    /* public data */
    Node<T> * preheadPtr;  //starting node before head node

    /* Constructors / Destructors */
    LinkedList();            //Constructor
    ~LinkedList() = default; //default destructors

    /* public methods/atributes */
    void insert(T data, Node<T> * prenodePtr); //insert node after prenodePtr with data
    void remove(Node<T> * prenodePtr);         //remove node after prenodePtr
    Node<T> * search(T data);                  //returns first match node given data

    /* converts the object to string */
    std::string const toString() const;
    
    template <typename printableT>      //overlaoding the outstream
    friend std::ostream& operator<<(std::ostream& out, LinkedList<T> const & lst);

};//End class LinkedList
//////////////////////////////////////////////////////////////////////////////
/***************************** Class Definition *****************************/



/**************************** Constructors ****************************/

/* Constructor with new list initiazizing the preheadPtr */
template <typename T>
LinkedList<T>::LinkedList(){
    preheadPtr = new Node<T>(std::numeric_limits<int>::min());
}//End Constructor

/**************************** Mutators ****************************/

//insert-------------------------------------------------------
template <typename T>
void LinkedList<T>::insert(T data, Node<T> * prenodePtr) {
    Node<T> * newNode = new Node<T>(data);
    newNode->next = prenodePtr->next;
    prenodePtr->next = newNode;
}//End insert()

//remove-------------------------------------------------------
template <typename T>
void LinkedList<T>::remove(Node<T> * prenodePtr) {
    Node<T> * deletion_node = prenodePtr->next;
    prenodePtr->next = deletion_node->next;
    deletion_node->next = NULL;
}//End remove()

/**************************** Attributes ****************************/

//search-------------------------------------------------------
template <typename T>
Node<T> * LinkedList<T>::search(T data){
    Node<T> * node = preheadPtr->next;
    while(node->data != data){
        if(node->next != NULL){
            node = node->next;
        } else {
            return preheadPtr;
        }
    }
    return node;
}//End search()

/**************************** Printing ****************************/

//toString-------------------------------------------------------
template <typename T>
std::string const LinkedList<T>::toString () const {
    std::string rtn;
    Node<T> * trav = this->preheadPtr->next;
    while(trav != NULL) {
            rtn += std::to_string(trav->data) + " -> ";
            trav = trav->next; 
    }
    return rtn;
}//End toString()

/**************************** Operator overloading ****************************/

//overload<<-------------------------------------------------------
template <typename T>
std::ostream& operator<<(std::ostream& out, LinkedList<T> const & lst) {
    out << lst.toString();
    return out;
}//End operator<<() overload






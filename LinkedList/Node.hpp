/**************************** Class Deffinition ****************************/
//////////////////////////////////////////////////////////////////////////////
template<typename T>
class Node{
    public:
        /* Public members */
        T data;         //data of node
        Node * next;    //pointer to the next node
        /* Constructors / Destructors */
        Node() = delete;    //block default construtor
        Node(T newData);    //creates new node with data field
        Node(T newData, Node * pt);     //creates new node with data and next pointer
        Node(Node const & copy);        //copy constuctor coppies node
        ~Node() = default;      //default destructor
        /* public methods/attributes */
        Node & operator=(Node const & assign);  //Overloading the assignment operator
};//End class Node
//////////////////////////////////////////////////////////////////////////////
/**************************** Class Deffinition ****************************/

/**************************** Constructors ****************************/

//Constructor1-------------------------------------------------------
template <typename T>
Node<T>::Node(T newData){
    data = newData;
    next = NULL;
} //End Constructor

//Constructor2-------------------------------------------------------
template <typename T>
Node<T>::Node(T newData, Node<T> * pt){
    data = newData;
    next = pt;
} //End Constructor

//Constructor3-------------------------------------------------------
template <typename T>
Node<T>::Node(Node const& copy){
    Node n(copy.data, copy.next);
}//End copy constructor

/**************************** Operator overloading ****************************/

//overload=-------------------------------------------------------
template <typename T>
Node<T> & Node<T>::operator=(Node<T> const & assign){
    this->data = assign.data;
    this->next = assign.next;
    return *this;
}//End operator=() overload
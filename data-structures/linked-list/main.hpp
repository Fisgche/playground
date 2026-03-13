
#define type_value int

class Node{
public:
    type_value value;
    Node* next; 
    Node();
    Node(type_value);

};

class List{
public:
     Node* firstNode; 
     int size;     
     List();
     void Add(Node*);
     Node Get(int index);
     bool Remove(int index);
     void Print();
     void PrintNode(Node node);
};


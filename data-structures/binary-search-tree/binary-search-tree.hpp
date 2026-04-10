#define tpye_value int

class Node{
    public:
        Node(tpye_value x);
        Node *Left;
        Node *Right;
        tpye_value Value;
};

class Tree{
    public:
        Node* Root;
        Tree(tpye_value x);
        void Insert(tpye_value x);
        void PrintInOrder(Node* node);
        void Print();

};


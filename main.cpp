#include <iostream>
using namespace std;


template <class T> struct Node {
  T value;
  Node<T> *next;
  Node<T> *previous;

};

template <class t> 
class Dlinklist {
    
public: //for debugging keep public 
  int count;
  Node<t> *head;
  Node<t> *tail;
  Node<t> *current;
  Node<t> *follow;

  Dlinklist();
//   ~Dlinklist();
  Dlinklist(t item);

  Node<t> *firstNode() const;
  Node<t> *lastNode() const;
  Node<t> *findNode(int pos) const;
  Node<t> *findItem(t val) const;
  void pop();
  void destroyNode(t &item);
  void destroylist();
  bool isEmpty() const;
  void insert(t val, int pos);
  int size() const;
  void print();

};

template <class t>
Dlinklist <t>::Dlinklist(){
    count = 0;
   head = NULL;
   tail = NULL;
   current = NULL;
   follow = NULL;
} 

// ~Dlinklist(){} will write destructor later

template <class t>
Dlinklist <t>::Dlinklist(t val){
    Node <t> *n = new Node <t>;
    n->value = val;
    head = n;
    tail = head;
    count++;
}

int main() {
  
}
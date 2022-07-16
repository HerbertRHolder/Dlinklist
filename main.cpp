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
  Node<t> *findNode(t val) const;
  Node<t> *getNode(int pos) const;
  t getValue(int pos) const;
  void setvalue(int pos, t val);
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

template <class t>
Dlinklist <t>::Node<t> *firstNode() { return head; }
template <class t>
Dlinklist <t>::Node<t> *lastNode() { return tail; }

template <class t>
Dlinklist <t>::Node<t> *findNode(t val) {
    Node<t> *tmp = head;
    while (tmp != NULL) {
      if (tmp->value == val) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return NULL;
  } // end of find node

template <class t>
  Dlinklist <t>::Node<t> *getNode(int pos) {
    if (pos < 0 || head == NULL) {
      return NULL;
    }
    int i = 0;
    Node<t> *tmp = head;
    while (tmp->next != NULL && i < pos) {
      tmp = tmp->next;
      i++;
    }
    return tmp;
  } // end of getNode

  template <class t>
   Dlinklist <t>::t getValue(int pos) {
    Node<t> *node = getNode(pos);
    if (node != NULL) {
      return node->value;
    } else {
      cout << "Value does not exist" << endl;
    }

  } // end getvalue

  // Sets the value given the position
  template <class t>
    void setvalue(int pos, t val) {
    Node<t> *node = getNode(pos);
    if (node != NULL) {
      node->value = val;
    } else {
      cout << "position does not exist" << endl;
    }
  } // end of setvalue()

int main() {
  
}
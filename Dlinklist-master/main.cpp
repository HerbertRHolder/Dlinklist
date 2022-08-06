#include <iostream>
using namespace std;


template <class T> struct Node {
  T value;
  Node<T> *next;
  Node<T> *previous;

};

template <class T> 
class Dlinklist {
    
public: //for debugging keep public 
  int count;
  Node<T> *head;
  Node<T> *tail;
  Node<T> *current;
  Node<T> *follow;

  // Dlinklist();
//   ~Dlinklist();
  // Dlinklist(T item);

  Node<T> *firstNode() const;
  Node<T> *lastNode() const;
  Node<T> *findNode(T val) const;
  Node<T> *getNode(int pos) const;
  T getValue(int pos) const;
  // void setvalue(int pos, T val);
  // void pop();
  // void destroyNode(T &item);
  // void destroylist();
  // bool isEmpty() const;
  // void insert(T val, int pos);
  // int size() const;
  // void print();

// ++++++++++++++++++++++++++++++++++++++++++++++++++
 
Dlinklist(){
    count = 0;
   head = NULL;
   tail = NULL;
   current = head;
   follow = NULL;
}
Dlinklist(T val){
    Node <T> *n = new Node <T>;
    n->value = val;
    head = n;
    tail = head;
    count++;
}

Node<T> *firstNode() { return head; }
Node<T> *lastNode() { return tail; }
Node<T> *findNode(T val) {
    Node<T> *tmp = head;
    while (tmp != NULL) {
      if (tmp->value == val) {
        return tmp;
      }
      tmp = tmp->next;
    }
    return NULL;
  } // end of find node
Node<T> *getNode(int pos) {
    if (pos < 0 || head == NULL) {
      return NULL;
    }
    int i = 0;
    Node<T> *tmp = head;
    while (tmp->next != NULL && i < pos) {
      tmp = tmp->next;
      i++;
    }
    return tmp;
  } // end of getNode
T getValue(int pos) {
    Node<T> *node = getNode(pos);
    if (node != NULL) {
      return node->value;
    } else {
      cout << "Value does not exist" << endl;
    }

  } // end getvalue

 void setvalue(int pos, T val) {
    Node<T> *node = getNode(pos);
    if (node != NULL) {
      node->value = val;
    } else {
      cout << "position does not exist" << endl;
    }
  } // end of setvalue()



}; //end of class Dlinklist




// ~Dlinklist(){} will write destructor later





  // Sets the value given the position
   
int main() {
  
}
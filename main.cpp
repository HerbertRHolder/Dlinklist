#include <iostream>
using namespace std;

// ADT Abstract Datatype
template <class T> struct Node {
  T value;
  Node<T> *next;
  Node<T> *previous;
};
// ADT Abstract Datatype
template <class T> class Dlinklist {

public: // for debugging keep public
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
  void setvalue(int pos, T val) const;
  // void pop();
  // void destroyNode(T &item);
  // void destroylist();
  // bool isEmpty() const;
  // void insert(T val, int pos);
  // int size() const;
  // void print();

  // ++++++++++++++++++++++++++++++++++++++++++++++++++
  // constructor
  Dlinklist() {
    // Count integer will give you the length of the list
    count = 0;
    head = NULL;
    tail = NULL;
    current = head;
    follow = NULL;
  }

  // Overload constructor: Declare value upon contruction of the instant
  Dlinklist(T val) {
    Node<T> *n = new Node<T>;
    n->value = val;
    head = n;
    tail = head;
    count++;
  }
  bool isEmpty() const { return (head == NULL); }

  int size() const {
    int count = 0;
    Node<T> *tmp = head;
    while (tmp != NULL) {
      count++;
      tmp = tmp->next;
    }
    return count;
  } // size function end

  Node<T> *firstNode() { return head; }
  Node<T> *lastNode() { return tail; }
  // Returns a Node in the list with the value (val) NOT the value itself!
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

  // pos(argument) is the position of the list
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

  // Think of all of the posible base cases that the user can choose
  // Need to account for
  // empty list
  // inserted a negative number for pos
  // if the user chooses the first node or pos = 1
  // if the user chooses the last node or getNode(pos)->next == tail->next;
  Node<T> *insert(int pos, T val) {
    if (pos < 0) {
      cout << "Incorrect Number" << endl;
    }

    Node<T> *n = new Node<T>;
    n->value = val;

    if (getNode(pos)->next == tail->next) {
      n->next = NULL;
      n->previous = tail = n;
      return tail;
    } else if (head == NULL) {
      n->next = head;
      n->previous = NULL;
      head = n;
    } else {
      current = getNode(pos);
      follow = getNode(pos - 1);
      n->next = current;
      current->previous = n;
      follow->next = n;
      n->previous = follow;
    }

    return n;

  } // end of insert

  // delete the end Node
  Node<T> *pop() {
    Node<T> *tmp = tail;
    if (isEmpty()) {
      cout << "list is empty";
    } else {
      tmp = tail->previous;
      tmp->next = NULL;
      delete tail;
      tail = tmp;
    }
    return tail;
  } // end of pop()

}; // end of class Dlinklist

// ~Dlinklist(){} will write destructor later

// Sets the value given the position

int main() {
  string wrd = "hello";

  Dlinklist<string> word(wrd);
}
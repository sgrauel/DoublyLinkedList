#include <iostream>
#include "doublyLinkedListErrors.h"

template <class T>
class Node {
private:
  T cargo;
  Node<T>* prev;
  Node<T>* next;
  template <class A> friend class LinkedList;
};

template <class A>
class LinkedList {
public:
  
  LinkedList();
  ~LinkedList();
  
  bool isEmpty() const;
  
  // functions for the front of the list
  void addFront(const A & elem);
  const A & peakFront() const;
  void removeFront();
  
  // functions for the back of the list
  void addBack(const A & elem);
  const A & peakBack() const;
  void removeBack();

  // print all elements in list
  void printAll();

  // get size
  int size();

  // find the middle node
  const A findMiddle();  

private:
  void add(const A & elem, Node<A>* target);
  void remove(Node<A>* target);

protected:
  Node<A>* header;
  Node<A>* trailer;
};


template <typename A>
LinkedList<A>::LinkedList() {
  header = new Node<A>;
  trailer = new Node<A>;
  header->next = trailer;
  header->prev = NULL;
  trailer->prev = header;
  trailer->next = NULL;
}

template <typename A>
LinkedList<A>::~LinkedList() {
  while (!isEmpty()) {
    removeFront();
  }
  delete header;
  delete trailer;
}

template <typename A>
bool LinkedList<A>::isEmpty() const {
  return (header->next == trailer); 
}

// functions on the front of the list
template <typename A>
void LinkedList<A>::addFront(const A & elem) {
  add(elem,header->next);
}

template <typename A>
const A & LinkedList<A>::peakFront() const {
  if (!isEmpty()) return header->next->cargo;
  else throw InvalidAccess("Cannot peak at the front of an empty deque.");
  exit(EXIT_FAILURE);
}

template <typename A>
void LinkedList<A>::removeFront() {
  if (!isEmpty()) {
    remove(header->next);
  } else {
    throw DequeUnderflow("You cannot remove from the front of an empty deque.");
    exit(EXIT_FAILURE);
  }
}


// functions on the back of the list
template <typename A>
void LinkedList<A>::addBack(const A & elem) {
  add(elem,trailer);
}

template <typename A>
const A & LinkedList<A>::peakBack() const {
  if (!isEmpty()) return (trailer->prev->cargo);
  else throw InvalidAccess("Cannot peak at the back of an empty deque");
  exit(EXIT_FAILURE);
}

template <typename A>
void LinkedList<A>::removeBack() {
  if (!isEmpty()) {
    remove(trailer->prev);
  } else {
    throw DequeUnderflow("You cannot remove from the back of an empty deque.");
    exit(EXIT_FAILURE);
  }
}

template <typename A>
void LinkedList<A>::printAll() {
  if (!isEmpty()) {
    Node<A>* trav = header->next;
    while (trav != trailer) {
      cout << trav->cargo << endl;
      trav = trav->next;
    }
  } else {
    throw PrintingError("Cannot print an empty deque.");
    exit(EXIT_FAILURE);
  }
}

template <typename A>
int LinkedList<A>::size() {
  if (!isEmpty()) {
    Node<A>* trav = header->next;
    int size = 0;
    while (trav != trailer) {
      size++;
      trav = trav->next;
    }
    return size;
  }
  else return 0;
}

/*
R-3.10 : What is the runtime of this function?
  answer: (3/2)*N e O(N) because of dependence on the size function
*/

template <typename A>
const A LinkedList<A>::findMiddle() {
  
  if (!isEmpty()) {

    int mid = size() / 2;
    Node<A>* trav = header->next;
    int i = 0;
  
    while (i != mid) {
    
      trav = trav->next;
      i++;
    }
  
    return trav->cargo;

  } else {
    throw InvalidAccess("Cannot find the middle of an empty deque.");
    exit(EXIT_FAILURE);
  }
}





// private members
template <typename A>
void LinkedList<A>::remove(Node<A>* target) {
  Node<A>* pred = target->prev;
  Node<A>* succ = target->next;
  pred->next = succ;
  succ->prev = pred;
  delete target;
}

template <typename A>
void LinkedList<A>::add(const A & elem, Node<A>* target) {
  
  // loading cargo
  Node<A>* newNode = new Node<A>;
  newNode->cargo = elem;
  
  // setting pointers for new node
  newNode->prev = target->prev;
  newNode->next = target;
  
  // setting pointers for successor and predecessor 
  // nodes relative to new node
  target->prev = target->prev->next = newNode;

}

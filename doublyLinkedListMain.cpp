#include <cstdlib>
#include <assert.h>
#include "doublyLinkedList.h"

using namespace std;

int main() {

  LinkedList<string> xs;
  
  string str1 = "New York";
  string str2 = "Chicago";
  string str3 = "Miami";
  string str4 = "Boston";
  
  xs.addFront(str1);
  xs.addFront(str2);
  xs.addFront(str3);
  xs.addFront(str4);
  
  xs.printAll();

  cout << xs.size() << endl;
  assert(xs.isEmpty() == false);

  cout << endl;
  cout << xs.findMiddle() << endl;
  
  
  /*
  xs.removeFront();
  xs.removeBack();
  
  cout << endl;

  xs.printAll();
  
  cout << xs.size() << endl;

  cout << endl;
  
  xs.removeFront();
  xs.removeFront();
  
  cout << xs.size() << endl;
  */
  
  return 0;
}

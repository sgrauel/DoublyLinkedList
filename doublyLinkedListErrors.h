#include <stdexcept>

using namespace std;

class DequeUnderflow : public underflow_error {
public:
  DequeUnderflow(const string & message = ""): underflow_error("Underflow Error: " + message) {};
};

class InvalidAccess : public range_error {
public:
  InvalidAccess(const string & message = ""): range_error("Range Error: " + message) {};
};

class PrintingError : public runtime_error {
public:
  PrintingError(const string & message = ""): runtime_error("Printing error: " + message) {};
};



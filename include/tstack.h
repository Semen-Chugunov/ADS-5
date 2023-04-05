// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size = 0>
class TStack {
 private:
    T arr[size] = {0};
    int h;

 public:
    TStack() {
        h = -1;
    }
    void push(const T& value) {
      if (!isfull())
        arr[++h] = value;
      else
        throw std::string("error");
    }
    bool isfull() {
        return h == size;
    }
    T get() const {
      return arr[h];
    }
    T pop() {
      return arr[h--];
    }
    bool isempty() const {
        return h == -1;
    }
    int GetTop() const {
        return h;
    }
};

#endif  // INCLUDE_TSTACK_H_

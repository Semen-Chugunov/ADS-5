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
    }
    bool isfull() {
        return h == size - 1;
    }
    const T& pop() {
        if (isempty()) {
            throw std::string("empty");
        } else {
            return arr[h--];
        }
    }
    bool isempty() const {
        return h == -1;
    }
    int GetTop() const {
        return arr[h];
    }
};

#endif  // INCLUDE_TSTACK_H_

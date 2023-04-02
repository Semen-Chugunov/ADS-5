// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>

 private:
    T* arr;
    int h;

 public:
    TStack() {
        h = -1;
    }
    void Push(const T& value) {
      if (!isfull())
        arr[++h] = value;
      else
        throw std::string("error")
    }
    bool isfull() {
        return h == size - 1;
    }
    T get() {
      return arr[h];
    }
    T pop() {
      return arr[h--];
    }
    bool isempty() const {
        return top == -1;
    }
    int GetTop() const {
        return top; 
    }

};
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

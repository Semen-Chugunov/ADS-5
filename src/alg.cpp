// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int top(char c) {
    if (c == '*' || c == '/') {
        return 3;
    if (c == '+' || c == '-')
        return 2;
    if (c == ')')
        return 1;
    if (c == '(')
        return 0;
    } else {
        return -1;
    }
}
std::string infx2pstfx(std::string inf) {
    TStack<char, 100> stk;
    std::string res;
    int k = 0;
    for (char c : inf) {
        bool fl = 1;
        if (top(c) == -1) {
            res += c;
            res += ' ';
            fl = 0;
        }
        if (top(c) == 0) {
            stk.push(c);
            fl = 0;
        }
        if (top(c) > top(stk.get())) {
            stk.push(c);
            fl = 0;
        }
        if (stk.isempty() && top(c) != -1) {
            stk.push(c);
            fl = 0;
        }
        if (fl && c != ')') {
            while (top(stk.get()) >= top(c)) {
                res += stk.pop();
                res += ' ';
            }
            stk.push(c);
        }
        if (c == ')') {
            while (stk.get() != '(') {
                res += stk.pop();
                res += ' ';
            }
            stk.pop();
        }
        if (k == inf.size() - 1) {
            while (!stk.isempty()) {
                res += stk.pop();
                if (stk.GetTop() != -1)
                    res += ' ';
            }
        }
        ++k;
    }
    return res;
}

int eval(std::string pref) {
  TStack<int, 100> stk1;
    for (char c : pref) {
        if (c == ' ') {
            continue;
        }
        if (c == '+') {
            int tmp = stk1.pop();
            tmp += stk1.pop();
            stk1.push(tmp);
        }
        if (c == '-') {
            int tmp = stk1.pop();
            tmp = stk1.pop() - tmp;
            stk1.push(tmp);
        }
        if (c == '*') {
            int tmp = stk1.pop();
            tmp *= stk1.pop();
            stk1.push(tmp);
        }
        if (c == '/') {
            int tmp = stk1.pop();
            tmp = stk1.pop() / tmp;
            stk1.push(tmp);
        }
        if ((c - '0') > 0) {
            int t = c - '0';
            stk1.push(t);
        }
    }
    return stk1.get();
}

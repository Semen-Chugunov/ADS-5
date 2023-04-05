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
    int l = 0;
    for (char k : inf) {
        bool fl = 1;
        if (top(k) == -1) {
            res += k;
            res += ' ';
            fl = 0;
        }
        if (top(k) == 0) {
            stk.push(k);
            fl = 0;
        }
        if (top(k) > top(stk.get())) {
            stk.push(k);
            fl = 0;
        }
        if (stk.isempty() && top(k) != -1) {
            stk.push(k);
            fl = 0;
        }
        if (fl && k != ')') {
            while (top(stk.get()) >= top(k)) {
                res += stk.pop();
                res += ' ';
            }
            stk.push(k);
        }
        if (k == ')') {
            while (stk.get() != '(') {
                res += stk.pop();
                res += ' ';
            }
            stk.pop();
        }
        if (l == inf.size() - 1) {
            while (!stk.isempty()) {
                res += stk.pop();
                if (stk.GetTop() != -1)
                    res += ' ';
            }
        }
        ++l;
    }
    return res;
}

int eval(std::string pref) {
  TStack<int, 100> stk1;
    for (char k : pref) {
        if (k == ' ') {
            continue;
        }
        if (k == '+') {
            int tmp = stk1.pop();
            tmp += stk1.pop();
            stk1.push(tmp);
        }
        if (k == '-') {
            int tmp = stk1.pop();
            tmp = stk1.pop() - tmp;
            stk1.push(tmp);
        }
        if (k == '*') {
            int tmp = stk1.pop();
            tmp *= stk1.pop();
            stk1.push(tmp);
        }
        if (k == '/') {
            int tmp = stk1.pop();
            tmp = stk1.pop() / tmp;
            stk1.push(tmp);
        }
        if ((k - '0') > 0) {
            int t = k - '0';
            stk1.push(t);
        }
    }
    return stk1.get();
}

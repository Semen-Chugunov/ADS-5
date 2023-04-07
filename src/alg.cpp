// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int fi(char a) {
    return a - '0';
}
int top(char str) {
    if (str == '+' || str == '-') {
        return 1;
    } else if (str == '*' || str == '/') {
        return 2;
    } else {
        return 0;
    }
}
std::string infx2pstfx(std::string inf) {
    std::string res = "";
    int fl = 0;
    TStack<char, 50> stk;
    for (int i = 0; i < inf.length(); i++) {
        if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' || inf[i] == '/') {
            if (fl == 1) {
                stk.push(inf[i]);
            } else if (fl != 1 && stk.isempty()) {
                stk.push(inf[i]);
            } else if (fl != 1 && !stk.isempty()) {
                if (top(inf[i]) <= top(stk.GetTop())) {
                    while (top(inf[i]) <= top(stk.GetTop())) {
                        res += stk.pop();
                        res += ' ';
                    }
                    stk.push(inf[i]);
                } else {
                    stk.push(inf[i]);
                }
            }
        } else if (inf[i] == '(') {
            fl = 1;
        } else if (inf[i] == ')' && fl == 1) {
            res += stk.pop();
            res += ' ';
            fl = 0;
        } else {
            res += inf[i];
            res += ' ';
        }
}
while (!stk.isempty()) {
    res += stk.pop();
    res += ' ';
}
res.pop_back();
return res;
}

int eval(std::string pref) {
    TStack<int, 50> stk;
    for (int i = 0; i < pref.length(); i++) {
        if (pref[i] == ' ') {
            continue;
        } else if (pref[i] == '*') {
            int s1 = stk.pop();
            int s2 = stk.pop();
            stk.push(s1 * s2);
        } else if (pref[i] == '/') {
            int s1 = stk.pop();
            int s2 = stk.pop();
            stk.push(s2 / s1);
        } else if (pref[i] == '+') {
            int s1 = stk.pop();
            int s2 = stk.pop();
            stk.push(s1 + s2);
        } else if (pref[i] == '-') {
            int s1 = stk.pop();
            int s2 = stk.pop();
            stk.push(s2 - s1);
        } else {
            stk.push(fi(pref[i]));
        }
    }
    return stk.pop();
}

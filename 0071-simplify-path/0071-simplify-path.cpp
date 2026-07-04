#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string solve(string path, stack<string> st) {
        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            string temp = "";
            while (i < path.size() && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == ".")
                continue;
            else if (temp == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(temp);
            }
            i++;
        }
        string res = "";
        // stack<string>st1;
        // while(!st.empty()) {
        //       st1.push(st.top());
        //       st.pop();
        // }
        while (!st.empty()) {
            res = "/" + st.top()+res;
            st.pop();
        }
        if (res.size() == 0) {
            return "/";
        }
        // reverse(res.begin(),res.end());
        return res;
    }
    string simplifyPath(string path) {
        // needs to defines the rules of strings
        stack<string> st;
        return solve(path, st);
    }
};
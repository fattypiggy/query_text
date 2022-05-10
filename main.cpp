#include <iostream>
#include <bits/stdc++.h>
#include "TextQuery.h"
using namespace std;

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}
int main() {
    ifstream file("input.txt"); // 文件应放在cmake-build-debug文件夹中，否则找不到
    runQueries(file);
    return 0;
}

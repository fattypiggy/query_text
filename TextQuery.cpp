//
// Created by William on 2022/5/10.
// 本程序为C++ Primer第12章：动态内存 最后实际项目
// 功能是读取input.txt文件，用户输入带查找词汇，若词汇在文件中出现过，则按升序输出出现的行号和当前行的内容。
// 本程序使用了shared_ptr。
//
#include <bits/stdc++.h>
#include "TextQuery.h"
using namespace std;
string make_plural(int n, string basic, string plural);
TextQuery::TextQuery(ifstream &is): file(new vector<string>) {
    string text;
    while(getline(is, text)) {
        file->push_back(text);
        const int n = file->size() - 1;
        string word;
        istringstream row(text);
        while (row >> word) {
            auto &line = mp[word]; // 这里必须使用引用
            if (!line)
                line.reset(new set<line_no>);
            line->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &s) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = mp.find(s);
    if (loc == mp.end())
        return QueryResult(s, file, nodata);
    else
        return QueryResult(s, file, loc->second);
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << endl;
    for (const auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ")"
            << *(qr.file->begin() + num) << endl;
    }
    return os;
}
string make_plural(int n, string basic, string plural) {
    if (n >= 2)
        return basic + plural;
    else
        return basic;
}
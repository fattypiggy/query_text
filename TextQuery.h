//
// Created by 经纬 on 2022/5/10.
//

#ifndef QUERY_TEXT_TEXTQUERY_H
#define QUERY_TEXT_TEXTQUERY_H

using namespace std;
class QueryResult;
class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &infile);
    QueryResult query(const string& s) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> mp;
};

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    using line_no = vector<string>::size_type;
    QueryResult(string s, shared_ptr<vector<string>> f, shared_ptr<set<line_no>> l): sought(s), file(f), lines(l) {}
private:
    string sought;
    shared_ptr<vector<string>> file;
    shared_ptr<set<line_no>> lines;
};
#endif //QUERY_TEXT_TEXTQUERY_H

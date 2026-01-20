class Solution {
  public:
  stack<char>s;
  string doc="";
    void append(char x) {
        // append x into document
        doc.push_back(x);
    }

    void undo() {
        // undo last change
        char ch=doc.back();
        doc.pop_back();
        s.push(ch);
    }

    void redo() {
        // redo changes
        char ch=s.top();
        s.pop();
        doc.push_back(ch);
    }

    string read() {
        // read the document
        return doc;
    }
};
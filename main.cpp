#include <iostream>
#include <cassert>

using namespace std;

class Trie {
 public:
  Trie() {
    //FIXME
  }

  void insert(string word) {
    //FIXME
  }

  bool search(string word) {
    //FIXME
    return false;
  }

  bool startsWith(string prefix) {
    //FIXME
    return false;
  }
};

void Test1() {
  Trie t;
  t.insert("apple");
  assert(t.search("apple"));
  assert(!t.search("app"));
  assert(t.startsWith("app"));
  t.insert("app");
  assert(t.search("app"));
}

int main() {
  Test1();
  cout << "Ok!"s << endl;

  return 0;
}

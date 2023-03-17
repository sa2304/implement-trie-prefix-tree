#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

class Trie {
  struct Node {
    unordered_map<char, Node*> children;
    bool is_word = false;

    Node* findChild(string_view& prefix) {
      Node* node = this;
      while (!prefix.empty() && node->children.count(prefix.front())) {
        node = node->children.at(prefix.front());
        prefix.remove_prefix(1);
      }
      return node;
    }
  };

  Node root_;

 public:
  Trie() {}

  void insert(string word) {
    string_view prefix{word};
    Node* node = root_.findChild(prefix);
    while (!prefix.empty()) {
      Node* child = new Node;
      node->children[prefix.front()] = child;
      prefix.remove_prefix(1);
      node = child;
    }
    node->is_word = true;
  }

  bool search(string word) {
    string_view prefix{word};
    Node* node = root_.findChild(prefix);
    return prefix.empty() && node->is_word;
  }

  bool startsWith(string prefix) {
    string_view p{prefix};
    Node* node = root_.findChild(p);
    return p.empty();
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

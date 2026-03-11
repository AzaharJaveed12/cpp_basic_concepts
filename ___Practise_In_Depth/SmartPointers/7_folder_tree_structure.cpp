/*

Scenario:
    Design a tree structure.

    Example:
        Root
        ├── Folder1
        │    └── File1
        └── Folder2
        Requirements

    Class:
        Node

    Each node should have:
        children
        parent


    Functions:
        addChild(...)
        getParent()
        printTree()
        Constraints

requirements:
    Tree must not create memory leaks
    Destroying root should destroy entire tree
*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std; // for ease of coding

class Node:  public enable_shared_from_this<Node> {
private:
    string name;
    vector<shared_ptr<Node>> children;
    weak_ptr<Node> parent;
public:
    Node(const string& name): name{name} {}

    shared_ptr<Node> addChild(const string& name) {
        shared_ptr<Node> child = make_shared<Node>(name);
        child->parent = shared_from_this();
        children.push_back(child);
        return child;
    }

    shared_ptr<Node> getParent() const {
        return parent.lock();
    }

    void printTree(int space = 0) {
        for(int i = 0; i <= space; i++) cout << " ";
        cout << name <<"\n";
        space+= 5;
        for(const auto& it: children) {
            it -> printTree(space);
            
        }
        space-= 5;
    }
};

int main() {
    shared_ptr<Node> root = make_shared<Node>("a");
    auto b = root->addChild("b");
    auto b1 = root ->addChild("b1");
    auto b2 =root->addChild("b2");
    b1 -> addChild("bc1");
    b1 -> addChild("bc2");
    b2 -> addChild("file.txt");
    root -> printTree();
    return 0;
}
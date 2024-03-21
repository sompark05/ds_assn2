#pragma once
#include <string>
#include <fstream>
using namespace std;

struct Node {
  Node(char input_value) : value(input_value), left(NULL), right(NULL) {}
  char value;
  Node *left;
  Node *right;
};

class BinaryTree {
public:
    BinaryTree() { _root = NULL; };
    Node* getRoot() {return _root;}

    ~BinaryTree() {
    delete[] _root;
    _root = NULL;
    };
    void buildFromString(const  char *data);

    int findHeightOfNode();
    int findLevelOfNode();

    string levelOrder();
    string printNodeAndChildren();

    string leafCount();
    string getWidth();

private:
    Node *_root;
    Node *_buildFromString(const char *data, int start, int end);
    /////////////////////////////////////////////////////////
    //////  TODO: Add Private members if required ///////////
    void _printNodeAndChildren();
    void _currentLevel();

    static const int MAX_DEPTH = 100;
    int levelCounts[MAX_DEPTH] = {0};

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
};
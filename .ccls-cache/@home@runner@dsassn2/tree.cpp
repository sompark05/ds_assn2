#include "tree.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/* This is given function. DO NOT MODIFY THIS FUNCTION */
int findIndex(const char *str, int start, int end) {
  if (start > end)
    return -1;

  string s;

  for (int i = start; i <= end; i++) {

    // if open parenthesis, push it
    if (str[i] == '(')
      s.push_back(str[i]);

    // if close parenthesis
    else if (str[i] == ')') {
      if (s.back() == '(') {
        s.pop_back();

        if (!s.length())
          return i;
      }
    }
  }
  // if not found return -1
  return -1;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
Node *BinaryTree::_buildFromString(const char *data, int start, int end) {

  if (start > end)
    return NULL;

  Node *root = new Node(data[start]);
  int index = -1;

  if (start + 1 <= end && data[start + 1] == '(')
    index = findIndex(data, start + 1, end);

  if (index != -1) {
    root->left = _buildFromString(data, start + 2, index - 1);
    root->right = _buildFromString(data, index + 2, end - 1);
  }
  return root;
}

/* This is given function. DO NOT MODIFY THIS FUNCTION */
void BinaryTree::buildFromString(const char *data) {
  Node *root = _buildFromString(data, 0, strlen(data) - 1);
  _root = root;
}

void BinaryTree::_printNodeAndChildren(string &list, Node *node) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (node == NULL) {
    return;
  }

  // add the value of the node to the list
  list += node->value;

  // check child nodes
  int count = 0;
  if (node->left != NULL) {
    count++;
  }
  if (node->right != NULL) {
    count++;
  }
  list += to_string(count);

  // if there is no child node, return
  if (count == 0) {
    return;
  }

  // if there is child node, call the function again (recurrsion)
  if (node->left != NULL) {
    _printNodeAndChildren(list, node->left);
  }
  if (node->right != NULL) {
    _printNodeAndChildren(list, node->right);
  }
  return;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::printNodeAndChildren() {
  string list = "";
  _printNodeAndChildren(list, _root);
  return list;
}

int BinaryTree::findHeightOfNode(Node *node, char nodeValue) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (node == NULL) {
    return 0;
  }
  if (node == _root) {
    Node *target = findNode(node, nodeValue);
    if (target == NULL) {
      return -1;
    }

    int left_height = findHeightOfNode(target->left, nodeValue);
    int right_height = findHeightOfNode(target->right, nodeValue);

    return max(left_height, right_height);
  }
  int left_height = findHeightOfNode(node->left, nodeValue);
  int right_height = findHeightOfNode(node->right, nodeValue);

  return 1 + max(left_height, right_height);
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

// method to find the node with the given value
Node *BinaryTree::findNode(Node *node, char nodeValue) {

  if (node == NULL) {
    return nullptr;
  }
  if (node->value == nodeValue) {
    return node;
  }

  Node *left_child = findNode(node->left, nodeValue);
  if (left_child != nullptr) {
    return left_child;
  }
  return findNode(node->right, nodeValue);
}

int BinaryTree::findLevelOfNode(Node *node, char nodeValue, int level) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (node == NULL) {
    return -1;
  }
  if (node->value == nodeValue) {
    return level;
  }

  int left = findLevelOfNode(node->left, nodeValue, level + 1);

  if (left != -1) {
    return left;
  }
  int right = findLevelOfNode(node->right, nodeValue + 1);
  return right;
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::levelOrder() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  string list = "";
  string result = "";
  int height = findHeightOfNode(_root, _root->value);

  for (int i = 0; i <= height; i++) {
    list += _currentLevel(_root, i);
  }

  for (int i = 0; i < list.size(); i++) {
    result += list.substr(i, 1) + " ";
  }

  return result;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::_currentLevel(Node *node, int height) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (node == NULL) {
    return "";
  }

  if (height == 0) {
    return string(1, node->value);
  } else {
    string left_result = _currentLevel(node->left, height - 1);
    string right_result = _currentLevel(node->right, height - 1);

    return left_result + right_result;
  }
  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

int BinaryTree::leafCount(Node *node) {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  if (node == NULL) {
    return 0;
  }
  if (node->left == NULL && node->right == NULL) {
    return 1;
  }
  int left_result = leafCount(node->left);
  int right_result = leafCount(node->right);
  return left_result + right_result;

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

string BinaryTree::getWidth() {
  /////////////////////////////////////////////////////////
  //////////  TODO: Implement From Here      //////////////
  int height = findHeightOfNode(_root, _root->value);
  int width = 0;
  for (int i = 1; i <= height; i++) {
    string current_width = _currentLevel(_root, i);
    if (current_width.size() > width) {
      width = current_width.size();
    }
  }
  return to_string(width);

  ///////////      End of Implementation      /////////////
  /////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////
//////////  You can implement any other functions ////////

///////////      End of Implementation      /////////////
/////////////////////////////////////////////////////////
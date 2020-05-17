// Copyright 2020 Isaev Ilya

#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
#include "include/rb_operation.h"

RBOperation* RBOperation::makeOperation(std::string op) {
    RBOperation* res = nullptr;
    if (op == "insert") {
        res = new InsertOperation;
    }
    if (op == "find") {
        res = new FindOperation;
    }
    if (op == "remove") {
        res = new RemoveOperation;
    }
    if (op == "getRoot") {
        res = new GetRootOperation;
    }
    if (res == nullptr)
        throw std::invalid_argument("Bad arguments!");
    return res;
}

int RBOperation::isNIL(Node* node) {
    return node->color == Color::black &&
        node->right == nullptr && node->left == nullptr;
}

std::string InsertOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
    tree->insert(new Node{arg[0]});
    return "";
}

std::string FindOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
        auto found = tree->find(arg[0]);
        std::stringstream stream;
        if (!isNIL(found)) {
            stream << "(" << arg[0] << " is found) ";
        } else {
            stream << "(" << arg[0] << " is not found) ";
        }
        return stream.str();
}

std::string RemoveOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
    std::string res;
    try {
        tree->remove(arg[0]);
        res = "";
    } catch(std::exception& ex) {
        res = "(" + std::string(ex.what()) + ")";
    }
    return res;
}

std::string GetRootOperation::operator()(RBTree* tree,
    const std::vector<int>& arg) {
    auto root = tree->getRoot();
    std::stringstream stream;
    if (!isNIL(root)) {
        stream << "(Root value: " << root->data << ")";
    } else {
        stream << "(Tree is empty)";
    }
    return stream.str();
}

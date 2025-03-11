/**
 * Реализуйте класс Tree бинарного дерева, используя интеллектуальные указатели для связи родителей и потомков.
 * Реализуйте структуру Node, содержащую указатели типа std::shared_ptr на правого и левого потомков, 
 * указатель типа std::weak_ptr на родителя и данные типа T. 
 * Продемонстрируйте отсутствие неразрушимых циклических связей и корректную работу деструкторов всех узлов 
 */
#pragma once
#include <iostream>
#include <memory>
#include <stdexcept>

namespace tree {

template <typename T>
class Tree {
private:

    struct Node {
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
        std::weak_ptr<Node> parent;

        Node(T data) : data(data), left(nullptr), right(nullptr) {}
        ~Node() {
            std::cout << "Dtor called. " << "Stored node data: " << data << std::endl;
        }
    };

public:

    Tree() : root(nullptr) {}

    void insert(T data) {
        auto newNode = std::make_shared<Node>(data);
        if (root) {
            insert(root, newNode);
        } else {
            root = newNode;
        }
    }

    void print() const {
        print(root);
    }

private:
    std::shared_ptr< Node > root;

    void insert(std::shared_ptr<Node> node, std::shared_ptr<Node> newNode) {
        if (newNode->data < node->data) {
            if (!node->left) {
                node->left = newNode;
                newNode->parent = node;
            } else {
                insert(node->left, newNode);
            }
        } else {
            if (!node->right) {
                node->right = newNode;
                newNode->parent = node;
            } else {
                insert(node->right, newNode);
            }
        }
    }

    void print(const std::shared_ptr<Node>& node) const {
        if (node) {
            print(node->left);
            std::cout << node->data << "\n";
            print(node->right);
        }
    }
};

}

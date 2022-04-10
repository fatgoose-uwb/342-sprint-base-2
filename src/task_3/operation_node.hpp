/*
 * DO NOT MAKE ANY CHANGES
 */
#pragma once

#include "node.hpp"

template<typename T>
class OperationNode : public Node<T> {
protected:
    std::vector<Node<T> *> nodes;

public:
    T evaluate() override = 0;

    OperationNode(const std::vector<Node<T> *> &nodes) : nodes(nodes) {};

    virtual ~OperationNode() override = default;
};

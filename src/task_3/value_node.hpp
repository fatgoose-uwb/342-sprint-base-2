/*
 * DO NOT MAKE ANY CHANGES
 */
#pragma once

#include "node.hpp"

template<typename T>
class ValueNode : public Node<T> {
private:
    T value;

public:
    T evaluate() override {
        return value;
    };

    ValueNode(const T &value) : value(value) {};

    ValueNode() : value(T()) {}

    void setValue(const T &value) {
        this->value = value;
    }
};

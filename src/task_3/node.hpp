/*
 * DO NOT MAKE ANY CHANGES
 */
#pragma once

template<typename T>
class Node {
public:
    virtual T evaluate() = 0;

    virtual ~Node() = default;
};

/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#include "operation_node.hpp"

template<typename T>
class MultiplicationNode : public OperationNode<T> {
public:
    T evaluate() override { // 6
        /*
         * TODO: return the value of multiplying (*) all nodes
         */
        return this->nodes[0]->evaluate();  // TODO: this is a placeholder. Replace it with your own code.
    };

    MultiplicationNode(const std::vector<Node<T> *> &nodes) : OperationNode<T>(nodes) {}

    virtual ~MultiplicationNode() { // 4
        /*
         * TODO: clean up nodes.
         */
    }
};

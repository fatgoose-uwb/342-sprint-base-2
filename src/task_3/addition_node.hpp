/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#include "operation_node.hpp"

template<typename T>
class AdditionNode : public OperationNode<T> {
public:
    T evaluate() override {
        /*
         * TODO: return the value of addition (+) all nodes
         */
        return this->nodes[0]->evaluate();  // TODO: this is a placeholder. Replace it with your own code.
    };

    AdditionNode(const std::vector<Node<T> *> &nodes) : OperationNode<T>(nodes) {}

    virtual ~AdditionNode() override {
        /*
         * TODO: clean up nodes.
         */
    }
};
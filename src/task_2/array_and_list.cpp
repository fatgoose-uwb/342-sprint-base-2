/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#include "array_and_list.h"

template<class T>
void ArrayList<T>::push_front(const T &value) {
    /*
     * TODO: insert the value at the front (index 0) of the list (stored in data array).
     *  If array is full, simply return.
     */
}

template<class T>
void ArrayList<T>::push_back(const T &value) {
    /*
     * TODO: insert the value at the tail of the data array.
     *  For example, if there's 4 (index 0 to 3) elements already, insert it at index 4.
     *  If array is full, simply return.
     *  This should be no more than 4 lines of code.
     */
}

template<class T>
void ArrayList<T>::pop_back() {
    /*
     * TODO: remove the last element in the list.
     *  No-op (no operation) if list is empty.
     */
}

template<class T>
void ArrayList<T>::pop_front() {
    /*
     * TODO: remove the first element in the list.
     *  The rest of the data needs to be move forward.
     *  For example, [0, 1, 2] would become [1, 2, ...]. Values after 2 don't matter for tests.
     *  No-op (no operation) if list is empty.
     */
}

template<class T>
void ArrayList<T>::remove(T &val) {
    /*
     * TODO: remove all elements that equal to the give value (OK to use "==" for equality check).
     *  Once an element is remove, the elements after it would be moved forward to fill in the space.
     *  For example: removing 8 from [0, 8, 2, 8, 4] would yield [0, 2, 4, ...]. Items after 4 don't matter for tests
     */
}

/*
 * merge in ascending order
 */
template<class T>
void ArrayList<T>::merge(const List<T> &other_list) {
    /*
     * TODO: Assuming the current list is sorted. Merge the given sorted list other_list into the current
     *  list as a new sorted list consisting of values from both lists.
     */
}
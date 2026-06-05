#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include "list_node.hpp"
#include "list_iterator.hpp"

#include <cassert>
#include <cstddef>  //ptrdiff_t
#include <iterator> //std::bidirectional_iterator_tag
#include <iostream>
#include <utility>

#include <initializer_list>

// forward declaration of template list class
template <typename T>
class List;

// forward declaration of free function "reverse"
template <typename T>
List<T> reverse(List<T> const& list_to_reverse);

template <typename T>
List<T> operator+(List<T> const& lhs, List<T> const& rhs);

template <typename T>
class List {
  public:

    //friend declarations for testing the members   
    template <typename TEST_TYPE>
    friend size_t get_size(List<TEST_TYPE> const& list_to_test);
    template <typename TEST_TYPE>
    friend ListNode<TEST_TYPE>* 
      get_first_pointer(List<TEST_TYPE> const& list_to_test);
    template <typename TEST_TYPE>
    friend ListNode<TEST_TYPE>* 
      get_last_pointer(List<TEST_TYPE> const& list_to_test);

    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = T const*;
    using reference       = T&;
    using const_reference = T const&;
    using iterator        = ListIterator<T>;

    /* Declaration of Default Constructor */
    List();
    
    /* Declaration of Copy Constructor using Deep-Copy Semantics */
    List(List const& rhs);

    /* Declaration of Move Constructor */
    List(List&& rhs);

    /* Declaration of Initializer-List-based Constructor */
    List(std::initializer_list<T> ini_list);

    /* Declaration of Destructor */
    ~List();

    /* Declaration of Unifying Assignment Operator - see: Vorlesung 10, pp. 11-13, watch video explanation!*/
    List& operator=(List rhs);

    /* Declaration of built-in Member-Swap method used by Unifying Assignment Operator */
    void swap(List& rhs);

    /* Declaration of list-comparison-operator in terms of equality */
    bool operator==(List const& rhs) const;

    /* Declaration of list-comparison-operator in terms of inequality */
    bool operator!=(List const& rhs) const;
    
    /* Declaration of size-Method */
    std::size_t size() const;

    /* Declaration of empty-Method */
    bool empty() const;

    /* Declaration of push_front-Method */
    void push_front(T const& element);

    /* Declaration of pop_front-Method */
    void pop_front();

    /* Declaration of push_front-Method */
    void push_back(T const& element);

    /* Declaration of push_front-Method */
    void pop_back();

    /* Declaration of emplace_front-Method */
    template <class... Args>
    void emplace_front(Args&&... args);

    /* Declaration of emplace_back-Method */
    template <class... Args>
    void emplace_back(Args&&... args);

    /* Declaration of front-Method */
    T& front();

    /* Declaration of back-Method */
    T& back();

    /* Declaration of clear-Method */
    void clear();

    /* Declaration of reverse-Method*/
    void reverse();

    /* Declaration of begin-Method returning a ListIterator refering to the first list_node */
    ListIterator<T> begin();
    /* Declaration of end-Method returning a ListIterator refering to the past-the-end-element which marks the end of the list*/
    ListIterator<T> end();

    /* Declaration of insert-Method */
    ListIterator<T> insert(ListIterator<T> const& position, T const& value);
    /* Declaration of emplace-Method */
    template <class... Args>
    ListIterator<T> emplace(ListIterator<T> const& position, Args&&... args);
    /* Declaration of erase-Method */
    ListIterator<T> erase(ListIterator<T> const& position);

  // list members
  private: 
    std::size_t size_;
    ListNode<T>* first_;
    ListNode<T>* last_;
};

/* ======================================== *
 * BEGIN COMMENTING AND IMPLEMENTATION HERE *
 * ======================================== */

 //=========================
// not fully implemented yet
/* Aufgabe 5.2 - Teil 1 */
/* ... */
template <typename T>
List<T>::List()
    : size_{ 0 },
    first_{ nullptr },
    last_{ nullptr }
{
}

//=========================
// test and implement
/* Aufgabe 5.2 - Teil 2 */
/* ... */
template <typename T>
std::size_t List<T>::size() const {
    //TODO: return value of member variable insteaf of 27
    return size_;
};

//=========================
// test and implement
/* Aufgabe 5.2 - Teil 3 */
/* ... */
template <typename T>
bool List<T>::empty() const {
    // check whether size member variable is zero -- this should be a one line implementation
    return size_ == 0;
};

//=========================
/* Aufgabe 5.3 - Teil 1 */
/* ... */
template <typename T>
void List<T>::push_front(T const& element) {

    auto* node = new ListNode<T>;
    node->value = element;

    if (empty()) {
        first_ = last_ = node;
    }
    else {
        node->next = first_;
        first_->prev = node;
        first_ = node;
    }

    ++size_;
}

//=========================
/* Aufgabe 5.3 - Teil 2 */
/* ... */
template <typename T>
void List<T>::pop_front() {
    if (empty()) {
        throw "List is empty";
    }
    ListNode<T>* old = first_;

    if (size_ == 1) {
        first_ = nullptr;
        last_ = nullptr;
    }
    else {
        first_ = first_->next;
        first_->prev = nullptr;
    }

    delete old;
    --size_;
    // TODO: remainder of pop_front-method (Aufgabe 5.3)
}

//=========================
/* Aufgabe 5.3 - Teil 3 */
/* ... */
template <typename T>
void List<T>::push_back(T const& element) {

    auto* node = new ListNode<T>;
    node->value = element;

    if (empty()) {
        first_ = last_ = node;
    }
    else {
        node->prev = last_;
        last_->next = node;
        last_ = node;
    }

    ++size_;
}

//=========================
/* Aufgabe 5.3 - Teil 4 */
/* ... */
template <typename T>
void List<T>::pop_back() {
    if (empty()) {
        throw "List is empty";
    }
    ListNode<T>* old = last_;

    if (size_ == 1) {
        first_ = nullptr;
        last_ = nullptr;
    }
    else {
        last_ = last_->prev;
        last_->next = nullptr;
    }

    delete old;
    --size_;
    // TODO: remainder of pop_back-method (Aufgabe 5.3)
}

//=========================
/* Aufgabe 5.3 - Teil 5 */
/* ... */
template <typename T>
template <class... Args>
void List<T>::emplace_back(Args&&... args)
{
    // TODO: emplace_back-method (Aufgabe 5.3)
}

//=========================
/* Aufgabe 5.3 - Teil 6 */
/* ... */
template <typename T>
template <class... Args>
void List<T>::emplace_front(Args&&... args)
{
    // TODO: emplace_front-method (Aufgabe 5.3)
}


//=========================
/* Aufgabe 5.3 - Teil 6 */
/* ... */
template <typename T>
T& List<T>::front() {
    if (empty()) {
        throw "List is empty";
    }
    return first_->value;
    // TODO: remainder of front-method (Aufgabe 5.3)
}

//=========================
/* Aufgabe 5.3 - Teil 8 */
/* ... */
template <typename T>
T& List<T>::back() {
    if (empty()) {
        throw "List is empty";
    }
    return last_->value;
    // TODO: remainder of back-method (Aufgabe 5.3)
}

//=========================
// test and implement:
// TODO: clear 
// Aufgabe 5.4 - Teil 1
/* ... */
template <typename T>
void List<T>::clear() {

    while (!empty()) {
        pop_front();
    }
}

//=========================
// test and implement:
// TODO: List Destructor implemented by calling clear
// Aufgabe 5.4 - Teil 2
/* ... */
template <typename T>
List<T>::~List() {
    clear();
    //TODO: Implement via clear-Method (Aufgabe 5.4)
} //can not be tested with unit tests

//=========================
// test and implement:
// TODO: Copy-Konstruktor using Deep-Copy semantics
// Aufgabe 5.5
/* ... */
template <typename T>
List<T>::List(List<T> const& rhs)
    : List()
{
    for (auto node = rhs.first_;
        node != nullptr;
        node = node->next)
    {
        push_back(node->value);
    }
}

//=========================
// test and implement:
// TODO: helper-swap-method for bultin-types used by unifying assignment operator (see Vorlesung 10, pp. 11-13)
// Aufgabe 5.6 - Teil 1
/* ... */
template <typename T>
void List<T>::swap(List<T>& rhs) {
    std::swap(size_, rhs.size_);
    std::swap(first_, rhs.first_);
    std::swap(last_, rhs.last_);
}

//=========================
// test and implement:
// TODO: unyfing assignment operator (see Vorlesung 10, pp. 11-13)
// Aufgabe 5.6 - Teil 2
/* ... */
template <typename T>
List<T>& List<T>::operator=(List<T> rhs) {
    swap(rhs);
    return *this;
}

//=========================
// Aufgabe 5.7 - Teil 1
/* ... */
template <typename T>
void List<T>::reverse() {

}

//=========================
// Aufgabe 5.7 - Teil 2
/* ... */
template <typename T>
List<T> reverse(List<T> const& list_to_reverse) {

}

//=========================
// Aufgabe 5.8 - Teil 1
/* ... */
template <typename T>
bool List<T>::operator==(List const& rhs) const {
    if (size_ != rhs.size_) {
        return false;
    }

    auto* lhs_node = first_;
    auto* rhs_node = rhs.first_;

    while (lhs_node != nullptr) {

        if (lhs_node->value != rhs_node->value) {
            return false;
        }

        lhs_node = lhs_node->next;
        rhs_node = rhs_node->next;
    }

    return true;
    //TODO: operator== (Aufgabe 5.8)
}

//=========================
// Aufgabe 5.8 - Teil 2
/* ... */
template <typename T>
bool List<T>::operator!=(List const& rhs) const {
    return !(*this == rhs);
    //TODO: operator!= (Aufgabe 5.8)
    // make use of operator== you implemented
}

//=========================
// Aufgabe 5.9 - Teil 1
/* ... */
template <typename T>
ListIterator<T> List<T>::begin() {
    //TODO: begin-Method returning an Iterator to the 
    //      first element in the List (Aufgabe 5.9)
    return ListIterator<T>(first_);
}

//=========================
// Aufgabe 5.9 - Teil 2
/* ... */
template <typename T>
ListIterator<T> List<T>::end() {
    //TODO: end-Method returning an Iterator to element after (!) 
    //      the last element in the List (Aufgabe 5.9)
    return ListIterator<T>(nullptr);
}

//=========================
// Aufgabe 5.11
/* ... */
template <typename T>
ListIterator<T> List<T>::insert(ListIterator<T> const& position, T const& value) {

}

template <typename T>
template <class... Args>
ListIterator<T> List<T>::emplace(ListIterator<T> const& position, Args&&... args)
{

}

//=========================
// Aufgabe 5.12
/* ... */
template <typename T>
ListIterator<T> List<T>::erase(ListIterator<T> const& position) {

}

//=========================
// Aufgabe 5.13 is a copy test and should be implemented in a cpp file

//=========================
// test and implement:
// TODO: Move-Konstruktor (Aufgabe 5.14)
/* ... */
template <typename T>
List<T>::List(List<T>&& rhs) {}

//=========================
// test and implement:
//TODO: Initializer - List Konstruktor (5.15 - Teil 1)
/* ...  */
template <typename T>
List<T>::List(std::initializer_list<T> ini_list) {
    //not implemented yet
}

//=========================
// Aufgabe 5.15 - Teil 2
/* ... */
template <typename T>
List<T> operator+(List<T> const& lhs, List<T> const& rhs) {

}


#endif // #ifndef BUW_LIST_HPP
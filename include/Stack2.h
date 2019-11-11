#pragma once

#include <iostream>
#include "Element.h"

template <typename T>
class Stack2
{
private:
    unsigned int size;
    Element<T> head_value;
public:
    Stack2();
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(T&& value);
    const T& head() const;
    T pop();
    ~Stack2() = default;
};

template <typename T>
Stack2<T>::Stack2() {
    this->size = 0;
}

template <typename T>
void Stack2<T>::push(T&& value) {
    Element<T> el(value, head_value);
    size++;
    this->head_value.reset(el);
}

template <typename T>
const T& Stack2<T>::head() const{
    return this->head_value.getValue();
}

template <typename T>
template <typename ... Args>
void Stack2<T>::push_emplace(Args&&... value) {
    T args [] = {value...};
    for(auto& e: args) {
        Element<T> el(e, head_value);
        size++;
        this->head_value.reset(el);
    }
}

template <typename T>
T Stack2<T>::pop() {
    T El = head_value.getValue();
    this->head_value.reset(head_value.getNext());
    size--;
    return El;
}

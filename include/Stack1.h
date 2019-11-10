#pragma once

#include <iostream>
#include "Element.h"


template <typename T>
class Stack
{
private:
    unsigned int size;
    Element<T> head_value;
public:
    Stack();
    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;
    ~Stack() = default;
};

template <typename T>
Stack<T>::Stack() {
    this->size = 0;
}

template <typename T>
void Stack<T>::push(T&& value) {
    Element<T> el(value, head_value);
    size++;
    this->head_value.reset(el);
}

template <typename T>
void Stack<T>::push(const T& value) {
    Element<T> el(value, head_value);
    size++;
    this->head_value.reset(el);
}

template <typename T>
void Stack<T>::pop() {
    this->head_value.reset(head_value.getNext());
    size--;
}

template <typename T>
const T& Stack<T>::head() const{
    return this->head_value.getValue();
}

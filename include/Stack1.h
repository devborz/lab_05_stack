#pragma once

#include <iostream>
#include "Element.h"


template <typename T>
class Stack1
{
private:
    unsigned int size;
    Element<T> head_value;
public:
    Stack1();
    void push(T&& value);
    void push(const T& value);
    void pop();
    const T& head() const;
    ~Stack1() = default;
};

template <typename T>
Stack1<T>::Stack1() {
    this->size = 0;
}

template <typename T>
void Stack1<T>::push(T&& value) {
    Element<T> el(value, head_value);
    size++;
    this->head_value.reset(el);
}

template <typename T>
void Stack1<T>::push(const T& value) {
    Element<T> el(value, head_value);
    size++;
    this->head_value.reset(el);
}

template <typename T>
void Stack1<T>::pop() {
    this->head_value.reset(head_value.getNext());
    size--;
}

template <typename T>
const T& Stack1<T>::head() const{
    return this->head_value.getValue();
}

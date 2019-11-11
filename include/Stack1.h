#pragma once

#include <iostream>

template <typename T>
class Stack1
{
private:
    unsigned int size;
    T *stack;

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
    this->stack = new T [size];
}

template <typename T>
void Stack1<T>::push(T&& value) {
    T* old = this->stack;

    size++;
    this->stack = new T [size];

    for(int i = 0; i < size - 1; i++) {
        this->stack[i + 1] = old[i];
    }
    this->stack[0] = std::move(value);
}

template <typename T>
void Stack1<T>::push(const T& value) {
    T* old = this->stack;

    size++;
    this->stack = new T [size];

    for(int i = 0; i < size - 1; i++) {
        this->stack[i + 1] = *old[i];
    }
    this->stack[0] = value;
}

template <typename T>
void Stack1<T>::pop() {
    T *old = this->stack;

    size--;
    this->stack = new T [size];

    for(int i = 0; i < size; i++) {
        this->stack[i] = old[i + 1];
    }
}

template <typename T>
const T& Stack1<T>::head() const{
    return this->stack[0];
}

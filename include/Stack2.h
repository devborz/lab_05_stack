#pragma once

#include <iostream>

template <typename T>
class Stack2
{
private:
    unsigned int size;
    T *stack;

public:
    Stack2();
    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(const T& value);
    void push(T&& value);
    const T& head() const;
    T pop();
    ~Stack2() = default;
};

template <typename T>
Stack2<T>::Stack2() {
    this->size = 0;
    this->stack = new T [size];
}

template <typename T>
void Stack2<T>::push(const T& value) {
    T* old = this->stack;

    size++;
    this->stack = new T [size];

    for(int i = 0; i < size - 1; i++) {
        this->stack[i + 1] = old[i];
    }
    this->stack[0] = value;;
}

template <typename T>
void Stack2<T>::push(T&& value) {
    T* old = this->stack;

    size++;
    this->stack = new T [size];

    for(int i = 0; i < size - 1; i++) {
        this->stack[i + 1] = old[i];
    }
    this->stack[0] = std::move(value);
}

template <typename T>
const T& Stack2<T>::head() const{
    return this->stack[0];
}

template <typename T>
template <typename ... Args>
void Stack2<T>::push_emplace(Args&&... value) {
    T args [] = {value...};

    for(const auto& e: args) {
        this->push(e);
    }
}

template <typename T>
T Stack2<T>::pop() {
    T* old = this->stack;
    T e = this->stack[0];

    size--;
    this->stack = new T [size];

    for(int i = 0; i < size; i++) {
        this->stack[i] = old[i + 1];
    }
    return e;
}

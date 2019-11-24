#pragma once

#include <iostream>

template <typename T>
class Stack
{
private:
    static const unsigned int st_capacity = 32; // reserved memory
    unsigned int size; // count of elements
    T *arr;

public:
    Stack();
    Stack(const Stack<T>& stack) = delete;
    Stack(Stack<T>&& stack);
    ~Stack() = default;

    void push(T&& value);
    void push(const T& value);
    void pop();

    bool isEmpty() const;
    bool isFull() const;

    const T& head() const;
};

template <typename T>
Stack<T>::Stack() {
    this->size = 0;
    this->arr = new T [this->st_capacity];
}

template <typename T>
Stack<T>::Stack(Stack<T>&& stack) {
    std::swap(this->size, stack->size);
    std::swap(this->arr, stack->arr);
}

template <typename T>
void Stack<T>::push(T&& value) {
    this->size++;
    if (this->size > this->st_capacity && !this->isFull()) {
        T* old = this->arr;

        this->arr = new T [this->size];

        for(int i = 0; i < this->size - 1; i++) {
            this->arr[i] = old[i];
        }
        this->arr[this->size - 1] = std::move(value);
    }
    else if (this->isFull()) {
        throw std::logic_error("|STACK OVERFLOW|");
        this->size--;
    }
    else this->arr[this->size - 1] = std::move(value);

}

template <typename T>
void Stack<T>::push(const T& value) {
    this->size++;
    if (this->size > this->st_capacity && !this->isFull()) {
        T* old = this->arr;

        this->arr = new T [size];

        for(int i = 0; i < this->size - 1; i++) {
            this->arr[i] = old[i];
        }
        this->arr[this->size - 1] = value;
    }
    else if (this->isFull()) {
        throw std::logic_error("|STACK OVERFLOW|");
        this->size--;
    }
    else
        this->arr[this->size - 1] = value;
}

template <typename T>
void Stack<T>::pop() {
    if(!this->isEmpty()) {
        T *old = this->arr;

        this->size--;
        if (this->size >= this->st_capacity) {
            T* old = this->arr;

            this->arr = new T [this->size];

            for(int i = 0; i < this->size; i++) {
                this->arr[i] = old[i];
            }
        }
    }
    else
        throw std::logic_error("|STACK IS EMPTY|");

}

template <typename T>
bool Stack<T>::isEmpty() const {
     return this->size == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
     return this->size > 1000;
}

template <typename T>
const T& Stack<T>::head() const{
    if (!this->isEmpty())
        return this->arr[this->size - 1];
    else
        throw std::logic_error("|STACK IS EMPTY|");
}

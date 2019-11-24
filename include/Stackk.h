#pragma once

#include <iostream>

template <typename T>
class Stackk
{
private:
    static const unsigned int st_capacity = 32; // reserved memory
    unsigned int size; // count of elements
    T *arr;

public:
    Stackk();
    Stackk(const Stackk<T>& stack) = delete;
    Stackk(Stackk<T>&& stack);
    ~Stackk() = default;

    template <typename ... Args>
    void push_emplace(Args&&... value);
    void push(const T& value);
    void push(T&& value);
    T pop();

    bool isEmpty() const;
    bool isFull() const;

    const T& head() const;
};

template <typename T>
Stackk<T>::Stackk() {
    this->size = 0;
    this->arr= new T [this->st_capacity];
}

template <typename T>
Stackk<T>::Stackk(Stackk<T>&& stack) {
    std::swap(this->size, stack->size);
    std::swap(this->arr, stack->arr);
}

template <typename T>
void Stackk<T>::push(const T& value) {
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
void Stackk<T>::push(T&& value) {
    this->size++;
    if (size > this->st_capacity && !this->isFull()) {
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
template <typename ... Args>
void Stackk<T>::push_emplace(Args&&... value) {
    T args [] = {value...};

    for(const auto& e: args) {
        this->push(e);
    }
}

template <typename T>
T Stackk<T>::pop() {
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
        return old[this->size];
    }
    else
        throw std::logic_error("|STACK IS EMPTY|");

}

template <typename T>
bool Stackk<T>::isEmpty() const {
     return this->size == 0;
}

template <typename T>
bool Stackk<T>::isFull() const {
     return this->size > 1000;
}

template <typename T>
const T& Stackk<T>::head() const {
    if (!this->isEmpty())
        return this->arr[this->size - 1];
    else
        throw std::logic_error("|STACK IS EMPTY|");
}

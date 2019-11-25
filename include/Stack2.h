#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Stack2
{
private:
    static const unsigned int st_capacity = 32; // reserved memory
    unsigned int size; // count of elements
    std::shared_ptr<T> arr_ptr;

public:
    Stack2();
    Stack2(const Stack2<T>& stack) = delete;
    Stack2(Stack2<T>&& stack);
    ~Stack2() = default;

    Stack2<T>& operator=(const Stack2<T>& stack) = delete;
    Stack2<T>& operator=(Stack2<T>&& stack);

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
Stack2<T>::Stack2() {
    this->size = 0;
    this->arr_ptr.reset(new T [this->st_capacity]);
}

template <typename T>
Stack2<T>::Stack2(Stack2<T>&& stack) {
    std::swap(this->size, stack.size);
    std::swap(this->arr_ptr, stack.arr_ptr);
}

template <typename T>
Stack2<T>& Stack2<T>::operator=(Stack2<T>&& stack) {
    if(std::move(stack) != this) {
        std::swap(this->size, stack.size);
        std::swap(this->arr_ptr, stack.arr_ptr);
    }

    return *this;
}

template <typename T>
void Stack2<T>::push(const T& value) {
    this->size++;
    if (this->size > this->st_capacity && !this->isFull()) {
        T* old = this->arr_ptr.get();

        this->arr_ptr.reset(new T [size]);

        for(int i = 0; i < this->size - 1; i++) {
            this->arr_ptr.get()[i] = old[i];
        }
        this->arr_ptr.get()[this->size - 1] = value;
    }
    else if (this->isFull()) {
        throw std::logic_error("|Stack2 OVERFLOW|");
        this->size--;
    }
    else
        this->arr_ptr.get()[this->size - 1] = value;
}

template <typename T>
void Stack2<T>::push(T&& value) {
    this->size++;
    if (size > this->st_capacity && !this->isFull()) {
        T* old = this->arr_ptr.get();

        this->arr_ptr.reset(new T [size]);

        for(int i = 0; i < this->size - 1; i++) {
            this->arr_ptr.get()[i] = old[i];
        }
        this->arr_ptr.get()[this->size - 1] = std::move(value);
    }
    else if (this->isFull()) {
        throw std::logic_error("|Stack2 OVERFLOW|");
        this->size--;
    }
    else this->arr_ptr.get()[this->size - 1] = std::move(value);
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
    if(!this->isEmpty()) {
        T *old = this->arr_ptr.get();

        this->size--;
        if (this->size >= this->st_capacity) {

            this->arr_ptr.reset(new T [this->size]);

            for(int i = 0; i < this->size; i++) {
                this->arr_ptr.get()[i] = old[i];
            }
        }
        return old[this->size];
    }
    else
        throw std::logic_error("|Stack2 IS EMPTY|");

}

template <typename T>
bool Stack2<T>::isEmpty() const {
     return this->size == 0;
}

template <typename T>
bool Stack2<T>::isFull() const {
     return this->size > 65536;
}

template <typename T>
const T& Stack2<T>::head() const {
    if (!this->isEmpty())
        return this->arr_ptr.get()[this->size - 1];
    else
        throw std::logic_error("|Stack2 IS EMPTY|");
}

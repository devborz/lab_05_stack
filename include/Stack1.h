#pragma once

#include <iostream>
#include <memory>

template <typename T>
class Stack1
{
private:
    static const unsigned int st_capacity = 32; // reserved memory
    unsigned int size; // count of elements
    std::shared_ptr<T> arr_ptr;

public:
    Stack1();
    Stack1(const Stack1<T>& stack) = delete;
    Stack1(Stack1<T>&& stack);
    ~Stack1() = default;

    Stack1<T>& operator=(const Stack1<T>& stack) = delete;
    Stack1<T>& operator=(Stack1<T>&& stack);

    void push(T&& value);
    void push(const T& value);
    void pop();

    bool isEmpty() const;
    bool isFull() const;

    const T& head() const;
};

template <typename T>
Stack1<T>::Stack1() {
    this->size = 0;
    this->arr_ptr.reset(new T [this->st_capacity]);
}

template <typename T>
Stack1<T>::Stack1(Stack1<T>&& stack) {
    std::swap(this->size, stack.size);
    std::swap(this->arr_ptr, stack.arr_ptr);
}

template <typename T>
Stack1<T>& Stack1<T>::operator=(Stack1<T>&& stack) {
    if(std::move(stack) != this) {
        std::swap(this->size, stack.size);
        std::swap(this->arr_ptr, stack.arr_ptr);
    }

    return *this;
}

template <typename T>
void Stack1<T>::push(T&& value) {
    this->size++;
    if (this->size > this->st_capacity && !this->isFull()) {
        T* old = this->arr_ptr.get();

        this->arr_ptr.reset(new T [size]);

        for(int i = 0; i < this->size - 1; i++) {
            this->arr_ptr.get()[i] = old[i];
        }
        this->arr_ptr.get()[this->size - 1] = std::move(value);
    }
    else if (this->isFull()) {
        throw std::logic_error("|Stack1 OVERFLOW|");
        this->size--;
    }
    else this->arr_ptr.get()[this->size - 1] = std::move(value);

}

template <typename T>
void Stack1<T>::push(const T& value) {
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
        throw std::logic_error("|Stack1 OVERFLOW|");
        this->size--;
    }
    else
        this->arr_ptr.get()[this->size - 1] = value;
}

template <typename T>
void Stack1<T>::pop() {
    if(!this->isEmpty()) {
        T *old = this->arr_ptr.get();

        this->size--;
        if (this->size >= this->st_capacity) {

            this->arr_ptr.reset(new T [this->size]);

            for(int i = 0; i < this->size; i++) {
                this->arr_ptr.get()[i] = old[i];
            }
        }
    }
    else
        throw std::logic_error("|Stack1 IS EMPTY|");

}

template <typename T>
bool Stack1<T>::isEmpty() const {
     return this->size == 0;
}

template <typename T>
bool Stack1<T>::isFull() const {
     return this->size > 1000;
}

template <typename T>
const T& Stack1<T>::head() const{
    if (!this->isEmpty())
        return this->arr_ptr.get()[this->size - 1];
    else
        throw std::logic_error("|Stack1 IS EMPTY|");
}

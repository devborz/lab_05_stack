#pragma once
#include <any>

template <typename T>
class Element {
public:
    T value;
    std::any nextEl;
public:
    Element() = default;
    Element(T& val, Element<T> next) {
        this->value = val;
        this->nextEl = next;
    }

    void reset(Element<T> El) {
        this->value = El.value;
        this->nextEl = El.nextEl;
    }

    const T& getValue() const {
        return this->value;
    }

    auto getNext() {
        return std::any_cast<Element<T>>(this->nextEl);
    }

    ~Element() = default;
};

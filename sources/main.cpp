#include <iostream>
#include "Stack.h"
#include "Stackk.h"

int main() {
    // Stack 1
    std::cout << "_____FIRST__STACK_____\n";
    for(int i = 0; i < 10; i++) {
        st1.push(i);
    }
    for(int i = 0; i < 10; i++) {
        std::cout << st1.head() << std::endl;
        st1.pop();
    }

    // Stack 2
    std::cout << "\n_____SECOND_STACK_____\n";
    Stackk<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push_emplace(3, 4, 5);
    for(int i = 0; i < 5; i++) {
        std::cout << st2.head() << std::endl;
        st2.pop();
    }

}

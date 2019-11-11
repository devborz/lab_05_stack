#include <iostream>
#include "Stack1.h"
#include "Stack2.h"

int main() {
    // Stack 1
    std::cout << "\n_____STACK1_____\n";
    Stack1<int> st1;
    st1.push(1);
    st1.push(2);
    std::cout << st1.head() << std::endl;
    st1.pop();
    std::cout << st1.head() << std::endl;
    st1.pop();

    // Stack 2
    std::cout << "\n_____STACK2_____\n";
    Stack2<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push_emplace(3, 4, 5);
    for(int i = 0; i < 5; i++) {
        std::cout << st2.head() << std::endl;
        st2.pop();
    }

}

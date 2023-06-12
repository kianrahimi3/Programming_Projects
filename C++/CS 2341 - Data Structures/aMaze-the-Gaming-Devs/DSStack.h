//
// Created by kianr on 3/24/2021.
//

#ifndef PA04_AMAZING_DSSTACK_H
#define PA04_AMAZING_DSSTACK_H

#include "DSList.h"
#include "DSVector.h"

template <typename T>
class DSStack{
private:
    DSVector<T> stack;

public:

    DSStack() = default;
  //  ~DSStack() = default;
  //  DSStack(const DSStack &copyStack) {
  //      for(int i = 0; i < copyStack.stack.size(); i++)
  //          this->stack.push_back(copyStack.stack[i]);
  //  }



    //used this website to understand uses of stack functions
    //https://appdividend.com/2019/10/09/stacks-in-cpp-example-cpp-stack-program/#:~:text=Stack%20in%20C++%20Stacks%20are%20a%20type%20of,can%20use%20stacks%20in%20PDA%20(Push%20down%20Automata).

    bool empty() {
        return stack.size() == 0;
    };

    int size() {
        if(empty())
            return 0;
        else
            return stack.size();
    };

    T top() {
        return stack[stack.size()-1];
    };

    void push(T data) {
        stack.push_back(data);
    };

    void pop() {
        stack.pop_back();
    };

    DSVector<T> getList() {
        return stack;
    };
};

#endif //PA04_AMAZING_DSSTACK_H

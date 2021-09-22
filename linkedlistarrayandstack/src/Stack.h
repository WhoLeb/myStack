#pragma once

#include "dynamic_array.h"

namespace WhoLeb
{

    template<class T>
    class stack : public dynamic_array<T>
    {
    public:
        stack();
        ~stack();

        T top();

       // bool empty();
        void push(T val);
        void pop();

    private:
        dynamic_array<T>* this_stack;
    };

    template<class T> stack<T>::stack()
    {
        this_stack = new dynamic_array<T>;
    }

    template<class T> stack<T>::~stack()
    {
        delete this_stack;
    }

	
    template<class T> T stack<T>::top()
    {
        if(!this_stack->size()) return 0;
        return this_stack->get(this_stack->size() - 1);
    }

    template<class T> void stack<T>::push(T val)
    {
        this_stack->add_element(this_stack->size(), val);
    }
    
    template<class T> void stack<T>::pop()
    {
        if(!this_stack->size()) return;
        this_stack->remove_element(this_stack->size() - 1);
    }
    
}
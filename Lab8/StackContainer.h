//
// Created by danilapoddubny on 07/12/2020.
//

#ifndef LAB7_STACKCONTAINER_H
#define LAB7_STACKCONTAINER_H
#include <string>
#include <exception>
#include <iostream>
#include "Exception.h"

using namespace std;


template<typename T, bool unique = false>
class StackContainer {
public:
    class inputIterator;
    class reverseIterator;
    class randomAccessIterator;
    class Stack;
    StackContainer() {
        front = nullptr;
        back = nullptr;
    }
    ~StackContainer() {
        while (!empty()) {
            pop();
        }
    }
    void push(T value) {
        try {
            if (unique && find(value) != nullptr)
                throw new Exception("Error! Element with this value has already exist.");
            Stack* obj = new Stack;
            if (front != nullptr)
                front->previous = obj;
            obj->value = value;
            obj->previous = nullptr;
            obj->next = front;
            front = obj;
            if (back == nullptr)
                back = front;
        }
        catch (Exception& ex) {
            cerr << "\nException! " << ex.getMessage() << "\n";
        }
    }
    T& top() {
        try {
            if (empty())
                throw string("Empty!");
            return front->value;

        }
        catch (string& str) {
            cerr << "\nException! " << str << "\n";
        }
        static T obj;
        return obj;
    }
    void pop() {
        try {
            if (empty())
                throw string("Empty!");
            Stack* obj = front;
            front = front->next;
            if (front == nullptr)
                back = nullptr;
            else front->previous = nullptr;
            delete obj;
        }
        catch (string& str) {
            cerr << "\nException! " << str << "\n";

        }
    }
    T* find(T x) {
        Stack* f = front;
        while (f != nullptr && f->value != x)f = f->next;
        if (f != nullptr)
            return &(f->value);
        else return nullptr;
    }
    bool empty() {
        return front == nullptr;
    }
    void sort() {
        randomAccessIterator I = randomAccessEnd();
        I--;

        while (I != randomAccessBegin()) {
            I--;
            T obj = *I;
            randomAccessIterator J = I;
            J++;
            while (J != randomAccessEnd() && *J < obj) {
                *(J - 1) = *J;
                J++;
            }
            *(J - 1) = obj;
        }
    }
    void print() {
        cout << "StackContainer: " << endl;
        inputIterator I = inputBegin();
        while (I != inputEnd())
            cout << *I++ << endl;
        cout << "\n";
    }

    T operator--() {
        pop();
        return top();
    }
    T operator--(int) {
        T tmp = top();
        pop();
        return tmp;
    }
    void operator +=(T val) {

        push(val);
    }

    inputIterator inputBegin() {
        inputIterator I(front);
        return I;
    }
    inputIterator inputEnd() {
        inputIterator I(nullptr);
        return I;
    }
    reverseIterator reverseBegin() {
        reverseIterator I(back);
        return I;
    }
    reverseIterator reverseEnd() {
        reverseIterator I(nullptr);
        return I;
    }
    randomAccessIterator randomAccessBegin() {
        randomAccessIterator I(front, back, front);
        return I;
    }
    randomAccessIterator randomAccessEnd() {
        randomAccessIterator I(front, back, nullptr);
        return I;
    }

    class randomAccessIterator {
    private:
        Stack* start;
        Stack* end;
        Stack* cur;

    public:
        randomAccessIterator() {
        }

        randomAccessIterator(Stack* first, Stack* last, Stack* now) {
            cur = now;
            start = first;
            end = last;
        }
        randomAccessIterator& operator++() {
            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                this->cur = this->cur->next;
                return *this;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            return *this;
        }
        randomAccessIterator operator++(int) {
            randomAccessIterator tmp = *this;
            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                this->cur = this->cur->next;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            return tmp;
        }
        randomAccessIterator& operator--() {
            if (this->cur == nullptr)
                this->cur = end;
            else {
                try {
                    if (!this->cur)
                        throw string("Value is out of range!");
                    this->cur = this->cur->previous;
                    return *this;
                }
                catch (string& str) {
                    cerr << "\nException! " << str << "\n";
                }
            }
            return *this;
        }
        randomAccessIterator operator--(int) {
            randomAccessIterator tmp = *this;
            if (this->cur == nullptr)
                this->cur = end;
            else {
                try {
                    if (!this->cur)
                        throw string("Value is out of range!");
                    this->cur = this->cur->previous;
                }
                catch (string& str) {
                    cerr << "\nException! " << str << "\n";
                }
            }
            return tmp;
        }
        randomAccessIterator operator-(int count) {
            randomAccessIterator tmp = *this;
            for (int i = 0; i < count; i++)--tmp;
            return tmp;
        }
        void operator=(randomAccessIterator obj) {
            this->cur = obj.cur;
            this->end = obj.end;
            this->start = obj.start;
        }
        T& operator*() {

            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                return this->cur->value;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            static T tmp;
            return tmp;
        }
        T& operator[](const int index) {
            try {
                this->cur = this->start;
                if (index < 0)
                    throw string("Value is out of range!");
                for (int i = 0; i < index; i++) {
                    if (!this->cur)
                        throw string("Value is out of range!");
                    this->cur = this->cur->next;
                }

                return **this;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            static T obj;
            return obj;
        }
        bool operator!=(randomAccessIterator cmp) {
            return this->cur != cmp.cur;
        }
    };

    class inputIterator {
    private:
        Stack* cur;
    public:

        inputIterator() {
        }
        inputIterator(Stack* first) {
            cur = first;
        }
        inputIterator& operator++() {
            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                this->cur = this->cur->next;
                return *this;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            return *this;
        }

        inputIterator operator++(int) {
            inputIterator tmp = *this;
            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                this->cur = this->cur->next;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            return tmp;
        }

        T& operator*() {
            return this->cur->value;
        }
        bool operator!=(inputIterator right) {
            return (this->cur != right.cur);
        }
    };

    class reverseIterator {
    private:
        Stack* cur;
    public:
        reverseIterator() {
        }
        reverseIterator(Stack* first) {
            cur = first;
        }

        reverseIterator& operator++() {
            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                this->cur = this->cur->previous;
                return *this;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            return *this;
        }

        reverseIterator operator++(int) {
            reverseIterator tmp = *this;
            try {
                if (!this->cur)
                    throw string("Value is out of range!");
                this->cur = this->cur->previous;
            }
            catch (string& str) {
                cerr << "\nException! " << str << "\n";
            }
            return tmp;
        }

        bool operator!=(reverseIterator obj) {
            return this->cur != obj.cur;
        }

        T& operator*() {
            return this->cur->value;
        }
    };


    class Stack {

    public:
        Stack() {
            next = NULL;
            previous = NULL;
        }
        T value;
        Stack* next;
        Stack* previous;


    };
private:
    Stack* back;
    Stack* front;
};

#endif //LAB7_STACKCONTAINER_H

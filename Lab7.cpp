#include <iostream>
#include <exception>      // set_terminate

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
                throw string("Error! Element with this value has already exist.");
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
        catch (string& str) {
            cerr << "\nException! " << str << "\n";
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
        cout << "StackContainer: ";
        inputIterator I = inputBegin();
        while (I != inputEnd())
            cout << *I++ << " ";
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

class Schoolkid {
private:
    int id;
    int missed;
    string name;
public:

    Schoolkid(int id, int missed, const string &name) : id(id), missed(missed), name(name) {

    }

    Schoolkid(){
        id = 42;
        missed = 0;
        name = "John Doe";
    }

    virtual ~Schoolkid() {
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Schoolkid::id = id;
    }

    int getMissed() const {
        return missed;
    }

    void setMissed(int missed) {
        Schoolkid::missed = missed;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Schoolkid::name = name;
    }



    friend ostream &operator<<(ostream &os, const Schoolkid &schoolkid) {
        os << "id: " << schoolkid.id << " missed: " << schoolkid.missed << " name: " << schoolkid.name;
        return os;
    }

    bool operator==(const Schoolkid &rhs) const {
        return id == rhs.id &&
               missed == rhs.missed &&
               name == rhs.name;
    }

    bool operator!=(const Schoolkid &rhs) const {
        return !(rhs == *this);
    }

};



int main()
{

    cout << "\n--------------------------------Case 1-------------------------------------\n";
    int* intPtr;
    StackContainer<int> intCont;
    intCont += 444;
    intCont += 333;
    intCont += 222;
    intCont += 111;
    intCont += 555;

    intCont.print();

    intPtr = intCont.find(555);
    if (!intPtr)
        cout << "not found\n";
    else
        cout << "found: " << *intPtr << "\n";

    intCont--;

    intPtr = intCont.find(228);
    if (!intPtr)
        cout << "not found\n";
    else
        cout << "found: " << *intPtr << "\n";

    cout << "Sorted ";
    intCont.print();


    intCont += 42;
    intCont += 43;
    intCont += 44;
    intCont.print();
    intCont.sort();
    intCont.print();

    cout << "Input iterator: ";
    for (StackContainer<int>::inputIterator I = intCont.inputBegin(); I != intCont.inputEnd(); I++)
        cout << *I << " ";


    cout << "\n--------------------------------Case 2-------------------------------------\n";
    double* doublePtr;
    StackContainer<double, true> doubleCont;
    doubleCont += 22.8;
    doubleCont += 101.101;
    doubleCont += 3.14;
    doubleCont += 22.8;
    doubleCont += 55.5;
    doubleCont.print();

    doublePtr = doubleCont.find(55.5);
    if (!doublePtr)cout << "not found\n";
    else cout << "found: " << *doublePtr << "\n";

    doubleCont--;

    doublePtr = doubleCont.find(2.181212);
    if (!doublePtr)
        cout << "not found\n";
    else
        cout << "found: " << *doublePtr << "\n";

    doubleCont.print();

    cout << "Reverse iterator: ";
    for (StackContainer<double,true>::reverseIterator I = doubleCont.reverseBegin(); I != doubleCont.reverseEnd(); I++)
        cout << *I << " ";


    cout << "\n--------------------------------Case 3-------------------------------------\n";
    Schoolkid* kidPtr;
    StackContainer<Schoolkid> kidCont;
    Schoolkid tmp;
    tmp.setName("Pasha");
    kidCont += tmp;
    tmp.setName("Dasha");
    kidCont += tmp;
    kidCont.print();

    kidPtr = kidCont.find(tmp);
    if (!kidPtr)
        cout << "not found\n";
    else
        cout << "found: " << *kidPtr << "\n";

    kidCont--;

    kidPtr = kidCont.find(tmp);
    if (!kidPtr)
        cout << "not found\n";
    else
        cout << "found: " << *kidPtr << "\n";

    kidCont.print();

    cout << "Random access iterator ";
    StackContainer<Schoolkid>::randomAccessIterator I = kidCont.randomAccessBegin();
    cout << I[0] << "\n";
    cout << I[1] << "\n";

}
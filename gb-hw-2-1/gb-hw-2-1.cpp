#include <iostream>
#include <math.h>
#include <cstdint>

using namespace std;

class Power {

private:
    float number;
    float degree;

public:
    Power() : number(2), degree(2) {}

    void set(float inNumber, float inDegree) {
        number = inNumber;
        degree = inDegree;
    }

    void calculate() {
        cout << number << "^" << degree << "=" << pow(number, degree) << endl;
    }

};

class RGBA {
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;

public: 
    RGBA(): m_red(0), m_green(0), m_blue(0), m_alpha(255) {}
    RGBA(uint8_t inR, uint8_t inG, uint8_t inB, uint8_t inA) {
        m_red = inR;
        m_green = inG;
        m_blue = inB;
        m_alpha = inA;
    }

    void print() {
        cout << "m_red: " << (unsigned int)m_red << endl;
        cout << "m_green: " << (unsigned int)m_green << endl;
        cout << "m_blue: " << (unsigned int)m_blue << endl;
        cout << "m_alpha: " << (unsigned int)m_alpha << endl;
    }

};

class Stack {
private:
    int array[10];
    unsigned int size;

public: 
    Stack() {

        size = 0;
        for (int i = 0; i < 10; i++)
        {
            array[i] = 0;
        }
    };

    void reset() {
        for (int i = 0; i < 10; i++)
        {
            array[i] = 0;
        }
        size = 0;
    }

    bool push(int num) {
        if (size == 10)
        {
            cout << "Stack is full!" << endl;
            return false;
        }

        array[size++] = num;   
        return true;
    }

    int pop() {
        if (size == 0)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return array[size--];
    }

    void print() {
        cout << "( ";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << ")" << endl;
    }


};

int main()
{
    cout << "task 1: " << endl;
    Power p;
    p.set(2, 5);
    p.calculate();
    cout << endl;

    cout << "task 2: " << endl;
    RGBA rgba(230, 126, 111, 255);
    rgba.print();
    cout << endl;

    cout << "task 3: " << endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}


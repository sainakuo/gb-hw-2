#include <iostream>
#include <string>

using namespace std;

enum Gender {
    MALE,
    FEMALE, 
    UNKNOWN
};

class Person {
protected:
    string name;
    unsigned int age;
    Gender gender;
    float weight;

public: 
    Person() {
        name = "unknown";
        age = 0;
        gender = UNKNOWN;
        weight = 0;
    }

    Person(string inName, unsigned int inAge, Gender inGender, float inWeight) :
        name(inName), age(inAge), gender(inGender), weight(inWeight) {};

    void setName(string inName) {
        name = inName;
    }

    void setAge(unsigned int inAge) {
        age = inAge;
    }

    void setWeight(unsigned int inWeight) {
        weight = inWeight;
    }
};


class Student : public Person {
private: 
    unsigned int yearEdu;
    static int studentsCount;

public: 
    Student() {
        yearEdu = 0;
        studentsCount++;
    }
    Student(unsigned int inYearEdu, string inName, unsigned int inAge, Gender inGender, float inWeight) : 
        yearEdu(inYearEdu), Person(inName, inAge, inGender, inWeight) {
        studentsCount++;
    };

    void setYearEdu(unsigned int inYearEdu) {
        yearEdu = inYearEdu;
    }

    void setNextYearEdu() {
        yearEdu++;
    }

    void print() const {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "gender: " << gender << endl;
        cout << "weight: " << weight << endl;
        cout << "education year: " << yearEdu << endl;
        cout << endl;
    }

    int getStudentsCount() const {
        return studentsCount;
    }

    ~Student() {
        studentsCount--;
    }
};

int Student::studentsCount = 0;

class Fruit {
protected: 
    string name;
    string color;

public: 
    string getName() const {
        return name;
    }

    string getColor() const {
        return color;
    }
};

class Apple : public Fruit {
public: 
    Apple() {
        name = "apple";
    };
    Apple(string inColor) { 
        name = "apple";
        color = inColor; 
    };
};

class Banana : public Fruit {
public: 
    Banana() {
        name = "banana";
        color = "yellow";
    }
};

class GrannySmith : public Apple {
public: 
    GrannySmith() {
        name = "Granny Smith";
        color = "green";
    }
};

int main()
{
    cout << "task 1:" << endl;
    Student stud1(1, "Grigoriy", 19, MALE, 56);
    Student stud2(3, "Anna", 21, FEMALE, 48);
    Student stud3(4, "Sergey", 24, MALE, 75);

    stud1.print();
    stud2.print();
    stud3.print();

    cout << "Students count: " << stud1.getStudentsCount() << endl;
    cout << endl;

    cout << "task 2:" << endl;
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

}

/*
Блэкджек
классы: 
карта (поля: тип, сколько очков добавляет)
участник (поля: имя или ник, возраст, очки, массив карт, ход)
крупье наследуется от участника 
игрок наследуется от участника (поля: количество денег)
игра (поля: крупье, игрок, ставка игрока, массив карт, статус игры(кто выиграл или ничья))
()
*/
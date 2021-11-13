#include <iostream>
#include <string>

template<typename T>
T divv(T d1, T d2) {
    if (d2 == 0)
    {
        throw "DivisionByZero";
    }

    return (d1 / d2);
}

class Ex {
private:
    float x;
public:
    Ex(float inX): x(inX) {}
    float getX() const {
        return x;
    }
};

class Bar {
private:
    float y;
public: 
    Bar() {
        y = 0;
    }

    void set(float a) {
        if ((y + a) > 100)
        {
            throw Ex(a * y);
        }
        else
        {
            y = a;
        }
    }
};

enum direct {
    UP,    //0
    RIGHT, //1
    DOWN,  //2
    LEFT   //3
};

class OffTheField {
private:
    direct d;
public: 
    OffTheField(direct inD): d(inD) {}
    void print() const {
        std::string mes[4] = {"up", "right", "down", "left"};
        std::cout << "Off The Field! Impossible to go to " << mes[d] << std::endl;
    }
};

class IllegalCommand {
private:
    int dir;
public: 
    IllegalCommand(int inDir): dir(inDir) {}
    void print() const {
        std::cout << "Illegal Command! " << dir << " direct doesn't exist" << std::endl;
    }
};

class Field {
protected: 
    int sizeX;
    int sizeY;
public: 
    Field(int inSizeX = 10, int inSizeY = 10): sizeX(inSizeX), sizeY(inSizeY) {}
};

class Robot: public Field {
private:
    int x;
    int y;
public: 
    //(0,0) - нижний левый угол
    Robot(int inX = 0, int inY = 0): Field(), x(inX), y(inY) {}

    void go(int dir) {
   
        switch (dir)
        {
        case UP:
        {
            if (y + 1 < sizeY)
                y++;
            else
                throw OffTheField(UP);
            break;
        }
        case RIGHT:
        {
            if (x+1 < sizeX)
                x++;
            else
                throw OffTheField(RIGHT);
            break;
        }
        case DOWN:
        {
            if (y-1 >= 0)
                y--;
            else
                throw OffTheField(DOWN);
            break;
        }
        case LEFT: 
        {
            if (x - 1 >= 0)
                x--;
            else
                throw OffTheField(LEFT);
            break;
        }
        default: 
        {
            throw IllegalCommand(dir);
            break;
        }
        }

    }

    friend std::ostream& operator<<(std::ostream& out, Robot& robot);
};

std::ostream& operator<<(std::ostream& out, Robot& robot) {
    out << "robot position x:" << robot.x << " y:" << robot.y << std::endl;
    return out;
}

int main()
{
    std::cout << "task 1:" << std::endl;
    try {
        std::cout << divv(6, 0);
    }
    catch (const char* c) {
        std::cerr << "Error: " << c << std::endl;
    }

    std::cout << "task 2:" << std::endl;
    Bar bar;
    int n;
    try {
        do {
            std::cout << "Input n: " << std::endl;
            std::cin >> n;
            bar.set(n);

        } while (n != 0);
    }
    catch (Ex ex) {
        std::cerr << "Error! " << ex.getX() << std::endl;
    }

    std::cout << "task 3: " << std::endl;
    Robot r;
    int in;
    while (true)
    {
        try {
            std::cout << r;
            std::cout << "Input direct: 0 - UP, 1 - RIGHT, 2 - DOWN, 3- LEFT" << std::endl;
            std::cin >> in;
            r.go(in);
        }
        catch (OffTheField otf)
        {
            otf.print();
        }
        catch (IllegalCommand ilc)
        {
            ilc.print();
        }

    }

    return 0;
}


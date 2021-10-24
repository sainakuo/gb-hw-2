#include <iostream>
#include <string>

using namespace std;

//-------------- 1 task -----------------

const double PI = 3.1415926535;

class Figure {
public: 
	virtual double area() const = 0;
};

class Parallelogram : public Figure {
protected:
	int a; //основание
	int h; //высота

public: 
	Parallelogram(int inA, int inH) : a(inA), h(inH) {};

	double area() const {
		return (a * h);
	}

	
};

class Rectangle : public Parallelogram {
public: 
	Rectangle(int inA, int inH) : Parallelogram(inA, inH) {};
};

class Square : public Parallelogram {
public:
	Square(int inA) : Parallelogram(inA, inA) {};
};

class Rhombus : public Parallelogram {
public: 
	Rhombus(int inA, int inH) : Parallelogram(inA, inH) {};
};

class Circle : public Figure {
private:
	int radius;

public:
	Circle() {
		radius = 1;
	}

	Circle(int inR) : radius(inR) {};

	double area() const {
		double area;
		return (PI * radius * radius);
	}
};

//-------------- 2 task -----------------

class Car {
protected:
	string company;
	string model;
public:
	Car() {
		cout << "Car constructor" << endl;
	};
	Car(string inCompany, string inModel) : company(inCompany), model(inModel) {
		cout << "Car constructor" << endl;
	};
};

class PassengerCar: virtual public Car{
public: 
	PassengerCar() {
		cout << "PassengerCar constructor" << endl;
	};
	
	PassengerCar(string inCompany, string inModel) : Car(inCompany, inModel) {
		cout << "PassengerCar constructor" << endl;
	};

};

class Bus : virtual public Car {
public:
	Bus() {
		cout << "Bus constructor" << endl;
	};

	Bus(string inCompany, string inModel) : Car(inCompany, inModel) {
		cout << "Bus constructor" << endl;
	};
};

class Minivan : public PassengerCar, public Bus {
public: 
	Minivan() {
		cout << "Minivan constructor" << endl;
	};

	Minivan(string inCompany, string inModel) : Car(inCompany, inModel) {
		cout << "Minivan constructor" << endl;
	};
};

//-------------- 3 task -----------------

int nod(int a1, int a2);
int nok(int a1, int a2);

class Fraction {
private: 
	int num; //числитель
	int denom; //знаменатель

public: 
	Fraction(): num(1), denom(1) {};

	Fraction(int inNum, int inDenom) {
		num = inNum;

		if (inDenom != 0)
		{
			denom = inDenom;
		}
		else
		{
			cout << "Error, denominator is 0";
		}
	};

	void print() const {
		cout << num << "/" << denom;
	}

	void operator-() {
		num = -num;
	}

	friend Fraction operator+(Fraction fr1, Fraction fr2);
	friend Fraction operator-(Fraction fr1, Fraction fr2);
	friend Fraction operator*(Fraction fr1, Fraction fr2);
	friend Fraction operator/(Fraction fr1, Fraction fr2);

	friend bool operator==(Fraction fr1, Fraction fr2);
	friend bool operator!=(Fraction fr1, Fraction fr2);
	friend bool operator<(Fraction fr1, Fraction fr2);
	friend bool operator>(Fraction fr1, Fraction fr2);
	friend bool operator<=(Fraction fr1, Fraction fr2);
	friend bool operator>=(Fraction fr1, Fraction fr2);

	//сокращение дроби
	void reduction() {

		int temp = nod(num, denom);

		if (temp != 1) {
			num = num / temp;
			denom = denom / temp;
		}

	}

};

int findMax(int a1, int a2) {
	return (a1 > a2) ? a1 : a2;
}

int findMin(int a1, int a2) {
	return (a1 < a2) ? a1 : a2;
}

//наименьшее общее кратное
int nok(int a1, int a2) {

	if (a1 == a2)
		return a1;
	
	int max = findMax(a1, a2);
	int min = findMin(a1, a2);

	int nok = max;
	while (!((nok % min == 0) && (nok % max == 0)))
	{
		nok++;
	}

	return nok;
}

//наибольший общий делитель
int nod(int a1, int a2) {
	int max = findMax(a1, a2);
	int min = findMin(a1, a2);

	int nod = 1;

	for (int i = 1; i <= min; i++) {
		if (min % i == 0 && max % i == 0)
			nod = i;
	}

	return nod;
}

Fraction operator+(Fraction fr1, Fraction fr2) {
	int num, denom;

	denom = nok(fr1.denom, fr2.denom);
	num = (denom / fr1.denom) * fr1.num + (denom / fr2.denom) * fr2.num;

	Fraction frac(num, denom);
	frac.reduction();
	return frac;
}

Fraction operator-(Fraction fr1, Fraction fr2) {
	int num, denom;

	denom = nok(fr1.denom, fr2.denom);
	num = (denom / fr1.denom) * fr1.num - (denom / fr2.denom) * fr2.num;

	Fraction frac(num, denom);
	frac.reduction();
	return frac;
}


Fraction operator*(Fraction fr1, Fraction fr2) {
	int num, denom;
	int temp;

	num = fr1.num * fr2.num;
	denom = fr1.denom * fr2.denom;

	Fraction frac(num, denom);
	frac.reduction();
	return frac;
}

Fraction operator/(Fraction fr1, Fraction fr2) {

	Fraction temp(fr2.denom, fr2.num);
	Fraction result;
	result = fr1 * temp;

	return result;
}

bool operator==(Fraction fr1, Fraction fr2) {

	//сокращаем дроби сначала
	fr1.reduction();
	fr2.reduction();

	if ((fr1.num == fr2.num) && (fr1.denom == fr2.denom)) {
		return true;
	}
	else
		return false;
}

bool operator!=(Fraction fr1, Fraction fr2) {
	if (fr1 == fr2)
		return false;
	else
		return true;
}

bool operator<(Fraction fr1, Fraction fr2) {

	//сокращаем дроби сначала
	fr1.reduction();
	fr2.reduction();

	if (fr1.denom == fr2.denom)
	{
		if (fr1.num < fr2.num)
			return true;
		else
			return false;
	}

	int temp = nok(fr1.denom, fr2.denom);
	int num1 = (temp / fr1.denom) * fr1.num;
	int num2 = (temp / fr2.denom) * fr2.num;

	if (num1 < num2)
		return true;
	else
		return false;

}

bool operator>(Fraction fr1, Fraction fr2) {
	//сокращаем дроби сначала
	fr1.reduction();
	fr2.reduction();

	if (fr1.denom == fr2.denom)
	{
		if (fr1.num > fr2.num)
			return true;
		else
			return false;
	}

	int temp = nok(fr1.denom, fr2.denom);
	int num1 = (temp / fr1.denom) * fr1.num;
	int num2 = (temp / fr2.denom) * fr2.num;

	if (num1 > num2)
		return true;
	else
		return false;
}

bool operator<=(Fraction fr1, Fraction fr2) {
	if (fr1 > fr2)
		return false;
	else
		return true;
}

bool operator>=(Fraction fr1, Fraction fr2) {
	if (fr1 < fr2)
		return false;
	else
		return true;
}

int main()
{
	cout << "task 1: " << endl;
	Rectangle rec(2, 6);
	cout << "rectangle area: " << rec.area() << endl;
	Square sq(5);
	cout << "square area: " << sq.area() << endl;
	Rhombus rombus(4, 5);
	cout << "rombus area: " << rombus.area() << endl;
	Circle circle(5);
	cout << "circle area: " << circle.area() << endl;
	cout << endl;

	cout << "task 2" << endl;
	cout << "Car object: " << endl;
	Car car;
	cout << endl;
	cout << "PassengerCar object: " << endl;
	PassengerCar passCar;
	cout << endl;
	cout << "Bus object: " << endl;
	Bus bus;
	cout << endl;
	cout << "Minivan object: " << endl;
	Minivan minivan;
	cout << endl;

	cout << "task 3" << endl;

	Fraction fr1(1, 5);
	Fraction fr2(1, 7);
	Fraction fr3;

	fr3 = fr1 + fr2;
	fr1.print(); 
	cout << " + ";
	fr2.print();
	cout << " = ";
	fr3.print();
	cout << endl;

	fr3 = fr1 - fr2;
	fr1.print();
	cout << " - ";
	fr2.print();
	cout << " = ";
	fr3.print();
	cout << endl;

	fr3 = fr1 * fr2;
	fr1.print();
	cout << " * ";
	fr2.print();
	cout << " = ";
	fr3.print();
	cout << endl;

	fr3 = fr1 / fr2;
	fr1.print();
	cout << " / ";
	fr2.print();
	cout << " = ";
	fr3.print();
	cout << endl;

	cout << "-";
	fr1.print();
	cout << " = ";
	-fr1;
	fr1.print();
	cout << endl;

	fr1.print();
	cout << " == ";
	fr2.print();
	cout << " ? " << (fr1 == fr2) << endl;

	fr1.print();
	cout << " != ";
	fr2.print();
	cout << " ? " << (fr1 != fr2) << endl;

	fr1.print();
	cout << " < ";
	fr2.print();
	cout << " ? " << (fr1 < fr2) << endl;

	fr1.print();
	cout << " > ";
	fr2.print();
	cout << " ? " << (fr1 > fr2) << endl;

	fr1.print();
	cout << " <= ";
	fr2.print();
	cout << " ? " << (fr1 <= fr2) << endl;

	fr1.print();
	cout << " >= ";
	fr2.print();
	cout << " ? " << (fr1 >= fr2) << endl;

}
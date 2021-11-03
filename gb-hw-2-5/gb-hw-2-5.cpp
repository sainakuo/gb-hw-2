#include <iostream>

using namespace std;

template <class T>
class Pair1 {
private:
	T p1;
	T p2;
public: 
	Pair1(T inP1, T inP2) : p1(inP1), p2(inP2) {}
	T first() const {
		return p1;
	}

	T second() const {
		return p2;
	}
};

template <class T, class V>
class Pair {
private:
	T p1;
	V p2;
public:
	Pair(T inP1, V inP2) : p1(inP1), p2(inP2) {}
	T first() const {
		return p1;
	}

	V second() const {
		return p2;
	}
};

template<class V>
class StringValuePair: public Pair<string, V> {
public: 
	StringValuePair(string s, V v) : Pair<string, V>(s, v) {};
};


int main()
{
	cout << "task 1: " << endl;

	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	cout << endl;

	cout << "task 2: " << endl;

	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4(3.4, 5);
	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
	cout << endl;

	cout << "task 3: " << endl;
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayInt {
private:
	int* data;
	int length;
public: 
	ArrayInt() : length(0), data(nullptr) {};

	ArrayInt(int inLength) : length(inLength) {
		assert(length >= 0);
		if (length > 0)
		{
			data = new int[length];
		}
		else
			data = nullptr;
	}

	void erase() {
		if (length > 0)
		{
			delete[] data;
			data = nullptr;
			length = 0;
		}
	}

	int getLength() const {
		return length;
	}
	
	int& operator[](int index) {
		return data[index];
	}

	void deleteLast() {
		
		assert(length != 0);

		if (length == 1)
		{
			erase();
		}
		else
		{
			int* new_data = new int[length - 1];

			for (int i = 0; i < length - 1; i++) {
				new_data[i] = data[i];
			}

			delete[] data;
			data = new_data;
			length--;
		}
	}

	void deleteFirst() {
		assert(length != 0);

		if (length == 1)
		{
			erase();
		}
		else
		{
			int* new_data = new int[length - 1];

			for (int i = 0; i < length - 1; i++) {
				new_data[i] = data[i+1];
			}

			delete[] data;
			data = new_data;
			length--;
		}
	}

	//сортировка пузырьком
	void sort() {
		assert(length != 0);

		int tempIndex = 0;
		int lastIndex = length - 1;
		int temp;

		while (lastIndex > 0)
		{
			if (data[tempIndex] > data[tempIndex + 1])
			{
				temp = data[tempIndex];
				data[tempIndex] = data[tempIndex + 1];
				data[tempIndex + 1] = temp;
			}

			if (tempIndex == lastIndex - 1)
			{
				tempIndex = 0;
				lastIndex--;
			}
			else
			{
				tempIndex++;
			}
		}
	}

	void print() const {
		assert(length != 0);

		for (int i = 0; i < length; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
		cout << "length: " << length << endl;
	}

	~ArrayInt() {
		delete[] data;
	}
};

int differentCount(vector<int> vect) {

	sort(vect.begin(), vect.end());

	if (vect.size() == 0)
		return 0;

	if (vect.size() == 1)
		return 1;

	int sum = 1;
	vector<int>::iterator it;
	for (it = vect.begin(); it != vect.end()-1; it++)
	{
		if (*it != *(it+1))
			sum++;
	}
	return sum;
}

int main()
{
	ArrayInt array(5);

	array[0] = 2;
	array[1] = 3;
	array[2] = 1;
	array[3] = 0;
	array[4] = 4;
	array.print();

	array.deleteLast();
	array.print();

	array.deleteFirst();
	array.print();

	array.sort();
	array.print();

	vector<int> vect{ 1, 2, 1, 3, 4, 5, 5, 4, 2, 6, 7, 1, 8 };

	cout << differentCount(vect) << endl;
}

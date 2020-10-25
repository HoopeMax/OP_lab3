#include<iostream>

class MyClass
{
private:
	int *data;
	int arr_size;
public:


	MyClass(int size)
	{
		this->data = new int [size];
		this->arr_size = size;
		for (int i(0); i < size; i++)
		{
			data[i] = i;
			std::cout << data[i];

		}
		std::cout << "Сработал конструктор" << std::endl;
	}

	MyClass(const MyClass& new_object)
	{
		std::cout << "Сработал конструктор копирования" << std::endl;

		this->arr_size = new_object.arr_size;
		this->data = new int[new_object.arr_size];//выделили новое место в памяти под массив

		for (int i(0); i < new_object.arr_size; i++)
		{
			this->data[i] = new_object.data[i];
		}
	}

	~MyClass()
	{
		std::cout << "Сработал деструктор" << std::endl;
		delete[] data;
	}

};

int main(void)
{
	setlocale(LC_ALL, "rus");
	int a;
	std::cin >> a;
	MyClass object(a);
	MyClass object2(object);

	system("pause");
	return 0;
}


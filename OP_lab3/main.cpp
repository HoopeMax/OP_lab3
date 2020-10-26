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
		std::cout << "�������� �����������" << this << std::endl;
	}

	MyClass(const MyClass& new_object)
	{
		std::cout << "�������� ����������� �����������" << this << std::endl;

		this->arr_size = new_object.arr_size;
		this->data = new int[new_object.arr_size];//�������� ����� ����� � ������ ��� ������

		for (int i(0); i < new_object.arr_size; i++)
		{
			this->data[i] = new_object.data[i];
		}
	}

	MyClass & operator = (const MyClass &new_object)
	{
		
		this->arr_size = new_object.arr_size;

		std::cout << "�������� �������� ������������" << this << std::endl;

		if (this->data != nullptr)
		{
			delete[] this->data;
		}	

		this->data = new int[new_object.arr_size];

		for (int i(0); i < new_object.arr_size; i++)
		{
			this->data[i] = new_object.data[i];
		}
		return *this;
	}

	~MyClass()
	{
		std::cout << "�������� ����������" << std::endl;
		delete[] data;
	}
};

int main(void)
{
	setlocale(LC_ALL, "rus");

	int a = 10; 
	int b = 2; 
	int c = 5;

	MyClass object(a);
	MyClass object2(object);//��� �������������� ����������� ����������� 
	MyClass object3(c);

	object = object2 = object3;//����������� �������, ������ ���������� ��������� ������������ (�������������� �����������)

	system("pause");
	return 0;
}


#include<iostream>

class MyClass
{
private:
	int data;
public:


	MyClass(int data)
	{
		this->data = data;
		std::cout << "�������� �����������" << std::endl;
	}


	~MyClass()
	{
		std::cout << "�������� ����������" << std::endl;
	}

};

void Foon1(MyClass);
MyClass Foon2();

int main(void)
{
	setlocale(LC_ALL, "rus");
	MyClass object(5);
	MyClass object2(object);
	Foon1(object);
	Foon2();

	system("pause");
	return 0;
}

void Foon1(MyClass val)
{
	std::cout << "������� Foon1 " << std::endl;
}

MyClass Foon2()
{
	MyClass cop_object(3);
	std::cout << "������� Foon2 " << std::endl;
	return cop_object;
}
#include<iostream>

class Figure
{
private:
	int x;
	int y;

public:
	Figure()
	{
		x = 0;
		y = 0;
		std::cout << this << "�����������" << std::endl;
	}

	Figure(int valX, int valY)
	{
		x = valX;
		y = valY;
		std::cout << this << "�����������" << std::endl;
	}

	void Print()
	{
		std::cout << x << std::endl;
		std::cout << y << std::endl;
	}

	void SetY(int y)
	{
		this->y = y;
	}

	int GetY()
	{
		return y;
	}

	void SetX(int x)
	{
		this->x = x;
	}

	int GetX()
	{
		return x;
	}

	bool operator == (const Figure& newObject)//��� �������� ���������� ==
	{
		return (this->x == newObject.x && this->y == newObject.y);
	}

	bool operator != (const Figure& newObject)// �������� ���������� !=
	{
		return !(this->x == newObject.x && this->y == newObject.y);
	}
};


int main(void)
{

	setlocale(LC_ALL, "rus");

	Figure point(3, 5);
	Figure point2(2, 5);

	bool result1 = point == point2;//���������� false
	bool result2 = point != point2;//���������� true(���������� ����� �� ������������)


	system("pause");
	return 0;
}



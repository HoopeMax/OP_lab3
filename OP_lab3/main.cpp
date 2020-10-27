#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>


class Figure
{
protected:

	float sideA;
	float sideB;

public:

	virtual float Perimetr() = 0;
	virtual float Area() = 0;
	
	Figure(float sideA, float sideB)
	{
		this->sideA = sideA;
		this->sideB = sideB;
	}

	void Output()
	{
		std::cout << "Периметр: " << Perimetr()<<std::endl;
		std::cout << "Площадь: " << Area() << std::endl;
	}
	
};

class Rectangle : public Figure
{
public:
	Rectangle(float sideA, float sideB) :Figure( sideA, sideB)
	{
		this->sideA = sideA;
		this->sideB = sideB;
		Perimetr();
		Area();
	}
	
	float Perimetr() override
	{
		return (sideA + sideB) * 2;
	}

	float Area() override
	{
		return (sideA * sideB);
	}

};

class Parallelogram : public Figure
{
private:
	float angle;
public:
	
	float Perimetr() override
	{
		return sideA + sideB + sideA + sideB;
	}

	float Area() override
	{
		float h = sideA * sin((angle * M_PI) / 180);
		return sideB* h;

	}

	Parallelogram(float sideA, float sideB, float angle) :Figure(sideA, sideB)
	{
		this->angle = angle;
		Perimetr();
		Area();
	}

};


int main(void)
{
	
	setlocale(LC_ALL, "rus");
	const int N = 3, M = 2;

	Rectangle* object1 = new Rectangle[N]
	{
		{2,3},
		{4,3},
		{2,5}
	};

	Parallelogram* object2 = new Parallelogram[M]
	{
		{4,8,30},
		{3,2,45}
	};

	for (int i(0); i < N; i++)
	{
		object1[i].Output();
	}

	for (int i(0); i < M; i++)
	{
		object2[i].Output();
	}

	system("pause");
	return 0;
}


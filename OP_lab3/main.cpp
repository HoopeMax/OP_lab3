#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>


class Figure
{
protected:

	float sideA;
	float sideB;

	virtual float Perimetr() = 0;
	virtual float Area() = 0;
	virtual void Output() = 0;
public:
	
	Figure(float sideA, float sideB)
	{
		this->sideA = sideA;
		this->sideB = sideB;
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

	void Output() override
	{
		std::cout << "Периметр: " << Perimetr() << std::endl;
		std::cout << "   Площадь: " << Area() << std::endl;
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

	float Height()
	{
		return sideA * sin((angle * M_PI) / 180);
	}

	float Area() override
	{
		
		return sideB* Height();
	}

	Parallelogram(float sideA, float sideB, float angle) :Figure(sideA, sideB)
	{
		this->angle = angle;
		Perimetr();
		Area();
	}

	void Output() override
	{
		std::cout << "Периметр: " << Perimetr() << std::endl;
		std::cout << "   Площадь: " << Area() << std::endl;
		std::cout << "   Высота: " << Height() << std::endl;
	}

};

float Find_Rect_Max(unsigned short size, Rectangle* object1);
float Find_Rect_Min(unsigned short size, Rectangle* object1);

void Output_Rect(Rectangle* object1, unsigned short size);
void Output_Paral(Parallelogram* object2, unsigned short size);

float Find_Paral(unsigned short size, Parallelogram* object2);

int main(void)
{
	
	setlocale(LC_ALL, "rus");

	const unsigned short N = 3, M = 2;

	/*float* sideA = new  float[N];
	float* sideB = new  float[N];*/

	/*for (unsigned short i(0); i < N; i++)
	{
		std::cin >> sideA[i];
		std::cin >> sideB[i];
	}*/

	Rectangle* object1 = new Rectangle[N]
	{
		
		{2,5},
		{4,3},
		{2,5}
	};

	Parallelogram* object2 = new Parallelogram[M]
	{
		{4,8,30},
		{3,2,45}
	};

	std::cout << std::endl << "Прямоугольники:" << std::endl << std::endl;
	Output_Rect(object1, N);

	std::cout << std::endl << "Пaраллелограммы:" << std::endl << std::endl;
	Output_Paral(object2, M);

	std::cout << std::endl << "Минимальная площадь прямоугольника = " << Find_Rect_Min(N, object1) << std::endl;
	std::cout << std::endl << "Максимальная площадь прямоугольника = " << Find_Rect_Max(N, object1) << std::endl;
	
	std::cout << std::endl << "Минимальная высота пaраллелограмма = " << Find_Paral(M, object2) << std::endl << std::endl;

	system("pause");
	return 0;
}

void Output_Rect(Rectangle* object1, unsigned short size)
{
	for (int i(0); i < size; i++)
	{
		std::cout << i+1 <<") ";
		object1[i].Output();
	}
}

void Output_Paral(Parallelogram* object2, unsigned short size)
{
	for (int i(0); i < size; i++)
	{
		std::cout << i+1 << ") ";
		object2[i].Output();
	}
}

float Find_Rect_Min(unsigned short size, Rectangle* object1)
{
	float min = FLT_MAX;

	for (unsigned short i(0);i<size;i++)
	{
		if (min > object1[i].Area())
		{
			min = object1[i].Area();
		}
	}
	return min;
}

float Find_Rect_Max(unsigned short size, Rectangle* object1)
{

	float max = FLT_MIN;

	for (unsigned short i(0); i < size; i++)
	{
		
		if (max < object1[i].Area())
		{
			max = object1[i].Area();
		}
	}
	return max;
}

float Find_Paral(unsigned short size, Parallelogram* object2)
{
	float min = FLT_MAX;

	for (unsigned short i(0); i < size; i++)
	{
		if (min > object2[i].Height())
		{
			min = object2[i].Height();
		}
	}
	return min;
}

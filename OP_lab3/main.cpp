#include<iostream>

class Figure
{
protected:

	float* sideA;
	float* sideB;

public:

	virtual float Perimetr(int size) = 0;
	virtual void Area() = 0;
	
	Figure(int size)
	{
		this->sideA = new float[size];
		this->sideB = new float[size];
	}
	
};

class Rectangle : public Figure
{
public:
	Rectangle(int size, float* sideA) :Figure(size)
	{
		this->sideA = new float[size];

		for (int i(0); i < size; i++)
		{
			std::cin >> sideA[i];
			this->sideA[i] = sideA[i];
			std::cin >> sideB[i];
			this->sideB[i] = sideB[i];
			std::cout << "\n" << this->sideA[i]<<"\n";
			std::cout << "\n" << this->sideB[i] << "\n";
		}

	}
	
	float Perimetr(int size) override
	{
		float perimetr[2];
		for (int i = 0; i < size; i++)
		{
			perimetr[i] = (sideA[i] + sideB[i]) * 2;
			return perimetr[i];
		}
	}

	void Area() override
	{

	}

};

//class Parallelogram : public Figure
//{
//public:
//	Parallelogram(int size, float* sideA) :Figure(size)
//	{
//		
//	}
//	virtual void Perimetr() override
//	{
//
//	}
//	virtual void Area() override
//	{
//
//	}
//
//};


int main(void)
{
	
	setlocale(LC_ALL, "rus");

	int N = 2, M = 3;
	float* sideA;
	sideA = new float[N];
	
	Rectangle object(N, sideA);

	for (int i = 0; i < N; i++)
	{
		std::cout << object.Perimetr(N);
	}

	system("pause");
	return 0;
}



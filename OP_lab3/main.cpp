#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>

class Figure
{
protected:

	float X;
	float Y;

	//����� ����������� �������
	virtual float Perimetr() = 0;
	virtual float Area() = 0;
	virtual void Output() = 0;
public:
	
	Figure(float X, float Y)
	{
		this->X = X;
		this->Y = Y;
	}	
};

class Rectangle : public Figure
{
private:
	float sideA;
	float sideB;

public:
	Rectangle(float X, float Y, float sideA, float sideB) :Figure( X, Y)
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
		std::cout << "��������: " << Perimetr() << std::endl;
		std::cout << "   �������: " << Area() << std::endl;
	}
};

class Parallelogram : public Figure
{
private:
	float angle;
	float sideA;
	float sideB;
public:
	
	float Perimetr() override//��������������� ������� 
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

	Parallelogram(float X, float Y, float sideA, float sideB, float angle) :Figure(X, Y)
	{
		this->sideA = sideA;
		this->sideB = sideB;
		this->angle = angle;
		Perimetr();
		Area();
	}

	void Output() override
	{
		std::cout << "��������: " << Perimetr() << std::endl;
		std::cout << "   �������: " << Area() << std::endl;
		std::cout << "   ������: " << Height() << std::endl;
	}

};
//���� ������ ��������������
void Print_Side(float* side1, float* side2, unsigned short size);

//���� ������ ��������������� � ���� (� �����������)
void Print_Side(float* side1, float* side2, unsigned short size, float* angle);

//���� ����������� ������� ��������������� 
float Find_Rect_Max(unsigned short size, Rectangle* object1);
//���� ������������ ������� ��������������� 
float Find_Rect_Min(unsigned short size, Rectangle* object1);

//����� ���������� � ������������� 
void Output_Rect(Rectangle* object1, unsigned short size);
//����� ���������� � ���������������
void Output_Paral(Parallelogram* object2, unsigned short size);
//���� ����������� ������ ���������������
float Find_Paral(unsigned short size, Parallelogram* object2);

int main(void)
{
	setlocale(LC_ALL, "rus");
	
	const unsigned short N = 4, M = 3;

	float* rec_sideA = new  float[N];
	float* rec_sideB = new  float[N];

	float* paral_sideA = new  float[M];
	float* paral_sideB = new  float[M];
	float* angle = new  float[M];

	std::cout << std::endl << "��������������:" << std::endl << std::endl;
	Print_Side(rec_sideA, rec_sideB, N);

	std::cout << std::endl << "�a�������������:" << std::endl << std::endl;
	Print_Side(paral_sideA, paral_sideB, M, angle);

	Rectangle* object1 = new Rectangle[N]
	{
		{0, 0, rec_sideA[0], rec_sideB[0]},
		{0, 0,rec_sideA[1], rec_sideB[1]},
		{0, 0,rec_sideA[2], rec_sideB[2]},
		{0, 0,rec_sideA[3], rec_sideB[3]},

	};

	Parallelogram* object2 = new Parallelogram[M]
	{
		{0, 0,paral_sideA[0], paral_sideB[0], angle[0]},
		{0, 0,paral_sideA[1], paral_sideB[1], angle[1]},
		{0, 0,paral_sideA[2], paral_sideB[2], angle[2]},

	};

	std::cout << std::endl << "��������������:" << std::endl << std::endl;
	Output_Rect(object1, N);

	std::cout << std::endl << "�a�������������:" << std::endl << std::endl;
	Output_Paral(object2, M);

	std::cout << std::endl << "����������� ������� �������������� = " << Find_Rect_Min(N, object1) << std::endl;
	std::cout << std::endl << "������������ ������� �������������� = " << Find_Rect_Max(N, object1) << std::endl;

	std::cout << std::endl << "����������� ������ �a������������� = " << Find_Paral(M, object2) << std::endl << std::endl;

	delete[] object1, object2, rec_sideA, rec_sideB, paral_sideA, paral_sideB, angle;

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

void Print_Side(float *side1, float* side2, unsigned short size)
{
	for (unsigned short i(0); i < size; i++)
	{
		
		std::cout << "������� ������� � : ";
		std::cin >> side1[i];
		std::cout << "������� ������� B : ";
		std::cin >> side2[i];
	}
}

void Print_Side(float* side3, float* side4, unsigned short size, float* angle)
{
	for (unsigned short i(0); i < size; i++)
	{
		std::cout << "������� ������� � : ";
		std::cin >> side3[i];
		std::cout << "������� ������� B : ";
		std::cin >> side4[i];
		std::cout << "������� ���� : ";
		std::cin >> angle[i];
	}
}
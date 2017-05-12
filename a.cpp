#include <iostream>
#include <stdlib.h>
#include  <fstream>
#include<ctime>
#include <string> 
#define Z '+'
#define X '-'
#define C '*'
#define V '/'
using namespace std;
char language, over;
int  kind, r;
int n;
float s;



void	printthree(float v, ofstream &outfile)
{

	
		cout << "答案是：" << v << endl;
		outfile << "答案是：" << v <<endl;
	
}
int scan(string argc)//扫描文件中的要求的算式数量
{
	int n;
	ifstream infile;
	infile.open(argc)
	if (!infile.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	infile >> n;
	infile.close();
	return n;
}
void generateExpression(int num, ofstream &outfile)//用于生成运算式
{
	void generateExpressionone(ofstream & outfile);
	void generateExpressiontow(ofstream & outfile);
	void generateExpressionthree(ofstream & outfile);
	void generateExpressionfour(ofstream & outfile);
	void generateExpressionfive(ofstream & outfile);

	int i;
	srand(time(0));
	for (i = 1; i <= num; i++)
	{
		kind = rand() % 5;
		switch (kind)
		{
		case 0:
			generateExpressionone(outfile);
			break;
		case 1:
			generateExpressiontow(outfile);
			break;
		case 2:
			generateExpressionthree(outfile);
			break;
		case 3:
			generateExpressionfour(outfile);
			break;
		case 4:
			generateExpressionfive(outfile);
			break;
		}



	}

}
float   calculateResultone(float k1, float k2, float k3, float k4, int m1, int m2, int m3, int i, int f)//用于计算生成的运算式的结果
{
	float l1=0, l2=0;
	float counting(int a, float b, float c, float t);
	l1 = counting(m1, k1, k2, l1);
	l2 = counting(m3, k3, k4, l2);
	if (l2 == 0 && m2 == 3)
	{
		i--;
		f = 1;
		return 0;
	}

	s = counting(m2, l1, l2, s);
	return s;
}

void generateExpressionone(ofstream &outfile)
{
	int randomNumber();
	int randomOperation();
	int  m1, m2, m3, a, f = 0;
	char n1 = 'a', n2 = 'a', n3 = 'a';
	float l1, l2, k1, k2, k3, k4;
	srand(time(0));
	char sigh(int d, char n);
	for (int i = 0; i < 1; i++)
	{
		k1 = randomNumber();//用于随机生成数字
		k2 = randomNumber();
		k3 = randomNumber();
		k4 = randomNumber();
		m1 = randomOperation();//用于随机生成运算符
		m2 = randomOperation();//用于随机生成运算符
		m3 = randomOperation();//用于随机生成运算符
		s = calculateResultone(k1, k2, k3, k4, m1, m2, m3, i, f);//用于计算生成的运算式的结果
		if (f == 1)continue;
		if (s - (int)s != 0)
		{
			i--;
			continue;
		}
		n3 = sigh(m3, n3);//转换符号
		n2 = sigh(m2, n2);
		n1 = sigh(m1, n1);

		if (s - (int)s == 0)
		{
			cout << "（" << k1 << n1 << k2 << ")" << n2 << "(" << k3 << n3 << k4 << ")=";
			outfile << "（" << k1 << n1 << k2 << ")" << n2 << "(" << k3 << n3 << k4 << ")=";
			cin >> a;
			outfile << a;
			printthree(s,outfile);
			if (a == s)
				r++;
		}
	}
}

float   calculateResulttow(float k1, float k2, int m1, int i, int f)//用于计算生成的运算式的结果
{
	float l1, l2=0;
	float counting(int a, float b, float c, float t);
	s = counting(m1, k1, k2, s);
	if (l2 == 0 && m1 == 3)
	{
		i--;
		f = 1;
		return 0;
	}

	return s;
}
void generateExpressiontow(ofstream &outfile)
{
	int randomNumber();
	int randomOperation();
	float counting(int a, float b, float c, float t);
	char sigh(int d, char n);
	int  m1, a, f = 0;
	char n1 = 'a';
	float k1, k2;
	srand(time(0));
	for (int i = 0; i < 1; i++)
	{
		k1 = randomNumber();
		k2 = randomNumber();
		m1 = randomOperation();
		n1 = sigh(m1, n1);
		s = calculateResulttow(k1, k2, m1, i, f);
		if (f == 1)continue;
		if (s - (int)s != 0)
		{
			i--;
			continue;
		}
		if (s - (int)s == 0)
		{
			cout << k1 << n1 << k2 << "=";
			outfile << k1 << n1 << k2 << "=";
			cin >> a;
			outfile << a << endl;
			printthree(s,outfile);
			if (a == s)
				r++;
		}
	}
}
float   calculateResultthree(float k1, float k2, float k3, int m1, int m2, int i, int f)//用于计算生成的运算式的结果
{
	float l1;
	float counting(int a, float b, float c, float t);
	l1 = counting(m1, k1, k2, s);
	if (k3 == 0 && m2 == 3)
	{
		i--;
		f = 1;
		return 0;
	}
	s = counting(m2, l1, k3, s);
	return s;
}
void generateExpressionthree(ofstream &outfile)
{
	int f=0;
	int randomNumber();
	int randomOperation();
	float counting(int a, float b, float c, float t);
	char sigh(int d, char n);
	int m1, m2, a;
	char n1 = 'a', n2 = 'a';
	float s, l1, k1, k2, k3;
	srand(time(0));
	for (int i = 0; i<1; i++)
	{
		k1 = randomNumber();
		k2 = randomNumber();
		k3 = randomNumber();
		m1 = randomOperation();
		m2 = randomOperation();
		s = calculateResultthree(k1, k2, k3, m1, m2, i, f);
		n1 = sigh(m1, n1);
		n2 = sigh(m2, n2);
		if (s - (int)s != 0)
		{
			i--;
			continue;
		}
		if (s - (int)s == 0)
		{
			cout << "（" << k1 << n1 << k2 << ")" << n2 << k3 << "=";
			outfile << "（" << k1 << n1 << k2 << ")" << n2 << k3 << "=";
			cin >> a;
			outfile << a << endl;
			printthree(s,outfile);
			if (a == s)
				r++;
		}
	}

}
float   calculateResultfour(float k1, float k2, float k3, int m1, int m2, int i, int f)//用于计算生成的运算式的结果
{
	float l1;
	float counting(int a, float b, float c, float t);
	l1 = counting(m2, k2, k3, s);
	if (l1 == 0 && m1 == 3)
	{
		i--;
		f = 1;
		return 0;
	}
	s = counting(m1, k1, l1, s);
	return s;
}
void generateExpressionfour(ofstream &outfile)
{
	int f=0;
	int randomNumber();
	int randomOperation();
	float counting(int a, float b, float c, float t);
	char sigh(int d, char n);
	int m1, m2, a;
	char n1 = 'a', n2 = 'a';
	float k1, k2, k3, l1;

	srand(time(0));
	for (int i = 0; i<1; i++)
	{
		k1 = randomNumber();
		k2 = randomNumber();
		k3 = randomNumber();
		m1 = randomOperation();
		m2 = randomOperation();
		n2 = sigh(m2, n2);
		n1 = sigh(m1, n1);
		s = calculateResultfour(k1, k2, k3, m1, m2, i, f);
		if (s - (int)s != 0)
		{
			i--;
			continue;
		}
		if (s - (int)s == 0)
		{
			cout << k1 << n1 << "(" << k2 << n2 << k3 << ")=";
			outfile << k1 << n1 << "(" << k2 << n2 << k3 << ")=";
			cin >> a;
			outfile << a << endl;
			printthree(s,outfile);
			if (a == s)
				r++;
		}
	}
}
void generateExpressionfive(ofstream &outfile)
{
	int randomNumber();
	int randomOperation();
	float counting(int a, float b, float c, float t);
	char sigh(int d, char n);
	int m1, m2, a, m3;
	char n1 = 'a', n2 = 'a', n3 = 'a';
	float s=0, l1=0, k1, k2, k3, k4;
	srand(time(0));
	for (int i = 0; i<1; i++)
	{
		k1 = randomNumber();
		k2 = randomNumber();
		k3 = randomNumber();
		k4 = randomNumber();
		m1 = randomOperation();
		m2 = randomOperation();
		m3 = randomOperation();
		l1 = counting(m1, k1, k2, l1);
		n1 = sigh(m1, n1);
		if (k3 == 0 && m2 == 3)
		{
			i--;
			continue;
		}
		if (k4 == 0 && m3 == 3)
		{
			i--;
			continue;
		}
		if (m3 == 0 || m3 == 1)
		{
			i--;
			continue;
		}
		if (m2 == 0 || m2 == 1)
		{
			i--;
			continue;
		}
		s = counting(m2, l1, k3, s);
		s = counting(m3, s, k4, s);
		n2 = sigh(m2, n2);
		n3 = sigh(m3, n3);
		if (s - (int)s != 0)
		{
			i--;
			continue;
		}
		if (s - (int)s == 0)
		{
			cout << "（" << k1 << n1 << k2 << ")" << n2 << k3 << n3 << k4 << "=";
			outfile << "（" << k1 << n1 << k2 << ")" << n2 << k3 << n3 << k4 << "=";
			cin >> a;
			outfile << a << endl;
			printthree(s,outfile);
			if (a == s)
				r++;
		}
	}

}
int randomOperation()
{
	int a;

	a = rand() % 4;
	return a;
}
int randomOperation1()
{
	int a;

	a = rand() % 2;
	return a;
}
int randomNumber()
{

	int a;
	a = rand() % 10;
	return a;
}
float counting(int a, float b, float c, float t)
{
	switch (a)
	{
	case 0:
		t = b + c*1.0;
		break;
	case 1:
		t = b - c*1.0;
		break;
	case 2:
		t = b * c*1.0;
		break;
	case 3:
		if (c == 0)
			for (int j = 0;; j++)
			{
				c = rand() % 10;
				if (c != 0)break;
			}
		t = b *1.0 / c;
		break;

	}
	return t;
}

char sigh(int d, char n)
{
	switch (d)
	{
	case 0:
		n = Z;
		break;
	case 1:
		n = X;
		break;
	case 2:
		n = C;
		break;
	case 3:
		n = V;
		break;
	}
	return n;
}
void print(ofstream &outfile)
{

	cout << "请按O查看答题情况" << endl;
	outfile << "请按O查看答题情况" << endl;

	cin >> over;
	if (over == 'O')
	{

		cout << "您答对了" << r << "道题；" << "答错了" << n - r << "道题。" << endl;
		outfile << "您答对了" << r << "道题；" << "答错了" << n - r << "道题。" << endl;
	}
}
int main(int argv, char *argc[])
{

		n=scan(argc[1]);
	ofstream outfile;
	outfile.open(argc[2])
	if (!outfile.is_open())
	{
		cout << "文件无法打开" << endl;
		exit(1);
	}
	generateExpression(n,outfile);//用于生成运算式;
	print(outfile);//将统计结果输出给用户
	return 0;
}

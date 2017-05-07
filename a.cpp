#include"iostream"
#include<ctime>
#include<stdlib.h>
#include<fstream>
#include"string"
int zheng = 0;
using namespace std;
double calculateResult(int a, int b, int c)
{
	switch (a)
	{
	case 0:return (double)b + (double)c; break;
	case 1:return (double)b - (double)c; break;
	case 2:return (double)b*(double)c; break;
	case 3:return (double)b / (double)c; break;
	}
}
int scan(string argv)//扫描文件中的要求的算式数量
{
	int n;
	ifstream infile;
	infile.open(argv);
	if (!infile.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}
	infile >> n;
	infile.close();
	return n;
}
int randomNumber()//产生随机数
{
	int number = rand() % 10;
	return number;
}
void change1(int &b, int &c)//要是除法出现非整数或者除数为0 更改算式 使其结果为整数
{
	while (true)
	{
		if (c == 0)
		{
			c = randomNumber();
			continue;
		}
		double s = (double)b / (double)c;
		if (s - (int)s != 0)
		{
			b = randomNumber();
			c = randomNumber();
		}
		else break;
	}
}
void change2(int &a, int& b, int &c)
{
	while (true)
	{
		if (b == 0)
		{
			c = randomNumber();
			continue;
		}
		if (c == 0)
		{
			c = randomNumber();
			continue;
		}
		double s = (double)a / (double)b / (double)c;
		if (s - (int)s != 0)
		{
			b = randomNumber();
			c = randomNumber();
		}
		else break;

	}
}
int randonOperation()//产生随机运算符
{
	int operation = rand() % 4;
	return operation;
}
char transform(int a)//将产生的随机运算符转化为符号
{
	switch (a)
	{
	case 0:return '+'; break;
	case 1:return '-'; break;
	case 2:return '*'; break;
	case 3:return '/'; break;
	}
}
void print(int a, int b,ofstream &outfile)//打印答题的对错情况冰糖同时输出到out.txt文件中
{
	if (a == 1)
	{
		cout << "您答对了" << endl;
		outfile << "您答对了" << endl;
		zheng++;
	}
	else
	{
		cout << "您答错了，正确答案是" << b << endl;
		outfile << "您答错了，正确答案是" << b << endl;
	}
}
void classone(ofstream & outfile)//（3+4）*（5+6）类型的算式
{
	srand(time(0));
	double result;
	int n1, n2, n3, n4, o1, o2, o3, judge = 1;
	char op1, op2, op3;
	while (true)
	{
		n1 = randomNumber();
		n2 = randomNumber();
		n3 = randomNumber();
		n4 = randomNumber();
		o1 = randonOperation();
		o2 = randonOperation();
		o3 = randonOperation();
		op1 = transform(o1);
		op2 = transform(o2);
		op3 = transform(o3);
		if (op1 == '/')
			change1(n1, n2);
		if (op3 == '/')
			change1(n3, n4);
		result = calculateResult(o2, calculateResult(o1, n1, n2), calculateResult(o3, n3, n4));
		if (result - (int)result == 0)
			break;
	}
	cout << "(" << n1 << op1 << n2 << ")" << op2 << "(" << n3 << op3 << n4 << ")=";
	outfile << "(" << n1 << op1 << n2 << ")" << op2 << "(" << n3 << op3 << n4 << ")="<<endl;
	int answer;
	cin >> answer;
	outfile << "您的答案是" << answer << endl;
	if (answer != (int)result)
		judge = 0;
	print(judge, (int)result,outfile);
}
void classtwo(ofstream& outfile)// (3+4)*5*l类型的算式
{
	srand(time(0));
	double result=0;
	int result2=0;
	int n1, n2, n3, n4, o1, o2, o3, judge = 1;
	char op1, op2, op3;
	while (true)
	{
		n1 = randomNumber();
		n2 = randomNumber();
		n3 = randomNumber();
		n4 = randomNumber();
		o1 = randonOperation();
		o2 = randonOperation();
		o3 = randonOperation();
		op1 = transform(o1);
		op2 = transform(o2);
		op3 = transform(o3);
		if (op1 == '/')
			change1(n1, n2);
		double n = calculateResult(o1, n1, n2);
		result2 = (int)calculateResult(o1, n1, n2);
		if (op2 == '*')
		{
			if (op3 == '*')
				result = calculateResult(o1, n1, n2)*n3*n4;
			else if (op3 == '/')
			{
				while (true)
				{
					if ((result2*n3 / n4 - ((double)result2*((double)n3) / ((double)n4))) == 0)
					{
						result = result2*n3 / n4;
						break;
					}
					else
						n4 = randomNumber();
				}
			}
			else if (op3 == '+')
				result = n*n3 + n4;
			else if (op3 == '-')
				result = n*n3 - n4;
		}
		else if (op2 == '/')
		{
			if (op3 == '/')
			{
				change2(result2, n3, n4);
				result = n / n3 / n4;
			}
			if (op3 == '*')
			{
				while (true)
				{
					if ((result2*n4 / n3 - ((double)result2*((double)n4) / ((double)n3))) == 0)
					{
						result = result2*n4 / n3;
						break;
					}
					else
						n3 = randomNumber();
				}
			}
			else
			{
				while (true)
				{
					double s = n / n3;
					if (s - (int)s != 0)
						n3 = randomNumber();
					else
						break;
				}
				if (op3 == '+')
					result = n / n3 + n4;
				if (op3 == '-')
					result = n / n3 - n4;;
			}
		}
		else
		{
			if (op3 == '*')
				result = calculateResult(o2, (int)n, n3*n4);
			if (op3 == '/')
			{
				change1(n3, n4);
				result = calculateResult(o2, (int)n, n3/n4);
			}
			else
				result = calculateResult(o3,calculateResult(o2, (int)n, n3),n4);
		}
		if (result - (int)result == 0)
			break;
	}
	cout << "(" << n1 << op1 << n2 << ")" << op2  << n3 << op3 << n4 << "=";
	outfile << "(" << n1 << op1 << n2 << ")" << op2 << n3 << op3 << n4 << "=" << endl;
	int answer;
	cin >> answer;
	outfile << "您的答案是" << answer << endl;
	if (answer != (int)result)
		judge = 0;
	print(judge, (int)result, outfile);
}
int chooseclass()
{
	return rand() % 2;
}
void generateExpression(int n, ofstream & outfile)//产生随机算式
{
	for (int i = 0; i<n; i++)
	{
		int classes = chooseclass();
		if (classes == 0)
			classone(outfile);
		if (classes == 1)
			classtwo(outfile);
	}
}
int main(int args,char* argv[])
{
	int n = scan(argv[1]);
	ofstream outfile;
	outfile.open(argv[2]);
	if (!outfile.is_open())
	{
		cout << "文件无法打开" << endl;
		exit(1);
	}
	generateExpression(n,outfile);
	outfile << "你答对了 " << zheng << " 道题。" << endl;
	cout << "按e查看答题情况" << endl;
	char r;
	cin >> r;
	if(r=='e')
		cout << "你答对了 " << zheng << " 道题。" << endl;
	outfile.close();
	system("pause");
	return 0;
}

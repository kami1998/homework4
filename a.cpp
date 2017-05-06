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
int scan(string argv)
{
	cout << "������������Ŀ������" << endl;
	int n;
	ifstream infile;
	infile.open(argv);
	if (!infile.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		exit(1);
	}
	infile >> n;
	infile.close();
	return n;
}
int randomNumber()
{
	int number = rand() % 10;
	return number;
}
void change(int &b, int &c)
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
int randonOperation()
{
	int operation = rand() % 4;
	return operation;
}
char transform(int a)
{
	switch (a)
	{
	case 0:return '+'; break;
	case 1:return '-'; break;
	case 2:return '*'; break;
	case 3:return '/'; break;
	}
}
void print(int a, int b,ofstream &outfile)
{
	if (a == 1)
	{
		cout << "�������" << endl;
		outfile << "�������" << endl;
		zheng++;
	}
	else
	{
		cout << "������ˣ���ȷ����" << b << endl;
		outfile << "������ˣ���ȷ����" << b << endl;
	}
}
void classone(ofstream & outfile)
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
			change(n1, n2);
		if (op3 == '/')
			change(n3, n4);
		result = calculateResult(o2, calculateResult(o1, n1, n2), calculateResult(o3, n3, n4));
		if (result - (int)result == 0)
			break;
	}
	cout << "(" << n1 << op1 << n2 << ")" << op2 << "(" << n3 << op3 << n4 << ")=";
	outfile << "(" << n1 << op1 << n2 << ")" << op2 << "(" << n3 << op3 << n4 << ")="<<endl;
	int answer;
	cin >> answer;
	outfile << "���Ĵ���" << answer << endl;
	if (answer != (int)result)
		judge = 0;
	print(judge, (int)result,outfile);
}
void generateExpression(int n,ofstream & outfile)
{
	for (int i = 0; i<n; i++)
	{
		classone(outfile);
	}
}

int main(int args,char* argv[])
{
        cout<<argv[1]<<" "<<argv[2]<<endl;
	int n = scan(argv[1]);
	ofstream outfile;
	outfile.open(argv[2]);
        if(!outfile.is_open())
        cout<<"123"<<endl;
	generateExpression(n,outfile);
	outfile << "������ " << zheng << " ���⡣" << endl;
	cout << "��e�鿴�������" << endl;
	char r;
	cin >> r;
	if(r=='e')
		cout << "������ " << zheng << " ���⡣" << endl;
	outfile.close();
	system("pause");
	return 0;
}
#include"iostream"
#include"����.h"//����ͷ���������ͷ�ļ�
#include"iomanip"
using namespace std;
int main()
{
	double r=0;//��ʼ��r
	cin >> r;;//����뾶r
	cout << fixed<<setprecision(6)<<count(r) << endl;//�������ĺ���λС��
	system("pause");//�������������ͣ
	return 0;
}
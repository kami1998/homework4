#include"iostream"
#include"计算.h"//包含头计算面积的头文件
#include"iomanip"//控制输出小数位数
using namespace std;
int main()
{
	double r=0;//初始化r
	cin >> r;;//输入半径r
	cout << fixed<<setprecision(6)<<count(r) << endl;//输出面积的后六位小数
	system("pause");//程序运行完后暂停
	return 0;
}

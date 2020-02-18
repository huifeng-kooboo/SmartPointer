// main.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "SmartPointer.h"

class A{
public:
	A(){
		cout << "A Init" << endl;
	}
	~A()
	{
		cout << "A Destroy" << endl;
	}
	void ShowA()
	{
		cout << "Show A" << endl;
	}
};


//��������ָ�뷽��
void TestSmartPointer()
{
	SmartPointer<A> MM(new A());
	SmartPointer<A> FF(new A());
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestSmartPointer();
	system("pause");
	return 0;
}

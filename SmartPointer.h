#include "stdafx.h"

// 自制智能指针类头文件
template<typename T>
class SmartPointer{
public:
	SmartPointer(T* ptr_);
	~SmartPointer();
	T* operator->() const; //重载->符号
	T& operator*() const; //重载*符号
	SmartPointer<T>& operator=(SmartPointer<T>&ptr_); //重写=符号::转移所有权
	void Release(); //释放智能指针
	T* GetObjPtr(); //得到指针地址
	T * m_ptr; //存放智能指针
private:
	int m_count;//指针计数:为0时可释放
};

template<typename T>
SmartPointer<T>::SmartPointer(T* ptr_)
{
	// 判断是否为空
	if (ptr_)
	{
		m_ptr = ptr_;
		m_count = 1;
	}
	else{
		m_ptr = nullptr;
		cout << "指针为空，无法实现智能指针" << endl;
		m_count = 0;
	}
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
	if (m_ptr&&(m_count <= 1))
	{
		cout << "---------析构-------" << endl;
		delete m_ptr;
		m_ptr = NULL; //置为空
	}
	else
	{
		cout << "智能指针被转移:不进行析构" << endl;
	}
}

template<typename T>
T* SmartPointer<T>::operator->() const
{
	if (m_ptr)
	{
		return m_ptr;
	}
	else
	{
		cout << "智能指针为空，出错了！" << endl;
		return nullptr;
	}
}

template<typename T>
T& SmartPointer<T>::operator*()const
{
	if (m_ptr)
	{
		return *m_ptr;
	}
	else{
		cout << "智能指针为空，出错了！" << endl;
		return NULL;
	}
}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer<T>& ob_)
{
	if (this != &ob_)
	{
		delete m_ptr;
		m_ptr = ob_.m_ptr;
		ob_.m_ptr = NULL;
	}
	return *this;
}

template<typename T>
void SmartPointer<T>::Release()
{
	if(m_ptr)
	{
		delete m_ptr; //提前释放
		m_ptr = NULL; //需要置为空
		m_count = 0;
	}
}

//得到指针对象
template<typename T>
T* SmartPointer<T>::GetObjPtr()
{
	if (m_ptr)
	{
		m_count ++; //计数增加
		return m_ptr;
	}
	return nullptr;
}
#include "stdafx.h"

// ��������ָ����ͷ�ļ�
template<typename T>
class SmartPointer{
public:
	SmartPointer(T* ptr_);
	~SmartPointer();
	T* operator->() const; //����->����
	T& operator*() const; //����*����
	SmartPointer<T>& operator=(SmartPointer<T>&ptr_); //��д=����::ת������Ȩ
	void Release(); //�ͷ�����ָ��
	T* GetObjPtr(); //�õ�ָ���ַ
	T * m_ptr; //�������ָ��
private:
	int m_count;//ָ�����:Ϊ0ʱ���ͷ�
};

template<typename T>
SmartPointer<T>::SmartPointer(T* ptr_)
{
	// �ж��Ƿ�Ϊ��
	if (ptr_)
	{
		m_ptr = ptr_;
		m_count = 1;
	}
	else{
		m_ptr = nullptr;
		cout << "ָ��Ϊ�գ��޷�ʵ������ָ��" << endl;
		m_count = 0;
	}
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
	if (m_ptr&&(m_count <= 1))
	{
		cout << "---------����-------" << endl;
		delete m_ptr;
		m_ptr = NULL; //��Ϊ��
	}
	else
	{
		cout << "����ָ�뱻ת��:����������" << endl;
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
		cout << "����ָ��Ϊ�գ������ˣ�" << endl;
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
		cout << "����ָ��Ϊ�գ������ˣ�" << endl;
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
		delete m_ptr; //��ǰ�ͷ�
		m_ptr = NULL; //��Ҫ��Ϊ��
		m_count = 0;
	}
}

//�õ�ָ�����
template<typename T>
T* SmartPointer<T>::GetObjPtr()
{
	if (m_ptr)
	{
		m_count ++; //��������
		return m_ptr;
	}
	return nullptr;
}
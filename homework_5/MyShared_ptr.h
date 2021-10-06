#ifndef MYSHARED_PTR_H
#define MYSHARED_PTR_H

#include <map>

template<class T>
class MyShared_ptr
{
public:
	MyShared_ptr() : ptr_(nullptr) {}
	MyShared_ptr(T* ptr) : ptr_(ptr) { ptrBase_[ptr] = 1; }
	~MyShared_ptr();

	MyShared_ptr(MyShared_ptr&& other);
	MyShared_ptr& operator=(MyShared_ptr&& other);

	MyShared_ptr(const MyShared_ptr& other);
	MyShared_ptr& operator=(const MyShared_ptr& other);

	T* get() { return ptr_; }
	void reset();
	unsigned int use_count() { return ptrBase_[ptr_]; }

private:
	T* ptr_;
	static std::map<T*, unsigned int> ptrBase_;
};

template<class T>
std::map<T*, unsigned int> MyShared_ptr<T>::ptrBase_;

template<class T>
inline MyShared_ptr<T>::~MyShared_ptr()
{
	if (ptrBase_[ptr_] == 1)
		delete ptr_;
	else
	{
		ptrBase_[ptr_] -= 1;
		ptr_ = nullptr;
	}
}

template<class T>
inline MyShared_ptr<T>::MyShared_ptr(MyShared_ptr&& other)
{
	if (this != &other)
	{
		if (ptr_ != nullptr)
			reset();

		ptr_ = other.ptr_;

		if (other.ptr_ != nullptr)
			ptrBase_[other.ptr_] += 1;
	}

}

template<class T>
inline MyShared_ptr<T>& MyShared_ptr<T>::operator=(MyShared_ptr&& other)
{
	if (this != &other)
	{
		if (ptr_ != nullptr)
			reset();

		ptr_ = other.ptr_;
	}
	return *this;
}

template<class T>
inline MyShared_ptr<T>::MyShared_ptr(const MyShared_ptr& other)
{
	if (this != &other)
	{
		if (ptr_ != nullptr)
			reset();

		ptr_ = other.ptr_;

		if (other.ptr_ != nullptr)
			ptrBase_[other.ptr_] += 1;
	}
}

template<class T>
inline MyShared_ptr<T>& MyShared_ptr<T>::operator=(const MyShared_ptr& other)
{
	if (this != &other)
	{
		if (ptr_ != nullptr)
			reset();

		ptr_ = other.ptr_;

		if (other.ptr_ != nullptr)
			ptrBase_[other.ptr_] += 1;
	}

	return *this;
}

template<class T>
inline void MyShared_ptr<T>::reset()
{
	if (ptrBase_[ptr_] == 1)
		delete ptr_;
	else
	{
		ptrBase_[ptr_] -= 1;
		ptr_ = nullptr;
	}
}


#endif

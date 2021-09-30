#include <iostream>

#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector
{
public:
	
	typedef T* Iterator;

	MyVector() :  arr_(nullptr), capacity_(0), size_(0){}
	~MyVector() { delete[] arr_; }
	MyVector(unsigned size);
	MyVector(const MyVector& other);
	MyVector(MyVector&& other);

	void push_back(const T& value);
	void pop_back();
	void reserve(unsigned n);
	void erase(unsigned id);

	T& operator[](unsigned id);
	void operator=(const MyVector& other);
	void operator=(MyVector&& other);

	unsigned size() { return size_; }
	unsigned capacity() { return capacity_; }


private:
	T* arr_;
	unsigned capacity_;
	unsigned size_;
};

template<typename T>
inline MyVector<T>::MyVector(unsigned size)
{
	capacity_ = 2 * size+1;
	size_ = size;
	arr_ = new T[capacity_];
}

template<>
inline MyVector<int>::MyVector(unsigned size)
{
	capacity_ = 2 * size;
	size_ = size;
	arr_ = new int[capacity_];

	for (unsigned i = 0; i < size; ++i)
		arr_[i] = 0;
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector& other)
{
	arr_ = new T[other.capacity_];

	for (unsigned i = 0; i < other.size_; ++i)
		arr_[i] = other.arr_[i];

	size_ = other.size_;
	capacity_ = other.capacity_;
}

template<typename T>
inline MyVector<T>::MyVector(MyVector<T>&& other)
	: arr_(other.arr_), capacity_(other.capacity_), size_(other.size_)
{
	 other.arr_ = nullptr;
	 other.capacity_ = 0;
	 other.size_ = 0;
}

template<typename T>
inline void MyVector<T>::push_back(const T& value)
{
	if (size_ >= capacity_)
		reserve(2 * size_ + 1);

	arr_[size_++] = value;
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	if (size_ <= 0)
		throw std::out_of_range("ERROR: no items to pop!");
	size_--;
}

template<typename T>
inline void MyVector<T>::reserve(unsigned n)
{
	T* new_arr = new T[n];

	for (unsigned i = 0; i < size_; ++i)
		new_arr[i] = arr_[i];

	delete[] arr_;
	arr_ = new_arr;
	capacity_ = n;
}

template<typename T>
inline void MyVector<T>::erase(unsigned id)
{
	if (id < 0 || id >= size_)
		throw std::out_of_range("invalid index");

	if (size_ == 1)
	{
		size_--;
		return;
	}
	
	T* new_arr = new T[capacity_];
	for (unsigned i = 0, j=0; i < size_; ++i, ++j)
	{
		if (i == id)
			i++;
		new_arr[j] = arr_[i];
			
	}

	delete[] arr_;
	arr_ = new_arr;
	size_--;
}

template<typename T>
inline T& MyVector<T>::operator[](unsigned id)
{
	if (id < 0 || id >= size_)
		throw std::out_of_range("invalid index");
	return *(arr_ + id);
}

template<typename T>
inline void MyVector<T>::operator=(const MyVector& other)
{
	if (arr_ != nullptr)
		delete[] arr_;

	arr_ = new T[other.capacity_];
	for (unsigned i = 0; i < other.size_; ++i)
		arr_[i] = other.arr_[i];

	capacity_ = other.capacity_;
	size_ = other.size_;
}

template<typename T>
inline void MyVector<T>::operator=(MyVector<T>&& other)
{
	if (arr_ != nullptr)
		delete[] arr_;

	std::cout << "oper\n";
	arr_ = other.arr_;
	capacity_ = other.capacity_;
	size_ = other.size_;

	other.arr_ = nullptr;
	other.capacity_ = 0;
	other.size_ = 0;
}

#endif
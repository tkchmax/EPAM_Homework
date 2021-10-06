#ifndef MYUNIQUE_PTR_H
#define MYUNIQUE_PTR_H

template<class T>
class MyUnique_ptr
{
public:
	MyUnique_ptr(const MyUnique_ptr&) = delete;
	MyUnique_ptr& operator=(const MyUnique_ptr&) = delete;

	MyUnique_ptr(MyUnique_ptr&& other);
	MyUnique_ptr& operator=(MyUnique_ptr&& other);

	MyUnique_ptr() : ptr_(nullptr){}
	MyUnique_ptr(T* ptr) : ptr_(ptr){}
	~MyUnique_ptr();

	T* get() { return ptr_; }
	void reset();
	void release();

	operator bool();
private:
	T* ptr_;
};

template<class T>
inline MyUnique_ptr<T>::MyUnique_ptr(MyUnique_ptr&& other) : ptr_(other.ptr_)
{
	other.ptr_ = nullptr;
}

template<class T>
inline MyUnique_ptr<T>& MyUnique_ptr<T>::operator=(MyUnique_ptr&& other)
{
	if (this != &other)
	{
		if (ptr_ != nullptr)
			delete ptr_;
		ptr_ = other.ptr_;
		
		other.ptr_ = nullptr;
	}
	return *this;
}

template<class T>
inline MyUnique_ptr<T>::~MyUnique_ptr()
{
	if (ptr_ != nullptr)
		delete ptr_;
}

template<class T>
inline void MyUnique_ptr<T>::reset()
{
	if (ptr_ != nullptr)
		delete ptr_;
}

template<class T>
inline void MyUnique_ptr<T>::release()
{
	ptr_ = nullptr;
}

template<class T>
inline MyUnique_ptr<T>::operator bool()
{
	if (ptr_ != nullptr)
		return true;
	return false;
}


//ARRAYS
template<class T>
class MyUnique_ptr<T[]>
{
public:
	MyUnique_ptr(const MyUnique_ptr&) = delete;
	MyUnique_ptr& operator=(const MyUnique_ptr&) = delete;

	MyUnique_ptr(MyUnique_ptr&& other);
	MyUnique_ptr& operator=(MyUnique_ptr&& other);

	MyUnique_ptr() : arr_(nullptr) {}
	MyUnique_ptr(T* arr) : arr_(arr) {}
	~MyUnique_ptr();

	T* get() { return arr_; }
	void release() { arr_ = nullptr; }
	void reset();

private:
	T* arr_;
};

template<class T>
inline MyUnique_ptr<T[]>::MyUnique_ptr(MyUnique_ptr&& other)
{
	arr_ = other.arr_;
	other.arr_ = nullptr;
}

template<class T>
inline MyUnique_ptr<T[]>& MyUnique_ptr<T[]>::operator=(MyUnique_ptr&& other)
{
	if (this != &other)
	{
		if (arr_ != nullptr)
			delete[] arr_;
		arr_ = other.arr_;

		other.arr_ = nullptr;
	}
	return *this;
}

template<class T>
inline MyUnique_ptr<T[]>::~MyUnique_ptr() 
{
	if (arr_ != nullptr)
		delete[] arr_;
}

template<class T>
inline void MyUnique_ptr<T[]>::reset()
{
	if (arr_ != nullptr)
		delete[] arr_;
}

#endif

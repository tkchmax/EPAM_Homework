
#include <queue>
#include <stdexcept>
#include <fstream>
#include <mutex>

template<class T, std::size_t size>
class SafeQueue : public std::queue<T>
{
public:
	void push(const T& val);
	T pop();
private:
	std::mutex mutex_;
	std::condition_variable cv_;
};


template<class T, std::size_t size>
inline void SafeQueue<T, size>::push(const T& val)
{
	std::unique_lock <std::mutex> ul(mutex_);
	cv_.wait(ul, [&] {return std::queue<T>::size() < size; });

	std::queue<T>::push(val);
}

template<class T, std::size_t size>
inline T SafeQueue<T, size>::pop()
{
	std::lock_guard<std::mutex> l(mutex_);

	T val = std::queue<T>::front();
	std::queue<T>::pop();
	cv_.notify_one();

	return val;
}


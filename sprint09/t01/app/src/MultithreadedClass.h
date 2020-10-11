#pragma once

#include <thread>
#include <mutex>

class MultithreadedClass{
public:
	MultithreadedClass() = default;
	~MultithreadedClass() = default;

	int getInt() const { return m_int; };
	void add(int addValue) {
		const std::lock_guard<std::mutex> lock(m_mutex);
		for (int i = 0; i < addValue; i++)
			m_int++;
	};
	void subtract(int subtractValue) {
		const std::lock_guard<std::mutex> lock(m_mutex);
		for (int i = 0; i < subtractValue; i++)
			m_int--;
	};
private:
	int m_int{0};
	std::mutex m_mutex;
};

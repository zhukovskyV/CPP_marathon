#pragma once

#include <iostream>
#include <thread>

class Worker{
public:
	Worker() = default;
	~Worker() { joinThread(); };

	template <typename Function, class... Args>
	void startWorker(Function&& func, Args&& ...args) {
		if (m_thread != nullptr && m_thread->joinable())
			joinThread();
		std::thread* thread = new std::thread(func, args...);
		m_thread = thread;
	};

	void joinThread() {
		m_thread->join();
		delete m_thread;
	};
private:
	std::thread* m_thread{nullptr};
};

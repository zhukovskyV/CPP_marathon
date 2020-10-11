#pragma once

#include <thread>
#include <utility>
#include <vector>

class Worker{
public:
	Worker() = default;
	~Worker() { joinAllThreads(); };

	template <typename Function, class... Args>
	void startNewThread(Function&& func, Args&&... args) {
		m_workerThreads.push_back(std::thread(func, (std::forward<Args>(args))...));
	};

	void joinAllThreads() {
		for (auto &th : m_workerThreads) {
			if (th.joinable()) {
				th.join();
			}
		}
	};
private:
	std::vector<std::thread> m_workerThreads;
};

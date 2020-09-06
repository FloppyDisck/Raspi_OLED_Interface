#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP
#include <queue>
#include <mutex>
#include <condition_variable>

//C++ struggles with template classes divided by two files
//https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp

template <class T>
class Safe_Queue {
    public:
        Safe_Queue()
            : queue()
            , mutex()
            , cond()
        {} //Zero initialize the variables

        void enqueue(T t) {
            std::lock_guard<std::mutex> lock(mutex);
            queue.push(t);
            cond.notify_one();
        }

        // Get the "front"-element.
        // If the queue is empty return null.
        T dequeue() {
            std::unique_lock<std::mutex> lock(mutex);
            while(queue.empty())
            {
                return NULL;
            }
            T val = queue.front();
            queue.pop();
            return val;
        }

        bool empty() {
            std::lock_guard<std::mutex> lock(mutex);
            return queue.empty();
        }

    private:
        mutable std::mutex mutex;
        std::condition_variable cond;
        std::queue<T> queue;
};
#endif
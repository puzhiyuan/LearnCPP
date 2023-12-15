/*
 * @Author: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @Date: 2023-12-15 14:18:18
 * @LastEditors: ‘puzhiyuan’ ‘puzhiyuan185489643@gmail.com’
 * @LastEditTime: 2023-12-15 21:53:50
 * @FilePath: \LearnCPP\src\Foundation\lessons03\Callback.cpp
 * @Description: 回调函数
 */
#include <iostream>
#include <thread>
#include <functional>

// 回调函数类型
using Callback = std::function<void()>;

// 异步任务
void AsyncTask(Callback callback) {
    // 模拟异步任务
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Async task completed." << std::endl;

    // 执行回调函数通知主线程
    callback();
}

// 主线程中的回调函数
void OnTaskCompleted() {
    std::cout << "Main thread: Task completed callback received." << std::endl;
}

int main() {
    // 启动异步任务，并在任务完成时调用回调函数
    AsyncTask(OnTaskCompleted);

    // 主线程继续执行其他工作
    std::cout << "Main thread continues to work." << std::endl;

    // 等待异步任务完成
    std::this_thread::sleep_for(std::chrono::seconds(2));

    return 0;
}

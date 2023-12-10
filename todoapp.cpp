#include <iostream>
#include <vector>
#include <algorithm>  // 新增這一行
using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoApp {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        Task newTask(desc);
        tasks.push_back(newTask);
        cout << "任務已新增：" << desc << endl;
    }

    void showTasks() {
        if (tasks.empty()) {
            cout << "目前沒有任務。" << endl;
        } else {
            cout << "代辦事項清單：" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << (tasks[i].completed ? "[完成] " : "[未完成] ") << i + 1 << ". " << tasks[i].description << endl;
            }
        }
    }

    void completeTask(const string& desc) {
        auto it = find_if(tasks.begin(), tasks.end(), [&desc](const Task& task) {
            return task.description == desc;
        });

        if (it != tasks.end()) {
            it->completed = true;
            cout << "任務已標記為完成：" << it->description << endl;
        } else {
            cout << "找不到該任務。" << endl;
        }
    }
};

int main() {
    TodoApp todoApp;

    while (true) {
        cout << "\n請選擇操作：" << endl;
        cout << "1. 新增任務" << endl;
        cout << "2. 顯示所有任務" << endl;
        cout << "3. 標記任務完成" << endl;
        cout << "0. 退出" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "請輸入任務描述：";
                string desc;
                cin.ignore();  // 忽略之前的換行符
                getline(cin, desc);
                todoApp.addTask(desc);
                break;
            }
            case 2:
                todoApp.showTasks();
                break;
            case 3: {
                cout << "請輸入要標記為完成的任務描述：";
                string desc;
                cin.ignore();  // 忽略之前的換行符
                getline(cin, desc);
                todoApp.completeTask(desc);
                todoApp.showTasks();  // 修正：標記任務完成後繼續顯示操作選項
                break;
            }
            case 0:
                cout << "退出代辦事項應用。" << endl;
                return 0;
            default:
                cout << "無效的選擇。" << endl;
        }
    }

    return 0;
}

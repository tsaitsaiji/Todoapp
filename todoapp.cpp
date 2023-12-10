#include <iostream>
#include <vector>
#include <algorithm>  // �s�W�o�@��
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
        cout << "���Ȥw�s�W�G" << desc << endl;
    }

    void showTasks() {
        if (tasks.empty()) {
            cout << "�ثe�S�����ȡC" << endl;
        } else {
            cout << "�N��ƶ��M��G" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << (tasks[i].completed ? "[����] " : "[������] ") << i + 1 << ". " << tasks[i].description << endl;
            }
        }
    }

    void completeTask(const string& desc) {
        auto it = find_if(tasks.begin(), tasks.end(), [&desc](const Task& task) {
            return task.description == desc;
        });

        if (it != tasks.end()) {
            it->completed = true;
            cout << "���Ȥw�аO�������G" << it->description << endl;
        } else {
            cout << "�䤣��ӥ��ȡC" << endl;
        }
    }
};

int main() {
    TodoApp todoApp;

    while (true) {
        cout << "\n�п�ܾާ@�G" << endl;
        cout << "1. �s�W����" << endl;
        cout << "2. ��ܩҦ�����" << endl;
        cout << "3. �аO���ȧ���" << endl;
        cout << "0. �h�X" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "�п�J���ȴy�z�G";
                string desc;
                cin.ignore();  // �������e�������
                getline(cin, desc);
                todoApp.addTask(desc);
                break;
            }
            case 2:
                todoApp.showTasks();
                break;
            case 3: {
                cout << "�п�J�n�аO�����������ȴy�z�G";
                string desc;
                cin.ignore();  // �������e�������
                getline(cin, desc);
                todoApp.completeTask(desc);
                todoApp.showTasks();  // �ץ��G�аO���ȧ������~����ܾާ@�ﶵ
                break;
            }
            case 0:
                cout << "�h�X�N��ƶ����ΡC" << endl;
                return 0;
            default:
                cout << "�L�Ī���ܡC" << endl;
        }
    }

    return 0;
}

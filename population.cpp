#include <iostream>

using namespace std;

class PopulationSimulator {
public:
    int simulate(int initialPopulation, int years, double growthRate) {
        if (years == 0) {
            return initialPopulation;
        } else {
            // �����H�f�W��
            int newPopulation = initialPopulation * (1 + growthRate);

            // ��ܷ�e�~�����H�f��
            cout << "�~��: " << years << "�A�H�f��: " << newPopulation << endl;

            // ���j�����U�@�~
            return simulate(newPopulation, years - 1, growthRate);
        }
    }
};

int main() {
    // ��l�Ƽ�����
    PopulationSimulator simulator;

    // �]�w��l�H�f�B�����~���M�W���v
    int initialPopulation = 1000;
    int simulationYears = 10;
    double growthRate = 0.1;

    // �}�l����
    int finalPopulation = simulator.simulate(initialPopulation, simulationYears, growthRate);

    // ��̲ܳפH�f��
    cout << "���������A�̲פH�f�Ƭ�: " << finalPopulation << endl;

    return 0;
}

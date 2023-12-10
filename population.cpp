#include <iostream>

using namespace std;

class PopulationSimulator {
public:
    int simulate(int initialPopulation, int years, double growthRate) {
        if (years == 0) {
            return initialPopulation;
        } else {
            // 模擬人口增長
            int newPopulation = initialPopulation * (1 + growthRate);

            // 顯示當前年份的人口數
            cout << "年份: " << years << "，人口數: " << newPopulation << endl;

            // 遞迴模擬下一年
            return simulate(newPopulation, years - 1, growthRate);
        }
    }
};

int main() {
    // 初始化模擬器
    PopulationSimulator simulator;

    // 設定初始人口、模擬年份和增長率
    int initialPopulation = 1000;
    int simulationYears = 10;
    double growthRate = 0.1;

    // 開始模擬
    int finalPopulation = simulator.simulate(initialPopulation, simulationYears, growthRate);

    // 顯示最終人口數
    cout << "模擬結束，最終人口數為: " << finalPopulation << endl;

    return 0;
}

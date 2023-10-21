#include <iostream>

#include <DataWorker/dataworker.h>
#include <Equation/equation.h>
#include <Method/methodemc.h>
#include <Equation/LotkaVolterraEquation.h>

#define T 20000 // время в мс
#define k 1000 // число шагов
#define m 5 // число траекторий
#define X 0 // начальное значение

#define PATH_1 "test1.json"
#define PATH_2 "test2.json"
#define PATH_3 "test3.json"
#define PATH_4 "test4.json"
#define PATH_5 "test5.json"
#define PATH_6 "test6.json"

typedef  QVector<QVector<double>> Trajectories;

int main() {
    MethodEMC *data(new MethodEMC(T, k, m));
    /*
     * a - коэф рождаемости жертв
     * b - коэф убийства жертвы при встрече с хищником
     * g - коэф убывания хищников
     * d - коэф воспроизводства хищников
     * A - популяция жертв
     * B - популяция хищников
    */
    // 0.5, 0.02, 0.3, 0.01, 40, 30 - самое адекватное, что нашел

    LotkaVolterraEquation eq(0.5, 0.02, 0.3, 0.01, 40, 30);
    QPair<Trajectories, Trajectories> obj = data->start(eq);

    DataWorker::save(PATH_1, obj.first);
    DataWorker::save(PATH_2, obj.second);

    return 0;
}

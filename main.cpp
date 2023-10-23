#include <iostream>

#include <DataWorker/dataworker.h>

#include <Equation/equation.h>
#include <Equation/LotkaVolterraEquation.h>

#include <Methods/methodemc.h>
#include <Methods/methodmilstein.h>
#include <Methods/methodrk4.h>
#include <Methods/methodtr.h>


#define T 50000 // время в мс
#define K 5000 // число шагов
#define M 3 // число траекторий
#define X 0 // начальное значение

#define PATH_1 "test1.json"
#define PATH_2 "test2.json"
#define PATH_3 "test3.json"
#define PATH_4 "test4.json"
#define PATH_5 "test5.json"
#define PATH_6 "test6.json"

typedef  QVector<QVector<double>> Trajectories;

int main() {
    /*
     * a - коэф рождаемости жертв
     * b - коэф убийства жертвы при встрече с хищником
     * g - коэф убывания хищников
     * d - коэф воспроизводства хищников
     * A - популяция жертв
     * B - популяция хищников
    */
    // 0.5, 0.02, 0.3, 0.01, 40, 30 - самое адекватное, что нашел
    // или 0.8, 0.02, 0.3, 0.01, 40, 30
    LotkaVolterraEquation eq(0.8, 0.02, 0.3, 0.01, 40, 30);
/*
    MethodEMC *dataEMC(new MethodEMC(T, K, M, X));
    QPair<Trajectories, Trajectories> objEMC = dataEMC->start(eq);
    DataWorker::save(PATH_1, objEMC.first);
    DataWorker::save(PATH_2, objEMC.second);

    MethodRK4 *dataRK4(new MethodRK4(T, K, M, X));
    QPair<Trajectories, Trajectories> objRK4 = dataRK4->start(eq);
    DataWorker::save(PATH_3, objRK4.first);
    DataWorker::save(PATH_4, objRK4.second);
*/
    MethodTR *dataTR(new MethodTR(T, K, M, X));
    QPair<Trajectories, Trajectories> objTR = dataTR->start(eq);
    DataWorker::save(PATH_5, objTR.first);
    DataWorker::save(PATH_6, objTR.second);

    return 0;
}

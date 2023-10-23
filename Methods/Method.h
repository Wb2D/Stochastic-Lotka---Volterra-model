#ifndef METHOD_H
#define METHOD_H

#include <chrono>
#include <ctime>
#include <random>
#include <QtMath>
#include <QVector>
#include <QRandomGenerator>

#include <Equation/LotkaVolterraEquation.h>

#define DEVIATION 6.

typedef unsigned int uint;
typedef  QVector<QVector<double>> Trajectories;

class Method
{
public:
    Method(const uint &T, const uint &k, const uint &m, const uint &X) :
        T(T), k(k), m(m), X(X) {
        deltaT = (T - X) / k;
    }

protected:
    virtual QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const = 0;

    uint T; // время в секундах
    uint k; // число временных шагов
    uint m; // число траекторий
    uint X; // начальное значчение Х

    uint deltaT;
};

#endif // METHOD_H

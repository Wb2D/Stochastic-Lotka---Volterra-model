#ifndef METHOD_H
#define METHOD_H

#include <chrono>
#include <ctime>
#include <random>
#include <QtMath>
#include <QVector>
#include <QRandomGenerator>

#include <Equation/LotkaVolterraEquation.h>

typedef unsigned int uint;
typedef  QVector<QVector<double>> Trajectories;

class Method
{
public:
    Method(const uint &T, const uint &k, const uint &m, const uint &X, const double &dev) :
        T(T), k(k), m(m), X(X), dev(dev) {
        deltaT = (T - X) / k;
    }

protected:
    virtual QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const = 0;

    uint T; // время в секундах
    uint k; // число временных шагов
    uint m; // число траекторий
    uint X; // начальное значчение Х
    double dev; // стандартное отклонение

    uint deltaT; // шаг
};

#endif // METHOD_H

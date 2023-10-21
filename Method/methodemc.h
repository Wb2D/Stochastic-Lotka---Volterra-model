#ifndef METHODEMC_H
#define METHODEMC_H

#include <QtGlobal>
#include <random>
#include <cmath>
#include <ctime>
#include <QVector>
#include <QRandomGenerator>

#include <Equation/equation.h>
#include <Equation/LotkaVolterraEquation.h>

typedef unsigned int uint;
typedef  QVector<QVector<double>> Trajectories;

class MethodEMC
{
public:
    MethodEMC(const uint &T, const uint &k, const uint &m) :
        T(T), k(k), m(m) {
        deltaT = T / k;
    }

    Trajectories start() const; // не работает, сломано
    QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const;


private:
    uint T; // время в секундах
    uint k; // число временных шагов
    uint m; // число траекторий

    uint deltaT;
};

#endif // METHODEMC_H

#ifndef METHODMILSTEIN_H
#define METHODMILSTEIN_H

#include "Method.h"

class MethodMilstein : public Method
{
public:
    MethodMilstein(const uint &T, const uint &k, const uint &m, const uint &X, const double &dev) :
        Method(T, k, m, X, dev) {}

    QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const override;
};

#endif // METHODMILSTEIN_H

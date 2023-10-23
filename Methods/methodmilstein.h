#ifndef METHODMILSTEIN_H
#define METHODMILSTEIN_H

#include "Method.h"

#define DEVIATION 0.

class MethodMilstein : public Method
{
public:
    MethodMilstein(const uint &T, const uint &k, const uint &m, const uint &X) :
        Method(T, k, m, X) {}

    QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const override;
};

#endif // METHODMILSTEIN_H

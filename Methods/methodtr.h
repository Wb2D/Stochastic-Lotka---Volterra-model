#ifndef METHODTR_H
#define METHODTR_H

#include "Method.h"

class MethodTR : public Method
{
public:
    MethodTR(const uint &T, const uint &k, const uint &m, const uint &X) :
        Method(T, k, m, X) {}

    QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const override;
};

#endif // METHODTR_H

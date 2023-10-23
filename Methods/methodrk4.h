#ifndef METHODRK4_H
#define METHODRK4_H

#include "Method.h"

class MethodRK4 : public Method
{
public:
    MethodRK4(const uint &T, const uint &k, const uint &m, const uint &X) :
        Method(T, k, m, X) {}

    QPair<Trajectories, Trajectories> start(const LotkaVolterraEquation&) const override;
};

#endif // METHODRK4_H

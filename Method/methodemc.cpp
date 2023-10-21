#include "methodemc.h"

Trajectories MethodEMC::start() const {
    std::default_random_engine gen;
    std::normal_distribution<double> dist(0.,1.);
    Trajectories result;
    for(uint j = 0; j < m; ++j) {
        //double X = startX;
        result.push_back(QVector<double>());
        for(uint i = 0; i < T; i += deltaT) {
            //double Xd = Equation::F(X) * static_cast<double>(deltaT)/1000;
            //double W = dist(gen);
            //double Xs = Equation::G(X) * W * sqrt(static_cast<double>(deltaT)/1000);
            //X += Xd + Xs;
            //result[j].append(X);
        }
    }
    return result;
}

QPair<Trajectories, Trajectories> MethodEMC::start(const LotkaVolterraEquation &eq) const {
    std::default_random_engine gen;
    std::normal_distribution<double> dist(0.,1.);
    QPair<Trajectories, Trajectories> result;
    double dT = static_cast<double>(deltaT)/1000;
    for(uint j = 0; j < m; ++j) {
        double A = eq.getStartA();
        result.first.append(QVector<double>());
        double B = eq.getStartB();
        result.second.append(QVector<double>());
        for(uint i = 0; i < T; i += deltaT) {
            A += eq.A(A, B) * dT + dist(gen) * sqrt(dT);
            B += eq.B(A, B) * dT + dist(gen) * sqrt(dT);
            result.first[j].append(A);
            result.second[j].append(B);
        }
    }
    return result;
}

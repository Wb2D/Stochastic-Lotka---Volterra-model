#include "methodemc.h"

QPair<Trajectories, Trajectories> MethodEMC::start(const LotkaVolterraEquation &eq) const {
    std::mt19937 gen;
    uint seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen.seed(seed);
    std::normal_distribution<double> dist(0., dev);
    QPair<Trajectories, Trajectories> result;
    double dt = static_cast<double>(deltaT) / 1000;
    for(uint j = 0; j < m; ++j) {
        double A = eq.getStartA();
        result.first.push_back(QVector<double>());
        double B = eq.getStartB();
        result.second.push_back(QVector<double>());
        for(uint i = X; i < T; i += deltaT) {
            double dW1 = dist(gen) * sqrt(dt);
            double dW2 = dist(gen) * sqrt(dt);

            A += eq.A(A, B) * dt + dW1;
            B += eq.B(A, B) * dt + dW2;

            result.first[j].push_back(A);
            result.second[j].push_back(B);
        }
    }
    return result;
}

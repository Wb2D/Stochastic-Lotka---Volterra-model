#include "methodrk4.h"

QPair<Trajectories, Trajectories> MethodRK4::start(const LotkaVolterraEquation &eq) const {
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

            double k1A = eq.A(A, B) + dW1;
            double k1B = eq.B(A, B) + dW2;
            double k2A = eq.A(A + (k1A * dt / 2), B) + dW1;
            double k2B = eq.B(A, B + (k1B * dt / 2)) + dW2;
            double k3A = eq.A(A + (k2A * dt / 2), B) + dW1;
            double k3B = eq.B(A, B + (k2B * dt / 2)) + dW2;
            double k4A = eq.A(A + k3A * dt, B) + dW1;
            double k4B = eq.B(A, B + k3B * dt) + dW2;

            A += (k1A + 2 * k2A + 2 * k3A + k4A) * dt / 6;
            B += (k1B + 2 * k2B + 2 * k3B + k4B) * dt / 6;

            result.first[j].push_back(A);
            result.second[j].push_back(B);
        }
    }
    return result;
}

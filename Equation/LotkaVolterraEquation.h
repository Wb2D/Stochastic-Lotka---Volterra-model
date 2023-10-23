#ifndef LOTKAVOLTERRAEQUATION_H
#define LOTKAVOLTERRAEQUATION_H

#include <Equation/equation.h>

/*
 * A - популяция жертв
 * B - популяция хищников
 * a - коэф рождаемости жертв
 * b - коэф убийства жертвы при встрече с хищником
 * g - коэф убывания хищников
 * d - коэф воспроизводства хищников
*/

class LotkaVolterraEquation : public Equation
{
public:
    LotkaVolterraEquation(const double &a, const double &b, const double &g,
                          const double &d, const double &A, const double &B) :
        a(a), b(b), g(g), d(d), startA(A), startB(B) {}

    double F(const double&) override { return 0; };
    double G(const double&) override { return 0; };

    double A(const double &A, const double &B) const override {
        return (a - b * B) * A;
    }

    double B(const double &A, const double &B) const override {
        return (-g + d * A) * B;
    }

    double prodA(const double &B) const { return a - b * B; }
    double prodB(const double &A) const { return -g + d * A; }

    double getStartA() const { return startA; }
    double getStartB() const { return startB; }

private:
    double a;
    double b;
    double g;
    double d;
    double startA;
    double startB;
};

#endif // LOTKAVOLTERRAEQUATION_H

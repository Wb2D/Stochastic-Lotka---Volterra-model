#ifndef EQUATION_H
#define EQUATION_H


class Equation
{
public:
    virtual double F(const double&) = 0;
    virtual double G(const double&) = 0;

    virtual double A(const double&, const double&) const = 0;
    virtual double B(const double&, const double&) const = 0;
};

#endif // EQUATION_H

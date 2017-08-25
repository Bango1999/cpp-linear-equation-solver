#include <iostream>
#include <cmath>

using namespace std;

class LinearEquation {
    
public:
    
    LinearEquation();
    ~LinearEquation();
    LinearEquation(const LinearEquation&);
    
    void SetCoefficients(const double, const double, const double);
    void GetCoefficients();
    bool IsHorizontal();
    bool IsVertical();
    void SolveForX(double);
    void SolveForY(double);
    void Print();
    void Intersection(const LinearEquation&);
    
private:
    
    double A;
    double B;
    double C;
    
};



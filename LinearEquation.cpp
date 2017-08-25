#include "LinearEquation.h"

using namespace std;

LinearEquation::LinearEquation() {
    A = B = C = 0;
    cout << "Creating an equation..." << endl;
}

LinearEquation::~LinearEquation() {
    cout << "Deleting an equation..." << endl;
}

LinearEquation::LinearEquation(const LinearEquation& orig) {
    A = orig.A;
    B = orig.B;
    C = orig.C;
    cout << "Copying an equation..." << endl;
}

void LinearEquation::GetCoefficients() {
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C = " << C << endl;
}

void LinearEquation::SetCoefficients(const double a, const double b, const double c) {
    A = a;
    B = b;
    C = c;
    cout << "Coefficients were set successfully!" << endl;
}

void LinearEquation::Print() {
    cout << A << "x + " << B << "y = " << C << endl;
}

void LinearEquation::Intersection(const LinearEquation& eq2) {
    
    double xMatrix1[2][2] = {C, B, eq2.C, eq2.B};
    double xMatrix2[2][2] = {A, B, eq2.A, eq2.B};
    
    double yMatrix1[2][2] = {A, C, eq2.A, eq2.C};
    double yMatrix2[2][2] = {A, B, eq2.A, eq2.B};
    
    double xSolved = ((xMatrix1[0][0] * xMatrix1[1][1]) - (xMatrix1[0][1] * xMatrix1[1][0])) / ((xMatrix2[0][0] * xMatrix2[1][1]) - (xMatrix2[0][1] * xMatrix2[1][0]));
    
    
    double ySolved = ((yMatrix1[0][0] * yMatrix1[1][1]) - (yMatrix1[0][1] * yMatrix1[1][0])) / ((yMatrix2[0][0] * yMatrix2[1][1]) - (yMatrix2[0][1] * yMatrix2[1][0]));
    
    cout << "The intersection is at ( " << xSolved << " , " << ySolved << " )" << endl;
    
    
}

bool LinearEquation::IsHorizontal() {
    if (A == 0 && B != 0)
        return true;
    else
        return false;
}

bool LinearEquation::IsVertical() {
    if (B == 0)
        return true;
    else
        return false;
}

void LinearEquation::SolveForX(double y) {
    double rhs = (C - (y * B)) / A;
    cout << "X = " << rhs << endl;
}

void LinearEquation::SolveForY(double x) {
    double rhs = (C - (x * A)) / B;
    cout << "Y = " << rhs << endl;
}

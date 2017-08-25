/* 
 * File:   main.cpp
 * Author: lbswango
 *
 * Created on June 3, 2013, 12:40 PM
 */

#include "LinearEquation.h"

using namespace std;

int input = 100;
string whichEQ = "1";

void GetCo(double& a, double& b, double& c) {
    
    cout << "What is the coefficient of A: ";
    cin >> a;
    cout << "What is the coefficient of B: ";
    cin >> b;
    cout << "What is the coefficient of C: ";
    cin >> c;
}

void GetX(double& num) {
    cout << "Enter a value for X: ";
            cin >> num;
}

void GetY(double& num) {
    cout << "Enter a value for Y: ";
            cin >> num;
}
int main() {

    LinearEquation eq1;
    LinearEquation eq2;
    double a = 0;
    double b = 0;
    double c = 0;
    double num;
    
    while (input != 0) {
    
        cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
        cout << "1.) Set Coefficients" << endl;
        cout << "2.) Get Coefficients" << endl;
        cout << "3.) Copy Equation" << endl;
        cout << "4.) Print Equations" << endl;
        cout << "5.) Check for horizontal" << endl;
        cout << "6.) Check for vertical" << endl;
        cout << "7.) Get Intersection" << endl;
        cout << "8.) Solve for X" << endl;
        cout << "9.) Solve for Y" << endl;
        cout << "0.) EXIT" << endl;
        
        cin >> input;
        
        while (input < 0 || input > 10) {
            cout << "Invalid option.  Try again..." << endl;
            
            cin >> input;
        }
        if ((input > 0 && input < 4) || (input > 4 && input < 7) || (input > 7 && input < 10)) {
            cout << "Which equation would you like to work with?" << endl;
            cout << "1.) Equation 1: ";
            eq1.Print();
            cout << "2.) Equation 2: ";
            eq2.Print();
            cin >> whichEQ;
        }
        
        
        while (whichEQ != "1" && whichEQ != "2") {
            cout << "Invalid choice.  Do you want equation 1 or 2?" << endl;
            cin >> whichEQ;
        }
        
        
        if (whichEQ == "1") {
            
            
            switch (input) {

                 case 1: {

                     GetCo(a, b, c);
                     eq1.SetCoefficients(a, b, c);
                    break;

                } case 2: {

                    eq1.GetCoefficients();
                    break;

                } case 3: {

                    eq2 = LinearEquation(eq1);
                    cout << "Copied Successfully!" << endl;
                    break;
                } case 4: {

                    cout << "eq1: ";
                    eq1.Print();
                    cout << "eq2: ";
                    eq2.Print();
                    break;

                } case 5: {

                    if (eq1.IsHorizontal())
                        cout << "The equation is horizontal" << endl;
                    else
                        cout << "The equation is not horizontal" << endl;
                    break;

                } case 6 : {

                    if (eq1.IsVertical())
                        cout << "The equation is vertical" << endl;
                    else
                        cout << "The equation is not vertical" << endl;
                    break;

                } case 7: {

                    eq1.Intersection(eq2);
                    break;

                } case 8: {

                    GetY(num);
                    eq1.SolveForX(num);
                    break;

                } case 9: {

                    GetX(num);
                    eq1.SolveForY(num);
                    break;

                } case 0: {

                    cout << "Bye." << endl;
                    break;

                } default: {

                    break;
                }
            }
            
        }
        
        else if (whichEQ == "2") {
            
            
            switch (input) {
            
             case 1: {
                 
                 GetCo(a, b, c);
                 eq2.SetCoefficients(a, b, c);
                break;
                
            } case 2: {
                
                eq2.GetCoefficients();
                break;
                
            } case 3: {
                
                eq1 = LinearEquation(eq2);
                cout << "Equation Copied!" << endl;
                break;
            } case 4: {
                
                cout << "eq1: ";
                eq1.Print();
                cout << endl;
                cout << "eq2: ";
                eq2.Print();
                cout << endl;
                break;
                
            } case 5: {
                
                if (eq2.IsHorizontal())
                    cout << "The equation is horizontal" << endl;
                else
                    cout << "The equation is not horizontal" << endl;
                break;
                
            } case 6 : {
                
                if (eq2.IsVertical())
                    cout << "The equation is vertical" << endl;
                else
                    cout << "The equation is not vertical" << endl;
                break;
                
            } case 7: {
                
                eq2.Intersection(eq1);
                break;
                
            } case 8: {
                
                GetY(num);
                eq2.SolveForX(num);
                break;
                
            } case 9: {
                
                GetX(num);
                eq2.SolveForY(num);
                break;
                
            } case 0: {
                
                cout << "Bye." << endl;
                break;

            } default: {
                
                break;
            }
          }
            
        }
        
            
            
    }
    
    
    
    return 0;
}



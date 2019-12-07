#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <cmath>

using namespace std;

const double TMin = 0.001;
const double TMax = 1000;

static std::mt19937 creator{
        std::random_device{}()
};

struct function {
    double operator()(const double& x) {
        return cos(x) * tanh(x);
    }
};
struct secondFunction {
    double operator()(const double& x) {
        return (cos(x) * tanh(x) * sin(5 * x));
    }
};

void print(double num,double tmax, double xmin, double fmin, double chance, string indicator) {
    cout << "|" << setw(3) << setprecision(0) << num << setw(3) << "|" << setw(10) << fixed << setprecision(3) << tmax;
    cout << setw(2) << "|" << setw(7) << xmin << setw(3) << "|" << setw(9) << fmin;
    cout << setw(3) << "|" << setw(7) << chance << setw(3) << "|" << setw(5) << indicator << setw(3) << "|" << endl;
}


template <class F>
void otzhig(F f, const double a, const double b)
{
    double Tmin = TMin;
    double Tmax = TMax;
    auto jump = std::uniform_real_distribution<double>(a, b);
    auto temp = std::uniform_real_distribution<double>(0, 1);
    double xmin = jump(creator);
    std::cout << "+---------------------------------------------------------+" << std::endl;
    std::cout << "|  N  |     T     |    x    |    f(x)   |    P    | Take? |" << std::endl;
    std::cout << "+---------------------------------------------------------+" << std::endl;
    int i = 1;
    std::string indicator = "";
    while (Tmax > Tmin)
    {
        double Xi = jump(creator);
        double chance = 0.0;
        double delta_f = f(Xi) - f(xmin); // Находим delta(f)
        indicator = "No";
        if (delta_f <= 0)
        {
            xmin = Xi;
            indicator = "Yes";
            chance = 1;
        }
        else
        {
            double temp1 = temp(creator);
            chance = exp(-delta_f / Tmax); // Рассчет вероятности перехода
            indicator = "No";
            if (temp1 < chance)
            {
                xmin = Xi;
                indicator = "Yes";
            }
        }
        print(i, Tmax, xmin, f(xmin), chance, indicator);
        Tmax *= 0.95;
        i++;
    }
    std::cout << "+---------------------------------------------------------+" << std::endl;
    cout << "\n\nResult: xmin: " << xmin << "    Fmin= " << f(xmin) << endl;
}
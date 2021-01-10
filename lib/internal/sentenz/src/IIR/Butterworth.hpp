/*
 * Version 1.02
 *
*/

#ifndef BUTTERWORTH_HPP
#define BUTTERWORTH_HPP

#include <iostream>
#include <exception>
#include <cmath>
#include <vector>
#include <iterator>
#include <cstddef>
#include <complex>
#include <cstdlib>
#include <cassert>
#include <memory>
#include <typeinfo>

namespace Sentenz
{

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                          Butterworth Filter                                //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
//	std::vector<double> x {2.5, 3.4, 2.2, 4.6, 1.3, 4.0, 5.5};
//	std::vector<double> y;
//
//      /// Low Pass
//	Butterworth butter(2, 0.2, "low");
//      /// High Pass
//	Butterworth butter(2, 0.1405, "high");
//
//	butter.filter(x, y);
//	/// vs
//	butter.filtfilt(x, y);
//
//	for (auto& it : y) std::cout << it << std::endl;
//
//	// Result: 0.168638, 0.759374, 1.57407, 2.32211, 2.86103, 3.06703, 3.32285
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

class Butterworth
{
public:
    Butterworth() {}
    Butterworth(const auto& _t) : type(_t) {}
    Butterworth(size_t _n, double _f, const auto& _t) : n(_n), fcf(_f), type(_t) {}
    Butterworth(size_t _n, double _f1, double _f2, const auto& _t) : n(_n), f1f(_f1), f2f(_f2), type(_t) {}
    virtual ~Butterworth() = default;
    Butterworth(const Butterworth&) = default;
    //const Butterworth& operator=(const Butterworth&) = default;

    /// Denominator
    auto &denCofLP();
    auto &denCofHP();
    auto &denCofBP();
    auto &denCofBS();

    /// Numerator
    auto &numCofLP();
    auto &numCofHP();
    auto &numCofBP();
    auto &numCofBS();

    /// Filter Arithmetic
    void filter(const std::vector<double> &src, std::vector<double> &dest);
    void filtfilt(std::vector<double> &src, std::vector<double> &dest);

    /// Functions
    std::string &getType();
    size_t &getOrder();
    double &getCutFreqC();
    double &getCutFreq1();
    double &getCutFreq2();

    void setType(const std::string type = "low");
    void setOrder(size_t order = 2);
    void setCutFreqC(double coeff = 0.14);
    void setCutFreq1(double coeff = 0.2);
    void setCutFreq2(double coeff = 0.6);

private:
    /// Binomial/Trinomial Multyplication
    template<typename T>
    void binomialMult(const T &p, T &o);
    template<typename T>
    void trinomialMult(const T &a, const T &b, T &o);

    /// Scale Factor
    double scaleFactorLP();
    double scaleFactorHP();
    double scaleFactorBP();
    double scaleFactorBS();

    void computeCoeffs();

    /// Variables
    size_t n = 2;
    double fcf = 0.14;
    double f1f = 0.2;
    double f2f = 0.6;
    std::string type = "low";
    std::vector<double> den;
    std::vector<double> num;
    std::shared_ptr<std::vector<double>> denCof;
    std::shared_ptr<std::vector<double>> numCof;
};

} /// SENTENZ

//#include "Butterworth.cpp"

#endif /// BUTTERWORTH_HPP

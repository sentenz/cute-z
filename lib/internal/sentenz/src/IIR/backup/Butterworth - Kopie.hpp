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
    Butterworth(size_t n_, double f_, const auto& m_) : n(n_), fcf(f_), mode(m_) {}
    Butterworth(size_t n_, double f1_, double f2_, const auto& m_) : n(n_), f1f(f1_), f2f(f2_), mode(m_) {}
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

    /// Functions
    size_t &getOrder();
    void setOrder(size_t order);

    double &getCoeff();
    void setCoeff(double coeff);

    void filter(const std::vector<double> &src, std::vector<double> &dest);
    void filtfilt(std::vector<double> &src, std::vector<double> &dest);

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

    void setMode();

    /// Variables
    size_t n;
    double fcf;
    double f1f;
    double f2f;
    const std::string mode;
    std::vector<double> den;
    std::vector<double> num;
    std::shared_ptr<std::vector<double>> denCof;
    std::shared_ptr<std::vector<double>> numCof;
};

} /// SENTENZ

//#include "Butterworth.cpp"

#endif /// BUTTERWORTH_HPP

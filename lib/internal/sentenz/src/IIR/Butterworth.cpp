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

#include "Butterworth.hpp"

namespace Sentenz
{

////////////////////////////////////////////////////////////////////////////////
//                     Binomial/Trinomial Multyplication                      //
////////////////////////////////////////////////////////////////////////////////
/*
  binomial_mult - multiplies a series of binomials together and returns the
  coefficients of the resulting polynomial.

  The multiplication has the following form:

  (x+p.at(0))*(x+p.at(1))*...*(x+p.at(n-1))

  The p.at(i) coefficients are assumed to be complex and are passed to the function
  as a pointer to an array of doubles of length 2n.

  The resulting polynomial has the following form:

  x^n + a.at(0)*x^n-1 + a.at(1)*x^n-2 + ... +a.at(n-2)*x + a.at(n-1)

  The a.at(i) coefficients can in general be complex but should in most cases turn
  out to be real. The a.at(i) coefficients are returned by the function as a pointer
  to an array of doubles of length 2n. Storage for the array is allocated by the
  function and should be freed by the calling program when no longer needed.

  Function arguments:

  n  -  The number of binomials to multiply
  a  -  Input data
  o  -  An array of doubles where o.at(2i) (i=0...n-1) is assumed to be the real
        part of the coefficient of the i-th binomial and o.at(2i+1) is assumed to
        be the imaginary part. The overall size of the array is then 2n.
*/

template<typename T>
void Butterworth::binomialMult(const T &a, T &o)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = i; j > 0; --j)
        {
            o.at(2*j) += a.at(2*i) * o.at(2*(j-1)) - a.at(2*i+1) * o.at(2*(j-1)+1);
            o.at(2*j+1) += a.at(2*i) * o.at(2*(j-1)+1) + a.at(2*i+1) * o.at(2*(j-1));
        }

        o.at(0) += a.at(2*i);
        o.at(1) += a.at(2*i+1);
    }
}

/*
  trinomial_mult - multiplies a series of trinomials together and returns the
  coefficients of the resulting polynomial.

  The multiplication has the following form:

  (x^2 + a.at(0)x + b.at(0))*(x^2 + a.at(1)x + b.at(1))*...*(x^2 + a.at(n-1)x + b.at(n-1))

  The a.at(i) and b.at(i) coefficients are assumed to be complex and are passed to the
  function as a pointers to arrays of doubles of length 2n. The real part of the
  coefficients are stored in the even numbered elements of the array and the
  imaginary parts are stored in the odd numbered elements.

  The resulting polynomial has the following form:

  x^2n + a.at(0)*x^2n-1 + a.at(1)*x^2n-2 + ... +a.at(2n-2)*x + a.at(2n-1)

  The a.at(i) coefficients can in general be complex but should in most cases turn
  out to be real. The a.at(i) coefficients are returned by the function as a pointer
  to an array of doubles of length 4n. The real and imaginary parts are stored,
  respectively, in the even and odd elements of the array. Storage for the array
  is allocated by the function and should be freed by the calling program when no
  longer needed.

  Function arguments:

  n  -  The number of trinomials to multiply
  a  -  Pointer to an array of doubles of length 2n.
  b  -  Pointer to an array of doubles of length 2n.
*/

template<typename T>
void Butterworth::trinomialMult(const T &a, const T &b, T &o)
{
    o.at(2) = b.at(0);
    o.at(3) = b.at(1);
    o.at(0) = a.at(0);
    o.at(1) = a.at(1);

    for (size_t i = 1; i < n; ++i)
    {
        o.at(2*(2*i+1)) += b.at(2*i)*o.at(2*(2*i-1)) - b.at(2*i+1)*o.at(2*(2*i-1)+1);
        o.at(2*(2*i+1)+1) += b.at(2*i)*o.at(2*(2*i-1)+1) + b.at(2*i+1)*o.at(2*(2*i-1));

        for (size_t j = 2*i; j > 1; --j)
        {
            o.at(2*j) += a.at(2*i) * o.at(2*(j-1)) - a.at(2*i+1) * o.at(2*(j-1)+1) + b.at(2*i) * o.at(2*(j-2)) - b.at(2*i+1) * o.at(2*(j-2)+1);
            o.at(2*j+1) += a.at(2*i) * o.at(2*(j-1)+1) + a.at(2*i+1) * o.at(2*(j-1)) + b.at(2*i) * o.at(2*(j-2)+1) + b.at(2*i+1) * o.at(2*(j-2));
        }

        o.at(2) += a.at(2*i) * o.at(0) - a.at(2*i+1) * o.at(1) + b.at(2*i);
        o.at(3) += a.at(2*i) * o.at(1) + a.at(2*i+1) * o.at(0) + b.at(2*i+1);
        o.at(0) += a.at(2*i);
        o.at(1) += a.at(2*i+1);
    }
}

////////////////////////////////////////////////////////////////////////////////
//                               Scale Factor                                 //
////////////////////////////////////////////////////////////////////////////////
/*
  scaleFactorLP - calculates the scaling factor for a butterworth lowpass filter.
  The scaling factor is what the c coefficients must be multiplied by so that the
  filter response has a maximum value of 1.
*/

double Butterworth::scaleFactorLP()
{
    double omega;           /// M_PI * fcf
    double fomega;          /// function of omega
    double parg0;           /// zeroth pole angle
    double sf;              /// scaling factor

    omega = M_PI * fcf;
    fomega = sin(omega);
    parg0 = M_PI / static_cast<double>(2*n);
    sf = 1.0;

    for (size_t k = 0; k < n/2; ++k)
    {
        sf *= 1.0 + fomega * sin(static_cast<double>(2*k+1)*parg0);
    }

    fomega = sin(omega/2.0);

    if (n % 2)
    {
        sf *= fomega + cos(omega/2.0);
    }

    sf = pow(fomega, n) / sf;

    return sf;
}

double Butterworth::scaleFactorHP()
{
    double omega;           /// M_PI * fcf
    double fomega;          /// function of omega
    double parg0;           /// zeroth pole angle
    double sf;              /// scaling factor

    omega = M_PI * fcf;
    fomega = sin(omega);
    parg0 = M_PI / static_cast<double>(2*n);
    sf = 1.0;

    for (size_t k = 0; k < n/2; ++k)
    {
        sf *= 1.0 + fomega * sin(static_cast<double>(2*k+1)*parg0);
    }

    fomega = cos(omega / 2.0);

    if (n % 2)
    {
        sf *= fomega + sin(omega / 2.0);
    }

    sf = pow(fomega, n) / sf;

    return sf;
}

double Butterworth::scaleFactorBP()
{
    double ctt;             /// cotangent of theta
    double sfr, sfi;        /// real and imaginary parts of the scaling factor
    double parg;            /// pole angle
    double sparg;           /// sine of pole angle
    double cparg;           /// cosine of pole angle
    double a, b, c;         /// workspace variables

    ctt = 1.0 / tan(M_PI * (f2f - f1f) / 2.0);
    sfr = 1.0;
    sfi = 0.0;

    for (size_t k = 0; k < n; ++k)
    {
        parg = M_PI * static_cast<double>(2*k+1) / static_cast<double>(2*n);
        sparg = ctt + sin(parg);
        cparg = cos(parg);
        a = (sfr + sfi) * (sparg - cparg);
        b = sfr * sparg;
        c = -sfi * cparg;
        sfr = b - c;
        sfi = a - b - c;
    }

    return (1.0 / sfr);
}

double Butterworth::scaleFactorBS()
{
    double tt;              /// tangent of theta
    double sfr, sfi;        /// real and imaginary parts of the scaling factor
    double parg;            /// pole angle
    double sparg;           /// sine of pole angle
    double cparg;           /// cosine of pole angle
    double a, b, c;         /// workspace variables

    tt = tan(M_PI * (f2f - f1f) / 2.0);
    sfr = 1.0;
    sfi = 0.0;

    for (size_t k = 0; k < n; ++k)
    {
        parg = M_PI *  static_cast<double>(2*k+1) / static_cast<double>(2*n);
        sparg = tt + sin(parg);
        cparg = cos(parg);
        a = (sfr + sfi)*(sparg - cparg);
        b = sfr * sparg;
        c = -sfi * cparg;
        sfr = b - c;
        sfi = a - b - c;
    }

    return (1.0 / sfr);
}

////////////////////////////////////////////////////////////////////////////////
//                               Denominator                                  //
////////////////////////////////////////////////////////////////////////////////

auto &Butterworth::denCofLP()
{
    double parg;            /// pole angle
    double sparg;           /// sine of the pole angle
    double cparg;           /// cosine of the pole angle
    double a;               /// workspace variable

    double theta = M_PI * fcf;
    double st = sin(theta);
    double ct = cos(theta);

    /// binomial coefficients
    std::vector<double> binCof(2*n);    /// binomial coefficients
    std::vector<double> tmpCof(2*n);    /// binomial results

    if (!denCof)
    {
        denCof = std::make_shared<std::vector<double>>(n+1);
    }
    else if (denCof->size() != n+1)
    {
        denCof.reset(new std::vector<double>(n+1));
    }

    for (size_t k = 0; k < n; ++k)
    {
        parg = M_PI * static_cast<double>(2*k+1) / static_cast<double>(2*n);
        sparg = sin(parg);
        cparg = cos(parg);
        a = 1. + st * sparg;
        binCof.at(2*k) = -ct / a;
        binCof.at(2*k+1) = -st * cparg / a;
    }

    this->binomialMult(binCof, tmpCof);

    denCof->at(2) = tmpCof.at(2);
    denCof->at(1) = tmpCof.at(0);
    denCof->at(0) = 1.;

    for (size_t k = 3; k < n+1; ++k)
    {
        denCof->at(k) = tmpCof.at(2*k-2);
    }

    return *denCof;
}

inline auto &Butterworth::denCofHP()
{
    return this->denCofLP();
}

auto &Butterworth::denCofBP()
{
    double theta;           /// M_PI * (f2f - f1f) / 2.0
    double cp;              /// cosine of phi
    double st;              /// sine of theta
    double ct;              /// cosine of theta
    double s2t;             /// sine of 2*theta
    double c2t;             /// cosine 0f 2*theta
    double parg;            /// pole angle
    double sparg;           /// sine of pole angle
    double cparg;           /// cosine of pole angle
    double a;               /// workspace variables

    cp = cos(M_PI * (f2f + f1f) / 2.0);
    theta = M_PI * (f2f - f1f) / 2.0;
    st = sin(theta);
    ct = cos(theta);
    s2t = 2.0 * st * ct;        // sine of 2*theta
    c2t = 2.0 * ct * ct - 1.0;  // cosine of 2*theta

    /// trinomial coefficients
    std::vector<double> triCofR(2*n);   /// z^-2 coefficients
    std::vector<double> triCofT(2*n);   /// z^-1 coefficients
    std::vector<double> tmpCof(4*n);    /// trinomial results

    if (!denCof)
    {
        denCof = std::make_shared<std::vector<double>>(2*n+1);
    }
    else if (denCof->size() != 2*n+1)
    {
        denCof.reset(new std::vector<double>(2*n+1));
    }

    for (size_t k = 0; k < n; ++k)
    {
        parg = M_PI * static_cast<double>(2*k+1) / static_cast<double>(2*n);
        sparg = sin(parg);
        cparg = cos(parg);
        a = 1.0 + s2t * sparg;
        triCofR.at(2*k) = c2t / a;
        triCofR.at(2*k+1) = s2t * cparg / a;
        triCofT.at(2*k) = -2.0 * cp * (ct + st * sparg) / a;
        triCofT.at(2*k+1) = -2.0 * cp * st * cparg / a;
    }

    this->trinomialMult(triCofT, triCofR, tmpCof);

    denCof->at(2) = tmpCof.at(2);
    denCof->at(1) = tmpCof.at(0);
    denCof->at(0) = 1.0;
    for (size_t k = 3; k < 2*n+1; ++k)
    {
        denCof->at(k) = tmpCof.at(2*k-2);
    }

    return *denCof;
}

auto &Butterworth::denCofBS()
{
    double theta;           /// M_PI * (f2f - f1f) / 2.0
    double cp;              /// cosine of phi
    double st;              /// sine of theta
    double ct;              /// cosine of theta
    double s2t;             /// sine of 2*theta
    double c2t;             /// cosine 0f 2*theta
    double parg;            /// pole angle
    double sparg;           /// sine of pole angle
    double cparg;           /// cosine of pole angle
    double a;               /// workspace variables

    cp = cos(M_PI * (f2f + f1f) / 2.0);
    theta = M_PI * (f2f - f1f) / 2.0;
    st = sin(theta);
    ct = cos(theta);
    s2t = 2.0 * st * ct;        // sine of 2*theta
    c2t = 2.0 * ct * ct - 1.0;  // cosine 0f 2*theta


    /// trinomial coefficients
    std::vector<double> triCofR(2*n);   /// z^-2 coefficients
    std::vector<double> triCofT(2*n);   /// z^-1 coefficients
    std::vector<double> tmpCof(4*n);    /// trinomial results

    if (!denCof)
    {
        denCof = std::make_shared<std::vector<double>>(2*n+1);
    }
    else if (denCof->size() != 2*n+1)
    {
        denCof.reset(new std::vector<double>(2*n+1));
    }

    for (size_t k = 0; k < n; ++k)
    {
        parg = M_PI * static_cast<double>(2*k+1) / static_cast<double>(2*n);
        sparg = sin(parg);
        cparg = cos(parg);
        a = 1.0 + s2t * sparg;
        triCofR.at(2*k) = c2t / a;
        triCofR.at(2*k+1) = -s2t * cparg / a;
        triCofT.at(2*k) = -2.0 * cp * (ct + st * sparg) / a;
        triCofT.at(2*k+1) = 2.0 * cp * st * cparg / a;
    }

    this->trinomialMult(triCofT, triCofR, tmpCof);

    denCof->at(2) = tmpCof.at(2);
    denCof->at(1) = tmpCof.at(0);
    denCof->at(0) = 1.0;
    for (size_t k = 3; k < 2*n+1; ++k)
    {
        denCof->at(k) = tmpCof.at(2*k-2);
    }

    return *denCof;
}

////////////////////////////////////////////////////////////////////////////////
//                                  Numerator                                 //
////////////////////////////////////////////////////////////////////////////////

auto &Butterworth::numCofLP()
{
    if (!numCof)
    {
        numCof = std::make_shared<std::vector<double>>(n+1);
    }
    else if (numCof->size() != n+1)
    {
        numCof.reset(new std::vector<double>(n+1));
    }

    numCof->at(0) = 1.0;
    numCof->at(1) = static_cast<double>(n);

    for (size_t i = 2; i <= n/2; ++i)
    {
        numCof->at(i) = static_cast<double>(n-i+1) * numCof->at(i-1) / static_cast<double>(i);
        numCof->at(n-i) = numCof->at(i);
    }

    numCof->at(n-1) = static_cast<double>(n);
    numCof->at(n) = 1.0;

    return *numCof;
}

auto &Butterworth::numCofHP()
{
    if (!numCof)
    {
        numCof = std::make_shared<std::vector<double>>(n+1);
    }
    else if (numCof->size() != n+1)
    {
        numCof.reset(new std::vector<double>(n+1));
    }

    *numCof = this->numCofLP();

    for (size_t i = 0; i < numCof->size(); ++i)
    {
        if (i % 2)
        {
            numCof->at(i) = -numCof->at(i);
        }
    }

    return *numCof;
}

auto &Butterworth::numCofBP()
{
    std::vector<double> tmpNum;

    tmpNum = this->numCofHP();

    if (!numCof)
    {
        numCof = std::make_shared<std::vector<double>>(2*n+1);
    }
    else if (numCof->size() != 2*n+1)
    {
        numCof.reset(new std::vector<double>(2*n+1));
    }

    for (size_t i = 0; i < n; ++i)
    {
        numCof->at(2*i) = tmpNum.at(i);
        numCof->at(2*i+1) = 0.0;
    }
    numCof->at(2*n) = tmpNum.at(n);

    return *numCof;
}

auto &Butterworth::numCofBS()
{
    double alpha = -2.0 * cos(M_PI * (f2f + f1f) / 2.0) / cos(M_PI * (f2f - f1f) / 2.0);

    if (!numCof)
    {
        numCof = std::make_shared<std::vector<double>>(2*n+1);
    }
    else if (numCof->size() != 2*n+1)
    {
        numCof.reset(new std::vector<double>(2*n+1));
    }

    numCof->at(0) = 1.0;
    numCof->at(2) = 1.0;
    numCof->at(1) = alpha;

    for (size_t i = 1; i < n; ++i)
    {
        numCof->at(2*i+2) += numCof->at(2*i);
        for (size_t j = 2*i; j > 1; --j)
        {
            numCof->at(j+1) += alpha * numCof->at(j) + numCof->at(j-1);
        }

        numCof->at(2) += alpha * numCof->at(1) + 1.0;
        numCof->at(1) += alpha;
    }

    return *numCof;
}

////////////////////////////////////////////////////////////////////////////////
//                                  Comptuion                                 //
////////////////////////////////////////////////////////////////////////////////

void Butterworth::computeCoeffs()
{
    if (den.empty() || num.empty())
    {
        try
        {
            if (type == "low")
            {
                num = this->numCofLP();
                den = this->denCofLP();

                /// Scale Factor
                double sf = this->scaleFactorLP();

                for (auto& it : num)
                {
                    it *= sf;
                }
            }
            else if (type == "high")
            {
                num = this->numCofHP();
                den = this->denCofHP();

                /// Scale Factor
                double sf = this->scaleFactorHP();

                for (auto& it : num)
                {
                    it *= sf;
                }
            }
            else if (type == "pass")
            {
                num = this->numCofBP();
                den = this->denCofBP();

                /// Scale Factor
                double sf = this->scaleFactorBP();

                for (auto& it : num)
                {
                    it *= sf;
                }
            }
            else if (type == "stop")
            {
                num = this->numCofBS();
                den = this->denCofBS();

                /// Scale Factor
                double sf = this->scaleFactorBS();

                for (auto& it : num)
                {
                    it *= sf;
                }
            }
            else
            {
                throw std::runtime_error("Unknown filter type in Butterworth::filter()\n");
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << "error: Butterworth '" << type << "' try .at('low' | 'high')" << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
//                              Filter Arithmetic                             //
////////////////////////////////////////////////////////////////////////////////

void Butterworth::filter(const std::vector<double> &src, std::vector<double> &dest)
{
    /// Filter Coeffs
    this->computeCoeffs();

    if (dest.size() != src.size())
    {
        dest.resize(src.size());
    }

    /// Filter Arithmetic
    dest.at(0) = num.at(0) * src.at(0);

    for (size_t i = 1; i < n+1; ++i)
    {
        dest.at(i) = 0.0;

        for (size_t j = 0; j < i+1; ++j)
        {
            dest.at(i) = dest.at(i) + num.at(j)*src.at(i-j);
        }

        for (size_t j = 0; j < i; ++j)
        {
            dest.at(i) = dest.at(i) - den.at(j+1)*dest.at(i-j-1);
        }
    }

    for (size_t i = n+1; i < src.size(); ++i)
    {
        dest.at(i) = 0.0;

        for (size_t j = 0; j < n+1; ++j)
        {
                dest.at(i) = dest.at(i) + num.at(j)*src.at(i-j);
        }

        for (size_t j = 0; j < n; ++j)
        {
                dest.at(i) = dest.at(i) - den.at(j+1)*dest.at(i-j-1);
        }
    }
}

void Butterworth::filtfilt(std::vector<double> &src, std::vector<double> &dest)
{
    if (dest.size() != src.size())
    {
        dest.resize(src.size());

    }

    this->filter(src, dest);

    for (size_t i = 0; i < src.size(); ++i)
    {
        src.at(i) = dest.at(src.size()-i-1);
    }

    this->filter(src, dest);

    for (size_t i = 0; i < src.size(); ++i)
    {
        src.at(i) = dest.at(src.size()-i-1);
    }

    dest = src;
}

////////////////////////////////////////////////////////////////////////////////
//                               Member Functions                             //
////////////////////////////////////////////////////////////////////////////////

std::string &Butterworth::getType()
{
    return this->type;
}

void Butterworth::setType(const std::string type)
{
    if (!den.empty() || !num.empty())
    {
        den.clear();
        num.clear();
    }

    this->type = type;
}

size_t &Butterworth::getOrder()
{
    return n;
}

void Butterworth::setOrder(size_t order)
{
    if (!den.empty() || !num.empty())
    {
        den.clear();
        num.clear();
    }

    n = order;
}

double &Butterworth::getCutFreqC()
{
    return this->fcf;
}

double &Butterworth::getCutFreq1()
{
    return this->f1f;
}

double &Butterworth::getCutFreq2()
{
    return this->f2f;
}

void Butterworth::setCutFreqC(double coeff)
{
    if (!den.empty() || !num.empty())
    {
        den.clear();
        num.clear();
    }

    this->fcf = coeff;
}

void Butterworth::setCutFreq1(double coeff)
{
    if (!den.empty() || !num.empty())
    {
        den.clear();
        num.clear();
    }

    this->f1f = coeff;
}

void Butterworth::setCutFreq2(double coeff)
{
    if (!den.empty() || !num.empty())
    {
        den.clear();
        num.clear();
    }

    this->f2f = coeff;
}

} /// SENTENZ

/*
 * Version 1.01
 *
*/

#ifndef CSV_HPP
#define CSV_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>		// std::istringstream
#include <cstring>		// std::stod
#include <vector>
#include <utility>		// std::pair
#include <map>
#include <tuple>
#include <algorithm>	// std::isalpha
#include <iterator>

#include <boost/range/algorithm/find.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

namespace Sentenz
{

using namespace boost::filesystem;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//                              CSV Reader                                    //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
//  // Initialize
//  CSV csv("Schlusskurs", ';');
//
//  // Read Database (3D vector of string`s)
//  csv.read("/home/sentenz/Sentenz/Trader/tmp/Electronic");
//
//  // Get Datas (2D vector of double`S)
//  auto compDatabase = csv.getData(int period, int pastDays, const std::string format);
//
//  // Get Filenames (2D vector of string`s)
//  auto csvFilenames(csv.getFilename());
//
//  // Get Position of Share (int)
//  auto pos = csv.getIndexOf("Lenovo");
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

    class CSV
    {
    public:
        CSV() = default;
        CSV(const auto &c_, const auto &s_) : column(c_), separator(s_) {}
        ~CSV() = default;
        CSV(const CSV&) = delete;
        const CSV &operator=(const CSV&);

        // Read
        void read(const path &directory);

        // Get : Database
        inline auto &getDatabase(void);
        // Get : Columns
        void getColumn(void);
        // Get : Compared Datas
        std::vector<std::vector<double>> &getData(const size_t period, size_t days, const std::string &format);
        // Get : Filename
        inline auto &getFilename(void);
        // Get : Index of a Share
        int getIndex(const std::string &name);
        int getIndex(auto const &vector, auto const &string);

        // Set
        void setInit(const std::string &c, const char &s);

        // Show Files
        void showFiles(const path &directory, bool recurse_into_subdirs);

    private:
        std::vector<std::vector<std::vector<std::string>>> database;
        std::map<size_t, std::map<std::string, double>> columnsDatabase;
        std::vector<std::vector<double>> comparedDatas;
        std::string basename(std::string &path);    // Filename determination
        std::vector<std::string> filename;
        std::string column;
        char separator;
    };

} /// SENTENZ

//#include "CSV.cpp"

#endif /// CSV_HPP

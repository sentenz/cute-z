#include <iostream>
#include <exception>
#include <fstream>
#include <sstream>		// std::istringstream
#include <cstring>		// std::string, std::stod
#include <vector>		// std::vector
#include <utility>		// std::pair
#include <map>			// std::map
#include <tuple>		// std::tuple
#include <algorithm>    // std::isalpha, find, distance, search
#include <iterator>

#include <boost/algorithm/string.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>

#include "CSV.hpp"

#include <QTime>

namespace Sentenz
{

using namespace boost::filesystem;

////////////////////////////////////////////////////////////////////////////////
//                              Reader                                        //
////////////////////////////////////////////////////////////////////////////////

    void CSV::read(const path &directory)
    {
        try
        {
            if (!exists(directory))
            {
                throw std::runtime_error("CSV::read(): Path error!");
            }

            directory_iterator end;

            for (directory_iterator it(directory); it != end ; ++it)
            {
                if (!is_directory(*it))
                {
                    // Convert from boost:: to fstream
                    const directory_entry& entry = *it;
                    std::string path = entry.path().string();
                    std::fstream file(path, std::ios::in);

                    // Check filepath
                    if (!file.is_open())
                    {
                        throw std::runtime_error("Reader: File not found!");
                    }

                    // Catch filename
                    filename.push_back(this->basename(path));

                    // Catch data
                    std::vector<std::vector<std::string>> csvUnit;
                    // Read every line from the stream
                    std::string csvLine;

                    while (std::getline(file, csvLine))
                    {
                        std::istringstream csvStream(csvLine);
                        // Read every element from the line that is seperated by commas/semicolon
                        std::vector<std::string> csvRow;
                        std::string csvCol;

                        while (std::getline(csvStream, csvCol, separator))
                        {
                            csvRow.push_back(csvCol);
                        }

                        csvUnit.push_back(csvRow);
                    }

                    database.push_back(csvUnit);
                }
            }
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }

////////////////////////////////////////////////////////////////////////////////
//                              Get Columns                                   //
////////////////////////////////////////////////////////////////////////////////

    void CSV::getColumn(void)
    {
        try
        {
            if (database.empty())
            {
                throw std::runtime_error("CSV::getColumn(): File is empty!");
            }

            // Init::Row increment
            size_t i = 0;

            for (auto &it : database)
            {
                // Find index of the desired column
                int index = -1;

                for (auto &itx : it)
                {
                    index = this->getIndex(itx, column);

                    if (index >= 0)
                    {
                        break;
                    }
                }

                if (index < 0)
                {
                    throw std::runtime_error("CSV::getColumn(): Could not find Column!");
                }

                // Column seperation
                for (auto &iter : it)
                {
                    // Store key (date) and this associative value
                    if (isdigit(iter.front().front()))
                    {
                        iter.at(index).erase(std::remove(iter.at(index).begin(), iter.at(index).end(), ' '), iter.at(index).end());
                        iter.at(index).erase(std::remove(iter.at(index).begin(), iter.at(index).end(), '.'), iter.at(index).end());
                        std::replace(iter.at(index).begin(), iter.at(index).end(), ',', '.');

                        columnsDatabase[i].emplace(std::make_pair(iter.front().c_str(), std::stod(iter.at(index))));
                    }
                }
                i++;
            }
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }

////////////////////////////////////////////////////////////////////////////////
//                           Get Compared Datas                               //
////////////////////////////////////////////////////////////////////////////////

    std::vector<std::vector<double>> &CSV::getData(const size_t period, size_t days, const std::string &format)
    {
        try
        {
            QString pastDate;

            this->getColumn();

            comparedDatas.resize(columnsDatabase.size(), std::vector<double>(period, 0.));

            for (size_t i = 0; i < columnsDatabase.size(); ++i)
            {
                for (size_t j = 0, count = 0; count < period; ++j)
                {
                    pastDate = QDate::currentDate().addDays(static_cast<int>(days-j)).toString(format.c_str());

                    if (QDate::fromString(pastDate, format.c_str()).dayOfWeek() != 6 && QDate::fromString(pastDate, format.c_str()).dayOfWeek() != 7)
                    {
                        if (columnsDatabase.at(i)[pastDate.toStdString()] != 0)
                        {
                            comparedDatas.at(i).at(count) = columnsDatabase.at(i).find(pastDate.toStdString())->second;
                            count++;
                        }
                        else
                        {
                            comparedDatas.at(i).at(count) = count > 0 ? comparedDatas.at(i).at(count-1) : comparedDatas.at(i).at(count);
                            count++;
                        }
                    }
                }
            }
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }

        return comparedDatas;
    }


////////////////////////////////////////////////////////////////////////////////
//                              Get Database                                  //
////////////////////////////////////////////////////////////////////////////////

    inline auto &CSV::getDatabase(void)
    {
        return database;
    }

////////////////////////////////////////////////////////////////////////////////
//                              Get Filename                                  //
////////////////////////////////////////////////////////////////////////////////

    inline auto &CSV::getFilename(void)
    {
        return filename;
    }

////////////////////////////////////////////////////////////////////////////////
//                          Get Index of a Share                              //
////////////////////////////////////////////////////////////////////////////////

    int CSV::getIndex(const std::string &string)
    {
        try
        {
            if (string.empty())
            {
                throw std::runtime_error("CSV::getIndex(): Empty string!");
            }

            auto it = find(filename.begin(), filename.end(), string);

            if (it != filename.end())
            {
                return std::distance(filename.begin(), it);
            }
            else
            {
                throw std::runtime_error("CSV::getIndex(): Failed string!");
            }
        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }


    int CSV::getIndex(auto const &vector, auto const &string)
    {
        try
        {
            if (vector.empty() || string.empty())
            {
                throw std::runtime_error("CSV::getIndex(): Empty inputs!");
            }

            auto it = find(vector.begin(), vector.end(), string);

            if (it != vector.end())
            {
                return std::distance(vector.begin(), it);
            }
            else
            {
                return -1;
            }

        }
        catch(std::exception& e)
        {
            std::cerr << "exception caught: " << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "warning: issua occurred" << std::endl;
        }
    }

////////////////////////////////////////////////////////////////////////////////
//                            Set Initialize                                  //
////////////////////////////////////////////////////////////////////////////////

    void CSV::setInit(const std::string &c, const char &s)
    {
        column = c;
        separator = s;
    }

////////////////////////////////////////////////////////////////////////////////
//                              Catch Filename                                //
////////////////////////////////////////////////////////////////////////////////

    std::string CSV::basename(std::string &path)
    {
        std::replace(path.begin(), path.end(), '\\', '/');

        //#if defined(_WIN32) || defined(_WIN64)
            //std::string::const_reverse_iterator pivotb = std::find(path.rbegin(), path.rend(), '\\');
        //#elif defined(__linux__) || defined(__unix__)
            std::string::const_reverse_iterator pivotb = std::find(path.rbegin(), path.rend(), '/');
        //#endif
        std::string::const_reverse_iterator pivote = std::find(path.rbegin(), path.rend(), '.');

        return pivote == path.rend() ? path : std::string(pivotb.base(), pivote.base()-1);
    }


////////////////////////////////////////////////////////////////////////////////
//                              Show Files                                    //
////////////////////////////////////////////////////////////////////////////////

    void CSV::showFiles(const path &directory, bool recurse_into_subdirs)
    {
        if (exists(directory))
        {
            directory_iterator end;

            for (directory_iterator iter(directory); iter != end ; ++iter)
            {
                // Directory
                if (is_directory(*iter))
                {
                    std::cout << *iter << std::endl;

                    if (recurse_into_subdirs)
                    {
                        showFiles(*iter, true);
                    }
                }
                // Files
                else
                {
                    std::cout << *iter << std::endl;
                }
            }
        }
    }

} // SENTENZ

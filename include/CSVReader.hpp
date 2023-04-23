#ifndef CSVREADER_HPP
#define CSVREADER_HPP

//#include <iterator>
//#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

namespace Utilities
{

class Row
{
public:
    std::string_view operator[](std::size_t index) const;
    std::size_t getDimensions() const;
    void readNextRow(std::istream& str);
private:
    std::string m_line;
    std::vector<float> m_data;
};

inline std::istream& operator>>(std::istream& str, Row& data);

class CSVReader
{
public:
    CSVReader(const std::string& file_path);
    std::istream& getNextRow(Row& data);
    void reset();
    ~CSVReader();
private:
    std::ifstream file_;
    Row row_;
};

} // Namespace Utilities
#endif
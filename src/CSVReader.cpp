#include "CSVReader.hpp"

namespace Utilities
{

std::string_view Row::operator[](std::size_t index) const {
    // Use m_data to map from index to speicifc slice of string
    return std::string_view(&m_line[m_data[index] + 1], m_data[index + 1] -  (m_data[index] + 1));
}

std::size_t Row::getDimensions() const {
    return m_data.size() - 1;
}

void Row::readNextRow(std::istream& str) {
    std::getline(str, m_line);
    m_data.clear();
    m_data.emplace_back(-1);
    std::string::size_type pos = 0;
    while((pos = m_line.find(',', pos)) != std::string::npos) {
        m_data.emplace_back(pos);
        ++pos;
    }
    pos   = m_line.size();
    m_data.emplace_back(pos);
}

std::istream& operator>>(std::istream& str, Row& data) {
    data.readNextRow(str);
    return str;
}

CSVReader::CSVReader(const std::string& file_path)
    : file_(file_path)
{
    if(!file_.good()) {
        throw std::runtime_error("Could not open file at: " + file_path);
    }
}

std::istream& CSVReader::getNextRow(Row& data) {
    file_ >> data;
    return file_;
}

void CSVReader::reset() {
    file_.clear();                 // clear fail and eof bits
    file_.seekg(0, std::ios::beg);
}

CSVReader::~CSVReader() {
    file_.close();
}

} // Namespace Utilities
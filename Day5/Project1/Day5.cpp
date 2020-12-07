#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using RNG = std::pair<int, int>;

bool loadFromFile(const std::string& fileName, std::vector<std::string>& numPool)
{
    std::string buffer;
    std::ifstream infile;
    infile.open(fileName);

    if (!infile.is_open()) {
        std::cout << "Sorry, this file could not be opened.";
        return false;
    }

    while (!infile.eof()) {
        getline(infile, buffer);
        numPool.push_back(buffer);
    }
    infile.close();
    return true;
}

int divTree(RNG& range, const char ref)
{
    int size = (range.second - range.first) + 1;
    int midpoint = size >> 1;

    switch (ref) 
    {
        case 'F':
        case 'L':
            range.second -= midpoint;
        break;

        case 'B':
        case 'R':
            range.first += midpoint;
        break;
    }

    return midpoint;
}

int main()
{
    std::vector<std::string> pool;
    std::string fileName = "in.txt";
    int maxVal{};

    loadFromFile(fileName, pool);

    for (auto const& str : pool) {
        RNG row{ 0,127 };
        RNG seat{ 0,7 };

        std::string rowKey = str.substr(0,7);
        std::string seatKey = str.substr(7, 3);

        for (char const& c : rowKey) {
            divTree(row, c);
        }        
        
        int rowVal = row.first;
 
        for (char const& c : seatKey) {
            divTree(seat, c);
        }

        int seatVal = seat.first;

        int seatID = (rowVal * 8) + seatVal;
        if (seatID > maxVal)
            maxVal = seatID;

        if (row.first != row.second)
            std::cout << "**ERROR ERROR**  " << row.first << "  " << row.second << std::endl;        
        if (seat.first != seat.second)
            std::cout << "**ERROR ERROR**  " << seat.first << "  " << seat.second << std::endl;

        std::cout << str << "  " << "seatID: " << seatID << " row: " << rowVal << " seat: " << seatVal << std::endl;
    }

    std::cout << maxVal;
}


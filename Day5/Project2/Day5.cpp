#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

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

    return range.first;
}

int main()
{
    std::vector<int> sid;
    std::vector<std::string> pool;
    std::string fileName = "in.txt";

    loadFromFile(fileName, pool);

    for (auto const& str : pool) {
        RNG row{ 0,127 };
        RNG seat{ 0,7 };

        std::string rowKey = str.substr(0, 7);
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

        sid.push_back(seatID);
    }
    std::sort(sid.begin(), sid.end());

    for (int i = 0; i < sid.size() - 1; i++)
        if (sid[i] + 1 != sid[i + 1])
        {
            RNG seatNum{ sid[i],sid[i + 1] };
            std::cout << sid[i] << "  * " << divTree(seatNum, 'B') << " *  " << sid[i + 1] << "\n";
        }
}


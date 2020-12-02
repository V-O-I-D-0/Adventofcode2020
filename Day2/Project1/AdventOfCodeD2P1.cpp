#include <iostream>
#include <vector>
#include <sstream>
#include <strstream>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int fintArray[1] = {};
    int sintArray[1] = {};
    string strArray[3] = {};
    string sFilename;

    vector<int>firstNum;
    vector<int>secNum;
    vector<string>strGvn;
    vector<string>psswrd;

    int correctPass = 0;

    regex rmvC("[:]");

    cout << "Filename: ";
    cin >> sFilename;

    char junk;

    ifstream f(sFilename);
    if (!f.is_open()) {
        return false;
    }
    while (!f.eof()) 
    {
        char line[128];
        f.getline(line, 128);

        strstream s;
        s << line;
        s >> fintArray[0] >> sintArray[0];
        s >> strArray[0] >> strArray[1] >> strArray[2];

        stringstream result;
        regex_replace(ostream_iterator<char>(result), strArray[0].begin(), strArray[0].end(), rmvC, "");
            
        result >> strArray[0];

        firstNum.push_back(fintArray[0]);
        secNum.push_back(abs(sintArray[0]));
        strGvn.push_back(strArray[0]);
        psswrd.push_back(strArray[1] + strArray[2]);
    }

    int iLength;
    int cLength;
    int fNum;
    int sNum;
    string pass;
    string sChar;
    char fChar;

    for (int i = 0; i < 1000; i++) {
        pass = psswrd[i];
        sChar = strGvn[i];
        fChar = sChar[0];
        fNum = firstNum[i];
        sNum = secNum[i];
        
        pass.erase(remove(pass.begin(), pass.end(), fChar), pass.end());
        cout << "Char used: " << fChar << endl;
        cout << psswrd[i] << " " << pass << endl;

        iLength = pass.length();
        cLength = psswrd[i].length() - iLength;
        cout << "Original length: " << psswrd[i].length() << "\n" << "Subtract: " << iLength << "\n" << "Final length: " << cLength << "\n" << "Between: " << fNum << " - " << sNum << endl;

        if (cLength >= fNum && cLength <= sNum) 
        {
            correctPass = correctPass + 1;
            cout << "Between lengths? " << "true" << "\n";
            cout << "Count: " << correctPass << "\n" << endl;
        }
        else {
            cout << "Between lengths? " << "false" << "\n";
            cout << "Count: " << correctPass << "\n" << endl;
        }

    }

    cout << "\n" << "Final Count: " << correctPass << "\n";
}

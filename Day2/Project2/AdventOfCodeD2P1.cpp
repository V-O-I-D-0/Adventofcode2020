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

    int lineCount = 0;
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

    int fNum;
    int sNum;
    string pass;
    string stringChar;
    char fChar;
    int count = 0;

    for (int i = 0; i < 1000; i++) {
        pass = psswrd[i];
        cout << "Password: " << pass << endl;

        fNum = firstNum[i] - 1;
        sNum = secNum[i] - 1;

        stringChar = strGvn[i];
        fChar = stringChar[0];
        cout << "Char: " << fChar << endl;
        cout << "first: " << fNum + 1 << "\n" << "second: " << sNum + 1 << endl;
        
        //cout << sChar << endl;
        if (!(pass[fNum] == fChar) != !(pass[sNum] == fChar)) 
        {
            count++;
            cout << "Count: " << count << "\n" << endl;
        }
        else 
        {

            cout << "Count: " << count << "\n" << endl;
        }

    }
    
    cout << count ;

}

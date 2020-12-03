#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool returnVec(std::string fileName, std::vector<std::string>& vecOfStrs) 
{
    std::ifstream in(fileName.c_str());
        
    if (!in) 
    {
        cout << "Sorry, the file could not be opened." << endl;
        return false;
    }
    
    std::string str;

        while (getline(in, str)) 
        {
            if (str.size() > 0) 
            {
                vecOfStrs.push_back(str);
            }
        }

        in.close();
}

int main()
{
    string fileName;
    cout << "Input file name: ";
    cin >> fileName;

    vector<string>mtnLines;

    bool result = returnVec(fileName, mtnLines);

    if (result)
    {
        for (string& line : mtnLines)
        {
        }
    }
    
    char tree = '#';
    string mtn;

    int length = mtnLines[0].length();
    int counter = 0;
    int iC;
    int xPos = 0;
    int yPos = 0;
    //0 - 30

    for (int i = 0; i < (mtnLines.size()*2) - 2; i++)
    {
        iC = i;
        yPos = yPos + 1;
        xPos = xPos + 3;

        if (xPos > (mtnLines[0].length()-1)) 
        {
            xPos = xPos - length;
        }

        mtn = mtnLines[yPos];

        
        if (mtn[xPos] == tree) 
        {
            mtn[xPos] = '0';
            counter = counter + 1;
        }
        else 
        {
            mtn[xPos] = 'X';
        }
        cout << iC << "   " << mtn << "   " << counter << endl;
        i = i + 1;
    }
    
    //cout << counter << endl;
    return 0;
}


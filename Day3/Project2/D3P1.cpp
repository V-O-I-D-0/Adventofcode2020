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
        std::cout << "Sorry, the file could not be opened." << endl;
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
    std::cout << "Input file name: ";
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
    vector<double>dCounts;
    int  dCount = 1;
    double ddCount = 1.0;

    int iC;
    int xPos = 0;
    int yPos = 0;

    int slopeX[5] = {1,3,5,7,1};
    int slopeY[5] = {1,1,1,1,2};


    for (int h = 0; h < 5; h++) {

        std::cout << "1   " << mtnLines[0] << "   Count: 0" << "\n";
        for (int i = 0; i < (mtnLines.size() * (2/slopeY[h])) - 2; i++)
        {
            iC = i;
            xPos = xPos + slopeX[h];
            yPos = yPos + slopeY[h];

            if (xPos > (mtnLines[yPos].length() - 1))
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
            std::cout << (iC / (2/slopeY[h])) + 2 << "   " << mtn << "   " << "Count: " << counter << endl;
            i = i + 1;
        }
        dCount = dCount * counter;

        //dCounts.push_back(counter * 1.0);
        counter = 0;
        xPos = 0;
        yPos = 0;

        std::cout << "\n" << "Itr count: " << h + 1 << "\n" << endl;
    }
    

    //for (int i = 0; i < 5; i++) 
    //{
    //    ddCount = ddCount * dCounts[i];
    //    std::cout << i + 1 << ": " << dCounts[i] << endl;
    //}

    std::cout << "\n" << "Final count: " << dCount << endl;
    return 0;
}


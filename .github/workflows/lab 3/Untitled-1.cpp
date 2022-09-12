#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string HSN;
    int score;
    int HS = 0;
    std::string line;
    ifstream myfile("scores.txt");
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            std::stringstream linestream(line);
            std::string data;
            std::getline(linestream, data, ':');
            linestream >> score;
            if (score > HS)
            {
                HS = score;
                HSN = line;
            }
            
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";

    cout << HSN;
}

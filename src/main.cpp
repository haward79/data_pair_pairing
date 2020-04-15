#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

int main()
{
    ifstream fin("simp.csv");
    ofstream fout("output.csv");
    string lineStr, id = "", values[25];
    int order;
    int sp1Index, sp2Index;
    
    while(getline(fin, lineStr))
    {
        if(lineStr == "")
            continue;

        sp1Index = lineStr.find(",");
        lineStr[sp1Index] = ' ';
        sp2Index = lineStr.find(",");

        // Different person.
        if(id != lineStr.substr(0, sp1Index))
        {
            // Output.
            if(id != "")
            {
                fout << id;
                cout << id;

                for(int i=0; i<25; ++i)
                {
                    fout << "," << values[i];
                    cout << "," << values[i];

                    values[i] = "";
                }

                fout << "\n";
                cout << "\n";
            }

            // Reset.
            id = lineStr.substr(0, sp1Index);
        }

        cout << lineStr.substr(sp2Index + 1) << "\n";
        order = std::stoi(lineStr.substr(sp2Index + 1));
        values[order] = lineStr.substr(sp1Index + 1, sp2Index - sp1Index - 1);
    }

    if(id != "")
    {
        fout << id;
        cout << id;

        for(int i=0; i<25; ++i)
        {
            fout << "," << values[i];
            cout << "," << values[i];

            values[i] = "";
        }

        fout << "\n";
        cout << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}


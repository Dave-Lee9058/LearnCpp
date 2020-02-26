#include <iostream>
#include <fstream>

using namespace std;

#if 1

int main()
{
    std::ifstream fin;
    std::ofstream fout;    

    fin.open("test.bmp", std::ios::binary);
    fout.open("copy.bmp", std::ios::binary);

    fin.seekg(0, std::ios::end); // seekg()를 이용하여 포인터를 마지막 포인터로 옮긴다.

    int sz = fin.tellg(); // tellg()를 이용하여 사아즈를 구한다. 
    std::cout << "size : " << sz << '\n';

    char *buf = new char[sz];

    fin.seekg(0, std::ios::beg);

    fin.read(buf, sz);

    fout.write(buf, sz);

    delete[] buf;

    fin.close();
    fout.close();   
    
    return 0;
}

#endif

#if 0

int main()
{
    std::string filePath = "test.txt";

    std::ofstream writeFile(filePath.data());

    if(writeFile.is_open())
    {
        writeFile << "Hello World! \n";
        writeFile << "This is c++ file contents. \n";
        writeFile.close();
    }

    ifstream openFile(filePath.data());

    if(openFile.is_open())
    {
        std::string line;

        while(std::getline(openFile, line))
        {
            std::cout << line << '\n';
        }

        openFile.close();
    }

    return 0;
}

#endif
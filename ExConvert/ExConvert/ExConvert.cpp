#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#ifdef _WIN32
#include <windows.h>
#endif
int main()
{
    while (1)
    {
#ifdef _WIN32
        SetConsoleTitleA("ExConvert by Veress Bence Gyula - 2022");
#endif
        std::string input;
        std::cout << "Enter the number of size, source unit and target unit or leave blank to exit!\nUppercase, lowercase, and spaces don't matter!\nBytes: BY, KB, MB, GB, TB, PB, EB, ZB, YB\nExords: EX, KE, ME, GE, TE, PE, EE, ZE, YE\n1 exord = " + std::to_string(sizeof(EXF)) + " bytes\nExample: 1.5 gb - me\nInput: ";
        std::getline(std::cin, input);
        if (input == "")
        {
            exit(0);
        }
        std::cout << "\nBytes normally use 1000 but 1024 in binary (kibi, mebi, etc...), please choose which one do you want to use at bytes\n1 - Use normal (1000)\n2 - Use binary (1024)\n\nbytec: ";
        int bytec;
        std::cin >> bytec;
        if (bytec == 1)
        {
            bytec = 1000;
        }
        else if (bytec == 2)
        {
            bytec = 1024;
        }
        else
        {
            std::cout << "Invalid choice!\n";
            bytec = 1000;
        }
        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        std::transform(input.begin(), input.end(), input.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
        std::string source = input.substr(0, input.find('-'));
        std::string unit_target = input.substr(input.find('-') + 1);
        std::string unit_source = source.substr(source.size() - 2, 2);
        source.erase(source.size() - 2, 2);
        std::cout << "Converting " << source << " " << unit_source << " to " << unit_target << std::endl;
        long double bytes = 0;
        if (unit_source == "by")
        {
            bytes = std::stold(source);
        }
        else if (unit_source == "kb")
        {
            bytes = std::stold(source) * bytec;
        }
        else if (unit_source == "mb")
        {
            bytes = std::stold(source) * bytec * bytec;
        }
        else if (unit_source == "gb")
        {
            bytes = std::stold(source) * bytec * bytec * bytec;
        }
        else if (unit_source == "tb")
        {
            bytes = std::stold(source) * bytec * bytec * bytec * bytec;
        }
        else if (unit_source == "pb")
        {
            bytes = std::stold(source) * bytec * bytec * bytec * bytec * bytec;
        }
        else if (unit_source == "eb")
        {
            bytes = std::stold(source) * bytec * bytec * bytec * bytec * bytec * bytec;
        }
        else if (unit_source == "zb")
        {
            bytes = std::stold(source) * bytec * bytec * bytec * bytec * bytec * bytec * bytec;
        }
        else if (unit_source == "yb")
        {
            bytes = std::stold(source) * bytec * bytec * bytec * bytec * bytec * bytec * bytec * bytec;
        }
        else if (unit_source == "ex")
        {
            bytes = std::stold(source) * sizeof(EXF);
        }
        else if (unit_source == "ke")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000;
        }
        else if (unit_source == "me")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000;
        }
        else if (unit_source == "ge")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000 * 1000;
        }
        else if (unit_source == "te")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000 * 1000 * 1000;
        }
        else if (unit_source == "pe")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000 * 1000 * 1000 * 1000;
        }
        else if (unit_source == "ee")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
        }
        else if (unit_source == "ze")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
        }
        else if (unit_source == "ye")
        {
            bytes = std::stold(source) * sizeof(EXF) * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 * 1000;
        }
        else
        {
            std::cout << "Invalid unit!\n";
            return 0;
        }
        if (unit_target == "by")
        {
            std::cout << bytes << " B\n";
        }
        else if (unit_target == "kb")
        {
            std::cout << bytes / bytec << " KB\n";
        }
        else if (unit_target == "mb")
        {
            std::cout << bytes / bytec / bytec << " MB\n";
        }
        else if (unit_target == "gb")
        {
            std::cout << bytes / bytec / bytec / bytec << " GB\n";
        }
        else if (unit_target == "tb")
        {
            std::cout << bytes / bytec / bytec / bytec / bytec << " TB\n";
        }
        else if (unit_target == "pb")
        {
            std::cout << bytes / bytec / bytec / bytec / bytec / bytec << " PB\n";
        }
        else if (unit_target == "eb")
        {
            std::cout << bytes / bytec / bytec / bytec / bytec / bytec / bytec << " EB\n";
        }
        else if (unit_target == "zb")
        {
            std::cout << bytes / bytec / bytec / bytec / bytec / bytec / bytec / bytec << " ZB\n";
        }
        else if (unit_target == "yb")
        {
            std::cout << bytes / bytec / bytec / bytec / bytec / bytec / bytec / bytec / bytec << " YB\n";
        }
        else if (unit_target == "ex")
        {
            std::cout << bytes / sizeof(EXF) << " E\n";
        }
        else if (unit_target == "ke")
        {
            std::cout << bytes / sizeof(EXF) / 1000 << " KE\n";
        }
        else if (unit_target == "me")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 << " ME\n";
        }
        else if (unit_target == "ge")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 / 1000 << " GE\n";
        }
        else if (unit_target == "te")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 / 1000 / 1000 << " TE\n";
        }
        else if (unit_target == "pe")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 / 1000 / 1000 / 1000 << " PE\n";
        }
        else if (unit_target == "ee")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 / 1000 / 1000 / 1000 / 1000 << " EE\n";
        }
        else if (unit_target == "ze")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 / 1000 / 1000 / 1000 / 1000 / 1000 << " ZE\n";
        }
        else if (unit_target == "ye")
        {
            std::cout << bytes / sizeof(EXF) / 1000 / 1000 / 1000 / 1000 / 1000 / 1000 / 1000 / 1000 << " YE\n";
        }
        else
        {
            std::cout << "Invalid unit!\n";
            return 0;
        }
        std::cin.get();
        std::cin.get();
        std::cout << std::endl;
    }
    return 0;
}
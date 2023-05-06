#include <iostream>
#include <cmath>
#include <string>
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
        SetConsoleTitleA("EXConvert by Veress Bence Gyula - 2022");
#endif
        std::string input;
        std::cout << "Enter the number of size, source unit and target unit!\nUppercase, lowercase, and spaces don't matter!\nBytes: BY, KB, MB, GB, TB, PB, EB, ZB, YB\nExords: EX, KE, ME, GE, TE, PE, EE, ZE, YE\nExample: 1.5 gb - me\nInput: ";
        std::getline(std::cin, input);
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
            bytes = std::stold(source) * 1024;
        }
        else if (unit_source == "mb")
        {
            bytes = std::stold(source) * 1024 * 1024;
        }
        else if (unit_source == "gb")
        {
            bytes = std::stold(source) * 1024 * 1024 * 1024;
        }
        else if (unit_source == "tb")
        {
            bytes = std::stold(source) * 1024 * 1024 * 1024 * 1024;
        }
        else if (unit_source == "pb")
        {
            bytes = std::stold(source) * 1024 * 1024 * 1024 * 1024 * 1024;
        }
        else if (unit_source == "eb")
        {
            bytes = std::stold(source) * 1024 * 1024 * 1024 * 1024 * 1024 * 1024;
        }
        else if (unit_source == "zb")
        {
            bytes = std::stold(source) * 1024 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024;
        }
        else if (unit_source == "yb")
        {
            bytes = std::stold(source) * 1024 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024;
        }
        else if (unit_source == "ex")
        {
            bytes = std::stold(source) * 104;
        }
        else if (unit_source == "ke")
        {
            bytes = std::stold(source) * 104 * 5;
        }
        else if (unit_source == "me")
        {
            bytes = std::stold(source) * 104 * 5 * 5;
        }
        else if (unit_source == "ge")
        {
            bytes = std::stold(source) * 104 * 5 * 5 * 5;
        }
        else if (unit_source == "te")
        {
            bytes = std::stold(source) * 104 * 5 * 5 * 5 * 5;
        }
        else if (unit_source == "pe")
        {
            bytes = std::stold(source) * 104 * 5 * 5 * 5 * 5 * 5;
        }
        else if (unit_source == "ee")
        {
            bytes = std::stold(source) * 104 * 5 * 5 * 5 * 5 * 5 * 5;
        }
        else if (unit_source == "ze")
        {
            bytes = std::stold(source) * 104 * 5 * 5 * 5 * 5 * 5 * 5 * 5;
        }
        else if (unit_source == "ye")
        {
            bytes = std::stold(source) * 104 * 5 * 5 * 5 * 5 * 5 * 5 * 5 * 5;
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
            std::cout << bytes / 1024 << " KB\n";
        }
        else if (unit_target == "mb")
        {
            std::cout << bytes / 1024 / 1024 << " MB\n";
        }
        else if (unit_target == "gb")
        {
            std::cout << bytes / 1024 / 1024 / 1024 << " GB\n";
        }
        else if (unit_target == "tb")
        {
            std::cout << bytes / 1024 / 1024 / 1024 / 1024 << " TB\n";
        }
        else if (unit_target == "pb")
        {
            std::cout << bytes / 1024 / 1024 / 1024 / 1024 / 1024 << " PB\n";
        }
        else if (unit_target == "eb")
        {
            std::cout << bytes / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 << " EB\n";
        }
        else if (unit_target == "zb")
        {
            std::cout << bytes / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 << " ZB\n";
        }
        else if (unit_target == "yb")
        {
            std::cout << bytes / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 / 1024 << " YB\n";
        }
        else if (unit_target == "ex")
        {
            std::cout << bytes / 104 << " E\n";
        }
        else if (unit_target == "ke")
        {
            std::cout << bytes / 104 / 5 << " KE\n";
        }
        else if (unit_target == "me")
        {
            std::cout << bytes / 104 / 5 / 5 << " ME\n";
        }
        else if (unit_target == "ge")
        {
            std::cout << bytes / 104 / 5 / 5 / 5 << " GE\n";
        }
        else if (unit_target == "te")
        {
            std::cout << bytes / 104 / 5 / 5 / 5 / 5 << " TE\n";
        }
        else if (unit_target == "pe")
        {
            std::cout << bytes / 104 / 5 / 5 / 5 / 5 / 5 << " PE\n";
        }
        else if (unit_target == "ee")
        {
            std::cout << bytes / 104 / 5 / 5 / 5 / 5 / 5 / 5 << " EE\n";
        }
        else if (unit_target == "ze")
        {
            std::cout << bytes / 104 / 5 / 5 / 5 / 5 / 5 / 5 / 5 << " ZE\n";
        }
        else if (unit_target == "ye")
        {
            std::cout << bytes / 104 / 5 / 5 / 5 / 5 / 5 / 5 / 5 / 5 << " YE\n";
        }
        else
        {
            std::cout << "Invalid unit!\n";
            return 0;
        }
        std::cin.get();
        std::cout << std::endl;
    }
    return 0;
}
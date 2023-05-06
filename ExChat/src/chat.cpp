#include "D:\Dev\ExCpp\ExCpp.h"
#include <chrono>
#include <thread>
int main()
{
    std::cout << "ExChat by Veress Bence Gyula 2022 - Chat viewer\n------------------------------------------\n";
    std::string file;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file);
    while (true)
    {
        system("cls");
        std::cout << "ExChat by Veress Bence Gyula 2022 - Chat viewer\n------------------------------------------\n";
        std::ifstream chat(file);
        std::string line;
        while (std::getline(chat, line))
        {
            std::cout << line << std::endl;
        }
        chat.close();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
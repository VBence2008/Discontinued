#include "D:\Dev\ExCpp\ExCpp.h"
#include <chrono>
bool SendMessage(std::string file, std::string message)
{
    std::ofstream chat(file, std::ios::app);
    chat << message << std::endl;
    chat.close();
    return true;
}
std::string Time()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%X");
    return ss.str();
}
int main()
{
    std::cout << "ExChat by Veress Bence Gyula 2022 - Message sender\n--------------------------------------------------\n";
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    std::string file;
    std::cout << "Enter the file name: ";
    std::getline(std::cin, file);
    std::string prefix;
    std::cout << "Enter the command prefix: ";
    std::getline(std::cin, prefix);
    if (!std::ifstream(file))
    {
        std::ofstream chat(file);
        chat << "Welcome to " << file << "!" << std::endl;
        chat.close();
    }
    system("cls");
    while (true)
    {
        system("cls");
        std::cout << "ExChat by Veress Bence Gyula 2022 - Message sender\n--------------------------------------------------\n";
        std::cout << "Registered as " << username << std::endl;
        std::string message;
        std::cout << "Enter your message: ";
        std::getline(std::cin, message);
        SendMessage(file, Time() + " " + username + ": " + message);
        if (message == prefix + "exit")
        {
            SendMessage(file, Time() + " " + username + " left the chat.");
            break;
        }
        else if (message == prefix + "clear")
        {
            std::ofstream chat(file);
            chat << "Welcome to " << file << "!" << std::endl;
            chat.close();
        }
        else if (message == prefix + "prefix")
            system("cls");
    }
    return 0;
}
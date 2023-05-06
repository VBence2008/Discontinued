#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <cstdlib>
int main()
{
	SetConsoleTitle(TEXT("ExPC-100"));
	system("cls");
	std::cout << "ExPC-100\nVeress Bence Gyula 2021-2022\nStarting..." << std::endl;
	bool exlerr = 1;
	std::string temp = "C:\\Ex\\ExPC\\100\\sys\\";
	std::ifstream check;
	check.open("C:\\Ex\\ExPC\\100\\sys\\main.ex0");
	if (check) {}
	else {
		std::cout << "\nSystem not found!\nPress any key to restart!";
		std::cin.get();
		main();
	}
	std::string sysc;
	std::ifstream sys("C:\\Ex\\ExPC\\100\\sys\\main.ex0");
	while (std::getline(sys, sysc))
	{
		if (sysc == "begin")
		{
			std::string varc = "del /Q ";
			system(varc.append(temp + "\\*.ex1").c_str());
			system("cls");
			std::cout << "ExPC-100\nVeress Bence Gyula 2021-2022\nStarting...\n" << std::endl;
			break;
		}
		else {}
	}
	while (std::getline(sys, sysc)) {
		if (sysc.substr(0, 1) == "#") {}
		else if (sysc == "") {}
		else if (sysc == "clear")
		{
			system("cls");
		}
		else if (sysc.substr(0, 5) == "print")
		{
			std::cout << sysc.substr(6);
		}
		else if (sysc == "nl")
		{
			std::cout << std::endl;
		}
		else if (sysc == "keyw")
		{
			std::cin.get();
		}
		else if (sysc == "end")
		{
			std::string varc = "del /Q ";
			system(varc.append(temp + "\\*.ex1").c_str());
			break;
		}
		else if (sysc == "close")
		{
			exit(0);
		}
		else if (sysc.substr(0, 3) == "set")
		{
			if (sysc.substr(4, 1) == "0")
			{
				if (sysc.substr(6) == "exlerr")
				{
					exlerr = 0;
				}
			}
			else if (sysc.substr(4, 1) == "1")
			{
				if (sysc.substr(6) == "exlerr")
				{
					exlerr = 1;
				}
			}
			else if (sysc.substr(4, 4) == "temp")
			{
				temp = sysc.substr(9);
			}
		}
		else if (sysc.substr(0, 5) == "varin")
		{
			std::string varname = sysc.substr(6);
			std::ofstream varfile(temp + "\\" + varname + ".ex1");
		}
		else if (sysc == "varc")
		{
			std::cout << "\n";
			std::string varc = "del /Q ";
			system(varc.append(temp + "\\*.ex1").c_str());
		}
		else if (sysc.substr(0, 3) == "var")
		{
			std::string varname = sysc.substr(4);
			std::ofstream varfile(temp + "\\" + varname + ".ex1");
		}
		else
		{
			if (exlerr)
			{
				std::cout << "\nEXL: ERROR\nPress any key to continue!" << std::endl;
				std::cin.get();
			}
		}
	}
	sys.close();
	system("cls");
	std::cout << "End of session!\nPress any key to restart!" << std::endl;
	std::cin.get();
	main();
}
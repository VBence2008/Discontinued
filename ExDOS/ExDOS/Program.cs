using System;
using System.IO;

namespace ExDOS
{
    class Program
    {
        static void Main(string[] args)
        {
            Reset:
            Console.Title = "ExDOS";
            Console.Clear();
            Console.WriteLine("ExDOS 1.0.0\n2021 - Veress Bence Gyula");
            Console.WriteLine("\nStarting...\n");
            string appdata = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            string exdir = Path.Combine(appdata, "exdos");
            string exfile = Path.Combine(exdir, "mainfile.exdos");
            if (!File.Exists(exfile))
            {
                Console.Clear();
                Console.WriteLine("-----------------------------\nExDOS installer - ExDOS 1.0.0\n-----------------------------\nThis wizard will help you to install ExDOS properly on your device!\nPress any key to continue!");
                Console.ReadKey();
                Console.Clear();
                Console.WriteLine("-----------------------------\nExDOS installer - ExDOS 1.0.0\n-----------------------------\nWho will use ExDOS on this device?\n");
                Console.Write("Username: ");
                string usernameg = Console.ReadLine();
                Console.Clear();
                Console.WriteLine("-----------------------------\nExDOS installer - ExDOS 1.0.0\n-----------------------------\nSet a password for your profile!\n");
                Console.Write("Password: ");
                string passwordg = Console.ReadLine();
                Console.Clear();
                Console.WriteLine("-----------------------------\nExDOS installer - ExDOS 1.0.0\n-----------------------------\nInstalling...\n");
                Directory.CreateDirectory(exdir);
                string[] setup = {"mainfile.exdos","inf:","{","    exdos","    100", "}","cont:","{","    " + usernameg, "    " + passwordg,"}","end"};
                using (StreamWriter outputFile = new StreamWriter(exfile))
                {
                    foreach (string line in setup)
                        outputFile.WriteLine(line);
                }
                Console.WriteLine("Finished!\nPress any key to continue!");
                Console.ReadKey();
                Console.Clear();
            }
            string username;
            string password;
            string passwordc;
            string cmd;
            Random rd = new Random();
            using (var sr = new StreamReader(exfile))
            {
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                username = sr.ReadLine();
            }
            using (var sr = new StreamReader(exfile))
            {
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                sr.ReadLine();
                password = sr.ReadLine();
            }
            Console.WriteLine("Welcome " + username.Substring(4) + "!\nPlease enter your password!\n");
            Login:
            Console.Write("Password: ");
            passwordc = Console.ReadLine();
            if (passwordc != password.Substring(4))
            {
                Console.WriteLine("Invalid password!");
                goto Login;
            }
            Console.Clear();
            RunCmd:
            Console.Write(">");
            cmd = Console.ReadLine();
            switch (cmd)
            {
                default:
                    Console.WriteLine("Error");
                    goto RunCmd;
                case "help":
                    Console.WriteLine("\nExDOS help for commands:\n\n");
                    Console.WriteLine("     clear = Clear the screen");
                    Console.WriteLine("     dice = Generate random number between 1 and 6");
                    Console.WriteLine("     help = Help menu for ExDOS commands");
                    Console.WriteLine("     logout = Go back to the login screen, you have to enter the password to unlock");
                    Console.WriteLine("     reset = Restarts ExDOS");
                    Console.WriteLine("\n");
                    goto RunCmd;
                case "clear":
                    Console.Clear();
                    goto RunCmd;
                case "reset":
                    goto Reset;
                case "logout":
                    Console.Clear();
                    goto Login;
                case "dice":
                    int dice = rd.Next(1, 7);
                    Console.WriteLine(dice);
                    goto RunCmd;
                case "ls":
                    //unfinished command
                    goto RunCmd;
            }
        }
    }
}

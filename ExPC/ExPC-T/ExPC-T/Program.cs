using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.IO.Compression;

namespace T
{
    class Program
    {
        static void Main(string[] args)
        {
        Start:
            Console.Clear();
            //Startup
            Console.Title = "ExPC-T";
            Console.WriteLine("ExPC-T\nVeress Bence Gyula - 2021\n\nStarting...");
            string exdir = @"C:\Ex";
            string appdir = @"C:\Ex\ExPC";
            string pcdir = @"C:\Ex\ExPC\T";
            string sysdir = @"C:\Ex\ExPC\T\sys";
            string system = @"C:\Ex\ExPC\T\sys\sys.exc";
            string exadir = @"C:\Ex\ExPC\T\exa";
            string exasysdir = @"C:\Ex\ExPC\T\exa\sys";
            string exaappdir = @"C:\Ex\ExPC\T\exa\app";
            //First run check
            if (!Directory.Exists(exdir))
            {
                Directory.CreateDirectory(exdir);
                Console.WriteLine("\nDirectory created: {0}", exdir);
            }
            if (!Directory.Exists(appdir))
            {
                Directory.CreateDirectory(appdir);
                Console.WriteLine("Directory created: {0}", appdir);
            }
            if (!Directory.Exists(pcdir))
            {
                Directory.CreateDirectory(pcdir);
                Console.WriteLine("Directory created: {0}", pcdir);
                Directory.CreateDirectory(exadir);
                Console.WriteLine("Directory created: {0}", exadir);
                Directory.CreateDirectory(exasysdir);
                Console.WriteLine("Directory created: {0}", exasysdir);
                Directory.CreateDirectory(exaappdir);
                Console.WriteLine("Directory created: {0}", exaappdir);
                Console.WriteLine("\nYour first time run setup finished!\nPress any key to restart!");
                Console.ReadKey();
                goto Start;
            }
            int exasyscount = Directory.GetFiles(exasysdir, "*.exa").Length;
            if (!Directory.Exists(sysdir) || !File.Exists(@"C:\Ex\ExPC\T\sys\sys.exc"))
            {
                if (exasyscount != 1)
                {
                    Console.WriteLine("\nSystem not found!\nPlease put ONE .exa archive into '{0}' that contains a system for ExPC!\nPress any key to retry!", exasysdir);
                    Console.ReadKey();
                    goto Start;
                }
                else
                {
                    //Scan, If it's a system or not
                    IEnumerable<string> exasf = Directory.EnumerateFiles(@"C:\Ex\ExPC\T\exa\sys", "*.exa");
                    string bexa = exasf.First();
                    Directory.CreateDirectory(sysdir);
                    Console.WriteLine("\nDirectory created: {0}", sysdir);
                    ZipFile.ExtractToDirectory(bexa, sysdir);
                    if (!File.Exists(@"C:\Ex\ExPC\T\sys\sys.exc"))
                    {
                        string[] filePaths = Directory.GetFiles(@"C:\Ex\ExPC\T\sys\");
                        foreach (string filePath in filePaths)
                            File.Delete(filePath);
                        Directory.Delete(sysdir);
                        Console.WriteLine("\nSystem not found!\nPlease put ONE .exa archive into '{0}' that contains a system for ExPC!\nPress any key to retry!", exasysdir);
                        Console.ReadKey();
                        goto Start;
                    }
                    string[] bsysfile = File.ReadAllLines(@"C:\Ex\ExPC\T\sys\sys.exc");
                    if (!bsysfile.Contains("*expc,t"))
                    {
                        string[] filePaths = Directory.GetFiles(@"C:\Ex\ExPC\T\sys\");
                        foreach (string filePath in filePaths)
                            File.Delete(filePath);
                        Directory.Delete(sysdir);
                        Console.WriteLine("\nSystem not found!\nPlease put ONE .exa archive into '{0}' that contains a system for ExPC!\nPress any key to retry!", exasysdir);
                        Console.ReadKey();
                        goto Start;
                    }
                    string bsysnam;
                    string bsysname;
                    string bsysautho;
                    string bsysauthor;
                    using (var sr = new StreamReader(system))
                    {
                        bsysnam = sr.ReadLine();
                        bsysautho = sr.ReadLine();
                        bsysname = bsysnam.Substring(1);
                        bsysauthor = bsysautho.Substring(1);
                    }
                    Console.WriteLine("\nDo you want to install this system to ExPC?\nName: {0}\nAuthor: {1}", bsysname,bsysauthor);
                    Console.Write("\nY/N: ");
                    string sysinstall = Console.ReadLine();
                    switch (sysinstall)
                    {
                        default:
                            string[] filePaths = Directory.GetFiles(@"C:\Ex\ExPC\T\sys\");
                            foreach (string filePath in filePaths)
                                File.Delete(filePath);
                            Directory.Delete(sysdir);
                            goto Start;
                        case "y":
                            goto Sysinstall;
                        case "Y":
                            goto Sysinstall;
                    }
                Sysinstall:
                    Console.WriteLine("\n{0} installed!\nPress any key to restart!", bsysname);
                    Console.ReadKey();
                    goto Start;
                }
            }
        Sys:
            //Read ExCode
            string systemtext = File.ReadAllText(system);
            string[] code = systemtext.Split('\n');
        ReadCode:
            try
            {
                foreach (var cp in code)
                {
                    if (cp.StartsWith("print"))
                    {
                        Console.WriteLine(cp.Substring(6));
                    }
                    else if (cp.StartsWith("#"))
                    {

                    }
                    else if (cp.StartsWith("*"))
                    {

                    }
                    else if (cp.StartsWith("end"))
                    {
                        goto Exit;
                    }
                    else if (cp.StartsWith("clear"))
                    {
                        Console.Clear();
                    }
                    else if (cp.StartsWith("keyw"))
                    {
                        Console.ReadKey();
                    }
                    else
                    {
                        Console.WriteLine("EXC: ERROR");
                    }
                }
            }
            catch { }
        Exit:
            Console.WriteLine("\nEnd of session!\nPress any key to restart!");
            Console.ReadKey();
            goto Start;
        }
    }
}

from codecs import ignore_errors
def ExOS():
    import os
    import ctypes
    os.system('cls')
    ctypes.windll.kernel32.SetConsoleTitleW("ExPC-TA")
    print("ExPC-TA\nVeress Bence Gyula - 2021\n\nStarting...\n")
    exdir = "C:\Ex"
    appdir = "C:\Ex\ExPC"
    verdir = "C:\Ex\ExPC\ExPC-TA"
    sysdir = "C:\Ex\ExPC\ExPC-TA\sys"
    exosdir = "C:\Ex\ExPC\ExPC-TA\ExOS"
    if not os.path.exists(exosdir):
        os.mkdir(exosdir)
        print("\nDirectory created: " + exosdir)
    

def main():
    #try:
        import os
        import codecs
        from zipfile import ZipFile
        import ctypes
        os.system('cls')
        ctypes.windll.kernel32.SetConsoleTitleW("ExPC-TA")
        print("ExPC-TA\nVeress Bence Gyula - 2021\n\nStarting...\n")
        exdir = "C:\Ex"
        appdir = "C:\Ex\ExPC"
        verdir = "C:\Ex\ExPC\ExPC-TA"
        sysdir = "C:\Ex\ExPC\ExPC-TA\sys"
        if not os.path.exists(exdir):
            os.mkdir(exdir)
            print("\nDirectory created: " + exdir)
        if not os.path.exists(appdir):
            os.mkdir(appdir)
            print("Directory created: " + appdir)
        if not os.path.exists(verdir):
            os.mkdir(verdir)
            print("Directory created: " + verdir)
            b00t_question = "\nDo you want to boot the default OS installed? (Y/N): "
            b00t_siy = {"y","Y"}
            b00t_sin = {"n","N"}
            b00t_done = False
            while not b00t_done:
                choice = input(b00t_question).lower()
                if choice in b00t_siy:
                    ExOS()
                elif choice in b00t_sin:
                    b00t_done = True
                    pass
                else:
                    b00t_done = True
                    ExOS()
                    
        if not os.path.exists(sysdir):
            files = os.listdir(verdir)
            for exa in files:
                if exa.endswith(".exa"):
                    exasys = ("C:\Ex\ExPC\ExPC-TA\\" + exa)
                    with ZipFile(exasys, "r") as zipObj:
                        zipObj.extractall(sysdir)
            try:
                syss = codecs.open("C:\Ex\ExPC\ExPC-TA\sys\sys.exs","r","utf-8")
            except FileNotFoundError:
                print("\nAn error occoured!\nPlease put one exa file into " + verdir + " that contains a valid system for ExPC!\nPress any key to continue!")
                input()
                main()
            syssscount = 0
            for line in syss:
                syssscount += 1
                if syssscount == 1:
                    print("Name: " + line)
                if syssscount == 2:
                    print("Author: " + line)
                if syssscount == 3:
                    print("Creation date: " + line)
                if syssscount == 4:
                    print("Description: " + line)
            syss.close()
            question = "\nDo you want to install this system? (Y/N): "
            siy = {"y","Y"}
            sin = {"n","N"}
            done = False
            while not done:
                choice = input(question).lower()
                if choice in siy:
                    done = True
                    print("\nSystem installed!\nPress any key to restart ExPC!")
                    input()
                    main()
                elif choice in sin:
                    done = True
                    for file in os.listdir(sysdir):
                        os.remove(os.path.join(sysdir, file))
                    os.rmdir(sysdir)
                    print("\nSystem installation cancelled!\nPress any key to restart ExPC!")
                    input()
                    main()
                else:
                    done = False
                    for file in os.listdir(sysdir):
                        os.remove(os.path.join(sysdir, file))
                    os.rmdir(sysdir)
                    print("\nSystem installation cancelled!\nPress any key to restart ExPC!")
                    input()
                    main()
        sysc = codecs.open("C:\Ex\ExPC\ExPC-TA\sys\sys.exc","r","utf-8")
        var = []
        for line in sysc:
            if (line.startswith("clear")):
                os.system('cls')
            elif(line.startswith("#")):
                pass
            elif(line.startswith("print ")):
                print (line[6::])
            elif (line.startswith("end")):
                print("End of session!\nPress any key to restart ExCode!")
                input()
                main()
            elif (line.startswith("keyw")):
                input()
            elif (line.startswith("var")):
                var.append(line[4::])
            elif (line.startswith("printvar ")):
                try:
                    print(var[int(line[9::])-1])
                except IndexError:
                    print("EXC: ERROR\nPress any key to continue!")
                    input()
            else:
                print("EXC: ERROR\nPress any key to continue!")
                input()
    #except:
        #print("PY: ERROR\nPress any key to pass the exception!")
        #input()
main()
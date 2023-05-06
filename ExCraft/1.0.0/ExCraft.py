from ursina import *
def v100():
    application.development_mode = False
    game100 = Ursina()
    window.exit_button.enabled = False
    window.cog_button.enabled = False
    window.fps_counter.enabled = False
    window.borderless = False
    window.fullscreen = True
    game100.run()
def launcher():
    #try:
        import os
        import ctypes
        from zipfile import ZipFile
        os.system('cls')
        ctypes.windll.kernel32.SetConsoleTitleW("ExCraft")
        print("ExCraft Launcher 1.0.0\nVeress Bence Gyula - 2021\n")
        exdir = "C:\Ex"
        appdir = "C:\Ex\ExCraft"
        verdir = "C:\Ex\ExCraft\\1.0.0"
        datadir = "C:\Ex\ExCraft\\1.0.0\data"
        if not os.path.exists(exdir):
            os.mkdir(exdir)
            print("Directory created: " + exdir)
        if not os.path.exists(appdir):
            os.mkdir(appdir)
            print("Directory created: " + appdir)
        if not os.path.exists(verdir):
            os.mkdir(verdir)
            print("Directory created: " + verdir)
        if not os.path.exists(datadir):
            os.mkdir(datadir)
            print("Directory created: " + datadir)
        if not (os.path.exists("C:\Ex\ExCraft\\1.0.0\data\data.excraft")):
            usernamef = open("C:\Ex\ExCraft\\1.0.0\data\data.excraft","w")
            usernamei = input("\nEnter a username: ")
            usernamef.write(usernamei)
            usernamef.close()
            print("\nExCraft setup completed!\nPress any key to restart ExCraft!")
            input()
            launcher()
        usernamef = open("C:\Ex\ExCraft\\1.0.0\data\data.excraft","r")
        linec = 0
        for line in usernamef:
            linec += 1
            if (linec == 1):
                username = line
        try:
            print("Welcome " + username + "!")
        except UnboundLocalError:
            username = "Player"
            print("Welcome " + username + "!")
        print("Available versions:\n")
        print("   1.0.0 - 2021.11.27")
        print("\nType which version do you want to play!")
        verselect = input("Selection: ")
        if (verselect == "1.0.0"):
            v100()
        else:
            print("Invalid version!\nPress any key to retry!")
            input()
            launcher()
    #except:
        #print("\nPY: ERROR\nPress any key to continue!")
        #input()
launcher()
def main():
    #try:
        import os
        import tkinter
        import base64
        import ctypes
        os.system('cls')
        ctypes.windll.kernel32.SetConsoleTitleW("ExGame 1.0.0")
        print("ExGame 1.0.0\nVeress Bence Gyula - 2021\n\nStarting...\n")
        exdir = "C:\Ex"
        appdir = "C:\Ex\ExGame"
        verdir = "C:\Ex\ExGame\\1.0.0"
        if not os.path.exists(exdir):
            os.mkdir(exdir)
            print("Directory created: " + exdir)
        if not os.path.exists(appdir):
            os.mkdir(appdir)
            print("Directory created: " + appdir)
        if not os.path.exists(verdir):
            os.mkdir(verdir)
            print("Directory created: " + verdir)
        com = input(">")
        if com.startswith("new "):
            win = tkinter.Tk()
            win.title("ExGame - " + com[4::])
            win.geometry("700x500")
            icon = ""
            icondata= base64.b64decode(icon)
            tempFile= "icon.ico"
            iconfile= open(tempFile,"wb")
            iconfile.write(icondata)
            iconfile.close()
            win.wm_iconbitmap(tempFile)
            os.remove(tempFile)
            win.mainloop()
    #except:
        #print("PY: ERROR")
main()
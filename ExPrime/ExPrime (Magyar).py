def program():
    import os
    import ctypes
    ctypes.windll.kernel32.SetConsoleTitleW("ExPrime (Magyar)")
    os.system('cls')
    print("ExPrime (Magyar)\nVeress Bence Gyula 2021\n")
    számláló = 0
    összeadás = 0
    start = int (input("Legkisebb szám: "))
    end = int (input("Legnagyobb szám: "))
    print ("Prímszámok", start, "-", end,":\n")
    for i in range(start, end+1):
        flag = 0
        for j in range(2, i):
            if (i % j == 0):
                flag = 1
                break
        if (flag == 0):
            print (i, end = " ")
            számláló += 1
            összeadás += i
    print("\n\nÖsszesen:",számláló,"\nNyomjon meg egy billentyűt a következő kereséshez!")
    input()
    program()
program()
def main():
    import os
    import ctypes
    ctypes.windll.kernel32.SetConsoleTitleW("ExPrime")
    os.system('cls')
    print("ExPrime\nVeress Bence Gyula\n")
    count = 0
    add = 0
    start = int (input("Enter the starting range: "))
    end = int (input("Enter the end range: "))
    print ("Prime numbers in the range", start, "to", end,":\n")
    for i in range(start, end+1):
        flag = 0
        for j in range(2, i):
            if (i % j == 0):
                flag = 1
                break
        if (flag == 0):
            print (i, end = " ")
            count += 1
            add += i
    print("\n\nTotal primes found:",count,"\nPress any key to find more!")
    input()
    main()
main()
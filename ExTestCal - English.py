def main():
    import os
    os.system('cls')
    smax = float(input("ExTestCal - Test percentage calculator (mostly)\nVeress Bence Gyula - 2022\nMaximum score: "))
    sget = float(input("Your score: "))
    sres = (sget/smax)*100
    print("\n--------------------\nResults:",str(int(sres))+"%\n--------------------\nScores:",str(sget)+"/"+str(smax),"\nPercent (simple):",str(int(sres))+"%","\nPercent (exact):",str(sres) + "%",)
    input()
    main()
main()
def main():
    import os
    os.system('cls')
    smax = float(input("ExTestCal - Teszt százalékszámítás (nagyjából)\nVeress Bence Gyula - 2022\nÖsszpontszám: "))
    sget = float(input("Te pontszámod: "))
    sres = (sget/smax)*100
    sreg = 0
    if (int(sres) > 90):
        sreg = 5
    elif (int(sres) == 90):
        sreg = "4 vagy 5 (határeset)"
    elif (int(sres) > 75):
        sreg = 4
    elif (int(sres) == 75):
        sreg = "3 vagy 4 (határeset)"
    elif (int(sres) > 50):
        sreg = 3
    elif (int(sres) == 50):
        sreg = "2 vagy 3 (határeset)"
    elif (int(sres) > 33):
        sreg = 2
    elif (int(sres) == 33):
        sreg = "1 vagy 2 (határeset)"
    elif (int(sres) > -1):
        sreg = 1
    print("\n--------------------\nEredmények:",str(int(sres))+"%","-",sreg,"\n--------------------\nPontok:",str(sget)+"/"+str(smax),"\nSzázalék (kerekítetlen):",str(int(sres))+"%","\nSzázalék (pontos):",str(sres) + "%","\nÉrdemjegy:",sreg,"\nAz osztályzás a Székesfehérvári II. Rákóczi Ferenc Általános Iskola házirendjén alapul!\n")
    print("----------------------------------------\nPonthatárok (pontatlanság lehetséges):\n----------------------------------------\nEgyszerűbb:\n5 =",int(smax*(91/100)),"-",int(smax),"\n4 =",int(smax*(76/100)),"-",int(smax*(90/100)),"\n3 =",int(smax*(51/100)),"-",int(smax*(75/100)),"\n2 =",int(smax*(34/100)),"-",int(smax*(50/100)),"\n1 =",int(smax*(0/100)),"-",int(smax*(33/100)))
    print("\nPontosabb:\n5 =",smax*(91/100),"-",smax,"\n4 =",smax*(76/100),"-",smax*(90/100),"\n3 =",smax*(51/100),"-",smax*(75/100),"\n2 =",smax*(34/100),"-",smax*(50/100),"\n1 =",smax*(0/100),"-",smax*(33/100))
    input()
    main()
main()
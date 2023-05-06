def main():
    import os
    os.system('cls')
    smax = float(input("ExTestCal - Teszt százalékszámítás (nagyjából)\nVeress Bence Gyula - 2022\nÖsszpontszám: "))
    sget = float(input("Te pontszámod: "))
    sres = (sget/smax)*100
    sreg = 0
    if (int(sres) > 88):
        sreg = 8
    elif (int(sres) > 75):
        sreg = 7
    elif (int(sres) > 63):
        sreg = 6
    elif (int(sres) > 50):
        sreg = 5
    elif (int(sres) > 38):
        sreg = 4
    elif (int(sres) > 25):
        sreg = 3
    elif (int(sres) > 13):
        sreg = 2
    elif (int(sres) > -1):
        sreg = 1
    print("\n--------------------\nEredmények:",str(int(sres))+"%","-",sreg,"\n--------------------\nPontok:",str(sget)+"/"+str(smax),"\nSzázalék (kerekítetlen):",str(int(sres))+"%","\nSzázalék (pontos):",str(sres) + "%","\nÉrdemjegy:",sreg,"\n")
    print("----------------------------------------\nPonthatárok (pontatlanság lehetséges):\n----------------------------------------\nEgyszerűbb:\n8 =",int(smax*(89/100)),"-",int(smax),"\n7 =",int(smax*(76/100)),"-",int(smax*(88/100)),"\n6 =",int(smax*(64/100)),"-",int(smax*(75/100)),"\n5 =",int(smax*(51/100)),"-",int(smax*(63/100)),"\n4 =",int(smax*(39/100)),"-",int(smax*(50/100)),"\n3 =",int(smax*(26/100)),"-",int(smax*(38/100)),"\n2 =",int(smax*(14/100)),"-",int(smax*(25/100)),"\n1 =",int(smax*(0/100)),"-",int(smax*(13/100)))
    print("\nPontosabban:\n8 =",smax*(89/100),"-",smax,"\n7 =",smax*(76/100),"-",smax*(88/100),"\n6 =",smax*(64/100),"-",smax*(75/100),"\n5 =",smax*(51/100),"-",smax*(63/100),"\n4 =",smax*(39/100),"-",smax*(50/100),"\n3 =",smax*(26/100),"-",smax*(38/100),"\n2 =",smax*(14/100),"-",smax*(25/100),"\n1 =",smax*(0/100),"-",smax*(13/100))
    input()
    main()
main()
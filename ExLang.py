import os
import ctypes
def main():
    os.system('cls')
    ctypes.windll.kernel32.SetConsoleTitleW("ExPC-TA")
    print("ExLang by Veress Bence Gyula - 2021\n\nStatus:\n\nLingadak: 2021.12.10\nSeilinga: Not available\nLingajdyryn: Not available\nLingaiopi: Not available\n\nPlease put space between the words and marks, for example: How are you ?")
    intext = input("\nSentence: ").lower().split()
    wordcount = 0
    for word in intext:
        wordcount += 1
        if (wordcount == 1):
            if (word == "a"):
                outtext_lingadak = "E"
            elif (word == "an"):
                outtext_lingadak = "En"
            elif (word == "the"):
                outtext_lingadak = "La"
            elif (word == "and"):
                outtext_lingadak = "Len"
            elif (word == "or"):
                outtext_lingadak = "Ar"
            elif (word == "what"):
                outtext_lingadak = "Me"
            elif (word == "yes"):
                outtext_lingadak = "Alln"
            elif (word == "no"):
                outtext_lingadak = "Na"
            elif (word == "but"):
                outtext_lingadak = "Della"
            elif (word == "where"):
                outtext_lingadak = "Uyan"
            elif (word == "how"):
                outtext_lingadak = "Han"
            elif (word == "who"):
                outtext_lingadak = "Heyl"
            elif (word == "i"):
                outtext_lingadak = "Yn"
            elif (word == "me"):
                outtext_lingadak = "Yn"
            elif (word == "my"):
                outtext_lingadak = "Ma"
            elif (word == "not"):
                outtext_lingadak = "Nalla"
            elif (word == "you"):
                outtext_lingadak = "Jun"
            elif (word == "your"):
                outtext_lingadak = "Ya"
            elif (word == "him"):
                outtext_lingadak = "Hayn"
            elif (word == "her"):
                outtext_lingadak = "Hayn"
            elif (word == "its"):
                outtext_lingadak = "Hayn"
            elif (word == "on"):
                outtext_lingadak = "Tayk"
            elif (word == "he"):
                outtext_lingadak = "Yam"
            elif (word == "she"):
                outtext_lingadak = "Yam"
            elif (word == "it"):
                outtext_lingadak = "Yam"
            elif (word == "their"):
                outtext_lingadak = "Yayn"
            elif (word == "with"):
                outtext_lingadak = "Lelle"
            elif (word == "without"):
                outtext_lingadak = "Lei"
            elif (word == "we"):
                outtext_lingadak = "Jal"
            elif (word == "us"):
                outtext_lingadak = "Jal"
            elif (word == "our"):
                outtext_lingadak = "Yayl"
            elif (word == "am"):
                outtext_lingadak = "A"
            elif (word == "are"):
                outtext_lingadak = "A"
            elif (word == "is"):
                outtext_lingadak = "A"
            elif (word == "they"):
                outtext_lingadak = "Yahl"
            elif (word == "them"):
                outtext_lingadak = "Yahl"
            elif (word == "to"):
                outtext_lingadak = "Ko"
            elif (word == "why"):
                outtext_lingadak = "Lean"
            elif (word == "very"):
                outtext_lingadak = "Yla"
            elif (word == "because"):
                outtext_lingadak = "Raga"
            elif (word == "of"):
                outtext_lingadak = "Unia"
            elif (word == "number"):
                outtext_lingadak = "Nume"
            elif (word == "fruit"):
                outtext_lingadak = "Late"
            elif (word == "vegetable"):
                outtext_lingadak = "Bani"
            elif (word == "juice"):
                outtext_lingadak = "Sepa"
            elif (word == "water"):
                outtext_lingadak = "Unter"
            elif (word == "hot"):
                outtext_lingadak = "Gan"
            elif (word == "cold"):
                outtext_lingadak = "Hul"
            elif (word == "speak"):
                outtext_lingadak = "Syek"
            elif (word == "open"):
                outtext_lingadak = "Ump"
            elif (word == "close"):
                outtext_lingadak = "Lak"
            elif (word == "do"):
                outtext_lingadak = "An"
            elif (word == "else"):
                outtext_lingadak = "Leran"
            elif (word == "ask"):
                outtext_lingadak = "Lait"
            elif (word == "word"):
                outtext_lingadak = "Vaynd"
            elif (word == "language"):
                outtext_lingadak = "Dak"
            elif (word == "text"):
                outtext_lingadak = "Tai"
            elif (word == "document"):
                outtext_lingadak = "Dok"
            elif (word == "long"):
                outtext_lingadak = "Yng"
            elif (word == "short"):
                outtext_lingadak = "Dang"
            elif (word == "high"):
                outtext_lingadak = "Uitang"
            elif (word == "low"):
                outtext_lingadak = "Autang"
            elif (word == "vehicle"):
                outtext_lingadak = "Vaink"
            elif (word == "machine"):
                outtext_lingadak = "Rada"
            elif (word == "smart"):
                outtext_lingadak = "Oki"
            elif (word == "stupid"):
                outtext_lingadak = "Lu"
            elif (word == "as"):
                outtext_lingadak = "Niod"
            elif (word == "always"):
                outtext_lingadak = "Cali"
            elif (word == "color"):
                outtext_lingadak = "Kolra"
            elif (word == "full"):
                outtext_lingadak = "Fan"
            elif (word == "can"):
                outtext_lingadak = "Ga"
            elif (word == "think"):
                outtext_lingadak = "Tsay"
            elif (word == "about"):
                outtext_lingadak = "Kurnei"
            else:
                outtext_lingadak = word
        else:
            if (word == "a"):
                outtext_lingadak = outtext_lingadak + " e"
            elif (word == "an"):
                outtext_lingadak = outtext_lingadak + " en"
            elif (word == "the"):
                outtext_lingadak = outtext_lingadak + " la"
            elif (word == "and"):
                outtext_lingadak = outtext_lingadak + " len"
            elif (word == "or"):
                outtext_lingadak = outtext_lingadak + " ar"
            elif (word == "what"):
                outtext_lingadak = outtext_lingadak + " me"
            elif (word == "yes"):
                outtext_lingadak = outtext_lingadak + " alln"
            elif (word == "no"):
                outtext_lingadak = outtext_lingadak + " na"
            elif (word == "but"):
                outtext_lingadak = outtext_lingadak + " della"
            elif (word == "where"):
                outtext_lingadak = outtext_lingadak + " uyan"
            elif (word == "how"):
                outtext_lingadak = outtext_lingadak + " han"
            elif (word == "who"):
                outtext_lingadak = outtext_lingadak + " heyl"
            elif (word == "i"):
                outtext_lingadak = outtext_lingadak + " ni"
            elif (word == "me"):
                outtext_lingadak = outtext_lingadak + " ni"
            elif (word == "my"):
                outtext_lingadak = outtext_lingadak + " ma"
            elif (word == "not"):
                outtext_lingadak = outtext_lingadak + " nalla"
            elif (word == "you"):
                outtext_lingadak = outtext_lingadak + " ji"
            elif (word == "your"):
                outtext_lingadak = outtext_lingadak + " ya"
            elif (word == "him"):
                outtext_lingadak = outtext_lingadak + " hayn"
            elif (word == "her"):
                outtext_lingadak = outtext_lingadak + " hayn"
            elif (word == "its"):
                outtext_lingadak = outtext_lingadak + " hayn"
            elif (word == "on"):
                 outtext_lingadak = outtext_lingadak + " tayk"
            elif (word == "he"):
                 outtext_lingadak = outtext_lingadak + " mi"
            elif (word == "she"):
                 outtext_lingadak = outtext_lingadak + " mi"
            elif (word == "it"):
                 outtext_lingadak = outtext_lingadak + " mi"
            elif (word == "their"):
                 outtext_lingadak = outtext_lingadak + " yayn"
            elif (word == "with"):
                 outtext_lingadak = outtext_lingadak + " lelle"
            elif (word == "without"):
                 outtext_lingadak = outtext_lingadak + " lei"
            elif (word == "we"):
                 outtext_lingadak = outtext_lingadak + " di"
            elif (word == "us"):
                 outtext_lingadak = outtext_lingadak + " di"
            elif (word == "our"):
                 outtext_lingadak = outtext_lingadak + " yayl"
            elif (word == "am"):
                 outtext_lingadak = outtext_lingadak + "a"
            elif (word == "are"):
                 outtext_lingadak = outtext_lingadak + "a"
            elif (word == "is"):
                 outtext_lingadak = outtext_lingadak + "a"
            elif (word == "they"):
                 outtext_lingadak = outtext_lingadak + " hi"
            elif (word == "them"):
                 outtext_lingadak = outtext_lingadak + " yahl"
            elif (word == "to"):
                 outtext_lingadak = outtext_lingadak + " ko"
            elif (word == "why"):
                 outtext_lingadak = outtext_lingadak + " lean"
            elif (word == "very"):
                 outtext_lingadak = outtext_lingadak + " yla"
            elif (word == "because"):
                 outtext_lingadak = outtext_lingadak + " raga"
            elif (word == "of"):
                 outtext_lingadak = outtext_lingadak + " unia"
            elif (word == "number"):
                 outtext_lingadak = outtext_lingadak + " nume"
            elif (word == "fruit"):
                 outtext_lingadak = outtext_lingadak + " late"
            elif (word == "vegetable"):
                 outtext_lingadak = outtext_lingadak + " bani"
            elif (word == "juice"):
                 outtext_lingadak = outtext_lingadak + " sepa"
            elif (word == "water"):
                 outtext_lingadak = outtext_lingadak + " unter"
            elif (word == "hot"):
                 outtext_lingadak = outtext_lingadak + " gan"
            elif (word == "cold"):
                 outtext_lingadak = outtext_lingadak + " hul"
            elif (word == "speak"):
                 outtext_lingadak = outtext_lingadak + " syek"
            elif (word == "open"):
                 outtext_lingadak = outtext_lingadak + " ump"
            elif (word == "close"):
                 outtext_lingadak = outtext_lingadak + " lak"
            elif (word == "do"):
                 outtext_lingadak = outtext_lingadak + " an"
            elif (word == "else"):
                 outtext_lingadak = outtext_lingadak + " leran"
            elif (word == "ask"):
                 outtext_lingadak = outtext_lingadak + " lait"
            elif (word == "word"):
                 outtext_lingadak = outtext_lingadak + " vaynd"
            elif (word == "language"):
                 outtext_lingadak = outtext_lingadak + " dak"
            elif (word == "text"):
                 outtext_lingadak = outtext_lingadak + " tai"
            elif (word == "document"):
                 outtext_lingadak = outtext_lingadak + " dok"
            elif (word == "long"):
                 outtext_lingadak = outtext_lingadak + " yng"
            elif (word == "short"):
                 outtext_lingadak = outtext_lingadak + " dang"
            elif (word == "high"):
                 outtext_lingadak = outtext_lingadak + " uitang"
            elif (word == "low"):
                 outtext_lingadak = outtext_lingadak + " autang"
            elif (word == "vehicle"):
                 outtext_lingadak = outtext_lingadak + " vaink"
            elif (word == "machine"):
                 outtext_lingadak = outtext_lingadak + " rada"
            elif (word == "smart"):
                 outtext_lingadak = outtext_lingadak + " oki"
            elif (word == "stupid"):
                 outtext_lingadak = outtext_lingadak + " lu"
            elif (word == "as"):
                 outtext_lingadak = outtext_lingadak + " niod"
            elif (word == "always"):
                 outtext_lingadak = outtext_lingadak + " cali"
            elif (word == "color"):
                 outtext_lingadak = outtext_lingadak + " kolra"
            elif (word == "full"):
                 outtext_lingadak = outtext_lingadak + " fan"
            elif (word == "can"):
                 outtext_lingadak = outtext_lingadak + " ga"
            elif (word == "think"):
                 outtext_lingadak = outtext_lingadak + " tsay"
            elif (word == "about"):
                 outtext_lingadak = outtext_lingadak + " kurnei"
            else:
                outtext_lingadak = outtext_lingadak + " " + word
    print("\nLingadak: " + outtext_lingadak)
    #print("Seilinga: " + outtext_seilinga)
    #print("Lingajdyryn: " + outtext_lingajdyryn)
    #print("Lingaiopi: " + outtext_lingaiopi)
    print("\nPress any key to translate more!")
    input()
    main()
main()
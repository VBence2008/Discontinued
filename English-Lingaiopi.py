import os
import ctypes
def main():
    os.system('cls')
    ctypes.windll.kernel32.SetConsoleTitleW("English - Lingaiopi")
    print("English - Lingaiopi (Änglis - Lindäioopi) translator by Veress Bence Gyula - 2021\n\nStatus: 2021.12.12\n\nPlease put space between the words and marks, for example: How are you ?")
    intext = input("\nSentence: ").lower().split()
    wordcount = 0
    for word in intext:
        wordcount += 1
        if (wordcount == 1):
            if (word == "a"):
                outtext = ""
                wordcount -= 1
            elif (word == "an"):
                outtext = ""
                wordcount -= 1
            elif (word == "the"):
                outtext = ""
                wordcount -= 1
            elif (word == "i" or word == "me"):
                outtext = "Ä"
                ipa = "aː"
            elif (word == "my" or word == "mine"):
                outtext = "Ämän"
                ipa = "aːmaːn"
            elif (word == "you" or word == "he" or word == "she" or word == "it" or word == "we" or word == "they" or word == "him" or word == "her" or word == "us" or word == "them"):
                outtext = "Ë"
                ipa = "eː"
            elif (word == "your" or word == "his" or word == "her" or word == "its" or word == "our" or word == "their"):
                outtext = "Ëmän"
                ipa = "eːmaːn"
            elif (word == "am" or word == "are" or word == "is"):
                outtext = "Dı"
                ipa = "gɯ"
            elif (word == "be"):
                outtext = "Dı"
                ipa = "gɯ"
            elif (word == "and"):
                outtext = "vä"
                ipa = "vaː"
            elif (word == "or"):
                outtext = "Še"
                ipa = "sɛ"
            elif (word == "what"):
                outtext = "Çık"
                ipa = "ʒɯk"
            elif (word == "yes"):
                outtext = "Jä"
                ipa = "jaː"
            elif (word == "no" or word == "not"):
                outtext = "Noř"
                ipa = "nor"
            elif (word == "have" or word == "has"):
                outtext = "Šan"
                ipa = "sɒn"
            elif (word == "like" or word == "love"):
                outtext = "Møn"
                ipa = "møn"
            elif (word == "thanks" or word == "thank"):
                outtext = "Nëor"
                ipa = "neːoɹ̠"
            elif (word == "to" or word == "for"):
                outtext = "Slä"
                ipa = "ʃlaː"
            elif (word == "but"):
                outtext = "Beh"
                ipa = "bɛh"
            elif (word == "where"):
                outtext = "Žian"
                ipa = "d͡ziɒn"
            elif (word == "how"):
                outtext = "Novä"
                ipa = "novaː"
            elif (word == "who"):
                outtext = "Heik"
                ipa = "hɛik"
            elif (word == "on" or word == "at"):
                outtext = "Vol"
                ipa = "vol"
            elif (word == "with"):
                outtext = "Myn"
                ipa = "myn"
            elif (word == "without"):
                outtext = "Mynnoř"
                ipa = "mynnor"
            elif (word == "why"):
                outtext = "Nä"
                ipa = "na"
            elif (word == "good" or word == "fine" or word == "nice"):
                outtext = "Hjei"
                ipa = "hjɛi"
            elif (word == "bad"):
                outtext = "Đeš"
                ipa = "ɟɛs"
            elif (word == "very" or word == "really"):
                outtext = "Fjer"
                ipa = "fjɛɹ̠"
            elif (word == "because"):
                outtext = "Buh"
                ipa = "buh"
            elif (word == "of"):
                outtext = "Käm"
                ipa = "kaːm"
            elif (word == "number"):
                outtext = "Nomaar"
                ipa = "nomɒr"
            elif (word == "fruit"):
                outtext = "Çdeižä"
                ipa = "ʒgɛid͡zaː"
            elif (word == "vegetable"):
                outtext = "Đežä"
                ipa = "ɟɛd͡zaː"
            elif (word == "juice"):
                outtext = "Çmä"
                ipa = "ʒmaː"
            elif (word == "water"):
                outtext = "Äqäori"
                ipa = "aːχaːoɹ̠i"
            elif (word == "hot"):
                outtext = "Øg"
                ipa = "øg"
            elif (word == "cold"):
                outtext = "Øgnä"
                ipa = "øgnaː"
            elif (word == "speak" or word == "say"):
                outtext = "Ţial"
                ipa = "t͡siɒl"
            elif (word == "open"):
                outtext = "Čnäuţ"
                ipa = "t͡ʃnaːut͡s"
            elif (word == "close"):
                outtext = "Čnäoř"
                ipa = "t͡ʃnaːor"
            elif (word == "do" or word == "does"):
                outtext = "Dëu"
                ipa = "geːu"
            elif (word == "else" or word == "other" or word == "otherwise"):
                outtext = "Lëna"
                ipa = "leːna"
            elif (word == "ask" or word == "question"):
                outtext = "Äfzøořçı"
                ipa = "aːfzøorʒɯ"
            elif (word == "answer"):
                outtext = "Ëfzuřçı"
                ipa = "eːfzurʒɯ"
            elif (word == "word"):
                outtext = "Đin"
                ipa = "ɟin"
            elif (word == "language"):
                outtext = "Oopi"
                ipa = "oopi"
            elif (word == "text" or word == "document" or word == "book"):
                outtext = "Řjieiţo"
                ipa = "rjieit͡so"
            elif (word == "long" or word == "thick" or word == "big" or word == "high"):
                outtext = "Ukjäiçe"
                ipa = "ukjaːiʒe"
            elif (word == "short" or word == "thin" or word == "small" or word == "low"):
                outtext = "Ukjëoçe"
                ipa = "ukjeːoʒe"
            elif (word == "vehicle" or word == "machine"):
                outtext = "Imřäuë"
                ipa = "imraːueː"
            elif (word == "smart" or word == "clever"):
                outtext = "Møid"
                ipa = "møig"
            elif (word == "stupid" or word == "idiot"):
                outtext = "Mähıd"
                ipa = "maːhɯg"
            elif (word == "as"):
                outtext = "Çy"
                ipa = "ʒy"
            elif (word == "always"):
                outtext = "Onzë"
                ipa = "Onzeː"
            elif (word == "color"):
                outtext = "Ylgi"
                ipa = "yldi"
            elif (word == "full" or word == "ready" or word == "done"):
                outtext = "Heueřø"
                ipa = "heuerø"
            elif (word == "can"):
                outtext = "Dëi"
                ipa = "geːi"
            elif (word == "think" or word == "guess"):
                outtext = "Däiäř"
                ipa = "gaːiaːr"
            elif (word == "about"):
                outtext = "Hieřë"
                ipa = "hiereː"
            elif (word == "hi" or word == "hello" or word == "hey"):
                outtext = "Häi"
                ipa = "Haːi"
            elif (word == "bye"):
                outtext = "Đoi"
                ipa = "ɟoi"
            elif (word == "too"):
                outtext = "Çni"
                ipa = "ʒni"
            else:
                outtext = word
                ipa = word
        else:
            if (word == "a"):
                outtext = outtext + ""
            elif (word == "an"):
                outtext = outtext + ""
            elif (word == "the"):
                outtext = outtext + ""
            elif (word == "i" or word == "me"):
                outtext = outtext + " škëj"
                ipa = ipa + " skeːj"
            elif (word == "my" or word == "mine"):
                outtext = outtext + " škëjmen"
                ipa = ipa + " skeːjmɛn"
            elif (word == "you" or word == "he" or word == "she" or word == "it" or word == "we" or word == "they" or word == "him" or word == "her" or word == "us" or word == "them"):
                outtext = outtext + " škäj"
                ipa = ipa + " skaːj"
            elif (word == "your" or word == "his" or word == "her" or word == "its" or word == "our" or word == "their"):
                outtext = outtext + " škäjmen"
                ipa = ipa + " skaːjmɛn"
            elif (word == "am" or word == "are" or word == "is"):
                outtext = outtext + "dı"
                ipa = ipa + "gɯ"
            elif (word == "be"):
                outtext = outtext + "dı"
                ipa = ipa + "gɯ"
            elif (word == "and"):
                outtext = outtext + "vä"
                ipa = ipa + "vaː"
            elif (word == "or"):
                outtext = outtext + "še"
                ipa = ipa + "sɛ"
            elif (word == "what"):
                outtext = outtext + " çık"
                ipa = ipa + " ʒɯk"
            elif (word == "yes"):
                outtext = outtext + " jä"
                ipa = ipa + " jaː"
            elif (word == "no"):
                outtext = outtext + " noř"
                ipa = ipa + " nor"
            elif (word == "not"):
                outtext = outtext + "noř"
                ipa = ipa + "nor"
            elif (word == "have" or word == "has"):
                outtext = outtext + "šan"
                ipa = ipa + "sɒn"
            elif (word == "like" or word == "love"):
                outtext = outtext + " møn"
                ipa = ipa + " møn"
            elif (word == "thanks" or word == "thank"):
                outtext = outtext + " nëor"
                ipa = ipa + " neːoɹ̠"
            elif (word == "to" or word == "for"):
                outtext = outtext + "slä"
                ipa = ipa + "ʃlaː"
            elif (word == "but"):
                outtext = outtext + "beh"
                ipa = ipa + "bɛh"
            elif (word == "where"):
                outtext = outtext + " žian"
                ipa = ipa + " d͡ziɒn"
            elif (word == "how"):
                outtext = outtext + " novä"
                ipa = ipa + " novaː"
            elif (word == "who"):
                outtext = outtext + " heik"
                ipa = ipa + " hɛik"
            elif (word == "on" or word == "at"):
                outtext = outtext + "vol"
                ipa = ipa + " vol"
            elif (word == "with"):
                outtext = outtext + "myn"
                ipa = ipa + "myn"
            elif (word == "without"):
                outtext = outtext + "mynnoř"
                ipa = ipa + "mynnor"
            elif (word == "why"):
                outtext = outtext + " nä"
                ipa = ipa + " na"
            elif (word == "good" or word == "fine" or word == "nice"):
                outtext = outtext + " hjei"
                ipa = ipa + " hjɛi"
            elif (word == "bad"):
                outtext = outtext + " đeš"
                ipa = ipa + " ɟɛs"
            elif (word == "very" or word == "really"):
                outtext = outtext + " fjer"
                ipa = ipa + " fjɛɹ̠"
            elif (word == "because"):
                outtext = outtext + "buh"
                ipa = ipa + "buh"
            elif (word == "of"):
                outtext = outtext + "käm"
                ipa = ipa + "kaːm"
            elif (word == "number"):
                outtext = outtext + " nomař"
                ipa = ipa + " nomɒr"
            elif (word == "fruit"):
                outtext = outtext + " çdeižä"
                ipa = ipa + " ʒgɛid͡zaː"
            elif (word == "vegetable"):
                outtext = outtext + " đežä"
                ipa = ipa + " ɟɛd͡zaː"
            elif (word == "juice"):
                outtext = outtext + " çmä"
                ipa = ipa + " ʒmaː"
            elif (word == "water"):
                outtext = outtext + " äqäorı"
                ipa = ipa + " aːχaːoɹ̠i"
            elif (word == "hot"):
                outtext = outtext + " øg"
                ipa = ipa + " øg"
            elif (word == "cold"):
                outtext = outtext + " øgnä"
                ipa = ipa + " øgnaː"
            elif (word == "speak" or word == "say"):
                outtext = outtext + " ţial"
                ipa = ipa + " t͡siɒl"
            elif (word == "open"):
                outtext = outtext + " čnäuţ"
                ipa = ipa + " t͡ʃnaːut͡s"
            elif (word == "close"):
                outtext = outtext + " čnäoř"
                ipa = ipa + " t͡ʃnaːor"
            elif (word == "do" or word == "does"):
                outtext = outtext + "dëu"
                ipa = ipa + "geːu"
            elif (word == "else" or word == "other" or word == "otherwise"):
                outtext = outtext + " lëna"
                ipa = ipa + " leːna"
            elif (word == "ask" or word == "question"):
                outtext = outtext + " äfzøořçı"
                ipa = ipa + " aːfzøorʒɯ"
            elif (word == "answer"):
                outtext = outtext + " ëfzuřçı"
                ipa = ipa + " eːfzurʒɯ"
            elif (word == "word"):
                outtext = outtext + " đin"
                ipa = ipa + " ɟin"
            elif (word == "language"):
                outtext = outtext + " oopi"
                ipa = ipa + " oopi"
            elif (word == "text" or word == "document" or word == "book"):
                outtext = outtext + " řjieiţo"
                ipa = ipa + " rjieit͡so"
            elif (word == "long" or word == "thick" or word == "big" or word == "high"):
                outtext = outtext + " ukjäiçe"
                ipa = ipa + " ukjaːiʒe"
            elif (word == "short" or word == "thin" or word == "small" or word == "low"):
                outtext = outtext + " ukjëoçe"
                ipa = ipa + " ukjeːoʒe"
            elif (word == "vehicle" or word == "machine"):
                outtext = outtext + " imřäuë"
                ipa = ipa + " imraːueː"
            elif (word == "smart" or word == "clever"):
                outtext = outtext + " møid"
                ipa = ipa + " møig"
            elif (word == "stupid" or word == "idiot"):
                outtext = outtext + " mähıd"
                ipa = ipa + " maːhɯg"
            elif (word == "as"):
                outtext = outtext + "çy"
                ipa = ipa + "ʒy"
            elif (word == "always"):
                outtext = outtext + " onzë"
                ipa = ipa + " onzeː"
            elif (word == "color"):
                outtext = outtext + " ylgi"
                ipa = ipa + " yldi"
            elif (word == "full" or word == "ready" or word == "done"):
                outtext = outtext + " heueřø"
                ipa = ipa + " heuerø"
            elif (word == "can"):
                outtext = outtext + "dëi"
                ipa = ipa + "geːi"
            elif (word == "think" or word == "guess"):
                outtext = outtext + " däiäř"
                ipa = ipa + " gaːiaːr"
            elif (word == "about"):
                outtext = outtext + " hieřë"
                ipa = ipa + " hiereː"
            elif (word == "hi" or word == "hello" or word == "hey"):
                outtext = outtext + " häi"
                ipa = ipa + " haːi"
            elif (word == "bye"):
                outtext = outtext + " đoi"
                ipa = ipa + " ɟoi"
            elif (word == "too"):
                outtext = outtext + "çni"
                ipa = ipa + "ʒni"
            else:
                outtext = outtext + " " + word
                ipa = ipa + " " + word
    print("\nResults:\n\nLingaiopi: " + outtext)
    print("IPA: " + ipa)
    print("\nPress any key to translate more!")
    input()
    main()
main()
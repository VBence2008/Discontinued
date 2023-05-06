def v100():
    #try:
    import ctypes
    user32_100 = ctypes.windll.user32
    WIDTH_100 = user32_100.GetSystemMetrics(0)
    HEIGHT_100 = user32_100.GetSystemMetrics(1)
    import os
    os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"
    import pygame
    import button
    pygame.init()
    g100 = pygame.display.set_mode((WIDTH_100, HEIGHT_100))
    pygame.display.set_caption("ExHeroBros 1.0.0")
    print("Loading game, please wait...")
    e100_mainbg_raw = pygame.image.load("C:\Ex\ExHeroBros\\1.0.0\\1.0.0\img\\mainbg.png").convert_alpha()
    e100_mainbg = pygame.transform.scale(e100_mainbg_raw,(WIDTH_100,HEIGHT_100))
    e100_playbtn_raw = pygame.image.load("C:\Ex\ExHeroBros\\1.0.0\\1.0.0\img\\tile001.png").convert_alpha()
    e100_playbtn = pygame.transform.scale(e100_playbtn_raw,(WIDTH_100 / 10,HEIGHT_100 / 6))
    e100_makebtn_raw = pygame.image.load("C:\Ex\ExHeroBros\\1.0.0\\1.0.0\img\\tile087.png").convert_alpha()
    e100_makebtn = pygame.transform.scale(e100_makebtn_raw,(WIDTH_100 / 10,HEIGHT_100 / 6))
    e100_exitbtn_raw = pygame.image.load("C:\Ex\ExHeroBros\\1.0.0\\1.0.0\img\\tile052.png").convert_alpha()
    e100_exitbtn = pygame.transform.scale(e100_exitbtn_raw,(WIDTH_100 / 10,HEIGHT_100 / 6))
    g100run = True
    while g100run:
        e100_clock = pygame.time.Clock()
        e100_clock.tick()
        print(e100_clock.get_fps())
        #print(pygame.mouse.get_pos())
        g100.blit(e100_mainbg, (0,0))
        g100.blit(e100_playbtn, (WIDTH_100/2.25 - WIDTH_100/7,HEIGHT_100/2))
        g100.blit(e100_makebtn, (WIDTH_100/2.25,HEIGHT_100/2))
        g100.blit(e100_exitbtn, (WIDTH_100/2.25 + WIDTH_100/7,HEIGHT_100/2))
        pygame.display.update()
        if e100_playbtn.get_rect().collidepoint(pygame.mouse.get_pos()):
            e100_playbtn_pos = pygame.transform.scale(e100_playbtn, (WIDTH_100/10 + WIDTH_100/100,HEIGHT_100/6 + WIDTH_100/60))
            g100.blit(e100_playbtn_pos,((WIDTH_100/2.25 - WIDTH_100/7)-10,(HEIGHT_100/2)-10))
            pygame.display.update
            print("Touch!!!")
        else:
            g100.blit(e100_playbtn, (WIDTH_100/2.25 - WIDTH_100/7,HEIGHT_100/2))
            pygame.display.update()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                g100run = False
                pygame.quit()
                print("\nGame closed!\nPress any key to restart the launcher or you can exit safely!")
                input()
                start()
    pygame.quit()
    #except:
        #print("PY: ERROR\nPress any key to continue!")
        #input()
def start():
    #try:
        import os
        import ctypes
        ctypes.windll.kernel32.SetConsoleTitleW("ExHeroBros Launcher 1.0.0")
        os.system("cls")
        print("ExHeroBros Launcher 1.0.0\n2021-2022 Veress Bence Gyula\nAll rights reserved!\n\nStarting...")
        exdir = "C:\Ex"
        appdir = "C:\Ex\ExHeroBros"
        verdir = "C:\Ex\ExHeroBros\\1.0.0"
        if not os.path.exists(exdir):
            print("Please reinstall ExHeroBros Launcher!")
            input()
            exit()
        if not os.path.exists(appdir):
            print("Please reinstall ExHeroBros Launcher!")
            input()
            exit()
        if not os.path.exists(verdir):
            print("Please reinstall ExHeroBros Launcher!")
            input()
            exit()
        print("\nAvailable versions:")
        print("\n1.0.0 - 2021.12.03\n")
        selver = input("Enter version number to play: ")
        if (selver == "1.0.0"):
            v100()
        else:
            print("Invalid version number!\nPress any key to restart the launcher!")
            input()
            start()
    #except:
        #print("PY: ERROR\nPress any key to continue!")
        #input()
start()
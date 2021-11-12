from tkinter import *
from os import system

mainMenu = Tk()
mainMenu.title("Hello World!")

widht = 640
height = 360

widhtScreen = mainMenu.winfo_screenwidth()
heightScreen = mainMenu.winfo_screenheight()

coordenateWindowX = (widhtScreen/2) - (widht/2) 
coordenateWindowY = (heightScreen/2) - (height/2)
 
mainMenu.geometry(f"%dx%d+%d+%d" % (widht, height, coordenateWindowX, coordenateWindowY))
mainMenu.resizable(True, True)

mainMenu.iconbitmap("E:/GitHub/exercicios-faculdade/avaliacoes/testeproject/image/icon.ico")
mainMenu['bg'] = "#49A"

#mainMenu.minsize(widht = 640, height = 360)
#mainMenu.maxsize(widht = 1280, height = 768)

#mainMenu.state("zoomed") Fullscreen
#mainMenu.state("iconic") Minimizado

label1 = Label(mainMenu, text="Label 1")
label1['bg'] = "#49A"
label1.pack()

def btnClick(text):
    print(text)

def clearScreen():
    system("cls")

btnExecute = Button(mainMenu, text="Executar", command=lambda: btnClick("Olá, Mundo!"))
btnExecute['bg'] = "#f9eac3"
btnExecute.pack()
btnClear = Button(mainMenu, text="limpar cmd", command=clearScreen)
btnClear['bg'] = "#f9eac3"
btnClear.pack()

mainMenu.mainloop()
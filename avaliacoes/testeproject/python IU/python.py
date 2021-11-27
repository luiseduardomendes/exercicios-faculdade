from tkinter import *
from os import system, times
from tkinter import font
from typing import Sized
from PIL import Image,ImageTk

mainMenu = Tk()
mainMenu.title("Hello World!")

widht = 640*2
height = 360*2

widhtScreen = mainMenu.winfo_screenwidth()
heightScreen = mainMenu.winfo_screenheight()

coordenateWindowX = (widhtScreen/2) - (widht/2) 
coordenateWindowY = (heightScreen/2) - (height/2)
 
mainMenu.geometry(f"%dx%d+%d+%d" % (widht, height, coordenateWindowX, coordenateWindowY))
mainMenu.resizable(True, True)

#mainMenu.iconbitmap("icon.ico")
mainMenu['bg'] = "#2c2d31"

#mainMenu.minsize(widht = 640, height = 360)
#mainMenu.maxsize(widht = 1280, height = 768)

#mainMenu.state("zoomed") Fullscreen
#mainMenu.state("iconic") Minimizado

plotOpen = 0
resizeScale = 2

def btnClick(text):
    print(text)

def clearScreen():
    system("cls")



label1 = Label(mainMenu, text="Leitor de gráficos: ",
                bg="#2c2d31",
                fg="#a9a8a2",
                font="arial 20 ",
                height=5)

btnExecute = Button(mainMenu, text="Executar", command=lambda: btnClick("Olá, Mundo!"))
btnExecute['bg'] = "#373736"
btnExecute['fg'] = "#c8c5c2"
btnExecute['height'] = 1

btnShowPlot1 = Button(mainMenu, text="Mostrar plot 1", command=lambda: showPlot(labelImage1))
btnShowPlot1['bg'] = "#373736"
btnShowPlot1['fg'] = "#c8c5c2"
btnShowPlot1['height'] = 1

btnShowPlot2 = Button(mainMenu, text="Mostrar plot 2", command=lambda: showPlot(labelImage2))
btnShowPlot2['bg'] = "#373736"
btnShowPlot2['fg'] = "#c8c5c2"
btnShowPlot2['height'] = 1


btnClear = Button(mainMenu, text="limpar cmd", command=clearScreen)
btnClear['bg'] = "#373736"
btnClear['fg'] = "#c8c5c2"
btnClear['height'] = 1

img1 = Image.open("plot1.png")
image_resized = img1.resize((widhtScreen//resizeScale,heightScreen//resizeScale), Image.ANTIALIAS)
img1 = ImageTk.PhotoImage(image_resized)
labelImage1 = Label(image=img1)

img2 = Image.open("plot2.png")
image_resized = img2.resize((widhtScreen//resizeScale,heightScreen//resizeScale), Image.ANTIALIAS)
img2 = ImageTk.PhotoImage(image_resized)
labelImage2 = Label(image=img2)

def showPlot(labelUsed):
    global plotOpen
    if(plotOpen == 0):
        labelUsed.pack()
        plotOpen = 1
    elif(plotOpen == 1):
        labelUsed.pack_forget()
        plotOpen = 0

label1.pack()

btnShowPlot1.pack()
btnShowPlot2.pack()



mainMenu.mainloop()



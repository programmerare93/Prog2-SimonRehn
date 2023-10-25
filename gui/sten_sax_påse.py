import random
from tkinter import *

valid_inputs = ["sten", "sax", "påse"]


def player_won(player_move, computer_move) -> bool:
    if player_move == computer_move:
        return False
    elif player_move == "sten":
        return computer_move == "sax"
    elif player_move == "sax":
        return computer_move == "påse"
    elif player_move == "påse":
        return computer_move == "sten"


def play(player_move):
    if not player_move in valid_inputs:
        lbl["text"] = f"Ogilltig input! Ange en av {str(valid_inputs)}"
        return

    computer_move = random.choice(valid_inputs)
    if player_won(player_move, computer_move):
        lbl["text"] = f"Du vann! Datorn valde {computer_move}"
    else:
        if player_move == computer_move:
            lbl["text"] = f"Oavgjort! Datorn valde också {computer_move}"
        else:
            lbl["text"] = f"Du förlorade! Datorn valde {computer_move}"


def click_handler(self):
    play(e.get().lower())


root = Tk()
root.title("Sten, Sax, Påse")
root.geometry("500x500")

description = Label(root)
description["text"] = "Sten, Sax, Påse!"
description.pack()

e = Entry(root)
e.pack()

b = Button(root, text = "Enter")
b.bind("<Button-1>", click_handler)
b.pack()

lbl = Label(root)
lbl.pack()

root.mainloop()

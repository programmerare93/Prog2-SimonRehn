import tkinter as tk
from tkinter import ttk
from tkinter import messagebox

WIDTH = 600
HEIGHT = 600

ENTER = 13

RACES = [
    "Människa",
    "Orc",
    "Alv"
]

# TODO: Undersök om bättre design finns utan global variable
character_name = ""
character_race = ""

def key_press(event: tk.Event):
    if event.keycode == ENTER:
        character_name = event.widget.get()
        messagebox.showinfo(title="Namn", message=character_name)

def race_select():
    character_race = race_box.get()
    messagebox.showinfo(title="Ras", message=character_race)

def name_selection_setup(frame: tk.Frame) -> tk.Frame:
    name_label = tk.Label(frame, text="Personens namn")
    name_label.pack(side=tk.LEFT)

    name_entry = tk.Entry(frame, bd=5)
    name_entry.bind("<KeyPress>", key_press)
    name_entry.pack()

    return frame

def race_selection_setup(frame: tk.Frame) -> tk.Frame:
    race_label = tk.Label(frame, text="Ras")
    race_label.pack(side=tk.LEFT)

    global race_box # TODO: Se om det finns bättre sätt att komma åt variabel i race_select()
    race_box = ttk.Combobox(frame, state="readonly", values=RACES)
    race_box.pack()

    race_button = ttk.Button(frame, command=race_select, text="Välj ras")
    race_button.pack()

    return frame

def job_selection_setup(frame: tk.Frame) -> tk.Frame:
    return frame

def main():
    root = tk.Tk()
    root.title("Drakar och Demoner")
    root.geometry(f"{WIDTH}x{HEIGHT}")

    #name_selection_setup(tk.Frame(root)).grid(row=1, column=1)
    #race_selection_setup(tk.Frame(root)).grid(row=2, column=1)
    #job_selection_setup(tk.Frame(root)).grid(row=3, column=1)
    name_selection_setup(tk.Frame(root)).pack()
    race_selection_setup(tk.Frame(root)).pack()
    job_selection_setup(tk.Frame(root)).pack()

    root.mainloop()

if __name__ == "__main__":
    main()

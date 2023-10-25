import tkinter as tk

# TODO: Omstrukturer klass så att menubar setup inte tillhör fönstret
class Window:
    def __init__(self, title: str, width: int, height: int):
        self.root = tk.Tk()
        self.root.title(title)
        self.root.geometry(f"{width}x{height}")
        self.__menubar_setup()

    def mainloop(self):
        self.root.mainloop()

    def __menubar_setup(self):
        menubar = tk.Menu(self.root)

        file_menu = tk.Menu(menubar, tearoff=False)
        self.__file_menu_setup(file_menu)
        menubar.add_cascade(menu=file_menu, label="File")

        edit_menu = tk.Menu(menubar, tearoff=False)
        self.__edit_menu_setup(edit_menu)
        menubar.add_cascade(menu=edit_menu, label="Edit")

        self.root.config(menu=menubar)

    def __donothing(self):
        pass

    def __close(self):
        self.root.destroy()


    def __file_menu_setup(self, file_menu: tk.Menu):
        file_menu.add_command(
            label="New File",
            command=self.__donothing
        )

        file_menu.add_command(
            label="Open File",
            command=self.__donothing
        )

        file_menu.add_command(
            label="Close File",
            command=self.__donothing
        )

        file_menu.add_separator()
        file_menu.add_command(
            label="Exit",
            command=self.__close
        )


    def __edit_menu_setup(self, edit_menu):
        edit_menu.add_command(
            label="TODO: Add commands",
            command=self.__donothing
        )


def main():
    window = Window("VSCode 2", 600, 600)
    window.mainloop()


if __name__ == "__main__":
    main()

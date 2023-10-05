
# CTodo

A Todo list maker written in C. This is a CLI project that allows users to create task descriptions (Just Strings), and save them to a file. Then the tasks are loaded up again when the program is ran and the user can continue to modify them. A basic project to help me lean C.




## Requirements
The only requirment is that [make](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows) needs to be installed to build the project.
## Installation

Clone this project with Github CLI

```bash
  git clone https://github.com/IssiahB/CTodo.git
  cd CTodo
```

Then once inside the projects root directory simply run the make command
```bash
  make
```

This will build the .o object files and place them in the /build folder, then create the executable and place it in the /bin folder.
    
## Usage/Examples
Finally to run the project just execute the executable.

```bash
    bin/main
```

The rest is pretty self explanitory you can use 4 different commands.

`create`, `delete`, `list`, and `quit`

## Author

- [@Issiah Banda](https://www.github.com/IssiahB)
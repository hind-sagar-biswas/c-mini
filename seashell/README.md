# Sea-(C)-Shell

```
             _.---._
         .'"".'/|\`.""'.
        :  .' / | \ `.  :
        '.'  /  |  \  `.'
         `. /   |   \ .'
           `-.__|__.-'
                      _          _ _
                     | |        | | |
   ___  ___  __ _ ___| |__   ___| | |
  / __|/ _ \/ _` / __| '_ \ / _ \ | |
  \__ \  __/ (_| \__ \ | | |  __/ | |
  |___/\___|\__,_|___/_| |_|\___|_|_|
```

![Project Language](https://img.shields.io/static/v1?label=language&message=C&color=grey)
![Project Type](https://img.shields.io/static/v1?label=type&message=application&color=red)
<!--![Stable Version](https://img.shields.io/static/v1?label=stable-version&message=v0.4.2&color=brightgreen)-->
<!--![Latest Version](https://img.shields.io/static/v1?label=latest-version&message=v0.4.2&color=yellow)-->
![Maintained](https://img.shields.io/static/v1?label=maintained&message=yes&color=green)
![License](https://img.shields.io/static/v1?label=license&message=MIT&color=orange)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/hind-sagar-biswas/c-mini/pulls)

A mini shell made in C programming language.

## Installation

To build the shell, run `./install.sh` in the root directory.

```
chmod +x install.sh
./install.sh
```

To run directly after installation:

```
chmod +x install.sh
./install.sh --run
```

## Usage

```
seashell [options] <..files>
```

### Options:

      -h, --help                Show this message, then exit.
      -v, --version             Show the version number, then exit.
      -i, --info                Run the shell with welcome message `info`.
      -r, --rc <file>           Run the shell with the given rc file. Defaults to ~/.cslrc

### Commands:

      cd <path>                 Change the current working directory.
      pwd                       Print the current working directory.
      cls                       Clear the screen.
      info                      Print information about the shell.
      alias                     List all aliases.
      alias <name>              Print the value of an alias.
      alias <name> <command>    Create an alias.
      unalias <name>            Remove an alias.
      exit                      Exit the shell.
 
## RC File

The rc file is a text file that contains commands that are executed when the shell is run. The file is read from the given path, or the default path `~/.cslrc` if no path is given.

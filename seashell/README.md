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

A mini shell made in C programming language.

## Usage

```
seashell [options] <..files>
```

## Options:

      -h, --help                Show this message, then exit.
      -v, --version             Show the version number, then exit.
      -i, --info                Run the shell with welcome message `info`.
      -r, --rc <file>           Run the shell with the given rc file. Defaults to ~/.cslrc

## Commands:

      cd <path>                 Change the current working directory.
      pwd                       Print the current working directory.
      cls                       Clear the screen.
      info                      Print information about the shell.
      alias                     List all aliases.
      alias <name>              Print the value of an alias.
      alias <name> <command>    Create an alias.
      unalias <name>            Remove an alias.
      exit                      Exit the shell.
 

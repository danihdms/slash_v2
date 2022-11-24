# slash, small laudable shell

A small shell written in C.

## Features

- [ ] Prompt new line after command
- [ ] Wildcard
  - [ ] `*`: all prefixes of basename that do not begin with a `.`
  - [ ] `**/`: all prefixes of physical paths that do not begin with a `.`
  - [ ] `?`: match any single character
- [ ] Internal commands
  - [ ] `cd [-L | -P] [ref | -]`: change current directory to `ref` or
    previous directory if `-` is given (by default change to home directory)
  - [ ] `exit [val]`: exit shell with optional return value (default 0)
  - [ ] `pwd [-L | -P]`: print current directory (default `-L`), `-P` for
    absolute physical path and `-L` for absolute logical path
  - [ ] `env`: print environment variables
  - [ ] `history`: show history current session
- [ ] Executing external commands
- [ ] Redirection
  - [ ] `cmd < fic`: redirect standard input of `cmd` to `fic`
  - [ ] `cmd > fic`: redirect standard output of `cmd` to `fic` **without
    truncating it**
  - [ ] `cmd >| fic`: redirect standard output of `cmd` to `fic` **by truncating
    it.**
  - [ ] `cmd >> fic`: redirect standard output of `cmd` to `fic` **by
    appending**
  - [ ] `cmd 2> fic`: redirect standard error of `cmd` to `fic` **without
    truncating it**
  - [ ] `cmd 2>| fic`: redirect standard error of `cmd` to `fic` **by truncating
    it.**
  - [ ] `cmd 2>> fic`: redirect standard error of `cmd` to `fic` **by
    appending**
  - [ ] `cmd1 | cmd2`: redirect standard output of `cmd1` and standard input
    of `cmd2` on the same anonymous pipe
- [ ] Signals
  - [ ] Make sure that the shell is not killed by a signal
  - [ ] `SIGINT`: interrupt current process
  - [ ] `SIGTERM`: terminate current process
- [ ] Environment variables
- [ ] History

## Authors

see [AUTHORS](AUTHORS.md)

## Architecture

see [ARCHITECTURE](ARCHITECTURE.md)

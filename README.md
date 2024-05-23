<h2 align="center">🧪 Welcome to:</h2>
<h1 align="center">Pipex</h1>
<p style="text-align: justify;" align="center">
  This project allows you to handle pipes and execute commands as if you were using the shell's pipe functionality, making it useful for complex command chaining in your C programs.
</p>
<h3 align="center">Languages and Tools:</h3>
<p align="center">
    <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/>
    <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/>
</p>

## Installation
To use the pipex function in your project, follow these steps:

- Clone the repository in the directory where you want to work.
- Edit the Makefile if necessary to suit your project structure.
- Use the provided Makefile to compile the project.
  
Example compilation and execution command:

```
make
$> ./pipex infile "command1" "command2" outfile
```

## Features
- Handles pipes between commands.
- Supports redirection of input and output files.
- Manages error handling and memory allocation efficiently.
- Easily integrates into C projects for shell-like command execution.

## Usage
The pipex program should be executed with the following arguments:

```
$> ./pipex file1 command1 command2 file2
```

Where:

- file1 is the input file.
- file2 is the output file.
- command1 and command2 are shell commands with their respective parameters.
  
The execution of the pipex program should achieve the same result as the following shell command:

```
$> < file1 command1 | command2 > file2
```

## Example

```
$> ./pipex infile "ls -l" "wc -l" outfile
```
This command should perform the same operation as:
```
$> < infile ls -l | wc -l > outfile
```


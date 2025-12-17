# Minishell

A bash-like shell implementation in C.

## About

Minishell is a fully functional UNIX shell that replicates core bash features including command execution, pipes, redirections, and environment variables.

## Features

- **Command execution** with PATH resolution
- **Pipes** (`|`) for connecting commands
- **Redirections** (`<`, `>`, `>>`, `<<`)
- **Quote handling** (single and double quotes)
- **Environment variables** (`$VAR`, `$?`)
- **Signal handling** (ctrl-C, ctrl-D)
- **Command history**

### Built-in Commands
`echo` • `cd` • `pwd` • `export` • `unset` • `env` • `exit`

## Installation
```bash
git clone [your-repository-url] minishell
cd minishell
make
./minishell
```
make sure you have the `readline` library installed.

## Usage Examples
```bash
# Basic commands
echo Hello World
pwd
ls -la

# Echo with -n flag
echo -n "No newline"

# Redirections
echo "test" > file.txt
cat < file.txt
echo "append" >> file.txt

# Here-document
cat << EOF
Line 1
Line 2
EOF

# Pipes
ls | grep minishell
cat file.txt | wc -l | cat -e

# Environment variables
export USER=john
echo $USER
echo $?

# Quotes
echo '$USER'        # prints: $USER
echo "$USER"        # prints: john

# Built-ins
cd /tmp
pwd
unset USER
env
exit
```

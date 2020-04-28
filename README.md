# 42_push_swap

## The “checker” program
The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```
## The “push_swap” program
The second one called push_swap which calculates and displays on the standard
output the smallest progam using Push_swap instruction language that sorts integer arguments received.
There’s only a few moves you’re allowed to used to manipulate the stacks that we’re going to called “Actions”. The main goal of this project is to organize Stack A in as few actions as possible.

```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

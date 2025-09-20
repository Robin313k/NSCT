NSCT stands for Number System Conversion Tool

How to install:
-execute $ gcc main.c -o NSCT
-execute $ sudo cp NSCT /usr/bin/.

OR

-execute $ sudo bash install_and_implement.sh




Usage: NSCT [decimal number] [flags]
Example: NSCT 1001 --bin --rev
Options:
  --help                   Display this information.\n
   -h                      Display this information.\n
  --bin                    Tells the programm to convert decimal to binary.
  --hex                    Tells the programm to convert decimal to hexadecimal.
  --rev                    Tells the programm to convert from hexadecimal or binary to decimal. (must be used with '--bin' or '--hex' in combination)

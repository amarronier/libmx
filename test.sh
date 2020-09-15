rm -rf a.out
clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c -I inc/ libmx.a -lm
./a.out

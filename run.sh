rm a.out
gcc main.c srcs/build.c srcs/conversions.c srcs/ft_printf.c srcs/ft_vprintf.c srcs/handle_length.c srcs/modifiers.c srcs/handle_diuox.c srcs/handle_scp.c srcs/handle_extra.c libftprintf.a -g
./a.out

cd libft
make re
cd ..
clear
gcc -I /usr/local/include -I -r libft/libft.a main.c ft_open_proc.c lstworker.c ft_strwork.c ft_getnbr.c bresen.c get_next_line.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o fdf
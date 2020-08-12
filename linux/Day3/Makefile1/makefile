#obj = add.o main.o mul.o sub.o
src = $(wildcard ./*.c)
obj = $(patsubst %.c, %.o, $(src))
target = app
$(target):$(obj)
	gcc $^ -o $@
#	gcc $(obj) -o $(target)

%.o:%.c
	gcc -c $< -o $@

#
#add.o:  add.c
#	gcc add.c -c
#main.o: main.c
#	gcc main.c -c
#mul.o:  mul.c
#	gcc mul.c -c
#sub.o:  sub.c
#	gcc sub.c -c

hello:
	echo "hello,makefile"
.PHONY:clear
clear:
	-mkdir /abc
	-rm -rf $(obj) $@
	-rm -rf /abc





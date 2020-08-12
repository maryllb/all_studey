CC=gcc
target=app
inc=./include

src=$(wildcard ./src/*.c)
obj=$(patsubst %.c, %.o, $(src))



$(target):$(obj)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $< -I $(inc) -o $@ 

.PHONY:clean
clean:
	-rm -rf $(obj)






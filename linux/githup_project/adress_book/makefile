CC=gcc
CFLAGS = -w -lncurses
target=address_book
inc=./include

src=$(wildcard ./src/*.c)
obj=$(patsubst %.c,%.o,$(src))


$(target):$(obj)
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c
	$(CC) -c $< -I $(inc) -o $@	$(CFLAGS)

.PHONY:clean_o
clean_o:
	-rm -rf $(obj)
.PHONE:clean_target
clean_target:
	-rm -rf $(target)

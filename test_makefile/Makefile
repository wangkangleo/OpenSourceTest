#need_compile_files := test_makefile.c
need_compile_files := $(wildcard *.c)   # wildcard通配符

#test string
str := this is a test string

test_makefile_cFile: $(need_compile_files)
	cc test_makefile.c -o test_makefile_cFile


.PHONY: always_execute
always_execute:
	echo "always_execute because of .PHONY" > always_execute


test: $(wildcard *.c)   # wildcard通配符
	printf '$(str) in file $@\n'   # $@ 代表文件名,此处指代 test
	ls -la $?   # 比现在新的依赖
	ls -la $^   # 所有依赖
	ls -la $<   # 第一个依赖

all: a.o b.o c.o
a.o : a.c
b.o : b.c
c.o : c.c
%.c:
	echo '%.c代表当前所有.c文件'
	touch $@

clean:
	rm -f always_execute
#网址: https://makefiletutorial.com/

#need_compile_files := test_makefile.c
need_compile_files := $(wildcard *.c)   # wildcard通配符

#test string
str := this is a test string  # =符号直接替换(官方名称: 递归)  :=视为变量(官方名称: 简单扩展)

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

#简写1 开始 核心:(%.c:)
all: all.c a.o b.o c.o

all.c:
	echo "int main(){return 0;}" > $@


a.o : a.c
b.o : b.c
c.o : c.c

%.c:
	echo '%.c代表当前所有.c文件'
	touch $@
#简写1 结束

#简写2 开始 (使用了简写1中的 %.c:)
object := a.o b.o c.o


$(object): %.o: %.c   # 用%做匹配   #注意1:  a.o : a.c这种会默认用c方式生成.o文件 注意2: 会和底下的object2冲突,因为两者都包含了同样的文件
	echo '执行 $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@'
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@   # CFLAGS 和 CPPFLAGS 暂时未指定

object2 := a.o b.o c.o test.res   #如果项目中没有test.res,会尝试创建,可能会导致错误

$(filter %.o, $(object2)): %.o: %.c   # filter提取(仅处理.o文件)  #注意1:  a.o : a.c这种会默认用c方式生成.o文件 注意2: 会和上面的object冲突,因为两者都包含了同样的文件
	@echo "target: $@  prereq: $<"    # 使用 @echo 会使自身这一行不会重复打印
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@   # CFLAGS 和 CPPFLAGS 暂时未指定

all2: $(object2)

all2.c:
	echo "int main(){return 0;}" > $@

#简写2 结束


one=this will only work locally
export two=we can run subcommands with this


# Recursive variable. This will print "later" below
one2 = one ${later_variable}
# Simply expanded variable. This will not print "later" below
two2 := two ${later_variable}   #定义变量时 later_variable 是空的
later_variable = later
#one2 = $(one2) append  这种会引发死循环(因为是使用时替换) 使用:=会解决此问题

one ?= will not be set # 如果 one 之前没有,则会被赋值

nullstring =
space = $(nullstring) # Make a variable with a single space.  # 一个空格字符
#echo $(nowhere)  # 空字符串 (注意: 不能写在这里)
space += append string  #追加

# Overrides command line arguments
override option_one = did_override  #重写传来的命令
# Does not override command line arguments
option_two = not_override



# 命令部分 可从此处开始阅读
test_shell:
	cd ..   #换行后 是一条新的命令
	# The cd above does not affect this line, because each command is effectively run in a new shell
	echo `pwd`
	# This cd command affects the next because they are on the same line
	cd ..;echo `pwd`
	# Same as above  \可以换行
	cd ..; \
	echo `pwd`
	# Same as running "sh_var='I am a shell variable'; echo $sh_var" in the shell   # 双$符号用于执行shell命令
	sh_var='I am a shell variable'; echo $$sh_var

	# Run this with "export shell_env_var='I am an environment variable'; make" #修正为 export shell_env_var='I am an environment variable'; make test_shell
	# Print out the Shell variable
	echo $$shell_env_var
	# Print out the Make variable
	echo $(shell_env_var)

	@echo $(one)
	@echo $$one   #这个取自shell环境而且没有export所以打印不出来
	@echo $(two)
	@echo $$two

	@echo $$new_contents

	@echo $(one2)
	@echo $(two2)

	#运行 make test_shell option_one=hi option_two=two  (option_one在上面被重写了)
	@echo $(option_one)
	@echo $(option_two)

	@echo $(three)  #不是全局的(定义在下方)

	@echo 传入的flags: $(MAKEFLAGS)  #运行 make test_shell -i  (打印 i)

test_shell: three = '在这定义不是全局的'
test_shell2:
	echo $(three)  # three在上方,不是全局的


#shell_env_var=Shell env var, created inside of Make  # 赋值为字符串
#export shell_env_var    # 改环境变量 (全局的)

.EXPORT_ALL_VARIABLES:
new_contents = "放在 .EXPORT_ALL_VARIABLES 底下可以直接变成全局的环境"

#SHELL=/home/wangkang/Code  #改shell的目录


#下面是 字符串 及 逻辑部分(条件和函数) 
foo = ok
nullstring2 =
foo2 = $(nullstring2) # end of line; there is a space here
bar := ${subst not,"totally", "I am not superman"}# 字符串替换(not 替换为 totally)
comma := ,# ,符号前面的空格会被忽视 而后面的空格不会被忽视
empty:=
space := $(empty) $(empty)
foo3 := a b c
bar3 := $(subst $(space),$(comma),$(foo3))# bar := $(subst $(space), $(comma) , $(foo)) # Watch out! 如果这样,$(comma)后面的空格会被替换进去

foo4 := a.o b.o l.a c.o
one4 := $(patsubst %.o,%.c,$(foo4))# 字符串替换(%.o匹配)
# This is a shorthand for the above
two4 := $(foo4:%.o=%.c)
# This is the suffix-only shorthand, and is also equivalent to the above.
three4 := $(foo4:.o=.c)

bar5 := $(foreach wrd,$(foo4),$(wrd)!)# 通过 foreach 添加感叹号

foo6 := $(if this-is-not-empty,then!,else!)# 类似三目运算符?:

sweet_new_fn = Variable Name: $(0) First: $(1) Second: $(2)# $(0)是变量名(即sweet_new_fn) $(1)开始为参数

test_logic:
ifeq ($(foo), ok)
	@echo "foo equals ok"
else
	@echo "nope"
endif
ifeq ($(strip $(foo2)),)     #去除两端空格
	@echo "foo is empty after being stripped"
endif
ifeq ($(nullstring2),)
	@echo "nullstring doesn't even have spaces"
endif
ifdef foo
	@echo "foo is defined"
endif

	@echo $(bar)

	@echo $(bar3)

	@echo $(one4)
	@echo $(two4)
	@echo $(three4)

	@echo $(bar5)

	@echo $(foo6)

	@echo $(call sweet_new_fn, 1, 2)# 函数

	@echo $(shell ls -la)# 调用shell函数 #会将输出内容的换行符替换为空格 Very ugly because the newlines are gone!

	@echo 同时过滤两个: $(filter %.o %.res, $(object2))
	@echo 除.h文件外:  $(filter-out %.h, $(object2))
	@echo 以.o结尾但不以a开头的文件:  $(filter %.o, $(filter-out a%, $(object2)))


.DELETE_ON_ERROR:#错误时删除
all7: one7 two7

one7:
	touch one7
	false

two7:
	touch two7
	false


clean:
	rm -f always_execute
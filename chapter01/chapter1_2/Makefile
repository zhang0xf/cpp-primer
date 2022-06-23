# 设置变量
SRCS = $(wildcard *.cpp)
NODIR_SRCS = $(notdir $(SRCS))
TARGETS = $(basename $(NODIR_SRCS))
FILE_EXISTS = 1

.PHONY:all clean

# 检查是否有未生成的文件,如果有,重新生成
# ifeq:用于控制make在Makefile看到的内容,不能用于make执行时！
# $()用法:1.函数调用(包含自定义函数);2.shell调用;3.取变量值.
# wildcard函数,测试文件是否存在
# eval函数修改变量值
# if函数: $(if <condition>,<then-part>,<else-part>). condition为非空字符串则返回真！
# 另见chapter1_3:Makefile
# $(shell [ condition ] && text)整个作为if的condition
# 存在问题:mv文件时,编译尚未完成!!!
all:
	@#echo $(FILE_EXISTS)
	$(foreach t, $(TARGETS), \
		$(if $(wildcard $(WORKDIR)/bin/$t), \
		$(eval FILE_EXISTS=1), \
		$(if $(wildcard ./$t), $(eval FILE_EXISTS=1), $(eval FILE_EXISTS=0))) )

	@#echo $(FILE_EXISTS)
	$(if $(shell [ $(FILE_EXISTS) -eq 0 ] && echo true), $(foreach c, $(NODIR_SRCS), $(CC) $c $(CFLAGS) $(LIBFLAGS) -o $(basename $c)) )

	$(foreach t, $(TARGETS), \
		$(if $(wildcard $(shell pwd)/$t), @mv $t $(WORKDIR)/bin) )


clean:
	@for target in $(TARGETS); do \
		if [ -e $$target ]; then \
			rm $$target -rf; \
		fi \
	done

# 设置变量
CUR_DIRS = $(shell pwd)
SRCS = $(wildcard *.cpp)
NODIR_SRCS = $(notdir $(SRCS))
TARGETS = $(basename $(NODIR_SRCS))

# ifeq:用于控制make在Makefile看到的内容,不能用于make执行时！

all:
	$(foreach s, $(NODIR_SRCS), \
		 $(CC) $s $(CFLAGS) $(LIBS) -o $(WORKDIR)/bin/$(basename $s); )

clean:
	$(foreach t, $(TARGETS), \
		$(if $(wildcard $(CUR_DIRS)/$t), $(shell rm $t -rf;)) )

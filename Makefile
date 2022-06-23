# 设置变量: export声明环境变量,使子目录Makefile可以使用该变量
CC = g++
export WORKDIR = $(shell pwd)
SUBDIRS = $(shell find $(WORKDIR) -maxdepth 5 -type d | grep 'chapter[0~9]')
export CFLAGS = -Wall -Wextra -Werror -g
export LIBFLAGS = -lstdc++

#.PHONY指定伪目标,Makefile默认目标是一个文件
.PHONY:all clean

all:
	@echo "make start"

	@# 注释:创建bin目录
	@if [ ! -d $(WORKDIR)/bin ]; then \
		mkdir bin; \
	fi

	@# 注释:如果目录中存在Makefile文件,才执行make -C
	@for dir in $(SUBDIRS); do \
		if [ -e $$dir/Makefile ]; then \
			make -C $$dir all; \
		fi \
	done
	
	@echo "make end"

clean:
	@echo "make clean start"
	
	@# 注释:如果目录中存在Makefile文件,才执行make -C
	@for dir in $(SUBDIRS); do \
		if [ -e $$dir/Makefile ]; then \
			make -C $$dir clean; \
		fi \
	done
	
	@rm $(WORKDIR)/bin/* -rf
	
	@echo "make clean end"
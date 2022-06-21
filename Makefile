# 设置变量: export声明环境变量,使子目录Makefile可以使用该变量
CC = g++
WORKDIR = .
SUBDIRS = $(shell find $(WORKDIR) -maxdepth 5 -type d | grep 'chapter[0~9]')
export CFLAGS = -Wall -Wextra -Werror -g
export LIBFLAGS = -lstdc++

#.PHONY指定伪目标,Makefile默认目标是文件
.PHONY:all clean

all:
	@echo "make start"

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
	
	@echo "make clean end"
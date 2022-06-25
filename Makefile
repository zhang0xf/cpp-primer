# 编译器
CC = g++

# export声明环境变量
export WORKDIR = $(shell pwd)
export CFLAGS = -Wall -Wextra -Werror -g
export LIBS = -lstdc++

# 子目录
CHAPTER_01 = $(shell find $(WORKDIR)  -mindepth 1 -maxdepth 1 -type d | grep 'chapter01')
CHAPTER_02 = $(shell find $(WORKDIR)  -mindepth 1 -maxdepth 1 -type d | grep 'chapter02')
CHAPTER_03 = $(shell find $(WORKDIR)  -mindepth 1 -maxdepth 1 -type d | grep 'chapter03')
CHAPTER_05 = $(shell find $(WORKDIR)  -mindepth 1 -maxdepth 1 -type d | grep 'chapter05')
CHAPTER_06 = $(shell find $(WORKDIR)  -mindepth 1 -maxdepth 1 -type d | grep 'chapter06')

# 伪目标
.PHONY:clean

all:
	@#创建bin目录
	@if [ ! -d $(WORKDIR)/bin ]; then \
		mkdir bin; \
	fi

	@echo "make"

	make -C $(CHAPTER_01) all;
	make -C $(CHAPTER_02) all;
	make -C $(CHAPTER_03) all;
	make -C $(CHAPTER_05) all;
	make -C $(CHAPTER_06) all;
	
	@echo "make end."

clean:
	@echo "make clean"
	
	make -C $(CHAPTER_01) clean;
	make -C $(CHAPTER_02) clean;
	make -C $(CHAPTER_03) clean;
	make -C $(CHAPTER_05) clean;
	make -C $(CHAPTER_06) clean;

	@rm $(WORKDIR)/bin/* -rf
	
	@echo "make clean end"
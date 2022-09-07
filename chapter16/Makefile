CUR_DIRS = $(shell pwd)
SUB_DIRS = $(shell find $(CUR_DIRS) -mindepth 1 -maxdepth 2 -type d | grep 'chapter16')

all:
	@#echo $(SUB_DIRS)
	@for dir in $(SUB_DIRS); do \
		if [ -e $$dir/Makefile ]; then \
			make -C $$dir all; \
		fi \
	done

clean:
	@for dir in $(SUB_DIRS); do \
		if [ -e $$dir/Makefile ]; then \
			make -C $$dir clean; \
		fi \
	done

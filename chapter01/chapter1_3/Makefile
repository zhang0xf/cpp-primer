# demno
# 设置变量
LIBS := a testb ctest d e
IS_TEST = $(findstring test, $L)
LIB_RULE = $(info LIB_COPY $1)
TEST_RULE = $(info TEST_COPY $1)

all:

test:
	$(foreach L, $(LIBS), $(if $(call IS_TEST,$L),$(call TEST_RULE, $L),$(call LIB_RULE, $L)) )

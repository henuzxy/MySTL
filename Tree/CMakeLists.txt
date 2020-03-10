# find all the source file in directory
# save in DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(Tree ${DIR_LIB_SRCS})
# Directories
src_dir = source
inc_dir = include
lib_dir = lib

# Output Parameters
out_dir  = out
out_file = Dot

# Source Parameters
src_files = source/*.cpp
inc_dirs  = -I${inc_dir} -I${lib_dir}/include

# Library Parameters
lib_dirs = -L${lib_dir}/bin
lib_list = 

# Warning Flags
warn_flags = -Wall -Werror --pedantic

# Optimization Flags
op_flags = -O3

setup:
	@echo Creating required directories...
	@echo ================
	mkdir ${out_dir}
	mkdir lib
	mkdir lib/bin
	mkdir lib/include

build:
	@echo Building Dot...
	@echo ================
	g++ ${src_files} -o ${out_dir}/${out_file} ${inc_dirs} ${lib_dirs} ${lib_list} ${warn_flags}
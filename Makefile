# Options

	# "Debug", "Release"
	opt_target = Debug

# Directories

	dir_build     = build
	dir_libraries = libraries
	dir_include   = include
	dir_source    = source

# Flags

	flag_warn = -Wall
	flag_misc = --pedantic

# Compiler Parameters

	param_out    = -o ${dir_build}/Dot
	param_source = $(wildcard ${dir_source}/*.c ${dir_source}/cells/*.c)
	param_incdir = -I${dir_include} -I${dir_libraries}/include
	param_libdir = -Llibraries/bin
	param_libs   = -lSDL3
	param_flags  = ${flag_warn} ${flag_misc}
	params = 

	ifeq ($(opt_target), Release)
		# TODO: Change -mwindows to something else if it is, in fact, Windows-only
		param_flags := $(param_flags) -O3 -mwindows
	endif
	ifeq ($(opt_target), Debug)
		param_out := $(param_out)_debug
		param_flags := $(param_flags) -g
	endif

	params = ${param_flags} ${param_out} ${param_source} ${param_incdir} ${param_libdir} ${param_libs}

setup:
	@echo Creating required directories...
	@echo ================
	mkdir ${dir_build}
	mkdir ${dir_libraries}
	mkdir ${dir_libraries}/bin
	mkdir ${dir_libraries}/include

m_build:
	@echo Building Dot (${opt_target})...
	@echo ================
	gcc ${params}
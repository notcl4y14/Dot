CC := gcc
PARAMS := -g -o build/Dot $(wildcard source/*.c) -Iinclude

setup:
	@echo Creating required directories...
	@echo ================
	mkdir build
	mkdir external

dot:
	@echo Building Dot...
	@echo ================
	$(CC) $(PARAMS)
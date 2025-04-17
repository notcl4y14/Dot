CC := gcc
PARAMS := -g -o build/Dot $(wildcard source/*.c) -Iinclude -Iexternal/CSFML/include -Lexternal/CSFML/bin -lcsfml-window-2 -lcsfml-graphics-2 -lcsfml-system-2

setup:
	@echo Creating required directories...
	@echo ================
	mkdir build
	mkdir external

dot:
	@echo Building Dot...
	@echo ================
	$(CC) $(PARAMS)
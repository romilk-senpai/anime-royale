build: 
	cmake -s . -b build/ -d cmake_build_type=debug
	cmake --build build/

run:
	make build
	./build/anime-royale

debug:
	make build
	gdb ./build/anime-royale

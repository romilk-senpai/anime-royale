build: 
	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug
	cmake --build build/
	make -C build/

run:
	make build
	make build
	make -C build/
	./build/anime-royale

debug:
	make build
	make -C build/
	gdb ./build/anime-royale

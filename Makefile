buildg:
	rm -r -d -f build/
	cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Debug
	cmake --build build/
	make -C build/

run:
	make buildg
	./build/anime-royale

debug:
	make buildg
	gdb ./build/anime-royale

.PHONY: build-linux build-wasm

build-linux:
	make clean-linux
	cmake -S . -B build-linux/
	make -C build-linux/

run-linux:
	make build-linux
	./build/anime-royale

debug-linux:
	make build-linux
	gdb ./build-linux/anime-royale

clean-linux:
	rm -r -d -f build-linux/

build-wasm:
	make clean-wasm
	cmake -S . -B build-wasm/ -D CMAKE_BUILD_TYPE=Debug -DEMSCRIPTEN=ON
	emmake make -C build-wasm/

clean-wasm:
	rm -r -d -f build-wasm/

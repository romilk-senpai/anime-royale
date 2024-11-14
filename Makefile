.PHONY: build-linux build-wasm build-wasm-test

build-linux:
	make clean-linux
	/usr/bin/cmake -S . -B build-linux/
	make -C build-linux/

run-linux:
	make build-linux
	./build-linux/anime-royale

debug-linux:
	make build-linux
	gdb ./build-linux/anime-royale

clean-linux:
	rm -r -d -f build-linux/

build-wasm:
	make clean-wasm
	mkdir -p build-wasm/
	cp html/* build-wasm/
	cp -r assets build-wasm/
	/usr/bin/cmake -S . -B build-wasm/ -DEMSCRIPTEN=ON
	emmake make -C build-wasm/
	mv build-wasm/anime-royale build-wasm/anime-royale.js

run-wasm:
	make build-wasm
	python3 -m http.server --directory build-wasm

clean-wasm:
	rm -r -d -f build-wasm/

build-wasm-test:
	mkdir -p build-wasm-test/
	emcc -o build-wasm-test/a.out.js \
	src/test/test.c \
	-sEXPORTED_FUNCTIONS=['_main'] \
	-sASYNCIFY \
	-sEXPORT_NAME='Main' \
	-sINVOKE_RUN=0 \
	-sMODULARIZE=1 \
	-sDISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=0 \
	-sEXPORTED_RUNTIME_METHODS=['callMain','ccall','cwrap'] \
	-sFORCE_FILESYSTEM=1 -sALLOW_MEMORY_GROWTH=1 \
	-sDISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR \
	--use-port=sdl2 \
	--use-port=sdl2_image:formats=png \
	-D __EMSCRIPTEN__
	cp src/test/index.html build-wasm-test/index.html


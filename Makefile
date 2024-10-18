run: build
	./build/main

build: src/*.c
	gcc -Ilib/ src/*.c lib/libraylib.a -o build/main -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
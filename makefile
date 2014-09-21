ShaderTest:main.o
	g++ `sdl2-config --cflags --libs` main.o -o ShaderTest `pkg-config glew --cflags --libs` -framework opengl -g
	rm -fr *.o
main.o:
	g++  `sdl2-config --cflags` -c -g  main.cpp

clean:
	rm -fr ShaderTest 


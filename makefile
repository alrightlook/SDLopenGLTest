ShaderTest:main.o
	g++ main.o -o ShaderTest -lopengl32 -lglew32 -lmingw32 -lSDL2main -lSDL2 -g
	rm -fr *.o
main.o:
	g++  `sdl2-config --cflags --libs` -c -g  main.cpp

clean:
	rm -fr ShaderTest 


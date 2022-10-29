all:
	cp src/*.cpp src/*.h ./examples/template/game-lib
	cd examples/template/ && $(MAKE) build run
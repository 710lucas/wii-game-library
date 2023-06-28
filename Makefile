all:
	cp -r src/* ./examples/template/game-lib
	cd examples/template/ && $(MAKE) build run
.PHONY: all build test #declare recipies

all: build

build:
	cmake -S . -B build
	cmake --build build --config Release

test: build
	ctest --test-dir build --output-on-failure

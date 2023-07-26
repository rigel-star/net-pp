.PHONY: all
.PHONY: clean

all:
	g++ -o main ./src/*.cpp

clean:
	rm main
all: main

main: main.o kernel.o
	g++ $^ -L /usr/local/cuda/lib64 -lcudart -o $@


main.o: main.cpp
	g++ -c $< -o $@

kernel.o: kernel.cu
	nvcc -c $< -I /usr/local/cuda/include -o $@

clean:
	rm *.o main



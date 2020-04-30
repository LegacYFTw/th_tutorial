all: edge_list
	python3 visualize.py < edge_list.txt

edge_list: edge_list_generator
	./edge_list_generator.out

edge_list_generator:
	c++ edge_list_generator.cpp -std=gnu++17 -Wall -Wextra -D_GLIBCXX_DEBUG -o edge_list_generator.out

clean:
	rm edge_list.txt edge_list_generator.out graph.png -rf

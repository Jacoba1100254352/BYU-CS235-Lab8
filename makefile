all:
	clear
	g++ -std=c++11 AVL.cpp main.cpp -o Lab8
	./Lab8
	bash check.sh
	# valgrind --leak-check=full -s ./Lab8

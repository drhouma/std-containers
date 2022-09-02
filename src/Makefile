CC=g++
CFLAGS=
all: build

build: clean
	g++ -std=c++20 TestStack.cpp -o test_stack -lgtest
	./test_stack
	-CK_FORK=no leaks --atExit -- ./test_stack > res.txt || echo "LEAKS!!! = $$?"

	g++ -std=c++20 TestQueue.cpp -o test_queue -lgtest
	./test_queue
	-CK_FORK=no leaks --atExit -- ./test_queue > res.txt || echo "LEAKS!!! = $$?"

	g++ -std=c++20 TestVector.cpp -o test_vector -lgtest
	./test_vector
	-CK_FORK=no leaks --atExit -- ./test_vector > res.txt || echo "LEAKS!!! = $$?"

	g++ -std=c++20 TestMap.cpp -o test_map -lgtest
	./test_map
	-CK_FORK=no leaks --atExit -- ./test_map > res.txt || echo "LEAKS!!! = $$?"

	g++ TestSetMultiset.cpp -lgtest -std=c++20 -o test_set_multiset
	./test_set_multiset
	CK_FORK=no leaks --atExit -- ./test_set_multiset > res.txt || echo "LEAKS!!! = $$?"

	$(CC) $(CFLAGS) TestList.cpp -o testList.out -lgtest
	./testList.out
	CK_FORK=no leaks --atExit -- ./testList.out > res.txt || echo "LEAKS!!! = $$?"

	$(CC) $(CFLAGS) TestArray.cpp -o testArray.out -lgtest
	./testArray.out
	CK_FORK=no leaks --atExit -- ./testArray.out > res.txt || echo "LEAKS!!! = $$?"

clean:
	rm -rf test* *.out res.txt *.dSYM


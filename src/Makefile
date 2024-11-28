CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
DEBUG_FLAGS = -Wall -Werror -Wextra -std=c11 -g
SRC = $(wildcard ./*.c)
TESTS_SRC = $(wildcard tests/*.c)
OS := $(shell uname -s)
OBJECTS = $(SRC:.c=.o)

ifeq ($(OS),Linux)
	OPEN_CMD = xdg-open
	TEST_LIBS = -lcheck -lsubunit -lrt -lm -pthread
endif
ifeq ($(OS),Darwin)
	OPEN_CMD = open
	TEST_LIBS = -lcheck
endif

all: clang format_style test gcov_report

test: clean s21_string.a
	$(CC) $(CFLAGS) -o test $(SRC) $(TESTS_SRC) $(TEST_LIBS)
	./test

debug: clean s21_string.a
	$(CC) $(CFLAGS) -g -o test $(SRC) $(TESTS_SRC) $(TEST_LIBS)

s21_string.a: $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a
	rm -rf $(OBJECTS)

gcov_report:
	$(CC) $(CFLAGS) --coverage $(SRC) $(TESTS_SRC) -o gcov_test $(TEST_LIBS)
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	$(OPEN_CMD) ./report/index.html

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test

clang: clean
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format --style=Google -i */*.c */*.h *.h
	clang-format --style=Google -n */*.c */*.h *.h

	rm .clang-format

format_style:
	cp ../materials/linters/.clang-format .
	clang-format -i */*.c */*.h
	clang-format -i *.c *.h
	rm .clang-format

clean: clean_test
	rm -rf test
	rm -rf debug
	rm -rf report
	rm -rf s21_string.a
	rm -rf report.out

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf gcov_test
	rm -rf test.o
	rm -rf a.out
#!/bin/bash

test ()
{
	echo " "
	echo "Test: '$1'"
	./Conversion "$1"
}

echo "========== CHARS =========="
test a
test A
test .
test ~
test " "

echo "========== INTS =========="
test 12
test 45
test -45
test 2147483647
test -2147483648

echo "========== FLOATS =========="
test 12.0f
test -42.0f
test 1.1234f
test 123.0f
test +inff
test -inff
test nanf

echo "========== DOUBLES =========="
test 12.0
test -42.0
test 1.1234
test 123.0
test +inf
test -inf
test nan

echo "========== OTHERS TESTS =========="
test 12.3456

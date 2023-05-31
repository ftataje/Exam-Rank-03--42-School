#!/bin/bash

set -e
cd $(dirname $0)
echo ">>COMP1<<<"
gcc -Wall -Werror -Wextra -DBUFFER_SIZE=5 main1.c get_next_line.c -o your_gnl_1.out || (echo "KO->COMP F" && exit 1)
gcc -Wall -Werror -Wextra -DBUFFER_SIZE=5 main2.c get_next_line.c -o your_gnl_2.out || (echo "KO->COMP F" && exit 1)
gcc -Wall -Werror -Wextra main2_generator.c -o generator.out
echo "OK"

echo ">>>TESTING<<<"
rm -f empty_file big_file big_file2 your_output our_output

echo ">Reading main1.c"
touch your_output
./your_gnl_1.out <main1.c> your_output || (echo "KO->EXE F0" && exit1)
diff your_output main1.c || (echo "KO->TEST F0" && exit 1)
rm -f your_output
echo "OK"

echo "Reading from an empty file"
touch empty_file your_output
./your_gnl_1.out <empty_file> your_output
diff your_output empty_file || (echo "KO-TEST F1" && exit 1)
rm -f empty_file your_output
echo "OK"

echo ">Reading from a big file 2"
touch big_file big_file2 your_output our_output
echo > big_file
for i in `seq 1 10`; do cat big_file >> big_file2; cat big_file2 >> big_file; done
./your_gnl_1.out <big_file> your_output || (echo "KO-TEST F2" && exit 1)
rm -f big_file big_file2 your_output our_output
echo "OK"

echo ">Reading from a big_file 3"
touch big_file big_file2 your_output our_output
echo a > big_file
for i in `seq 1 10`; do cat big_file >> big_file2; cat big_file2 >> big_file; done
./your_gnl_1.out <big_file> your_output || (echo "KO-TEST F3" && exit 1)
rm -f big_file big_file2 your_output our_output your_gnl_1.out

echo ">Sequential Read"
./generator.out > our_output
./your_gnl_2.out > your_output || (echo "KO-TEST F4" && exit 1)
diff your_output our_output || (echo "KO-TEST F4" && exit 1)
rm -f your_output our_output your_gnl_2.out generator.out
echo "OK"



#!/bin/bash

cd ./func_tests/scripts

failed=0;
test_number=1;
i="0${test_number}"
for path in "pos" "neg"; do
    test_number=1;
    i="0${test_number}"
    while [ -f "../data/${path}_${i}_in.txt" ]; do 
        line="./${path}_case.sh ../data/${path}_${i}_in.txt"
        if [ -f "../data/${path}_${i}_out.txt" ]; then
            line+=" ../data/${path}_${i}_out.txt"
        fi
        if [ -f "../data/${path}_${i}_args.txt" ]; then
            line+=" ../data/${path}_${i}_args.txt"
        fi
        printf "%s test %s " "$path" "$i";
        if eval "$line"; then
            printf "\e[32mpassed\e[0m\n";
        else
            printf "\e[31mfailed\e[0m\n";
            failed=$((failed+1));
        fi
        test_number=$((test_number+1))
        if [ $test_number -gt 9 ]; then
            i="${test_number}"
        else
            i="0${test_number}"
        fi
    done
done

cd ../..

exit $failed;

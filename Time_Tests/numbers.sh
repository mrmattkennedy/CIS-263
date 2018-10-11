#!/bin/bash

#Bubble:
for elems in 10 100 1000 10000
do
	printf "\n"
	for attempt in 0 1 2 3 4
	do
		cmd=$(./a.out $elems 0)
		echo "$elems,$cmd"
	done
done

#rest:
for sorts in 1 2 3 4
do
	printf "\n"
	case $sorts in
		1)
			sort="Selection:"
			;;
		2)
			sort="Insertion:"
			;;
		esac
	for elems in 10 100 1000 10000 100000
	do
		printf "\n"
		for attempt in 0 1 2 3 4
		do
			cmd=$(./a.out $elems $sorts)
			echo "$elems,$cmd"
		done
	done
done


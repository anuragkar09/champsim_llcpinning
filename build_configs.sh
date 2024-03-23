#!/bin/bash

while IFS= read -r config
do
	./config.py configs/$config
	make -j8
	echo
	echo built $config
	echo
	sleep 2
done < $1

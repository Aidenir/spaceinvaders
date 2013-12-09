#!/bin/bash

#        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
#                    Version 2, December 2004 
#
# Copyright (C) 2013 Viktor Hansson <viktor.hansson@me.com>
#
# Everyone is permitted to copy and distribute verbatim or modified 
# copies of this license document, and changing it is allowed as long 
# as the name is changed. 
#
#            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
#   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 
#
#  0. You just DO WHAT THE FUCK YOU WANT TO.

if [ "$1" = "clean" ]; then
	echo "Cleaning..."
	rm -rf bin
elif [ "$1" = "build" ]; then
	if [ ! -d "bin" ]; then
		mkdir bin
	fi
	if [ "$2" = "r" ] 
	then
		echo "Building Release..."
		if [ ! -d "bin/release" ]; then
			mkdir bin/release
			cd bin/release
			cmake -DCMAKE_BUILD_TYPE=Release ../../
			cd ../../
		fi
		cd bin/release
		make
	else
		echo "Building debug..."
		if [ ! -d "bin/debug" ]; then
			mkdir bin/debug
			cd bin/debug
			cmake  ../../
			cd ../../
		fi
		cd bin/debug
		make
	fi
elif [ "$1" = "rebuild" ]; then
	echo "Rebuilding.."
	rm -rf bin
	mkdir bin
	if [ "$2" = "r" ] 
	then
		echo "Building Release..."
		if [ ! -d "bin/release" ]; then
			mkdir bin/release
			cd bin/release
			cmake -DCMAKE_BUILD_TYPE=Release ../../
			cd ../../
		fi
		cd bin/release
		make
	else
		echo "Building debug..."
		if [ ! -d "bin/debug" ]; then
			mkdir bin/debug
			cd bin/debug
			cmake  ../../
			ln -s ../../src/shaders shaders
			cd ../../
		fi
		cd bin/debug
		make
	fi
else
	echo "Do nothing"
fi




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


setupDebug() 
{
	if [ ! -d "bin/debug" ]; then
		mkdir bin/debug
		cd bin/debug
		cmake ../../
		ln -s ../../src/shaders shaders
		cd ../../
	fi
}

setupRelease() {
	if [ ! -d "bin/release" ]; then
		mkdir bin/release
		cd bin/release
		cmake -DCMAKE_BUILD_TYPE=Release ../../
		ln -s ../../src/shaders shaders
		cd ../../
	fi
}

#If the rebuild or clean option is passed remove the bin
if [ "$1" = "clean" ] || [ "$1" = "rebuild" ]; then
	echo "Cleaning..."
	rm -rf bin
fi
#If the option contains build (build and rebuild) setup the bin
if [[ "$1" =~ "build" ]]; then
	if [ ! -d "bin" ]; then
		mkdir bin
	fi
	if [ "$2" = "r" ] 
	then
		echo "Building Release..."
		setupRelease
		cd bin/release
		rm shaders
		ln -s ../../src/shaders shaders
		rm images
		ln -s ../../src/images images
		make
	else
		echo "Building debug..."
		setupDebug
		cd bin/debug
		rm shaders
		ln -s ../../src/shaders shaders
		rm images
		ln -s ../../src/images images
		make
	fi
fi


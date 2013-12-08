#! bin/bash

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

if [ "$1" == "clean" ]
then
	echo "Cleaning..."
	rm -rf bin
elif [ "$1" == "build" ]
then
	if [ "$2" == "r" ] 
	then
		echo "Building Release..."
		if [ ! -d "bin"]
			mkdir bin
			mkdir bin/release
			cd bin/release
			cmake -DCMAKE_BUILD_TYPE=Release ../../
		fi
		make
	else
		echo "Building debug..."
		if [ ! -d "bin"]
			mkdir bin
			mkdir bin/debug
			cd bin/debug
			cmake  ../../
		fi
		make
	fi
fi




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
mkdir bin
mkdir bin/debug
mkdir bin/release

cd bin/debug
cmake ../../

cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ../../

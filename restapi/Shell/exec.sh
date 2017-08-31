#! /bin/bash 
###########################################
#
###########################################

# constants
baseDir=$(cd `dirname "$0"`;pwd)
rDir=$baseDir
binary=build64_release/projects/Src/HelloWorld

# functions
function recursive(){
    if [ -f "BLADE_ROOT" ]; then
        build64_release/projects/Src/HelloWorld
    elif [ $rDir!="/" ]; then
        cd ..
        recursive
    else
        echo $rDir
        echo "Not found BLADE_ROOT"
    fi
}

# main 
[ -z "${BASH_SOURCE[0]}" -o "${BASH_SOURCE[0]}" = "$0" ] || return
cd $baseDir/..
recursive

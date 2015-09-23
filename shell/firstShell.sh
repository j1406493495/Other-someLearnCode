#! /bin/bash

filename="hello = world"
file=${filename#hello*=[ ]*}
echo ${filename}
echo ${file}

firstFile=hello.tiff
secFile=${firstFile%.tiff}.pdf
echo ${firstFile}
echo ${secFile}
echo "${firstFile}"

picName=$1

if [ "" == "${picName}" ]
then
    echo "picName is empty"
fi

if [ "" == "$1" ]
then
    echo "picture is empty too"
fi

# !/bin/bash


if [ $# != 2 ] ; then 
echo "USAGE: $0 [start index] [end index]" 
exit 1; 
fi 

DEFAULT=leetcode
for  i in $(seq $1 $2 )
do
    DIR=${DEFAULT}${i}
    FILE=${i}.cpp
    mkdir ${DIR}
    cd ${DIR}
    touch ${FILE}
    chmod 644 ${FILE}
    cd ..
    echo "|${i}|Y|" >> README.md ## record
done

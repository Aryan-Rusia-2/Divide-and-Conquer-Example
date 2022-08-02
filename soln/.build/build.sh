#!/bin/bash
NAME=we7_solution
if ! [ -f $NAME ]
then
    make -s $NAME
    rm -f *.o
fi
chmod +x $NAME
./$NAME
rm -f $NAME

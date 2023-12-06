#!/bin/bash

set -e

DIRN=`dirname $1`
THIS_HOME=$( cd $DIRN ; pwd)
target_system=`echo $(hostname) | sed 's/c1/c2/g'`
binary=`basename $1`

echo "copying $1 to $target_system"

ssh $target_system mkdir -p $THIS_HOME
scp -rp $1 $target_system:${THIS_HOME}/



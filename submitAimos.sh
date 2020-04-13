#!/bin/bash
[ $# != 2 ] && echo "Usage: $0 <numberOfNodes> <runScript>" && exit 1
nodes=$1
script=$2
set -x
sbatch -N $nodes -n $((nodes*4)) -t 10 --gres=gpu:1 $script
set +x

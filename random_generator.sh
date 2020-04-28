#!/bin/bash
# $1 - from value
# $2 - till value

if (( $# == 1 )); then
  begin=0
  end=100
else
  begin=$1
  end=$2
fi

ARGS=$(python3 -c "import random; x = list(range($begin, $end)); random.shuffle(x); print(*x)")
echo "$ARGS"
#./push_swap

#!/bin/bash

echo "Count" $#
echo "Args" $@

avg=0
for c in "$@"
do
    avg=$((avg+$c))
done

echo "Average" $((avg/$#))
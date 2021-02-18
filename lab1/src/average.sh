#!/bin/sh

echo There were $# parameters.

count=0
sum=0

for param in $(cat $1)
do
sum=$(($sum+param))
count=$((count+1))
done

result=$((sum/count))
echo "Ans = $result"
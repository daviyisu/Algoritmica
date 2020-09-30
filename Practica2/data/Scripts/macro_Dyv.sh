#!/bin/bash
echo "Divide y vencerás"
let i=10000
while [ $i -le 250000 ];do
  echo $i
  ./bin/genera_duplicados_DyV  $i >> data/duplicados_DyV.dat
  let i=$i+10000
done

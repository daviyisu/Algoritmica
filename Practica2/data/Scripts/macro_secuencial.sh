#!/bin/bash
echo "Secuencial"
let i=10000
while [ $i -le 250000 ];do
  echo $i
  ./bin/genera_duplicados_secuencial  $i >> data/duplicados_secuencial.dat
  let i=$i+10000
done

I=$1;
echo $I $I;
for i in $(seq 1 $((I-1))); do
  echo $i $((i+1));
done;
echo $I 1


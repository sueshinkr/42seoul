i=0
value=0
for i in $(seq 1 $1);
do
	export ARG=$(./push_swap_tester-main/random_numbers $2 1)
	if [ "KO" == "$(./push_swap $ARG | ./checker_Mac $ARG)" ]; then
		echo "KO Fail"
		echo $ARG
		break
	fi
	value=$(./push_swap $ARG | wc -l)
	if [ ${value} -ge $3 ]; then
		echo "NUM Fail"
		echo $ARG
		break
	else
		echo ${value}
	fi
	if [ ${i} -eq 1000 ];then
		break
	fi
done

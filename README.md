Q1>
*****
*   *
*   *
*   *
*   *
*****

Q2>sum of the first 10 fibonacci numbers:88

Q3>sum of prime numbers between 1 and 100: 1060

::Q1)
::rectangle pattern
*****
*   *
*   *
*   *
*****
for ((i=1; i<=5; i++))
do
    for ((j=1; j<=5; j++))
    do
        if [ $i -eq 1 ] || [ $i -eq 5 ] || [ $j -eq 1 ] || [ $j -eq 5 ]
        then
            echo -n "*"
        else
            echo -n " "
        fi
    done
    echo     
done


--------------------------------------------------------------
::Q2)
	::Fibonacci series
	::0 1 1 2 3 5 8 13 21 34
	::sum of the series: 88



a=0
b=1
sum=0

echo "Fibonacci Series:"

for ((i=0; i<10; i++))
do
    echo -n "$a "
    sum=$(($sum + $a))
    temp=$b
    b=$(($a + $b))
    a=$temp
done

echo
echo "Sum of the series: $sum"

	

----------------------------------------------------------------------
::Q3)sum of prime numbers between 1 and 100 is : 1060

sum=0

for ((num=2; num<=100; num++))
do
    is_prime=1
    for ((i=2; i*i<=num; i++))
    do
        if (( num % i == 0 ))
        then
            is_prime=0
            break
        fi
    done

    if (( is_prime == 1 ))
    then
        sum=$(($sum + $num))
    fi
done

echo "Sum of prime numbers between 1 and 100 is: $sum"

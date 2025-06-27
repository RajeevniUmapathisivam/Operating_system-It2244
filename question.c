9>write a shell script to read n numbers as command arguments and 
sort them in descending order

10>write a shell script to generate a marksheet of a student. Take 3 subjects,
 calculate and display the total marks, average and grades of each subject obtained by the student
 
11>write a shell script to display the multiplication table of a given number

12>write a shell script to find the factorial of a given number

16> Write a script to find whether the given year is a leap year or not.
17>Write a script to wish “Happy Birthday” if the current date and month match the date of birth received from the user.
 

Answers
9>

if [ $# -eq 0 ]; then
  echo "Usage: $0 number1 number2 ... numberN"
  exit 1
fi

printf "%s\n" "$@" | sort -nr

10>
#!/bin/bash

echo "Enter marks for Subject 1:"
read sub1
echo "Enter marks for Subject 2:"
read sub2
echo "Enter marks for Subject 3:"
read sub3

total=$((sub1 + sub2 + sub3))
average=$(echo "scale=2; $total / 3" | bc)

grade() {
  if [ $1 -ge 90 ]; then
    echo "A"
  elif [ $1 -ge 80 ]; then
    echo "B"
  elif [ $1 -ge 70 ]; then
    echo "C"
  elif [ $1 -ge 60 ]; then
    echo "D"
  else
    echo "F"
  fi
}

echo "Marksheet:"
echo "Subject 1: $sub1 Grade: $(grade $sub1)"
echo "Subject 2: $sub2 Grade: $(grade $sub2)"
echo "Subject 3: $sub3 Grade: $(grade $sub3)"
echo "Total Marks: $total"
echo "Average: $average"

11>
#!/bin/bash

echo "Enter a number:"
read num

echo "Multiplication Table of $num:"
for ((i=1;i<=12;i++))
do
  echo "$num x $i = $((num * i))"
done


12>#!/bin/bash

echo "Enter a number:"
read n

factorial=1

for (( i=1; i<=n; i++ ))
do
  factorial=$((factorial * i))
done

echo "Factorial of $n is $factorial"


16>#!/bin/bash

echo "Enter a year:"
read year

if (( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) )); then
  echo "$year is a leap year."
else
  echo "$year is not a leap year."
fi


17>#!/bin/bash

echo "Enter your birth date (DD):"
read bd
echo "Enter your birth month (MM):"
read bm

current_day=$(date +%d)
current_month=$(date +%m)

if [ "$bd" == "$current_day" ] && [ "$bm" == "$current_month" ]; then
  echo "Happy Birthday!"
else
  echo "Today is not your birthday."
fi

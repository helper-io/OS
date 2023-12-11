## Shell programs
1. Conditionals and control statements
```bash
#!/bin/bash
echo "select the pattern to print"
echo "1. Pattern 1"
echo "2. Pattern 2"
echo "3. Pattern 3"
read ch

if [ $ch -eq 1 ]
then
echo "enter the rows"
read num
for((i=1;i<=num;i++))
do
for((k=1;k<=num-i;k++))
do
echo -n " "
done
for((j=1;j<=i;j++))
do
echo -n "* "
done
echo " "
done
elif [ $ch -eq 2 ]
then
echo "enter the rows"
read num
for((i=1;i<=num;i++))
do
for((k=1;k<i;k++))
do
echo -n " "
done
for((j=1;j<=num-i+1;j++))
do
echo -n "* "
done
echo " "
done
elif [ $ch -eq 3 ]
then
echo "enter the rows"
read num
for((i=1;i<=num;i++))
do
for((j=1;j<=i;j++))
do
echo -n "*"
done
echo " "
done

else
echo "invalid input"
fi
```

2. swap two numbers
```bash
#!/bin/bash
echo "enter first number"
read a
echo "enter second number"
read b

temp=$a
a=$b
b=$temp

echo "values after swapping"

echo "a = $a"
echo "b = $b"
```

#! /bin/bash

a=hello
b=world
x=1
y=3

echo $a $b
echo "x y:" $x $y

echo $0 #脚本名字 
echo $1 #第一个参数
echo $2 #第二个参数
echo $# #参数个数
echo "$*" #所有参数
echo $? #执行正确?0:1
echo "$@" #所有参数

echo "display for \"\$*\""
for val in "$*"
do
    echo $val
done

echo "display for \"\$@\""
for val in "$@"
do
    echo $val
done

#命令替换
DATE=`date`
echo "today is $DATE"

#变量替换
echo $val
echo ${val:-hai}
echo $val
#echo ${val:?no val}
echo ${val:=hai boy}
echo $val
echo ${val:+hai girl}
echo $val
#echo ${val:?no val}

#数学算术
echo "x + y = "`expr $x + $y`
echo "y - x = "`expr $y - $x`
echo "y * x = "`expr $y \* $x`
echo "y / x = "`expr $y / $x`
echo "y % x = "`expr $y % $x`

#if [$y == $x]
if [ $y == $x ]
then
    echo "y == x"
fi

#if [$y != $x]  error 空格
if [ $y != $x ]
then
    echo "y != x"
fi

#关系运算符，只适用数字
m=5
n=5

if [ $m -eq $n ]
then
    echo "m equal n"
fi
#-eq 等于 equal
#-ne 不等于 not equal
#-gt 大于 greater
#-lt 小于 less
#-ge 大于等于 greater equal
#-le 小于等于 less equal

#布尔运算, 用法同上
# !
# -o or
# -a and

#字符串运算
# =    [ $a = $b ]   字符串a=b?true:false
# !=   [ $a != $b ]  字符串a!=b?true:false
# -z   [ -z $a ]     字符串长度为0?true:false
# -n   [ -n $a ]     字符串长度不为0?true:false
# str  [ $s ]        字符串为空?true:false


echo "\" is $a"
#echo '\' is $a' 单引号内不能有单引号，转义也不行，单引号内变量无效
echo 'is $a'

echo ${#a} #获取字符串a的长度

echo ${a:1:2} #hello 中截取 el

#str = "hello world every body" =前后不能有空格
str="world every is body hello"
echo `expr index "$str" is` #查询i和s中其中一个首先出现的位置

#数组
#array[4]=(1, 2, 3, 4, 5)
array=(1 2 3 4 5)
for i in 0 1 2 3 4
do
    echo ${array[i]}
done


#if [ ]
#then
#else
#fi

#if [ ]
#then
#elif [ ]
#then
#else
#fi

case $x in
1)
    echo "is 1"
    ;;
2)
    echo "is 2"
    ;;
3)
    echo "is 3"
    ;;
esac


#while [ ]
#do 
#done

#until [ ]  当[]返回false执行语句，与while相反
#do 
#done


#break n  跳出n层循环, 直接退出
#contuine n 跳出n层循环，可继续

sayHello() 
{
    echo $str
}

sayWorld()
{
    echo $b >> sayWorld.txt #重定向输出到sayWorld.txt
    echo $* 1>> sayWorld 2>&1 #将正确与错误都输入到sayWorld中
    echo $# 1>> sayWorld 2>> /dev/null #将正确输入到sayWorld， 错误输入到/dev/null
}

sayHello
sayWorld 1 2 3



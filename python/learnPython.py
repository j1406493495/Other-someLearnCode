#! /usr/bin/python

import glo
print glo.x

a = "hello world"
print id(a)

a = "ni hao"
print id(a)

for y in range(0, 5, 2):
    print y

for y in 1, 2, 3:
    print y

if (glo.x == 2):
    print("a==2")
else:
    print("a!=2")

tuple_name = ("name", "age", "school")  #can't modify, only-read
list_name = ["boy", "girl"] #can modify
dict_name = {"a":"hello", "b":"world"}

def fun_hello(a=0, b=1):
    print("hello everybody")
    print(a)
    print(b)
fun_hello()

class MyClass:
    common=5
    def fun_sum(self, m, n):
        print(m+n)
mySum = MyClass()
mySum.fun_sum(11, 22)

mySum001 = MyClass()
print(mySum.common)
print(mySum001.common)
MyClass.common = 1000
print(mySum.common)
print(mySum001.common)
mySum.common = 9999
print(mySum.common)
print(mySum001.common)

class Student(MyClass):
    def fun_age(self, d):
        print(d)
stu = Student()
stu.fun_age(100)
stu.fun_sum(100, 200)


f = file("sayHello.txt", "w")
f.write("hello girls")
f.close()

section = "hello boys"
print(section[2:6])  #llo

# test1

~~~Jake@DESKTOP-3SHLOGR ~/study/practice
Jake@DESKTOP-3SHLOGR ~/study/practice
$ find ./test -name '*.txt' -type f -print -exec rm -rf {} \;
./test/test1/test1.txt
./test/test1/test2.txt
./test/test1/test3.txt
./test/test1/test4.txt
./test/test2/test1.txt
./test/test2/test2.txt
./test/test2/test3.txt
./test/test2/test4.txt
./test/test3/test1.txt
./test/test3/test2.txt
./test/test3/test3.txt
./test/test3/test4.txt
./test/test4/test1.txt
./test/test4/test2.txt
./test/test4/test3.txt
./test/test4/test4.txt
~~~

~~~Jake@DESKTOP-3SHLOGR ~/study/practice
Jake@DESKTOP-3SHLOGR ~/study/practice
$ find ./test -name '*.txt'
~~~

# test2

*出错：只能删除test2目录下的.doc

~~~Jake@DESKTOP-3SHLOGR ~/study/practice
$ find ./ -path '*/test/test1/*.doc' -o -path '*/test/test2/*.doc'
./test/test1/test1.doc
./test/test1/test2.doc
./test/test1/test3.doc
./test/test1/test4.doc
./test/test2/test1.doc
./test/test2/test2.doc
./test/test2/test3.doc
./test/test2/test4.doc
~~~

~~~Jake@DESKTOP-3SHLOGR ~/study/practice
$ find ./ -path '*/test/test1/*.doc' -o -path '*/test/test2/*.doc' -type f -print -exec rm -rf {} \;
./test/test2/test1.doc
./test/test2/test2.doc
./test/test2/test3.doc
./test/test2/test4.doc
~~~

~~~Jake@DESKTOP-3SHLOGR ~/study/practice
$ find ./ -path '*/test/test1/*.doc' -o -path '*/test/test2/*.doc'
./test/test1/test1.doc
./test/test1/test2.doc
./test/test1/test3.doc
./test/test1/test4.doc
~~~
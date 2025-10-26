>>> snipname=""
>>> snippy=[snipname,]
>>> text=""
>>> inserd='i(1:"insert text")'
>>> inserf='i(0:),'
>>> inserd='i(1:"insert text"),'
>>> textin='t('+text+'),'
>>> textin=lambda text:'t('+text+'),'
>>> inserd=lambda pos,temp:'i('+str(pos)+":"+temp+'),'
>>> iserd(2,"hiipo")
Traceback (most recent call last):
  File "<input>", line 1, in <module>
    iserd(2,"hiipo")
     ^^^^^
NameError: name 'iserd' is not defined
>>> inserd(2,"hiipo")
Traceback (most recent call last):
  File "<input>", line 1, in <module>
    inserd(2,"hiipo")
  File "<input>", line 1, in <lambda>
    inserd=lambda pos,temp:'i('+pos+":"+temp+'),'
                            ~~~~^~~~
TypeError: can only concatenate str (not "int") to str
>>> inserd(str(2),"hiipo")
'i(2:hiipo),'
>>> inserd(2,"hiipo")

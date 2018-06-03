#! /bin/bash 
echo "hello world"


echo THE NAME OF THE BASH IS** $BASH                   **//system variables **
echo ITS VERSION IS** $BASH_VERSION
echo HOME DIRECTORY IS** $HOME
echo PRESENT WORKING DIRECTORYIS THIS** $PWD
count=10
ded=abc
name=nitishkumar                                   
                                                           echo **//userdefined variables**
echo my name is $name
roono=zsdkjfkdf
echo my roll no is $roono

echo enter the names
read -a sname
echo "names are ${sname[0]},${sname[1]},${sname[2]}"

echo $0 $1 $2 $3 '> echo $0 $1 $2'
args=("s@")
#echo "${args[0]},${args[1]},${args[2]}"
echo $@
echo $#


if [ $count -ne 10 ]
then 
    echo "condition is true"
fi
if [ $count -eq 10 ]
then 
     echo "condition is true"
     fi
     
  if [ $ded == "abfffc" ]
then 
     echo "condition is true"
 elif [[ $ded == "abcc" ]]
then 
     echo "condition is true"
 else 
     echo "condition is false"
   fi
            
            age=25
            if [ "$age" -eq 18 -o "$age" -eq 30 ]
            then
            echo "valid"
            else
               echo "not valid"
               fi
               
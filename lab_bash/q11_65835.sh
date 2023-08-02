for file in $(find . -type f -name "*.c")
do
        file_name=$(echo $file | cut -d '/' -f2)
        prog_name=$(echo $file | cut -d '/' -f2 | cut -d '.' -f1)
        gcc -o $prog_name $file 2>/dev/null
        if [ -f $prog_name ]
        then
                ans=`./$prog_name`
                if [ $ans = 20 ]
                then
                        point=10
                else
                        point=7
                fi
        else
                point=5
        fi
        printf "%s\t %s\n" $file_name $point
        # printf "%s\t %s\n" $prog_name $point 
done
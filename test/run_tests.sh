PROGRAM=../bin/pascheck

allTestPassed=true

for file in *.*.pas; do
	need=`echo $file | sed -e 's/.*\.\([a-z]*\)\.pas/\1/g'`
	returned=`$PROGRAM <$file`
	echo
	echo ${file}:
	#cat $file
	#echo '-----------'
	if [ "$need" == "$returned" ]; then
		echo "  OK  программа вернула $returned"
	else
		echo " FAIL программа вернула $returned, но нужно $need"
		allTestPassed=false
	fi
	echo "==========="
done

if [ $allTestPassed == true ]; then
	echo "  OK  Все тесты пройдены"
else
	echo " FAIL Не все тесты пройдены"
fi
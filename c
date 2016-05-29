#calculates # of accepted problems solved on linux
TOTAL=`ls accepted/*.cpp | wc -l`

#statics by date
ls -ltr accepted/*.cpp | awk  'NR>1 { a[$6" "$7]++ } END { for (i in a) print i, a[i] }' > day.log


#start reporting
python progress.py $TOTAL

# remove temporary files
rm "day.log" -f

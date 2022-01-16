echo "exercise 3.1";
cd ~;
echo "assert that one of every pair of keys ends on .pub";
ls -l ./.ssh | grep ".pub" | wc -l;

echo "exercise 3.2";
mkdir 'MMS C camp';
cp ./*.c ./MMS\ C\ camp/;
rm [0-9]*;

echo "exercise 3.3";
chmod 754 $HOME/Desktop/testFile

echo "exercise 3.4";
cat source1.c source2.c | wc -l > lineCount;
cc="gcc --std=c2x -D_POSIX_C_SOURCE=200809L"
for file in *.c; do
	$cc -c -o "${file%.c}.o" "$file"
done
gcc -o main.elf *.o

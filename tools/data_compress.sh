#!/bin/bash
MAPFILE="./build/ge007."$2".map"
#this script is a hacky mess that can most definately be improved
#fixme as I will fail if vaddr of data gets moved!!!
DATASEG_START=$(printf "%d\n" 0x$(grep ${MAPFILE} -e '__csegtempPos =' | cut -d "x" -f3))
DATASEG_LEN=$(printf "%d\n" 0x$(grep ${MAPFILE} -e 'load address 0x0000000000c00000' | cut -d "x" -f3 | cut -d " " -f1))


echo "patching $1"
echo "extract data segment"
echo "one byte at a time is slow, sorry"
dd skip=${DATASEG_START} count=${DATASEG_LEN} if=$1 of=data_seg bs=1

echo "truncate $1 to 0x$(printf "%x\n" ${DATASEG_START})"
cat $1 | head --bytes=${DATASEG_START} > $1.tmp

echo "compress data segment"
tools/1172compress.sh data_seg data_seg.rz


echo "inject data segment"
RZSIZE=$(stat -c%s "data_seg.rz")
echo "size=${RZSIZE}"

#fixme as I will fail if position of c_data gets moved!!!
CDATA_POS=$(printf "%d\n" 0x$(grep  ${MAPFILE} -e 'c_data_array' | cut -d "x" -f 2 | cut -d " " -f 1 ))
#CDATA_MAX_SIZE=$(printf "%d\n" 0x$(grep  '${MAPFILE}' -e '.c_data         0x0000000000021990' | cut -d "x" -f 2 ))
#CDATA_POS=137616
CDATA_MAX_SIZE=72704

echo "maxsize=${CDATA_MAX_SIZE}"

echo "one byte at a time is slow, sorry"
dd if=data_seg.rz of=$1.tmp obs=1 seek=${CDATA_POS} conv=notrunc
#rm data_seg data_seg.rz

mv $1.tmp $1


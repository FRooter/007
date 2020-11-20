#include "ultra64.h"
#include "game/ob.h"
#include "memp.h"
#include "assets/obseg/obseg.h"
#include "game/decompress.h"


//bss
//800888b0
struct resource_lookup_data_entry resource_lookup_data_array[736];

// data
//D:80046050
s32 ob_c_debug_notice_list_entry = 0;


#include "assets/obseg/file_resource_table.inc.c"
/* struct fileentry file_resource_table[] = 
   {
       blah;
    };
 */


//D:800482D4
s32 file_entry_max = OBJ_INDEX_END;




void load_resource(u8 *ptrdata, u32 bytes, struct fileentry *srcfile, struct resource_lookup_data_entry *lookupdata)
{
    u8 *source;
    u8 buffer[0x2100];
    s32 unused;
    

    if (bytes == 0)
    {
        romCopy(ptrdata, srcfile->hw_address, lookupdata->rom_size);
        return;
    }
    source = (ptrdata + bytes) - ((lookupdata->rom_size + 7) & -8);
    if ((u32) (source - ptrdata) < 8U)
    {
        lookupdata->pc_remaining = 0;
    }
    else
    {
        romCopy(source, srcfile->hw_address, lookupdata->rom_size);
        lookupdata->pc_remaining = decompressdata(source, ptrdata, buffer);;
    }
}




#ifdef NONMATCHING
//need to tinker with stack size
void resource_load_from_indy(u8 *ptrdata, u32 bytes, struct fileentry *srcfile, struct resource_lookup_data_entry *lookupdata)
{
    void *sp2124;
    u8 buffer[8450];
    u8 *pPayload;
    u32 size;
static const u8 rz_header_1[] = {0x11, 0x72, 0x00, 0x00};
static const u8 rz_header_2[] = {0x11, 0x72, 0x00, 0x00};
    if (bytes == 0)
    {
        load_resource_on_indy(srcfile->filename, ptrdata);
        return;
    }
    check_file_found_on_indy(srcfile->filename, lookupdata->pc_size);
    pPayload = (ptrdata + bytes) - ((lookupdata->pc_size + 7) & -8);
    if ((u32) (pPayload - ptrdata) < 8U)
    {
        lookupdata->pc_remaining = 0;
    }
    else
    {
        sp2124 = pPayload;
        load_resource_on_indy(srcfile->filename, pPayload);
        if ((pPayload[0] == rz_header_1[0]) && (pPayload[1] == rz_header_2[1]))
        {
            size = decompressdata(pPayload, ptrdata, &buffer);
        }
        else
        {
            bcopy(pPayload, ptrdata, lookupdata->pc_size);
            size = lookupdata->pc_size;
        }
        lookupdata->pc_remaining = (s32) size;
    }
}
#else
GLOBAL_ASM(
.rdata
/*8005b66c*/
glabel rz_header_1
.word 0x11720000
/*8005b670*/
glabel rz_header_2
.word 0x11720000
.text
glabel resource_load_from_indy
/* 0F1664 7F0BCB34 27BDDED8 */  addiu $sp, $sp, -0x2128
/* 0F1668 7F0BCB38 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F166C 7F0BCB3C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1670 7F0BCB40 00808025 */  move  $s0, $a0
/* 0F1674 7F0BCB44 00E08825 */  move  $s1, $a3
/* 0F1678 7F0BCB48 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F167C 7F0BCB4C 14A00006 */  bnez  $a1, .L7F0BCB68
/* 0F1680 7F0BCB50 AFA5212C */   sw    $a1, 0x212c($sp)
/* 0F1684 7F0BCB54 8CC40004 */  lw    $a0, 4($a2)
/* 0F1688 7F0BCB58 0FC33FE7 */  jal   load_resource_on_indy
/* 0F168C 7F0BCB5C 02002825 */   move  $a1, $s0
/* 0F1690 7F0BCB60 1000002D */  b     .L7F0BCC18
/* 0F1694 7F0BCB64 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BCB68:
/* 0F1698 7F0BCB68 8CC40004 */  lw    $a0, 4($a2)
/* 0F169C 7F0BCB6C AFA62130 */  sw    $a2, 0x2130($sp)
/* 0F16A0 7F0BCB70 0FC34026 */  jal   check_file_found_on_indy
/* 0F16A4 7F0BCB74 26250008 */   addiu $a1, $s1, 8
/* 0F16A8 7F0BCB78 8E390008 */  lw    $t9, 8($s1)
/* 0F16AC 7F0BCB7C 8FAF212C */  lw    $t7, 0x212c($sp)
/* 0F16B0 7F0BCB80 2401FFF8 */  li    $at, -8
/* 0F16B4 7F0BCB84 27280007 */  addiu $t0, $t9, 7
/* 0F16B8 7F0BCB88 01014824 */  and   $t1, $t0, $at
/* 0F16BC 7F0BCB8C 020FC021 */  addu  $t8, $s0, $t7
/* 0F16C0 7F0BCB90 03093823 */  subu  $a3, $t8, $t1
/* 0F16C4 7F0BCB94 00F05023 */  subu  $t2, $a3, $s0
/* 0F16C8 7F0BCB98 2D410008 */  sltiu $at, $t2, 8
/* 0F16CC 7F0BCB9C 10200003 */  beqz  $at, .L7F0BCBAC
/* 0F16D0 7F0BCBA0 8FA62130 */   lw    $a2, 0x2130($sp)
/* 0F16D4 7F0BCBA4 1000001B */  b     .L7F0BCC14
/* 0F16D8 7F0BCBA8 AE200004 */   sw    $zero, 4($s1)
.L7F0BCBAC:
/* 0F16DC 7F0BCBAC 8CC40004 */  lw    $a0, 4($a2)
/* 0F16E0 7F0BCBB0 AFA72124 */  sw    $a3, 0x2124($sp)
/* 0F16E4 7F0BCBB4 0FC33FE7 */  jal   load_resource_on_indy
/* 0F16E8 7F0BCBB8 00E02825 */   move  $a1, $a3
/* 0F16EC 7F0BCBBC 8FA72124 */  lw    $a3, 0x2124($sp)
/* 0F16F0 7F0BCBC0 3C0C8006 */  lui   $t4, %hi(rz_header_1) 
/* 0F16F4 7F0BCBC4 918CB66C */  lbu   $t4, %lo(rz_header_1)($t4)
/* 0F16F8 7F0BCBC8 90EB0000 */  lbu   $t3, ($a3)
/* 0F16FC 7F0BCBCC 3C0E8006 */  lui   $t6, %hi(rz_header_2 + 0x1) 
/* 0F1700 7F0BCBD0 02002825 */  move  $a1, $s0
/* 0F1704 7F0BCBD4 156C000B */  bne   $t3, $t4, .L7F0BCC04
/* 0F1708 7F0BCBD8 00E02025 */   move  $a0, $a3
/* 0F170C 7F0BCBDC 90ED0001 */  lbu   $t5, 1($a3)
/* 0F1710 7F0BCBE0 91CEB671 */  lbu   $t6, %lo(rz_header_2 + 0x1)($t6)
/* 0F1714 7F0BCBE4 27A60024 */  addiu $a2, $sp, 0x24
/* 0F1718 7F0BCBE8 15AE0006 */  bne   $t5, $t6, .L7F0BCC04
/* 0F171C 7F0BCBEC 00000000 */   nop   
/* 0F1720 7F0BCBF0 00E02025 */  move  $a0, $a3
/* 0F1724 7F0BCBF4 0FC339FC */  jal   decompressdata
/* 0F1728 7F0BCBF8 02002825 */   move  $a1, $s0
/* 0F172C 7F0BCBFC 10000004 */  b     .L7F0BCC10
/* 0F1730 7F0BCC00 00401825 */   move  $v1, $v0
.L7F0BCC04:
/* 0F1734 7F0BCC04 0C003E5C */  jal   bcopy
/* 0F1738 7F0BCC08 8E260008 */   lw    $a2, 8($s1)
/* 0F173C 7F0BCC0C 8E230008 */  lw    $v1, 8($s1)
.L7F0BCC10:
/* 0F1740 7F0BCC10 AE230004 */  sw    $v1, 4($s1)
.L7F0BCC14:
/* 0F1744 7F0BCC14 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BCC18:
/* 0F1748 7F0BCC18 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F174C 7F0BCC1C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1750 7F0BCC20 03E00008 */  jr    $ra
/* 0F1754 7F0BCC24 27BD2128 */   addiu $sp, $sp, 0x2128
)
#endif





#ifdef NONMATCHING
void obInitDebugNoticeList(void)
{
    struct resource_lookup_data_entry *lookupentry;
    struct resource_lookup_data_entry *nextlookup;
    int file_count;
    struct fileentry *filetable_entry;
    
    debCheckAddDebugNoticeListEntry(&ob_c_debug_notice_list_entry,"ob_c_debug");
    filetable_entry = &file_resource_table[0];
    file_count = file_entry_max - 1;
    if (1 < file_count) {
        lookupentry = resource_lookup_data_array + 1;
        while (nextlookup < resource_lookup_data_array + file_count) {
            filetable_entry = filetable_entry + 1;
            nextlookup = lookupentry + 1;
            lookupentry->rom_size = filetable_entry[1].hw_address - filetable_entry->hw_address;
            lookupentry->pc_remaining = 0;
            lookupentry->pc_size = 0;
            lookupentry->rom_remaining = 0;
            lookupentry = nextlookup;
        } ;
    }
    return;
}
#else
GLOBAL_ASM(
.rdata
/*D:8005B674*/
glabel aOb_c_debug
/*"ob_c_debug"*/
.word 0x6F625F63, 0x5F646562, 0x75670000
.text
glabel obInitDebugNoticeList
/* 0F1758 7F0BCC28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F175C 7F0BCC2C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1760 7F0BCC30 3C048004 */  lui   $a0, %hi(ob_c_debug_notice_list_entry)
/* 0F1764 7F0BCC34 3C058006 */  lui   $a1, %hi(aOb_c_debug)
/* 0F1768 7F0BCC38 24A5B674 */  addiu $a1, %lo(aOb_c_debug) # addiu $a1, $a1, -0x498c
/* 0F176C 7F0BCC3C 0C001398 */  jal   debCheckAddDebugNoticeListEntry
/* 0F1770 7F0BCC40 24846050 */   addiu $a0, %lo(ob_c_debug_notice_list_entry) # addiu $a0, $a0, 0x6050
/* 0F1774 7F0BCC44 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1778 7F0BCC48 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F177C 7F0BCC4C 3C048004 */  lui   $a0, %hi(file_resource_table + 0xC)
/* 0F1780 7F0BCC50 24846060 */  addiu $a0, %lo(file_resource_table + 0xC) # addiu $a0, $a0, 0x6060
/* 0F1784 7F0BCC54 2463FFFF */  addiu $v1, $v1, -1
/* 0F1788 7F0BCC58 28610002 */  slti  $at, $v1, 2
/* 0F178C 7F0BCC5C 14200013 */  bnez  $at, .L7F0BCCAC
/* 0F1790 7F0BCC60 3C028009 */   lui   $v0, %hi(resource_lookup_data_array+0x14)
/* 0F1794 7F0BCC64 00037080 */  sll   $t6, $v1, 2
/* 0F1798 7F0BCC68 01C37021 */  addu  $t6, $t6, $v1
/* 0F179C 7F0BCC6C 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F17A0 7F0BCC70 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F17A4 7F0BCC74 000E7080 */  sll   $t6, $t6, 2
/* 0F17A8 7F0BCC78 01CF2821 */  addu  $a1, $t6, $t7
/* 0F17AC 7F0BCC7C 244288C4 */  addiu $v0, %lo(resource_lookup_data_array+0x14) # addiu $v0, $v0, -0x773c
.L7F0BCC80:
/* 0F17B0 7F0BCC80 8C980014 */  lw    $t8, 0x14($a0)
/* 0F17B4 7F0BCC84 8C990008 */  lw    $t9, 8($a0)
/* 0F17B8 7F0BCC88 24420014 */  addiu $v0, $v0, 0x14
/* 0F17BC 7F0BCC8C 0045082B */  sltu  $at, $v0, $a1
/* 0F17C0 7F0BCC90 03191823 */  subu  $v1, $t8, $t9
/* 0F17C4 7F0BCC94 2484000C */  addiu $a0, $a0, 0xc
/* 0F17C8 7F0BCC98 AC43FFEC */  sw    $v1, -0x14($v0)
/* 0F17CC 7F0BCC9C AC40FFF0 */  sw    $zero, -0x10($v0)
/* 0F17D0 7F0BCCA0 AC40FFF4 */  sw    $zero, -0xc($v0)
/* 0F17D4 7F0BCCA4 1420FFF6 */  bnez  $at, .L7F0BCC80
/* 0F17D8 7F0BCCA8 AC40FFF8 */   sw    $zero, -8($v0)
.L7F0BCCAC:
/* 0F17DC 7F0BCCAC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F17E0 7F0BCCB0 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F17E4 7F0BCCB4 03E00008 */  jr    $ra
/* 0F17E8 7F0BCCB8 00000000 */   nop   
)
#endif






void _load_rom_index_to_membank(s32 index,s32 param_2,s32 size,u8 bank) {
    load_rom_resource_index_to_membank(index, param_2, size, bank);
}

void _load_resource_index_to_membank(int index,s32 param_2,u8 *ptrdata,int size) {
    load_resource_index_to_buffer(index, param_2, ptrdata, size);
}

void _load_resource_named_to_membank(u8 *filename,s32 param_2,s32 size,u8 bank)
{
    load_rom_resource_index_to_membank(get_index_num_of_named_resource(filename), param_2, size, bank);
}

void _load_resource_named_to_buffer(u8 *filename,s32 bank,u8 *ptrdata,int size)
{
    load_resource_index_to_buffer(get_index_num_of_named_resource(filename), bank, ptrdata, size);
}

/**
 * 0F18AC 7F0BCD7C
 * loads data stored at an offset of a bg file
 */
void obLoadBGFileBytesAtOffset(u8 *bgname, u8 *target, s32 offset, s32 len)
{
  s32 index;
  struct fileentry *fileentry;

  index = get_index_num_of_named_resource(bgname);
  fileentry = &file_resource_table[index];
  
  if (resource_lookup_data_array[index].rom_size != 0)
  {
    //if the size of offset data would exceed file size, loop forever
    if ((resource_lookup_data_array[index].rom_size + 0xF) < (offset + len))
    {
      while (1){};
    }
    romCopy(target, &fileentry->hw_address[offset], len, fileentry);
  }

}




#ifdef NONMATCHING//
u8 * load_rom_resource_index_to_membank(s32 index,s32 type,s32 size,u8 bank)
{
    
    u8 *ptrdata;
    if (((type == 0) || (type == 1)) || (type == 2))
    {
        if (resource_lookup_data_array[index].pc_remaining == 0)
        {
            resource_lookup_data_array[index].pc_remaining = mempGetBankSizeLeft(bank);
        }
        ptrdata = mempAllocBytesInBank(resource_lookup_data_array[index].pc_remaining, bank);
        resource_lookup_data_array[index].rom_remaining = resource_lookup_data_array[index].pc_remaining;
        if (file_resource_table[index].hw_address == 0)
        {
            resource_load_from_indy(ptrdata, resource_lookup_data_array[index].rom_remaining, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        else
        {
            load_resource(ptrdata, resource_lookup_data_array[index].rom_remaining, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        if (type != 0)
        {
            mempAddEntryOfSizeToBank(ptrdata, resource_lookup_data_array[index].pc_remaining, bank);
        }
    }
    else
    {
        if (resource_lookup_data_array[index].pc_remaining == 0)
        {
            if (resource_lookup_data_array[index].rom_size == 0)
            {
                resource_lookup_data_array[index].pc_remaining = resource_lookup_data_array[index].pc_size;
            }
            else
            {
                resource_lookup_data_array[index].pc_remaining = resource_lookup_data_array[index].rom_size;
            }
        }
        ptrdata = mempAllocBytesInBank(resource_lookup_data_array[index].pc_remaining,bank);
        resource_lookup_data_array[index].rom_remaining = resource_lookup_data_array[index].pc_remaining;
        if (file_resource_table[index].hw_address == 0)
        {
            resource_load_from_indy(ptrdata, 0, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        else
        {
            
            load_resource(ptrdata , 0, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        if (size == 0)
        {
            resource_lookup_data_array[index].loaded_bank = bank;
        }
    }
    return ptrdata;
}
#else
GLOBAL_ASM(
.text
glabel load_rom_resource_index_to_membank
/* 0F193C 7F0BCE0C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1940 7F0BCE10 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1944 7F0BCE14 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1948 7F0BCE18 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F194C 7F0BCE1C AFA40030 */  sw    $a0, 0x30($sp)
/* 0F1950 7F0BCE20 AFA50034 */  sw    $a1, 0x34($sp)
/* 0F1954 7F0BCE24 AFA60038 */  sw    $a2, 0x38($sp)
/* 0F1958 7F0BCE28 10A00006 */  beqz  $a1, .L7F0BCE44
/* 0F195C 7F0BCE2C AFA7003C */   sw    $a3, 0x3c($sp)
/* 0F1960 7F0BCE30 24010001 */  li    $at, 1
/* 0F1964 7F0BCE34 10A10003 */  beq   $a1, $at, .L7F0BCE44
/* 0F1968 7F0BCE38 24010002 */   li    $at, 2
/* 0F196C 7F0BCE3C 14A10033 */  bne   $a1, $at, .L7F0BCF0C
/* 0F1970 7F0BCE40 8FAD0030 */   lw    $t5, 0x30($sp)
.L7F0BCE44:
/* 0F1974 7F0BCE44 8FAF0030 */  lw    $t7, 0x30($sp)
/* 0F1978 7F0BCE48 3C198009 */  lui   $t9, %hi(resource_lookup_data_array) 
/* 0F197C 7F0BCE4C 273988B0 */  addiu $t9, %lo(resource_lookup_data_array) # addiu $t9, $t9, -0x7750
/* 0F1980 7F0BCE50 000FC080 */  sll   $t8, $t7, 2
/* 0F1984 7F0BCE54 030FC021 */  addu  $t8, $t8, $t7
/* 0F1988 7F0BCE58 0018C080 */  sll   $t8, $t8, 2
/* 0F198C 7F0BCE5C 03198821 */  addu  $s1, $t8, $t9
/* 0F1990 7F0BCE60 8E300004 */  lw    $s0, 4($s1)
/* 0F1994 7F0BCE64 56000006 */  bnezl $s0, .L7F0BCE80
/* 0F1998 7F0BCE68 02002025 */   move  $a0, $s0
/* 0F199C 7F0BCE6C 0C002644 */  jal   mempGetBankSizeLeft
/* 0F19A0 7F0BCE70 93A4003F */   lbu   $a0, 0x3f($sp)
/* 0F19A4 7F0BCE74 AE220004 */  sw    $v0, 4($s1)
/* 0F19A8 7F0BCE78 00408025 */  move  $s0, $v0
/* 0F19AC 7F0BCE7C 02002025 */  move  $a0, $s0
.L7F0BCE80:
/* 0F19B0 7F0BCE80 0C0025C8 */  jal   mempAllocBytesInBank
/* 0F19B4 7F0BCE84 93A5003F */   lbu   $a1, 0x3f($sp)
/* 0F19B8 7F0BCE88 8E300004 */  lw    $s0, 4($s1)
/* 0F19BC 7F0BCE8C 3C0A8004 */  lui   $t2, %hi(file_resource_table) 
/* 0F19C0 7F0BCE90 254A6054 */  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
/* 0F19C4 7F0BCE94 AE30000C */  sw    $s0, 0xc($s1)
/* 0F19C8 7F0BCE98 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F19CC 7F0BCE9C 00402025 */  move  $a0, $v0
/* 0F19D0 7F0BCEA0 02203825 */  move  $a3, $s1
/* 0F19D4 7F0BCEA4 00084880 */  sll   $t1, $t0, 2
/* 0F19D8 7F0BCEA8 01284823 */  subu  $t1, $t1, $t0
/* 0F19DC 7F0BCEAC 00094880 */  sll   $t1, $t1, 2
/* 0F19E0 7F0BCEB0 012A3021 */  addu  $a2, $t1, $t2
/* 0F19E4 7F0BCEB4 8CCB0008 */  lw    $t3, 8($a2)
/* 0F19E8 7F0BCEB8 02002825 */  move  $a1, $s0
/* 0F19EC 7F0BCEBC 15600007 */  bnez  $t3, .L7F0BCEDC
/* 0F19F0 7F0BCEC0 00000000 */   nop   
/* 0F19F4 7F0BCEC4 02002825 */  move  $a1, $s0
/* 0F19F8 7F0BCEC8 02203825 */  move  $a3, $s1
/* 0F19FC 7F0BCECC 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1A00 7F0BCED0 AFA20024 */   sw    $v0, 0x24($sp)
/* 0F1A04 7F0BCED4 10000004 */  b     .L7F0BCEE8
/* 0F1A08 7F0BCED8 8FB00024 */   lw    $s0, 0x24($sp)
.L7F0BCEDC:
/* 0F1A0C 7F0BCEDC 0FC2F2A8 */  jal   load_resource
/* 0F1A10 7F0BCEE0 AFA40024 */   sw    $a0, 0x24($sp)
/* 0F1A14 7F0BCEE4 8FB00024 */  lw    $s0, 0x24($sp)
.L7F0BCEE8:
/* 0F1A18 7F0BCEE8 8FAC0034 */  lw    $t4, 0x34($sp)
/* 0F1A1C 7F0BCEEC 02002025 */  move  $a0, $s0
/* 0F1A20 7F0BCEF0 93A6003F */  lbu   $a2, 0x3f($sp)
/* 0F1A24 7F0BCEF4 51800035 */  beql  $t4, $zero, .L7F0BCFCC
/* 0F1A28 7F0BCEF8 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0F1A2C 7F0BCEFC 0C002601 */  jal   mempAddEntryOfSizeToBank
/* 0F1A30 7F0BCF00 8E250004 */   lw    $a1, 4($s1)
/* 0F1A34 7F0BCF04 10000031 */  b     .L7F0BCFCC
/* 0F1A38 7F0BCF08 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BCF0C:
/* 0F1A3C 7F0BCF0C 000D7080 */  sll   $t6, $t5, 2
/* 0F1A40 7F0BCF10 01CD7021 */  addu  $t6, $t6, $t5
/* 0F1A44 7F0BCF14 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F1A48 7F0BCF18 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F1A4C 7F0BCF1C 000E7080 */  sll   $t6, $t6, 2
/* 0F1A50 7F0BCF20 01CF8821 */  addu  $s1, $t6, $t7
/* 0F1A54 7F0BCF24 8E300004 */  lw    $s0, 4($s1)
/* 0F1A58 7F0BCF28 56000009 */  bnezl $s0, .L7F0BCF50
/* 0F1A5C 7F0BCF2C 02002025 */   move  $a0, $s0
/* 0F1A60 7F0BCF30 8E220000 */  lw    $v0, ($s1)
/* 0F1A64 7F0BCF34 10400003 */  beqz  $v0, .L7F0BCF44
/* 0F1A68 7F0BCF38 00408025 */   move  $s0, $v0
/* 0F1A6C 7F0BCF3C 10000003 */  b     .L7F0BCF4C
/* 0F1A70 7F0BCF40 AE220004 */   sw    $v0, 4($s1)
.L7F0BCF44:
/* 0F1A74 7F0BCF44 8E300008 */  lw    $s0, 8($s1)
/* 0F1A78 7F0BCF48 AE300004 */  sw    $s0, 4($s1)
.L7F0BCF4C:
/* 0F1A7C 7F0BCF4C 02002025 */  move  $a0, $s0
.L7F0BCF50:
/* 0F1A80 7F0BCF50 0C0025C8 */  jal   mempAllocBytesInBank
/* 0F1A84 7F0BCF54 93A5003F */   lbu   $a1, 0x3f($sp)
/* 0F1A88 7F0BCF58 8E390004 */  lw    $t9, 4($s1)
/* 0F1A8C 7F0BCF5C 3C0A8004 */  lui   $t2, %hi(file_resource_table) 
/* 0F1A90 7F0BCF60 254A6054 */  addiu $t2, %lo(file_resource_table) # addiu $t2, $t2, 0x6054
/* 0F1A94 7F0BCF64 AE39000C */  sw    $t9, 0xc($s1)
/* 0F1A98 7F0BCF68 8FA80030 */  lw    $t0, 0x30($sp)
/* 0F1A9C 7F0BCF6C 00408025 */  move  $s0, $v0
/* 0F1AA0 7F0BCF70 02203825 */  move  $a3, $s1
/* 0F1AA4 7F0BCF74 00084880 */  sll   $t1, $t0, 2
/* 0F1AA8 7F0BCF78 01284823 */  subu  $t1, $t1, $t0
/* 0F1AAC 7F0BCF7C 00094880 */  sll   $t1, $t1, 2
/* 0F1AB0 7F0BCF80 012A3021 */  addu  $a2, $t1, $t2
/* 0F1AB4 7F0BCF84 8CCB0008 */  lw    $t3, 8($a2)
/* 0F1AB8 7F0BCF88 02002025 */  move  $a0, $s0
/* 0F1ABC 7F0BCF8C 00002825 */  move  $a1, $zero
/* 0F1AC0 7F0BCF90 15600006 */  bnez  $t3, .L7F0BCFAC
/* 0F1AC4 7F0BCF94 00000000 */   nop   
/* 0F1AC8 7F0BCF98 00402025 */  move  $a0, $v0
/* 0F1ACC 7F0BCF9C 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1AD0 7F0BCFA0 00002825 */   move  $a1, $zero
/* 0F1AD4 7F0BCFA4 10000004 */  b     .L7F0BCFB8
/* 0F1AD8 7F0BCFA8 8FAC0038 */   lw    $t4, 0x38($sp)
.L7F0BCFAC:
/* 0F1ADC 7F0BCFAC 0FC2F2A8 */  jal   load_resource
/* 0F1AE0 7F0BCFB0 02203825 */   move  $a3, $s1
/* 0F1AE4 7F0BCFB4 8FAC0038 */  lw    $t4, 0x38($sp)
.L7F0BCFB8:
/* 0F1AE8 7F0BCFB8 93AD003F */  lbu   $t5, 0x3f($sp)
/* 0F1AEC 7F0BCFBC 55800003 */  bnezl $t4, .L7F0BCFCC
/* 0F1AF0 7F0BCFC0 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0F1AF4 7F0BCFC4 A22D0010 */  sb    $t5, 0x10($s1)
/* 0F1AF8 7F0BCFC8 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BCFCC:
/* 0F1AFC 7F0BCFCC 02001025 */  move  $v0, $s0
/* 0F1B00 7F0BCFD0 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1B04 7F0BCFD4 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1B08 7F0BCFD8 03E00008 */  jr    $ra
/* 0F1B0C 7F0BCFDC 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif



/*
 *this matches except:
 *baserom.u.z64                                                                   
 *000F 1BC0: AE 0C 00 0C 8F A5 00 2C  0F C2 F2 A8 8F A4 00 28  ......., .......( 
 *ge007.u.z64               this   is flipped with   this                 
 *000F 1BC0: AE 0C 00 0C 8F A4 00 28  0F C2 F2 A8 8F A5 00 2C  .......( .......,
 */
#ifdef NONMATCHING//
u8* load_resource_index_to_buffer(s32 index,s32 bank,u8 *ptrdata,s32 bytes)
{
    if (resource_lookup_data_array[index].pc_remaining == 0)
    {
        if (resource_lookup_data_array[index].rom_size > 0)
        {
            resource_lookup_data_array[index].pc_remaining = resource_lookup_data_array[index].rom_size;
        }
        else
        {
            resource_lookup_data_array[index].pc_remaining = resource_lookup_data_array[index].pc_size;
        }
    }
    if (((bank == 0) || (bank == 1)) || (bank == 2))
    {
        if (!file_resource_table[index].hw_address)
        {
            resource_lookup_data_array[index].rom_remaining = bytes;
            resource_load_from_indy(ptrdata, bytes, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        else
        {
            resource_lookup_data_array[index].rom_remaining = bytes;
            //flip happens here
            load_resource(ptrdata, bytes, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
    }
    else
    {
        if (!file_resource_table[index].hw_address)
        {
            resource_load_from_indy(ptrdata, 0, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
        else
        {
            
            load_resource(ptrdata, 0, &file_resource_table[index], &resource_lookup_data_array[index]);
        }
    }
    return ptrdata;
}
#else
GLOBAL_ASM(
.text
glabel load_resource_index_to_buffer
/* 0F1B10 7F0BCFE0 00047080 */  sll   $t6, $a0, 2
/* 0F1B14 7F0BCFE4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F1B18 7F0BCFE8 01C47021 */  addu  $t6, $t6, $a0
/* 0F1B1C 7F0BCFEC 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F1B20 7F0BCFF0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F1B24 7F0BCFF4 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F1B28 7F0BCFF8 000E7080 */  sll   $t6, $t6, 2
/* 0F1B2C 7F0BCFFC 01CF8021 */  addu  $s0, $t6, $t7
/* 0F1B30 7F0BD000 8E180004 */  lw    $t8, 4($s0)
/* 0F1B34 7F0BD004 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1B38 7F0BD008 AFA60028 */  sw    $a2, 0x28($sp)
/* 0F1B3C 7F0BD00C 17000008 */  bnez  $t8, .L7F0BD030
/* 0F1B40 7F0BD010 AFA7002C */   sw    $a3, 0x2c($sp)
/* 0F1B44 7F0BD014 8E020000 */  lw    $v0, ($s0)
/* 0F1B48 7F0BD018 50400004 */  beql  $v0, $zero, .L7F0BD02C
/* 0F1B4C 7F0BD01C 8E190008 */   lw    $t9, 8($s0)
/* 0F1B50 7F0BD020 10000003 */  b     .L7F0BD030
/* 0F1B54 7F0BD024 AE020004 */   sw    $v0, 4($s0)
/* 0F1B58 7F0BD028 8E190008 */  lw    $t9, 8($s0)
.L7F0BD02C:
/* 0F1B5C 7F0BD02C AE190004 */  sw    $t9, 4($s0)
.L7F0BD030:
/* 0F1B60 7F0BD030 10A00005 */  beqz  $a1, .L7F0BD048
/* 0F1B64 7F0BD034 24010001 */   li    $at, 1
/* 0F1B68 7F0BD038 10A10003 */  beq   $a1, $at, .L7F0BD048
/* 0F1B6C 7F0BD03C 24010002 */   li    $at, 2
/* 0F1B70 7F0BD040 14A10019 */  bne   $a1, $at, .L7F0BD0A8
/* 0F1B74 7F0BD044 00046880 */   sll   $t5, $a0, 2
.L7F0BD048:
/* 0F1B78 7F0BD048 00044080 */  sll   $t0, $a0, 2
/* 0F1B7C 7F0BD04C 01044023 */  subu  $t0, $t0, $a0
/* 0F1B80 7F0BD050 3C098004 */  lui   $t1, %hi(file_resource_table) 
/* 0F1B84 7F0BD054 25296054 */  addiu $t1, %lo(file_resource_table) # addiu $t1, $t1, 0x6054
/* 0F1B88 7F0BD058 00084080 */  sll   $t0, $t0, 2
/* 0F1B8C 7F0BD05C 01093021 */  addu  $a2, $t0, $t1
/* 0F1B90 7F0BD060 8CCA0008 */  lw    $t2, 8($a2)
/* 0F1B94 7F0BD064 8FAB002C */  lw    $t3, 0x2c($sp)
/* 0F1B98 7F0BD068 8FAC002C */  lw    $t4, 0x2c($sp)
/* 0F1B9C 7F0BD06C 15400008 */  bnez  $t2, .L7F0BD090
/* 0F1BA0 7F0BD070 02003825 */   move  $a3, $s0
/* 0F1BA4 7F0BD074 AE0B000C */  sw    $t3, 0xc($s0)
/* 0F1BA8 7F0BD078 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1BAC 7F0BD07C 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F1BB0 7F0BD080 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1BB4 7F0BD084 02003825 */   move  $a3, $s0
/* 0F1BB8 7F0BD088 10000019 */  b     .L7F0BD0F0
/* 0F1BBC 7F0BD08C 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD090:
/* 0F1BC0 7F0BD090 AE0C000C */  sw    $t4, 0xc($s0)
/* 0F1BC4 7F0BD094 8FA5002C */  lw    $a1, 0x2c($sp)
/* 0F1BC8 7F0BD098 0FC2F2A8 */  jal   load_resource
/* 0F1BCC 7F0BD09C 8FA40028 */   lw    $a0, 0x28($sp)
/* 0F1BD0 7F0BD0A0 10000013 */  b     .L7F0BD0F0
/* 0F1BD4 7F0BD0A4 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD0A8:
/* 0F1BD8 7F0BD0A8 01A46823 */  subu  $t5, $t5, $a0
/* 0F1BDC 7F0BD0AC 3C0E8004 */  lui   $t6, %hi(file_resource_table) 
/* 0F1BE0 7F0BD0B0 25CE6054 */  addiu $t6, %lo(file_resource_table) # addiu $t6, $t6, 0x6054
/* 0F1BE4 7F0BD0B4 000D6880 */  sll   $t5, $t5, 2
/* 0F1BE8 7F0BD0B8 01AE3021 */  addu  $a2, $t5, $t6
/* 0F1BEC 7F0BD0BC 8CCF0008 */  lw    $t7, 8($a2)
/* 0F1BF0 7F0BD0C0 02003825 */  move  $a3, $s0
/* 0F1BF4 7F0BD0C4 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1BF8 7F0BD0C8 15E00006 */  bnez  $t7, .L7F0BD0E4
/* 0F1BFC 7F0BD0CC 00002825 */   move  $a1, $zero
/* 0F1C00 7F0BD0D0 8FA40028 */  lw    $a0, 0x28($sp)
/* 0F1C04 7F0BD0D4 0FC2F2CD */  jal   resource_load_from_indy
/* 0F1C08 7F0BD0D8 00002825 */   move  $a1, $zero
/* 0F1C0C 7F0BD0DC 10000004 */  b     .L7F0BD0F0
/* 0F1C10 7F0BD0E0 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F0BD0E4:
/* 0F1C14 7F0BD0E4 0FC2F2A8 */  jal   load_resource
/* 0F1C18 7F0BD0E8 02003825 */   move  $a3, $s0
/* 0F1C1C 7F0BD0EC 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F0BD0F0:
/* 0F1C20 7F0BD0F0 8FA20028 */  lw    $v0, 0x28($sp)
/* 0F1C24 7F0BD0F4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F1C28 7F0BD0F8 03E00008 */  jr    $ra
/* 0F1C2C 7F0BD0FC 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif






s32 get_pc_remaining_buffer_for_index(s32 index)
{
    return resource_lookup_data_array[index].pc_remaining;
}


s32 get_rom_remaining_buffer_for_index(s32 index)
{
    return resource_lookup_data_array[index].rom_remaining;
}



#ifdef NONMATCHING
void sub_GAME_7F0BD138(int index, u8 *ptrdata, u32 size, u32 param_4)
{
  u32 new_var;
  resource_lookup_data_array[index].pc_remaining = size;
  resource_lookup_data_array[index].rom_remaining = size;
  new_var = param_4;
  if (new_var)
  {
    mempAddEntryOfSizeToBank(ptrdata, size, 4);
  }

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD138
/* 0F1C68 7F0BD138 00047080 */  sll   $t6, $a0, 2
/* 0F1C6C 7F0BD13C 01C47021 */  addu  $t6, $t6, $a0
/* 0F1C70 7F0BD140 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F1C74 7F0BD144 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F1C78 7F0BD148 000E7080 */  sll   $t6, $t6, 2
/* 0F1C7C 7F0BD14C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F1C80 7F0BD150 01CF1021 */  addu  $v0, $t6, $t7
/* 0F1C84 7F0BD154 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F1C88 7F0BD158 AFA5001C */  sw    $a1, 0x1c($sp)
/* 0F1C8C 7F0BD15C AC460004 */  sw    $a2, 4($v0)
/* 0F1C90 7F0BD160 10E00005 */  beqz  $a3, .L7F0BD178
/* 0F1C94 7F0BD164 AC46000C */   sw    $a2, 0xc($v0)
/* 0F1C98 7F0BD168 00A02025 */  move  $a0, $a1
/* 0F1C9C 7F0BD16C 00C02825 */  move  $a1, $a2
/* 0F1CA0 7F0BD170 0C002601 */  jal   mempAddEntryOfSizeToBank
/* 0F1CA4 7F0BD174 24060004 */   li    $a2, 4
.L7F0BD178:
/* 0F1CA8 7F0BD178 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F1CAC 7F0BD17C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F1CB0 7F0BD180 03E00008 */  jr    $ra
/* 0F1CB4 7F0BD184 00000000 */   nop   
)
#endif






s32 get_pc_buffer_remaining_value(u8 *name)
{
    int index;
    
    index = get_index_num_of_named_resource(name);
    return resource_lookup_data_array[index].pc_remaining;
}


void obBlankResourcesLoadedInBank(u8 bank)
{
    int i;
    for (i = 1; i < file_entry_max; i++) {
        if (resource_lookup_data_array[i].loaded_bank <= bank) {
            resource_lookup_data_array[i].loaded_bank = '\0';
        }
        if (bank == 4) {
            resource_lookup_data_array[i].pc_remaining = 0;
        }
    }
}

void obBlankResourcesInBank5(void) {
  obBlankResourcesLoadedInBank(5);
}





#ifdef NONMATCHING

int get_index_num_of_named_resource(u8 *resname)
{

    int i;
    int buffer [3];
    
    for (i = 1; i < file_entry_max; i++)
    {
        if ((file_resource_table[i].filename) && \
        (something_with_strings_0(resname,file_resource_table[i].filename) == 0));
        {
            return i;
        }
    }

    i = file_entry_max;
    if (file_entry_max < OBJ_INDEX_MAX) {
        file_entry_max += 1;

        if (check_file_found_on_indy(resname,buffer) != 0) {
            file_resource_table[i].index = i;
            file_resource_table[i].filename = resname;
            resource_lookup_data_array[i].unk_11 = '\0';
            file_resource_table[i].hw_address = 0;
            resource_lookup_data_array[i].rom_size = 0;
            resource_lookup_data_array[i].pc_remaining = 0;
            resource_lookup_data_array[i].rom_remaining = 0;
            resource_lookup_data_array[i].loaded_bank = '\0';
            resource_lookup_data_array[i].pc_size = (buffer[0] + 0xfU | 0xf) ^ 0xf;
        }
    }
    else {
        i = 0;
    }
    return i;
}
#else
GLOBAL_ASM(
.text
glabel get_index_num_of_named_resource
/* 0F1D84 7F0BD254 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F1D88 7F0BD258 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F1D8C 7F0BD25C 3C128005 */  lui   $s2, %hi(file_entry_max)
/* 0F1D90 7F0BD260 265282D4 */  addiu $s2, %lo(file_entry_max) # addiu $s2, $s2, -0x7d2c
/* 0F1D94 7F0BD264 8E420000 */  lw    $v0, ($s2)
/* 0F1D98 7F0BD268 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F1D9C 7F0BD26C AFB10018 */  sw    $s1, 0x18($sp)
/* 0F1DA0 7F0BD270 28410002 */  slti  $at, $v0, 2
/* 0F1DA4 7F0BD274 00809825 */  move  $s3, $a0
/* 0F1DA8 7F0BD278 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F1DAC 7F0BD27C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F1DB0 7F0BD280 14200012 */  bnez  $at, .L7F0BD2CC
/* 0F1DB4 7F0BD284 24110001 */   li    $s1, 1
/* 0F1DB8 7F0BD288 3C108004 */  lui   $s0, %hi(file_resource_table + 0xC)
/* 0F1DBC 7F0BD28C 26106060 */  addiu $s0, %lo(file_resource_table + 0xC) # addiu $s0, $s0, 0x6060
/* 0F1DC0 7F0BD290 8E050004 */  lw    $a1, 4($s0)
.L7F0BD294:
/* 0F1DC4 7F0BD294 50A00008 */  beql  $a1, $zero, .L7F0BD2B8
/* 0F1DC8 7F0BD298 8E420000 */   lw    $v0, ($s2)
/* 0F1DCC 7F0BD29C 0C002A13 */  jal   something_with_strings_0
/* 0F1DD0 7F0BD2A0 02602025 */   move  $a0, $s3
/* 0F1DD4 7F0BD2A4 54400004 */  bnezl $v0, .L7F0BD2B8
/* 0F1DD8 7F0BD2A8 8E420000 */   lw    $v0, ($s2)
/* 0F1DDC 7F0BD2AC 1000002E */  b     .L7F0BD368
/* 0F1DE0 7F0BD2B0 02201025 */   move  $v0, $s1
/* 0F1DE4 7F0BD2B4 8E420000 */  lw    $v0, ($s2)
.L7F0BD2B8:
/* 0F1DE8 7F0BD2B8 26310001 */  addiu $s1, $s1, 1
/* 0F1DEC 7F0BD2BC 2610000C */  addiu $s0, $s0, 0xc
/* 0F1DF0 7F0BD2C0 0222082A */  slt   $at, $s1, $v0
/* 0F1DF4 7F0BD2C4 5420FFF3 */  bnezl $at, .L7F0BD294
/* 0F1DF8 7F0BD2C8 8E050004 */   lw    $a1, 4($s0)
.L7F0BD2CC:
/* 0F1DFC 7F0BD2CC 284102E0 */  slti  $at, $v0, 0x2e0 /*OBJ_INDEX_MAX*/
/* 0F1E00 7F0BD2D0 14200003 */  bnez  $at, .L7F0BD2E0
/* 0F1E04 7F0BD2D4 00408825 */   move  $s1, $v0
/* 0F1E08 7F0BD2D8 10000023 */  b     .L7F0BD368
/* 0F1E0C 7F0BD2DC 00001025 */   move  $v0, $zero
.L7F0BD2E0:
/* 0F1E10 7F0BD2E0 244E0001 */  addiu $t6, $v0, 1
/* 0F1E14 7F0BD2E4 AE4E0000 */  sw    $t6, ($s2)
/* 0F1E18 7F0BD2E8 02602025 */  move  $a0, $s3
/* 0F1E1C 7F0BD2EC 0FC34026 */  jal   check_file_found_on_indy
/* 0F1E20 7F0BD2F0 27A50034 */   addiu $a1, $sp, 0x34
/* 0F1E24 7F0BD2F4 14400003 */  bnez  $v0, .L7F0BD304
/* 0F1E28 7F0BD2F8 00117880 */   sll   $t7, $s1, 2
/* 0F1E2C 7F0BD2FC 1000001A */  b     .L7F0BD368
/* 0F1E30 7F0BD300 00001025 */   move  $v0, $zero
.L7F0BD304:
/* 0F1E34 7F0BD304 01F17823 */  subu  $t7, $t7, $s1
/* 0F1E38 7F0BD308 3C188004 */  lui   $t8, %hi(file_resource_table) 
/* 0F1E3C 7F0BD30C 27186054 */  addiu $t8, %lo(file_resource_table) # addiu $t8, $t8, 0x6054
/* 0F1E40 7F0BD310 000F7880 */  sll   $t7, $t7, 2
/* 0F1E44 7F0BD314 0011C880 */  sll   $t9, $s1, 2
/* 0F1E48 7F0BD318 01F88021 */  addu  $s0, $t7, $t8
/* 0F1E4C 7F0BD31C 0331C821 */  addu  $t9, $t9, $s1
/* 0F1E50 7F0BD320 3C088009 */  lui   $t0, %hi(resource_lookup_data_array) 
/* 0F1E54 7F0BD324 250888B0 */  addiu $t0, %lo(resource_lookup_data_array) # addiu $t0, $t0, -0x7750
/* 0F1E58 7F0BD328 0019C880 */  sll   $t9, $t9, 2
/* 0F1E5C 7F0BD32C AE110000 */  sw    $s1, ($s0)
/* 0F1E60 7F0BD330 AE130004 */  sw    $s3, 4($s0)
/* 0F1E64 7F0BD334 03281821 */  addu  $v1, $t9, $t0
/* 0F1E68 7F0BD338 A0600011 */  sb    $zero, 0x11($v1)
/* 0F1E6C 7F0BD33C AE000008 */  sw    $zero, 8($s0)
/* 0F1E70 7F0BD340 AC600000 */  sw    $zero, ($v1)
/* 0F1E74 7F0BD344 AC600004 */  sw    $zero, 4($v1)
/* 0F1E78 7F0BD348 8FA90034 */  lw    $t1, 0x34($sp)
/* 0F1E7C 7F0BD34C AC60000C */  sw    $zero, 0xc($v1)
/* 0F1E80 7F0BD350 A0600010 */  sb    $zero, 0x10($v1)
/* 0F1E84 7F0BD354 252A000F */  addiu $t2, $t1, 0xf
/* 0F1E88 7F0BD358 354B000F */  ori   $t3, $t2, 0xf
/* 0F1E8C 7F0BD35C 396C000F */  xori  $t4, $t3, 0xf
/* 0F1E90 7F0BD360 AC6C0008 */  sw    $t4, 8($v1)
/* 0F1E94 7F0BD364 02201025 */  move  $v0, $s1
.L7F0BD368:
/* 0F1E98 7F0BD368 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F1E9C 7F0BD36C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F1EA0 7F0BD370 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F1EA4 7F0BD374 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F1EA8 7F0BD378 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F1EAC 7F0BD37C 03E00008 */  jr    $ra
/* 0F1EB0 7F0BD380 27BD0040 */   addiu $sp, $sp, 0x40
)
#endif





void removed_handle_filetable_entry(u32 index)
{
    return;
}

void removed_loop_handle_filetable_entries(void)
{
    int i;
    for (i = 1; (i < file_entry_max); i++)
    {
        removed_handle_filetable_entry(i);
    }
}

void removed_loop_filetableentries(void)
{
    int i;
    
    for (i = 1; (i < file_entry_max); i++)
    {
        ;
    }
}






#ifdef NONMATCHING
void *sub_GAME_7F0BD410(void) {
    u32 temp_v0;
    u32 phi_v0;

    // Node 0
    if (file_entry_max >= 2)
    {
        // Node 1
        phi_v0 = &resource_lookup_data_array+0x14;
loop_2:
        // Node 2
        temp_v0 = (phi_v0 + 0x14);
        phi_v0 = temp_v0;
        if (temp_v0 < (u32) ((file_entry_max * 0x14) + &resource_lookup_data_array))
        {
            goto loop_2;
        }
    }
    // Node 3
    return &resource_lookup_data_array+0x14;
}

#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F0BD410
/* 0F1F40 7F0BD410 3C038005 */  lui   $v1, %hi(file_entry_max)
/* 0F1F44 7F0BD414 8C6382D4 */  lw    $v1, %lo(file_entry_max)($v1)
/* 0F1F48 7F0BD418 3C028009 */  lui   $v0, %hi(resource_lookup_data_array+0x14)
/* 0F1F4C 7F0BD41C 244288C4 */  addiu $v0, %lo(resource_lookup_data_array+0x14) # addiu $v0, $v0, -0x773c
/* 0F1F50 7F0BD420 28610002 */  slti  $at, $v1, 2
/* 0F1F54 7F0BD424 1420000A */  bnez  $at, .L7F0BD450
/* 0F1F58 7F0BD428 00037080 */   sll   $t6, $v1, 2
/* 0F1F5C 7F0BD42C 01C37021 */  addu  $t6, $t6, $v1
/* 0F1F60 7F0BD430 3C0F8009 */  lui   $t7, %hi(resource_lookup_data_array) 
/* 0F1F64 7F0BD434 25EF88B0 */  addiu $t7, %lo(resource_lookup_data_array) # addiu $t7, $t7, -0x7750
/* 0F1F68 7F0BD438 000E7080 */  sll   $t6, $t6, 2
/* 0F1F6C 7F0BD43C 01CF2021 */  addu  $a0, $t6, $t7
/* 0F1F70 7F0BD440 24420014 */  addiu $v0, $v0, 0x14
.L7F0BD444:
/* 0F1F74 7F0BD444 0044082B */  sltu  $at, $v0, $a0
/* 0F1F78 7F0BD448 5420FFFE */  bnezl $at, .L7F0BD444
/* 0F1F7C 7F0BD44C 24420014 */   addiu $v0, $v0, 0x14
.L7F0BD450:
/* 0F1F80 7F0BD450 03E00008 */  jr    $ra
/* 0F1F84 7F0BD454 00000000 */   nop   
)
#endif


 

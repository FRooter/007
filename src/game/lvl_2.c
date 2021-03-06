
#include "ultra64.h"
#include "game/debugmenu_090490.h"
#include "game/lvl.h"
#include "game/initunk_0072B0.h"
#include "game/mainmenu.h"


//D:800483F0

//move me to better home
extern u32* ramrom_Dam_1;
extern u32* ramrom_Dam_2;
extern u32* ramrom_Facility_1;
extern u32* ramrom_Facility_2;
extern u32* ramrom_Facility_3;
extern u32* ramrom_Runway_1;
extern u32* ramrom_Runway_2;
extern u32* ramrom_BunkerI_1;
extern u32* ramrom_BunkerI_2;
extern u32* ramrom_Silo_1;
extern u32* ramrom_Silo_2;
extern u32* ramrom_Frigate_1;
extern u32* ramrom_Frigate_2;
extern u32* ramrom_Train;

struct ramrom_struct ramrom_table[] = {
    {&ramrom_Dam_1, 0}, {&ramrom_Dam_2, 0}, {&ramrom_Facility_1, 0}, {&ramrom_Facility_2, 0}, {&ramrom_Facility_3, 0}, 
    {&ramrom_Runway_1, 0}, {&ramrom_Runway_2, 0}, {&ramrom_BunkerI_1, 0}, {&ramrom_BunkerI_2, 0}, {&ramrom_Silo_1, 0},
    {&ramrom_Silo_2, 0}, {&ramrom_Frigate_1, 0}, {&ramrom_Frigate_2, 0}, {&ramrom_Train, 0}, {0,0}
};

//D:80048468
s32 ptr_active_demofile = 0;
//D:8004846C
s32 ramrom_blkbuf_2 = 0;
//D:80048470
s32 ramrom_blkbuf_3 = 0;
//D:80048474
s32 is_ramrom_flag = 0;
//D:80048478
s32 ramrom_demo_related_3 = 0;
//D:8004847C
s32 ramrom_demo_related_4 = 0;
//D:80048480
s32 recording_ramrom_flag = 0;
//D:80048484
s32 ramrom_demo_related_6 = 0;
//D:80048488
s32 flag_to_record_ramrom = 0;
//D:8004848C
//                     .align 4

//D:8005B750
const char aReplayDemo_D[] = "replay/demo.%d";
//D:8005B760
const char aReplayDemo_D_1[] = "replay/demo.%d";
//D:8005B770
const char aReplayDemo_load[] = "replay/demo.load";







void clear_ramrom_block_buffer_heading_ptrs(void) {
    ptr_active_demofile = 0;
    ramrom_blkbuf_2 = 0;
    ramrom_blkbuf_3 = 0;
}


s32 get_is_ramrom_flag(void) {
    return is_ramrom_flag;
}


s32 get_recording_ramrom_flag(void) {
    return recording_ramrom_flag;
}


s32 interface_menu0B_runstage(void) {
    return ramrom_demo_related_4;
}

#ifdef NONMATCHING
void finalize_ramrom_on_hw(void) {
    s32 temp_a0;
    ? temp_ret;

    // Node 0
    temp_a0 = (((sp + 0x2f) | 0xf) ^ 0xf);
    *temp_a0 = (u8)0;
    temp_a0->unk1 = (u8)0;
    romWrite(temp_a0, address_demo_loaded, 0x10);
    address_demo_loaded = (s32) (address_demo_loaded + 4);
    temp_ret = romCopyAligned(&ramrom_data_target, 0xf00000, 0xf0);
    ptr_active_demofile = temp_ret;
    temp_ret->unk7C = (s32) (global_timer - clock_timer);
    ptr_active_demofile->unk80 = (s32) (address_demo_loaded - 0xf00000);
    return romWrite(ptr_active_demofile, 0xf00000, 0xf0);
}
#else
GLOBAL_ASM(
.text
glabel finalize_ramrom_on_hw
/* 0F47E0 7F0BFCB0 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0F47E4 7F0BFCB4 03A02025 */  move  $a0, $sp
/* 0F47E8 7F0BFCB8 2484002F */  addiu $a0, $a0, 0x2f
/* 0F47EC 7F0BFCBC 348E000F */  ori   $t6, $a0, 0xf
/* 0F47F0 7F0BFCC0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F47F4 7F0BFCC4 39C4000F */  xori  $a0, $t6, 0xf
/* 0F47F8 7F0BFCC8 A0800000 */  sb    $zero, ($a0)
/* 0F47FC 7F0BFCCC A0800001 */  sb    $zero, 1($a0)
/* 0F4800 7F0BFCD0 3C058009 */  lui   $a1, %hi(address_demo_loaded)
/* 0F4804 7F0BFCD4 8CA5C5F4 */  lw    $a1, %lo(address_demo_loaded)($a1)
/* 0F4808 7F0BFCD8 0C001742 */  jal   romWrite
/* 0F480C 7F0BFCDC 24060010 */   li    $a2, 16
/* 0F4810 7F0BFCE0 3C028009 */  lui   $v0, %hi(address_demo_loaded)
/* 0F4814 7F0BFCE4 2442C5F4 */  addiu $v0, %lo(address_demo_loaded) # addiu $v0, $v0, -0x3a0c
/* 0F4818 7F0BFCE8 8C580000 */  lw    $t8, ($v0)
/* 0F481C 7F0BFCEC 3C048009 */  lui   $a0, %hi(ramrom_data_target)
/* 0F4820 7F0BFCF0 2484C270 */  addiu $a0, %lo(ramrom_data_target) # addiu $a0, $a0, -0x3d90
/* 0F4824 7F0BFCF4 27190004 */  addiu $t9, $t8, 4
/* 0F4828 7F0BFCF8 AC590000 */  sw    $t9, ($v0)
/* 0F482C 7F0BFCFC 3C0500F0 */  lui   $a1, 0xf0
/* 0F4830 7F0BFD00 0C001711 */  jal   romCopyAligned
/* 0F4834 7F0BFD04 240600F0 */   li    $a2, 240
/* 0F4838 7F0BFD08 3C038005 */  lui   $v1, %hi(ptr_active_demofile)
/* 0F483C 7F0BFD0C 24638468 */  addiu $v1, %lo(ptr_active_demofile) # addiu $v1, $v1, -0x7b98
/* 0F4840 7F0BFD10 AC620000 */  sw    $v0, ($v1)
/* 0F4844 7F0BFD14 3C088005 */  lui   $t0, %hi(global_timer) 
/* 0F4848 7F0BFD18 3C098005 */  lui   $t1, %hi(clock_timer) 
/* 0F484C 7F0BFD1C 8D298374 */  lw    $t1, %lo(clock_timer)($t1)
/* 0F4850 7F0BFD20 8D08837C */  lw    $t0, %lo(global_timer)($t0)
/* 0F4854 7F0BFD24 3C0C8009 */  lui   $t4, %hi(address_demo_loaded) 
/* 0F4858 7F0BFD28 3C0500F0 */  lui   $a1, 0xf0
/* 0F485C 7F0BFD2C 01095023 */  subu  $t2, $t0, $t1
/* 0F4860 7F0BFD30 AC4A007C */  sw    $t2, 0x7c($v0)
/* 0F4864 7F0BFD34 8D8CC5F4 */  lw    $t4, %lo(address_demo_loaded)($t4)
/* 0F4868 7F0BFD38 8C6E0000 */  lw    $t6, ($v1)
/* 0F486C 7F0BFD3C 240600F0 */  li    $a2, 240
/* 0F4870 7F0BFD40 01856823 */  subu  $t5, $t4, $a1
/* 0F4874 7F0BFD44 ADCD0080 */  sw    $t5, 0x80($t6)
/* 0F4878 7F0BFD48 0C001742 */  jal   romWrite
/* 0F487C 7F0BFD4C 8C640000 */   lw    $a0, ($v1)
/* 0F4880 7F0BFD50 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F4884 7F0BFD54 27BD0048 */  addiu $sp, $sp, 0x48
/* 0F4888 7F0BFD58 03E00008 */  jr    $ra
/* 0F488C 7F0BFD5C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void save_ramrom_to_devtool(void)
{
    int iVar2;
    undefined auStack264 [4];
    char indyFileName [260];
    
    for (iVar2 = 1; check_file_found_on_indy(indyFileName,(u32)auStack264) != 0; iVar2++)
    {
        sprintf(indyFileName,"replay/demo.%d",iVar2);
    }
    sprintf(indyFileName,"replay/demo.%d",iVar2);
    check_file_exported(indyFileName,0xf00000,(ptr_active_demofile + 0x80));
}
#else
GLOBAL_ASM(
.text
glabel save_ramrom_to_devtool
/* 0F4890 7F0BFD60 27BDFED0 */  addiu $sp, $sp, -0x130
/* 0F4894 7F0BFD64 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0F4898 7F0BFD68 AFB30020 */  sw    $s3, 0x20($sp)
/* 0F489C 7F0BFD6C AFB10018 */  sw    $s1, 0x18($sp)
/* 0F48A0 7F0BFD70 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F48A4 7F0BFD74 3C128006 */  lui   $s2, %hi(aReplayDemo_D)
/* 0F48A8 7F0BFD78 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0F48AC 7F0BFD7C 2652B750 */  addiu $s2, %lo(aReplayDemo_D) # addiu $s2, $s2, -0x48b0
/* 0F48B0 7F0BFD80 24100001 */  li    $s0, 1
/* 0F48B4 7F0BFD84 27B1002C */  addiu $s1, $sp, 0x2c
/* 0F48B8 7F0BFD88 27B30028 */  addiu $s3, $sp, 0x28
.L7F0BFD8C:
/* 0F48BC 7F0BFD8C 02202025 */  move  $a0, $s1
/* 0F48C0 7F0BFD90 02402825 */  move  $a1, $s2
/* 0F48C4 7F0BFD94 0C002B25 */  jal   sprintf
/* 0F48C8 7F0BFD98 02003025 */   move  $a2, $s0
/* 0F48CC 7F0BFD9C 02202025 */  move  $a0, $s1
/* 0F48D0 7F0BFDA0 0FC34026 */  jal   check_file_found_on_indy
/* 0F48D4 7F0BFDA4 02602825 */   move  $a1, $s3
/* 0F48D8 7F0BFDA8 10400003 */  beqz  $v0, .L7F0BFDB8
/* 0F48DC 7F0BFDAC 00000000 */   nop   
/* 0F48E0 7F0BFDB0 1000FFF6 */  b     .L7F0BFD8C
/* 0F48E4 7F0BFDB4 26100001 */   addiu $s0, $s0, 1
.L7F0BFDB8:
/* 0F48E8 7F0BFDB8 3C058006 */  lui   $a1, %hi(aReplayDemo_D_1)
/* 0F48EC 7F0BFDBC 24A5B760 */  addiu $a1, %lo(aReplayDemo_D_1) # addiu $a1, $a1, -0x48a0
/* 0F48F0 7F0BFDC0 02202025 */  move  $a0, $s1
/* 0F48F4 7F0BFDC4 0C002B25 */  jal   sprintf
/* 0F48F8 7F0BFDC8 02003025 */   move  $a2, $s0
/* 0F48FC 7F0BFDCC 3C0E8005 */  lui   $t6, %hi(ptr_active_demofile) 
/* 0F4900 7F0BFDD0 8DCE8468 */  lw    $t6, %lo(ptr_active_demofile)($t6)
/* 0F4904 7F0BFDD4 02202025 */  move  $a0, $s1
/* 0F4908 7F0BFDD8 3C0500F0 */  lui   $a1, 0xf0
/* 0F490C 7F0BFDDC 0FC34017 */  jal   check_file_exported
/* 0F4910 7F0BFDE0 8DC60080 */   lw    $a2, 0x80($t6)
/* 0F4914 7F0BFDE4 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0F4918 7F0BFDE8 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F491C 7F0BFDEC 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F4920 7F0BFDF0 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0F4924 7F0BFDF4 8FB30020 */  lw    $s3, 0x20($sp)
/* 0F4928 7F0BFDF8 03E00008 */  jr    $ra
/* 0F492C 7F0BFDFC 27BD0130 */   addiu $sp, $sp, 0x130
)
#endif





#ifdef NONMATCHING
void load_ramrom_from_devtool(void)
{
    s32 size;

    if (check_file_found_on_indy("replay/demo.load", &size) != 0)
    {
        indy_load_ramrom_file("replay/demo.load",(u8 *)0xf00000,size);
        ptr_active_demofile = romCopyAligned(&ramrom_data_target,(u8 *)0xf00000,0xe8);
    }
}
#else
GLOBAL_ASM(
.text
glabel load_ramrom_from_devtool
/* 0F4930 7F0BFE00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4934 7F0BFE04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F4938 7F0BFE08 3C048006 */  lui   $a0, %hi(aReplayDemo_load)
/* 0F493C 7F0BFE0C 2484B770 */  addiu $a0, %lo(aReplayDemo_load) # addiu $a0, $a0, -0x4890
/* 0F4940 7F0BFE10 0FC34026 */  jal   check_file_found_on_indy
/* 0F4944 7F0BFE14 27A5001C */   addiu $a1, $sp, 0x1c
/* 0F4948 7F0BFE18 1040000C */  beqz  $v0, .L7F0BFE4C
/* 0F494C 7F0BFE1C 3C048006 */   lui   $a0, %hi(aReplayDemo_load)
/* 0F4950 7F0BFE20 2484B770 */  addiu $a0, %lo(aReplayDemo_load) # addiu $a0, $a0, -0x4890
/* 0F4954 7F0BFE24 3C0500F0 */  lui   $a1, 0xf0
/* 0F4958 7F0BFE28 0FC34007 */  jal   indy_loadfile
/* 0F495C 7F0BFE2C 8FA6001C */   lw    $a2, 0x1c($sp)
/* 0F4960 7F0BFE30 3C048009 */  lui   $a0, %hi(ramrom_data_target)
/* 0F4964 7F0BFE34 2484C270 */  addiu $a0, %lo(ramrom_data_target) # addiu $a0, $a0, -0x3d90
/* 0F4968 7F0BFE38 3C0500F0 */  lui   $a1, 0xf0
/* 0F496C 7F0BFE3C 0C001711 */  jal   romCopyAligned
/* 0F4970 7F0BFE40 240600E8 */   li    $a2, 232
/* 0F4974 7F0BFE44 3C018005 */  lui   $at, %hi(ptr_active_demofile)
/* 0F4978 7F0BFE48 AC228468 */  sw    $v0, %lo(ptr_active_demofile)($at)
.L7F0BFE4C:
/* 0F497C 7F0BFE4C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F4980 7F0BFE50 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F4984 7F0BFE54 03E00008 */  jr    $ra
/* 0F4988 7F0BFE58 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void record_player_input_as_packet(void) {

}
#else
GLOBAL_ASM(
.text
glabel record_player_input_as_packet
/* 0F498C 7F0BFE5C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4990 7F0BFE60 3C0E8005 */  lui   $t6, %hi(ptr_active_demofile) 
/* 0F4994 7F0BFE64 3C0F8009 */  lui   $t7, %hi(ramrom_data_target + 0x1F8) 
/* 0F4998 7F0BFE68 8DCE8468 */  lw    $t6, %lo(ptr_active_demofile)($t6)
/* 0F499C 7F0BFE6C 25EFC468 */  addiu $t7, %lo(ramrom_data_target + 0x1F8) # addiu $t7, $t7, -0x3b98
/* 0F49A0 7F0BFE70 25F8000F */  addiu $t8, $t7, 0xf
/* 0F49A4 7F0BFE74 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F49A8 7F0BFE78 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F49AC 7F0BFE7C AFB00014 */  sw    $s0, 0x14($sp)
/* 0F49B0 7F0BFE80 3719000F */  ori   $t9, $t8, 0xf
/* 0F49B4 7F0BFE84 3C088005 */  lui   $t0, %hi(ramrom_blkbuf_3) 
/* 0F49B8 7F0BFE88 3C0C8005 */  lui   $t4, %hi(ramrom_blkbuf_2) 
/* 0F49BC 7F0BFE8C 3B2D000F */  xori  $t5, $t9, 0xf
/* 0F49C0 7F0BFE90 8DC90018 */  lw    $t1, 0x18($t6)
/* 0F49C4 7F0BFE94 258C846C */  addiu $t4, %lo(ramrom_blkbuf_2) # addiu $t4, $t4, -0x7b94
/* 0F49C8 7F0BFE98 25088470 */  addiu $t0, %lo(ramrom_blkbuf_3) # addiu $t0, $t0, -0x7b90
/* 0F49CC 7F0BFE9C 25AE0004 */  addiu $t6, $t5, 4
/* 0F49D0 7F0BFEA0 00C08025 */  move  $s0, $a2
/* 0F49D4 7F0BFEA4 00808825 */  move  $s1, $a0
/* 0F49D8 7F0BFEA8 00005025 */  move  $t2, $zero
/* 0F49DC 7F0BFEAC 00003825 */  move  $a3, $zero
/* 0F49E0 7F0BFEB0 AD8D0000 */  sw    $t5, ($t4)
/* 0F49E4 7F0BFEB4 AD0E0000 */  sw    $t6, ($t0)
/* 0F49E8 7F0BFEB8 10A60048 */  beq   $a1, $a2, .L7F0BFFDC
/* 0F49EC 7F0BFEBC 01A01025 */   move  $v0, $t5
/* 0F49F0 7F0BFEC0 240B0014 */  li    $t3, 20
/* 0F49F4 7F0BFEC4 24AF0001 */  addiu $t7, $a1, 1
/* 0F49F8 7F0BFEC8 01EB001A */  div   $zero, $t7, $t3
/* 0F49FC 7F0BFECC 00003010 */  mfhi  $a2
/* 0F4A00 7F0BFED0 00002025 */  move  $a0, $zero
/* 0F4A04 7F0BFED4 15600002 */  bnez  $t3, .L7F0BFEE0
/* 0F4A08 7F0BFED8 00000000 */   nop   
/* 0F4A0C 7F0BFEDC 0007000D */  break 7
.L7F0BFEE0:
/* 0F4A10 7F0BFEE0 2401FFFF */  li    $at, -1
/* 0F4A14 7F0BFEE4 15610004 */  bne   $t3, $at, .L7F0BFEF8
/* 0F4A18 7F0BFEE8 3C018000 */   lui   $at, 0x8000
/* 0F4A1C 7F0BFEEC 15E10002 */  bne   $t7, $at, .L7F0BFEF8
/* 0F4A20 7F0BFEF0 00000000 */   nop   
/* 0F4A24 7F0BFEF4 0006000D */  break 6
.L7F0BFEF8:
/* 0F4A28 7F0BFEF8 19200025 */  blez  $t1, .L7F0BFF90
/* 0F4A2C 7F0BFEFC 00000000 */   nop   
/* 0F4A30 7F0BFF00 01490019 */  multu $t2, $t1
/* 0F4A34 7F0BFF04 0006C880 */  sll   $t9, $a2, 2
/* 0F4A38 7F0BFF08 00196880 */  sll   $t5, $t9, 2
/* 0F4A3C 7F0BFF0C 01B96823 */  subu  $t5, $t5, $t9
/* 0F4A40 7F0BFF10 000D6840 */  sll   $t5, $t5, 1
/* 0F4A44 7F0BFF14 022D1821 */  addu  $v1, $s1, $t5
/* 0F4A48 7F0BFF18 00002812 */  mflo  $a1
/* 0F4A4C 7F0BFF1C 0005C080 */  sll   $t8, $a1, 2
/* 0F4A50 7F0BFF20 03002825 */  move  $a1, $t8
.L7F0BFF24:
/* 0F4A54 7F0BFF24 8D0E0000 */  lw    $t6, ($t0)
/* 0F4A58 7F0BFF28 80790002 */  lb    $t9, 2($v1)
/* 0F4A5C 7F0BFF2C 0004C080 */  sll   $t8, $a0, 2
/* 0F4A60 7F0BFF30 00AE7821 */  addu  $t7, $a1, $t6
/* 0F4A64 7F0BFF34 01F81021 */  addu  $v0, $t7, $t8
/* 0F4A68 7F0BFF38 A0590000 */  sb    $t9, ($v0)
/* 0F4A6C 7F0BFF3C 806D0003 */  lb    $t5, 3($v1)
/* 0F4A70 7F0BFF40 24840001 */  addiu $a0, $a0, 1
/* 0F4A74 7F0BFF44 24630006 */  addiu $v1, $v1, 6
/* 0F4A78 7F0BFF48 A04D0001 */  sb    $t5, 1($v0)
/* 0F4A7C 7F0BFF4C 946FFFFA */  lhu   $t7, -6($v1)
/* 0F4A80 7F0BFF50 904E0001 */  lbu   $t6, 1($v0)
/* 0F4A84 7F0BFF54 904D0000 */  lbu   $t5, ($v0)
/* 0F4A88 7F0BFF58 A04F0002 */  sb    $t7, 2($v0)
/* 0F4A8C 7F0BFF5C 9478FFFA */  lhu   $t8, -6($v1)
/* 0F4A90 7F0BFF60 01AE7821 */  addu  $t7, $t5, $t6
/* 0F4A94 7F0BFF64 0018CA03 */  sra   $t9, $t8, 8
/* 0F4A98 7F0BFF68 90580002 */  lbu   $t8, 2($v0)
/* 0F4A9C 7F0BFF6C A0590003 */  sb    $t9, 3($v0)
/* 0F4AA0 7F0BFF70 904D0003 */  lbu   $t5, 3($v0)
/* 0F4AA4 7F0BFF74 01F8C821 */  addu  $t9, $t7, $t8
/* 0F4AA8 7F0BFF78 032D7021 */  addu  $t6, $t9, $t5
/* 0F4AAC 7F0BFF7C 31CF00FF */  andi  $t7, $t6, 0xff
/* 0F4AB0 7F0BFF80 00EF3821 */  addu  $a3, $a3, $t7
/* 0F4AB4 7F0BFF84 30F800FF */  andi  $t8, $a3, 0xff
/* 0F4AB8 7F0BFF88 1489FFE6 */  bne   $a0, $t1, .L7F0BFF24
/* 0F4ABC 7F0BFF8C 03003825 */   move  $a3, $t8
.L7F0BFF90:
/* 0F4AC0 7F0BFF90 14D00003 */  bne   $a2, $s0, .L7F0BFFA0
/* 0F4AC4 7F0BFF94 254A0001 */   addiu $t2, $t2, 1
/* 0F4AC8 7F0BFF98 10000010 */  b     .L7F0BFFDC
/* 0F4ACC 7F0BFF9C 8D820000 */   lw    $v0, ($t4)
.L7F0BFFA0:
/* 0F4AD0 7F0BFFA0 24D90001 */  addiu $t9, $a2, 1
/* 0F4AD4 7F0BFFA4 032B001A */  div   $zero, $t9, $t3
/* 0F4AD8 7F0BFFA8 00003010 */  mfhi  $a2
/* 0F4ADC 7F0BFFAC 00002025 */  move  $a0, $zero
/* 0F4AE0 7F0BFFB0 15600002 */  bnez  $t3, .L7F0BFFBC
/* 0F4AE4 7F0BFFB4 00000000 */   nop   
/* 0F4AE8 7F0BFFB8 0007000D */  break 7
.L7F0BFFBC:
/* 0F4AEC 7F0BFFBC 2401FFFF */  li    $at, -1
/* 0F4AF0 7F0BFFC0 15610004 */  bne   $t3, $at, .L7F0BFFD4
/* 0F4AF4 7F0BFFC4 3C018000 */   lui   $at, 0x8000
/* 0F4AF8 7F0BFFC8 17210002 */  bne   $t9, $at, .L7F0BFFD4
/* 0F4AFC 7F0BFFCC 00000000 */   nop   
/* 0F4B00 7F0BFFD0 0006000D */  break 6
.L7F0BFFD4:
/* 0F4B04 7F0BFFD4 1000FFC8 */  b     .L7F0BFEF8
/* 0F4B08 7F0BFFD8 00000000 */   nop   
.L7F0BFFDC:
/* 0F4B0C 7F0BFFDC A04A0001 */  sb    $t2, 1($v0)
/* 0F4B10 7F0BFFE0 3C0D8005 */  lui   $t5, %hi(D_80048498) 
/* 0F4B14 7F0BFFE4 8DAD8498 */  lw    $t5, %lo(D_80048498)($t5)
/* 0F4B18 7F0BFFE8 8D8E0000 */  lw    $t6, ($t4)
/* 0F4B1C 7F0BFFEC 3C198002 */  lui   $t9, %hi(randseed + 0x4) 
/* 0F4B20 7F0BFFF0 3C118009 */  lui   $s1, %hi(address_demo_loaded)
/* 0F4B24 7F0BFFF4 A1CD0000 */  sb    $t5, ($t6)
/* 0F4B28 7F0BFFF8 8D8D0000 */  lw    $t5, ($t4)
/* 0F4B2C 7F0BFFFC 8F394464 */  lw    $t9, %lo(randseed + 0x4)($t9)
/* 0F4B30 7F0C0000 2631C5F4 */  addiu $s1, %lo(address_demo_loaded) # addiu $s1, $s1, -0x3a0c
/* 0F4B34 7F0C0004 A1B90002 */  sb    $t9, 2($t5)
/* 0F4B38 7F0C0008 8D820000 */  lw    $v0, ($t4)
/* 0F4B3C 7F0C000C 904E0000 */  lbu   $t6, ($v0)
/* 0F4B40 7F0C0010 90580001 */  lbu   $t8, 1($v0)
/* 0F4B44 7F0C0014 904F0002 */  lbu   $t7, 2($v0)
/* 0F4B48 7F0C0018 01D8C821 */  addu  $t9, $t6, $t8
/* 0F4B4C 7F0C001C 032F7021 */  addu  $t6, $t9, $t7
/* 0F4B50 7F0C0020 0009C880 */  sll   $t9, $t1, 2
/* 0F4B54 7F0C0024 032A0019 */  multu $t9, $t2
/* 0F4B58 7F0C0028 00EEC021 */  addu  $t8, $a3, $t6
/* 0F4B5C 7F0C002C A0580003 */  sb    $t8, 3($v0)
/* 0F4B60 7F0C0030 8E250000 */  lw    $a1, ($s1)
/* 0F4B64 7F0C0034 8D840000 */  lw    $a0, ($t4)
/* 0F4B68 7F0C0038 00008012 */  mflo  $s0
/* 0F4B6C 7F0C003C 26100004 */  addiu $s0, $s0, 4
/* 0F4B70 7F0C0040 2606000F */  addiu $a2, $s0, 0xf
/* 0F4B74 7F0C0044 34CF000F */  ori   $t7, $a2, 0xf
/* 0F4B78 7F0C0048 0C001742 */  jal   romWrite
/* 0F4B7C 7F0C004C 39E6000F */   xori  $a2, $t7, 0xf
/* 0F4B80 7F0C0050 8E2E0000 */  lw    $t6, ($s1)
/* 0F4B84 7F0C0054 26180001 */  addiu $t8, $s0, 1
/* 0F4B88 7F0C0058 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F4B8C 7F0C005C 37190001 */  ori   $t9, $t8, 1
/* 0F4B90 7F0C0060 3B2F0001 */  xori  $t7, $t9, 1
/* 0F4B94 7F0C0064 3C018009 */  lui   $at, %hi(address_demo_loaded)
/* 0F4B98 7F0C0068 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F4B9C 7F0C006C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F4BA0 7F0C0070 01CF6821 */  addu  $t5, $t6, $t7
/* 0F4BA4 7F0C0074 AC2DC5F4 */  sw    $t5, %lo(address_demo_loaded)($at)
/* 0F4BA8 7F0C0078 03E00008 */  jr    $ra
/* 0F4BAC 7F0C007C 27BD0020 */   addiu $sp, $sp, 0x20
)
#endif





#ifdef NONMATCHING
void ramrom_replay_handler(void) {

}
#else
GLOBAL_ASM(
.text
glabel ramrom_replay_handler
/* 0F4BB0 7F0C0080 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F4BB4 7F0C0084 3C028005 */  lui   $v0, %hi(ramrom_blkbuf_2)
/* 0F4BB8 7F0C0088 8C42846C */  lw    $v0, %lo(ramrom_blkbuf_2)($v0)
/* 0F4BBC 7F0C008C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F4BC0 7F0C0090 AFB10018 */  sw    $s1, 0x18($sp)
/* 0F4BC4 7F0C0094 AFB00014 */  sw    $s0, 0x14($sp)
/* 0F4BC8 7F0C0098 904A0001 */  lbu   $t2, 1($v0)
/* 0F4BCC 7F0C009C 3C0E8005 */  lui   $t6, %hi(ptr_active_demofile) 
/* 0F4BD0 7F0C00A0 8DCE8468 */  lw    $t6, %lo(ptr_active_demofile)($t6)
/* 0F4BD4 7F0C00A4 00A08025 */  move  $s0, $a1
/* 0F4BD8 7F0C00A8 00808825 */  move  $s1, $a0
/* 0F4BDC 7F0C00AC 00004025 */  move  $t0, $zero
/* 0F4BE0 7F0C00B0 00003825 */  move  $a3, $zero
/* 0F4BE4 7F0C00B4 19400041 */  blez  $t2, .L7F0C01BC
/* 0F4BE8 7F0C00B8 8DC60018 */   lw    $a2, 0x18($t6)
/* 0F4BEC 7F0C00BC 3C058005 */  lui   $a1, %hi(ramrom_blkbuf_3)
/* 0F4BF0 7F0C00C0 24A58470 */  addiu $a1, %lo(ramrom_blkbuf_3) # addiu $a1, $a1, -0x7b90
/* 0F4BF4 7F0C00C4 240B0014 */  li    $t3, 20
/* 0F4BF8 7F0C00C8 24090004 */  li    $t1, 4
/* 0F4BFC 7F0C00CC 260F0001 */  addiu $t7, $s0, 1
.L7F0C00D0:
/* 0F4C00 7F0C00D0 01EB001A */  div   $zero, $t7, $t3
/* 0F4C04 7F0C00D4 00008010 */  mfhi  $s0
/* 0F4C08 7F0C00D8 0010C080 */  sll   $t8, $s0, 2
/* 0F4C0C 7F0C00DC 0018C880 */  sll   $t9, $t8, 2
/* 0F4C10 7F0C00E0 0338C823 */  subu  $t9, $t9, $t8
/* 0F4C14 7F0C00E4 0019C840 */  sll   $t9, $t9, 1
/* 0F4C18 7F0C00E8 15600002 */  bnez  $t3, .L7F0C00F4
/* 0F4C1C 7F0C00EC 00000000 */   nop   
/* 0F4C20 7F0C00F0 0007000D */  break 7
.L7F0C00F4:
/* 0F4C24 7F0C00F4 2401FFFF */  li    $at, -1
/* 0F4C28 7F0C00F8 15610004 */  bne   $t3, $at, .L7F0C010C
/* 0F4C2C 7F0C00FC 3C018000 */   lui   $at, 0x8000
/* 0F4C30 7F0C0100 15E10002 */  bne   $t7, $at, .L7F0C010C
/* 0F4C34 7F0C0104 00000000 */   nop   
/* 0F4C38 7F0C0108 0006000D */  break 6
.L7F0C010C:
/* 0F4C3C 7F0C010C 02391821 */  addu  $v1, $s1, $t9
/* 0F4C40 7F0C0110 00002025 */  move  $a0, $zero
.L7F0C0114:
/* 0F4C44 7F0C0114 0086082A */  slt   $at, $a0, $a2
/* 0F4C48 7F0C0118 5020001E */  beql  $at, $zero, .L7F0C0194
/* 0F4C4C 7F0C011C A0600002 */   sb    $zero, 2($v1)
/* 0F4C50 7F0C0120 00E60019 */  multu $a3, $a2
/* 0F4C54 7F0C0124 8CAE0000 */  lw    $t6, ($a1)
/* 0F4C58 7F0C0128 0004C080 */  sll   $t8, $a0, 2
/* 0F4C5C 7F0C012C 00006012 */  mflo  $t4
/* 0F4C60 7F0C0130 000C6880 */  sll   $t5, $t4, 2
/* 0F4C64 7F0C0134 01AE7821 */  addu  $t7, $t5, $t6
/* 0F4C68 7F0C0138 01F81021 */  addu  $v0, $t7, $t8
/* 0F4C6C 7F0C013C 80590000 */  lb    $t9, ($v0)
/* 0F4C70 7F0C0140 A0790002 */  sb    $t9, 2($v1)
/* 0F4C74 7F0C0144 804C0001 */  lb    $t4, 1($v0)
/* 0F4C78 7F0C0148 A06C0003 */  sb    $t4, 3($v1)
/* 0F4C7C 7F0C014C 904D0003 */  lbu   $t5, 3($v0)
/* 0F4C80 7F0C0150 904F0002 */  lbu   $t7, 2($v0)
/* 0F4C84 7F0C0154 000D7200 */  sll   $t6, $t5, 8
/* 0F4C88 7F0C0158 01CFC025 */  or    $t8, $t6, $t7
/* 0F4C8C 7F0C015C A4780000 */  sh    $t8, ($v1)
/* 0F4C90 7F0C0160 904C0001 */  lbu   $t4, 1($v0)
/* 0F4C94 7F0C0164 90590000 */  lbu   $t9, ($v0)
/* 0F4C98 7F0C0168 904E0002 */  lbu   $t6, 2($v0)
/* 0F4C9C 7F0C016C 90580003 */  lbu   $t8, 3($v0)
/* 0F4CA0 7F0C0170 032C6821 */  addu  $t5, $t9, $t4
/* 0F4CA4 7F0C0174 01AE7821 */  addu  $t7, $t5, $t6
/* 0F4CA8 7F0C0178 01F8C821 */  addu  $t9, $t7, $t8
/* 0F4CAC 7F0C017C 332C00FF */  andi  $t4, $t9, 0xff
/* 0F4CB0 7F0C0180 010C4021 */  addu  $t0, $t0, $t4
/* 0F4CB4 7F0C0184 310D00FF */  andi  $t5, $t0, 0xff
/* 0F4CB8 7F0C0188 10000004 */  b     .L7F0C019C
/* 0F4CBC 7F0C018C 01A04025 */   move  $t0, $t5
/* 0F4CC0 7F0C0190 A0600002 */  sb    $zero, 2($v1)
.L7F0C0194:
/* 0F4CC4 7F0C0194 A0600003 */  sb    $zero, 3($v1)
/* 0F4CC8 7F0C0198 A4600000 */  sh    $zero, ($v1)
.L7F0C019C:
/* 0F4CCC 7F0C019C 24840001 */  addiu $a0, $a0, 1
/* 0F4CD0 7F0C01A0 1489FFDC */  bne   $a0, $t1, .L7F0C0114
/* 0F4CD4 7F0C01A4 24630006 */   addiu $v1, $v1, 6
/* 0F4CD8 7F0C01A8 24E70001 */  addiu $a3, $a3, 1
/* 0F4CDC 7F0C01AC 54EAFFC8 */  bnel  $a3, $t2, .L7F0C00D0
/* 0F4CE0 7F0C01B0 260F0001 */   addiu $t7, $s0, 1
/* 0F4CE4 7F0C01B4 3C028005 */  lui   $v0, %hi(ramrom_blkbuf_2)
/* 0F4CE8 7F0C01B8 8C42846C */  lw    $v0, %lo(ramrom_blkbuf_2)($v0)
.L7F0C01BC:
/* 0F4CEC 7F0C01BC 3C0F8002 */  lui   $t7, %hi(randseed + 0x4) 
/* 0F4CF0 7F0C01C0 8DEF4464 */  lw    $t7, %lo(randseed + 0x4)($t7)
/* 0F4CF4 7F0C01C4 90430002 */  lbu   $v1, 2($v0)
/* 0F4CF8 7F0C01C8 31F900FF */  andi  $t9, $t7, 0xff
/* 0F4CFC 7F0C01CC 53230008 */  beql  $t9, $v1, .L7F0C01F0
/* 0F4D00 7F0C01D0 904C0000 */   lbu   $t4, ($v0)
/* 0F4D04 7F0C01D4 0FC30232 */  jal   ensureCameraModeA
/* 0F4D08 7F0C01D8 A3A80023 */   sb    $t0, 0x23($sp)
/* 0F4D0C 7F0C01DC 3C028005 */  lui   $v0, %hi(ramrom_blkbuf_2)
/* 0F4D10 7F0C01E0 8C42846C */  lw    $v0, %lo(ramrom_blkbuf_2)($v0)
/* 0F4D14 7F0C01E4 93A80023 */  lbu   $t0, 0x23($sp)
/* 0F4D18 7F0C01E8 90430002 */  lbu   $v1, 2($v0)
/* 0F4D1C 7F0C01EC 904C0000 */  lbu   $t4, ($v0)
.L7F0C01F0:
/* 0F4D20 7F0C01F0 904D0001 */  lbu   $t5, 1($v0)
/* 0F4D24 7F0C01F4 018D7021 */  addu  $t6, $t4, $t5
/* 0F4D28 7F0C01F8 904C0003 */  lbu   $t4, 3($v0)
/* 0F4D2C 7F0C01FC 01C3C021 */  addu  $t8, $t6, $v1
/* 0F4D30 7F0C0200 01184021 */  addu  $t0, $t0, $t8
/* 0F4D34 7F0C0204 311900FF */  andi  $t9, $t0, 0xff
/* 0F4D38 7F0C0208 132C0003 */  beq   $t9, $t4, .L7F0C0218
/* 0F4D3C 7F0C020C 00000000 */   nop   
/* 0F4D40 7F0C0210 0FC30232 */  jal   ensureCameraModeA
/* 0F4D44 7F0C0214 00000000 */   nop   
.L7F0C0218:
/* 0F4D48 7F0C0218 0C00324C */  jal   controller_7000C930
/* 0F4D4C 7F0C021C 00002025 */   move  $a0, $zero
/* 0F4D50 7F0C0220 00002025 */  move  $a0, $zero
/* 0F4D54 7F0C0224 0C0030EB */  jal   get_controller_buttons_pressed
/* 0F4D58 7F0C0228 3405FFFF */   li    $a1, 65535
/* 0F4D5C 7F0C022C 10400006 */  beqz  $v0, .L7F0C0248
/* 0F4D60 7F0C0230 00000000 */   nop   
/* 0F4D64 7F0C0234 0FC30232 */  jal   ensureCameraModeA
/* 0F4D68 7F0C0238 00000000 */   nop   
/* 0F4D6C 7F0C023C 240D0001 */  li    $t5, 1
/* 0F4D70 7F0C0240 3C018003 */  lui   $at, %hi(prev_keypresses)
/* 0F4D74 7F0C0244 AC2DA934 */  sw    $t5, %lo(prev_keypresses)($at)
.L7F0C0248:
/* 0F4D78 7F0C0248 0C00324C */  jal   controller_7000C930
/* 0F4D7C 7F0C024C 24040001 */   li    $a0, 1
/* 0F4D80 7F0C0250 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F4D84 7F0C0254 02001025 */  move  $v0, $s0
/* 0F4D88 7F0C0258 8FB00014 */  lw    $s0, 0x14($sp)
/* 0F4D8C 7F0C025C 8FB10018 */  lw    $s1, 0x18($sp)
/* 0F4D90 7F0C0260 03E00008 */  jr    $ra
/* 0F4D94 7F0C0264 27BD0038 */   addiu $sp, $sp, 0x38
)
#endif





#ifdef NONMATCHING
s32 iterate_ramrom_entries_handle_camera_out(void) {
    ? temp_ret;
    s32 temp_a3;
    s32 temp_v1;
    s32 phi_a0;
    void *phi_v1;
    s32 phi_a3;
    void *phi_v1_2;
    s32 phi_return;

    // Node 0
    temp_ret = romCopyAligned(&ramrom_data_target + 0x1F8, address_demo_loaded, 4);
    ramrom_blkbuf_2 = temp_ret;
    temp_a3 = temp_ret->unk1;
    phi_a0 = temp_a3;
    phi_v1 = temp_ret;
    phi_a3 = temp_a3;
    if (temp_a3 > 0)
    {
        // Node 1
        ramrom_blkbuf_3 = romCopyAligned(&ramrom_data_target + 0x21E, (address_demo_loaded + 4), ((ptr_active_demofile->unk18 * 4) * temp_a3), temp_a3);
        phi_a0 = ramrom_blkbuf_2->unk1;
        phi_v1 = (void *) ramrom_blkbuf_2;
        phi_a3 = ramrom_blkbuf_2->unk1;
    }
    // Node 2
    if ((phi_a0 == 0) && (*phi_v1 == 0))
    {
        // Node 4
        ensureCameraModeA(phi_a0, phi_a3);
        phi_v1_2 = (void *) ramrom_blkbuf_2;
    }
    else
    {
        // Node 5
        address_demo_loaded = (s32) (address_demo_loaded + (((((ptr_active_demofile->unk18 * 4) * phi_a3) + 5) | 1) ^ 1));
        phi_v1_2 = phi_v1;
    }
    // Node 6
    sub_GAME_7F0C0AA0(*phi_v1_2);
    temp_v1 = (ptr_active_demofile->unk7C + -0x3c);
    phi_return = global_timer;
    if (global_timer >= temp_v1)
    {
        // Node 7
        phi_return = global_timer;
        if ((global_timer - clock_timer) < temp_v1)
        {
            // Node 8
            phi_return = ensureCameraModeA();
        }
    }
    // Node 9
    return phi_return;
}

#else
GLOBAL_ASM(
.text
glabel iterate_ramrom_entries_handle_camera_out
/* 0F4D98 7F0C0268 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F4D9C 7F0C026C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F4DA0 7F0C0270 3C048009 */  lui   $a0, %hi(ramrom_data_target + 0x1F8)
/* 0F4DA4 7F0C0274 3C058009 */  lui   $a1, %hi(address_demo_loaded)
/* 0F4DA8 7F0C0278 8CA5C5F4 */  lw    $a1, %lo(address_demo_loaded)($a1)
/* 0F4DAC 7F0C027C 2484C468 */  addiu $a0, %lo(ramrom_data_target + 0x1F8) # addiu $a0, $a0, -0x3b98
/* 0F4DB0 7F0C0280 0C001711 */  jal   romCopyAligned
/* 0F4DB4 7F0C0284 24060004 */   li    $a2, 4
/* 0F4DB8 7F0C0288 3C058005 */  lui   $a1, %hi(ramrom_blkbuf_2)
/* 0F4DBC 7F0C028C 24A5846C */  addiu $a1, %lo(ramrom_blkbuf_2) # addiu $a1, $a1, -0x7b94
/* 0F4DC0 7F0C0290 ACA20000 */  sw    $v0, ($a1)
/* 0F4DC4 7F0C0294 90470001 */  lbu   $a3, 1($v0)
/* 0F4DC8 7F0C0298 00401825 */  move  $v1, $v0
/* 0F4DCC 7F0C029C 3C0E8005 */  lui   $t6, %hi(ptr_active_demofile) 
/* 0F4DD0 7F0C02A0 18E00013 */  blez  $a3, .L7F0C02F0
/* 0F4DD4 7F0C02A4 00E02025 */   move  $a0, $a3
/* 0F4DD8 7F0C02A8 8DCE8468 */  lw    $t6, %lo(ptr_active_demofile)($t6)
/* 0F4DDC 7F0C02AC 3C058009 */  lui   $a1, %hi(address_demo_loaded)
/* 0F4DE0 7F0C02B0 8CA5C5F4 */  lw    $a1, %lo(address_demo_loaded)($a1)
/* 0F4DE4 7F0C02B4 8DCF0018 */  lw    $t7, 0x18($t6)
/* 0F4DE8 7F0C02B8 3C048009 */  lui   $a0, %hi(ramrom_data_target + 0x21E)
/* 0F4DEC 7F0C02BC 2484C48E */  addiu $a0, %lo(ramrom_data_target + 0x21E) # addiu $a0, $a0, -0x3b72
/* 0F4DF0 7F0C02C0 000FC080 */  sll   $t8, $t7, 2
/* 0F4DF4 7F0C02C4 03070019 */  multu $t8, $a3
/* 0F4DF8 7F0C02C8 24A50004 */  addiu $a1, $a1, 4
/* 0F4DFC 7F0C02CC 00003012 */  mflo  $a2
/* 0F4E00 7F0C02D0 0C001711 */  jal   romCopyAligned
/* 0F4E04 7F0C02D4 00000000 */   nop   
/* 0F4E08 7F0C02D8 3C038005 */  lui   $v1, %hi(ramrom_blkbuf_2)
/* 0F4E0C 7F0C02DC 8C63846C */  lw    $v1, %lo(ramrom_blkbuf_2)($v1)
/* 0F4E10 7F0C02E0 3C018005 */  lui   $at, %hi(ramrom_blkbuf_3)
/* 0F4E14 7F0C02E4 AC228470 */  sw    $v0, %lo(ramrom_blkbuf_3)($at)
/* 0F4E18 7F0C02E8 90670001 */  lbu   $a3, 1($v1)
/* 0F4E1C 7F0C02EC 00E02025 */  move  $a0, $a3
.L7F0C02F0:
/* 0F4E20 7F0C02F0 14800009 */  bnez  $a0, .L7F0C0318
/* 0F4E24 7F0C02F4 3C098005 */   lui   $t1, %hi(ptr_active_demofile) 
/* 0F4E28 7F0C02F8 90790000 */  lbu   $t9, ($v1)
/* 0F4E2C 7F0C02FC 17200006 */  bnez  $t9, .L7F0C0318
/* 0F4E30 7F0C0300 00000000 */   nop   
/* 0F4E34 7F0C0304 0FC30232 */  jal   ensureCameraModeA
/* 0F4E38 7F0C0308 00000000 */   nop   
/* 0F4E3C 7F0C030C 3C038005 */  lui   $v1, %hi(ramrom_blkbuf_2)
/* 0F4E40 7F0C0310 1000000E */  b     .L7F0C034C
/* 0F4E44 7F0C0314 8C63846C */   lw    $v1, %lo(ramrom_blkbuf_2)($v1)
.L7F0C0318:
/* 0F4E48 7F0C0318 8D298468 */  lw    $t1, %lo(ptr_active_demofile)($t1)
/* 0F4E4C 7F0C031C 3C088009 */  lui   $t0, %hi(address_demo_loaded) 
/* 0F4E50 7F0C0320 8D08C5F4 */  lw    $t0, %lo(address_demo_loaded)($t0)
/* 0F4E54 7F0C0324 8D2A0018 */  lw    $t2, 0x18($t1)
/* 0F4E58 7F0C0328 3C018009 */  lui   $at, %hi(address_demo_loaded)
/* 0F4E5C 7F0C032C 000A5880 */  sll   $t3, $t2, 2
/* 0F4E60 7F0C0330 01670019 */  multu $t3, $a3
/* 0F4E64 7F0C0334 00006012 */  mflo  $t4
/* 0F4E68 7F0C0338 258D0005 */  addiu $t5, $t4, 5
/* 0F4E6C 7F0C033C 35AE0001 */  ori   $t6, $t5, 1
/* 0F4E70 7F0C0340 39CF0001 */  xori  $t7, $t6, 1
/* 0F4E74 7F0C0344 010FC021 */  addu  $t8, $t0, $t7
/* 0F4E78 7F0C0348 AC38C5F4 */  sw    $t8, %lo(address_demo_loaded)($at)
.L7F0C034C:
/* 0F4E7C 7F0C034C 0FC302A8 */  jal   sub_GAME_7F0C0AA0
/* 0F4E80 7F0C0350 90640000 */   lbu   $a0, ($v1)
/* 0F4E84 7F0C0354 3C198005 */  lui   $t9, %hi(ptr_active_demofile) 
/* 0F4E88 7F0C0358 8F398468 */  lw    $t9, %lo(ptr_active_demofile)($t9)
/* 0F4E8C 7F0C035C 3C028005 */  lui   $v0, %hi(global_timer)
/* 0F4E90 7F0C0360 8C42837C */  lw    $v0, %lo(global_timer)($v0)
/* 0F4E94 7F0C0364 8F23007C */  lw    $v1, 0x7c($t9)
/* 0F4E98 7F0C0368 3C098005 */  lui   $t1, %hi(clock_timer) 
/* 0F4E9C 7F0C036C 2463FFC4 */  addiu $v1, $v1, -0x3c
/* 0F4EA0 7F0C0370 0043082A */  slt   $at, $v0, $v1
/* 0F4EA4 7F0C0374 54200009 */  bnezl $at, .L7F0C039C
/* 0F4EA8 7F0C0378 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4EAC 7F0C037C 8D298374 */  lw    $t1, %lo(clock_timer)($t1)
/* 0F4EB0 7F0C0380 00495023 */  subu  $t2, $v0, $t1
/* 0F4EB4 7F0C0384 0143082A */  slt   $at, $t2, $v1
/* 0F4EB8 7F0C0388 50200004 */  beql  $at, $zero, .L7F0C039C
/* 0F4EBC 7F0C038C 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F4EC0 7F0C0390 0FC30232 */  jal   ensureCameraModeA
/* 0F4EC4 7F0C0394 00000000 */   nop   
/* 0F4EC8 7F0C0398 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C039C:
/* 0F4ECC 7F0C039C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F4ED0 7F0C03A0 03E00008 */  jr    $ra
/* 0F4ED4 7F0C03A4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void copy_current_ingame_registers_before_ramrom_playback(void *arg0) {
    ? temp_ret;

    // Node 0
    arg0->unk4 = (?32) randseed + 0x4;
    *arg0 = (?32) randseed;
    arg0->unkC = (?32) random_val + 0x4;
    arg0->unk8 = (?32) random_val;
    arg0->unk84 = (?32) gamemode;
    arg0->unk8C = (?32) selected_num_players;
    arg0->unk90 = (?32) scenario;
    arg0->unk94 = (?32) MP_stage_selected;
    arg0->unk98 = (?32) game_length;
    arg0->unk9C = get_mp_weapon_set();
    arg0->unkA0 = (?32) player_1_char;
    arg0->unkA4 = (?32) player_1_char.unk4;
    arg0->unkA8 = (?32) player_1_char.unk8;
    arg0->unkAC = (?32) player_1_char.unkC;
    arg0->unkB0 = (?32) handicap_player1;
    arg0->unkB4 = (?32) handicap_player1.unk4;
    arg0->unkB8 = (?32) handicap_player1.unk8;
    arg0->unkBC = (?32) handicap_player1.unkC;
    arg0->unkC0 = (?32) controlstyle_player;
    arg0->unkC4 = (?32) controlstyle_player.unk4;
    arg0->unkC8 = (?32) controlstyle_player.unk8;
    arg0->unkCC = (?32) controlstyle_player.unkC;
    arg0->unkD0 = (?32) aim_sight_adjustment;
    arg0->unkD4 = get_players_team_or_scenario_item_flag(0);
    arg0->unkD8 = get_players_team_or_scenario_item_flag(1);
    arg0->unkDC = get_players_team_or_scenario_item_flag(2);
    arg0->unkE0 = get_players_team_or_scenario_item_flag(3);
}

#else
GLOBAL_ASM(
.text
glabel copy_current_ingame_registers_before_ramrom_playback
/* 0F4ED8 7F0C03A8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F4EDC 7F0C03AC 3C0E8002 */  lui   $t6, %hi(randseed) 
/* 0F4EE0 7F0C03B0 3C0F8002 */  lui   $t7, %hi(randseed + 0x4) 
/* 0F4EE4 7F0C03B4 8DEF4464 */  lw    $t7, %lo(randseed + 0x4)($t7)
/* 0F4EE8 7F0C03B8 8DCE4460 */  lw    $t6, %lo(randseed)($t6)
/* 0F4EEC 7F0C03BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F4EF0 7F0C03C0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F4EF4 7F0C03C4 AC8F0004 */  sw    $t7, 4($a0)
/* 0F4EF8 7F0C03C8 AC8E0000 */  sw    $t6, ($a0)
/* 0F4EFC 7F0C03CC 3C188004 */  lui   $t8, %hi(random_val) 
/* 0F4F00 7F0C03D0 3C198004 */  lui   $t9, %hi(random_val + 0x4) 
/* 0F4F04 7F0C03D4 8F390164 */  lw    $t9, %lo(random_val + 0x4)($t9)
/* 0F4F08 7F0C03D8 8F180160 */  lw    $t8, %lo(random_val)($t8)
/* 0F4F0C 7F0C03DC 3C088003 */  lui   $t0, %hi(gamemode) 
/* 0F4F10 7F0C03E0 AC99000C */  sw    $t9, 0xc($a0)
/* 0F4F14 7F0C03E4 AC980008 */  sw    $t8, 8($a0)
/* 0F4F18 7F0C03E8 8D08A8F0 */  lw    $t0, %lo(gamemode)($t0)
/* 0F4F1C 7F0C03EC 3C098003 */  lui   $t1, %hi(selected_num_players) 
/* 0F4F20 7F0C03F0 3C0A8003 */  lui   $t2, %hi(scenario) 
/* 0F4F24 7F0C03F4 AC880084 */  sw    $t0, 0x84($a0)
/* 0F4F28 7F0C03F8 8D29B520 */  lw    $t1, %lo(selected_num_players)($t1)
/* 0F4F2C 7F0C03FC 3C0B8003 */  lui   $t3, %hi(MP_stage_selected) 
/* 0F4F30 7F0C0400 3C0C8003 */  lui   $t4, %hi(game_length) 
/* 0F4F34 7F0C0404 AC89008C */  sw    $t1, 0x8c($a0)
/* 0F4F38 7F0C0408 8D4AB540 */  lw    $t2, %lo(scenario)($t2)
/* 0F4F3C 7F0C040C 00808025 */  move  $s0, $a0
/* 0F4F40 7F0C0410 AC8A0090 */  sw    $t2, 0x90($a0)
/* 0F4F44 7F0C0414 8D6BB534 */  lw    $t3, %lo(MP_stage_selected)($t3)
/* 0F4F48 7F0C0418 AC8B0094 */  sw    $t3, 0x94($a0)
/* 0F4F4C 7F0C041C 8D8CB538 */  lw    $t4, %lo(game_length)($t4)
/* 0F4F50 7F0C0420 0FC3198F */  jal   get_mp_weapon_set
/* 0F4F54 7F0C0424 AC8C0098 */   sw    $t4, 0x98($a0)
/* 0F4F58 7F0C0428 3C038003 */  lui   $v1, %hi(player_1_char)
/* 0F4F5C 7F0C042C 2463B524 */  addiu $v1, %lo(player_1_char) # addiu $v1, $v1, -0x4adc
/* 0F4F60 7F0C0430 AE02009C */  sw    $v0, 0x9c($s0)
/* 0F4F64 7F0C0434 8C6D0000 */  lw    $t5, ($v1)
/* 0F4F68 7F0C0438 3C058007 */  lui   $a1, %hi(handicap_player1)
/* 0F4F6C 7F0C043C 24A597A8 */  addiu $a1, %lo(handicap_player1) # addiu $a1, $a1, -0x6858
/* 0F4F70 7F0C0440 AE0D00A0 */  sw    $t5, 0xa0($s0)
/* 0F4F74 7F0C0444 8C6E0004 */  lw    $t6, 4($v1)
/* 0F4F78 7F0C0448 3C068007 */  lui   $a2, %hi(controlstyle_player)
/* 0F4F7C 7F0C044C 24C697B8 */  addiu $a2, %lo(controlstyle_player) # addiu $a2, $a2, -0x6848
/* 0F4F80 7F0C0450 AE0E00A4 */  sw    $t6, 0xa4($s0)
/* 0F4F84 7F0C0454 8C6F0008 */  lw    $t7, 8($v1)
/* 0F4F88 7F0C0458 00002025 */  move  $a0, $zero
/* 0F4F8C 7F0C045C AE0F00A8 */  sw    $t7, 0xa8($s0)
/* 0F4F90 7F0C0460 8C78000C */  lw    $t8, 0xc($v1)
/* 0F4F94 7F0C0464 3C0F8003 */  lui   $t7, %hi(aim_sight_adjustment) 
/* 0F4F98 7F0C0468 AE1800AC */  sw    $t8, 0xac($s0)
/* 0F4F9C 7F0C046C 8CB90000 */  lw    $t9, ($a1)
/* 0F4FA0 7F0C0470 AE1900B0 */  sw    $t9, 0xb0($s0)
/* 0F4FA4 7F0C0474 8CA80004 */  lw    $t0, 4($a1)
/* 0F4FA8 7F0C0478 AE0800B4 */  sw    $t0, 0xb4($s0)
/* 0F4FAC 7F0C047C 8CA90008 */  lw    $t1, 8($a1)
/* 0F4FB0 7F0C0480 AE0900B8 */  sw    $t1, 0xb8($s0)
/* 0F4FB4 7F0C0484 8CAA000C */  lw    $t2, 0xc($a1)
/* 0F4FB8 7F0C0488 AE0A00BC */  sw    $t2, 0xbc($s0)
/* 0F4FBC 7F0C048C 8CCB0000 */  lw    $t3, ($a2)
/* 0F4FC0 7F0C0490 AE0B00C0 */  sw    $t3, 0xc0($s0)
/* 0F4FC4 7F0C0494 8CCC0004 */  lw    $t4, 4($a2)
/* 0F4FC8 7F0C0498 AE0C00C4 */  sw    $t4, 0xc4($s0)
/* 0F4FCC 7F0C049C 8CCD0008 */  lw    $t5, 8($a2)
/* 0F4FD0 7F0C04A0 AE0D00C8 */  sw    $t5, 0xc8($s0)
/* 0F4FD4 7F0C04A4 8CCE000C */  lw    $t6, 0xc($a2)
/* 0F4FD8 7F0C04A8 AE0E00CC */  sw    $t6, 0xcc($s0)
/* 0F4FDC 7F0C04AC 8DEFB53C */  lw    $t7, %lo(aim_sight_adjustment)($t7)
/* 0F4FE0 7F0C04B0 0FC05322 */  jal   get_players_team_or_scenario_item_flag
/* 0F4FE4 7F0C04B4 AE0F00D0 */   sw    $t7, 0xd0($s0)
/* 0F4FE8 7F0C04B8 AE0200D4 */  sw    $v0, 0xd4($s0)
/* 0F4FEC 7F0C04BC 0FC05322 */  jal   get_players_team_or_scenario_item_flag
/* 0F4FF0 7F0C04C0 24040001 */   li    $a0, 1
/* 0F4FF4 7F0C04C4 AE0200D8 */  sw    $v0, 0xd8($s0)
/* 0F4FF8 7F0C04C8 0FC05322 */  jal   get_players_team_or_scenario_item_flag
/* 0F4FFC 7F0C04CC 24040002 */   li    $a0, 2
/* 0F5000 7F0C04D0 AE0200DC */  sw    $v0, 0xdc($s0)
/* 0F5004 7F0C04D4 0FC05322 */  jal   get_players_team_or_scenario_item_flag
/* 0F5008 7F0C04D8 24040003 */   li    $a0, 3
/* 0F500C 7F0C04DC AE0200E0 */  sw    $v0, 0xe0($s0)
/* 0F5010 7F0C04E0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F5014 7F0C04E4 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F5018 7F0C04E8 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F501C 7F0C04EC 03E00008 */  jr    $ra
/* 0F5020 7F0C04F0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void copy_recorded_ramrom_registers_to_proper_place_ingame(void *arg0) {
    // Node 0
    randseed = (?32) *arg0;
    randseed + 0x4 = (?32) arg0->unk4;
    random_val = (?32) arg0->unk8;
    random_val + 0x4 = (?32) arg0->unkC;
    gamemode = (?32) arg0->unk84;
    selected_num_players = (?32) arg0->unk8C;
    scenario = (?32) arg0->unk90;
    MP_stage_selected = (?32) arg0->unk94;
    game_length = (?32) arg0->unk98;
    set_mp_weapon_set(arg0->unk9C);
    player_1_char = (?32) arg0->unkA0;
    player_1_char.unk4 = (?32) arg0->unkA4;
    player_1_char.unk8 = (?32) arg0->unkA8;
    player_1_char.unkC = (?32) arg0->unkAC;
    handicap_player1 = (?32) arg0->unkB0;
    handicap_player1.unk4 = (?32) arg0->unkB4;
    handicap_player1.unk8 = (?32) arg0->unkB8;
    handicap_player1.unkC = (?32) arg0->unkBC;
    controlstyle_player = (?32) arg0->unkC0;
    controlstyle_player.unk4 = (?32) arg0->unkC4;
    controlstyle_player.unk8 = (?32) arg0->unkC8;
    controlstyle_player.unkC = (?32) arg0->unkCC;
    aim_sight_adjustment = (?32) arg0->unkD0;
    set_players_team_or_scenario_item_flag(0, arg0->unkD4, &controlstyle_player);
    set_players_team_or_scenario_item_flag(1, arg0->unkD8);
    set_players_team_or_scenario_item_flag(2, arg0->unkDC);
    return set_players_team_or_scenario_item_flag(3, arg0->unkE0);
}
#else
GLOBAL_ASM(
.text
glabel copy_recorded_ramrom_registers_to_proper_place_ingame
/* 0F5024 7F0C04F4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F5028 7F0C04F8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F502C 7F0C04FC AFB00018 */  sw    $s0, 0x18($sp)
/* 0F5030 7F0C0500 8C8E0000 */  lw    $t6, ($a0)
/* 0F5034 7F0C0504 8C8F0004 */  lw    $t7, 4($a0)
/* 0F5038 7F0C0508 3C018002 */  lui   $at, %hi(randseed)
/* 0F503C 7F0C050C AC2E4460 */  sw    $t6, %lo(randseed)($at)
/* 0F5040 7F0C0510 3C018002 */  lui   $at, %hi(randseed + 0x4)
/* 0F5044 7F0C0514 AC2F4464 */  sw    $t7, %lo(randseed + 0x4)($at)
/* 0F5048 7F0C0518 8C980008 */  lw    $t8, 8($a0)
/* 0F504C 7F0C051C 8C99000C */  lw    $t9, 0xc($a0)
/* 0F5050 7F0C0520 3C018004 */  lui   $at, %hi(random_val)
/* 0F5054 7F0C0524 AC380160 */  sw    $t8, %lo(random_val)($at)
/* 0F5058 7F0C0528 3C018004 */  lui   $at, %hi(random_val + 0x4)
/* 0F505C 7F0C052C AC390164 */  sw    $t9, %lo(random_val + 0x4)($at)
/* 0F5060 7F0C0530 8C880084 */  lw    $t0, 0x84($a0)
/* 0F5064 7F0C0534 3C018003 */  lui   $at, %hi(gamemode)
/* 0F5068 7F0C0538 00808025 */  move  $s0, $a0
/* 0F506C 7F0C053C AC28A8F0 */  sw    $t0, %lo(gamemode)($at)
/* 0F5070 7F0C0540 8C89008C */  lw    $t1, 0x8c($a0)
/* 0F5074 7F0C0544 3C018003 */  lui   $at, %hi(selected_num_players)
/* 0F5078 7F0C0548 AC29B520 */  sw    $t1, %lo(selected_num_players)($at)
/* 0F507C 7F0C054C 8C8A0090 */  lw    $t2, 0x90($a0)
/* 0F5080 7F0C0550 3C018003 */  lui   $at, %hi(scenario)
/* 0F5084 7F0C0554 AC2AB540 */  sw    $t2, %lo(scenario)($at)
/* 0F5088 7F0C0558 8C8B0094 */  lw    $t3, 0x94($a0)
/* 0F508C 7F0C055C 3C018003 */  lui   $at, %hi(MP_stage_selected)
/* 0F5090 7F0C0560 AC2BB534 */  sw    $t3, %lo(MP_stage_selected)($at)
/* 0F5094 7F0C0564 8C8C0098 */  lw    $t4, 0x98($a0)
/* 0F5098 7F0C0568 3C018003 */  lui   $at, %hi(game_length)
/* 0F509C 7F0C056C AC2CB538 */  sw    $t4, %lo(game_length)($at)
/* 0F50A0 7F0C0570 0FC3198C */  jal   set_mp_weapon_set
/* 0F50A4 7F0C0574 8C84009C */   lw    $a0, 0x9c($a0)
/* 0F50A8 7F0C0578 8E0D00A0 */  lw    $t5, 0xa0($s0)
/* 0F50AC 7F0C057C 3C028003 */  lui   $v0, %hi(player_1_char)
/* 0F50B0 7F0C0580 2442B524 */  addiu $v0, %lo(player_1_char) # addiu $v0, $v0, -0x4adc
/* 0F50B4 7F0C0584 AC4D0000 */  sw    $t5, ($v0)
/* 0F50B8 7F0C0588 8E0E00A4 */  lw    $t6, 0xa4($s0)
/* 0F50BC 7F0C058C 3C038007 */  lui   $v1, %hi(handicap_player1)
/* 0F50C0 7F0C0590 246397A8 */  addiu $v1, %lo(handicap_player1) # addiu $v1, $v1, -0x6858
/* 0F50C4 7F0C0594 AC4E0004 */  sw    $t6, 4($v0)
/* 0F50C8 7F0C0598 8E0F00A8 */  lw    $t7, 0xa8($s0)
/* 0F50CC 7F0C059C 3C068007 */  lui   $a2, %hi(controlstyle_player)
/* 0F50D0 7F0C05A0 24C697B8 */  addiu $a2, %lo(controlstyle_player) # addiu $a2, $a2, -0x6848
/* 0F50D4 7F0C05A4 AC4F0008 */  sw    $t7, 8($v0)
/* 0F50D8 7F0C05A8 8E1800AC */  lw    $t8, 0xac($s0)
/* 0F50DC 7F0C05AC 3C018003 */  lui   $at, %hi(aim_sight_adjustment)
/* 0F50E0 7F0C05B0 00002025 */  move  $a0, $zero
/* 0F50E4 7F0C05B4 AC58000C */  sw    $t8, 0xc($v0)
/* 0F50E8 7F0C05B8 8E1900B0 */  lw    $t9, 0xb0($s0)
/* 0F50EC 7F0C05BC AC790000 */  sw    $t9, ($v1)
/* 0F50F0 7F0C05C0 8E0800B4 */  lw    $t0, 0xb4($s0)
/* 0F50F4 7F0C05C4 AC680004 */  sw    $t0, 4($v1)
/* 0F50F8 7F0C05C8 8E0900B8 */  lw    $t1, 0xb8($s0)
/* 0F50FC 7F0C05CC AC690008 */  sw    $t1, 8($v1)
/* 0F5100 7F0C05D0 8E0A00BC */  lw    $t2, 0xbc($s0)
/* 0F5104 7F0C05D4 AC6A000C */  sw    $t2, 0xc($v1)
/* 0F5108 7F0C05D8 8E0B00C0 */  lw    $t3, 0xc0($s0)
/* 0F510C 7F0C05DC ACCB0000 */  sw    $t3, ($a2)
/* 0F5110 7F0C05E0 8E0C00C4 */  lw    $t4, 0xc4($s0)
/* 0F5114 7F0C05E4 ACCC0004 */  sw    $t4, 4($a2)
/* 0F5118 7F0C05E8 8E0D00C8 */  lw    $t5, 0xc8($s0)
/* 0F511C 7F0C05EC ACCD0008 */  sw    $t5, 8($a2)
/* 0F5120 7F0C05F0 8E0E00CC */  lw    $t6, 0xcc($s0)
/* 0F5124 7F0C05F4 ACCE000C */  sw    $t6, 0xc($a2)
/* 0F5128 7F0C05F8 8E0F00D0 */  lw    $t7, 0xd0($s0)
/* 0F512C 7F0C05FC AC2FB53C */  sw    $t7, %lo(aim_sight_adjustment)($at)
/* 0F5130 7F0C0600 0FC05329 */  jal   set_players_team_or_scenario_item_flag
/* 0F5134 7F0C0604 8E0500D4 */   lw    $a1, 0xd4($s0)
/* 0F5138 7F0C0608 24040001 */  li    $a0, 1
/* 0F513C 7F0C060C 0FC05329 */  jal   set_players_team_or_scenario_item_flag
/* 0F5140 7F0C0610 8E0500D8 */   lw    $a1, 0xd8($s0)
/* 0F5144 7F0C0614 24040002 */  li    $a0, 2
/* 0F5148 7F0C0618 0FC05329 */  jal   set_players_team_or_scenario_item_flag
/* 0F514C 7F0C061C 8E0500DC */   lw    $a1, 0xdc($s0)
/* 0F5150 7F0C0620 24040003 */  li    $a0, 3
/* 0F5154 7F0C0624 0FC05329 */  jal   set_players_team_or_scenario_item_flag
/* 0F5158 7F0C0628 8E0500E0 */   lw    $a1, 0xe0($s0)
/* 0F515C 7F0C062C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F5160 7F0C0630 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F5164 7F0C0634 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F5168 7F0C0638 03E00008 */  jr    $ra
/* 0F516C 7F0C063C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void test_if_recording_demos_this_stage_load(void) {

}
#else
GLOBAL_ASM(
.text
glabel test_if_recording_demos_this_stage_load
/* 0F5170 7F0C0640 3C0E8005 */  lui   $t6, %hi(flag_to_record_ramrom) 
/* 0F5174 7F0C0644 8DCE8488 */  lw    $t6, %lo(flag_to_record_ramrom)($t6)
/* 0F5178 7F0C0648 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F517C 7F0C064C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F5180 7F0C0650 11C00032 */  beqz  $t6, .L7F0C071C
/* 0F5184 7F0C0654 AFB00018 */   sw    $s0, 0x18($sp)
/* 0F5188 7F0C0658 3C0F8009 */  lui   $t7, %hi(ramrom_data_target) 
/* 0F518C 7F0C065C 25EFC270 */  addiu $t7, %lo(ramrom_data_target) # addiu $t7, $t7, -0x3d90
/* 0F5190 7F0C0660 25F8000F */  addiu $t8, $t7, 0xf
/* 0F5194 7F0C0664 3C108005 */  lui   $s0, %hi(ptr_active_demofile)
/* 0F5198 7F0C0668 3719000F */  ori   $t9, $t8, 0xf
/* 0F519C 7F0C066C 26108468 */  addiu $s0, %lo(ptr_active_demofile) # addiu $s0, $s0, -0x7b98
/* 0F51A0 7F0C0670 3B28000F */  xori  $t0, $t9, 0xf
/* 0F51A4 7F0C0674 AE080000 */  sw    $t0, ($s0)
/* 0F51A8 7F0C0678 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C5F8)
/* 0F51AC 7F0C067C AC20C5F8 */  sw    $zero, %lo(dword_CODE_bss_8008C5F8)($at)
/* 0F51B0 7F0C0680 8E090000 */  lw    $t1, ($s0)
/* 0F51B4 7F0C0684 AD240010 */  sw    $a0, 0x10($t1)
/* 0F51B8 7F0C0688 8E0A0000 */  lw    $t2, ($s0)
/* 0F51BC 7F0C068C 0C002E7E */  jal   get_attached_controller_count
/* 0F51C0 7F0C0690 AD450014 */   sw    $a1, 0x14($t2)
/* 0F51C4 7F0C0694 8E0B0000 */  lw    $t3, ($s0)
/* 0F51C8 7F0C0698 3C0C8009 */  lui   $t4, %hi(record_slot_num) 
/* 0F51CC 7F0C069C AD620018 */  sw    $v0, 0x18($t3)
/* 0F51D0 7F0C06A0 8E0D0000 */  lw    $t5, ($s0)
/* 0F51D4 7F0C06A4 8D8CC5F0 */  lw    $t4, %lo(record_slot_num)($t4)
/* 0F51D8 7F0C06A8 ADAC0088 */  sw    $t4, 0x88($t5)
/* 0F51DC 7F0C06AC 8E040000 */  lw    $a0, ($s0)
/* 0F51E0 7F0C06B0 0FC07587 */  jal   sub_GAME_7F01D61C
/* 0F51E4 7F0C06B4 2484001C */   addiu $a0, $a0, 0x1c
/* 0F51E8 7F0C06B8 0FC300EA */  jal   copy_current_ingame_registers_before_ramrom_playback
/* 0F51EC 7F0C06BC 8E040000 */   lw    $a0, ($s0)
/* 0F51F0 7F0C06C0 24020001 */  li    $v0, 1
/* 0F51F4 7F0C06C4 3C018005 */  lui   $at, %hi(recording_ramrom_flag)
/* 0F51F8 7F0C06C8 AC228480 */  sw    $v0, %lo(recording_ramrom_flag)($at)
/* 0F51FC 7F0C06CC 3C018005 */  lui   $at, %hi(ramrom_demo_related_6)
/* 0F5200 7F0C06D0 3C047F0C */  lui   $a0, %hi(record_player_input_as_packet) # $a0, 0x7f0c
/* 0F5204 7F0C06D4 AC228484 */  sw    $v0, %lo(ramrom_demo_related_6)($at)
/* 0F5208 7F0C06D8 0C002EEF */  jal   set_ptr_tlb_ramrom_record
/* 0F520C 7F0C06DC 2484FE5C */   addiu $a0, %lo(record_player_input_as_packet) # addiu $a0, $a0, -0x1a4
/* 0F5210 7F0C06E0 3C028009 */  lui   $v0, %hi(address_demo_loaded)
/* 0F5214 7F0C06E4 2442C5F4 */  addiu $v0, %lo(address_demo_loaded) # addiu $v0, $v0, -0x3a0c
/* 0F5218 7F0C06E8 3C0500F0 */  lui   $a1, 0xf0
/* 0F521C 7F0C06EC AC450000 */  sw    $a1, ($v0)
/* 0F5220 7F0C06F0 8E040000 */  lw    $a0, ($s0)
/* 0F5224 7F0C06F4 0C001742 */  jal   romWrite
/* 0F5228 7F0C06F8 240600F0 */   li    $a2, 240
/* 0F522C 7F0C06FC 3C028009 */  lui   $v0, %hi(address_demo_loaded)
/* 0F5230 7F0C0700 2442C5F4 */  addiu $v0, %lo(address_demo_loaded) # addiu $v0, $v0, -0x3a0c
/* 0F5234 7F0C0704 8C4F0000 */  lw    $t7, ($v0)
/* 0F5238 7F0C0708 3C018005 */  lui   $at, %hi(flag_to_record_ramrom)
/* 0F523C 7F0C070C 25F800E8 */  addiu $t8, $t7, 0xe8
/* 0F5240 7F0C0710 AC580000 */  sw    $t8, ($v0)
/* 0F5244 7F0C0714 10000024 */  b     .L7F0C07A8
/* 0F5248 7F0C0718 AC208488 */   sw    $zero, %lo(flag_to_record_ramrom)($at)
.L7F0C071C:
/* 0F524C 7F0C071C 3C198005 */  lui   $t9, %hi(ramrom_demo_related_4) 
/* 0F5250 7F0C0720 8F39847C */  lw    $t9, %lo(ramrom_demo_related_4)($t9)
/* 0F5254 7F0C0724 13200020 */  beqz  $t9, .L7F0C07A8
/* 0F5258 7F0C0728 3C108005 */   lui   $s0, %hi(ptr_active_demofile)
/* 0F525C 7F0C072C 3C018009 */  lui   $at, %hi(dword_CODE_bss_8008C5F8)
/* 0F5260 7F0C0730 26108468 */  addiu $s0, %lo(ptr_active_demofile) # addiu $s0, $s0, -0x7b98
/* 0F5264 7F0C0734 AC20C5F8 */  sw    $zero, %lo(dword_CODE_bss_8008C5F8)($at)
/* 0F5268 7F0C0738 8E080000 */  lw    $t0, ($s0)
/* 0F526C 7F0C073C 0FC07567 */  jal   set_selected_difficulty
/* 0F5270 7F0C0740 8D040014 */   lw    $a0, 0x14($t0)
/* 0F5274 7F0C0744 8E090000 */  lw    $t1, ($s0)
/* 0F5278 7F0C0748 0FC0757B */  jal   set_solo_and_ptr_briefing
/* 0F527C 7F0C074C 8D240010 */   lw    $a0, 0x10($t1)
/* 0F5280 7F0C0750 8E040000 */  lw    $a0, ($s0)
/* 0F5284 7F0C0754 0FC07591 */  jal   sub_GAME_7F01D644
/* 0F5288 7F0C0758 2484001C */   addiu $a0, $a0, 0x1c
/* 0F528C 7F0C075C 3C048009 */  lui   $a0, %hi(ramrom_data_target + 0x110)
/* 0F5290 7F0C0760 0FC300EA */  jal   copy_current_ingame_registers_before_ramrom_playback
/* 0F5294 7F0C0764 2484C380 */   addiu $a0, %lo(ramrom_data_target + 0x110) # addiu $a0, $a0, -0x3c80
/* 0F5298 7F0C0768 0FC3013D */  jal   copy_recorded_ramrom_registers_to_proper_place_ingame
/* 0F529C 7F0C076C 8E040000 */   lw    $a0, ($s0)
/* 0F52A0 7F0C0770 24020001 */  li    $v0, 1
/* 0F52A4 7F0C0774 3C018005 */  lui   $at, %hi(is_ramrom_flag)
/* 0F52A8 7F0C0778 AC228474 */  sw    $v0, %lo(is_ramrom_flag)($at)
/* 0F52AC 7F0C077C 3C018005 */  lui   $at, %hi(ramrom_demo_related_3)
/* 0F52B0 7F0C0780 AC228478 */  sw    $v0, %lo(ramrom_demo_related_3)($at)
/* 0F52B4 7F0C0784 8E0A0000 */  lw    $t2, ($s0)
/* 0F52B8 7F0C0788 3C047F0C */  lui   $a0, %hi(ramrom_replay_handler) # $a0, 0x7f0c
/* 0F52BC 7F0C078C 24840080 */  addiu $a0, %lo(ramrom_replay_handler) # addiu $a0, $a0, 0x80
/* 0F52C0 7F0C0790 0C002EEA */  jal   set_disable_all_rumble_and_something
/* 0F52C4 7F0C0794 8D450018 */   lw    $a1, 0x18($t2)
/* 0F52C8 7F0C0798 0C00324C */  jal   controller_7000C930
/* 0F52CC 7F0C079C 24040001 */   li    $a0, 1
/* 0F52D0 7F0C07A0 3C018005 */  lui   $at, %hi(ramrom_demo_related_4)
/* 0F52D4 7F0C07A4 AC20847C */  sw    $zero, %lo(ramrom_demo_related_4)($at)
.L7F0C07A8:
/* 0F52D8 7F0C07A8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F52DC 7F0C07AC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F52E0 7F0C07B0 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F52E4 7F0C07B4 03E00008 */  jr    $ra
/* 0F52E8 7F0C07B8 00000000 */   nop   
)
#endif






void setRamRomRecordSlot(s32 arg0) {
    flag_to_record_ramrom = 1;
    record_slot_num = arg0;
}

void stop_recording_ramrom(void) {
    if (ramrom_demo_related_6 != 0)
    {
        finalize_ramrom_on_hw();
        set_ptr_tlb_ramrom_record(0);
        ramrom_demo_related_6 = 0;
        recording_ramrom_flag = 0;
    }
}






#ifdef NONMATCHING
void replay_recorded_ramrom_at_address(s32 arg0) 
{
    address_demo_loaded = arg0;
    ptr_active_demofile = romCopyAligned(&ramrom_data_target, address_demo_loaded, 0xe8);
    address_demo_loaded += 0xe8;
    ramrom_demo_related_4 = 1;
    set_solo_and_ptr_briefing(ptr_active_demofile->unk10);
    set_selected_difficulty(ptr_active_demofile->unk14);
    return set_menu_to_mode(0xb, 1);
}
#else
GLOBAL_ASM(
.text
glabel replay_recorded_ramrom_at_address
/* 0F534C 7F0C081C 3C038009 */  lui   $v1, %hi(address_demo_loaded)
/* 0F5350 7F0C0820 2463C5F4 */  addiu $v1, %lo(address_demo_loaded) # addiu $v1, $v1, -0x3a0c
/* 0F5354 7F0C0824 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5358 7F0C0828 AC640000 */  sw    $a0, ($v1)
/* 0F535C 7F0C082C AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5360 7F0C0830 3C048009 */  lui   $a0, %hi(ramrom_data_target)
/* 0F5364 7F0C0834 2484C270 */  addiu $a0, %lo(ramrom_data_target) # addiu $a0, $a0, -0x3d90
/* 0F5368 7F0C0838 8C650000 */  lw    $a1, ($v1)
/* 0F536C 7F0C083C 0C001711 */  jal   romCopyAligned
/* 0F5370 7F0C0840 240600E8 */   li    $a2, 232
/* 0F5374 7F0C0844 3C038009 */  lui   $v1, %hi(address_demo_loaded)
/* 0F5378 7F0C0848 2463C5F4 */  addiu $v1, %lo(address_demo_loaded) # addiu $v1, $v1, -0x3a0c
/* 0F537C 7F0C084C 8C6E0000 */  lw    $t6, ($v1)
/* 0F5380 7F0C0850 3C058005 */  lui   $a1, %hi(ptr_active_demofile)
/* 0F5384 7F0C0854 24A58468 */  addiu $a1, %lo(ptr_active_demofile) # addiu $a1, $a1, -0x7b98
/* 0F5388 7F0C0858 25CF00E8 */  addiu $t7, $t6, 0xe8
/* 0F538C 7F0C085C ACA20000 */  sw    $v0, ($a1)
/* 0F5390 7F0C0860 AC6F0000 */  sw    $t7, ($v1)
/* 0F5394 7F0C0864 24180001 */  li    $t8, 1
/* 0F5398 7F0C0868 3C018005 */  lui   $at, %hi(ramrom_demo_related_4)
/* 0F539C 7F0C086C AC38847C */  sw    $t8, %lo(ramrom_demo_related_4)($at)
/* 0F53A0 7F0C0870 8CB90000 */  lw    $t9, ($a1)
/* 0F53A4 7F0C0874 0FC0757B */  jal   set_solo_and_ptr_briefing
/* 0F53A8 7F0C0878 8F240010 */   lw    $a0, 0x10($t9)
/* 0F53AC 7F0C087C 3C088005 */  lui   $t0, %hi(ptr_active_demofile) 
/* 0F53B0 7F0C0880 8D088468 */  lw    $t0, %lo(ptr_active_demofile)($t0)
/* 0F53B4 7F0C0884 0FC07567 */  jal   set_selected_difficulty
/* 0F53B8 7F0C0888 8D040014 */   lw    $a0, 0x14($t0)
/* 0F53BC 7F0C088C 2404000B */  li    $a0, 11
/* 0F53C0 7F0C0890 0FC06975 */  jal   set_menu_to_mode
/* 0F53C4 7F0C0894 24050001 */   li    $a1, 1
/* 0F53C8 7F0C0898 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F53CC 7F0C089C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F53D0 7F0C08A0 03E00008 */  jr    $ra
/* 0F53D4 7F0C08A4 00000000 */   nop   
)
#endif





void replay_recorded_ramrom_from_indy(void)
{
    replay_recorded_ramrom_at_address(0xf00000);
}

void ensureCameraModeA(void)
{
    if (get_camera_mode() != 0xa)
    {
        set_camera_mode(0xa);
    }
}






#ifdef NONMATCHING
void stop_demo_playback(void)
{
    if (ramrom_demo_related_6 == 0) {
        if (ramrom_demo_related_3 != 0) {
            copy_recorded_ramrom_registers_to_proper_place_ingame(&ramromsettingsbackup);
            set_disable_all_rumble_and_something(0,0xffffffff);
            controller_7000C930(0);
            ramrom_demo_related_3 = 0;
            is_ramrom_flag = 0;
        }
    }
    else {
        stop_recording_ramrom();
    }
}
#else
GLOBAL_ASM(
.text
glabel stop_demo_playback
/* 0F542C 7F0C08FC 3C0E8005 */  lui   $t6, %hi(ramrom_demo_related_6) 
/* 0F5430 7F0C0900 8DCE8484 */  lw    $t6, %lo(ramrom_demo_related_6)($t6)
/* 0F5434 7F0C0904 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5438 7F0C0908 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F543C 7F0C090C 11C00005 */  beqz  $t6, .L7F0C0924
/* 0F5440 7F0C0910 3C0F8005 */   lui   $t7, %hi(ramrom_demo_related_3) 
/* 0F5444 7F0C0914 0FC301F5 */  jal   stop_recording_ramrom
/* 0F5448 7F0C0918 00000000 */   nop   
/* 0F544C 7F0C091C 10000011 */  b     .L7F0C0964
/* 0F5450 7F0C0920 8FBF0014 */   lw    $ra, 0x14($sp)
.L7F0C0924:
/* 0F5454 7F0C0924 8DEF8478 */  lw    $t7, %lo(ramrom_demo_related_3)($t7)
/* 0F5458 7F0C0928 3C048009 */  lui   $a0, %hi(ramrom_data_target + 0x110)
/* 0F545C 7F0C092C 51E0000D */  beql  $t7, $zero, .L7F0C0964
/* 0F5460 7F0C0930 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F5464 7F0C0934 0FC3013D */  jal   copy_recorded_ramrom_registers_to_proper_place_ingame
/* 0F5468 7F0C0938 2484C380 */   addiu $a0, %lo(ramrom_data_target + 0x110) # addiu $a0, $a0, -0x3c80
/* 0F546C 7F0C093C 00002025 */  move  $a0, $zero
/* 0F5470 7F0C0940 0C002EEA */  jal   set_disable_all_rumble_and_something
/* 0F5474 7F0C0944 2405FFFF */   li    $a1, -1
/* 0F5478 7F0C0948 0C00324C */  jal   controller_7000C930
/* 0F547C 7F0C094C 00002025 */   move  $a0, $zero
/* 0F5480 7F0C0950 3C018005 */  lui   $at, %hi(ramrom_demo_related_3)
/* 0F5484 7F0C0954 AC208478 */  sw    $zero, %lo(ramrom_demo_related_3)($at)
/* 0F5488 7F0C0958 3C018005 */  lui   $at, %hi(is_ramrom_flag)
/* 0F548C 7F0C095C AC208474 */  sw    $zero, %lo(is_ramrom_flag)($at)
/* 0F5490 7F0C0960 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F0C0964:
/* 0F5494 7F0C0964 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F5498 7F0C0968 03E00008 */  jr    $ra
/* 0F549C 7F0C096C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void select_ramrom_to_play(void) {

}
#else
GLOBAL_ASM(
.text
glabel select_ramrom_to_play
/* 0F54A0 7F0C0970 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F54A4 7F0C0974 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F54A8 7F0C0978 0FC07A66 */  jal   check_egypt_completed_any_folder
/* 0F54AC 7F0C097C 00000000 */   nop   
/* 0F54B0 7F0C0980 3C0E8005 */  lui   $t6, %hi(ramrom_table) 
/* 0F54B4 7F0C0984 8DCE83F0 */  lw    $t6, %lo(ramrom_table)($t6)
/* 0F54B8 7F0C0988 00402025 */  move  $a0, $v0
/* 0F54BC 7F0C098C 00001825 */  move  $v1, $zero
/* 0F54C0 7F0C0990 11C00011 */  beqz  $t6, .L7F0C09D8
/* 0F54C4 7F0C0994 3C0F8005 */   lui   $t7, %hi(ramrom_table + 0x4) 
/* 0F54C8 7F0C0998 8DEF83F4 */  lw    $t7, %lo(ramrom_table + 0x4)($t7)
/* 0F54CC 7F0C099C 3C198005 */  lui   $t9, %hi(ramrom_table) 
/* 0F54D0 7F0C09A0 273983F0 */  addiu $t9, %lo(ramrom_table) # addiu $t9, $t9, -0x7c10
/* 0F54D4 7F0C09A4 004F082A */  slt   $at, $v0, $t7
/* 0F54D8 7F0C09A8 1420000B */  bnez  $at, .L7F0C09D8
/* 0F54DC 7F0C09AC 0003C0C0 */   sll   $t8, $v1, 3
/* 0F54E0 7F0C09B0 03191021 */  addu  $v0, $t8, $t9
/* 0F54E4 7F0C09B4 8C480008 */  lw    $t0, 8($v0)
.L7F0C09B8:
/* 0F54E8 7F0C09B8 24630001 */  addiu $v1, $v1, 1
/* 0F54EC 7F0C09BC 24420008 */  addiu $v0, $v0, 8
/* 0F54F0 7F0C09C0 11000005 */  beqz  $t0, .L7F0C09D8
/* 0F54F4 7F0C09C4 00000000 */   nop   
/* 0F54F8 7F0C09C8 8C490004 */  lw    $t1, 4($v0)
/* 0F54FC 7F0C09CC 0089082A */  slt   $at, $a0, $t1
/* 0F5500 7F0C09D0 5020FFF9 */  beql  $at, $zero, .L7F0C09B8
/* 0F5504 7F0C09D4 8C480008 */   lw    $t0, 8($v0)
.L7F0C09D8:
/* 0F5508 7F0C09D8 0C002914 */  jal   get_random_value
/* 0F550C 7F0C09DC AFA3001C */   sw    $v1, 0x1c($sp)
/* 0F5510 7F0C09E0 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0F5514 7F0C09E4 3C048005 */  lui   $a0, %hi(ramrom_table)
/* 0F5518 7F0C09E8 0043001B */  divu  $zero, $v0, $v1
/* 0F551C 7F0C09EC 00005010 */  mfhi  $t2
/* 0F5520 7F0C09F0 000A58C0 */  sll   $t3, $t2, 3
/* 0F5524 7F0C09F4 008B2021 */  addu  $a0, $a0, $t3
/* 0F5528 7F0C09F8 14600002 */  bnez  $v1, .L7F0C0A04
/* 0F552C 7F0C09FC 00000000 */   nop   
/* 0F5530 7F0C0A00 0007000D */  break 7
.L7F0C0A04:
/* 0F5534 7F0C0A04 8C8483F0 */  lw    $a0, %lo(ramrom_table)($a0)
/* 0F5538 7F0C0A08 0FC30207 */  jal   replay_recorded_ramrom_at_address
/* 0F553C 7F0C0A0C 00000000 */   nop   
/* 0F5540 7F0C0A10 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F5544 7F0C0A14 27BD0020 */  addiu $sp, $sp, 0x20
/* 0F5548 7F0C0A18 03E00008 */  jr    $ra
/* 0F554C 7F0C0A1C 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
s32 check_ramrom_flags(void)
{
    if ((get_is_ramrom_flag() == 0) && (get_recording_ramrom_flag() == 0))
    {
        return 0;
    }
    else
    {
        return *(undefined4 *)(ptr_active_demofile + 0x88);
    }
}
#else
GLOBAL_ASM(
.text
glabel check_ramrom_flags
/* 0F5550 7F0C0A20 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5554 7F0C0A24 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F5558 7F0C0A28 0FC2FF23 */  jal   get_is_ramrom_flag
/* 0F555C 7F0C0A2C 00000000 */   nop   
/* 0F5560 7F0C0A30 14400004 */  bnez  $v0, .L7F0C0A44
/* 0F5564 7F0C0A34 00000000 */   nop   
/* 0F5568 7F0C0A38 0FC2FF26 */  jal   get_recording_ramrom_flag
/* 0F556C 7F0C0A3C 00000000 */   nop   
/* 0F5570 7F0C0A40 10400004 */  beqz  $v0, .L7F0C0A54
.L7F0C0A44:
/* 0F5574 7F0C0A44 3C0E8005 */   lui   $t6, %hi(ptr_active_demofile) 
/* 0F5578 7F0C0A48 8DCE8468 */  lw    $t6, %lo(ptr_active_demofile)($t6)
/* 0F557C 7F0C0A4C 10000002 */  b     .L7F0C0A58
/* 0F5580 7F0C0A50 8DC20088 */   lw    $v0, 0x88($t6)
.L7F0C0A54:
/* 0F5584 7F0C0A54 00001025 */  move  $v0, $zero
.L7F0C0A58:
/* 0F5588 7F0C0A58 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0F558C 7F0C0A5C 27BD0018 */  addiu $sp, $sp, 0x18
/* 0F5590 7F0C0A60 03E00008 */  jr    $ra
/* 0F5594 7F0C0A64 00000000 */   nop   
)
#endif




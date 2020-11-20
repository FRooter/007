#include "ultra64.h"
#include "game/lvl.h"
#include "game/unk_093880.h"

// data
//D:80036AD0
u32 D_80036AD0 = 0x4144;
u32 D_80036AD4 = 0x41180000;
u32 D_80036AD8 = 0x41D80000;
u32 D_80036ADC = 0;
u32 D_80036AE0 = 0;

//D:80036AE4
u32 D_80036AE4 = 0x3FC00000;
u32 D_80036AE8 = 0x4070;
u32 D_80036AEC = 0x40F00000;
u32 D_80036AF0 = 0x41880000;
u32 D_80036AF4 = 0;
//D:80036AF8
u32 D_80036AF8 = 0x3FC00000;
//D:80036AFC
u32 D_80036AFC =  0x42C80000;

//D:80036B00
u32 D_80036B00 = 0;
//D:80036B04
u32 D_80036B04 = 0;
//D:80036B08
u32 D_80036B08 = 0;
//D:80036B0C
u32 D_80036B0C = 0;
//D:80036B10
u32 D_80036B10 = 0;
//D:80036B14
f32 D_80036B14 = 1.0;
//D:80036B18
u32 D_80036B18 = 0;
//D:80036B1C
f32 D_80036B1C =  1.0;
//D:80036B20
u32 D_80036B20 = 0;
//D:80036B24
u32 D_80036B24 = 0;
//D:80036B28
u32 D_80036B28 = 1;
//D:80036B2C
u32 D_80036B2C = 3;
//D:80036B30
u32 D_80036B30[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//D:80036B60
u32 D_80036B60 = 0;
//D:80036B64
u32 D_80036B64 = 0;
//D:80036B68
u32 D_80036B68 = 0;
//D:80036B6C
u32 D_80036B6C = 0;



// rodata



#ifdef NONMATCHING//
void sub_GAME_7F08DBB0(void)
{
    pPlayer->field_5BC = (pPlayer->field_5BC == 0);
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08DBB0
/* 0C26E0 7F08DBB0 3C038008 */  lui   $v1, %hi(pPlayer)
/* 0C26E4 7F08DBB4 8C63A0B0 */  lw    $v1, %lo(pPlayer)($v1)
/* 0C26E8 7F08DBB8 806205BC */  lb    $v0, 0x5bc($v1)
/* 0C26EC 7F08DBBC 2C4E0001 */  sltiu $t6, $v0, 1
/* 0C26F0 7F08DBC0 03E00008 */  jr    $ra
/* 0C26F4 7F08DBC4 A06E05BC */   sb    $t6, 0x5bc($v1)
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08DBC8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800552E0
.word 0x3ca3d70a /*0.02*/
glabel D_800552E4
.word 0x3ca3d70a /*0.02*/
glabel D_800552E8
.word 0x3c23d70a /*0.0099999998*/
glabel D_800552EC
.word 0xbc23d70a  /*-0.0099999998*/
glabel D_800552F0
.word 0xbc23d70a  /*-0.0099999998*/
glabel D_800552F4
.word 0x3c23d70a /*0.0099999998*/
.text
glabel sub_GAME_7F08DBC8
/* 0C26F8 7F08DBC8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C26FC 7F08DBCC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C2700 7F08DBD0 AFB20028 */  sw    $s2, 0x28($sp)
/* 0C2704 7F08DBD4 AFB10024 */  sw    $s1, 0x24($sp)
/* 0C2708 7F08DBD8 AFB00020 */  sw    $s0, 0x20($sp)
/* 0C270C 7F08DBDC 0C002914 */  jal   get_random_value
/* 0C2710 7F08DBE0 F7B40018 */   sdc1  $f20, 0x18($sp)
/* 0C2714 7F08DBE4 44822000 */  mtc1  $v0, $f4
/* 0C2718 7F08DBE8 3C118008 */  lui   $s1, %hi(pPlayer)
/* 0C271C 7F08DBEC 3C012F80 */  li    $at, 0x2F800000 # 0.000000
/* 0C2720 7F08DBF0 4481A000 */  mtc1  $at, $f20
/* 0C2724 7F08DBF4 2631A0B0 */  addiu $s1, %lo(pPlayer) # addiu $s1, $s1, -0x5f50
/* 0C2728 7F08DBF8 8E300000 */  lw    $s0, ($s1)
/* 0C272C 7F08DBFC 2412000C */  li    $s2, 12
/* 0C2730 7F08DC00 04410005 */  bgez  $v0, .L7F08DC18
/* 0C2734 7F08DC04 468021A0 */   cvt.s.w $f6, $f4
/* 0C2738 7F08DC08 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C273C 7F08DC0C 44814000 */  mtc1  $at, $f8
/* 0C2740 7F08DC10 00000000 */  nop   
/* 0C2744 7F08DC14 46083180 */  add.s $f6, $f6, $f8
.L7F08DC18:
/* 0C2748 7F08DC18 46143282 */  mul.s $f10, $f6, $f20
/* 0C274C 7F08DC1C 8E0E0594 */  lw    $t6, 0x594($s0)
/* 0C2750 7F08DC20 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C2754 7F08DC24 44818000 */  mtc1  $at, $f16
/* 0C2758 7F08DC28 01D20019 */  multu $t6, $s2
/* 0C275C 7F08DC2C 3C018005 */  lui   $at, %hi(D_800552E0)
/* 0C2760 7F08DC30 C42452E0 */  lwc1  $f4, %lo(D_800552E0)($at)
/* 0C2764 7F08DC34 46105481 */  sub.s $f18, $f10, $f16
/* 0C2768 7F08DC38 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C276C 7F08DC3C 44813000 */  mtc1  $at, $f6
/* 0C2770 7F08DC40 46049202 */  mul.s $f8, $f18, $f4
/* 0C2774 7F08DC44 00007812 */  mflo  $t7
/* 0C2778 7F08DC48 020FC021 */  addu  $t8, $s0, $t7
/* 0C277C 7F08DC4C E7080564 */  swc1  $f8, 0x564($t8)
/* 0C2780 7F08DC50 8E300000 */  lw    $s0, ($s1)
/* 0C2784 7F08DC54 8E190594 */  lw    $t9, 0x594($s0)
/* 0C2788 7F08DC58 03320019 */  multu $t9, $s2
/* 0C278C 7F08DC5C 00004012 */  mflo  $t0
/* 0C2790 7F08DC60 02084821 */  addu  $t1, $s0, $t0
/* 0C2794 7F08DC64 0C002914 */  jal   get_random_value
/* 0C2798 7F08DC68 E526056C */   swc1  $f6, 0x56c($t1)
/* 0C279C 7F08DC6C 44825000 */  mtc1  $v0, $f10
/* 0C27A0 7F08DC70 8E300000 */  lw    $s0, ($s1)
/* 0C27A4 7F08DC74 04410005 */  bgez  $v0, .L7F08DC8C
/* 0C27A8 7F08DC78 46805420 */   cvt.s.w $f16, $f10
/* 0C27AC 7F08DC7C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C27B0 7F08DC80 44819000 */  mtc1  $at, $f18
/* 0C27B4 7F08DC84 00000000 */  nop   
/* 0C27B8 7F08DC88 46128400 */  add.s $f16, $f16, $f18
.L7F08DC8C:
/* 0C27BC 7F08DC8C 46148102 */  mul.s $f4, $f16, $f20
/* 0C27C0 7F08DC90 8E0A0594 */  lw    $t2, 0x594($s0)
/* 0C27C4 7F08DC94 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C27C8 7F08DC98 44814000 */  mtc1  $at, $f8
/* 0C27CC 7F08DC9C 01520019 */  multu $t2, $s2
/* 0C27D0 7F08DCA0 3C018005 */  lui   $at, %hi(D_800552E4)
/* 0C27D4 7F08DCA4 C42A52E4 */  lwc1  $f10, %lo(D_800552E4)($at)
/* 0C27D8 7F08DCA8 46082181 */  sub.s $f6, $f4, $f8
/* 0C27DC 7F08DCAC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C27E0 7F08DCB0 44818000 */  mtc1  $at, $f16
/* 0C27E4 7F08DCB4 460A3482 */  mul.s $f18, $f6, $f10
/* 0C27E8 7F08DCB8 00005812 */  mflo  $t3
/* 0C27EC 7F08DCBC 020B6021 */  addu  $t4, $s0, $t3
/* 0C27F0 7F08DCC0 E592057C */  swc1  $f18, 0x57c($t4)
/* 0C27F4 7F08DCC4 8E300000 */  lw    $s0, ($s1)
/* 0C27F8 7F08DCC8 8E0D0594 */  lw    $t5, 0x594($s0)
/* 0C27FC 7F08DCCC 01B20019 */  multu $t5, $s2
/* 0C2800 7F08DCD0 00007012 */  mflo  $t6
/* 0C2804 7F08DCD4 020E7821 */  addu  $t7, $s0, $t6
/* 0C2808 7F08DCD8 E5F00580 */  swc1  $f16, 0x580($t7)
/* 0C280C 7F08DCDC 8E380000 */  lw    $t8, ($s1)
/* 0C2810 7F08DCE0 8F190594 */  lw    $t9, 0x594($t8)
/* 0C2814 7F08DCE4 13200027 */  beqz  $t9, .L7F08DD84
/* 0C2818 7F08DCE8 00000000 */   nop   
/* 0C281C 7F08DCEC 0C002914 */  jal   get_random_value
/* 0C2820 7F08DCF0 00000000 */   nop   
/* 0C2824 7F08DCF4 44822000 */  mtc1  $v0, $f4
/* 0C2828 7F08DCF8 8E300000 */  lw    $s0, ($s1)
/* 0C282C 7F08DCFC 04410005 */  bgez  $v0, .L7F08DD14
/* 0C2830 7F08DD00 46802220 */   cvt.s.w $f8, $f4
/* 0C2834 7F08DD04 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C2838 7F08DD08 44813000 */  mtc1  $at, $f6
/* 0C283C 7F08DD0C 00000000 */  nop   
/* 0C2840 7F08DD10 46064200 */  add.s $f8, $f8, $f6
.L7F08DD14:
/* 0C2844 7F08DD14 8E080594 */  lw    $t0, 0x594($s0)
/* 0C2848 7F08DD18 46144282 */  mul.s $f10, $f8, $f20
/* 0C284C 7F08DD1C 3C018005 */  lui   $at, %hi(D_800552E8)
/* 0C2850 7F08DD20 01120019 */  multu $t0, $s2
/* 0C2854 7F08DD24 C43252E8 */  lwc1  $f18, %lo(D_800552E8)($at)
/* 0C2858 7F08DD28 46125402 */  mul.s $f16, $f10, $f18
/* 0C285C 7F08DD2C 00004812 */  mflo  $t1
/* 0C2860 7F08DD30 02095021 */  addu  $t2, $s0, $t1
/* 0C2864 7F08DD34 0C002914 */  jal   get_random_value
/* 0C2868 7F08DD38 E5500568 */   swc1  $f16, 0x568($t2)
/* 0C286C 7F08DD3C 44822000 */  mtc1  $v0, $f4
/* 0C2870 7F08DD40 8E300000 */  lw    $s0, ($s1)
/* 0C2874 7F08DD44 04410005 */  bgez  $v0, .L7F08DD5C
/* 0C2878 7F08DD48 468021A0 */   cvt.s.w $f6, $f4
/* 0C287C 7F08DD4C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C2880 7F08DD50 44814000 */  mtc1  $at, $f8
/* 0C2884 7F08DD54 00000000 */  nop   
/* 0C2888 7F08DD58 46083180 */  add.s $f6, $f6, $f8
.L7F08DD5C:
/* 0C288C 7F08DD5C 8E0B0594 */  lw    $t3, 0x594($s0)
/* 0C2890 7F08DD60 46143282 */  mul.s $f10, $f6, $f20
/* 0C2894 7F08DD64 3C018005 */  lui   $at, %hi(D_800552EC)
/* 0C2898 7F08DD68 01720019 */  multu $t3, $s2
/* 0C289C 7F08DD6C C43252EC */  lwc1  $f18, %lo(D_800552EC)($at)
/* 0C28A0 7F08DD70 46125402 */  mul.s $f16, $f10, $f18
/* 0C28A4 7F08DD74 00006012 */  mflo  $t4
/* 0C28A8 7F08DD78 020C6821 */  addu  $t5, $s0, $t4
/* 0C28AC 7F08DD7C 10000026 */  b     .L7F08DE18
/* 0C28B0 7F08DD80 E5B00584 */   swc1  $f16, 0x584($t5)
.L7F08DD84:
/* 0C28B4 7F08DD84 0C002914 */  jal   get_random_value
/* 0C28B8 7F08DD88 00000000 */   nop   
/* 0C28BC 7F08DD8C 44822000 */  mtc1  $v0, $f4
/* 0C28C0 7F08DD90 8E300000 */  lw    $s0, ($s1)
/* 0C28C4 7F08DD94 04410005 */  bgez  $v0, .L7F08DDAC
/* 0C28C8 7F08DD98 46802220 */   cvt.s.w $f8, $f4
/* 0C28CC 7F08DD9C 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C28D0 7F08DDA0 44813000 */  mtc1  $at, $f6
/* 0C28D4 7F08DDA4 00000000 */  nop   
/* 0C28D8 7F08DDA8 46064200 */  add.s $f8, $f8, $f6
.L7F08DDAC:
/* 0C28DC 7F08DDAC 8E0E0594 */  lw    $t6, 0x594($s0)
/* 0C28E0 7F08DDB0 46144282 */  mul.s $f10, $f8, $f20
/* 0C28E4 7F08DDB4 3C018005 */  lui   $at, %hi(D_800552F0)
/* 0C28E8 7F08DDB8 01D20019 */  multu $t6, $s2
/* 0C28EC 7F08DDBC C43252F0 */  lwc1  $f18, %lo(D_800552F0)($at)
/* 0C28F0 7F08DDC0 46125402 */  mul.s $f16, $f10, $f18
/* 0C28F4 7F08DDC4 00007812 */  mflo  $t7
/* 0C28F8 7F08DDC8 020FC021 */  addu  $t8, $s0, $t7
/* 0C28FC 7F08DDCC 0C002914 */  jal   get_random_value
/* 0C2900 7F08DDD0 E7100568 */   swc1  $f16, 0x568($t8)
/* 0C2904 7F08DDD4 44822000 */  mtc1  $v0, $f4
/* 0C2908 7F08DDD8 8E300000 */  lw    $s0, ($s1)
/* 0C290C 7F08DDDC 04410005 */  bgez  $v0, .L7F08DDF4
/* 0C2910 7F08DDE0 468021A0 */   cvt.s.w $f6, $f4
/* 0C2914 7F08DDE4 3C014F80 */  li    $at, 0x4F800000 # 4294967296.000000
/* 0C2918 7F08DDE8 44814000 */  mtc1  $at, $f8
/* 0C291C 7F08DDEC 00000000 */  nop   
/* 0C2920 7F08DDF0 46083180 */  add.s $f6, $f6, $f8
.L7F08DDF4:
/* 0C2924 7F08DDF4 8E190594 */  lw    $t9, 0x594($s0)
/* 0C2928 7F08DDF8 46143282 */  mul.s $f10, $f6, $f20
/* 0C292C 7F08DDFC 3C018005 */  lui   $at, %hi(D_800552F4)
/* 0C2930 7F08DE00 03320019 */  multu $t9, $s2
/* 0C2934 7F08DE04 C43252F4 */  lwc1  $f18, %lo(D_800552F4)($at)
/* 0C2938 7F08DE08 46125402 */  mul.s $f16, $f10, $f18
/* 0C293C 7F08DE0C 00004012 */  mflo  $t0
/* 0C2940 7F08DE10 02084821 */  addu  $t1, $s0, $t0
/* 0C2944 7F08DE14 E5300584 */  swc1  $f16, 0x584($t1)
.L7F08DE18:
/* 0C2948 7F08DE18 8E300000 */  lw    $s0, ($s1)
/* 0C294C 7F08DE1C 240B0001 */  li    $t3, 1
/* 0C2950 7F08DE20 8E0A0594 */  lw    $t2, 0x594($s0)
/* 0C2954 7F08DE24 016A6023 */  subu  $t4, $t3, $t2
/* 0C2958 7F08DE28 AE0C0594 */  sw    $t4, 0x594($s0)
/* 0C295C 7F08DE2C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C2960 7F08DE30 8FB20028 */  lw    $s2, 0x28($sp)
/* 0C2964 7F08DE34 8FB10024 */  lw    $s1, 0x24($sp)
/* 0C2968 7F08DE38 8FB00020 */  lw    $s0, 0x20($sp)
/* 0C296C 7F08DE3C D7B40018 */  ldc1  $f20, 0x18($sp)
/* 0C2970 7F08DE40 03E00008 */  jr    $ra
/* 0C2974 7F08DE44 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08DE48(struct xyzpoint *param_1)
{
    int i;
    
    if (pPlayer->field_4DC != 0)
    {
        (pPlayer->velocity).x = 0.00000000f;
        (pPlayer->velocity).y = param_1->y / 0.06999999f;
        (pPlayer->velocity).z = 0.00000000f;
        pPlayer->field_4DC = 0;
    }
    for (i = 0; i < clock_timer; ++i)
    {
        //wrong register allocation for mult
        (pPlayer->velocity).x = param_1->x + ((pPlayer->velocity).x * 0.93f);
        (pPlayer->velocity).y = param_1->y + ((pPlayer->velocity).y * 0.93f);
        (pPlayer->velocity).z = param_1->z + ((pPlayer->velocity).z * 0.93f);
    }
    (pPlayer->scaled_velocity).x = (pPlayer->velocity).x * 0.06999999f;
    (pPlayer->scaled_velocity).y = (pPlayer->velocity).y * 0.06999999f;
    (pPlayer->scaled_velocity).z = (pPlayer->velocity).z * 0.06999999f;
}
#else
GLOBAL_ASM(
.late_rodata
glabel D_800552F8
.word 0x3d8f5c28 /*0.069999993*/
glabel master_player_perspective
.word 0x3d8f5c28 /*0.069999993*/
glabel D_80055300
.word 0x3f6e147b /*0.93000001*/
.text
glabel sub_GAME_7F08DE48
/* 0C2978 7F08DE48 3C058008 */  lui   $a1, %hi(pPlayer)
/* 0C297C 7F08DE4C 24A5A0B0 */  addiu $a1, %lo(pPlayer) # addiu $a1, $a1, -0x5f50
/* 0C2980 7F08DE50 8CA20000 */  lw    $v0, ($a1)
/* 0C2984 7F08DE54 3C068005 */  lui   $a2, %hi(clock_timer)
/* 0C2988 7F08DE58 24C68374 */  addiu $a2, %lo(clock_timer) # addiu $a2, $a2, -0x7c8c
/* 0C298C 7F08DE5C 8C4E04DC */  lw    $t6, 0x4dc($v0)
/* 0C2990 7F08DE60 51C0000E */  beql  $t6, $zero, .L7F08DE9C
/* 0C2994 7F08DE64 8CC80000 */   lw    $t0, ($a2)
/* 0C2998 7F08DE68 44800000 */  mtc1  $zero, $f0
/* 0C299C 7F08DE6C 3C018005 */  lui   $at, %hi(D_800552F8)
/* 0C29A0 7F08DE70 C42252F8 */  lwc1  $f2, %lo(D_800552F8)($at)
/* 0C29A4 7F08DE74 E4400520 */  swc1  $f0, 0x520($v0)
/* 0C29A8 7F08DE78 C4840004 */  lwc1  $f4, 4($a0)
/* 0C29AC 7F08DE7C 8CAF0000 */  lw    $t7, ($a1)
/* 0C29B0 7F08DE80 46022183 */  div.s $f6, $f4, $f2
/* 0C29B4 7F08DE84 E5E60524 */  swc1  $f6, 0x524($t7)
/* 0C29B8 7F08DE88 8CB80000 */  lw    $t8, ($a1)
/* 0C29BC 7F08DE8C E7000528 */  swc1  $f0, 0x528($t8)
/* 0C29C0 7F08DE90 8CB90000 */  lw    $t9, ($a1)
/* 0C29C4 7F08DE94 AF2004DC */  sw    $zero, 0x4dc($t9)
/* 0C29C8 7F08DE98 8CC80000 */  lw    $t0, ($a2)
.L7F08DE9C:
/* 0C29CC 7F08DE9C 3C018005 */  lui   $at, %hi(master_player_perspective)
/* 0C29D0 7F08DEA0 C42252FC */  lwc1  $f2, %lo(master_player_perspective)($at)
/* 0C29D4 7F08DEA4 1900001A */  blez  $t0, .L7F08DF10
/* 0C29D8 7F08DEA8 00001825 */   move  $v1, $zero
/* 0C29DC 7F08DEAC 3C018005 */  lui   $at, %hi(D_80055300)
/* 0C29E0 7F08DEB0 C4205300 */  lwc1  $f0, %lo(D_80055300)($at)
/* 0C29E4 7F08DEB4 8CA20000 */  lw    $v0, ($a1)
.L7F08DEB8:
/* 0C29E8 7F08DEB8 C4880000 */  lwc1  $f8, ($a0)
/* 0C29EC 7F08DEBC 24630001 */  addiu $v1, $v1, 1
/* 0C29F0 7F08DEC0 C44A0520 */  lwc1  $f10, 0x520($v0)
/* 0C29F4 7F08DEC4 460A0402 */  mul.s $f16, $f0, $f10
/* 0C29F8 7F08DEC8 46104480 */  add.s $f18, $f8, $f16
/* 0C29FC 7F08DECC E4520520 */  swc1  $f18, 0x520($v0)
/* 0C2A00 7F08DED0 8CA20000 */  lw    $v0, ($a1)
/* 0C2A04 7F08DED4 C4840004 */  lwc1  $f4, 4($a0)
/* 0C2A08 7F08DED8 C4460524 */  lwc1  $f6, 0x524($v0)
/* 0C2A0C 7F08DEDC 46060282 */  mul.s $f10, $f0, $f6
/* 0C2A10 7F08DEE0 460A2200 */  add.s $f8, $f4, $f10
/* 0C2A14 7F08DEE4 E4480524 */  swc1  $f8, 0x524($v0)
/* 0C2A18 7F08DEE8 8CA20000 */  lw    $v0, ($a1)
/* 0C2A1C 7F08DEEC C4900008 */  lwc1  $f16, 8($a0)
/* 0C2A20 7F08DEF0 C4520528 */  lwc1  $f18, 0x528($v0)
/* 0C2A24 7F08DEF4 46120182 */  mul.s $f6, $f0, $f18
/* 0C2A28 7F08DEF8 46068100 */  add.s $f4, $f16, $f6
/* 0C2A2C 7F08DEFC E4440528 */  swc1  $f4, 0x528($v0)
/* 0C2A30 7F08DF00 8CC90000 */  lw    $t1, ($a2)
/* 0C2A34 7F08DF04 0069082A */  slt   $at, $v1, $t1
/* 0C2A38 7F08DF08 5420FFEB */  bnezl $at, .L7F08DEB8
/* 0C2A3C 7F08DF0C 8CA20000 */   lw    $v0, ($a1)
.L7F08DF10:
/* 0C2A40 7F08DF10 8CA20000 */  lw    $v0, ($a1)
/* 0C2A44 7F08DF14 C44A0520 */  lwc1  $f10, 0x520($v0)
/* 0C2A48 7F08DF18 46025202 */  mul.s $f8, $f10, $f2
/* 0C2A4C 7F08DF1C E44804FC */  swc1  $f8, 0x4fc($v0)
/* 0C2A50 7F08DF20 8CA20000 */  lw    $v0, ($a1)
/* 0C2A54 7F08DF24 C4520524 */  lwc1  $f18, 0x524($v0)
/* 0C2A58 7F08DF28 46029402 */  mul.s $f16, $f18, $f2
/* 0C2A5C 7F08DF2C E4500500 */  swc1  $f16, 0x500($v0)
/* 0C2A60 7F08DF30 8CA20000 */  lw    $v0, ($a1)
/* 0C2A64 7F08DF34 C4460528 */  lwc1  $f6, 0x528($v0)
/* 0C2A68 7F08DF38 46023102 */  mul.s $f4, $f6, $f2
/* 0C2A6C 7F08DF3C 03E00008 */  jr    $ra
/* 0C2A70 7F08DF40 E4440504 */   swc1  $f4, 0x504($v0)
)
#endif






void sub_GAME_7F08DF44(struct xyzpoint *param_1, struct xyzpoint *param_2)
{
    int i;
    
    if (pPlayer->field_4E0 != 0)
    {
        (pPlayer->field_52C).x = param_1->x / (1.0f - pPlayer->field_4EC);
        (pPlayer->field_52C).y = param_1->y / (1.0f - pPlayer->field_4EC);
        (pPlayer->field_52C).z = param_1->z / (1.0f - pPlayer->field_4EC);
        (pPlayer->field_538).x = param_2->x / (1.0f - pPlayer->field_4EC);
        (pPlayer->field_538).y = param_2->y / (1.0f - pPlayer->field_4EC);
        (pPlayer->field_538).z = param_2->z / (1.0f - pPlayer->field_4EC);
        pPlayer->field_4E0 = 0;
    }

    for (i = 0; i < clock_timer; ++i)
    {
        (pPlayer->field_52C).x = param_1->x + pPlayer->field_4EC * (pPlayer->field_52C).x;
        (pPlayer->field_52C).y = param_1->y + pPlayer->field_4EC * (pPlayer->field_52C).y;
        (pPlayer->field_52C).z = param_1->z + pPlayer->field_4EC * (pPlayer->field_52C).z;
        (pPlayer->field_538).x = param_2->x + pPlayer->field_4EC * (pPlayer->field_538).x;
        (pPlayer->field_538).y = param_2->y + pPlayer->field_4EC * (pPlayer->field_538).y;
        (pPlayer->field_538).z = param_2->z + pPlayer->field_4EC * (pPlayer->field_538).z;
    }

    (pPlayer->field_508).x = (pPlayer->field_52C).x * (1.0f - pPlayer->field_4EC);
    (pPlayer->field_508).y = (pPlayer->field_52C).y * (1.0f - pPlayer->field_4EC);
    (pPlayer->field_508).z = (pPlayer->field_52C).z * (1.0f - pPlayer->field_4EC);
    (pPlayer->field_514).x = (pPlayer->field_538).x * (1.0f - pPlayer->field_4EC);
    (pPlayer->field_514).y = (pPlayer->field_538).y * (1.0f - pPlayer->field_4EC);
    (pPlayer->field_514).z = (pPlayer->field_538).z * (1.0f - pPlayer->field_4EC);

}


void sub_GAME_7F08E164(float param_1)
{
    float fVar1;
    
    if (param_1 != pPlayer->field_4EC) {
        fVar1 = 1.0f - param_1;
        (pPlayer->field_52C).x = ((pPlayer->field_52C).x * (1.0f - pPlayer->field_4EC)) / fVar1;
        (pPlayer->field_52C).y = ((pPlayer->field_52C).y * (1.0f - pPlayer->field_4EC)) / fVar1;
        (pPlayer->field_52C).z = ((pPlayer->field_52C).z * (1.0f - pPlayer->field_4EC)) / fVar1;

        (pPlayer->field_538).x = ((pPlayer->field_538).x * (1.0f - pPlayer->field_4EC)) / fVar1;
        (pPlayer->field_538).y = ((pPlayer->field_538).y * (1.0f - pPlayer->field_4EC)) / fVar1;
        (pPlayer->field_538).z = ((pPlayer->field_538).z * (1.0f - pPlayer->field_4EC)) / fVar1;
        pPlayer->field_4EC = param_1;
    }
}




#ifdef NONMATCHING
void sub_GAME_7F08E240(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80055304
.word 0x3f333333 /*0.69999999*/
glabel D_80055308
.word 0x3dcccccd /*0.1*/
glabel D_8005530C
.word 0x3f19999a /*0.60000002*/
glabel D_80055310
.word 0x3f199999 /*0.59999996*/
glabel D_80055314
.word 0x3ecccccd /*0.40000001*/
glabel D_80055318
.word 0x3ecccccd /*0.40000001*/
glabel D_8005531C
.word 0x3f666666 /*0.89999998*/
glabel D_80055320
.word 0x3f6e147b /*0.93000001*/
glabel D_80055324
.word 0x3f7d70a4 /*0.99000001*/
glabel D_80055328
.word 0x3f59999a /*0.85000002*/
glabel D_8005532C
.word 0x3f7d70a4 /*0.99000001*/
glabel D_80055330
.word 0x3c088889 /*0.0083333338*/
glabel D_80055334
.word 0x3cccccce /*0.025000002*/
.text
glabel sub_GAME_7F08E240
/* 0C2D70 7F08E240 27BDFF18 */  addiu $sp, $sp, -0xe8
/* 0C2D74 7F08E244 3C0F8003 */  lui   $t7, %hi(D_80036B00) 
/* 0C2D78 7F08E248 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C2D7C 7F08E24C AFB00018 */  sw    $s0, 0x18($sp)
/* 0C2D80 7F08E250 E7AC00E8 */  swc1  $f12, 0xe8($sp)
/* 0C2D84 7F08E254 E7AE00EC */  swc1  $f14, 0xec($sp)
/* 0C2D88 7F08E258 25EF6B00 */  addiu $t7, %lo(D_80036B00) # addiu $t7, $t7, 0x6b00
/* 0C2D8C 7F08E25C 8DE10000 */  lw    $at, ($t7)
/* 0C2D90 7F08E260 27AE00DC */  addiu $t6, $sp, 0xdc
/* 0C2D94 7F08E264 8DE80004 */  lw    $t0, 4($t7)
/* 0C2D98 7F08E268 ADC10000 */  sw    $at, ($t6)
/* 0C2D9C 7F08E26C 8DE10008 */  lw    $at, 8($t7)
/* 0C2DA0 7F08E270 3C0A8003 */  lui   $t2, %hi(D_80036B0C) 
/* 0C2DA4 7F08E274 254A6B0C */  addiu $t2, %lo(D_80036B0C) # addiu $t2, $t2, 0x6b0c
/* 0C2DA8 7F08E278 ADC80004 */  sw    $t0, 4($t6)
/* 0C2DAC 7F08E27C ADC10008 */  sw    $at, 8($t6)
/* 0C2DB0 7F08E280 8D410000 */  lw    $at, ($t2)
/* 0C2DB4 7F08E284 27A900D0 */  addiu $t1, $sp, 0xd0
/* 0C2DB8 7F08E288 8D4D0004 */  lw    $t5, 4($t2)
/* 0C2DBC 7F08E28C AD210000 */  sw    $at, ($t1)
/* 0C2DC0 7F08E290 8D410008 */  lw    $at, 8($t2)
/* 0C2DC4 7F08E294 3C188003 */  lui   $t8, %hi(D_80036B18) 
/* 0C2DC8 7F08E298 27186B18 */  addiu $t8, %lo(D_80036B18) # addiu $t8, $t8, 0x6b18
/* 0C2DCC 7F08E29C AD2D0004 */  sw    $t5, 4($t1)
/* 0C2DD0 7F08E2A0 AD210008 */  sw    $at, 8($t1)
/* 0C2DD4 7F08E2A4 8F010000 */  lw    $at, ($t8)
/* 0C2DD8 7F08E2A8 27B900C4 */  addiu $t9, $sp, 0xc4
/* 0C2DDC 7F08E2AC 8F080004 */  lw    $t0, 4($t8)
/* 0C2DE0 7F08E2B0 AF210000 */  sw    $at, ($t9)
/* 0C2DE4 7F08E2B4 8F010008 */  lw    $at, 8($t8)
/* 0C2DE8 7F08E2B8 3C108008 */  lui   $s0, %hi(pPlayer)
/* 0C2DEC 7F08E2BC 2610A0B0 */  addiu $s0, %lo(pPlayer) # addiu $s0, $s0, -0x5f50
/* 0C2DF0 7F08E2C0 AF280004 */  sw    $t0, 4($t9)
/* 0C2DF4 7F08E2C4 AF210008 */  sw    $at, 8($t9)
/* 0C2DF8 7F08E2C8 8E040000 */  lw    $a0, ($s0)
/* 0C2DFC 7F08E2CC 0FC1BD86 */  jal   sub_GAME_7F06F618
/* 0C2E00 7F08E2D0 24840598 */   addiu $a0, $a0, 0x598
/* 0C2E04 7F08E2D4 8E020000 */  lw    $v0, ($s0)
/* 0C2E08 7F08E2D8 E7A000C0 */  swc1  $f0, 0xc0($sp)
/* 0C2E0C 7F08E2DC 3C098003 */  lui   $t1, %hi(D_80036B24) 
/* 0C2E10 7F08E2E0 8C4304E8 */  lw    $v1, 0x4e8($v0)
/* 0C2E14 7F08E2E4 25296B24 */  addiu $t1, %lo(D_80036B24) # addiu $t1, $t1, 0x6b24
/* 0C2E18 7F08E2E8 252D003C */  addiu $t5, $t1, 0x3c
/* 0C2E1C 7F08E2EC 14600024 */  bnez  $v1, .L7F08E380
/* 0C2E20 7F08E2F0 27AB0080 */   addiu $t3, $sp, 0x80
/* 0C2E24 7F08E2F4 3C018005 */  lui   $at, %hi(D_80055304)
/* 0C2E28 7F08E2F8 C4245304 */  lwc1  $f4, %lo(D_80055304)($at)
/* 0C2E2C 7F08E2FC 3C018005 */  lui   $at, %hi(D_80055308)
/* 0C2E30 7F08E300 4600203C */  c.lt.s $f4, $f0
/* 0C2E34 7F08E304 00000000 */  nop   
/* 0C2E38 7F08E308 45000005 */  bc1f  .L7F08E320
/* 0C2E3C 7F08E30C 00000000 */   nop   
/* 0C2E40 7F08E310 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C2E44 7F08E314 44813000 */  mtc1  $at, $f6
/* 0C2E48 7F08E318 10000015 */  b     .L7F08E370
/* 0C2E4C 7F08E31C E44604F4 */   swc1  $f6, 0x4f4($v0)
.L7F08E320:
/* 0C2E50 7F08E320 C4225308 */  lwc1  $f2, %lo(D_80055308)($at)
/* 0C2E54 7F08E324 3C018005 */  lui   $at, %hi(D_80055318)
/* 0C2E58 7F08E328 4600103C */  c.lt.s $f2, $f0
/* 0C2E5C 7F08E32C 00000000 */  nop   
/* 0C2E60 7F08E330 4500000D */  bc1f  .L7F08E368
/* 0C2E64 7F08E334 00000000 */   nop   
/* 0C2E68 7F08E338 46020201 */  sub.s $f8, $f0, $f2
/* 0C2E6C 7F08E33C 3C018005 */  lui   $at, %hi(D_8005530C)
/* 0C2E70 7F08E340 C42A530C */  lwc1  $f10, %lo(D_8005530C)($at)
/* 0C2E74 7F08E344 3C018005 */  lui   $at, %hi(D_80055310)
/* 0C2E78 7F08E348 C4325310 */  lwc1  $f18, %lo(D_80055310)($at)
/* 0C2E7C 7F08E34C 460A4402 */  mul.s $f16, $f8, $f10
/* 0C2E80 7F08E350 3C018005 */  lui   $at, %hi(D_80055318)
/* 0C2E84 7F08E354 C4265314 */  lwc1  $f6, %lo(D_80055314)($at)
/* 0C2E88 7F08E358 46128103 */  div.s $f4, $f16, $f18
/* 0C2E8C 7F08E35C 46062200 */  add.s $f8, $f4, $f6
/* 0C2E90 7F08E360 10000003 */  b     .L7F08E370
/* 0C2E94 7F08E364 E44804F4 */   swc1  $f8, 0x4f4($v0)
.L7F08E368:
/* 0C2E98 7F08E368 C42A5318 */  lwc1  $f10, %lo(D_80055318)($at)
/* 0C2E9C 7F08E36C E44A04F4 */  swc1  $f10, 0x4f4($v0)
.L7F08E370:
/* 0C2EA0 7F08E370 8E020000 */  lw    $v0, ($s0)
/* 0C2EA4 7F08E374 C45004F4 */  lwc1  $f16, 0x4f4($v0)
/* 0C2EA8 7F08E378 10000012 */  b     .L7F08E3C4
/* 0C2EAC 7F08E37C E45004F8 */   swc1  $f16, 0x4f8($v0)
.L7F08E380:
/* 0C2EB0 7F08E380 24010001 */  li    $at, 1
/* 0C2EB4 7F08E384 14610008 */  bne   $v1, $at, .L7F08E3A8
/* 0C2EB8 7F08E388 3C018005 */   lui   $at, %hi(D_8005531C)
/* 0C2EBC 7F08E38C C432531C */  lwc1  $f18, %lo(D_8005531C)($at)
/* 0C2EC0 7F08E390 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C2EC4 7F08E394 44812000 */  mtc1  $at, $f4
/* 0C2EC8 7F08E398 E45204F4 */  swc1  $f18, 0x4f4($v0)
/* 0C2ECC 7F08E39C 8E0C0000 */  lw    $t4, ($s0)
/* 0C2ED0 7F08E3A0 10000008 */  b     .L7F08E3C4
/* 0C2ED4 7F08E3A4 E58404F8 */   swc1  $f4, 0x4f8($t4)
.L7F08E3A8:
/* 0C2ED8 7F08E3A8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C2EDC 7F08E3AC 44813000 */  mtc1  $at, $f6
/* 0C2EE0 7F08E3B0 00000000 */  nop   
/* 0C2EE4 7F08E3B4 E44604F4 */  swc1  $f6, 0x4f4($v0)
/* 0C2EE8 7F08E3B8 8E020000 */  lw    $v0, ($s0)
/* 0C2EEC 7F08E3BC C44804F4 */  lwc1  $f8, 0x4f4($v0)
/* 0C2EF0 7F08E3C0 E44804F8 */  swc1  $f8, 0x4f8($v0)
.L7F08E3C4:
/* 0C2EF4 7F08E3C4 8D210000 */  lw    $at, ($t1)
/* 0C2EF8 7F08E3C8 2529000C */  addiu $t1, $t1, 0xc
/* 0C2EFC 7F08E3CC 256B000C */  addiu $t3, $t3, 0xc
/* 0C2F00 7F08E3D0 AD61FFF4 */  sw    $at, -0xc($t3)
/* 0C2F04 7F08E3D4 8D21FFF8 */  lw    $at, -8($t1)
/* 0C2F08 7F08E3D8 AD61FFF8 */  sw    $at, -8($t3)
/* 0C2F0C 7F08E3DC 8D21FFFC */  lw    $at, -4($t1)
/* 0C2F10 7F08E3E0 152DFFF8 */  bne   $t1, $t5, .L7F08E3C4
/* 0C2F14 7F08E3E4 AD61FFFC */   sw    $at, -4($t3)
/* 0C2F18 7F08E3E8 8D210000 */  lw    $at, ($t1)
/* 0C2F1C 7F08E3EC 3C0E8003 */  lui   $t6, %hi(D_80036B64) 
/* 0C2F20 7F08E3F0 25CE6B64 */  addiu $t6, %lo(D_80036B64) # addiu $t6, $t6, 0x6b64
/* 0C2F24 7F08E3F4 AD610000 */  sw    $at, ($t3)
/* 0C2F28 7F08E3F8 8DC10000 */  lw    $at, ($t6)
/* 0C2F2C 7F08E3FC 27AF0034 */  addiu $t7, $sp, 0x34
/* 0C2F30 7F08E400 8DD80004 */  lw    $t8, 4($t6)
/* 0C2F34 7F08E404 ADE10000 */  sw    $at, ($t7)
/* 0C2F38 7F08E408 8DC10008 */  lw    $at, 8($t6)
/* 0C2F3C 7F08E40C ADF80004 */  sw    $t8, 4($t7)
/* 0C2F40 7F08E410 0FC1C078 */  jal   sub_GAME_7F0701E0
/* 0C2F44 7F08E414 ADE10008 */   sw    $at, 8($t7)
/* 0C2F48 7F08E418 8E080000 */  lw    $t0, ($s0)
/* 0C2F4C 7F08E41C AFA20030 */  sw    $v0, 0x30($sp)
/* 0C2F50 7F08E420 00002025 */  move  $a0, $zero
/* 0C2F54 7F08E424 0FC1C075 */  jal   sub_GAME_7F0701D4
/* 0C2F58 7F08E428 AD0004E4 */   sw    $zero, 0x4e4($t0)
/* 0C2F5C 7F08E42C 8E040000 */  lw    $a0, ($s0)
/* 0C2F60 7F08E430 3C058005 */  lui   $a1, %hi(clock_timer)
/* 0C2F64 7F08E434 8CA58374 */  lw    $a1, %lo(clock_timer)($a1)
/* 0C2F68 7F08E438 24060001 */  li    $a2, 1
/* 0C2F6C 7F08E43C 0FC1C2BB */  jal   sub_GAME_7F070AEC
/* 0C2F70 7F08E440 24840598 */   addiu $a0, $a0, 0x598
/* 0C2F74 7F08E444 0FC1C075 */  jal   sub_GAME_7F0701D4
/* 0C2F78 7F08E448 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C2F7C 7F08E44C 8E040000 */  lw    $a0, ($s0)
/* 0C2F80 7F08E450 0FC1B5AC */  jal   subcalcpos
/* 0C2F84 7F08E454 24840598 */   addiu $a0, $a0, 0x598
/* 0C2F88 7F08E458 0FC15FF4 */  jal   matrix_4x4_set_identity
/* 0C2F8C 7F08E45C 27A40040 */   addiu $a0, $sp, 0x40
/* 0C2F90 7F08E460 8E020000 */  lw    $v0, ($s0)
/* 0C2F94 7F08E464 27AC0040 */  addiu $t4, $sp, 0x40
/* 0C2F98 7F08E468 AFAC0080 */  sw    $t4, 0x80($sp)
/* 0C2F9C 7F08E46C 244A06D0 */  addiu $t2, $v0, 0x6d0
/* 0C2FA0 7F08E470 AFAA0090 */  sw    $t2, 0x90($sp)
/* 0C2FA4 7F08E474 27A40080 */  addiu $a0, $sp, 0x80
/* 0C2FA8 7F08E478 0FC1BCBE */  jal   subcalcmatrices
/* 0C2FAC 7F08E47C 24450598 */   addiu $a1, $v0, 0x598
/* 0C2FB0 7F08E480 8E020000 */  lw    $v0, ($s0)
/* 0C2FB4 7F08E484 27A50034 */  addiu $a1, $sp, 0x34
/* 0C2FB8 7F08E488 C44A0554 */  lwc1  $f10, 0x554($v0)
/* 0C2FBC 7F08E48C E44A0544 */  swc1  $f10, 0x544($v0)
/* 0C2FC0 7F08E490 8E020000 */  lw    $v0, ($s0)
/* 0C2FC4 7F08E494 C4500558 */  lwc1  $f16, 0x558($v0)
/* 0C2FC8 7F08E498 E4500548 */  swc1  $f16, 0x548($v0)
/* 0C2FCC 7F08E49C 8E020000 */  lw    $v0, ($s0)
/* 0C2FD0 7F08E4A0 C452055C */  lwc1  $f18, 0x55c($v0)
/* 0C2FD4 7F08E4A4 E452054C */  swc1  $f18, 0x54c($v0)
/* 0C2FD8 7F08E4A8 8E040000 */  lw    $a0, ($s0)
/* 0C2FDC 7F08E4AC 0FC1B2E6 */  jal   getsuboffset
/* 0C2FE0 7F08E4B0 24840598 */   addiu $a0, $a0, 0x598
/* 0C2FE4 7F08E4B4 8E020000 */  lw    $v0, ($s0)
/* 0C2FE8 7F08E4B8 C7A40034 */  lwc1  $f4, 0x34($sp)
/* 0C2FEC 7F08E4BC C7AA003C */  lwc1  $f10, 0x3c($sp)
/* 0C2FF0 7F08E4C0 C4460700 */  lwc1  $f6, 0x700($v0)
/* 0C2FF4 7F08E4C4 27A50034 */  addiu $a1, $sp, 0x34
/* 0C2FF8 7F08E4C8 24440598 */  addiu $a0, $v0, 0x598
/* 0C2FFC 7F08E4CC 46062201 */  sub.s $f8, $f4, $f6
/* 0C3000 7F08E4D0 E7A80034 */  swc1  $f8, 0x34($sp)
/* 0C3004 7F08E4D4 C4500708 */  lwc1  $f16, 0x708($v0)
/* 0C3008 7F08E4D8 46105481 */  sub.s $f18, $f10, $f16
/* 0C300C 7F08E4DC 0FC1B303 */  jal   setsuboffset
/* 0C3010 7F08E4E0 E7B2003C */   swc1  $f18, 0x3c($sp)
/* 0C3014 7F08E4E4 44800000 */  mtc1  $zero, $f0
/* 0C3018 7F08E4E8 C7A400C0 */  lwc1  $f4, 0xc0($sp)
/* 0C301C 7F08E4EC 4604003C */  c.lt.s $f0, $f4
/* 0C3020 7F08E4F0 00000000 */  nop   
/* 0C3024 7F08E4F4 45020071 */  bc1fl .L7F08E6BC
/* 0C3028 7F08E4F8 8E020000 */   lw    $v0, ($s0)
/* 0C302C 7F08E4FC 8E020000 */  lw    $v0, ($s0)
/* 0C3030 7F08E500 C7A800EC */  lwc1  $f8, 0xec($sp)
/* 0C3034 7F08E504 3C048005 */  lui   $a0, %hi(clock_timer)
/* 0C3038 7F08E508 C4460700 */  lwc1  $f6, 0x700($v0)
/* 0C303C 7F08E50C 24848374 */  addiu $a0, %lo(clock_timer) # addiu $a0, $a0, -0x7c8c
/* 0C3040 7F08E510 3C038005 */  lui   $v1, %hi(global_timer_delta)
/* 0C3044 7F08E514 46083280 */  add.s $f10, $f6, $f8
/* 0C3048 7F08E518 E44A0700 */  swc1  $f10, 0x700($v0)
/* 0C304C 7F08E51C 8E020000 */  lw    $v0, ($s0)
/* 0C3050 7F08E520 C7B200E8 */  lwc1  $f18, 0xe8($sp)
/* 0C3054 7F08E524 C4500708 */  lwc1  $f16, 0x708($v0)
/* 0C3058 7F08E528 46128102 */  mul.s $f4, $f16, $f18
/* 0C305C 7F08E52C E4440708 */  swc1  $f4, 0x708($v0)
/* 0C3060 7F08E530 8C8D0000 */  lw    $t5, ($a0)
/* 0C3064 7F08E534 59A0000D */  blezl $t5, .L7F08E56C
/* 0C3068 7F08E538 8E020000 */   lw    $v0, ($s0)
/* 0C306C 7F08E53C 8E020000 */  lw    $v0, ($s0)
/* 0C3070 7F08E540 24638378 */  addiu $v1, %lo(global_timer_delta) # addiu $v1, $v1, -0x7c88
/* 0C3074 7F08E544 C4680000 */  lwc1  $f8, ($v1)
/* 0C3078 7F08E548 C4460700 */  lwc1  $f6, 0x700($v0)
/* 0C307C 7F08E54C 46083283 */  div.s $f10, $f6, $f8
/* 0C3080 7F08E550 E44A0700 */  swc1  $f10, 0x700($v0)
/* 0C3084 7F08E554 8E020000 */  lw    $v0, ($s0)
/* 0C3088 7F08E558 C4720000 */  lwc1  $f18, ($v1)
/* 0C308C 7F08E55C C4500708 */  lwc1  $f16, 0x708($v0)
/* 0C3090 7F08E560 46128103 */  div.s $f4, $f16, $f18
/* 0C3094 7F08E564 E4440708 */  swc1  $f4, 0x708($v0)
/* 0C3098 7F08E568 8E020000 */  lw    $v0, ($s0)
.L7F08E56C:
/* 0C309C 7F08E56C C4460700 */  lwc1  $f6, 0x700($v0)
/* 0C30A0 7F08E570 C44804F4 */  lwc1  $f8, 0x4f4($v0)
/* 0C30A4 7F08E574 46083282 */  mul.s $f10, $f6, $f8
/* 0C30A8 7F08E578 E7AA00DC */  swc1  $f10, 0xdc($sp)
/* 0C30AC 7F08E57C C4500704 */  lwc1  $f16, 0x704($v0)
/* 0C30B0 7F08E580 C4400550 */  lwc1  $f0, 0x550($v0)
/* 0C30B4 7F08E584 C44404F4 */  lwc1  $f4, 0x4f4($v0)
/* 0C30B8 7F08E588 46008481 */  sub.s $f18, $f16, $f0
/* 0C30BC 7F08E58C 46049182 */  mul.s $f6, $f18, $f4
/* 0C30C0 7F08E590 46003200 */  add.s $f8, $f6, $f0
/* 0C30C4 7F08E594 E7A800E0 */  swc1  $f8, 0xe0($sp)
/* 0C30C8 7F08E598 C45004F4 */  lwc1  $f16, 0x4f4($v0)
/* 0C30CC 7F08E59C C44A0708 */  lwc1  $f10, 0x708($v0)
/* 0C30D0 7F08E5A0 46105482 */  mul.s $f18, $f10, $f16
/* 0C30D4 7F08E5A4 E7B200E4 */  swc1  $f18, 0xe4($sp)
/* 0C30D8 7F08E5A8 8C4904E8 */  lw    $t1, 0x4e8($v0)
/* 0C30DC 7F08E5AC 05220032 */  bltzl $t1, .L7F08E678
/* 0C30E0 7F08E5B0 C45006F0 */   lwc1  $f16, 0x6f0($v0)
/* 0C30E4 7F08E5B4 C44406F0 */  lwc1  $f4, 0x6f0($v0)
/* 0C30E8 7F08E5B8 C44604F8 */  lwc1  $f6, 0x4f8($v0)
/* 0C30EC 7F08E5BC 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C30F0 7F08E5C0 44810000 */  mtc1  $at, $f0
/* 0C30F4 7F08E5C4 46062202 */  mul.s $f8, $f4, $f6
/* 0C30F8 7F08E5C8 8C990000 */  lw    $t9, ($a0)
/* 0C30FC 7F08E5CC E7A800D0 */  swc1  $f8, 0xd0($sp)
/* 0C3100 7F08E5D0 C45004F4 */  lwc1  $f16, 0x4f4($v0)
/* 0C3104 7F08E5D4 C44A06F4 */  lwc1  $f10, 0x6f4($v0)
/* 0C3108 7F08E5D8 46105482 */  mul.s $f18, $f10, $f16
/* 0C310C 7F08E5DC E7B200D4 */  swc1  $f18, 0xd4($sp)
/* 0C3110 7F08E5E0 C44406F8 */  lwc1  $f4, 0x6f8($v0)
/* 0C3114 7F08E5E4 C44804F4 */  lwc1  $f8, 0x4f4($v0)
/* 0C3118 7F08E5E8 46002181 */  sub.s $f6, $f4, $f0
/* 0C311C 7F08E5EC 46083282 */  mul.s $f10, $f6, $f8
/* 0C3120 7F08E5F0 46005400 */  add.s $f16, $f10, $f0
/* 0C3124 7F08E5F4 E7B000D8 */  swc1  $f16, 0xd8($sp)
/* 0C3128 7F08E5F8 C44404F4 */  lwc1  $f4, 0x4f4($v0)
/* 0C312C 7F08E5FC C45206E0 */  lwc1  $f18, 0x6e0($v0)
/* 0C3130 7F08E600 46049182 */  mul.s $f6, $f18, $f4
/* 0C3134 7F08E604 E7A600C4 */  swc1  $f6, 0xc4($sp)
/* 0C3138 7F08E608 C44806E4 */  lwc1  $f8, 0x6e4($v0)
/* 0C313C 7F08E60C C45004F4 */  lwc1  $f16, 0x4f4($v0)
/* 0C3140 7F08E610 46004281 */  sub.s $f10, $f8, $f0
/* 0C3144 7F08E614 46105482 */  mul.s $f18, $f10, $f16
/* 0C3148 7F08E618 46009100 */  add.s $f4, $f18, $f0
/* 0C314C 7F08E61C E7A400C8 */  swc1  $f4, 0xc8($sp)
/* 0C3150 7F08E620 C44804F4 */  lwc1  $f8, 0x4f4($v0)
/* 0C3154 7F08E624 C44606E8 */  lwc1  $f6, 0x6e8($v0)
/* 0C3158 7F08E628 46083282 */  mul.s $f10, $f6, $f8
/* 0C315C 7F08E62C E7AA00CC */  swc1  $f10, 0xcc($sp)
/* 0C3160 7F08E630 8C4B04F0 */  lw    $t3, 0x4f0($v0)
/* 0C3164 7F08E634 01797821 */  addu  $t7, $t3, $t9
/* 0C3168 7F08E638 AC4F04F0 */  sw    $t7, 0x4f0($v0)
/* 0C316C 7F08E63C 8E0E0000 */  lw    $t6, ($s0)
/* 0C3170 7F08E640 8DD804F0 */  lw    $t8, 0x4f0($t6)
/* 0C3174 7F08E644 2B01003D */  slti  $at, $t8, 0x3d
/* 0C3178 7F08E648 14200005 */  bnez  $at, .L7F08E660
/* 0C317C 7F08E64C 3C018005 */   lui   $at, %hi(D_80055320)
/* 0C3180 7F08E650 0FC23859 */  jal   sub_GAME_7F08E164
/* 0C3184 7F08E654 C42C5320 */   lwc1  $f12, %lo(D_80055320)($at)
/* 0C3188 7F08E658 1000008E */  b     .L7F08E894
/* 0C318C 7F08E65C 00000000 */   nop   
.L7F08E660:
/* 0C3190 7F08E660 3C018005 */  lui   $at, %hi(D_80055324)
/* 0C3194 7F08E664 0FC23859 */  jal   sub_GAME_7F08E164
/* 0C3198 7F08E668 C42C5324 */   lwc1  $f12, %lo(D_80055324)($at)
/* 0C319C 7F08E66C 10000089 */  b     .L7F08E894
/* 0C31A0 7F08E670 00000000 */   nop   
/* 0C31A4 7F08E674 C45006F0 */  lwc1  $f16, 0x6f0($v0)
.L7F08E678:
/* 0C31A8 7F08E678 3C018005 */  lui   $at, %hi(D_80055328)
/* 0C31AC 7F08E67C C42C5328 */  lwc1  $f12, %lo(D_80055328)($at)
/* 0C31B0 7F08E680 E7B000D0 */  swc1  $f16, 0xd0($sp)
/* 0C31B4 7F08E684 C45206F4 */  lwc1  $f18, 0x6f4($v0)
/* 0C31B8 7F08E688 E7B200D4 */  swc1  $f18, 0xd4($sp)
/* 0C31BC 7F08E68C C44406F8 */  lwc1  $f4, 0x6f8($v0)
/* 0C31C0 7F08E690 E7A400D8 */  swc1  $f4, 0xd8($sp)
/* 0C31C4 7F08E694 C44606E0 */  lwc1  $f6, 0x6e0($v0)
/* 0C31C8 7F08E698 E7A600C4 */  swc1  $f6, 0xc4($sp)
/* 0C31CC 7F08E69C C44806E4 */  lwc1  $f8, 0x6e4($v0)
/* 0C31D0 7F08E6A0 E7A800C8 */  swc1  $f8, 0xc8($sp)
/* 0C31D4 7F08E6A4 C44A06E8 */  lwc1  $f10, 0x6e8($v0)
/* 0C31D8 7F08E6A8 0FC23859 */  jal   sub_GAME_7F08E164
/* 0C31DC 7F08E6AC E7AA00CC */   swc1  $f10, 0xcc($sp)
/* 0C31E0 7F08E6B0 10000078 */  b     .L7F08E894
/* 0C31E4 7F08E6B4 00000000 */   nop   
/* 0C31E8 7F08E6B8 8E020000 */  lw    $v0, ($s0)
.L7F08E6BC:
/* 0C31EC 7F08E6BC 3C018005 */  lui   $at, %hi(D_8005532C)
/* 0C31F0 7F08E6C0 C4500554 */  lwc1  $f16, 0x554($v0)
/* 0C31F4 7F08E6C4 E4500544 */  swc1  $f16, 0x544($v0)
/* 0C31F8 7F08E6C8 8E020000 */  lw    $v0, ($s0)
/* 0C31FC 7F08E6CC C4520558 */  lwc1  $f18, 0x558($v0)
/* 0C3200 7F08E6D0 E4520548 */  swc1  $f18, 0x548($v0)
/* 0C3204 7F08E6D4 8E020000 */  lw    $v0, ($s0)
/* 0C3208 7F08E6D8 C444055C */  lwc1  $f4, 0x55c($v0)
/* 0C320C 7F08E6DC E444054C */  swc1  $f4, 0x54c($v0)
/* 0C3210 7F08E6E0 8E020000 */  lw    $v0, ($s0)
/* 0C3214 7F08E6E4 E7A000DC */  swc1  $f0, 0xdc($sp)
/* 0C3218 7F08E6E8 C4460550 */  lwc1  $f6, 0x550($v0)
/* 0C321C 7F08E6EC E7A000E4 */  swc1  $f0, 0xe4($sp)
/* 0C3220 7F08E6F0 E7A600E0 */  swc1  $f6, 0xe0($sp)
/* 0C3224 7F08E6F4 AC4004F0 */  sw    $zero, 0x4f0($v0)
/* 0C3228 7F08E6F8 0FC23859 */  jal   sub_GAME_7F08E164
/* 0C322C 7F08E6FC C42C532C */   lwc1  $f12, %lo(D_8005532C)($at)
/* 0C3230 7F08E700 0FC227B5 */  jal   get_BONDdata_bondfadefracnew
/* 0C3234 7F08E704 00000000 */   nop   
/* 0C3238 7F08E708 3C018005 */  lui   $at, %hi(D_80055330)
/* 0C323C 7F08E70C C4285330 */  lwc1  $f8, %lo(D_80055330)($at)
/* 0C3240 7F08E710 3C018005 */  lui   $at, %hi(D_80055334)
/* 0C3244 7F08E714 C42A5334 */  lwc1  $f10, %lo(D_80055334)($at)
/* 0C3248 7F08E718 3C038005 */  lui   $v1, %hi(global_timer_delta)
/* 0C324C 7F08E71C 24638378 */  addiu $v1, %lo(global_timer_delta) # addiu $v1, $v1, -0x7c88
/* 0C3250 7F08E720 46005402 */  mul.s $f16, $f10, $f0
/* 0C3254 7F08E724 C4640000 */  lwc1  $f4, ($v1)
/* 0C3258 7F08E728 8E020000 */  lw    $v0, ($s0)
/* 0C325C 7F08E72C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C3260 7F08E730 C44A0560 */  lwc1  $f10, 0x560($v0)
/* 0C3264 7F08E734 46104480 */  add.s $f18, $f8, $f16
/* 0C3268 7F08E738 44818000 */  mtc1  $at, $f16
/* 0C326C 7F08E73C 46049182 */  mul.s $f6, $f18, $f4
/* 0C3270 7F08E740 46065200 */  add.s $f8, $f10, $f6
/* 0C3274 7F08E744 E4480560 */  swc1  $f8, 0x560($v0)
/* 0C3278 7F08E748 8E020000 */  lw    $v0, ($s0)
/* 0C327C 7F08E74C C4420560 */  lwc1  $f2, 0x560($v0)
/* 0C3280 7F08E750 4602803E */  c.le.s $f16, $f2
/* 0C3284 7F08E754 00000000 */  nop   
/* 0C3288 7F08E758 4502000C */  bc1fl .L7F08E78C
/* 0C328C 7F08E75C 8C430594 */   lw    $v1, 0x594($v0)
/* 0C3290 7F08E760 0FC236F2 */  jal   sub_GAME_7F08DBC8
/* 0C3294 7F08E764 00000000 */   nop   
/* 0C3298 7F08E768 8E020000 */  lw    $v0, ($s0)
/* 0C329C 7F08E76C 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C32A0 7F08E770 44812000 */  mtc1  $at, $f4
/* 0C32A4 7F08E774 C4520560 */  lwc1  $f18, 0x560($v0)
/* 0C32A8 7F08E778 46049281 */  sub.s $f10, $f18, $f4
/* 0C32AC 7F08E77C E44A0560 */  swc1  $f10, 0x560($v0)
/* 0C32B0 7F08E780 8E020000 */  lw    $v0, ($s0)
/* 0C32B4 7F08E784 C4420560 */  lwc1  $f2, 0x560($v0)
/* 0C32B8 7F08E788 8C430594 */  lw    $v1, 0x594($v0)
.L7F08E78C:
/* 0C32BC 7F08E78C 44061000 */  mfc1  $a2, $f2
/* 0C32C0 7F08E790 27A700D0 */  addiu $a3, $sp, 0xd0
/* 0C32C4 7F08E794 00034080 */  sll   $t0, $v1, 2
/* 0C32C8 7F08E798 01034023 */  subu  $t0, $t0, $v1
/* 0C32CC 7F08E79C 00081880 */  sll   $v1, $t0, 2
/* 0C32D0 7F08E7A0 00036023 */  negu  $t4, $v1
/* 0C32D4 7F08E7A4 004C2821 */  addu  $a1, $v0, $t4
/* 0C32D8 7F08E7A8 00432021 */  addu  $a0, $v0, $v1
/* 0C32DC 7F08E7AC 24840564 */  addiu $a0, $a0, 0x564
/* 0C32E0 7F08E7B0 0FC16B80 */  jal   sub_GAME_7F05AE00
/* 0C32E4 7F08E7B4 24A50570 */   addiu $a1, $a1, 0x570
/* 0C32E8 7F08E7B8 0FC227B5 */  jal   get_BONDdata_bondfadefracnew
/* 0C32EC 7F08E7BC 00000000 */   nop   
/* 0C32F0 7F08E7C0 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C32F4 7F08E7C4 44813000 */  mtc1  $at, $f6
/* 0C32F8 7F08E7C8 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0C32FC 7F08E7CC 44814000 */  mtc1  $at, $f8
/* 0C3300 7F08E7D0 C7A400D0 */  lwc1  $f4, 0xd0($sp)
/* 0C3304 7F08E7D4 46004402 */  mul.s $f16, $f8, $f0
/* 0C3308 7F08E7D8 46103480 */  add.s $f18, $f6, $f16
/* 0C330C 7F08E7DC 46122282 */  mul.s $f10, $f4, $f18
/* 0C3310 7F08E7E0 0FC227B5 */  jal   get_BONDdata_bondfadefracnew
/* 0C3314 7F08E7E4 E7AA00D0 */   swc1  $f10, 0xd0($sp)
/* 0C3318 7F08E7E8 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C331C 7F08E7EC 44814000 */  mtc1  $at, $f8
/* 0C3320 7F08E7F0 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0C3324 7F08E7F4 44813000 */  mtc1  $at, $f6
/* 0C3328 7F08E7F8 C7B200D4 */  lwc1  $f18, 0xd4($sp)
/* 0C332C 7F08E7FC 8E020000 */  lw    $v0, ($s0)
/* 0C3330 7F08E800 46003402 */  mul.s $f16, $f6, $f0
/* 0C3334 7F08E804 27A700C4 */  addiu $a3, $sp, 0xc4
/* 0C3338 7F08E808 46104100 */  add.s $f4, $f8, $f16
/* 0C333C 7F08E80C 46049282 */  mul.s $f10, $f18, $f4
/* 0C3340 7F08E810 E7AA00D4 */  swc1  $f10, 0xd4($sp)
/* 0C3344 7F08E814 8C430594 */  lw    $v1, 0x594($v0)
/* 0C3348 7F08E818 8C460560 */  lw    $a2, 0x560($v0)
/* 0C334C 7F08E81C 00035080 */  sll   $t2, $v1, 2
/* 0C3350 7F08E820 01435023 */  subu  $t2, $t2, $v1
/* 0C3354 7F08E824 000A1880 */  sll   $v1, $t2, 2
/* 0C3358 7F08E828 00036823 */  negu  $t5, $v1
/* 0C335C 7F08E82C 004D2821 */  addu  $a1, $v0, $t5
/* 0C3360 7F08E830 00432021 */  addu  $a0, $v0, $v1
/* 0C3364 7F08E834 2484057C */  addiu $a0, $a0, 0x57c
/* 0C3368 7F08E838 0FC16B80 */  jal   sub_GAME_7F05AE00
/* 0C336C 7F08E83C 24A50588 */   addiu $a1, $a1, 0x588
/* 0C3370 7F08E840 0FC227B5 */  jal   get_BONDdata_bondfadefracnew
/* 0C3374 7F08E844 00000000 */   nop   
/* 0C3378 7F08E848 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C337C 7F08E84C 44813000 */  mtc1  $at, $f6
/* 0C3380 7F08E850 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0C3384 7F08E854 44814000 */  mtc1  $at, $f8
/* 0C3388 7F08E858 C7A400C4 */  lwc1  $f4, 0xc4($sp)
/* 0C338C 7F08E85C 46004402 */  mul.s $f16, $f8, $f0
/* 0C3390 7F08E860 46103480 */  add.s $f18, $f6, $f16
/* 0C3394 7F08E864 46122282 */  mul.s $f10, $f4, $f18
/* 0C3398 7F08E868 0FC227B5 */  jal   get_BONDdata_bondfadefracnew
/* 0C339C 7F08E86C E7AA00C4 */   swc1  $f10, 0xc4($sp)
/* 0C33A0 7F08E870 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 0C33A4 7F08E874 44814000 */  mtc1  $at, $f8
/* 0C33A8 7F08E878 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0C33AC 7F08E87C 44813000 */  mtc1  $at, $f6
/* 0C33B0 7F08E880 C7B200CC */  lwc1  $f18, 0xcc($sp)
/* 0C33B4 7F08E884 46003402 */  mul.s $f16, $f6, $f0
/* 0C33B8 7F08E888 46104100 */  add.s $f4, $f8, $f16
/* 0C33BC 7F08E88C 46049282 */  mul.s $f10, $f18, $f4
/* 0C33C0 7F08E890 E7AA00CC */  swc1  $f10, 0xcc($sp)
.L7F08E894:
/* 0C33C4 7F08E894 0FC23792 */  jal   sub_GAME_7F08DE48
/* 0C33C8 7F08E898 27A400DC */   addiu $a0, $sp, 0xdc
/* 0C33CC 7F08E89C 27A400D0 */  addiu $a0, $sp, 0xd0
/* 0C33D0 7F08E8A0 0FC237D1 */  jal   sub_GAME_7F08DF44
/* 0C33D4 7F08E8A4 27A500C4 */   addiu $a1, $sp, 0xc4
/* 0C33D8 7F08E8A8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C33DC 7F08E8AC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C33E0 7F08E8B0 27BD00E8 */  addiu $sp, $sp, 0xe8
/* 0C33E4 7F08E8B4 03E00008 */  jr    $ra
/* 0C33E8 7F08E8B8 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08E8BC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08E8BC
/* 0C33EC 7F08E8BC 3C058003 */  lui   $a1, %hi(D_80036AD0)
/* 0C33F0 7F08E8C0 24A56AD0 */  addiu $a1, %lo(D_80036AD0) # addiu $a1, $a1, 0x6ad0
/* 0C33F4 7F08E8C4 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 0C33F8 7F08E8C8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C33FC 7F08E8CC AFB00020 */  sw    $s0, 0x20($sp)
/* 0C3400 7F08E8D0 3C108003 */  lui   $s0, %hi(D_80036AD0)
/* 0C3404 7F08E8D4 46046302 */  mul.s $f12, $f12, $f4
/* 0C3408 7F08E8D8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C340C 7F08E8DC 26106AD0 */  addiu $s0, %lo(D_80036AD0) # addiu $s0, $s0, 0x6ad0
/* 0C3410 7F08E8E0 00001025 */  move  $v0, $zero
/* 0C3414 7F08E8E4 24030002 */  li    $v1, 2
.L7F08E8E8:
/* 0C3418 7F08E8E8 C600000C */  lwc1  $f0, 0xc($s0)
/* 0C341C 7F08E8EC C6060014 */  lwc1  $f6, 0x14($s0)
/* 0C3420 7F08E8F0 46060202 */  mul.s $f8, $f0, $f6
/* 0C3424 7F08E8F4 4608603E */  c.le.s $f12, $f8
/* 0C3428 7F08E8F8 00000000 */  nop   
/* 0C342C 7F08E8FC 4500004A */  bc1f  .L7F08EA28
/* 0C3430 7F08E900 3C088008 */   lui   $t0, %hi(pPlayer) 
/* 0C3434 7F08E904 8D08A0B0 */  lw    $t0, %lo(pPlayer)($t0)
/* 0C3438 7F08E908 3C188007 */  lui   $t8, %hi(ptr_animation_table) 
/* 0C343C 7F08E90C 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C3440 7F08E910 8D0404E8 */  lw    $a0, 0x4e8($t0)
/* 0C3444 7F08E914 5044003A */  beql  $v0, $a0, .L7F08EA00
/* 0C3448 7F08E918 46006303 */   div.s $f12, $f12, $f0
/* 0C344C 7F08E91C 44807000 */  mtc1  $zero, $f14
/* 0C3450 7F08E920 0480000F */  bltz  $a0, .L7F08E960
/* 0C3454 7F08E924 00047080 */   sll   $t6, $a0, 2
/* 0C3458 7F08E928 01C47023 */  subu  $t6, $t6, $a0
/* 0C345C 7F08E92C 000E70C0 */  sll   $t6, $t6, 3
/* 0C3460 7F08E930 00AE1821 */  addu  $v1, $a1, $t6
/* 0C3464 7F08E934 C4600004 */  lwc1  $f0, 4($v1)
/* 0C3468 7F08E938 C4720008 */  lwc1  $f18, 8($v1)
/* 0C346C 7F08E93C C50A05C0 */  lwc1  $f10, 0x5c0($t0)
/* 0C3470 7F08E940 C6020004 */  lwc1  $f2, 4($s0)
/* 0C3474 7F08E944 46009101 */  sub.s $f4, $f18, $f0
/* 0C3478 7F08E948 C6060008 */  lwc1  $f6, 8($s0)
/* 0C347C 7F08E94C 46005401 */  sub.s $f16, $f10, $f0
/* 0C3480 7F08E950 46023201 */  sub.s $f8, $f6, $f2
/* 0C3484 7F08E954 46048383 */  div.s $f14, $f16, $f4
/* 0C3488 7F08E958 460E4282 */  mul.s $f10, $f8, $f14
/* 0C348C 7F08E95C 46025380 */  add.s $f14, $f10, $f2
.L7F08E960:
/* 0C3490 7F08E960 44819000 */  mtc1  $at, $f18
/* 0C3494 7F08E964 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0C3498 7F08E968 810605BC */  lb    $a2, 0x5bc($t0)
/* 0C349C 7F08E96C 44818000 */  mtc1  $at, $f16
/* 0C34A0 7F08E970 8E0F0000 */  lw    $t7, ($s0)
/* 0C34A4 7F08E974 8F189538 */  lw    $t8, %lo(ptr_animation_table)($t8)
/* 0C34A8 7F08E978 44077000 */  mfc1  $a3, $f14
/* 0C34AC 7F08E97C E7AC0030 */  swc1  $f12, 0x30($sp)
/* 0C34B0 7F08E980 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0C34B4 7F08E984 25040598 */  addiu $a0, $t0, 0x598
/* 0C34B8 7F08E988 E7B20010 */  swc1  $f18, 0x10($sp)
/* 0C34BC 7F08E98C E7B00014 */  swc1  $f16, 0x14($sp)
/* 0C34C0 7F08E990 0FC1BF2A */  jal   sub_GAME_7F06FCA8
/* 0C34C4 7F08E994 01F82821 */   addu  $a1, $t7, $t8
/* 0C34C8 7F08E998 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C34CC 7F08E99C 8C84A0B0 */  lw    $a0, %lo(pPlayer)($a0)
/* 0C34D0 7F08E9A0 8E050004 */  lw    $a1, 4($s0)
/* 0C34D4 7F08E9A4 24060000 */  li    $a2, 0
/* 0C34D8 7F08E9A8 0FC1BF73 */  jal   sub_GAME_7F06FDCC
/* 0C34DC 7F08E9AC 24840598 */   addiu $a0, $a0, 0x598
/* 0C34E0 7F08E9B0 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C34E4 7F08E9B4 8C84A0B0 */  lw    $a0, %lo(pPlayer)($a0)
/* 0C34E8 7F08E9B8 8E050008 */  lw    $a1, 8($s0)
/* 0C34EC 7F08E9BC 0FC1BF7A */  jal   sub_GAME_7F06FDE8
/* 0C34F0 7F08E9C0 24840598 */   addiu $a0, $a0, 0x598
/* 0C34F4 7F08E9C4 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C34F8 7F08E9C8 8C84A0B0 */  lw    $a0, %lo(pPlayer)($a0)
/* 0C34FC 7F08E9CC 3C057F09 */  lui   $a1, %hi(sub_GAME_7F08DBB0) # $a1, 0x7f09
/* 0C3500 7F08E9D0 24A5DBB0 */  addiu $a1, %lo(sub_GAME_7F08DBB0) # addiu $a1, $a1, -0x2450
/* 0C3504 7F08E9D4 0FC1BF8F */  jal   sub_GAME_7F06FE3C
/* 0C3508 7F08E9D8 24840598 */   addiu $a0, $a0, 0x598
/* 0C350C 7F08E9DC 3C198008 */  lui   $t9, %hi(pPlayer) 
/* 0C3510 7F08E9E0 8FA2002C */  lw    $v0, 0x2c($sp)
/* 0C3514 7F08E9E4 8F39A0B0 */  lw    $t9, %lo(pPlayer)($t9)
/* 0C3518 7F08E9E8 C7AC0030 */  lwc1  $f12, 0x30($sp)
/* 0C351C 7F08E9EC 3C088008 */  lui   $t0, %hi(pPlayer) 
/* 0C3520 7F08E9F0 AF2204E8 */  sw    $v0, 0x4e8($t9)
/* 0C3524 7F08E9F4 8D08A0B0 */  lw    $t0, %lo(pPlayer)($t0)
/* 0C3528 7F08E9F8 C600000C */  lwc1  $f0, 0xc($s0)
/* 0C352C 7F08E9FC 46006303 */  div.s $f12, $f12, $f0
.L7F08EA00:
/* 0C3530 7F08EA00 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C3534 7F08EA04 44812000 */  mtc1  $at, $f4
/* 0C3538 7F08EA08 25040598 */  addiu $a0, $t0, 0x598
/* 0C353C 7F08EA0C 24060000 */  li    $a2, 0
/* 0C3540 7F08EA10 46046182 */  mul.s $f6, $f12, $f4
/* 0C3544 7F08EA14 44053000 */  mfc1  $a1, $f6
/* 0C3548 7F08EA18 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 0C354C 7F08EA1C 00000000 */   nop   
/* 0C3550 7F08EA20 10000005 */  b     .L7F08EA38
/* 0C3554 7F08EA24 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F08EA28:
/* 0C3558 7F08EA28 24420001 */  addiu $v0, $v0, 1
/* 0C355C 7F08EA2C 1443FFAE */  bne   $v0, $v1, .L7F08E8E8
/* 0C3560 7F08EA30 26100018 */   addiu $s0, $s0, 0x18
/* 0C3564 7F08EA34 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F08EA38:
/* 0C3568 7F08EA38 8FB00020 */  lw    $s0, 0x20($sp)
/* 0C356C 7F08EA3C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C3570 7F08EA40 03E00008 */  jr    $ra
/* 0C3574 7F08EA44 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EA48(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EA48
/* 0C3578 7F08EA48 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C357C 7F08EA4C 44877000 */  mtc1  $a3, $f14
/* 0C3580 7F08EA50 44812000 */  mtc1  $at, $f4
/* 0C3584 7F08EA54 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C3588 7F08EA58 AFA50024 */  sw    $a1, 0x24($sp)
/* 0C358C 7F08EA5C 46047182 */  mul.s $f6, $f14, $f4
/* 0C3590 7F08EA60 44866000 */  mtc1  $a2, $f12
/* 0C3594 7F08EA64 00802825 */  move  $a1, $a0
/* 0C3598 7F08EA68 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C359C 7F08EA6C 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C35A0 7F08EA70 3C014140 */  li    $at, 0x41400000 # 12.000000
/* 0C35A4 7F08EA74 44814000 */  mtc1  $at, $f8
/* 0C35A8 7F08EA78 8C84A0B0 */  lw    $a0, %lo(pPlayer)($a0)
/* 0C35AC 7F08EA7C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C35B0 7F08EA80 44076000 */  mfc1  $a3, $f12
/* 0C35B4 7F08EA84 8FA60024 */  lw    $a2, 0x24($sp)
/* 0C35B8 7F08EA88 E7A60010 */  swc1  $f6, 0x10($sp)
/* 0C35BC 7F08EA8C 24840598 */  addiu $a0, $a0, 0x598
/* 0C35C0 7F08EA90 0FC1BF2A */  jal   sub_GAME_7F06FCA8
/* 0C35C4 7F08EA94 E7A80014 */   swc1  $f8, 0x14($sp)
/* 0C35C8 7F08EA98 3C0F8008 */  lui   $t7, %hi(pPlayer) 
/* 0C35CC 7F08EA9C 8DEFA0B0 */  lw    $t7, %lo(pPlayer)($t7)
/* 0C35D0 7F08EAA0 240EFFFF */  li    $t6, -1
/* 0C35D4 7F08EAA4 ADEE04E8 */  sw    $t6, 0x4e8($t7)
/* 0C35D8 7F08EAA8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C35DC 7F08EAAC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C35E0 7F08EAB0 03E00008 */  jr    $ra
/* 0C35E4 7F08EAB4 00000000 */   nop   
)
#endif






#ifdef NONMATCHING
void sub_GAME_7F08EAB8(f32 param_1)
{
    sub_GAME_7F06FE4C(pPlayer->field_598, param_1 * 0.5f, 0);
    return;
}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EAB8
/* 0C35E8 7F08EAB8 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0C35EC 7F08EABC 44812000 */  mtc1  $at, $f4
/* 0C35F0 7F08EAC0 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C35F4 7F08EAC4 8C84A0B0 */  lw    $a0, %lo(pPlayer)($a0)
/* 0C35F8 7F08EAC8 46046182 */  mul.s $f6, $f12, $f4
/* 0C35FC 7F08EACC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0C3600 7F08EAD0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C3604 7F08EAD4 24060000 */  li    $a2, 0
/* 0C3608 7F08EAD8 24840598 */  addiu $a0, $a0, 0x598
/* 0C360C 7F08EADC 44053000 */  mfc1  $a1, $f6
/* 0C3610 7F08EAE0 0FC1BF93 */  jal   sub_GAME_7F06FE4C
/* 0C3614 7F08EAE4 00000000 */   nop   
/* 0C3618 7F08EAE8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C361C 7F08EAEC 27BD0018 */  addiu $sp, $sp, 0x18
/* 0C3620 7F08EAF0 03E00008 */  jr    $ra
/* 0C3624 7F08EAF4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EAF8(void) {

}
#else
GLOBAL_ASM(
.late_rodata
glabel D_80055338
.word 0x3c4cccce /*0.012500001*/
glabel D_8005533C
.word 0x3b888889 /*0.0041666669*/
.text
glabel sub_GAME_7F08EAF8
/* 0C3628 7F08EAF8 3C0E8008 */  lui   $t6, %hi(pPlayer) 
/* 0C362C 7F08EAFC 8DCEA0B0 */  lw    $t6, %lo(pPlayer)($t6)
/* 0C3630 7F08EB00 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C3634 7F08EB04 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C3638 7F08EB08 8DCF04E8 */  lw    $t7, 0x4e8($t6)
/* 0C363C 7F08EB0C 05E2002B */  bltzl $t7, .L7F08EBBC
/* 0C3640 7F08EB10 44800000 */   mtc1  $zero, $f0
/* 0C3644 7F08EB14 0FC227B5 */  jal   get_BONDdata_bondfadefracnew
/* 0C3648 7F08EB18 00000000 */   nop   
/* 0C364C 7F08EB1C 3C018005 */  lui   $at, %hi(D_80055338)
/* 0C3650 7F08EB20 C4245338 */  lwc1  $f4, %lo(D_80055338)($at)
/* 0C3654 7F08EB24 3C018005 */  lui   $at, %hi(D_8005533C)
/* 0C3658 7F08EB28 C428533C */  lwc1  $f8, %lo(D_8005533C)($at)
/* 0C365C 7F08EB2C 46040182 */  mul.s $f6, $f0, $f4
/* 0C3660 7F08EB30 3C048008 */  lui   $a0, %hi(pPlayer)
/* 0C3664 7F08EB34 8C84A0B0 */  lw    $a0, %lo(pPlayer)($a0)
/* 0C3668 7F08EB38 24840598 */  addiu $a0, $a0, 0x598
/* 0C366C 7F08EB3C 46083080 */  add.s $f2, $f6, $f8
/* 0C3670 7F08EB40 0FC1BD86 */  jal   sub_GAME_7F06F618
/* 0C3674 7F08EB44 E7A2001C */   swc1  $f2, 0x1c($sp)
/* 0C3678 7F08EB48 44805000 */  mtc1  $zero, $f10
/* 0C367C 7F08EB4C C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 0C3680 7F08EB50 3C188008 */  lui   $t8, %hi(pPlayer) 
/* 0C3684 7F08EB54 4600503C */  c.lt.s $f10, $f0
/* 0C3688 7F08EB58 00000000 */  nop   
/* 0C368C 7F08EB5C 45000014 */  bc1f  .L7F08EBB0
/* 0C3690 7F08EB60 00000000 */   nop   
/* 0C3694 7F08EB64 8F18A0B0 */  lw    $t8, %lo(pPlayer)($t8)
/* 0C3698 7F08EB68 3C098003 */  lui   $t1, %hi(D_80036AD0) 
/* 0C369C 7F08EB6C 25296AD0 */  addiu $t1, %lo(D_80036AD0) # addiu $t1, $t1, 0x6ad0
/* 0C36A0 7F08EB70 8F1904E8 */  lw    $t9, 0x4e8($t8)
/* 0C36A4 7F08EB74 00194080 */  sll   $t0, $t9, 2
/* 0C36A8 7F08EB78 01194023 */  subu  $t0, $t0, $t9
/* 0C36AC 7F08EB7C 000840C0 */  sll   $t0, $t0, 3
/* 0C36B0 7F08EB80 01091021 */  addu  $v0, $t0, $t1
/* 0C36B4 7F08EB84 C4500008 */  lwc1  $f16, 8($v0)
/* 0C36B8 7F08EB88 C4520004 */  lwc1  $f18, 4($v0)
/* 0C36BC 7F08EB8C 46128101 */  sub.s $f4, $f16, $f18
/* 0C36C0 7F08EB90 46040303 */  div.s $f12, $f0, $f4
/* 0C36C4 7F08EB94 4602603C */  c.lt.s $f12, $f2
/* 0C36C8 7F08EB98 00000000 */  nop   
/* 0C36CC 7F08EB9C 45000002 */  bc1f  .L7F08EBA8
/* 0C36D0 7F08EBA0 00000000 */   nop   
/* 0C36D4 7F08EBA4 46001306 */  mov.s $f12, $f2
.L7F08EBA8:
/* 0C36D8 7F08EBA8 10000005 */  b     .L7F08EBC0
/* 0C36DC 7F08EBAC 46006006 */   mov.s $f0, $f12
.L7F08EBB0:
/* 0C36E0 7F08EBB0 10000003 */  b     .L7F08EBC0
/* 0C36E4 7F08EBB4 46001006 */   mov.s $f0, $f2
/* 0C36E8 7F08EBB8 44800000 */  mtc1  $zero, $f0
.L7F08EBBC:
/* 0C36EC 7F08EBBC 00000000 */  nop   
.L7F08EBC0:
/* 0C36F0 7F08EBC0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C36F4 7F08EBC4 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C36F8 7F08EBC8 03E00008 */  jr    $ra
/* 0C36FC 7F08EBCC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EBD0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EBD0
/* 0C3700 7F08EBD0 3C028007 */  lui   $v0, %hi(ptr_setup_path_tbl)
/* 0C3704 7F08EBD4 8C425D00 */  lw    $v0, %lo(ptr_setup_path_tbl)($v0)
/* 0C3708 7F08EBD8 27BDFFF0 */  addiu $sp, $sp, -0x10
/* 0C370C 7F08EBDC F7B40008 */  sdc1  $f20, 8($sp)
/* 0C3710 7F08EBE0 AFA50014 */  sw    $a1, 0x14($sp)
/* 0C3714 7F08EBE4 00803825 */  move  $a3, $a0
/* 0C3718 7F08EBE8 10400024 */  beqz  $v0, .L7F08EC7C
/* 0C371C 7F08EBEC 00001825 */   move  $v1, $zero
/* 0C3720 7F08EBF0 8C4E0000 */  lw    $t6, ($v0)
/* 0C3724 7F08EBF4 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0C3728 7F08EBF8 44810000 */  mtc1  $at, $f0
/* 0C372C 7F08EBFC 05C0001F */  bltz  $t6, .L7F08EC7C
/* 0C3730 7F08EC00 00402025 */   move  $a0, $v0
/* 0C3734 7F08EC04 3C068007 */  lui   $a2, %hi(ptr_0xxxpresets)
/* 0C3738 7F08EC08 C4EC0008 */  lwc1  $f12, 8($a3)
/* 0C373C 7F08EC0C C4F00000 */  lwc1  $f16, ($a3)
/* 0C3740 7F08EC10 4480A000 */  mtc1  $zero, $f20
/* 0C3744 7F08EC14 2407002C */  li    $a3, 44
/* 0C3748 7F08EC18 8CC65D18 */  lw    $a2, %lo(ptr_0xxxpresets)($a2)
/* 0C374C 7F08EC1C 8C450000 */  lw    $a1, ($v0)
.L7F08EC20:
/* 0C3750 7F08EC20 00A70019 */  multu $a1, $a3
/* 0C3754 7F08EC24 4614003C */  c.lt.s $f0, $f20
/* 0C3758 7F08EC28 00007812 */  mflo  $t7
/* 0C375C 7F08EC2C 01E61021 */  addu  $v0, $t7, $a2
/* 0C3760 7F08EC30 C4440008 */  lwc1  $f4, 8($v0)
/* 0C3764 7F08EC34 C4460000 */  lwc1  $f6, ($v0)
/* 0C3768 7F08EC38 46046381 */  sub.s $f14, $f12, $f4
/* 0C376C 7F08EC3C 46068481 */  sub.s $f18, $f16, $f6
/* 0C3770 7F08EC40 460E7202 */  mul.s $f8, $f14, $f14
/* 0C3774 7F08EC44 00000000 */  nop   
/* 0C3778 7F08EC48 46129282 */  mul.s $f10, $f18, $f18
/* 0C377C 7F08EC4C 45010005 */  bc1t  .L7F08EC64
/* 0C3780 7F08EC50 460A4080 */   add.s $f2, $f8, $f10
/* 0C3784 7F08EC54 4600103C */  c.lt.s $f2, $f0
/* 0C3788 7F08EC58 00000000 */  nop   
/* 0C378C 7F08EC5C 45020004 */  bc1fl .L7F08EC70
/* 0C3790 7F08EC60 8C850010 */   lw    $a1, 0x10($a0)
.L7F08EC64:
/* 0C3794 7F08EC64 46001006 */  mov.s $f0, $f2
/* 0C3798 7F08EC68 00801825 */  move  $v1, $a0
/* 0C379C 7F08EC6C 8C850010 */  lw    $a1, 0x10($a0)
.L7F08EC70:
/* 0C37A0 7F08EC70 24840010 */  addiu $a0, $a0, 0x10
/* 0C37A4 7F08EC74 04A1FFEA */  bgez  $a1, .L7F08EC20
/* 0C37A8 7F08EC78 00000000 */   nop   
.L7F08EC7C:
/* 0C37AC 7F08EC7C D7B40008 */  ldc1  $f20, 8($sp)
/* 0C37B0 7F08EC80 27BD0010 */  addiu $sp, $sp, 0x10
/* 0C37B4 7F08EC84 03E00008 */  jr    $ra
/* 0C37B8 7F08EC88 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EC8C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EC8C
/* 0C37BC 7F08EC8C AFA50004 */  sw    $a1, 4($sp)
/* 0C37C0 7F08EC90 8CC20004 */  lw    $v0, 4($a2)
/* 0C37C4 7F08EC94 00803825 */  move  $a3, $a0
/* 0C37C8 7F08EC98 00C01825 */  move  $v1, $a2
/* 0C37CC 7F08EC9C 1040002E */  beqz  $v0, .L7F08ED58
/* 0C37D0 7F08ECA0 00000000 */   nop   
/* 0C37D4 7F08ECA4 8CCE0000 */  lw    $t6, ($a2)
/* 0C37D8 7F08ECA8 240A002C */  li    $t2, 44
/* 0C37DC 7F08ECAC 3C0B8007 */  lui   $t3, %hi(ptr_setup_path_tbl) 
/* 0C37E0 7F08ECB0 01CA0019 */  multu $t6, $t2
/* 0C37E4 7F08ECB4 256B5D00 */  addiu $t3, %lo(ptr_setup_path_tbl) # addiu $t3, $t3, 0x5d00
/* 0C37E8 7F08ECB8 8D650018 */  lw    $a1, 0x18($t3)
/* 0C37EC 7F08ECBC C4E20008 */  lwc1  $f2, 8($a3)
/* 0C37F0 7F08ECC0 C4EE0000 */  lwc1  $f14, ($a3)
/* 0C37F4 7F08ECC4 8C490000 */  lw    $t1, ($v0)
/* 0C37F8 7F08ECC8 8D680000 */  lw    $t0, ($t3)
/* 0C37FC 7F08ECCC 00007812 */  mflo  $t7
/* 0C3800 7F08ECD0 01E52021 */  addu  $a0, $t7, $a1
/* 0C3804 7F08ECD4 C4840008 */  lwc1  $f4, 8($a0)
/* 0C3808 7F08ECD8 C4860000 */  lwc1  $f6, ($a0)
/* 0C380C 7F08ECDC 46041301 */  sub.s $f12, $f2, $f4
/* 0C3810 7F08ECE0 46067401 */  sub.s $f16, $f14, $f6
/* 0C3814 7F08ECE4 460C6202 */  mul.s $f8, $f12, $f12
/* 0C3818 7F08ECE8 00000000 */  nop   
/* 0C381C 7F08ECEC 46108282 */  mul.s $f10, $f16, $f16
/* 0C3820 7F08ECF0 05200019 */  bltz  $t1, .L7F08ED58
/* 0C3824 7F08ECF4 460A4000 */   add.s $f0, $f8, $f10
/* 0C3828 7F08ECF8 0009C100 */  sll   $t8, $t1, 4
.L7F08ECFC:
/* 0C382C 7F08ECFC 03083021 */  addu  $a2, $t8, $t0
/* 0C3830 7F08ED00 8CD90000 */  lw    $t9, ($a2)
/* 0C3834 7F08ED04 032A0019 */  multu $t9, $t2
/* 0C3838 7F08ED08 00006012 */  mflo  $t4
/* 0C383C 7F08ED0C 01852021 */  addu  $a0, $t4, $a1
/* 0C3840 7F08ED10 C4840008 */  lwc1  $f4, 8($a0)
/* 0C3844 7F08ED14 C4860000 */  lwc1  $f6, ($a0)
/* 0C3848 7F08ED18 46041301 */  sub.s $f12, $f2, $f4
/* 0C384C 7F08ED1C 46067401 */  sub.s $f16, $f14, $f6
/* 0C3850 7F08ED20 460C6202 */  mul.s $f8, $f12, $f12
/* 0C3854 7F08ED24 00000000 */  nop   
/* 0C3858 7F08ED28 46108282 */  mul.s $f10, $f16, $f16
/* 0C385C 7F08ED2C 460A4480 */  add.s $f18, $f8, $f10
/* 0C3860 7F08ED30 4600903C */  c.lt.s $f18, $f0
/* 0C3864 7F08ED34 00000000 */  nop   
/* 0C3868 7F08ED38 45000003 */  bc1f  .L7F08ED48
/* 0C386C 7F08ED3C 00000000 */   nop   
/* 0C3870 7F08ED40 46009006 */  mov.s $f0, $f18
/* 0C3874 7F08ED44 00C01825 */  move  $v1, $a2
.L7F08ED48:
/* 0C3878 7F08ED48 8C490004 */  lw    $t1, 4($v0)
/* 0C387C 7F08ED4C 24420004 */  addiu $v0, $v0, 4
/* 0C3880 7F08ED50 0523FFEA */  bgezl $t1, .L7F08ECFC
/* 0C3884 7F08ED54 0009C100 */   sll   $t8, $t1, 4
.L7F08ED58:
/* 0C3888 7F08ED58 03E00008 */  jr    $ra
/* 0C388C 7F08ED5C 00601025 */   move  $v0, $v1
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08ED60(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08ED60
/* 0C3890 7F08ED60 8C830000 */  lw    $v1, ($a0)
/* 0C3894 7F08ED64 3C028007 */  lui   $v0, %hi(ptr_setup_path_link)
/* 0C3898 7F08ED68 00A03025 */  move  $a2, $a1
/* 0C389C 7F08ED6C 0460000E */  bltz  $v1, .L7F08EDA8
/* 0C38A0 7F08ED70 8C425D04 */   lw    $v0, %lo(ptr_setup_path_link)($v0)
/* 0C38A4 7F08ED74 2407000C */  li    $a3, 12
.L7F08ED78:
/* 0C38A8 7F08ED78 00670019 */  multu $v1, $a3
/* 0C38AC 7F08ED7C 00007012 */  mflo  $t6
/* 0C38B0 7F08ED80 01C22821 */  addu  $a1, $t6, $v0
/* 0C38B4 7F08ED84 8CAF0008 */  lw    $t7, 8($a1)
/* 0C38B8 7F08ED88 54CF0004 */  bnel  $a2, $t7, .L7F08ED9C
/* 0C38BC 7F08ED8C 8C830004 */   lw    $v1, 4($a0)
/* 0C38C0 7F08ED90 03E00008 */  jr    $ra
/* 0C38C4 7F08ED94 00A01025 */   move  $v0, $a1

/* 0C38C8 7F08ED98 8C830004 */  lw    $v1, 4($a0)
.L7F08ED9C:
/* 0C38CC 7F08ED9C 24840004 */  addiu $a0, $a0, 4
/* 0C38D0 7F08EDA0 0461FFF5 */  bgez  $v1, .L7F08ED78
/* 0C38D4 7F08EDA4 00000000 */   nop   
.L7F08EDA8:
/* 0C38D8 7F08EDA8 00001025 */  move  $v0, $zero
/* 0C38DC 7F08EDAC 03E00008 */  jr    $ra
/* 0C38E0 7F08EDB0 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EDB4(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EDB4
/* 0C38E4 7F08EDB4 8C830000 */  lw    $v1, ($a0)
/* 0C38E8 7F08EDB8 3C028007 */  lui   $v0, %hi(ptr_setup_path_link)
/* 0C38EC 7F08EDBC 00A03025 */  move  $a2, $a1
/* 0C38F0 7F08EDC0 0460000D */  bltz  $v1, .L7F08EDF8
/* 0C38F4 7F08EDC4 8C425D04 */   lw    $v0, %lo(ptr_setup_path_link)($v0)
/* 0C38F8 7F08EDC8 2407000C */  li    $a3, 12
.L7F08EDCC:
/* 0C38FC 7F08EDCC 00670019 */  multu $v1, $a3
/* 0C3900 7F08EDD0 00007012 */  mflo  $t6
/* 0C3904 7F08EDD4 01C22821 */  addu  $a1, $t6, $v0
/* 0C3908 7F08EDD8 8CAF0008 */  lw    $t7, 8($a1)
/* 0C390C 7F08EDDC 05E30003 */  bgezl $t7, .L7F08EDEC
/* 0C3910 7F08EDE0 8C830004 */   lw    $v1, 4($a0)
/* 0C3914 7F08EDE4 ACA60008 */  sw    $a2, 8($a1)
/* 0C3918 7F08EDE8 8C830004 */  lw    $v1, 4($a0)
.L7F08EDEC:
/* 0C391C 7F08EDEC 24840004 */  addiu $a0, $a0, 4
/* 0C3920 7F08EDF0 0461FFF6 */  bgez  $v1, .L7F08EDCC
/* 0C3924 7F08EDF4 00000000 */   nop   
.L7F08EDF8:
/* 0C3928 7F08EDF8 03E00008 */  jr    $ra
/* 0C392C 7F08EDFC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EE00(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EE00
/* 0C3930 7F08EE00 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C3934 7F08EE04 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C3938 7F08EE08 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C393C 7F08EE0C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C3940 7F08EE10 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C3944 7F08EE14 8C860000 */  lw    $a2, ($a0)
/* 0C3948 7F08EE18 00808025 */  move  $s0, $a0
/* 0C394C 7F08EE1C 00A08825 */  move  $s1, $a1
/* 0C3950 7F08EE20 10C0000C */  beqz  $a2, .L7F08EE54
/* 0C3954 7F08EE24 00009025 */   move  $s2, $zero
/* 0C3958 7F08EE28 8E0E0008 */  lw    $t6, 8($s0)
.L7F08EE2C:
/* 0C395C 7F08EE2C 00C02025 */  move  $a0, $a2
/* 0C3960 7F08EE30 26250001 */  addiu $a1, $s1, 1
/* 0C3964 7F08EE34 562E0004 */  bnel  $s1, $t6, .L7F08EE48
/* 0C3968 7F08EE38 8E06000C */   lw    $a2, 0xc($s0)
/* 0C396C 7F08EE3C 0FC23B6D */  jal   sub_GAME_7F08EDB4
/* 0C3970 7F08EE40 24120001 */   li    $s2, 1
/* 0C3974 7F08EE44 8E06000C */  lw    $a2, 0xc($s0)
.L7F08EE48:
/* 0C3978 7F08EE48 2610000C */  addiu $s0, $s0, 0xc
/* 0C397C 7F08EE4C 54C0FFF7 */  bnezl $a2, .L7F08EE2C
/* 0C3980 7F08EE50 8E0E0008 */   lw    $t6, 8($s0)
.L7F08EE54:
/* 0C3984 7F08EE54 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C3988 7F08EE58 02401025 */  move  $v0, $s2
/* 0C398C 7F08EE5C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C3990 7F08EE60 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C3994 7F08EE64 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C3998 7F08EE68 03E00008 */  jr    $ra
/* 0C399C 7F08EE6C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EE70(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EE70
/* 0C39A0 7F08EE70 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C39A4 7F08EE74 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C39A8 7F08EE78 AFB30020 */  sw    $s3, 0x20($sp)
/* 0C39AC 7F08EE7C AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C39B0 7F08EE80 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C39B4 7F08EE84 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C39B8 7F08EE88 8CCE0000 */  lw    $t6, ($a2)
/* 0C39BC 7F08EE8C 00C08825 */  move  $s1, $a2
/* 0C39C0 7F08EE90 00E09025 */  move  $s2, $a3
/* 0C39C4 7F08EE94 00A09825 */  move  $s3, $a1
/* 0C39C8 7F08EE98 24080001 */  li    $t0, 1
/* 0C39CC 7F08EE9C 11C00007 */  beqz  $t6, .L7F08EEBC
/* 0C39D0 7F08EEA0 00C01025 */   move  $v0, $a2
/* 0C39D4 7F08EEA4 2403FFFF */  li    $v1, -1
/* 0C39D8 7F08EEA8 8C4F000C */  lw    $t7, 0xc($v0)
.L7F08EEAC:
/* 0C39DC 7F08EEAC 2442000C */  addiu $v0, $v0, 0xc
/* 0C39E0 7F08EEB0 AC43FFFC */  sw    $v1, -4($v0)
/* 0C39E4 7F08EEB4 55E0FFFD */  bnezl $t7, .L7F08EEAC
/* 0C39E8 7F08EEB8 8C4F000C */   lw    $t7, 0xc($v0)
.L7F08EEBC:
/* 0C39EC 7F08EEBC AC800008 */  sw    $zero, 8($a0)
/* 0C39F0 7F08EEC0 16400003 */  bnez  $s2, .L7F08EED0
/* 0C39F4 7F08EEC4 00008025 */   move  $s0, $zero
/* 0C39F8 7F08EEC8 8E780008 */  lw    $t8, 8($s3)
/* 0C39FC 7F08EECC 0701000B */  bgez  $t8, .L7F08EEFC
.L7F08EED0:
/* 0C3A00 7F08EED0 02202025 */   move  $a0, $s1
.L7F08EED4:
/* 0C3A04 7F08EED4 0FC23B80 */  jal   sub_GAME_7F08EE00
/* 0C3A08 7F08EED8 02002825 */   move  $a1, $s0
/* 0C3A0C 7F08EEDC 26100001 */  addiu $s0, $s0, 1
/* 0C3A10 7F08EEE0 16400004 */  bnez  $s2, .L7F08EEF4
/* 0C3A14 7F08EEE4 00404025 */   move  $t0, $v0
/* 0C3A18 7F08EEE8 8E790008 */  lw    $t9, 8($s3)
/* 0C3A1C 7F08EEEC 07230004 */  bgezl $t9, .L7F08EF00
/* 0C3A20 7F08EEF0 8FBF0024 */   lw    $ra, 0x24($sp)
.L7F08EEF4:
/* 0C3A24 7F08EEF4 5500FFF7 */  bnezl $t0, .L7F08EED4
/* 0C3A28 7F08EEF8 02202025 */   move  $a0, $s1
.L7F08EEFC:
/* 0C3A2C 7F08EEFC 8FBF0024 */  lw    $ra, 0x24($sp)
.L7F08EF00:
/* 0C3A30 7F08EF00 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C3A34 7F08EF04 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C3A38 7F08EF08 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C3A3C 7F08EF0C 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C3A40 7F08EF10 27BD0028 */  addiu $sp, $sp, 0x28
/* 0C3A44 7F08EF14 03E00008 */  jr    $ra
/* 0C3A48 7F08EF18 01001025 */   move  $v0, $t0
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EF1C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EF1C
/* 0C3A4C 7F08EF1C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3A50 7F08EF20 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C3A54 7F08EF24 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C3A58 7F08EF28 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C3A5C 7F08EF2C AFA50034 */  sw    $a1, 0x34($sp)
/* 0C3A60 7F08EF30 0FC23B9C */  jal   sub_GAME_7F08EE70
/* 0C3A64 7F08EF34 00003825 */   move  $a3, $zero
/* 0C3A68 7F08EF38 8FA50034 */  lw    $a1, 0x34($sp)
/* 0C3A6C 7F08EF3C 10400012 */  beqz  $v0, .L7F08EF88
/* 0C3A70 7F08EF40 AFA20024 */   sw    $v0, 0x24($sp)
/* 0C3A74 7F08EF44 8CB00008 */  lw    $s0, 8($a1)
/* 0C3A78 7F08EF48 00A08825 */  move  $s1, $a1
/* 0C3A7C 7F08EF4C 2610FFFF */  addiu $s0, $s0, -1
/* 0C3A80 7F08EF50 0602000B */  bltzl $s0, .L7F08EF80
/* 0C3A84 7F08EF54 8E380008 */   lw    $t8, 8($s1)
.L7F08EF58:
/* 0C3A88 7F08EF58 8E2E0008 */  lw    $t6, 8($s1)
/* 0C3A8C 7F08EF5C 8E240000 */  lw    $a0, ($s1)
/* 0C3A90 7F08EF60 02002825 */  move  $a1, $s0
/* 0C3A94 7F08EF64 25CF2710 */  addiu $t7, $t6, 0x2710
/* 0C3A98 7F08EF68 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C3A9C 7F08EF6C AE2F0008 */   sw    $t7, 8($s1)
/* 0C3AA0 7F08EF70 2610FFFF */  addiu $s0, $s0, -1
/* 0C3AA4 7F08EF74 0601FFF8 */  bgez  $s0, .L7F08EF58
/* 0C3AA8 7F08EF78 00408825 */   move  $s1, $v0
/* 0C3AAC 7F08EF7C 8E380008 */  lw    $t8, 8($s1)
.L7F08EF80:
/* 0C3AB0 7F08EF80 27192710 */  addiu $t9, $t8, 0x2710
/* 0C3AB4 7F08EF84 AE390008 */  sw    $t9, 8($s1)
.L7F08EF88:
/* 0C3AB8 7F08EF88 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C3ABC 7F08EF8C 8FA20024 */  lw    $v0, 0x24($sp)
/* 0C3AC0 7F08EF90 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C3AC4 7F08EF94 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C3AC8 7F08EF98 03E00008 */  jr    $ra
/* 0C3ACC 7F08EF9C 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08EFA0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08EFA0
/* 0C3AD0 7F08EFA0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3AD4 7F08EFA4 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C3AD8 7F08EFA8 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C3ADC 7F08EFAC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C3AE0 7F08EFB0 28E10002 */  slti  $at, $a3, 2
/* 0C3AE4 7F08EFB4 00E09825 */  move  $s3, $a3
/* 0C3AE8 7F08EFB8 00A0A025 */  move  $s4, $a1
/* 0C3AEC 7F08EFBC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C3AF0 7F08EFC0 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C3AF4 7F08EFC4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C3AF8 7F08EFC8 AFA60038 */  sw    $a2, 0x38($sp)
/* 0C3AFC 7F08EFCC 14200022 */  bnez  $at, .L7F08F058
/* 0C3B00 7F08EFD0 00C08825 */   move  $s1, $a2
/* 0C3B04 7F08EFD4 3C068007 */  lui   $a2, %hi(ptr_setup_path_link)
/* 0C3B08 7F08EFD8 8CC65D04 */  lw    $a2, %lo(ptr_setup_path_link)($a2)
/* 0C3B0C 7F08EFDC 50C0001F */  beql  $a2, $zero, .L7F08F05C
/* 0C3B10 7F08EFE0 AE200000 */   sw    $zero, ($s1)
/* 0C3B14 7F08EFE4 0FC23BC7 */  jal   sub_GAME_7F08EF1C
/* 0C3B18 7F08EFE8 AFA40030 */   sw    $a0, 0x30($sp)
/* 0C3B1C 7F08EFEC 1040001A */  beqz  $v0, .L7F08F058
/* 0C3B20 7F08EFF0 8FA40030 */   lw    $a0, 0x30($sp)
/* 0C3B24 7F08EFF4 8FA20038 */  lw    $v0, 0x38($sp)
/* 0C3B28 7F08EFF8 00809025 */  move  $s2, $a0
/* 0C3B2C 7F08EFFC 2673270F */  addiu $s3, $s3, 0x270f
/* 0C3B30 7F08F000 AC440000 */  sw    $a0, ($v0)
/* 0C3B34 7F08F004 8E8E0008 */  lw    $t6, 8($s4)
/* 0C3B38 7F08F008 24102711 */  li    $s0, 10001
/* 0C3B3C 7F08F00C 24510004 */  addiu $s1, $v0, 4
/* 0C3B40 7F08F010 29C12711 */  slti  $at, $t6, 0x2711
/* 0C3B44 7F08F014 14200010 */  bnez  $at, .L7F08F058
/* 0C3B48 7F08F018 2A612712 */   slti  $at, $s3, 0x2712
/* 0C3B4C 7F08F01C 5420000F */  bnezl $at, .L7F08F05C
/* 0C3B50 7F08F020 AE200000 */   sw    $zero, ($s1)
/* 0C3B54 7F08F024 8E440000 */  lw    $a0, ($s2)
.L7F08F028:
/* 0C3B58 7F08F028 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C3B5C 7F08F02C 02002825 */   move  $a1, $s0
/* 0C3B60 7F08F030 AE220000 */  sw    $v0, ($s1)
/* 0C3B64 7F08F034 8E8F0008 */  lw    $t7, 8($s4)
/* 0C3B68 7F08F038 26100001 */  addiu $s0, $s0, 1
/* 0C3B6C 7F08F03C 00409025 */  move  $s2, $v0
/* 0C3B70 7F08F040 01F0082A */  slt   $at, $t7, $s0
/* 0C3B74 7F08F044 14200004 */  bnez  $at, .L7F08F058
/* 0C3B78 7F08F048 26310004 */   addiu $s1, $s1, 4
/* 0C3B7C 7F08F04C 0213082A */  slt   $at, $s0, $s3
/* 0C3B80 7F08F050 5420FFF5 */  bnezl $at, .L7F08F028
/* 0C3B84 7F08F054 8E440000 */   lw    $a0, ($s2)
.L7F08F058:
/* 0C3B88 7F08F058 AE200000 */  sw    $zero, ($s1)
.L7F08F05C:
/* 0C3B8C 7F08F05C 8FB80038 */  lw    $t8, 0x38($sp)
/* 0C3B90 7F08F060 26310004 */  addiu $s1, $s1, 4
/* 0C3B94 7F08F064 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C3B98 7F08F068 02381023 */  subu  $v0, $s1, $t8
/* 0C3B9C 7F08F06C 0002C883 */  sra   $t9, $v0, 2
/* 0C3BA0 7F08F070 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C3BA4 7F08F074 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C3BA8 7F08F078 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C3BAC 7F08F07C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C3BB0 7F08F080 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C3BB4 7F08F084 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C3BB8 7F08F088 03E00008 */  jr    $ra
/* 0C3BBC 7F08F08C 03201025 */   move  $v0, $t9
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F090(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F090
/* 0C3BC0 7F08F090 8C830000 */  lw    $v1, ($a0)
/* 0C3BC4 7F08F094 3C028007 */  lui   $v0, %hi(ptr_setup_path_tbl)
/* 0C3BC8 7F08F098 00A03825 */  move  $a3, $a1
/* 0C3BCC 7F08F09C 0460000F */  bltz  $v1, .L7F08F0DC
/* 0C3BD0 7F08F0A0 8C425D00 */   lw    $v0, %lo(ptr_setup_path_tbl)($v0)
/* 0C3BD4 7F08F0A4 00037100 */  sll   $t6, $v1, 4
.L7F08F0A8:
/* 0C3BD8 7F08F0A8 01C22821 */  addu  $a1, $t6, $v0
/* 0C3BDC 7F08F0AC 8CAF0008 */  lw    $t7, 8($a1)
/* 0C3BE0 7F08F0B0 54CF0007 */  bnel  $a2, $t7, .L7F08F0D0
/* 0C3BE4 7F08F0B4 8C830004 */   lw    $v1, 4($a0)
/* 0C3BE8 7F08F0B8 8CB8000C */  lw    $t8, 0xc($a1)
/* 0C3BEC 7F08F0BC 54F80004 */  bnel  $a3, $t8, .L7F08F0D0
/* 0C3BF0 7F08F0C0 8C830004 */   lw    $v1, 4($a0)
/* 0C3BF4 7F08F0C4 03E00008 */  jr    $ra
/* 0C3BF8 7F08F0C8 00A01025 */   move  $v0, $a1

/* 0C3BFC 7F08F0CC 8C830004 */  lw    $v1, 4($a0)
.L7F08F0D0:
/* 0C3C00 7F08F0D0 24840004 */  addiu $a0, $a0, 4
/* 0C3C04 7F08F0D4 0463FFF4 */  bgezl $v1, .L7F08F0A8
/* 0C3C08 7F08F0D8 00037100 */   sll   $t6, $v1, 4
.L7F08F0DC:
/* 0C3C0C 7F08F0DC 00001025 */  move  $v0, $zero
/* 0C3C10 7F08F0E0 03E00008 */  jr    $ra
/* 0C3C14 7F08F0E4 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F0E8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F0E8
/* 0C3C18 7F08F0E8 8C830000 */  lw    $v1, ($a0)
/* 0C3C1C 7F08F0EC 3C028007 */  lui   $v0, %hi(ptr_setup_path_tbl)
/* 0C3C20 7F08F0F0 00A03825 */  move  $a3, $a1
/* 0C3C24 7F08F0F4 0460000E */  bltz  $v1, .L7F08F130
/* 0C3C28 7F08F0F8 8C425D00 */   lw    $v0, %lo(ptr_setup_path_tbl)($v0)
/* 0C3C2C 7F08F0FC 00037100 */  sll   $t6, $v1, 4
.L7F08F100:
/* 0C3C30 7F08F100 01C22821 */  addu  $a1, $t6, $v0
/* 0C3C34 7F08F104 8CAF0008 */  lw    $t7, 8($a1)
/* 0C3C38 7F08F108 54CF0006 */  bnel  $a2, $t7, .L7F08F124
/* 0C3C3C 7F08F10C 8C830004 */   lw    $v1, 4($a0)
/* 0C3C40 7F08F110 8CB8000C */  lw    $t8, 0xc($a1)
/* 0C3C44 7F08F114 07030003 */  bgezl $t8, .L7F08F124
/* 0C3C48 7F08F118 8C830004 */   lw    $v1, 4($a0)
/* 0C3C4C 7F08F11C ACA7000C */  sw    $a3, 0xc($a1)
/* 0C3C50 7F08F120 8C830004 */  lw    $v1, 4($a0)
.L7F08F124:
/* 0C3C54 7F08F124 24840004 */  addiu $a0, $a0, 4
/* 0C3C58 7F08F128 0463FFF5 */  bgezl $v1, .L7F08F100
/* 0C3C5C 7F08F12C 00037100 */   sll   $t6, $v1, 4
.L7F08F130:
/* 0C3C60 7F08F130 03E00008 */  jr    $ra
/* 0C3C64 7F08F134 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F138(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F138
/* 0C3C68 7F08F138 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3C6C 7F08F13C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C3C70 7F08F140 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C3C74 7F08F144 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C3C78 7F08F148 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C3C7C 7F08F14C AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C3C80 7F08F150 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C3C84 7F08F154 8C820000 */  lw    $v0, ($a0)
/* 0C3C88 7F08F158 3C138007 */  lui   $s3, %hi(ptr_setup_path_tbl)
/* 0C3C8C 7F08F15C 00808025 */  move  $s0, $a0
/* 0C3C90 7F08F160 00A08825 */  move  $s1, $a1
/* 0C3C94 7F08F164 00C0A025 */  move  $s4, $a2
/* 0C3C98 7F08F168 00009025 */  move  $s2, $zero
/* 0C3C9C 7F08F16C 04400011 */  bltz  $v0, .L7F08F1B4
/* 0C3CA0 7F08F170 8E735D00 */   lw    $s3, %lo(ptr_setup_path_tbl)($s3)
/* 0C3CA4 7F08F174 00027100 */  sll   $t6, $v0, 4
.L7F08F178:
/* 0C3CA8 7F08F178 01D31821 */  addu  $v1, $t6, $s3
/* 0C3CAC 7F08F17C 8C6F000C */  lw    $t7, 0xc($v1)
/* 0C3CB0 7F08F180 562F0009 */  bnel  $s1, $t7, .L7F08F1A8
/* 0C3CB4 7F08F184 8E020004 */   lw    $v0, 4($s0)
/* 0C3CB8 7F08F188 8C640004 */  lw    $a0, 4($v1)
/* 0C3CBC 7F08F18C 26250001 */  addiu $a1, $s1, 1
/* 0C3CC0 7F08F190 02803025 */  move  $a2, $s4
/* 0C3CC4 7F08F194 50800004 */  beql  $a0, $zero, .L7F08F1A8
/* 0C3CC8 7F08F198 8E020004 */   lw    $v0, 4($s0)
/* 0C3CCC 7F08F19C 0FC23C3A */  jal   sub_GAME_7F08F0E8
/* 0C3CD0 7F08F1A0 24120001 */   li    $s2, 1
/* 0C3CD4 7F08F1A4 8E020004 */  lw    $v0, 4($s0)
.L7F08F1A8:
/* 0C3CD8 7F08F1A8 26100004 */  addiu $s0, $s0, 4
/* 0C3CDC 7F08F1AC 0443FFF2 */  bgezl $v0, .L7F08F178
/* 0C3CE0 7F08F1B0 00027100 */   sll   $t6, $v0, 4
.L7F08F1B4:
/* 0C3CE4 7F08F1B4 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C3CE8 7F08F1B8 02401025 */  move  $v0, $s2
/* 0C3CEC 7F08F1BC 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C3CF0 7F08F1C0 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C3CF4 7F08F1C4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C3CF8 7F08F1C8 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C3CFC 7F08F1CC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C3D00 7F08F1D0 03E00008 */  jr    $ra
/* 0C3D04 7F08F1D4 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F1D8(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F1D8
/* 0C3D08 7F08F1D8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3D0C 7F08F1DC AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C3D10 7F08F1E0 AFB50028 */  sw    $s5, 0x28($sp)
/* 0C3D14 7F08F1E4 AFB40024 */  sw    $s4, 0x24($sp)
/* 0C3D18 7F08F1E8 AFB30020 */  sw    $s3, 0x20($sp)
/* 0C3D1C 7F08F1EC AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C3D20 7F08F1F0 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C3D24 7F08F1F4 AFB00014 */  sw    $s0, 0x14($sp)
/* 0C3D28 7F08F1F8 8C8E0008 */  lw    $t6, 8($a0)
/* 0C3D2C 7F08F1FC 2415000C */  li    $s5, 12
/* 0C3D30 7F08F200 3C028007 */  lui   $v0, %hi(ptr_setup_path_tbl)
/* 0C3D34 7F08F204 01D50019 */  multu $t6, $s5
/* 0C3D38 7F08F208 24425D00 */  addiu $v0, %lo(ptr_setup_path_tbl) # addiu $v0, $v0, 0x5d00
/* 0C3D3C 7F08F20C 8C510004 */  lw    $s1, 4($v0)
/* 0C3D40 7F08F210 00809025 */  move  $s2, $a0
/* 0C3D44 7F08F214 00C09825 */  move  $s3, $a2
/* 0C3D48 7F08F218 00A0A025 */  move  $s4, $a1
/* 0C3D4C 7F08F21C 8C480000 */  lw    $t0, ($v0)
/* 0C3D50 7F08F220 2404FFFF */  li    $a0, -1
/* 0C3D54 7F08F224 00008025 */  move  $s0, $zero
/* 0C3D58 7F08F228 00007812 */  mflo  $t7
/* 0C3D5C 7F08F22C 022FC021 */  addu  $t8, $s1, $t7
/* 0C3D60 7F08F230 8F030004 */  lw    $v1, 4($t8)
/* 0C3D64 7F08F234 8C670000 */  lw    $a3, ($v1)
/* 0C3D68 7F08F238 04E00007 */  bltz  $a3, .L7F08F258
/* 0C3D6C 7F08F23C 0007C900 */   sll   $t9, $a3, 4
.L7F08F240:
/* 0C3D70 7F08F240 03281021 */  addu  $v0, $t9, $t0
/* 0C3D74 7F08F244 AC44000C */  sw    $a0, 0xc($v0)
/* 0C3D78 7F08F248 8C670004 */  lw    $a3, 4($v1)
/* 0C3D7C 7F08F24C 24630004 */  addiu $v1, $v1, 4
/* 0C3D80 7F08F250 04E3FFFB */  bgezl $a3, .L7F08F240
/* 0C3D84 7F08F254 0007C900 */   sll   $t9, $a3, 4
.L7F08F258:
/* 0C3D88 7F08F258 16600004 */  bnez  $s3, .L7F08F26C
/* 0C3D8C 7F08F25C AE40000C */   sw    $zero, 0xc($s2)
/* 0C3D90 7F08F260 8E89000C */  lw    $t1, 0xc($s4)
/* 0C3D94 7F08F264 05230011 */  bgezl $t1, .L7F08F2AC
/* 0C3D98 7F08F268 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F08F26C:
/* 0C3D9C 7F08F26C 8E460008 */  lw    $a2, 8($s2)
.L7F08F270:
/* 0C3DA0 7F08F270 02002825 */  move  $a1, $s0
/* 0C3DA4 7F08F274 00D50019 */  multu $a2, $s5
/* 0C3DA8 7F08F278 00005012 */  mflo  $t2
/* 0C3DAC 7F08F27C 022A5821 */  addu  $t3, $s1, $t2
/* 0C3DB0 7F08F280 0FC23C4E */  jal   sub_GAME_7F08F138
/* 0C3DB4 7F08F284 8D640004 */   lw    $a0, 4($t3)
/* 0C3DB8 7F08F288 26100001 */  addiu $s0, $s0, 1
/* 0C3DBC 7F08F28C 16600004 */  bnez  $s3, .L7F08F2A0
/* 0C3DC0 7F08F290 00401825 */   move  $v1, $v0
/* 0C3DC4 7F08F294 8E8C000C */  lw    $t4, 0xc($s4)
/* 0C3DC8 7F08F298 05830004 */  bgezl $t4, .L7F08F2AC
/* 0C3DCC 7F08F29C 8FBF002C */   lw    $ra, 0x2c($sp)
.L7F08F2A0:
/* 0C3DD0 7F08F2A0 5460FFF3 */  bnezl $v1, .L7F08F270
/* 0C3DD4 7F08F2A4 8E460008 */   lw    $a2, 8($s2)
/* 0C3DD8 7F08F2A8 8FBF002C */  lw    $ra, 0x2c($sp)
.L7F08F2AC:
/* 0C3DDC 7F08F2AC 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C3DE0 7F08F2B0 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C3DE4 7F08F2B4 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C3DE8 7F08F2B8 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C3DEC 7F08F2BC 8FB40024 */  lw    $s4, 0x24($sp)
/* 0C3DF0 7F08F2C0 8FB50028 */  lw    $s5, 0x28($sp)
/* 0C3DF4 7F08F2C4 03E00008 */  jr    $ra
/* 0C3DF8 7F08F2C8 27BD0030 */   addiu $sp, $sp, 0x30
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F2CC(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F2CC
/* 0C3DFC 7F08F2CC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C3E00 7F08F2D0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 0C3E04 7F08F2D4 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C3E08 7F08F2D8 00809025 */  move  $s2, $a0
/* 0C3E0C 7F08F2DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C3E10 7F08F2E0 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C3E14 7F08F2E4 AFA5002C */  sw    $a1, 0x2c($sp)
/* 0C3E18 7F08F2E8 0FC23C76 */  jal   sub_GAME_7F08F1D8
/* 0C3E1C 7F08F2EC 00003025 */   move  $a2, $zero
/* 0C3E20 7F08F2F0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0C3E24 7F08F2F4 8E30000C */  lw    $s0, 0xc($s1)
/* 0C3E28 7F08F2F8 2610FFFF */  addiu $s0, $s0, -1
/* 0C3E2C 7F08F2FC 0602000C */  bltzl $s0, .L7F08F330
/* 0C3E30 7F08F300 8E38000C */   lw    $t8, 0xc($s1)
.L7F08F304:
/* 0C3E34 7F08F304 8E2E000C */  lw    $t6, 0xc($s1)
/* 0C3E38 7F08F308 8E240004 */  lw    $a0, 4($s1)
/* 0C3E3C 7F08F30C 02002825 */  move  $a1, $s0
/* 0C3E40 7F08F310 25CF2710 */  addiu $t7, $t6, 0x2710
/* 0C3E44 7F08F314 AE2F000C */  sw    $t7, 0xc($s1)
/* 0C3E48 7F08F318 0FC23C24 */  jal   sub_GAME_7F08F090
/* 0C3E4C 7F08F31C 8E460008 */   lw    $a2, 8($s2)
/* 0C3E50 7F08F320 2610FFFF */  addiu $s0, $s0, -1
/* 0C3E54 7F08F324 0601FFF7 */  bgez  $s0, .L7F08F304
/* 0C3E58 7F08F328 00408825 */   move  $s1, $v0
/* 0C3E5C 7F08F32C 8E38000C */  lw    $t8, 0xc($s1)
.L7F08F330:
/* 0C3E60 7F08F330 27192710 */  addiu $t9, $t8, 0x2710
/* 0C3E64 7F08F334 AE39000C */  sw    $t9, 0xc($s1)
/* 0C3E68 7F08F338 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0C3E6C 7F08F33C 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C3E70 7F08F340 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C3E74 7F08F344 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C3E78 7F08F348 03E00008 */  jr    $ra
/* 0C3E7C 7F08F34C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F350(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F350
/* 0C3E80 7F08F350 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0C3E84 7F08F354 AFB50028 */  sw    $s5, 0x28($sp)
/* 0C3E88 7F08F358 AFB40024 */  sw    $s4, 0x24($sp)
/* 0C3E8C 7F08F35C AFB30020 */  sw    $s3, 0x20($sp)
/* 0C3E90 7F08F360 AFB10018 */  sw    $s1, 0x18($sp)
/* 0C3E94 7F08F364 28E10002 */  slti  $at, $a3, 2
/* 0C3E98 7F08F368 00E09825 */  move  $s3, $a3
/* 0C3E9C 7F08F36C 0080A025 */  move  $s4, $a0
/* 0C3EA0 7F08F370 00A0A825 */  move  $s5, $a1
/* 0C3EA4 7F08F374 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0C3EA8 7F08F378 AFB2001C */  sw    $s2, 0x1c($sp)
/* 0C3EAC 7F08F37C AFB00014 */  sw    $s0, 0x14($sp)
/* 0C3EB0 7F08F380 AFA60038 */  sw    $a2, 0x38($sp)
/* 0C3EB4 7F08F384 1420001D */  bnez  $at, .L7F08F3FC
/* 0C3EB8 7F08F388 00C08825 */   move  $s1, $a2
/* 0C3EBC 7F08F38C 0FC23CB3 */  jal   sub_GAME_7F08F2CC
/* 0C3EC0 7F08F390 00000000 */   nop   
/* 0C3EC4 7F08F394 8FA20038 */  lw    $v0, 0x38($sp)
/* 0C3EC8 7F08F398 02809025 */  move  $s2, $s4
/* 0C3ECC 7F08F39C 2673270F */  addiu $s3, $s3, 0x270f
/* 0C3ED0 7F08F3A0 AC540000 */  sw    $s4, ($v0)
/* 0C3ED4 7F08F3A4 8EAE000C */  lw    $t6, 0xc($s5)
/* 0C3ED8 7F08F3A8 24102711 */  li    $s0, 10001
/* 0C3EDC 7F08F3AC 24510004 */  addiu $s1, $v0, 4
/* 0C3EE0 7F08F3B0 29C12711 */  slti  $at, $t6, 0x2711
/* 0C3EE4 7F08F3B4 14200011 */  bnez  $at, .L7F08F3FC
/* 0C3EE8 7F08F3B8 2A612712 */   slti  $at, $s3, 0x2712
/* 0C3EEC 7F08F3BC 54200010 */  bnezl $at, .L7F08F400
/* 0C3EF0 7F08F3C0 AE200000 */   sw    $zero, ($s1)
/* 0C3EF4 7F08F3C4 8E440004 */  lw    $a0, 4($s2)
.L7F08F3C8:
/* 0C3EF8 7F08F3C8 02002825 */  move  $a1, $s0
/* 0C3EFC 7F08F3CC 0FC23C24 */  jal   sub_GAME_7F08F090
/* 0C3F00 7F08F3D0 8E860008 */   lw    $a2, 8($s4)
/* 0C3F04 7F08F3D4 AE220000 */  sw    $v0, ($s1)
/* 0C3F08 7F08F3D8 8EAF000C */  lw    $t7, 0xc($s5)
/* 0C3F0C 7F08F3DC 26100001 */  addiu $s0, $s0, 1
/* 0C3F10 7F08F3E0 00409025 */  move  $s2, $v0
/* 0C3F14 7F08F3E4 01F0082A */  slt   $at, $t7, $s0
/* 0C3F18 7F08F3E8 14200004 */  bnez  $at, .L7F08F3FC
/* 0C3F1C 7F08F3EC 26310004 */   addiu $s1, $s1, 4
/* 0C3F20 7F08F3F0 0213082A */  slt   $at, $s0, $s3
/* 0C3F24 7F08F3F4 5420FFF4 */  bnezl $at, .L7F08F3C8
/* 0C3F28 7F08F3F8 8E440004 */   lw    $a0, 4($s2)
.L7F08F3FC:
/* 0C3F2C 7F08F3FC AE200000 */  sw    $zero, ($s1)
.L7F08F400:
/* 0C3F30 7F08F400 8FB80038 */  lw    $t8, 0x38($sp)
/* 0C3F34 7F08F404 26310004 */  addiu $s1, $s1, 4
/* 0C3F38 7F08F408 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0C3F3C 7F08F40C 02381023 */  subu  $v0, $s1, $t8
/* 0C3F40 7F08F410 0002C883 */  sra   $t9, $v0, 2
/* 0C3F44 7F08F414 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C3F48 7F08F418 8FB50028 */  lw    $s5, 0x28($sp)
/* 0C3F4C 7F08F41C 8FB40024 */  lw    $s4, 0x24($sp)
/* 0C3F50 7F08F420 8FB30020 */  lw    $s3, 0x20($sp)
/* 0C3F54 7F08F424 8FB2001C */  lw    $s2, 0x1c($sp)
/* 0C3F58 7F08F428 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C3F5C 7F08F42C 27BD0030 */  addiu $sp, $sp, 0x30
/* 0C3F60 7F08F430 03E00008 */  jr    $ra
/* 0C3F64 7F08F434 03201025 */   move  $v0, $t9
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F438(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F438
/* 0C3F68 7F08F438 27BDFFF8 */  addiu $sp, $sp, -8
/* 0C3F6C 7F08F43C AFB00004 */  sw    $s0, 4($sp)
/* 0C3F70 7F08F440 AFA60010 */  sw    $a2, 0x10($sp)
/* 0C3F74 7F08F444 AFA70014 */  sw    $a3, 0x14($sp)
/* 0C3F78 7F08F448 8C880004 */  lw    $t0, 4($a0)
/* 0C3F7C 7F08F44C 3C0A8007 */  lui   $t2, %hi(ptr_setup_path_tbl) 
/* 0C3F80 7F08F450 254A5D00 */  addiu $t2, %lo(ptr_setup_path_tbl) # addiu $t2, $t2, 0x5d00
/* 0C3F84 7F08F454 8D090000 */  lw    $t1, ($t0)
/* 0C3F88 7F08F458 00A08025 */  move  $s0, $a1
/* 0C3F8C 7F08F45C 8D420000 */  lw    $v0, ($t2)
/* 0C3F90 7F08F460 0520001C */  bltz  $t1, .L7F08F4D4
/* 0C3F94 7F08F464 8D430004 */   lw    $v1, 4($t2)
/* 0C3F98 7F08F468 240A000C */  li    $t2, 12
/* 0C3F9C 7F08F46C 00097100 */  sll   $t6, $t1, 4
.L7F08F470:
/* 0C3FA0 7F08F470 01C22021 */  addu  $a0, $t6, $v0
/* 0C3FA4 7F08F474 8C850004 */  lw    $a1, 4($a0)
/* 0C3FA8 7F08F478 8CA60000 */  lw    $a2, ($a1)
/* 0C3FAC 7F08F47C 04C00011 */  bltz  $a2, .L7F08F4C4
/* 0C3FB0 7F08F480 00067900 */   sll   $t7, $a2, 4
.L7F08F484:
/* 0C3FB4 7F08F484 01E23821 */  addu  $a3, $t7, $v0
/* 0C3FB8 7F08F488 8CF80008 */  lw    $t8, 8($a3)
/* 0C3FBC 7F08F48C 030A0019 */  multu $t8, $t2
/* 0C3FC0 7F08F490 0000C812 */  mflo  $t9
/* 0C3FC4 7F08F494 03235821 */  addu  $t3, $t9, $v1
/* 0C3FC8 7F08F498 560B0007 */  bnel  $s0, $t3, .L7F08F4B8
/* 0C3FCC 7F08F49C 8CA60004 */   lw    $a2, 4($a1)
/* 0C3FD0 7F08F4A0 8FAC0010 */  lw    $t4, 0x10($sp)
/* 0C3FD4 7F08F4A4 AD840000 */  sw    $a0, ($t4)
/* 0C3FD8 7F08F4A8 8FAD0014 */  lw    $t5, 0x14($sp)
/* 0C3FDC 7F08F4AC 1000000D */  b     .L7F08F4E4
/* 0C3FE0 7F08F4B0 ADA70000 */   sw    $a3, ($t5)
/* 0C3FE4 7F08F4B4 8CA60004 */  lw    $a2, 4($a1)
.L7F08F4B8:
/* 0C3FE8 7F08F4B8 24A50004 */  addiu $a1, $a1, 4
/* 0C3FEC 7F08F4BC 04C3FFF1 */  bgezl $a2, .L7F08F484
/* 0C3FF0 7F08F4C0 00067900 */   sll   $t7, $a2, 4
.L7F08F4C4:
/* 0C3FF4 7F08F4C4 8D090004 */  lw    $t1, 4($t0)
/* 0C3FF8 7F08F4C8 25080004 */  addiu $t0, $t0, 4
/* 0C3FFC 7F08F4CC 0523FFE8 */  bgezl $t1, .L7F08F470
/* 0C4000 7F08F4D0 00097100 */   sll   $t6, $t1, 4
.L7F08F4D4:
/* 0C4004 7F08F4D4 8FAE0014 */  lw    $t6, 0x14($sp)
/* 0C4008 7F08F4D8 ADC00000 */  sw    $zero, ($t6)
/* 0C400C 7F08F4DC 8FAF0010 */  lw    $t7, 0x10($sp)
/* 0C4010 7F08F4E0 ADE00000 */  sw    $zero, ($t7)
.L7F08F4E4:
/* 0C4014 7F08F4E4 8FB00004 */  lw    $s0, 4($sp)
/* 0C4018 7F08F4E8 03E00008 */  jr    $ra
/* 0C401C 7F08F4EC 27BD0008 */   addiu $sp, $sp, 8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F4F0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F4F0
/* 0C4020 7F08F4F0 27BDFF90 */  addiu $sp, $sp, -0x70
/* 0C4024 7F08F4F4 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C4028 7F08F4F8 3C108007 */  lui   $s0, %hi(ptr_setup_path_link)
/* 0C402C 7F08F4FC 8E105D04 */  lw    $s0, %lo(ptr_setup_path_link)($s0)
/* 0C4030 7F08F500 AFB60030 */  sw    $s6, 0x30($sp)
/* 0C4034 7F08F504 AFB40028 */  sw    $s4, 0x28($sp)
/* 0C4038 7F08F508 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0C403C 7F08F50C 00E08825 */  move  $s1, $a3
/* 0C4040 7F08F510 0080B025 */  move  $s6, $a0
/* 0C4044 7F08F514 AFBF003C */  sw    $ra, 0x3c($sp)
/* 0C4048 7F08F518 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0C404C 7F08F51C AFB70034 */  sw    $s7, 0x34($sp)
/* 0C4050 7F08F520 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0C4054 7F08F524 AFB30024 */  sw    $s3, 0x24($sp)
/* 0C4058 7F08F528 AFB20020 */  sw    $s2, 0x20($sp)
/* 0C405C 7F08F52C AFA50074 */  sw    $a1, 0x74($sp)
/* 0C4060 7F08F530 AFA60078 */  sw    $a2, 0x78($sp)
/* 0C4064 7F08F534 1200003F */  beqz  $s0, .L7F08F634
/* 0C4068 7F08F538 00C0A025 */   move  $s4, $a2
/* 0C406C 7F08F53C 8C8E0008 */  lw    $t6, 8($a0)
/* 0C4070 7F08F540 2402000C */  li    $v0, 12
/* 0C4074 7F08F544 8CB90008 */  lw    $t9, 8($a1)
/* 0C4078 7F08F548 01C20019 */  multu $t6, $v0
/* 0C407C 7F08F54C 02003025 */  move  $a2, $s0
/* 0C4080 7F08F550 00007812 */  mflo  $t7
/* 0C4084 7F08F554 01F09821 */  addu  $s3, $t7, $s0
/* 0C4088 7F08F558 02602025 */  move  $a0, $s3
/* 0C408C 7F08F55C 03220019 */  multu $t9, $v0
/* 0C4090 7F08F560 00004012 */  mflo  $t0
/* 0C4094 7F08F564 0110F021 */  addu  $fp, $t0, $s0
/* 0C4098 7F08F568 0FC23BC7 */  jal   sub_GAME_7F08EF1C
/* 0C409C 7F08F56C 03C02825 */   move  $a1, $fp
/* 0C40A0 7F08F570 50400031 */  beql  $v0, $zero, .L7F08F638
/* 0C40A4 7F08F574 AE800000 */   sw    $zero, ($s4)
/* 0C40A8 7F08F578 8E700008 */  lw    $s0, 8($s3)
/* 0C40AC 7F08F57C 8FC90008 */  lw    $t1, 8($fp)
/* 0C40B0 7F08F580 02C0A825 */  move  $s5, $s6
/* 0C40B4 7F08F584 26100001 */  addiu $s0, $s0, 1
/* 0C40B8 7F08F588 0130082A */  slt   $at, $t1, $s0
/* 0C40BC 7F08F58C 14200021 */  bnez  $at, .L7F08F614
/* 0C40C0 7F08F590 02609025 */   move  $s2, $s3
/* 0C40C4 7F08F594 2A210002 */  slti  $at, $s1, 2
/* 0C40C8 7F08F598 1420001E */  bnez  $at, .L7F08F614
/* 0C40CC 7F08F59C 27B70044 */   addiu $s7, $sp, 0x44
/* 0C40D0 7F08F5A0 27B60048 */  addiu $s6, $sp, 0x48
/* 0C40D4 7F08F5A4 8E440000 */  lw    $a0, ($s2)
.L7F08F5A8:
/* 0C40D8 7F08F5A8 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C40DC 7F08F5AC 02002825 */   move  $a1, $s0
/* 0C40E0 7F08F5B0 00409825 */  move  $s3, $v0
/* 0C40E4 7F08F5B4 02402025 */  move  $a0, $s2
/* 0C40E8 7F08F5B8 00402825 */  move  $a1, $v0
/* 0C40EC 7F08F5BC 02C03025 */  move  $a2, $s6
/* 0C40F0 7F08F5C0 0FC23D0E */  jal   sub_GAME_7F08F438
/* 0C40F4 7F08F5C4 02E03825 */   move  $a3, $s7
/* 0C40F8 7F08F5C8 02A02025 */  move  $a0, $s5
/* 0C40FC 7F08F5CC 8FA50048 */  lw    $a1, 0x48($sp)
/* 0C4100 7F08F5D0 02803025 */  move  $a2, $s4
/* 0C4104 7F08F5D4 0FC23CD4 */  jal   sub_GAME_7F08F350
/* 0C4108 7F08F5D8 02203825 */   move  $a3, $s1
/* 0C410C 7F08F5DC 8FCC0008 */  lw    $t4, 8($fp)
/* 0C4110 7F08F5E0 26100001 */  addiu $s0, $s0, 1
/* 0C4114 7F08F5E4 244AFFFF */  addiu $t2, $v0, -1
/* 0C4118 7F08F5E8 02228823 */  subu  $s1, $s1, $v0
/* 0C411C 7F08F5EC 000A5880 */  sll   $t3, $t2, 2
/* 0C4120 7F08F5F0 0190082A */  slt   $at, $t4, $s0
/* 0C4124 7F08F5F4 26310001 */  addiu $s1, $s1, 1
/* 0C4128 7F08F5F8 028BA021 */  addu  $s4, $s4, $t3
/* 0C412C 7F08F5FC 8FB50044 */  lw    $s5, 0x44($sp)
/* 0C4130 7F08F600 14200004 */  bnez  $at, .L7F08F614
/* 0C4134 7F08F604 02609025 */   move  $s2, $s3
/* 0C4138 7F08F608 2A210002 */  slti  $at, $s1, 2
/* 0C413C 7F08F60C 5020FFE6 */  beql  $at, $zero, .L7F08F5A8
/* 0C4140 7F08F610 8E440000 */   lw    $a0, ($s2)
.L7F08F614:
/* 0C4144 7F08F614 02A02025 */  move  $a0, $s5
/* 0C4148 7F08F618 8FA50074 */  lw    $a1, 0x74($sp)
/* 0C414C 7F08F61C 02803025 */  move  $a2, $s4
/* 0C4150 7F08F620 0FC23CD4 */  jal   sub_GAME_7F08F350
/* 0C4154 7F08F624 02203825 */   move  $a3, $s1
/* 0C4158 7F08F628 244DFFFF */  addiu $t5, $v0, -1
/* 0C415C 7F08F62C 000D7080 */  sll   $t6, $t5, 2
/* 0C4160 7F08F630 028EA021 */  addu  $s4, $s4, $t6
.L7F08F634:
/* 0C4164 7F08F634 AE800000 */  sw    $zero, ($s4)
.L7F08F638:
/* 0C4168 7F08F638 8FAF0078 */  lw    $t7, 0x78($sp)
/* 0C416C 7F08F63C 26940004 */  addiu $s4, $s4, 4
/* 0C4170 7F08F640 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0C4174 7F08F644 028F1023 */  subu  $v0, $s4, $t7
/* 0C4178 7F08F648 0002C083 */  sra   $t8, $v0, 2
/* 0C417C 7F08F64C 8FB40028 */  lw    $s4, 0x28($sp)
/* 0C4180 7F08F650 8FBE0038 */  lw    $fp, 0x38($sp)
/* 0C4184 7F08F654 8FB70034 */  lw    $s7, 0x34($sp)
/* 0C4188 7F08F658 8FB60030 */  lw    $s6, 0x30($sp)
/* 0C418C 7F08F65C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0C4190 7F08F660 8FB30024 */  lw    $s3, 0x24($sp)
/* 0C4194 7F08F664 8FB20020 */  lw    $s2, 0x20($sp)
/* 0C4198 7F08F668 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0C419C 7F08F66C 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C41A0 7F08F670 27BD0070 */  addiu $sp, $sp, 0x70
/* 0C41A4 7F08F674 03E00008 */  jr    $ra
/* 0C41A8 7F08F678 03001025 */   move  $v0, $t8
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F67C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F67C
/* 0C41AC 7F08F67C 3C028007 */  lui   $v0, %hi(ptr_setup_path_tbl)
/* 0C41B0 7F08F680 8C425D00 */  lw    $v0, %lo(ptr_setup_path_tbl)($v0)
/* 0C41B4 7F08F684 2403FFFF */  li    $v1, -1
/* 0C41B8 7F08F688 8C4E0000 */  lw    $t6, ($v0)
/* 0C41BC 7F08F68C 05C00006 */  bltz  $t6, .L7F08F6A8
/* 0C41C0 7F08F690 00000000 */   nop   
/* 0C41C4 7F08F694 8C4F0010 */  lw    $t7, 0x10($v0)
.L7F08F698:
/* 0C41C8 7F08F698 AC43000C */  sw    $v1, 0xc($v0)
/* 0C41CC 7F08F69C 24420010 */  addiu $v0, $v0, 0x10
/* 0C41D0 7F08F6A0 05E3FFFD */  bgezl $t7, .L7F08F698
/* 0C41D4 7F08F6A4 8C4F0010 */   lw    $t7, 0x10($v0)
.L7F08F6A8:
/* 0C41D8 7F08F6A8 03E00008 */  jr    $ra
/* 0C41DC 7F08F6AC 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F6B0(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F6B0
/* 0C41E0 7F08F6B0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0C41E4 7F08F6B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C41E8 7F08F6B8 8C8E0000 */  lw    $t6, ($a0)
/* 0C41EC 7F08F6BC 00A03825 */  move  $a3, $a1
/* 0C41F0 7F08F6C0 00004825 */  move  $t1, $zero
/* 0C41F4 7F08F6C4 05C00006 */  bltz  $t6, .L7F08F6E0
/* 0C41F8 7F08F6C8 00801025 */   move  $v0, $a0
/* 0C41FC 7F08F6CC 8C4F0004 */  lw    $t7, 4($v0)
.L7F08F6D0:
/* 0C4200 7F08F6D0 25290001 */  addiu $t1, $t1, 1
/* 0C4204 7F08F6D4 24420004 */  addiu $v0, $v0, 4
/* 0C4208 7F08F6D8 05E3FFFD */  bgezl $t7, .L7F08F6D0
/* 0C420C 7F08F6DC 8C4F0004 */   lw    $t7, 4($v0)
.L7F08F6E0:
/* 0C4210 7F08F6E0 AFA40020 */  sw    $a0, 0x20($sp)
/* 0C4214 7F08F6E4 AFA70024 */  sw    $a3, 0x24($sp)
/* 0C4218 7F08F6E8 0C002914 */  jal   get_random_value
/* 0C421C 7F08F6EC AFA9001C */   sw    $t1, 0x1c($sp)
/* 0C4220 7F08F6F0 8FA9001C */  lw    $t1, 0x1c($sp)
/* 0C4224 7F08F6F4 8FA70024 */  lw    $a3, 0x24($sp)
/* 0C4228 7F08F6F8 8FAC0020 */  lw    $t4, 0x20($sp)
/* 0C422C 7F08F6FC 0049001B */  divu  $zero, $v0, $t1
/* 0C4230 7F08F700 00005810 */  mfhi  $t3
/* 0C4234 7F08F704 0169082A */  slt   $at, $t3, $t1
/* 0C4238 7F08F708 15200002 */  bnez  $t1, .L7F08F714
/* 0C423C 7F08F70C 00000000 */   nop   
/* 0C4240 7F08F710 0007000D */  break 7
.L7F08F714:
/* 0C4244 7F08F714 01605025 */  move  $t2, $t3
/* 0C4248 7F08F718 1020003C */  beqz  $at, .L7F08F80C
/* 0C424C 7F08F71C 01603025 */   move  $a2, $t3
/* 0C4250 7F08F720 012B1823 */  subu  $v1, $t1, $t3
/* 0C4254 7F08F724 30780003 */  andi  $t8, $v1, 3
/* 0C4258 7F08F728 13000011 */  beqz  $t8, .L7F08F770
/* 0C425C 7F08F72C 030B4021 */   addu  $t0, $t8, $t3
/* 0C4260 7F08F730 0006C880 */  sll   $t9, $a2, 2
/* 0C4264 7F08F734 3C058007 */  lui   $a1, %hi(ptr_setup_path_tbl)
/* 0C4268 7F08F738 8CA55D00 */  lw    $a1, %lo(ptr_setup_path_tbl)($a1)
/* 0C426C 7F08F73C 01991021 */  addu  $v0, $t4, $t9
.L7F08F740:
/* 0C4270 7F08F740 8C4D0000 */  lw    $t5, ($v0)
/* 0C4274 7F08F744 24C60001 */  addiu $a2, $a2, 1
/* 0C4278 7F08F748 000D7100 */  sll   $t6, $t5, 4
/* 0C427C 7F08F74C 01C52021 */  addu  $a0, $t6, $a1
/* 0C4280 7F08F750 8C8F000C */  lw    $t7, 0xc($a0)
/* 0C4284 7F08F754 14EF0003 */  bne   $a3, $t7, .L7F08F764
/* 0C4288 7F08F758 00000000 */   nop   
/* 0C428C 7F08F75C 10000066 */  b     .L7F08F8F8
/* 0C4290 7F08F760 00801025 */   move  $v0, $a0
.L7F08F764:
/* 0C4294 7F08F764 1506FFF6 */  bne   $t0, $a2, .L7F08F740
/* 0C4298 7F08F768 24420004 */   addiu $v0, $v0, 4
/* 0C429C 7F08F76C 10C90027 */  beq   $a2, $t1, .L7F08F80C
.L7F08F770:
/* 0C42A0 7F08F770 0006C080 */   sll   $t8, $a2, 2
/* 0C42A4 7F08F774 3C058007 */  lui   $a1, %hi(ptr_setup_path_tbl)
/* 0C42A8 7F08F778 8CA55D00 */  lw    $a1, %lo(ptr_setup_path_tbl)($a1)
/* 0C42AC 7F08F77C 01981021 */  addu  $v0, $t4, $t8
.L7F08F780:
/* 0C42B0 7F08F780 8C590000 */  lw    $t9, ($v0)
/* 0C42B4 7F08F784 24C60004 */  addiu $a2, $a2, 4
/* 0C42B8 7F08F788 00196900 */  sll   $t5, $t9, 4
/* 0C42BC 7F08F78C 01A52021 */  addu  $a0, $t5, $a1
/* 0C42C0 7F08F790 8C8E000C */  lw    $t6, 0xc($a0)
/* 0C42C4 7F08F794 54EE0004 */  bnel  $a3, $t6, .L7F08F7A8
/* 0C42C8 7F08F798 8C4F0004 */   lw    $t7, 4($v0)
/* 0C42CC 7F08F79C 10000056 */  b     .L7F08F8F8
/* 0C42D0 7F08F7A0 00801025 */   move  $v0, $a0
/* 0C42D4 7F08F7A4 8C4F0004 */  lw    $t7, 4($v0)
.L7F08F7A8:
/* 0C42D8 7F08F7A8 000FC100 */  sll   $t8, $t7, 4
/* 0C42DC 7F08F7AC 03051821 */  addu  $v1, $t8, $a1
/* 0C42E0 7F08F7B0 8C79000C */  lw    $t9, 0xc($v1)
/* 0C42E4 7F08F7B4 54F90004 */  bnel  $a3, $t9, .L7F08F7C8
/* 0C42E8 7F08F7B8 8C4D0008 */   lw    $t5, 8($v0)
/* 0C42EC 7F08F7BC 1000004E */  b     .L7F08F8F8
/* 0C42F0 7F08F7C0 00601025 */   move  $v0, $v1
/* 0C42F4 7F08F7C4 8C4D0008 */  lw    $t5, 8($v0)
.L7F08F7C8:
/* 0C42F8 7F08F7C8 000D7100 */  sll   $t6, $t5, 4
/* 0C42FC 7F08F7CC 01C51821 */  addu  $v1, $t6, $a1
/* 0C4300 7F08F7D0 8C6F000C */  lw    $t7, 0xc($v1)
/* 0C4304 7F08F7D4 54EF0004 */  bnel  $a3, $t7, .L7F08F7E8
/* 0C4308 7F08F7D8 8C58000C */   lw    $t8, 0xc($v0)
/* 0C430C 7F08F7DC 10000046 */  b     .L7F08F8F8
/* 0C4310 7F08F7E0 00601025 */   move  $v0, $v1
/* 0C4314 7F08F7E4 8C58000C */  lw    $t8, 0xc($v0)
.L7F08F7E8:
/* 0C4318 7F08F7E8 0018C900 */  sll   $t9, $t8, 4
/* 0C431C 7F08F7EC 03251821 */  addu  $v1, $t9, $a1
/* 0C4320 7F08F7F0 8C6D000C */  lw    $t5, 0xc($v1)
/* 0C4324 7F08F7F4 14ED0003 */  bne   $a3, $t5, .L7F08F804
/* 0C4328 7F08F7F8 00000000 */   nop   
/* 0C432C 7F08F7FC 1000003E */  b     .L7F08F8F8
/* 0C4330 7F08F800 00601025 */   move  $v0, $v1
.L7F08F804:
/* 0C4334 7F08F804 14C9FFDE */  bne   $a2, $t1, .L7F08F780
/* 0C4338 7F08F808 24420010 */   addiu $v0, $v0, 0x10
.L7F08F80C:
/* 0C433C 7F08F80C 19600039 */  blez  $t3, .L7F08F8F4
/* 0C4340 7F08F810 00003025 */   move  $a2, $zero
/* 0C4344 7F08F814 3C058007 */  lui   $a1, %hi(ptr_setup_path_tbl)
/* 0C4348 7F08F818 31630003 */  andi  $v1, $t3, 3
/* 0C434C 7F08F81C 10600010 */  beqz  $v1, .L7F08F860
/* 0C4350 7F08F820 8CA55D00 */   lw    $a1, %lo(ptr_setup_path_tbl)($a1)
/* 0C4354 7F08F824 00007080 */  sll   $t6, $zero, 2
/* 0C4358 7F08F828 018E1021 */  addu  $v0, $t4, $t6
/* 0C435C 7F08F82C 00604025 */  move  $t0, $v1
.L7F08F830:
/* 0C4360 7F08F830 8C4F0000 */  lw    $t7, ($v0)
/* 0C4364 7F08F834 24C60001 */  addiu $a2, $a2, 1
/* 0C4368 7F08F838 000FC100 */  sll   $t8, $t7, 4
/* 0C436C 7F08F83C 03052021 */  addu  $a0, $t8, $a1
/* 0C4370 7F08F840 8C99000C */  lw    $t9, 0xc($a0)
/* 0C4374 7F08F844 14F90003 */  bne   $a3, $t9, .L7F08F854
/* 0C4378 7F08F848 00000000 */   nop   
/* 0C437C 7F08F84C 1000002A */  b     .L7F08F8F8
/* 0C4380 7F08F850 00801025 */   move  $v0, $a0
.L7F08F854:
/* 0C4384 7F08F854 1506FFF6 */  bne   $t0, $a2, .L7F08F830
/* 0C4388 7F08F858 24420004 */   addiu $v0, $v0, 4
/* 0C438C 7F08F85C 10CB0025 */  beq   $a2, $t3, .L7F08F8F4
.L7F08F860:
/* 0C4390 7F08F860 00066880 */   sll   $t5, $a2, 2
/* 0C4394 7F08F864 018D1021 */  addu  $v0, $t4, $t5
.L7F08F868:
/* 0C4398 7F08F868 8C4E0000 */  lw    $t6, ($v0)
/* 0C439C 7F08F86C 24C60004 */  addiu $a2, $a2, 4
/* 0C43A0 7F08F870 000E7900 */  sll   $t7, $t6, 4
/* 0C43A4 7F08F874 01E52021 */  addu  $a0, $t7, $a1
/* 0C43A8 7F08F878 8C98000C */  lw    $t8, 0xc($a0)
/* 0C43AC 7F08F87C 54F80004 */  bnel  $a3, $t8, .L7F08F890
/* 0C43B0 7F08F880 8C590004 */   lw    $t9, 4($v0)
/* 0C43B4 7F08F884 1000001C */  b     .L7F08F8F8
/* 0C43B8 7F08F888 00801025 */   move  $v0, $a0
/* 0C43BC 7F08F88C 8C590004 */  lw    $t9, 4($v0)
.L7F08F890:
/* 0C43C0 7F08F890 00196900 */  sll   $t5, $t9, 4
/* 0C43C4 7F08F894 01A51821 */  addu  $v1, $t5, $a1
/* 0C43C8 7F08F898 8C6E000C */  lw    $t6, 0xc($v1)
/* 0C43CC 7F08F89C 54EE0004 */  bnel  $a3, $t6, .L7F08F8B0
/* 0C43D0 7F08F8A0 8C4F0008 */   lw    $t7, 8($v0)
/* 0C43D4 7F08F8A4 10000014 */  b     .L7F08F8F8
/* 0C43D8 7F08F8A8 00601025 */   move  $v0, $v1
/* 0C43DC 7F08F8AC 8C4F0008 */  lw    $t7, 8($v0)
.L7F08F8B0:
/* 0C43E0 7F08F8B0 000FC100 */  sll   $t8, $t7, 4
/* 0C43E4 7F08F8B4 03051821 */  addu  $v1, $t8, $a1
/* 0C43E8 7F08F8B8 8C79000C */  lw    $t9, 0xc($v1)
/* 0C43EC 7F08F8BC 54F90004 */  bnel  $a3, $t9, .L7F08F8D0
/* 0C43F0 7F08F8C0 8C4D000C */   lw    $t5, 0xc($v0)
/* 0C43F4 7F08F8C4 1000000C */  b     .L7F08F8F8
/* 0C43F8 7F08F8C8 00601025 */   move  $v0, $v1
/* 0C43FC 7F08F8CC 8C4D000C */  lw    $t5, 0xc($v0)
.L7F08F8D0:
/* 0C4400 7F08F8D0 000D7100 */  sll   $t6, $t5, 4
/* 0C4404 7F08F8D4 01C51821 */  addu  $v1, $t6, $a1
/* 0C4408 7F08F8D8 8C6F000C */  lw    $t7, 0xc($v1)
/* 0C440C 7F08F8DC 14EF0003 */  bne   $a3, $t7, .L7F08F8EC
/* 0C4410 7F08F8E0 00000000 */   nop   
/* 0C4414 7F08F8E4 10000004 */  b     .L7F08F8F8
/* 0C4418 7F08F8E8 00601025 */   move  $v0, $v1
.L7F08F8EC:
/* 0C441C 7F08F8EC 14CAFFDE */  bne   $a2, $t2, .L7F08F868
/* 0C4420 7F08F8F0 24420010 */   addiu $v0, $v0, 0x10
.L7F08F8F4:
/* 0C4424 7F08F8F4 00001025 */  move  $v0, $zero
.L7F08F8F8:
/* 0C4428 7F08F8F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0C442C 7F08F8FC 27BD0020 */  addiu $sp, $sp, 0x20
/* 0C4430 7F08F900 03E00008 */  jr    $ra
/* 0C4434 7F08F904 00000000 */   nop   
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08F908(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08F908
/* 0C4438 7F08F908 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0C443C 7F08F90C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C4440 7F08F910 AFB00018 */  sw    $s0, 0x18($sp)
/* 0C4444 7F08F914 8C8E0000 */  lw    $t6, ($a0)
/* 0C4448 7F08F918 00A08025 */  move  $s0, $a1
/* 0C444C 7F08F91C 00004825 */  move  $t1, $zero
/* 0C4450 7F08F920 05C00006 */  bltz  $t6, .L7F08F93C
/* 0C4454 7F08F924 00801025 */   move  $v0, $a0
/* 0C4458 7F08F928 8C4F0004 */  lw    $t7, 4($v0)
.L7F08F92C:
/* 0C445C 7F08F92C 25290001 */  addiu $t1, $t1, 1
/* 0C4460 7F08F930 24420004 */  addiu $v0, $v0, 4
/* 0C4464 7F08F934 05E3FFFD */  bgezl $t7, .L7F08F92C
/* 0C4468 7F08F938 8C4F0004 */   lw    $t7, 4($v0)
.L7F08F93C:
/* 0C446C 7F08F93C AFA40028 */  sw    $a0, 0x28($sp)
/* 0C4470 7F08F940 0C002914 */  jal   get_random_value
/* 0C4474 7F08F944 AFA90024 */   sw    $t1, 0x24($sp)
/* 0C4478 7F08F948 8FA90024 */  lw    $t1, 0x24($sp)
/* 0C447C 7F08F94C 8FAC0028 */  lw    $t4, 0x28($sp)
/* 0C4480 7F08F950 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0C4484 7F08F954 0049001B */  divu  $zero, $v0, $t1
/* 0C4488 7F08F958 00005810 */  mfhi  $t3
/* 0C448C 7F08F95C 0169082A */  slt   $at, $t3, $t1
/* 0C4490 7F08F960 15200002 */  bnez  $t1, .L7F08F96C
/* 0C4494 7F08F964 00000000 */   nop   
/* 0C4498 7F08F968 0007000D */  break 7
.L7F08F96C:
/* 0C449C 7F08F96C 01605025 */  move  $t2, $t3
/* 0C44A0 7F08F970 10200043 */  beqz  $at, .L7F08FA80
/* 0C44A4 7F08F974 01603025 */   move  $a2, $t3
/* 0C44A8 7F08F978 012B1823 */  subu  $v1, $t1, $t3
/* 0C44AC 7F08F97C 30780003 */  andi  $t8, $v1, 3
/* 0C44B0 7F08F980 13000013 */  beqz  $t8, .L7F08F9D0
/* 0C44B4 7F08F984 030B4021 */   addu  $t0, $t8, $t3
/* 0C44B8 7F08F988 0006C880 */  sll   $t9, $a2, 2
/* 0C44BC 7F08F98C 3C058007 */  lui   $a1, %hi(ptr_setup_path_link)
/* 0C44C0 7F08F990 8CA55D04 */  lw    $a1, %lo(ptr_setup_path_link)($a1)
/* 0C44C4 7F08F994 01991021 */  addu  $v0, $t4, $t9
/* 0C44C8 7F08F998 2407000C */  li    $a3, 12
.L7F08F99C:
/* 0C44CC 7F08F99C 8C4D0000 */  lw    $t5, ($v0)
/* 0C44D0 7F08F9A0 24C60001 */  addiu $a2, $a2, 1
/* 0C44D4 7F08F9A4 01A70019 */  multu $t5, $a3
/* 0C44D8 7F08F9A8 00007012 */  mflo  $t6
/* 0C44DC 7F08F9AC 01C52021 */  addu  $a0, $t6, $a1
/* 0C44E0 7F08F9B0 8C8F0008 */  lw    $t7, 8($a0)
/* 0C44E4 7F08F9B4 160F0003 */  bne   $s0, $t7, .L7F08F9C4
/* 0C44E8 7F08F9B8 00000000 */   nop   
/* 0C44EC 7F08F9BC 10000071 */  b     .L7F08FB84
/* 0C44F0 7F08F9C0 00801025 */   move  $v0, $a0
.L7F08F9C4:
/* 0C44F4 7F08F9C4 1506FFF5 */  bne   $t0, $a2, .L7F08F99C
/* 0C44F8 7F08F9C8 24420004 */   addiu $v0, $v0, 4
/* 0C44FC 7F08F9CC 10C9002C */  beq   $a2, $t1, .L7F08FA80
.L7F08F9D0:
/* 0C4500 7F08F9D0 0006C080 */   sll   $t8, $a2, 2
/* 0C4504 7F08F9D4 3C058007 */  lui   $a1, %hi(ptr_setup_path_link)
/* 0C4508 7F08F9D8 8CA55D04 */  lw    $a1, %lo(ptr_setup_path_link)($a1)
/* 0C450C 7F08F9DC 01981021 */  addu  $v0, $t4, $t8
/* 0C4510 7F08F9E0 2407000C */  li    $a3, 12
.L7F08F9E4:
/* 0C4514 7F08F9E4 8C590000 */  lw    $t9, ($v0)
/* 0C4518 7F08F9E8 24C60004 */  addiu $a2, $a2, 4
/* 0C451C 7F08F9EC 03270019 */  multu $t9, $a3
/* 0C4520 7F08F9F0 00006812 */  mflo  $t5
/* 0C4524 7F08F9F4 01A52021 */  addu  $a0, $t5, $a1
/* 0C4528 7F08F9F8 8C8E0008 */  lw    $t6, 8($a0)
/* 0C452C 7F08F9FC 560E0004 */  bnel  $s0, $t6, .L7F08FA10
/* 0C4530 7F08FA00 8C4F0004 */   lw    $t7, 4($v0)
/* 0C4534 7F08FA04 1000005F */  b     .L7F08FB84
/* 0C4538 7F08FA08 00801025 */   move  $v0, $a0
/* 0C453C 7F08FA0C 8C4F0004 */  lw    $t7, 4($v0)
.L7F08FA10:
/* 0C4540 7F08FA10 01E70019 */  multu $t7, $a3
/* 0C4544 7F08FA14 0000C012 */  mflo  $t8
/* 0C4548 7F08FA18 03051821 */  addu  $v1, $t8, $a1
/* 0C454C 7F08FA1C 8C790008 */  lw    $t9, 8($v1)
/* 0C4550 7F08FA20 56190004 */  bnel  $s0, $t9, .L7F08FA34
/* 0C4554 7F08FA24 8C4D0008 */   lw    $t5, 8($v0)
/* 0C4558 7F08FA28 10000056 */  b     .L7F08FB84
/* 0C455C 7F08FA2C 00601025 */   move  $v0, $v1
/* 0C4560 7F08FA30 8C4D0008 */  lw    $t5, 8($v0)
.L7F08FA34:
/* 0C4564 7F08FA34 01A70019 */  multu $t5, $a3
/* 0C4568 7F08FA38 00007012 */  mflo  $t6
/* 0C456C 7F08FA3C 01C51821 */  addu  $v1, $t6, $a1
/* 0C4570 7F08FA40 8C6F0008 */  lw    $t7, 8($v1)
/* 0C4574 7F08FA44 560F0004 */  bnel  $s0, $t7, .L7F08FA58
/* 0C4578 7F08FA48 8C58000C */   lw    $t8, 0xc($v0)
/* 0C457C 7F08FA4C 1000004D */  b     .L7F08FB84
/* 0C4580 7F08FA50 00601025 */   move  $v0, $v1
/* 0C4584 7F08FA54 8C58000C */  lw    $t8, 0xc($v0)
.L7F08FA58:
/* 0C4588 7F08FA58 03070019 */  multu $t8, $a3
/* 0C458C 7F08FA5C 0000C812 */  mflo  $t9
/* 0C4590 7F08FA60 03251821 */  addu  $v1, $t9, $a1
/* 0C4594 7F08FA64 8C6D0008 */  lw    $t5, 8($v1)
/* 0C4598 7F08FA68 160D0003 */  bne   $s0, $t5, .L7F08FA78
/* 0C459C 7F08FA6C 00000000 */   nop   
/* 0C45A0 7F08FA70 10000044 */  b     .L7F08FB84
/* 0C45A4 7F08FA74 00601025 */   move  $v0, $v1
.L7F08FA78:
/* 0C45A8 7F08FA78 14C9FFDA */  bne   $a2, $t1, .L7F08F9E4
/* 0C45AC 7F08FA7C 24420010 */   addiu $v0, $v0, 0x10
.L7F08FA80:
/* 0C45B0 7F08FA80 2407000C */  li    $a3, 12
/* 0C45B4 7F08FA84 1960003E */  blez  $t3, .L7F08FB80
/* 0C45B8 7F08FA88 00003025 */   move  $a2, $zero
/* 0C45BC 7F08FA8C 3C058007 */  lui   $a1, %hi(ptr_setup_path_link)
/* 0C45C0 7F08FA90 31630003 */  andi  $v1, $t3, 3
/* 0C45C4 7F08FA94 10600011 */  beqz  $v1, .L7F08FADC
/* 0C45C8 7F08FA98 8CA55D04 */   lw    $a1, %lo(ptr_setup_path_link)($a1)
/* 0C45CC 7F08FA9C 00007080 */  sll   $t6, $zero, 2
/* 0C45D0 7F08FAA0 018E1021 */  addu  $v0, $t4, $t6
/* 0C45D4 7F08FAA4 00604025 */  move  $t0, $v1
.L7F08FAA8:
/* 0C45D8 7F08FAA8 8C4F0000 */  lw    $t7, ($v0)
/* 0C45DC 7F08FAAC 24C60001 */  addiu $a2, $a2, 1
/* 0C45E0 7F08FAB0 01E70019 */  multu $t7, $a3
/* 0C45E4 7F08FAB4 0000C012 */  mflo  $t8
/* 0C45E8 7F08FAB8 03052021 */  addu  $a0, $t8, $a1
/* 0C45EC 7F08FABC 8C990008 */  lw    $t9, 8($a0)
/* 0C45F0 7F08FAC0 16190003 */  bne   $s0, $t9, .L7F08FAD0
/* 0C45F4 7F08FAC4 00000000 */   nop   
/* 0C45F8 7F08FAC8 1000002E */  b     .L7F08FB84
/* 0C45FC 7F08FACC 00801025 */   move  $v0, $a0
.L7F08FAD0:
/* 0C4600 7F08FAD0 1506FFF5 */  bne   $t0, $a2, .L7F08FAA8
/* 0C4604 7F08FAD4 24420004 */   addiu $v0, $v0, 4
/* 0C4608 7F08FAD8 10CB0029 */  beq   $a2, $t3, .L7F08FB80
.L7F08FADC:
/* 0C460C 7F08FADC 00066880 */   sll   $t5, $a2, 2
/* 0C4610 7F08FAE0 018D1021 */  addu  $v0, $t4, $t5
.L7F08FAE4:
/* 0C4614 7F08FAE4 8C4E0000 */  lw    $t6, ($v0)
/* 0C4618 7F08FAE8 24C60004 */  addiu $a2, $a2, 4
/* 0C461C 7F08FAEC 01C70019 */  multu $t6, $a3
/* 0C4620 7F08FAF0 00007812 */  mflo  $t7
/* 0C4624 7F08FAF4 01E52021 */  addu  $a0, $t7, $a1
/* 0C4628 7F08FAF8 8C980008 */  lw    $t8, 8($a0)
/* 0C462C 7F08FAFC 56180004 */  bnel  $s0, $t8, .L7F08FB10
/* 0C4630 7F08FB00 8C590004 */   lw    $t9, 4($v0)
/* 0C4634 7F08FB04 1000001F */  b     .L7F08FB84
/* 0C4638 7F08FB08 00801025 */   move  $v0, $a0
/* 0C463C 7F08FB0C 8C590004 */  lw    $t9, 4($v0)
.L7F08FB10:
/* 0C4640 7F08FB10 03270019 */  multu $t9, $a3
/* 0C4644 7F08FB14 00006812 */  mflo  $t5
/* 0C4648 7F08FB18 01A51821 */  addu  $v1, $t5, $a1
/* 0C464C 7F08FB1C 8C6E0008 */  lw    $t6, 8($v1)
/* 0C4650 7F08FB20 560E0004 */  bnel  $s0, $t6, .L7F08FB34
/* 0C4654 7F08FB24 8C4F0008 */   lw    $t7, 8($v0)
/* 0C4658 7F08FB28 10000016 */  b     .L7F08FB84
/* 0C465C 7F08FB2C 00601025 */   move  $v0, $v1
/* 0C4660 7F08FB30 8C4F0008 */  lw    $t7, 8($v0)
.L7F08FB34:
/* 0C4664 7F08FB34 01E70019 */  multu $t7, $a3
/* 0C4668 7F08FB38 0000C012 */  mflo  $t8
/* 0C466C 7F08FB3C 03051821 */  addu  $v1, $t8, $a1
/* 0C4670 7F08FB40 8C790008 */  lw    $t9, 8($v1)
/* 0C4674 7F08FB44 56190004 */  bnel  $s0, $t9, .L7F08FB58
/* 0C4678 7F08FB48 8C4D000C */   lw    $t5, 0xc($v0)
/* 0C467C 7F08FB4C 1000000D */  b     .L7F08FB84
/* 0C4680 7F08FB50 00601025 */   move  $v0, $v1
/* 0C4684 7F08FB54 8C4D000C */  lw    $t5, 0xc($v0)
.L7F08FB58:
/* 0C4688 7F08FB58 01A70019 */  multu $t5, $a3
/* 0C468C 7F08FB5C 00007012 */  mflo  $t6
/* 0C4690 7F08FB60 01C51821 */  addu  $v1, $t6, $a1
/* 0C4694 7F08FB64 8C6F0008 */  lw    $t7, 8($v1)
/* 0C4698 7F08FB68 160F0003 */  bne   $s0, $t7, .L7F08FB78
/* 0C469C 7F08FB6C 00000000 */   nop   
/* 0C46A0 7F08FB70 10000004 */  b     .L7F08FB84
/* 0C46A4 7F08FB74 00601025 */   move  $v0, $v1
.L7F08FB78:
/* 0C46A8 7F08FB78 14CAFFDA */  bne   $a2, $t2, .L7F08FAE4
/* 0C46AC 7F08FB7C 24420010 */   addiu $v0, $v0, 0x10
.L7F08FB80:
/* 0C46B0 7F08FB80 00001025 */  move  $v0, $zero
.L7F08FB84:
/* 0C46B4 7F08FB84 8FB00018 */  lw    $s0, 0x18($sp)
/* 0C46B8 7F08FB88 03E00008 */  jr    $ra
/* 0C46BC 7F08FB8C 27BD0028 */   addiu $sp, $sp, 0x28
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08FB90(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08FB90
/* 0C46C0 7F08FB90 3C068007 */  lui   $a2, %hi(ptr_setup_path_link)
/* 0C46C4 7F08FB94 8CC65D04 */  lw    $a2, %lo(ptr_setup_path_link)($a2)
/* 0C46C8 7F08FB98 27BDFFA8 */  addiu $sp, $sp, -0x58
/* 0C46CC 7F08FB9C AFB10018 */  sw    $s1, 0x18($sp)
/* 0C46D0 7F08FBA0 00808825 */  move  $s1, $a0
/* 0C46D4 7F08FBA4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0C46D8 7F08FBA8 10C00056 */  beqz  $a2, .L7F08FD04
/* 0C46DC 7F08FBAC AFB00014 */   sw    $s0, 0x14($sp)
/* 0C46E0 7F08FBB0 8C8E0008 */  lw    $t6, 8($a0)
/* 0C46E4 7F08FBB4 2402000C */  li    $v0, 12
/* 0C46E8 7F08FBB8 8CB80008 */  lw    $t8, 8($a1)
/* 0C46EC 7F08FBBC 01C20019 */  multu $t6, $v0
/* 0C46F0 7F08FBC0 00003825 */  move  $a3, $zero
/* 0C46F4 7F08FBC4 00007812 */  mflo  $t7
/* 0C46F8 7F08FBC8 01E68021 */  addu  $s0, $t7, $a2
/* 0C46FC 7F08FBCC 00000000 */  nop   
/* 0C4700 7F08FBD0 03020019 */  multu $t8, $v0
/* 0C4704 7F08FBD4 0000C812 */  mflo  $t9
/* 0C4708 7F08FBD8 03262021 */  addu  $a0, $t9, $a2
/* 0C470C 7F08FBDC 16040016 */  bne   $s0, $a0, .L7F08FC38
/* 0C4710 7F08FBE0 00000000 */   nop   
/* 0C4714 7F08FBE4 0FC23D9F */  jal   sub_GAME_7F08F67C
/* 0C4718 7F08FBE8 AFA5005C */   sw    $a1, 0x5c($sp)
/* 0C471C 7F08FBEC 8FA4005C */  lw    $a0, 0x5c($sp)
/* 0C4720 7F08FBF0 02202825 */  move  $a1, $s1
/* 0C4724 7F08FBF4 0FC23C76 */  jal   sub_GAME_7F08F1D8
/* 0C4728 7F08FBF8 24060001 */   li    $a2, 1
/* 0C472C 7F08FBFC 8E240004 */  lw    $a0, 4($s1)
/* 0C4730 7F08FC00 0FC23DAC */  jal   sub_GAME_7F08F6B0
/* 0C4734 7F08FC04 2405FFFF */   li    $a1, -1
/* 0C4738 7F08FC08 50400004 */  beql  $v0, $zero, .L7F08FC1C
/* 0C473C 7F08FC0C 8E25000C */   lw    $a1, 0xc($s1)
/* 0C4740 7F08FC10 1000003E */  b     .L7F08FD0C
/* 0C4744 7F08FC14 8FBF001C */   lw    $ra, 0x1c($sp)
/* 0C4748 7F08FC18 8E25000C */  lw    $a1, 0xc($s1)
.L7F08FC1C:
/* 0C474C 7F08FC1C 8E240004 */  lw    $a0, 4($s1)
/* 0C4750 7F08FC20 0FC23DAC */  jal   sub_GAME_7F08F6B0
/* 0C4754 7F08FC24 24A50001 */   addiu $a1, $a1, 1
/* 0C4758 7F08FC28 50400037 */  beql  $v0, $zero, .L7F08FD08
/* 0C475C 7F08FC2C 00001025 */   move  $v0, $zero
/* 0C4760 7F08FC30 10000036 */  b     .L7F08FD0C
/* 0C4764 7F08FC34 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F08FC38:
/* 0C4768 7F08FC38 0FC23B9C */  jal   sub_GAME_7F08EE70
/* 0C476C 7F08FC3C 02002825 */   move  $a1, $s0
/* 0C4770 7F08FC40 8E080008 */  lw    $t0, 8($s0)
/* 0C4774 7F08FC44 2405FFFF */  li    $a1, -1
/* 0C4778 7F08FC48 0502002F */  bltzl $t0, .L7F08FD08
/* 0C477C 7F08FC4C 00001025 */   move  $v0, $zero
/* 0C4780 7F08FC50 0FC23E42 */  jal   sub_GAME_7F08F908
/* 0C4784 7F08FC54 8E040000 */   lw    $a0, ($s0)
/* 0C4788 7F08FC58 10400013 */  beqz  $v0, .L7F08FCA8
/* 0C478C 7F08FC5C 00402825 */   move  $a1, $v0
/* 0C4790 7F08FC60 02002025 */  move  $a0, $s0
/* 0C4794 7F08FC64 27A60040 */  addiu $a2, $sp, 0x40
/* 0C4798 7F08FC68 0FC23D0E */  jal   sub_GAME_7F08F438
/* 0C479C 7F08FC6C 27A7003C */   addiu $a3, $sp, 0x3c
/* 0C47A0 7F08FC70 8FA50040 */  lw    $a1, 0x40($sp)
/* 0C47A4 7F08FC74 02202025 */  move  $a0, $s1
/* 0C47A8 7F08FC78 27A60030 */  addiu $a2, $sp, 0x30
/* 0C47AC 7F08FC7C 14B10003 */  bne   $a1, $s1, .L7F08FC8C
/* 0C47B0 7F08FC80 00000000 */   nop   
/* 0C47B4 7F08FC84 10000020 */  b     .L7F08FD08
/* 0C47B8 7F08FC88 8FA2003C */   lw    $v0, 0x3c($sp)
.L7F08FC8C:
/* 0C47BC 7F08FC8C 0FC23CD4 */  jal   sub_GAME_7F08F350
/* 0C47C0 7F08FC90 24070003 */   li    $a3, 3
/* 0C47C4 7F08FC94 28410003 */  slti  $at, $v0, 3
/* 0C47C8 7F08FC98 5420001B */  bnezl $at, .L7F08FD08
/* 0C47CC 7F08FC9C 00001025 */   move  $v0, $zero
/* 0C47D0 7F08FCA0 10000019 */  b     .L7F08FD08
/* 0C47D4 7F08FCA4 8FA20034 */   lw    $v0, 0x34($sp)
.L7F08FCA8:
/* 0C47D8 7F08FCA8 8E050008 */  lw    $a1, 8($s0)
/* 0C47DC 7F08FCAC 8E040000 */  lw    $a0, ($s0)
/* 0C47E0 7F08FCB0 0FC23B58 */  jal   sub_GAME_7F08ED60
/* 0C47E4 7F08FCB4 24A5FFFF */   addiu $a1, $a1, -1
/* 0C47E8 7F08FCB8 10400012 */  beqz  $v0, .L7F08FD04
/* 0C47EC 7F08FCBC 00402825 */   move  $a1, $v0
/* 0C47F0 7F08FCC0 02002025 */  move  $a0, $s0
/* 0C47F4 7F08FCC4 27A60028 */  addiu $a2, $sp, 0x28
/* 0C47F8 7F08FCC8 0FC23D0E */  jal   sub_GAME_7F08F438
/* 0C47FC 7F08FCCC 27A70024 */   addiu $a3, $sp, 0x24
/* 0C4800 7F08FCD0 8FA40028 */  lw    $a0, 0x28($sp)
/* 0C4804 7F08FCD4 02202825 */  move  $a1, $s1
/* 0C4808 7F08FCD8 0FC23C76 */  jal   sub_GAME_7F08F1D8
/* 0C480C 7F08FCDC 24060001 */   li    $a2, 1
/* 0C4810 7F08FCE0 8E25000C */  lw    $a1, 0xc($s1)
/* 0C4814 7F08FCE4 8E240004 */  lw    $a0, 4($s1)
/* 0C4818 7F08FCE8 8E260008 */  lw    $a2, 8($s1)
/* 0C481C 7F08FCEC 0FC23C24 */  jal   sub_GAME_7F08F090
/* 0C4820 7F08FCF0 24A50001 */   addiu $a1, $a1, 1
/* 0C4824 7F08FCF4 50400004 */  beql  $v0, $zero, .L7F08FD08
/* 0C4828 7F08FCF8 00001025 */   move  $v0, $zero
/* 0C482C 7F08FCFC 10000003 */  b     .L7F08FD0C
/* 0C4830 7F08FD00 8FBF001C */   lw    $ra, 0x1c($sp)
.L7F08FD04:
/* 0C4834 7F08FD04 00001025 */  move  $v0, $zero
.L7F08FD08:
/* 0C4838 7F08FD08 8FBF001C */  lw    $ra, 0x1c($sp)
.L7F08FD0C:
/* 0C483C 7F08FD0C 8FB00014 */  lw    $s0, 0x14($sp)
/* 0C4840 7F08FD10 8FB10018 */  lw    $s1, 0x18($sp)
/* 0C4844 7F08FD14 03E00008 */  jr    $ra
/* 0C4848 7F08FD18 27BD0058 */   addiu $sp, $sp, 0x58
)
#endif





#ifdef NONMATCHING
void sub_GAME_7F08FD1C(void) {

}
#else
GLOBAL_ASM(
.text
glabel sub_GAME_7F08FD1C
/* 0C484C 7F08FD1C 3C088007 */  lui   $t0, %hi(ptr_setup_path_tbl) 
/* 0C4850 7F08FD20 8D085D00 */  lw    $t0, %lo(ptr_setup_path_tbl)($t0)
/* 0C4854 7F08FD24 27BDFF08 */  addiu $sp, $sp, -0xf8
/* 0C4858 7F08FD28 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0C485C 7F08FD2C 5100002F */  beql  $t0, $zero, .L7F08FDEC
/* 0C4860 7F08FD30 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0C4864 7F08FD34 8D0E0000 */  lw    $t6, ($t0)
/* 0C4868 7F08FD38 00001825 */  move  $v1, $zero
/* 0C486C 7F08FD3C 01001025 */  move  $v0, $t0
/* 0C4870 7F08FD40 05C20007 */  bltzl $t6, .L7F08FD60
/* 0C4874 7F08FD44 AFA300F0 */   sw    $v1, 0xf0($sp)
/* 0C4878 7F08FD48 8C4F0010 */  lw    $t7, 0x10($v0)
.L7F08FD4C:
/* 0C487C 7F08FD4C 24420010 */  addiu $v0, $v0, 0x10
/* 0C4880 7F08FD50 24630001 */  addiu $v1, $v1, 1
/* 0C4884 7F08FD54 05E3FFFD */  bgezl $t7, .L7F08FD4C
/* 0C4888 7F08FD58 8C4F0010 */   lw    $t7, 0x10($v0)
/* 0C488C 7F08FD5C AFA300F0 */  sw    $v1, 0xf0($sp)
.L7F08FD60:
/* 0C4890 7F08FD60 0C002914 */  jal   get_random_value
/* 0C4894 7F08FD64 AFA800F4 */   sw    $t0, 0xf4($sp)
/* 0C4898 7F08FD68 8FA300F0 */  lw    $v1, 0xf0($sp)
/* 0C489C 7F08FD6C 8FA800F4 */  lw    $t0, 0xf4($sp)
/* 0C48A0 7F08FD70 0043001B */  divu  $zero, $v0, $v1
/* 0C48A4 7F08FD74 0000C010 */  mfhi  $t8
/* 0C48A8 7F08FD78 0018C900 */  sll   $t9, $t8, 4
/* 0C48AC 7F08FD7C 14600002 */  bnez  $v1, .L7F08FD88
/* 0C48B0 7F08FD80 00000000 */   nop   
/* 0C48B4 7F08FD84 0007000D */  break 7
.L7F08FD88:
/* 0C48B8 7F08FD88 03284821 */  addu  $t1, $t9, $t0
/* 0C48BC 7F08FD8C 0C002914 */  jal   get_random_value
/* 0C48C0 7F08FD90 AFA900E8 */   sw    $t1, 0xe8($sp)
/* 0C48C4 7F08FD94 8FA300F0 */  lw    $v1, 0xf0($sp)
/* 0C48C8 7F08FD98 8FA800F4 */  lw    $t0, 0xf4($sp)
/* 0C48CC 7F08FD9C 8FA400E8 */  lw    $a0, 0xe8($sp)
/* 0C48D0 7F08FDA0 0043001B */  divu  $zero, $v0, $v1
/* 0C48D4 7F08FDA4 00005010 */  mfhi  $t2
/* 0C48D8 7F08FDA8 000A5900 */  sll   $t3, $t2, 4
/* 0C48DC 7F08FDAC 14600002 */  bnez  $v1, .L7F08FDB8
/* 0C48E0 7F08FDB0 00000000 */   nop   
/* 0C48E4 7F08FDB4 0007000D */  break 7
.L7F08FDB8:
/* 0C48E8 7F08FDB8 27A6001C */  addiu $a2, $sp, 0x1c
/* 0C48EC 7F08FDBC 24070032 */  li    $a3, 50
/* 0C48F0 7F08FDC0 0FC23D3C */  jal   sub_GAME_7F08F4F0
/* 0C48F4 7F08FDC4 01682821 */   addu  $a1, $t3, $t0
/* 0C48F8 7F08FDC8 10400007 */  beqz  $v0, .L7F08FDE8
/* 0C48FC 7F08FDCC 8FAC001C */   lw    $t4, 0x1c($sp)
/* 0C4900 7F08FDD0 11800005 */  beqz  $t4, .L7F08FDE8
/* 0C4904 7F08FDD4 27A2001C */   addiu $v0, $sp, 0x1c
/* 0C4908 7F08FDD8 8C4D0004 */  lw    $t5, 4($v0)
.L7F08FDDC:
/* 0C490C 7F08FDDC 24420004 */  addiu $v0, $v0, 4
/* 0C4910 7F08FDE0 55A0FFFE */  bnezl $t5, .L7F08FDDC
/* 0C4914 7F08FDE4 8C4D0004 */   lw    $t5, 4($v0)
.L7F08FDE8:
/* 0C4918 7F08FDE8 8FBF0014 */  lw    $ra, 0x14($sp)
.L7F08FDEC:
/* 0C491C 7F08FDEC 27BD00F8 */  addiu $sp, $sp, 0xf8
/* 0C4920 7F08FDF0 03E00008 */  jr    $ra
/* 0C4924 7F08FDF4 00000000 */   nop   
)
#endif




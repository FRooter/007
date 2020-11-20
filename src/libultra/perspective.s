# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64

.include "macros.inc"

.section .rodata
glabel F64_80029430
.word 0x3f91df46, 0x9d353918
.align 4

.section .text, "ax"   
glabel guPerspectiveF
/* 010880 7000FC80 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 010884 7000FC84 44867000 */  mtc1  $a2, $f14
/* 010888 7000FC88 AFBF0014 */  sw    $ra, 0x14($sp)
/* 01088C 7000FC8C AFA7003C */  sw    $a3, 0x3c($sp)
/* 010890 7000FC90 AFA40030 */  sw    $a0, 0x30($sp)
/* 010894 7000FC94 AFA50034 */  sw    $a1, 0x34($sp)
/* 010898 7000FC98 0C004004 */  jal   guMtxIdentF
/* 01089C 7000FC9C E7AE0038 */   swc1  $f14, 0x38($sp)
/* 0108A0 7000FCA0 C7AE0038 */  lwc1  $f14, 0x38($sp)
/* 0108A4 7000FCA4 3C018003 */  lui    $at, %hi(F64_80029430) #0x80030000
/* 0108A8 7000FCA8 D4269430 */  ldc1  $f6, %lo(F64_80029430)($at) # -0x6bd0($at)
/* 0108AC 7000FCAC 46007121 */  cvt.d.s $f4, $f14
/* 0108B0 7000FCB0 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0108B4 7000FCB4 46262202 */  mul.d $f8, $f4, $f6
/* 0108B8 7000FCB8 44815000 */  mtc1  $at, $f10
/* 0108BC 7000FCBC 462043A0 */  cvt.s.d $f14, $f8
/* 0108C0 7000FCC0 460A7303 */  div.s $f12, $f14, $f10
/* 0108C4 7000FCC4 0FC15FA8 */  jal   cosf
/* 0108C8 7000FCC8 E7AC001C */   swc1  $f12, 0x1c($sp)
/* 0108CC 7000FCCC C7AC001C */  lwc1  $f12, 0x1c($sp)
/* 0108D0 7000FCD0 0FC15FAB */  jal   sinf
/* 0108D4 7000FCD4 E7A00020 */   swc1  $f0, 0x20($sp)
/* 0108D8 7000FCD8 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0108DC 7000FCDC C7A6003C */  lwc1  $f6, 0x3c($sp)
/* 0108E0 7000FCE0 C7AE0040 */  lwc1  $f14, 0x40($sp)
/* 0108E4 7000FCE4 46002083 */  div.s $f2, $f4, $f0
/* 0108E8 7000FCE8 C7B00044 */  lwc1  $f16, 0x44($sp)
/* 0108EC 7000FCEC 3C01BF80 */  li    $at, 0xBF800000 # -1.000000
/* 0108F0 7000FCF0 44812000 */  mtc1  $at, $f4
/* 0108F4 7000FCF4 46107480 */  add.s $f18, $f14, $f16
/* 0108F8 7000FCF8 8FA20030 */  lw    $v0, 0x30($sp)
/* 0108FC 7000FCFC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 010900 7000FD00 46107301 */  sub.s $f12, $f14, $f16
/* 010904 7000FD04 8FA50034 */  lw    $a1, 0x34($sp)
/* 010908 7000FD08 E444002C */  swc1  $f4, 0x2c($v0)
/* 01090C 7000FD0C 00001825 */  move  $v1, $zero
/* 010910 7000FD10 24040004 */  li    $a0, 4
/* 010914 7000FD14 460C9283 */  div.s $f10, $f18, $f12
/* 010918 7000FD18 E4420014 */  swc1  $f2, 0x14($v0)
/* 01091C 7000FD1C 46061203 */  div.s $f8, $f2, $f6
/* 010920 7000FD20 44813000 */  mtc1  $at, $f6
/* 010924 7000FD24 E44A0028 */  swc1  $f10, 0x28($v0)
/* 010928 7000FD28 E4480000 */  swc1  $f8, ($v0)
/* 01092C 7000FD2C 460E3202 */  mul.s $f8, $f6, $f14
/* 010930 7000FD30 44803000 */  mtc1  $zero, $f6
/* 010934 7000FD34 00000000 */  nop   
/* 010938 7000FD38 E446003C */  swc1  $f6, 0x3c($v0)
/* 01093C 7000FD3C 46104282 */  mul.s $f10, $f8, $f16
/* 010940 7000FD40 460C5103 */  div.s $f4, $f10, $f12
/* 010944 7000FD44 E4440038 */  swc1  $f4, 0x38($v0)
/* 010948 7000FD48 C7A00048 */  lwc1  $f0, 0x48($sp)
/* 01094C 7000FD4C C4460000 */  lwc1  $f6, ($v0)
/* 010950 7000FD50 24630001 */  addiu $v1, $v1, 1
/* 010954 7000FD54 C4500004 */  lwc1  $f16, 4($v0)
/* 010958 7000FD58 46003282 */  mul.s $f10, $f6, $f0
/* 01095C 7000FD5C C44C0008 */  lwc1  $f12, 8($v0)
/* 010960 7000FD60 10640010 */  beq   $v1, $a0, .L7000FDA4
/* 010964 7000FD64 C44E000C */   lwc1  $f14, 0xc($v0)
.L7000FD68:
/* 010968 7000FD68 46008202 */  mul.s $f8, $f16, $f0
/* 01096C 7000FD6C C4460010 */  lwc1  $f6, 0x10($v0)
/* 010970 7000FD70 C4500014 */  lwc1  $f16, 0x14($v0)
/* 010974 7000FD74 46006102 */  mul.s $f4, $f12, $f0
/* 010978 7000FD78 C44C0018 */  lwc1  $f12, 0x18($v0)
/* 01097C 7000FD7C 24630001 */  addiu $v1, $v1, 1
/* 010980 7000FD80 46007082 */  mul.s $f2, $f14, $f0
/* 010984 7000FD84 C44E001C */  lwc1  $f14, 0x1c($v0)
/* 010988 7000FD88 E44A0000 */  swc1  $f10, ($v0)
/* 01098C 7000FD8C 46003282 */  mul.s $f10, $f6, $f0
/* 010990 7000FD90 E4480004 */  swc1  $f8, 4($v0)
/* 010994 7000FD94 E4440008 */  swc1  $f4, 8($v0)
/* 010998 7000FD98 24420010 */  addiu $v0, $v0, 0x10
/* 01099C 7000FD9C 1464FFF2 */  bne   $v1, $a0, .L7000FD68
/* 0109A0 7000FDA0 E442FFFC */   swc1  $f2, -4($v0)
.L7000FDA4:
/* 0109A4 7000FDA4 46008202 */  mul.s $f8, $f16, $f0
/* 0109A8 7000FDA8 24420010 */  addiu $v0, $v0, 0x10
/* 0109AC 7000FDAC E44AFFF0 */  swc1  $f10, -0x10($v0)
/* 0109B0 7000FDB0 46006102 */  mul.s $f4, $f12, $f0
/* 0109B4 7000FDB4 00000000 */  nop   
/* 0109B8 7000FDB8 46007082 */  mul.s $f2, $f14, $f0
/* 0109BC 7000FDBC E448FFF4 */  swc1  $f8, -0xc($v0)
/* 0109C0 7000FDC0 E444FFF8 */  swc1  $f4, -8($v0)
/* 0109C4 7000FDC4 E442FFFC */  swc1  $f2, -4($v0)
/* 0109C8 7000FDC8 10A00035 */  beqz  $a1, .L7000FEA0
/* 0109CC 7000FDCC 3C014000 */   li    $at, 0x40000000 # 2.000000
/* 0109D0 7000FDD0 44814800 */  mtc1  $at, $f9
/* 0109D4 7000FDD4 44804000 */  mtc1  $zero, $f8
/* 0109D8 7000FDD8 46009021 */  cvt.d.s $f0, $f18
/* 0109DC 7000FDDC 340EFFFF */  li    $t6, 65535
/* 0109E0 7000FDE0 4628003E */  c.le.d $f0, $f8
/* 0109E4 7000FDE4 3C014100 */  li    $at, 0x41000000 # 8.000000
/* 0109E8 7000FDE8 45020004 */  bc1fl .L7000FDFC
/* 0109EC 7000FDEC 44815800 */   mtc1  $at, $f11
/* 0109F0 7000FDF0 1000002B */  b     .L7000FEA0
/* 0109F4 7000FDF4 A4AE0000 */   sh    $t6, ($a1)
/* 0109F8 7000FDF8 44815800 */  mtc1  $at, $f11
.L7000FDFC:
/* 0109FC 7000FDFC 44805000 */  mtc1  $zero, $f10
/* 010A00 7000FE00 24180001 */  li    $t8, 1
/* 010A04 7000FE04 3C0141E0 */  li    $at, 0x41E00000 # 28.000000
/* 010A08 7000FE08 46205103 */  div.d $f4, $f10, $f0
/* 010A0C 7000FE0C 24080001 */  li    $t0, 1
/* 010A10 7000FE10 444FF800 */  cfc1  $t7, $31
/* 010A14 7000FE14 44D8F800 */  ctc1  $t8, $31
/* 010A18 7000FE18 00000000 */  nop   
/* 010A1C 7000FE1C 462021A4 */  cvt.w.d $f6, $f4
/* 010A20 7000FE20 4458F800 */  cfc1  $t8, $31
/* 010A24 7000FE24 00000000 */  nop   
/* 010A28 7000FE28 33180078 */  andi  $t8, $t8, 0x78
/* 010A2C 7000FE2C 53000014 */  beql  $t8, $zero, .L7000FE80
/* 010A30 7000FE30 44183000 */   mfc1  $t8, $f6
/* 010A34 7000FE34 44813800 */  mtc1  $at, $f7
/* 010A38 7000FE38 44803000 */  mtc1  $zero, $f6
/* 010A3C 7000FE3C 24180001 */  li    $t8, 1
/* 010A40 7000FE40 46262181 */  sub.d $f6, $f4, $f6
/* 010A44 7000FE44 44D8F800 */  ctc1  $t8, $31
/* 010A48 7000FE48 00000000 */  nop   
/* 010A4C 7000FE4C 462031A4 */  cvt.w.d $f6, $f6
/* 010A50 7000FE50 4458F800 */  cfc1  $t8, $31
/* 010A54 7000FE54 00000000 */  nop   
/* 010A58 7000FE58 33180078 */  andi  $t8, $t8, 0x78
/* 010A5C 7000FE5C 17000005 */  bnez  $t8, .L7000FE74
/* 010A60 7000FE60 00000000 */   nop   
/* 010A64 7000FE64 44183000 */  mfc1  $t8, $f6
/* 010A68 7000FE68 3C018000 */  lui   $at, 0x8000
/* 010A6C 7000FE6C 10000007 */  b     .L7000FE8C
/* 010A70 7000FE70 0301C025 */   or    $t8, $t8, $at
.L7000FE74:
/* 010A74 7000FE74 10000005 */  b     .L7000FE8C
/* 010A78 7000FE78 2418FFFF */   li    $t8, -1
/* 010A7C 7000FE7C 44183000 */  mfc1  $t8, $f6
.L7000FE80:
/* 010A80 7000FE80 00000000 */  nop   
/* 010A84 7000FE84 0700FFFB */  bltz  $t8, .L7000FE74
/* 010A88 7000FE88 00000000 */   nop   
.L7000FE8C:
/* 010A8C 7000FE8C 44CFF800 */  ctc1  $t7, $31
/* 010A90 7000FE90 3319FFFF */  andi  $t9, $t8, 0xffff
/* 010A94 7000FE94 1F200002 */  bgtz  $t9, .L7000FEA0
/* 010A98 7000FE98 A4B80000 */   sh    $t8, ($a1)
/* 010A9C 7000FE9C A4A80000 */  sh    $t0, ($a1)
.L7000FEA0:
/* 010AA0 7000FEA0 8FBF0014 */  lw    $ra, 0x14($sp)
/* 010AA4 7000FEA4 27BD0030 */  addiu $sp, $sp, 0x30
/* 010AA8 7000FEA8 03E00008 */  jr    $ra
/* 010AAC 7000FEAC 00000000 */   nop   

glabel guPerspective
/* 010AB0 7000FEB0 27BDFF98 */  addiu $sp, $sp, -0x68
/* 010AB4 7000FEB4 44866000 */  mtc1  $a2, $f12
/* 010AB8 7000FEB8 44877000 */  mtc1  $a3, $f14
/* 010ABC 7000FEBC C7A40078 */  lwc1  $f4, 0x78($sp)
/* 010AC0 7000FEC0 C7A6007C */  lwc1  $f6, 0x7c($sp)
/* 010AC4 7000FEC4 C7A80080 */  lwc1  $f8, 0x80($sp)
/* 010AC8 7000FEC8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 010ACC 7000FECC AFA40068 */  sw    $a0, 0x68($sp)
/* 010AD0 7000FED0 44066000 */  mfc1  $a2, $f12
/* 010AD4 7000FED4 44077000 */  mfc1  $a3, $f14
/* 010AD8 7000FED8 27A40028 */  addiu $a0, $sp, 0x28
/* 010ADC 7000FEDC E7A40010 */  swc1  $f4, 0x10($sp)
/* 010AE0 7000FEE0 E7A60014 */  swc1  $f6, 0x14($sp)
/* 010AE4 7000FEE4 0C003F20 */  jal   guPerspectiveF
/* 010AE8 7000FEE8 E7A80018 */   swc1  $f8, 0x18($sp)
/* 010AEC 7000FEEC 27A40028 */  addiu $a0, $sp, 0x28
/* 010AF0 7000FEF0 0C003FC4 */  jal   guMtxF2L
/* 010AF4 7000FEF4 8FA50068 */   lw    $a1, 0x68($sp)
/* 010AF8 7000FEF8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 010AFC 7000FEFC 27BD0068 */  addiu $sp, $sp, 0x68
/* 010B00 7000FF00 03E00008 */  jr    $ra
/* 010B04 7000FF04 00000000 */   nop   


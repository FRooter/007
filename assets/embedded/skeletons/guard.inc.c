#ifdef DEBUG
char* chrJointNames[] = {/*oliveguard names*/
    "SKEL_NECK",
    "SKEL_BACK",
    "SKEL_LF_SHOULDER",
    "SKEL_RT_SHOULDER",
    "SKEL_POSITION",
    "SKEL_BASE",
    "SKEL_LF_HIP",
    "SKEL_LF_KNEE",
    "SKEL_LF_ANKLE",
    "",
    "SKEL_RT_HIP",
    "SKEL_RT_KNEE",
    "SKEL_RT_ANKLE",
    "",
    "SKEL_RT_ELBOW",
    "SKEL_RT_WRIST",
    "",
    "SKEL_LF_ELBOW",
    "SKEL_LF_WRIST"
};
char* chrJointNames2[] = { /*greyguard names*/
    "SKEL_NECK",
    "SKEL_BACK",
    "SKEL_LF_SHOULDER",
    "SKEL_RT_SHOULDER",
    "SKEL_POSITION",
    "SKEL_BASE",
    "SKEL_RT_HIP",
    "SKEL_RT_KNEE",
    "SKEL_RT_ANKLE",
    "",
    "SKEL_LF_HIP",
    "SKEL_LF_KNEE",
    "SKEL_LF_ANKLE",
    "",
    "SKEL_RT_ELBOW",
    "SKEL_RT_WRIST",
    "",
    "SKEL_LF_ELBOW",
    "SKEL_LF_WRIST" };

char* chrJointNames3[] = {/*trevguard names*/
    "SKEL_NECK",
    "SKEL_BACK",
    "SKEL_LF_SHOULDER",
    "SKEL_RT_SHOULDER",
    "SKEL_POSITION",
    "SKEL_BASE",
    "SKEL_LF_HIP",
    "SKEL_LF_KNEE",
    "SKEL_LF_ANKLE",
    "",
    "SKEL_RT_HIP",
    "SKEL_RT_KNEE",
    "SKEL_RT_ANKLE",
    "",
    "SKEL_LF_ELBOW",
    "SKEL_LF_WRIST",
    "",
    "SKEL_RT_ELBOW",
    "SKEL_RT_WRIST" };

char* chrJointNames4[] = {/*camguard names*/
    "SKEL_NECK",
    "SKEL_BACK",
    "SKEL_LF_SHOULDER",
    "SKEL_RT_SHOULDER",
    "SKEL_POSITION",
    "SKEL_BASE",
    "SKEL_RT_HIP",
    "SKEL_RT_KNEE",
    "SKEL_RT_ANKLE",
    "",
    "SKEL_LF_HIP",
    "SKEL_LF_KNEE",
    "SKEL_LF_ANKLE",
    "",
    "SKEL_LF_ELBOW",
    "SKEL_LF_WRIST",
    "",
    "SKEL_RT_ELBOW",
    "SKEL_RT_WRIST" };
char* chrJointNames5[] = {/*spicebond names*/
    "SKEL_NECK",
    "SKEL_BACK",
    "SKEL_LF_SHOULDER",
    "SKEL_RT_SHOULDER",
    "SKEL_POSITION",
    "SKEL_BASE",
    "SKEL_LF_ELBOW",
    "SKEL_LF_WRIST",
    "",
    "SKEL_RT_ELBOW",
    "SKEL_RT_WRIST",
    "",
    "",
    "SKEL_RT_HIP",
    "SKEL_RT_KNEE",
    "SKEL_RT_ANKLE",
    "",
    "SKEL_LF_HIP",
    "SKEL_LF_KNEE",
    "SKEL_LF_ANKLE",
    ""
};
#endif
//D:8003A3A0
ModelJoint JOINTLIST(guard)[] = {
    {0x401, 0x0, 0x0}, 
    {0x02, 0x00, 0x00},
    {0x02, 0x03, 0x03}, 
    {0x02, 0x06, 0x06}, 
    {0x02, 0x09, 0x0C},
    {0x02, 0x0C, 0x09},
    {0x02, 0x0F, 0x12},
    {0x02, 0x12, 0x0F},
    {0x02, 0x15, 0x18},
    {0x02, 0x18, 0x15},
    {0x02, 0x1B, 0x1E},
    {0x02, 0x1E, 0x1B},
    {0x02, 0x21, 0x24},
    {0x02, 0x24, 0x21},
    {0x02, 0x27, 0x2A},
    {0x02, 0x2A, 0x27}
};


//D:8003D400
MODELSKELETON(guard, 0x10, 0x2D)
//D:8003D40C
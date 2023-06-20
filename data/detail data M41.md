## blake3_hash_many  (M41):
        size_t num_inputs=4,
        size_t blocks=1,
        uint64_t counter=0
        bool increment_counter=0,
        uint8_t flags=4,
        uint8_t flags_start=0,
        uint8_t flags_end=0

### input message: [0~255]

####  Parallel 1
98,e1,5c,f4,a7,6e,5c,a6,7c,48,20,5d,c5,dc,ea,b0,
9d,e9,8e,4b,5d,63,e8,dc,9e,31,de,b9,be,21,be,6c,
a7,5e,6e,3f,8a,ce,f6,3f,9f,35,f8,5a,1c,99,41,88,
aa,be,3d,87,80,57,26,4f,eb,c5,a5,14,3b,da,35,db,

#### Parallel 2
b0,7d,1a,86,92,36,bb,38,22,1b,f2,96,03,0f,66,76,
86,a8,f5,dd,64,e0,44,61,36,95,2f,f7,f9,32,2b,18,
04,a9,8b,fe,12,47,52,31,67,a0,73,b4,46,9c,d3,dd,
33,f9,27,31,2d,90,5a,aa,2d,fd,cf,d9,76,b8,18,7e,

#### Parallel 3
1e,92,b6,7e,a8,35,5a,f2,e3,6d,dd,12,83,a8,6d,11,
d0,61,34,5b,d1,4d,23,75,03,45,a0,a9,89,26,de,fb,
79,04,89,08,10,26,a7,2c,02,4d,2e,87,bf,89,35,6f,
70,fd,32,84,24,50,0f,31,8e,8d,67,18,25,9b,6b,1f,

#### Parallel 4
16,6b,8c,d4,70,0d,0c,ac,2f,d1,17,34,ec,98,fc,1d,
d0,7b,1c,f7,46,71,5b,16,38,42,10,a1,99,a5,37,04,
97,ed,22,04,6a,d8,85,29,41,c2,c9,c8,df,b0,ef,e4,
20,df,64,aa,9c,8e,e1,35,01,0d,91,cf,46,3a,b8,b8,

### input key: [0~7]
 6A09E667, BB67AE85, 3C6EF372, A54FF53A, 510E527F, 9B05688C, 1F83D9AB,

 blake3_hash_many_portable
### inputs in compress_pre:
        block_len: 64,counter:0,:flags4
#### block[0~63]:
        98,E1,5C,F4,A7,6E,5C,A6,7C,48,20,5D,C5,DC,EA,B0,9D,E9,8E,4B,5D,63,E8,DC,9E,31,DE,B9,BE,21,BE,6C,
        A7,5E,6E,3F,8A,CE,F6,3F,9F,35,F8,5A,1C,99,41,88,AA,BE,3D,87,80,57,26,4F,EB,C5,A5,14,3B,DA,35,DB,

#### block_words[0~15]:
        F45CE198,A65C6EA7,5D20487C,B0EADCC5,4B8EE99D,DCE8635D,B9DE319E,6CBE21BE,
        3F6E5EA7,3FF6CE8A,5AF8359F,8841991C,873DBEAA,4F265780,14A5C5EB,DB35DA3B,

#### cv[0~7]:
        6A09E667,BB67AE85,3C6EF372,A54FF53A,510E527F,9B05688C,1F83D9AB,5BE0CD19,
#### state[0~15]:
        4C56F8B0,00000096,E6CB3335,00007FFB,00340036,0052005C,4C56F8C0,00000096,
        0000001C,00000000,4C56F998,00000096,0000001C,00000000,E6CB32E6,00007FFB,

#### state[0~15] after round0:
        C0E12142,E012485B,64A6FD15,29712DDA,9916EDF7,8AC831BE,77D2BEA5,44657CA9,
        99DF38C0,3BF38B3E,18DD6C9A,CB19631C,1BEDC499,5BB07D48,60C9938A,6942C32D,

#### state[0~15] after round1:
        E664DE0C,B4CB4242,5E952553,457543E3,5073E260,69FF59DF,0136895A,11801750,
        7A9085C7,B36135F0,D7683A97,09BD0E41,CD8208D0,3B652C43,1A0DF824,02B63608,

#### state[0~15] after round2:
        21497F87,6B4DF512,A8B4F888,7DC4625F,BE80B168,A387F942,26F8DE17,E742BA7E,
        4D47AAE2,5A283EA6,66474020,F5D6BC42,E90748AA,042D68A2,2EC35C3E,315FA7AD,

#### state[0~15] after round3:
        74160325,1FA1EC2D,0E4B7440,A1AFAE2F,2C36E234,9A11D5E0,F4595D3A,070BBA41,
        25838D83,DD57DBF5,79D05ACC,407875EB,0DFCB564,8A4C0BDE,9A01B283,C4F5A988,

#### state[0~15] after round4:
        5E03FDBD,6CD86B82,B59797AF,C313E700,0C69F2FD,DDCAEDFB,DDFD75D5,35C36F60,
        E5A2E0DD,CE6E2CDB,4CB7D3E5,D92FE4D2,1809DAC1,348EF1C6,C6F70513,48B6CD39,

#### state[0~15] after round5:
        E1604822,94D583A9,6AD7E053,1862CBD8,5868F6A7,3E0262B2,DF565461,B73F4B02,
        35BDC6D7,DB87E584,11CA5211,86FB3C33,1A2EB0A7,2AFC0EC9,0DD42E7A,CC64638C,

#### state[0~15] after round6:
        2B447D07,B9D4B988,4AA3DFB1,38BAF7FE,F9E2FEBA,CF1D2FDD,941839C5,7E9BF851,
        98BDF954,3F1F7FCA,F47F010B,A0B4DC98,224A88BE,0E21F4CA,A6010234,6130B1C6,

#### xor in blake3_compress_in_place_portable:
            state[0~ 7] 2B447D07,B9D4B988,4AA3DFB1,38BAF7FE,F9E2FEBA,CF1D2FDD,941839C5,7E9BF851,
        xor state[8~15] 98BDF954,3F1F7FCA,F47F010B,A0B4DC98,224A88BE,0E21F4CA,A6010234,6130B1C6,
          =    cv[0~ 7] B3F98453,86CBC642,BEDCDEBA,980E2B66,DBA87604,C13CDB17,32193BF1,1FAB4997,
### inputs in compress_pre:
        block_len: 64,counter:0,:flags4
#### block[0~63]:
        B0,7D,1A,86,92,36,BB,38,22,1B,F2,96,03,0F,66,76,86,A8,F5,DD,64,E0,44,61,36,95,2F,F7,F9,32,2B,18,
        04,A9,8B,FE,12,47,52,31,67,A0,73,B4,46,9C,D3,DD,33,F9,27,31,2D,90,5A,AA,2D,FD,CF,D9,76,B8,18,7E,

#### block_words[0~15]:
        861A7DB0,38BB3692,96F21B22,76660F03,DDF5A886,6144E064,F72F9536,182B32F9,
        FE8BA904,31524712,B473A067,DDD39C46,3127F933,AA5A902D,D9CFFD2D,7E18B876,

#### cv[0~7]:
        6A09E667,BB67AE85,3C6EF372,A54FF53A,510E527F,9B05688C,1F83D9AB,5BE0CD19,
#### state[0~15]:
        2B447D07,B9D4B988,4AA3DFB1,38BAF7FE,F9E2FEBA,CF1D2FDD,941839C5,7E9BF851,
        98BDF954,3F1F7FCA,F47F010B,A0B4DC98,224A88BE,0E21F4CA,A6010234,6130B1C6,

#### state[0~15] after round0:
        1FF923E4,8E81F712,94436717,67EBF2D0,14911D4E,E376B122,18B46E6C,1616C45A,
        E164510E,A5B2CDF3,365035AB,30790F3A,1C6C5E8C,5DB1E0E2,D90380C0,35600776,

#### state[0~15] after round1:
        2997C588,5BD3E9FA,C3820401,2A14A222,D8ABF913,79C151EA,6BE6531F,3FEB30F0,
        135ADD21,AF962AC3,6C655CB3,DA000D33,8ABEE865,71A3E668,F17BE61C,B84CA89B,

#### state[0~15] after round2:
        5430001A,AF328A5D,B1F0FD18,4744A103,1457F2AE,C0DCE852,A75150D1,BE39A4EF,
        BF9D8513,8F99FCA0,942AF61B,FF0A057E,B49655BB,99BA00F3,FD4DCC0E,EA224B70,

#### state[0~15] after round3:
        24D11F41,AECBF269,844727D5,50E1B343,1CEAC5EA,1CC59C5B,53E01ED1,AAD720DF,
        05B46FE6,B33555F5,D6A1E3F7,32ABAE99,B224984F,8396BBCC,6A01263D,BDFB3EAC,

#### state[0~15] after round4:
        20ABF387,82947138,27380C58,DD30E099,A02BF634,52970C31,0A873873,11F1C644,
        D51729D2,A6BE8B97,C2D65BBF,BAF6E795,CCA490FE,D33FE179,4C592123,501A7356,

#### state[0~15] after round5:
        BCFD7281,09E24658,974CB7C7,EEA3C63B,9B1576C2,A7CC4D8C,44C748D8,0D20C15F,
        DDB2B827,91D5D7AE,9481FE65,7714B538,F4B18F9B,5EFB1774,A555BB0E,88B48E43,

#### state[0~15] after round6:
        2A2328CF,31ECEA04,6AC6B5BF,53FD7E95,0C5D57A9,EB94E626,63D3493E,81E1A49B,
        C6114E8F,5646DBEF,C7B4458A,C5082A90,B9DF1796,AEEC7F35,14250D65,1C756BA9,

#### xor in blake3_compress_in_place_portable:
            state[0~ 7] 2A2328CF,31ECEA04,6AC6B5BF,53FD7E95,0C5D57A9,EB94E626,63D3493E,81E1A49B,
        xor state[8~15] C6114E8F,5646DBEF,C7B4458A,C5082A90,B9DF1796,AEEC7F35,14250D65,1C756BA9,
          =    cv[0~ 7] EC326640,67AA31EB,AD72F035,96F55405,B582403F,45789913,77F6445B,9D94CF32,
### inputs in compress_pre:
        block_len: 64,counter:0,:flags4
#### block[0~63]:
        1E,92,B6,7E,A8,35,5A,F2,E3,6D,DD,12,83,A8,6D,11,D0,61,34,5B,D1,4D,23,75,03,45,A0,A9,89,26,DE,FB,
        79,04,89,08,10,26,A7,2C,02,4D,2E,87,BF,89,35,6F,70,FD,32,84,24,50,0F,31,8E,8D,67,18,25,9B,6B,1F,

#### block_words[0~15]:
        7EB6921E,F25A35A8,12DD6DE3,116DA883,5B3461D0,75234DD1,A9A04503,FBDE2689,
        08890479,2CA72610,872E4D02,6F3589BF,8432FD70,310F5024,18678D8E,1F6B9B25,

#### cv[0~7]:
        6A09E667,BB67AE85,3C6EF372,A54FF53A,510E527F,9B05688C,1F83D9AB,5BE0CD19,
#### state[0~15]:
        2A2328CF,31ECEA04,6AC6B5BF,53FD7E95,0C5D57A9,EB94E626,63D3493E,81E1A49B,
        C6114E8F,5646DBEF,C7B4458A,C5082A90,B9DF1796,AEEC7F35,14250D65,1C756BA9,

#### state[0~15] after round0:
        03A5922A,1FFA351A,6E2E3781,539236E8,F4A62DBE,21DE1BFB,116A7B81,25E10B9A,
        1E5C679A,03A293A3,0FCED205,0A3EE726,40572EB9,2E53713D,EBC10947,61B328B0,

#### state[0~15] after round1:
        C1A1647E,0C9C3DB6,21D83DE2,5FE30FF0,03A894ED,5567301F,ADFE0D91,75464469,
        62E8F4D3,44A03610,7ADA1D36,0AAC40D6,E42FFBB5,41F45196,C1551FC4,A4291786,

#### state[0~15] after round2:
        6BF23889,37A971C9,E68F9C81,27320DD8,89ADBCC9,BD35EADF,DD0AA659,917B2B3B,
        3B821E95,8CFCD2E7,66CB25FD,F48F64F9,EFACFD27,3CD6B8AD,A26EC8D0,6490CF33,

#### state[0~15] after round3:
        0D6CB8FD,9E73D0AD,74975CF6,68E16A18,1ADC9F83,54C2D4E2,F329F1E3,1851BE3E,
        9A212EC9,464E2EB8,7668BDC3,0300721E,C3A09D1C,C9E1C286,2F2CDEE9,9342F50A,

#### state[0~15] after round4:
        8E655BE1,BABA5989,9B0963C4,89528BE4,559DEBA8,CE0B4021,71ED86EB,3AC0692B,
        DBF712FB,FDB41C5D,6509D25C,0F69FB05,0C87DF0E,B65179B8,5F9E46E8,B1E25AC0,

#### state[0~15] after round5:
        AD35A890,EF43816D,0AD50BE1,29D36861,54BB9639,1552CF07,1DDD0B10,60F130A7,
        454913E7,B6C44497,D8A69844,ADD4E229,6DADB7EB,97DAC999,7A1ADDDA,423B97A0,

#### state[0~15] after round6:
        207E00D7,344A7EEE,DD09AE32,AC0AEBBE,3BEA782B,95896EC7,C55AE108,0007D87F,
        4CC4CB6B,194B16FF,C7CB9DF5,AC8F273B,73C2167C,11177F5D,C72DE68B,7FCF6B1F,

#### xor in blake3_compress_in_place_portable:
            state[0~ 7] 207E00D7,344A7EEE,DD09AE32,AC0AEBBE,3BEA782B,95896EC7,C55AE108,0007D87F,
        xor state[8~15] 4CC4CB6B,194B16FF,C7CB9DF5,AC8F273B,73C2167C,11177F5D,C72DE68B,7FCF6B1F,
          =    cv[0~ 7] 6CBACBBC,2D016811,1AC233C7,0085CC85,48286E57,849E119A,02770783,7FC8B360,
### inputs in compress_pre:
        block_len: 64,counter:0,:flags4
#### block[0~63]:
        16,6B,8C,D4,70,0D,0C,AC,2F,D1,17,34,EC,98,FC,1D,D0,7B,1C,F7,46,71,5B,16,38,42,10,A1,99,A5,37,04,
        97,ED,22,04,6A,D8,85,29,41,C2,C9,C8,DF,B0,EF,E4,20,DF,64,AA,9C,8E,E1,35,01,0D,91,CF,46,3A,B8,B8,

#### block_words[0~15]:
        D48C6B16,AC0C0D70,3417D12F,1DFC98EC,F71C7BD0,165B7146,A1104238,0437A599,
        0422ED97,2985D86A,C8C9C241,E4EFB0DF,AA64DF20,35E18E9C,CF910D01,B8B83A46,

#### cv[0~7]:
        6A09E667,BB67AE85,3C6EF372,A54FF53A,510E527F,9B05688C,1F83D9AB,5BE0CD19,
#### state[0~15]:
        207E00D7,344A7EEE,DD09AE32,AC0AEBBE,3BEA782B,95896EC7,C55AE108,0007D87F,
        4CC4CB6B,194B16FF,C7CB9DF5,AC8F273B,73C2167C,11177F5D,C72DE68B,7FCF6B1F,

#### state[0~15] after round0:
        AB2D9DAD,404C97A0,4346A943,FC63747C,19BC976B,BC871501,FD5A74ED,14441F6A,
        C3AC7329,6F782FB7,05A7AFE8,E232932D,D54A8CD1,AA824407,1FDAAFC5,9F154CFE,

#### state[0~15] after round1:
        29828DBD,63E8EA63,D1C0F246,C215CA80,36D4736A,F67BA6C0,51F4DEE9,E269ABC4,
        1233E527,78B0B7FA,525EFE1C,853A2304,CA637D33,3AA07F56,7CC9BBA5,7DB7DFCC,

#### state[0~15] after round2:
        F766A5FE,F26F3432,331BA905,B1AD0BBB,345B8DED,4CB2E5F5,6CB41D6C,B67CA54E,
        81FE0B6E,3D3CE329,2B62C24D,B3FB16EB,21B7E9C6,DDDBD486,9FD2B438,744FA5C8,

#### state[0~15] after round3:
        68BDF01C,635A3659,01EE7DE9,3E003452,B64C5E5D,ACFEBC2F,E244932A,51D9837F,
        C07E4F5A,7AAA4D51,3FA7DE8F,E1838984,F3FD4C9A,F5608C71,D9672D3E,2D5C01A2,

#### state[0~15] after round4:
        CBCC4E97,DC464D61,9391ADD0,39055B5D,143CF6F6,1D5275BF,C20D99F5,8094B5D3,
        87F7B6DE,554D1623,6FB266EC,1233CDC6,30C80B64,CE8447D1,51E57674,96929DB9,

#### state[0~15] after round5:
        939D03AA,A6908902,DDB1EE10,F10C9522,A0542F73,0E805402,0B872EFF,71BE9601,
        62AC79FD,527602E5,52B2CB74,901D2224,6E045F1C,B32C1546,6063713D,E848C0F6,

#### state[0~15] after round6:
        27EAAF78,94CA2B11,7C0FAD70,E1F57DA7,01418E2D,128D2892,3C070ED0,0BBF34CF,
        82DB870E,0B00E9B7,DD5229DD,F6E05CBC,99A6E8F4,08538B48,1269BE4C,8E48FFAE,

#### xor in blake3_compress_in_place_portable:
            state[0~ 7] 27EAAF78,94CA2B11,7C0FAD70,E1F57DA7,01418E2D,128D2892,3C070ED0,0BBF34CF,
        xor state[8~15] 82DB870E,0B00E9B7,DD5229DD,F6E05CBC,99A6E8F4,08538B48,1269BE4C,8E48FFAE,
          =    cv[0~ 7] A5312876,9FCAC2A6,A15D84AD,1715211B,98E766D9,1ADEA3DA,2E6EB09C,85F7CB61,

### output out: [0~128]
53,84,F9,B3,42,C6,CB,86,BA,DE,DC,BE,66,2B,0E,98,04,76,A8,DB,17,DB,3C,C1,F1,3B,19,32,97,49,AB,1F,
40,66,32,EC,EB,31,AA,67,35,F0,72,AD,05,54,F5,96,3F,40,82,B5,13,99,78,45,5B,44,F6,77,32,CF,94,9D,
BC,CB,BA,6C,11,68,01,2D,C7,33,C2,1A,85,CC,85,00,57,6E,28,48,9A,11,9E,84,83,07,77,02,60,B3,C8,7F,
76,28,31,A5,A6,C2,CA,9F,AD,84,5D,A1,1B,21,15,17,D9,66,E7,98,DA,A3,DE,1A,9C,B0,6E,2E,61,CB,F7,85,
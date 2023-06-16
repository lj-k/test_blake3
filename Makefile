

C_DEF_SWITCH_PRINT=-DPRINTF_ON=1 -DPRIOUT_ON=1
C_DEF_SWITCH_TIMETEST= -DTIME_TEST_NUM=1000000000 #-DTEST_TIME

# configure more above 
#parameters used in make
# MNUM = M21 M41 M81 M161 M116 M216 M416 M816 M1616
# PLT  = AVX512 NEON RVV PORT
#example
#use MNUM=M216 as `make gccmany MNUM=M216`
#use MNUM=M216 in avx512 as `make gccmany MNUM=M216 PLT=AVX512`
#use MNUM=M216 in avx512 as `make gccmany MNUM=M216 PLT=AVX512`
#make runmanyall PLT=AVX512
###########################
SRC_PATH=src/
EXE_PATH=gccP/

###########################
ifeq ($(MNUM),M21)
$(info M21)
C_DEF_MANY_NUM=-DNUM_inputs=2 -DNUM_blocks=1
else ifeq ($(MNUM),M41)
$(info M41)
C_DEF_MANY_NUM=-DNUM_inputs=4 -DNUM_blocks=1
else ifeq ($(MNUM),M81)
$(info M81)
C_DEF_MANY_NUM=-DNUM_inputs=8 -DNUM_blocks=1
else ifeq ($(MNUM),M161)
$(info M161)
C_DEF_MANY_NUM=-DNUM_inputs=16 -DNUM_blocks=1
else ifeq ($(MNUM),M116)
$(info M116)
C_DEF_MANY_NUM=-DNUM_inputs=1 -DNUM_blocks=16
else ifeq ($(MNUM),M216)
$(info M216)
C_DEF_MANY_NUM=-DNUM_inputs=2 -DNUM_blocks=16
else ifeq ($(MNUM),M416)
$(info M416)
C_DEF_MANY_NUM=-DNUM_inputs=4 -DNUM_blocks=16
else ifeq ($(MNUM),M816)
$(info M816)
C_DEF_MANY_NUM=-DNUM_inputs=8 -DNUM_blocks=16
else ifeq ($(MNUM),M1616)
$(info M1616)
C_DEF_MANY_NUM=-DNUM_inputs=16 -DNUM_blocks=16
endif

GCC_FLAGS=-o

ifeq ($(PLT),AVX512)
	C_DEF_PLATFORM=-DTEST_USE_AVX512=1
	GCC_FLAGS=-o $(EXE_PATH)test_$(PLT)_$(MNUM) -mavx512f -mavx512vl
else ifeq ($(PLT),RVV)
	C_DEF_PLATFORM=-DTEST_USE_RVV=1
	GCC_FLAGS=-o $(EXE_PATH)test_$(PLT)_$(MNUM)
else ifeq ($(PLT),NEON)
	C_DEF_PLATFORM=-DTEST_USE_NEON=1
	GCC_FLAGS=-o $(EXE_PATH)test_$(PLT)_$(MNUM)
else ifeq ($(PLT),PORT)
	C_DEF_PLATFORM=-DTEST_USE_PORTABLE=1
	GCC_FLAGS=-o $(EXE_PATH)test_$(PLT)_$(MNUM)
else 
	PLT=PORT
	C_DEF_PLATFORM=-DTEST_USE_PORTABLE=1
	GCC_FLAGS=-o $(EXE_PATH)test_$(PLT)_$(MNUM)
endif


TEST_MANY_FILES=$(SRC_PATH)perftest_module_many.c $(SRC_PATH)blake3_portable.c
TEST_MANY_DEFINES=-DUSEGCCDF $(C_DEF_MANY_NUM) $(C_DEF_SWITCH_PRINT) $(C_DEF_SWITCH_TIMETEST)$(C_DEF_PLATFORM)

TEST_XOF_FILES=$(SRC_PATH)perftest_module_xofinp.c $(SRC_PATH)blake3_portable.c
TEST_XOF_DEFINES=-DUSEGCCDF -DTEST_XOF=1 $(C_DEF_SWITCH_PRINT) $(C_DEF_SWITCH_TIMETEST)

TEST_INP_FILES=$(SRC_PATH)perftest_module_xofinp.c $(SRC_PATH)blake3_portable.c
TEST_INP_DEFINES=-DUSEGCCDF -DTEST_INPLACE=1 $(C_DEF_SWITCH_PRINT) $(C_DEF_SWITCH_TIMETEST)


.PHONY:gccmany
gccmany:
	gcc $(GCC_FLAGS) $(TEST_MANY_DEFINES) $(TEST_MANY_FILES)

.PHONY:gccmanyall
gccmanyall:
	make gccmany MNUM=M21 PLT=$(PLT)
	make gccmany MNUM=M41 PLT=$(PLT)
	make gccmany MNUM=M81 PLT=$(PLT)
	make gccmany MNUM=M161 PLT=$(PLT)
	make gccmany MNUM=M116 PLT=$(PLT)
	make gccmany MNUM=M216 PLT=$(PLT)
	make gccmany MNUM=M416 PLT=$(PLT)
	make gccmany MNUM=M816 PLT=$(PLT)
	make gccmany MNUM=M1616 PLT=$(PLT)
.PHONY:gccxof
gccxof:
	gcc -o $(EXE_PATH)test_xof $(TEST_XOF_DEFINES) $(TEST_XOF_FILES)

.PHONY:gccinp #inplace
gccinp:
	gcc -o $(EXE_PATH)test_xof $(TEST_INP_DEFINES) $(TEST_INP_FILES)

.PHONY:runall
runall:
	./$(EXE_PATH)test_$(PLT)_M21
	./$(EXE_PATH)test_$(PLT)_M41
	./$(EXE_PATH)test_$(PLT)_M81
	./$(EXE_PATH)test_$(PLT)_M161 
	./$(EXE_PATH)test_$(PLT)_M116 
	./$(EXE_PATH)test_$(PLT)_M216 
	./$(EXE_PATH)test_$(PLT)_M416 
	./$(EXE_PATH)test_$(PLT)_M816 
	./$(EXE_PATH)test_$(PLT)_M1616

.PHONY:run
run:
	./$(EXE_PATH)test

.PHONY:clean
clean:
	rm -rf $(EXE_PATH)*

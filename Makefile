

SWITCH_PRINT=-DPRINTF_ON=1 -DPRIOUT_ON=1
SWITCH_TIMETEST= -DTIME_TEST_NUM=1000000000 #-DTEST_TIME

# configure more above
#use MNUM=M21 as `make gccmany MNUM=M216`
###########################
SRC_PATH=src/
EXE_PATH=gccP/

###########################
ifeq ($(MNUM),M21)
$(info M21)
MANY_NUM=-DNUM_inputs=2 -DNUM_blocks=1
else ifeq ($(MNUM),M41)
$(info M41)
MANY_NUM=-DNUM_inputs=4 -DNUM_blocks=1
else ifeq ($(MNUM),M81)
$(info M81)
MANY_NUM=-DNUM_inputs=8 -DNUM_blocks=1
else ifeq ($(MNUM),M161)
$(info M161)
MANY_NUM=-DNUM_inputs=16 -DNUM_blocks=1
else ifeq ($(MNUM),M116)
$(info M116)
MANY_NUM=-DNUM_inputs=1 -DNUM_blocks=16
else ifeq ($(MNUM),M216)
$(info M216)
MANY_NUM=-DNUM_inputs=2 -DNUM_blocks=16
else ifeq ($(MNUM),M416)
$(info M416)
MANY_NUM=-DNUM_inputs=4 -DNUM_blocks=16
else ifeq ($(MNUM),M816)
$(info M816)
MANY_NUM=-DNUM_inputs=8 -DNUM_blocks=16
else ifeq ($(MNUM),M1616)
$(info M1616)
MANY_NUM=-DNUM_inputs=16 -DNUM_blocks=16
endif

TEST_MANY_FILES=$(SRC_PATH)perftest_module_many.c $(SRC_PATH)blake3_portable.c
TEST_MANY_DEFINES=-DUSEGCCDF $(MANY_NUM) $(SWITCH_PRINT) $(SWITCH_TIMETEST)

TEST_XOF_FILES=$(SRC_PATH)perftest_module_xofinp.c $(SRC_PATH)blake3_portable.c
TEST_XOF_DEFINES=-DUSEGCCDF -DTEST_XOF=1 $(SWITCH_PRINT) $(SWITCH_TIMETEST)

TEST_INP_FILES=$(SRC_PATH)perftest_module_xofinp.c $(SRC_PATH)blake3_portable.c
TEST_INP_DEFINES=-DUSEGCCDF -DTEST_INPLACE=1 $(SWITCH_PRINT) $(SWITCH_TIMETEST)


.PHONY:gccmany
gccmany:
	gcc -o $(EXE_PATH)test $(TEST_MANY_DEFINES) $(TEST_MANY_FILES)

.PHONY:gccxof
gccxof:
	gcc -o $(EXE_PATH)test $(TEST_XOF_DEFINES) $(TEST_XOF_FILES)

.PHONY:gccinp #inplace
gccinp:
	gcc -o $(EXE_PATH)test $(TEST_INP_DEFINES) $(TEST_INP_FILES)

.PHONY:run 
run:
	./$(EXE_PATH)test

.PHONY:clean
clean:
	rm -rf $(EXE_PATH)*

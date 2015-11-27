#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/761576308/Cellule.o \
	${OBJECTDIR}/_ext/761576308/ListeTrieeChainee.o \
	${OBJECTDIR}/_ext/761576308/PrecondVioleeExcep.o \
	${OBJECTDIR}/_ext/761576308/testeListeTrieeChainee.o \
	${OBJECTDIR}/_ext/761576308/testeListeTrieeChaineeExtensions.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/listetriee

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/listetriee: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/listetriee ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/761576308/Cellule.o: ../TP12/Cellule.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/761576308
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/761576308/Cellule.o ../TP12/Cellule.cpp

${OBJECTDIR}/_ext/761576308/ListeTrieeChainee.o: ../TP12/ListeTrieeChainee.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/761576308
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/761576308/ListeTrieeChainee.o ../TP12/ListeTrieeChainee.cpp

${OBJECTDIR}/_ext/761576308/PrecondVioleeExcep.o: ../TP12/PrecondVioleeExcep.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/761576308
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/761576308/PrecondVioleeExcep.o ../TP12/PrecondVioleeExcep.cpp

${OBJECTDIR}/_ext/761576308/testeListeTrieeChainee.o: ../TP12/testeListeTrieeChainee.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/761576308
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/761576308/testeListeTrieeChainee.o ../TP12/testeListeTrieeChainee.cpp

${OBJECTDIR}/_ext/761576308/testeListeTrieeChaineeExtensions.o: ../TP12/testeListeTrieeChaineeExtensions.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/761576308
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/761576308/testeListeTrieeChaineeExtensions.o ../TP12/testeListeTrieeChaineeExtensions.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/listetriee

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
